#include <array>
#include <string>
#include <iostream>

//Boost Libraries
#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioService;
tcp::endpoint tcp_endpoint{tcp::v4(), 8081};
tcp::acceptor tcp_acceptor{ioService, tcp_endpoint};
tcp::socket tcp_socket{ioService};
string data;

void write_handler(const boost::system::error_code &ec,
        size_t bytes_transferred) {
    if (!ec){
        tcp_socket.shutdown(tcp::socket::shutdown_send);
    }
}

void accept_handler(const boost::system::error_code &ec) {
    if (!ec){
        string say_hello = "Hello World \n";
        data = say_hello;
        async_write(tcp_socket, buffer(data), write_handler);
    }
}

void add_client_to_node_list(const boost::system::error_code &ec) {

}

void return_node_list(const boost::system::error_code &ec) {

}

int main() {

    tcp_acceptor.listen();
    tcp_acceptor.async_accept(tcp_socket, accept_handler);
    ioService.run();
}