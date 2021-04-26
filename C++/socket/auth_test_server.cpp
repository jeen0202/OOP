#include "ServerSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(std::string str, char delimiter);
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
            std::string data,id,pass,cId,cPass;
            std::vector<std::string> result;
            try
            {
                while(true)
                {
                    
                    //Client에서 보내는 메시지 수신
                    new_sock >> data;
                    result = split(data,':');
                    id = result[0];
                    pass = result[1];
                    cId = "sejing";
                    cPass = "hijacking";
                    std::cout << "id : " << id << " pass : " <<pass <<std::endl;
                    if(id.compare(cId)==0)
                    {
                        if(pass.compare(cPass)==0)
                            data = "Success";
                        else
                            data = "Fail, Wrong Password";
                    }else
                    {
                        data = "Fail! Wrong ID";
                    }
                    // if(data=="1324")
                    //     data = "Success";
                    // else
                    //     data = "Fail";    
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

std::vector<std::string> split(std::string input, char delimiter) {
    std::vector<std::string> answer;
    std::stringstream ss(input);
    std::string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}