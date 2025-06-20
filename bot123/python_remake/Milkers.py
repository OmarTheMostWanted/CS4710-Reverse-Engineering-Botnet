import os
import time
import signal
import random
import socket
import fcntl
import errno
import select
import logging

# Global variables (placeholders)
ourIP = [0, 0, 0, 0]
macAddress = [0] * 6
mainCommSock = None
numpids = 0
pids = []
buffer_size = 4108

currentServer = 0
commServer = []


# debug
daemon = False


def init_rand(param_1):
    # Initialize global variables
    DAT_006ef984 = param_1 - 0x61c88647
    _DAT_006ef988 = param_1 + 0x3c6ef372
    Q = [0] * 0x1000  # Placeholder for the array

    # Deterministic initialization of Q
    Q[0] = param_1
    for local_c in range(3, 0x1000):
        Q[local_c] = local_c ^ Q[local_c - 3] ^ Q[local_c - 2] ^ 0x9e3779b9


def getOurIP():
    """
    Attempts to determine the local machine's IP address and network interface.

    This function creates a UDP socket and connects to a public DNS server (8.8.8.8) to determine the local IP address.
    It then reads the system's routing table to find the default network interface. The code for retrieving the MAC address of the interface is present but commented out.

    Global Variables:
        ourIP (list of int): The local IP address as a list of integers.
        macAddress: Intended to store the MAC address of the interface (currently not set).

    Returns:
        int: 1 if the operation is successful, 0 otherwise.
    """
    global ourIP, macAddress
    try:
        # Create a socket
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        # Connect to a public IP (Google's DNS server)
        sock.connect(("8.8.8.8", 53))

        # Get the local IP address
        ourIP = list(map(int, sock.getsockname()[0].split('.')))

        # Open the routing table
        with open("/proc/net/route", "r") as route_file:
            for line in route_file:
                if "\t00000000\t" in line:
                    interface = line.split("\t")[0]
                    break
            else:
                interface = None

        # if interface:
        # Get the MAC address of the interface
        # mac = fcntl.ioctl(
        #     sock.fileno(),
        #     0x8927,  # SIOCGIFHWADDR
        #     struct.pack('256s', interface[:15].encode('utf-8'))
        # )
        # macAddress = list(mac[18:24])

        sock.close()
        return 1
    except Exception:
        return 0


def fdgets(buffer, max_size, fd):
    """
    Reads from a file descriptor into a buffer until a newline is encountered,
    the buffer is full, or the read operation ends.

    Args:
        buffer (bytearray): The buffer to store the read data.
        max_size (int): The maximum size of the buffer.
        fd (int): The file descriptor to read from.

    Returns:
        int: The number of bytes read, or 0 if the read operation ends.
    """
    local_c = 1
    local_10 = 0

    while local_c == 1 and local_10 < max_size and (local_10 == 0 or buffer[local_10 - 1] != ord('\n')):
        sVar1 = os.read(fd, 1)
        if not sVar1:  # End of file or no data
            local_c = 0
            break
        buffer[local_10] = sVar1[0]
        local_10 += 1

    if local_c == 0:
        return 0
    return local_10


def initConnection():
    """
    Initializes and establishes a connection to the current command and control server.

    This function resets the main communication socket if it exists, updates the current server index,
    parses the server's IP address and port (defaulting to 6966 if not specified), and attempts to
    establish a TCP connection to the server with a timeout.

    Returns:
        bool: True if the connection was successful, False otherwise.
    """
    global mainCommSock, currentServer, commServer

    ip = bytearray(524)  # Buffer for the IP
    port_number = 0x1b46  # Default port (6966 in decimal)

    # Reset the main communication socket
    if mainCommSock is not None:
        mainCommSock.close()
        mainCommSock = None

    # Update the current server index
    if currentServer == 0:
        currentServer = 0
    else:
        currentServer += 1

    # Copy the current server's IP and port
    ip_str = commServer[currentServer]
    ip[:len(ip_str)] = ip_str.encode()

    # Parse the IP and port if specified
    if b":" in ip:
        ip_split = ip.split(b":")
        ip = ip_split[0]
        port_number = int(ip_split[1].strip(b"\x00"))  # Strip null bytes

    # Create a new socket
    mainCommSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Attempt to connect with a timeout
    success = connectTimeout(mainCommSock, ip.decode(), port_number, 30)
    return success == 0


def connectTimeout(sock, ip, port, timeout):
    """
    Attempts to connect to a server with a timeout.

    Args:
        sock (socket.socket): The socket to use for the connection.
        ip (str): The IP address of the server.
        port (int): The port number of the server.
        timeout (int): The timeout in seconds.

    Returns:
        bool: True if the connection is successful, False otherwise.
    """
    print(f"\033[1;32mConnecting to {ip}:{port} with timeout {timeout}s...\033[0m")
    import fcntl, os, select, socket, errno
    flags = fcntl.fcntl(sock, fcntl.F_GETFL)
    fcntl.fcntl(sock, fcntl.F_SETFL, flags | os.O_NONBLOCK)

    # Initiate non-blocking connect
    err = sock.connect_ex((ip, port))
    if err not in (0, errno.EINPROGRESS, errno.EALREADY, errno.EWOULDBLOCK):
        return False

    # Wait for write readiness or errors
    ready_to_read, ready_to_write, in_error = select.select([], [sock], [sock], timeout)
    if sock in in_error or sock not in ready_to_write:
        return False

    # Check final socket error
    error = sock.getsockopt(socket.SOL_SOCKET, socket.SO_ERROR)
    if error != 0:
        return False

    # Restore blocking mode
    fcntl.fcntl(sock, fcntl.F_SETFL, flags)
    return True

    # Simple blocking connect (commented out for original functionality)
    # sock.settimeout(timeout)
    # try:
    #     sock.connect((ip, port))
    #     sock.settimeout(None)
    #     return True
    # except socket.timeout:
    #     return False
    # except Exception as e:
    #     print(f"Connection error: {e}")
    #     return False


def getArch():
    return "x86_64"


def getPortz():
    """
    Checks for the existence of specific files and returns a port or "Unknown Port".

    Returns:
        str: The port number or "Unknown Port".
    """
    if os.access("/usr/bin/python", os.F_OK):
        return "22"
    elif os.access("/usr/bin/python3", os.F_OK):
        return "22"
    elif os.access("/usr/bin/perl", os.F_OK):
        return "22"
    elif os.access("/usr/sbin/telnetd", os.F_OK):
        return "22"
    else:
        return "Unknown Port"


def sockprintf(sock, message, *args):
    """
    Formats a message, appends a newline, and sends it over a socket.

    Args:
        sock (socket.socket): The socket to send the message through.
        message (str): The format string.
        *args: Arguments to format the message.

    Returns:
        int: The number of bytes sent, or -1 on failure.
    """
    try:
        # Format the message with the provided arguments
        formatted_message = message % args

        # Append a newline to the message
        formatted_message += '\n'

        # Send the message over the socket
        bytes_sent = sock.send(formatted_message.encode('utf-8'))
        return bytes_sent
    except Exception as e:
        return -1


def recvLine(sock, buffer, size):
    """
    Reads data from a socket until a newline is encountered, the buffer is full, or an error occurs.

    Args:
        sock (socket.socket): The socket to read from.
        buffer (bytearray): The buffer to store the read data.
        size (int): The maximum size of the buffer.

    Returns:
        int: The number of bytes read, or -1 on error.
    """
    buffer[:] = b'\x00' * size  # Clear the buffer
    timeout = 30  # Timeout in seconds

    for _ in range(10):  # Retry up to 10 times
        ready = select.select([sock], [], [], timeout)
        if ready[0]:  # If the socket is ready for reading
            break
    else:
        return -1  # Timeout occurred

    bytes_read = 0
    while bytes_read < size - 1:  # Leave space for null terminator
        try:
            data = sock.recv(1)  # Read one byte
            if not data:  # Connection closed
                buffer[bytes_read] = 0
                return -1
            buffer[bytes_read] = data[0]
            bytes_read += 1
            if data == b'\n':  # Stop at newline
                break
        except socket.error:
            buffer[bytes_read] = 0
            return -1

    buffer[bytes_read] = 0  # Null-terminate the buffer
    return bytes_read


def trim(param):
    """
    Removes leading and trailing whitespace from a string.

    Args:
        param (str): The input string to trim.

    Returns:
        str: The trimmed string.
    """
    # Remove leading and trailing whitespace
    return param.strip()


import os
import signal


def processCmd(param_count, params):
    """
    Processes commands and their parameters, performing specific actions based on the command type.

    Args:
        param_count (int): The number of parameters.
        params (list): The list of parameters.
    """
    global numpids, pids, mainCommSock

    cmd = params[0]

    if cmd == "TCP":
        if param_count < 6:
            return

    elif cmd == "UDP":
        if param_count < 6:
            return


    elif cmd == "VSE":
        if param_count < 6:
            return


    elif cmd == "STDHEX":
        if param_count < 4:
            return


    elif cmd == "STD":
        if param_count < 4:
            return


    elif cmd == "NFODROP":
        if param_count < 4:
            return


    elif cmd == "OVHKILL":
        if param_count < 4:
            return


    elif cmd == "XMAS":
        if param_count < 4:
            return

    elif cmd == "CRUSH":
        if param_count < 6:
            return

    elif cmd == "STOMP":
        if param_count < 6:
            return

    elif cmd == "STOP":
        for pid in pids:
            if pid != 0 and pid != os.getpid():
                os.kill(pid, signal.SIGKILL)

        # close the main communication socket
        if mainCommSock is not None:
            try:
                mainCommSock.close()
            except Exception as e:
                print(f"Error closing main communication socket: {e}")
            mainCommSock = None


def ftcp(target, port, duration, packets, data, threads, delay):
    """
    Placeholder for the ftcp function.
    """
    pass


def SendUDP(target, port, duration, packets, delay, flag):
    """
    Placeholder for the SendUDP function.
    """
    pass


def vseattack(target, port, duration, packets, data, threads, interval, extra):
    """
    Placeholder for the vseattack function.
    """
    pass


def SendSTDHEX(target, duration, packets):
    """
    Placeholder for the SendSTDHEX function.
    """
    pass


def SendSTD(target, duration, packets):
    """
    Placeholder for the SendSTD function.
    """
    pass


def stdhexflood(target, duration, packets):
    """
    Placeholder for the stdhexflood function.
    """
    pass


def SendSTD_HEX(target, duration, packets):
    """
    Placeholder for the SendSTD_HEX function.
    """
    pass


def rtcp(target, duration, packets, flag1, flag2, delay):
    """
    Placeholder for the rtcp function.
    """
    pass


def astd(target, port, duration, flag):
    """
    Placeholder for the astd function.
    """
    pass


def atcp(target, port, duration, packets, data, spoof, interval):
    """
    Placeholder for the atcp function.
    """
    pass


def audp(target, port, duration, packets, spoof, interval):
    """
    Placeholder for the audp function.
    """
    pass


def listFork():
    """
    Placeholder for the listFork function.
    Simulates forking a process.
    """
    return os.fork()


def main():
    global numpids, pids, mainCommSock, daemon

    # Deterministic randomness
    seed = os.getpid() ^ int(time.time())
    random.seed(seed)
    init_rand(seed)

    getOurIP()

    if daemon:
        if os.fork() != 0:
            os.wait()
            os._exit(0)

        if os.fork() != 0:
            os._exit(0)

        os.setsid()
        os.chdir("/")
        signal.signal(signal.SIGPIPE, signal.SIG_IGN)

    while True:
        while initConnection() != 0:
            time.sleep(5)

        print(f"\x1b[1;92mConnected to {commServer[currentServer]}\x1b[0m")
        architecture = getArch()
        our_port = getPortz()
        ourIPStr = ".".join(map(str, ourIP))
        ip = socket.inet_ntoa(socket.inet_aton(ourIPStr))
        hello = "\x1b[1;95mDevice Connected: %s | Port: %s | Arch: %s\x1b[0m"
        print(f"Sending hello: {hello % (ip, our_port, architecture)}")
        sockprintf(mainCommSock, hello, ip, our_port, architecture)

        while True:
            buffer = bytearray(buffer_size)
            bytes_received = recvLine(mainCommSock, buffer, buffer_size)
            if bytes_received == -1:
                break

            for pid_index in range(numpids):
                pid = pids[pid_index]
                if os.waitpid(pid, os.WNOHANG)[0] > 0:
                    pids.pop(pid_index)
                    numpids -= 1

            buffer = buffer[:bytes_received].decode('utf-8')
            trim(buffer)

            if buffer.startswith("!"):
                command_line = buffer[1:].strip()
                command_with_params = command_line.split(" ")
                print(f"\033[94mReceived command: {command_with_params}\033[0m")
                logging.info("Received command: %s", command_line)

                if command_with_params[0].upper() == "STOP":
                    # Close the socket and exit the loop
                    if mainCommSock:
                        mainCommSock.close()
                        mainCommSock = None
                    break
                if len(command_with_params) >= 1:
                    command = command_with_params[0].upper()
                    params = command_with_params[1:]
                    processCmd(len(command_with_params), command_with_params)


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="Bot123 C2 Milker")
    # server IP, default to 'localhost'
    # server port (default to 6969)
    # deamonize option (default to False)
    parser.add_argument('--server', type=str, default='0.0.0.0', help='Server IP address')
    parser.add_argument('--port', type=int, default=6969, help='Server port number')
    parser.add_argument('--daemonize', action='store_true', help='Run as a daemon (annoying to kill after)')
    args = parser.parse_args()

    server = args.server
    port = args.port
    daemonize = args.daemonize

    logging.basicConfig(
        filename="commands.log",
        level=logging.INFO,
        format="%(asctime)s - %(message)s",
        datefmt="%Y-%m-%d %H:%M:%S"
    )

    print(f"\033[1;92mBot123 C2 Milker starting...\033[0m")

    if daemonize:
        print(f"\033[1;91mRunning in daemon mode, to kill the program you need to use `killall -9 python3` or `kill -KILL {os.getpid()}`\033[0m")
        print("You won't be able to see anything in the terminal, but it will run in the background.")

    commServer.append(f"{server}:{port}")
    daemon = daemonize



    main()
