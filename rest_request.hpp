//
//  rest_request.hpp
//  cpprest
//
//  Created by 冉惟之 on 16/4/29.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef rest_request_hpp
#define rest_request_hpp
//
// Created by windr on 4/25/16.
//

#ifndef CPPREST_HTTP_REQUEST_H
#define CPPREST_HTTP_REQUEST_H

#include <iostream>

#include <cpprest/details/basic_types.h>
#include <pplx/pplxtasks.h>
#include <cpprest/filestream.h>
#include <cpprest/http_client.h>
#include <cpprest/rawptrstream.h>

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

namespace cse {
    class rest_request {
    public:
        
        std::string create(const std::string uri, const std::string body);
        
        std::string retrieve(const std::string uri, const std::string body);
        
        std::string update(const std::string uri, const std::string body);
        
        std::string dele(const std::string uri, const std::string body);
        
        
    private:
        
        enum METHOD {
            CREATE,
            RETR,
            UPDATE,
            DELETE
        };
        
        std::string make_request(const METHOD m,const std::string uri, const std::string body);
        
        
    };
}
#endif //CPPREST_HTTP_REQUEST_H

#endif /* rest_request_hpp */
