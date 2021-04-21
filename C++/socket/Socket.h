
#ifndef Socket_class
#define Socket_class


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

const int MAXHOSTNAME = 200;
const int MAXCONNECTIONS = 5;
const int MAXRECV = 500;

class Socket
{
    public :
    Socket();
    virtual ~Socket();
    //서버 초기화
    bool create();
    bool bind (const int port);
    bool listen() const;
    bool accept (Socket&) const;

    //클라이언트 초기화
    bool connect (const std::string host, const int port);

    //데이터 전송
    bool send(const std::string s) const;
    int recv (std::string& s) const;

    void set_non_blocking(const bool);
    bool is_valid() const {return m_sock != -1;}
    
    private:
    int m_sock;
    sockaddr_in m_addr;
};

#endif