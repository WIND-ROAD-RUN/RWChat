#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

void client(boost::asio::io_context& io_context, const std::string& host, const std::string& port) {
    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve(host, port);
    tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);
    for (;;) {
        std::array<char, 128> buf;
        boost::system::error_code error;
        size_t len = socket.read_some(boost::asio::buffer(buf), error);
        if (error == boost::asio::error::eof)
            break; // Connection closed cleanly by peer.
        else if (error)
            throw boost::system::system_error(error); // Some other error.
        std::cout.write(buf.data(), len);
    }
}

int main() {
    try {
        boost::asio::io_context io_context;
        client(io_context, "8.155.13.117", "2048"); // 使用 8080 端口
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}