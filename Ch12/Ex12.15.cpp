#include <iostream>
#include <memory>
#include <string>

struct destination
{
    std::string destinationName;
    unsigned destinationID;
    destination(const std::string& s = " ", unsigned i = 0): destinationName(s), destinationID(i) {}
};

struct connection
{
    destination* connectionDest;
    int port;
};

connection connect(destination* d, int i)
{
    connection c;
    c.connectionDest = d;
    c.port = i;
    std::cout << "Setting up new connection to " << c.connectionDest->destinationName << " using ID code " << c.connectionDest->destinationID << " at port " << c.port << "." << std::endl;
    return c;
}

void disconnect(connection c)
{
    std::cout << "Disconnecting from " << c.connectionDest->destinationName << std::endl;
    c.connectionDest = nullptr;
}

void endConnection(connection* c)
{
    disconnect(*c);
}

void manageConnection(destination& d)
{
    connection c = connect(&d,5);
    std::shared_ptr<connection> p(&c, [] (connection* c) {disconnect(*c);});
    std::cout << "Managing connection of " << p->connectionDest->destinationName << std::endl;
}

int main()
{
    destination d("Test", 555);
    manageConnection(d);
}

