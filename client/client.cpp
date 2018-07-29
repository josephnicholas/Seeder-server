//
// Created by joseph-dev on 7/28/18.
//

#include <array>
#include <string>
#include <iostream>
#include <vector>

//Boost Libraries
#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

io_service      ioservice_client;
tcp::endpoint   tcp_endpoint{ip::address::from_string("127.0.0.1"), 8081};
tcp::socket     tcp_socket(ioservice_client);

const size_t MAX_LENGTH = 1024;
char data_from_server[MAX_LENGTH];


bool isConnected = false;
void hello_to_join_server() {
    std::string msg("hello\n");
    tcp_socket.write_some(buffer(msg));
    std::cout << "hello sent!" << std::endl;
}

void start_connection() {
    std::cout << "Connecting to server . . . . !"<<std::endl;
    try {
        tcp_socket.connect(tcp_endpoint);
        hello_to_join_server();
        size_t length = tcp_socket.read_some(buffer(data_from_server, MAX_LENGTH));

        std::cout.write(data_from_server, length);
        isConnected = true;
    }catch (boost::system::system_error &ec) {
        std::cout << "Terminate client: exception "<< ec.what() <<std::endl;
    }

}

int main(){
    start_connection();
}