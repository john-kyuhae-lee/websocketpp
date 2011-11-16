/*
 * Copyright (c) 2011, Peter Thorson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the WebSocket++ Project nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL PETER THORSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef WEBSOCKETPP_ROLE_CLIENT_HPP
#define WEBSOCKETPP_ROLE_CLIENT_HPP

#include "../endpoint.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>

#include <iostream>

namespace websocketpp {
namespace role {

template <class endpoint>
class client {
public:
	// handler interface callback class
	class handler {
		virtual void on_action() = 0;
	};
	
	typedef boost::shared_ptr<handler> handler_ptr;
	
	// types
	typedef client<endpoint> type;
	typedef endpoint endpoint_type;
	typedef typename endpoint_traits<endpoint>::connection_ptr connection_ptr;
	
	client (boost::asio::io_service& m,handler_ptr h) : m_handler(h),m_io_service(m) {
		std::cout << "setup client endpoint role" << std::endl;
	}
	
	void connect() {
		static_cast< endpoint_type* >(this)->start();
	}
	
	void public_api() {
		std::cout << "endpoint::client::public_api()" << std::endl;
	}
protected:
	handler_ptr get_handler() {
		return m_handler;
	}
	
	void protected_api() {
		std::cout << "endpoint::client::protected_api()" << std::endl;
	}
private:
	void private_api() {
		std::cout << "endpoint::client::private_api()" << std::endl;
	}
	handler_ptr m_handler;
	boost::asio::io_service& m_io_service;
};


} // namespace role
} // namespace websocketpp

#endif // WEBSOCKETPP_ROLE_CLIENT_HPP
