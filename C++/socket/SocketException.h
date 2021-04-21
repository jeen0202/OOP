
#ifndef SocketException_class
#define SocketException_class

#include <string>

class SocketExecption
{
    public:
    SocketExecption(std::string s) : m_s (s) {};
    ~SocketExecption() {};

    std::string description() {return m_s;}
    private:
    std:: string m_s;
};

#endif