#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>

using namespace std;

void print(const boost::system::error_code& , boost::asio::steady_timer* t, int* count)
{
    if(*count < 5)
    {
        cout << *count << endl;
        ++(*count);

        t->expires_at(t->expiry() + boost::asio::chrono::seconds(5));
        t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));
    }
}

int main()
{
    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

    int count = 0;
    t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));
    io.run();

    cout << "Final Count is: " << count << endl;

    return 0;
}