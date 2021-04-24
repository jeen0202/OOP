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
        while(1)
        {
            std:: cout << "Input Password >> ";
            std:: cin >> reply;
            try{
                
                    //Client에서 Server에 Message 전송                
                    client_socket << reply;
                    //Server에서 보내는 응답 수신
                    client_socket >> reply;
                    // if(reply=="Success"){
                    //     reply = "Login Success!";                    
                    // }else{
                    //     reply = "Fail";
                    // }
                
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