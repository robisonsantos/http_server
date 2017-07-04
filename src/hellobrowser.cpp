#include <boost/network/protocol/http/server.hpp>

#define PORT "8888"

namespace http = boost::network::http;

struct handler;
typedef http::server<handler> http_server;

struct handler {
    void operator() (http_server::request const &request,
                     http_server::response &response) {
        response = http_server::response::stock_reply(
            http_server::response::ok, "Hello, world from CPPLib!");
    }

    void log(http_server::string_type const &info) {
        std::cerr << "ERROR: " << info << '\n';
    }
};

int main(int arg, char * argv[]) {
    handler handler_;
    http_server::options options(handler_);
    http_server server_( options.address("0.0.0.0").port(PORT));
    std::cout << "Running server at port: " << PORT << '\n';
    server_.run();
}

