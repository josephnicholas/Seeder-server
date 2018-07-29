#include <vector>
#include <string>
#include <iostream>

//Boost Libraries
#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace boost::asio;
using namespace boost::asio::ip;

io_service io_service_server;
tcp::endpoint tcp_endpoint_server{tcp::v4(), 8081};
tcp::acceptor tcp_acceptor_server{io_service_server, tcp_endpoint_server};
tcp::socket tcp_socket{io_service_server};
std::string data;

std::vector<std::string> nodes;

//Node functions - refactor
std::string get_client_ip() {
    return (tcp_socket.remote_endpoint().address().to_string() + ":" + std::to_string(tcp_socket.remote_endpoint().port()));
}

//Server functions - refactor

void write_to_client(const std::string &msg) {
    tcp_socket.write_some(buffer(msg));
}

void write_handler(const boost::system::error_code &ec,
        size_t bytes_transferred ) {
    if (!ec){
        //tcp_socket.write_some(buffer(msg));
    }
}

void accept_handler(const boost::system::error_code &ec) {
    if (!ec){
        //std::string say_hello = "hello " + get_client_ip();
        //data = say_hello;
        //async_write(tcp_socket, buffer(data), write_handler);
    }
}


void add_node_to_list(const boost::system::error_code &ec) {
    if(!ec) {
        while(true) {
            std::string msg_added_client = "added: " + get_client_ip() + "\n";
            data = msg_added_client;

            nodes.push_back(data);
            write_to_client("hello from node server " + data);
        }
    }
}



int main() {
    tcp_acceptor_server.listen();
    tcp_acceptor_server.async_accept(tcp_socket, add_node_to_list);
    io_service_server.run();
}