#include "ClientSocket.h"
#include "SocketException.h"
#include "Message.h"
#include <iostream>
#include <string>

int main(int argc, int argv[])
{
    //메시지 전송을 위한 객체선언
    Message msg;
    std::string inputPass,inputId;
    std::string reply;
    try
    {
        ClientSocket client_socket ("localhost", 30000);        
        while(1)
        {   
            std:: cout << "Input ID >> ";
            std:: cin >> inputId;
            std:: cout << "Input Password >> ";
            std:: cin >> inputPass;
            msg.setId(inputId);
            msg.setPass(inputPass);
            reply = msg.toString();

            // std:: cout << "Input Password >> ";
            // std:: cin >> reply;
            try{
                
                    //Client에서 Server에 Message 전송                
                    client_socket << reply;
                    //Server에서 보내는 응답 수신
                    client_socket >> reply;
                
            }catch(SocketException&) {}        
            std::cout << "Login " << reply <<"\n";;  
            if(reply=="Success")
                break;     
        }   
}
    catch(SocketException& e)
    {
        std::cout << "Exception was caught :" << e.description() << std::endl;
    }
    return 0;
    
}