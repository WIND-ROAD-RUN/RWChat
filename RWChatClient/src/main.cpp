//#include <boost/asio.hpp>
//#include <iostream>
//
//using boost::asio::ip::tcp;
//
//void server(boost::asio::io_context& io_context, short port) {
//    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
//    for (;;) {
//        tcp::socket socket(io_context);
//        acceptor.accept(socket);
//        std::string message = "Hello from server!";
//        boost::system::error_code ignored_error;
//        boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
//    }
//}
//
//int main() {
//    try {
//        boost::asio::io_context io_context;
//        server(io_context, 8080); // 使用 8080 端口
//    }
//    catch (std::exception& e) {
//        std::cerr << "Exception: " << e.what() << "\n";
//    }
//    return 0;
//}

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
