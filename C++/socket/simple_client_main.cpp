#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main(int argc, int argv[])
{
    try
    {
        ClientSocket client_socket ("localhost", 30000);

        std::string reply;
        try{
            //Client에서 Server에 Message 전송
            client_socket << "Test";
            //Server에서 보내는 응답 수신
            client_socket >> reply;
        }catch(SocketException&) {}
        
        std::cout << "We recieved this response from the server:\n\'" << reply <<"\''\n";;
    
    }
    catch(SocketException& e)
    {
        std::cout << "Exception was caught :" << e.description() << std::endl;
    }
    return 0;
    
}