#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>

int main(int argc, int argv[])
{
    std::cout << "running....\n";

    try
    {
        //Socket 생성
        ServerSocket server(30000);

        while(true)
        {
            ServerSocket new_sock;
            server.accept(new_sock);
            try
            {
                while(true)
                {
                    std::string data;
                    new_sock >> data;
                    new_sock << data;
                }
            }
            catch(SocketException&){}
            
        }
    }catch(SocketException& e)
    {
        std::cout << "EXception was caught: " << e.description() << "\nExisting.\n";
    }
    return 0;
}