#ifndef Message_CLASS
#define Message_CLASS

#include <iostream>
#include <string>
class Message
{
private:
    std::string userid;
    std::string pass;

public:
    Message();
    Message(std::string,std::string);
    std::string getId();
    std::string getPass();
    void setId(std::string);
    void setPass(std::string);
    std::string toString();
    ~Message();
};

Message::Message()
{
}

Message::~Message()
{
}

std::string Message::getId()
{
    return this->userid;
}

std::string Message::getPass()
{
    return this->pass;
}

void Message::setId(std::string newId)
{
    this->userid = newId;
}

void Message::setPass(std::string newPass)
{
    this->pass = newPass;
}

std::string Message::toString(){
    std::string result;
    result += this->userid;
    result += ":";
    result += this->pass;
    //std::cout << "result : " << result << std::endl;
    return result;
}
#endif