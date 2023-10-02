import socket
from _thread import start_new_thread


def main():
    # STEP 1 : define host and port for the socket server
    host = ""
    port = 50183
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # STEP 2 : BIND
    server.bind((host, port))

    # Put the socket into listening mode
    server.listen(5)
    print("Waiting for a connection...")
    thread_num = 1
    # STEP 6 : use while loop to run server endlessly
    while True:
        # STEP 7 : Establish connection with client
        c, addr = server.accept()

        print('Connected to :', addr[0], ':', addr[1])
        print('Thread Number: '+str(thread_num))
        thread_num+=1
        # Start the new thread and return its identifier
        start_new_thread(threaded_client, (c,))


# STEP 3, STEP 4 threaded client
def threaded_client(client):
    while True:
        # Data is received from the client
        data = client.recv(1024)
        # STEP 5 Appened data
        data = "Server Says : "+str(data.decode("ascii"))

        # Send back reversed string to the client
        client.send(data.encode("ascii"))



if __name__ == '__main__':
    main()