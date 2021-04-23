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
                    //Client에서 보내는 메시지 수신
                    new_sock >> data;
                    if(data=="1324")
                        data = "Success";
                    else
                        data = "Fail";    
                    //Client에 응답메시지 전송
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