import socket
import select
import time
import random

HOST = '0.0.0.0'
PORT = 6969


def start_server():
    """
    Starts a command-and-control (C2) server that listens for incoming bot connections.

    The server creates a TCP socket, binds it to the specified HOST and PORT, and listens for incoming connections.
    For each connection, it accepts the client, prints the client's address, and handles the client using the handle_client function.
    After handling, the client socket is closed.

    Returns:
        None
    """
    server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_sock.bind((HOST, PORT))
    server_sock.listen(5)
    print("C2 clone started, waiting for bots...")

    while True:
        client_sock, addr = server_sock.accept()
        print("Connection from", addr)
        if handle_client(client_sock):
            client_sock.close()


def handle_client(client_sock):
    """
    Handles communication with a connected client socket.

    This function waits for a specific greeting message from the client indicating a device connection.
    If the expected greeting is received, it randomly selects and shuffles a subset of predefined command
    strings, sends them to the client with a delay between each, and finally sends a "! STOP" command.
    If the greeting is not as expected, it logs the unexpected message. Any exceptions during processing
    are caught and logged.

    Args:
        client_sock (socket.socket): The client socket object to communicate with.

    Returns:
        bool: Always returns True after handling the client.
    """
    client_sock.settimeout(30)
    try:
        data = receive_line(client_sock)
        if data and "Device Connected:" in data:
            commands = [
                "! TCP 127.0.0.1 80 5 128 test",
                "! UDP 127.0.0.1 53 5 64",
                "! VSE 127.0.0.1 27015 5 1024 123",
                "! STDHEX 127.0.0.1 5 128",
                "! STD 127.0.0.1 5 128",
                "! NFODROP 127.0.0.1 5 128",
                "! OVHKILL 127.0.0.1 5 128",
                "! XMAS 127.0.0.1 5 128",
                "! CRUSH 127.0.0.1 80 5 128 test 1 10",
                "! STOMP 127.0.0.1 80 5 128 test 1 10"
            ]
            # pick a random number of cammands in a random order
            random.shuffle(commands)
            num_commands = random.randint(1, len(commands))
            commands = commands[:num_commands]
            for cmd in commands:
                print("Sending command:", cmd)
                client_sock.sendall(cmd.encode("utf-8") + b"\n")
                time.sleep(1)

            client_sock.sendall("! STOP".encode("utf-8") + b"\n")
        else:
            print("Unexpected greeting:", data)
    except Exception as e:
        print("Error:", e)
    return True


def receive_line(sock):
    """
    Receives a line of text from a socket, reading one byte at a time until a newline character is encountered,
    the connection is closed, or a timeout occurs.

    Args:
        sock (socket.socket): The socket object to read from.

    Returns:
        str: The received line as a UTF-8 decoded string (excluding the newline character).
             Returns an empty string if the connection is closed or no data is received within the timeout.
    """
    line = []
    while True:
        ready = select.select([sock], [], [], 5)
        if ready[0]:
            char = sock.recv(1)
            if not char:
                break
            if char == b'\n':
                break
            line.append(char)
        else:
            break
    return b''.join(line).decode('utf-8', errors='ignore')


if __name__ == '__main__':
    start_server()
