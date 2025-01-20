#include <iostream>
#include <boost/asio.hpp>

using btcp = boost::asio::ip::tcp;

class acceptor
{
public:
    acceptor(boost::asio::io_context &_cxt, uint16_t port) :
            acc(_cxt, btcp::endpoint(btcp::v4(), port)) {}

    void accept()
    {
        acc.async_accept([this](boost::system::error_code ec, btcp::socket socket){
            if (ec)
                return;

            for (;;)
            {
                
            }

            accept();
        });
    }

private:
    btcp::acceptor acc;
};

void echo_server()
{
    boost::asio::io_context cxt;
    acceptor ac(cxt, 8888);
    ac.accept();
    cxt.run();
}

int main()
{
    return 0;
}
