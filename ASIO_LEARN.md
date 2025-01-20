


## 异步方式实现echo server

```cpp


#define BUF_SIZE 8192

using btcp = boost::asio::ip::tcp;

class session : public std::enable_shared_from_this<session>
{
public:
    session(btcp::socket &&_sock) : m_socket(std::move(_sock)) {}

    void read()
    {
        std::cout << "Ready Read" << std::endl;
        auto self(shared_from_this());
        m_socket.async_read_some(boost::asio::buffer(rwbuff),[this, self](boost::system::error_code ec, std::size_t length) {
            if (ec)
                return;

            write(length);
        });
    }

    void write(std::size_t len)
    {
        auto self(shared_from_this());
        boost::asio::async_write(m_socket, boost::asio::buffer(rwbuff, len), [this, self](boost::system::error_code ec, std::size_t length){
            if (!ec) {
                read();
            }
        });
    }
private:
    btcp::socket m_socket;
    std::array<char, BUF_SIZE> rwbuff;
};

class acceptor
{
public:
    acceptor(boost::asio::io_context &_cxt, uint16_t port) :
        acc(_cxt, btcp::endpoint(btcp::v4(), port)) {}

    void accept()
    {
        acc.async_accept([this](boost::system::error_code ec, btcp::socket socket){
            if (!ec) {
                std::cout << "Conn ESTB" << std::endl;
                std::make_shared<session>(std::move(socket))->read();
            }

            std::cout << "Accept Continue" << std::endl;
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
```


## 配合协程实现异步 echo server

```cpp

```