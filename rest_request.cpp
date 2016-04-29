//
// Created by windr on 4/27/16.
//

#include "rest_request.hpp"
using namespace cse;
std::stringstream stream;
std::string rest_request::create(const std::string uri, const std::string body) {
    try {
        return make_request(METHOD::CREATE, uri, body);
    }
    catch (std::exception e) {
        throw e;
    }
}

std::string rest_request::retrieve(const std::string uri, const std::string body) {
    try {
        return make_request(METHOD::RETR, uri, body);
    }
    catch (std::exception e) {
        throw e;
    }
}

std::string rest_request::update(const std::string uri, const std::string body) {
    try {
        return make_request(METHOD::UPDATE, uri, body);
    }
    catch (std::exception e) {
        throw e;
    }
}

std::string rest_request::dele(const std::string uri, const std::string body) {
    try {
        return make_request(METHOD::DELETE, uri, body);
    }
    catch (std::exception e) {
        throw e;
    }
}

std::string rest_request::make_request(const rest_request::METHOD m, const std::string uri, const std::string body) {
    try {
        http_client client(U(uri)) ;
        method req_method ;
        switch (m) {
            case METHOD::CREATE: {
                req_method = methods::POST;
                break;
            }
            case METHOD::DELETE: {
                req_method = methods::DEL;
                break;
            }
            case METHOD::UPDATE :{
                req_method = methods::PUT;
                break;
            }
            case METHOD::RETR : {
                req_method = methods::GET;
                break;
            }
        }
        pplx::task<void> requestTask = client.request(req_method, "", body).
        then([=](http_response response) {
            concurrency::streams::stringstreambuf str;
            response.body().read_to_end(str).get();
            auto & target = str.collection();
            stream<<target.c_str();
        });
        requestTask.wait();
        return stream.str();
    }
    catch (std::exception e) {
        throw e;
    }
}
