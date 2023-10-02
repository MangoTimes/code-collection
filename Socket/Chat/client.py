import socket


def main():
    # STEP 1 : define host and port for the socket server

    host = "127.0.0.1"
    port = 50183
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print("Waiting for connection")
    # STEP 2 : setup a connection
    server.connect((host, port))
    print("Welcome to the Server")

    while True:
        message = input("Say Something : ")
        # Message sent to server
        server.send(message.encode("ascii"))

        # Message received from server
        data = server.recv(1024)

        # Print the received message from server
        print(str(data.decode("ascii")))


if __name__ == "__main__":
    main()
