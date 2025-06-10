import socket
import select
import time
import random

HOST = '0.0.0.0'
PORT = 6969


def start_server():
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
