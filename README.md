### images
<img src="/imgs/client-server.png">
<img src="/imgs/socket2.png">


This is a client-server chat application built in C using Socket Programming. It allows a client and a server to communicate over a network using TCP sockets.

### How to Clone the Project 

``` bash
git clone https://github.com/KaraniAbdellah/client-server-in-c.git
cd client-server-in-c/app
```

``` bash
# Compile the server
gcc server.c -o server
./server port_number 
# Compile the client
gcc client.c -o client
./client server_addr_ip port_number
```

<b>Example: </b>

``` bash
./server 9898
./client 127.0.0.1 9898
```


**made with love by <a href="">abdellah karani</a>**



