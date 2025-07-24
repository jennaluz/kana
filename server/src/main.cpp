#include <iostream>

#include "http_server.hpp"

namespace {

void register_endpoints(HttpServer& server);

} // namespace

int main()
{
    auto server = HttpServer{"localhost", 8080};

    register_endpoints(server);

    server.listen();
}

namespace {

void register_endpoints(HttpServer& server)
{
    server.register_endpoint("/api/v1/foo")
        .get([](auto const& request, auto& response) {
            response.set_status(HttpServer::Status::Ok);
            response.set_body("{\"Foo\": \"Bar\"}");
        });
}

} // namespace
