#include <termios.h>
#include <iostream>
#include <array> //arr.size()
#include <string>
#include <random>
#include <sstream>
#include <algorithm>
#include <unistd.h>
#include "Menu.h"
//#include "Servant.cpp"
#include <fstream>

using namespace std;
float lastbattle = 200;
Player enemy("RED");
Player player("player"); 
vector<string> split(string str, char delimeter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while(getline(ss,temp,delimeter)){
        internal.emplace_back(temp);
    }
    return internal;
}

int getKey(int is_echo =0)
{
    int ch;
    struct termios old;
    struct termios current;
    /* 현재 설정된 terminal i/o 값을 backup함 */ 
    tcgetattr(0, &old); 
    /* 현재의 설정된 terminal i/o에 일부 속성만 변경하기 위해 복사함 */ 
    current = old; 
    /* buffer i/o를 중단함 */ 
    current.c_lflag &= ~ICANON;
    if (is_echo) { 
        // 입력값을 화면에 표시할 경우 
        current.c_lflag |= ECHO; } 
    else { // 입력값을 화면에 표시하지 않을 경우
         current.c_lflag &= ~ECHO; } /* 변경된 설정값으로 설정합니다.*/ 
    tcsetattr(0, TCSANOW, &current); 
    ch = getchar(); 
    tcsetattr(0, TCSANOW, &old);
    return ch;
}

void clrscr(){ system("clear"); }


void Menu::main_menu()
{    
    char ch;
    while(1)
    {

        clrscr();
        cout<<"*************************************************************"<<endl;
        cout<<"*************************************************************"<<endl;
        cout <<"S E R V A N T W O R L D" << endl;        
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;       
        cout <<"1: Servant 잡기" << endl;        
        cout <<"2: 내 Servant" << endl;        
        cout <<"3: 도전하기" << endl;   
        cout <<"0: 종료" << endl;       
        cout <<"선택 : ";
        ch = getKey();
        if (ch == '1')
        {
            clrscr();
            serv_menu();

        }
        else if (ch == '2')
        {
            clrscr();
            list_of_servant();
               
        }
        else if (ch == '3')
        {
            clrscr();
            battle_menu();
        }
        else if (ch == '0')            
            break ;
        }
        clrscr();
    }
void Menu::serv_menu()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> diskill(1,MAXSKILL);
    uniform_int_distribution<int> skill(0,3);    
    char ch;    
    vector<string> servBox;
    vector<Skill> newSkills;    
    string line,name,skillname;
    int level,maxSkill,skillcount[4];
    float damage,acc;
    Servant newServ;    
    Skill newSkill;    
    //string newSkills[MAXSKILL];       
    ifstream file;
    file.open("Servant.txt", ios::in);
    do
    {
        getline(file,line);
        servBox.emplace_back(line);
    } while (file.peek()!=EOF);
    file.close();
    
    //cout << "Exit(0)" << endl;
    while(1)
    {
        uniform_int_distribution<int> dis(0,servBox.size()-1);
        //line = servBox.at(dis(gen));
        vector<string> skillBox;
        //cout << "Line => " << line << endl;
        name = servBox.at(dis(gen));
        //cout << "name " << name << endl;    
        uniform_int_distribution<int> lv(1,10);
        level = lv(gen);
        newServ.setName(name);
        newServ.setLevel(level);
        file.open("SKILL.txt", ios::in);
        do
        {        
            getline(file,line);
            if(split(line,' ')[0] == name)
            {
                        
                //cout << "line => " << line << endl;
                skillBox.emplace_back(line);
            }
        } while (file.peek()!=EOF);
        file.close();
        maxSkill = diskill(gen);
        //cout << "maxskill" << maxSkill << endl;
        newSkills.clear();
        int i,j =0;
        newSkills.reserve(maxSkill);
        //cout << "maxSkill=> " << maxSkill << endl;
        for(i =0;i<maxSkill;i++)
        {
            skillcount[i] = skill(gen);
            
            //cout << "Check " << i << endl;        
            for(j = 0; j<i;j++)
            {
                //cout << "check " << j << endl;
                if(skillcount[j] == skillcount[i])
                {
                    i--;               
                    newSkills.pop_back();
                    //cout<<"POP " << newSkills.size()<< endl;                
                    break;                    
                }                      
            };
            //cout << "Check " << skillcount[i] << endl;
            //cout << "skillBox" << skillBox.size() << endl;
            skillname = split(skillBox.at(skillcount[i]),' ')[1];                        
            damage = stof(split(skillBox.at(skillcount[i]),' ')[2]);
            damage = presicion(damage);
            acc = stof(split(skillBox.at(skillcount[i]),' ')[3]);
            acc = presicion(acc);
            newSkill.setName(skillname);
            newSkill.setDamage(damage);
            newSkill.setAccuracy(acc);                    
            newSkills.emplace_back(newSkill);                   
            //cout << "==Check==\n" << skillname<<damage<<acc<<endl;        
            // newSkills[i] = skillBox.at(skillcount[i]);        
        }

        //cout << "Final Check => " << newSkills.size() << endl;
        
        newServ.setSkills(newSkills);
        //cout << "Empty check => " << newServ.getSkills().size() << endl;
        cout <<"======S E R V A N T 잡기=====" << endl;        
        cout << "이름 : " << newServ.getName() << " Level : " << newServ.getLevel() << endl;
        cout << "==========기 술==========" << endl;
        for(int i = 0; i <newServ.getSkills().size();i++)
        {       
                 
                cout << newServ.getSkills().at(i).toString();
                //cout << newSkills[i].getName() <<" : " <<newSkills[i].getDamage() << endl;
        }
        // for(int i = 0; i <maxSkill;i++)
        // {
        //     if(!newSkills[i].empty())
        //         cout << split(newSkills[i],' ')[1] <<" : " <<split(newSkills[i],' ')[2] << endl;
        // }
        cout <<"==========================" << endl;
        cout << "이 Servant를 잡으시겠습니까?(Y/N)" ;
        ch = getKey(0);
        ch = toupper(ch);    
        clrscr();
        // cout << endl;
        
        if(ch == 'Y')
        {
            ifstream maxCheck;
            int check=0;
            string nickname;
            maxCheck.open("Player.txt",ios::in);
            do
            {
                getline(maxCheck,line);
                check++;
            } while (maxCheck.peek()!=EOF);
            if(check<MAXSERVANT)
            {
              cout << "애칭을 붙일까요?(Y/N)" ;
              ch = getKey();
              ch = toupper(ch);
              if(ch=='Y')
              {
                  cout << "\n애칭 : " ;
                  cin >> nickname;
                  newServ.setName(nickname);
              }  
                
                line = newServ.toString();
                ofstream file;
                file.open("Player.txt", ios::out | ios::app);
                //writeFile.write((char*)&pizza,sizeof(Food));
                file << line << endl;
                file.close();
                file.open("ServSkill.txt", ios::out | ios::app);
                for(int i = 0;i<newServ.getSkills().size();i++)
                {
                    file << newServ.getSkills()[i].toString() ;
                }
                file << "====================" << endl;
                file.close();
                cout <<"\n" << newServ.getName() << "을 잡았습니다 " << endl;
                if(getKey())
                    return;
            }else
            {
                cout << "더이상 잡을 수 없습니다!!!" << endl;
                cout << "Press Any Key to return" << endl;
                getKey();
                return;
            }
            
        }
        if(ch == '0')
            return;  
    }
    
    
}

void Menu::list_of_servant()
{
    char ch;
    ifstream readServant;
    vector<string> list;
    vector<Skill> skillList[4];
    string temp,skillname;
    float damage,acc;
    Skill tempSkill;
    readServant.open("Player.txt", ios::in);
    if(!readServant.is_open()){
        cout << "Servant를 가지고 있지 않습니다." << endl;
        cout << "Press any key to return..." << endl;
        getKey();
        return;
    }else{
    while (readServant.peek()!=EOF)
    {
       getline(readServant,temp);
        list.emplace_back(temp);
    } 
    readServant.close();    
    }
    readServant.open("ServSkill.txt", ios::in);
    if(!readServant.is_open())
    {
        cout << "File Open ERROR!!" << endl;
        cout << "Press Any Key to Return..." << endl;
        getKey();
        return;
    }
    for(int i = 0; i<list.size();i++)
    {
        do
        {
           
            getline(readServant,temp);
            if(temp=="====================")
                break;
            skillname = split(temp,' ')[0];               
            damage = stof(split(temp,' ')[1]);
            damage = presicion(damage);
            acc = stof(split(temp,' ')[2]);
            acc = presicion(acc);
            tempSkill.setName(skillname);
            tempSkill.setDamage(damage);
            tempSkill.setAccuracy(acc);         
            skillList[i].emplace_back(tempSkill);
        } while (readServant.peek()!=EOF);
         cout << "check" << endl;        
    }
    
    // for(int i = 0;i<4;i++){
    //     if(!skillList[i].empty()){
    //     for(int j = 0;j<skillList[i].size();j++)
    //     {         
    //             cout << skillList[i].at(j).toString();
    //     }
    //     cout <<"===================="<< endl;
    //     }       
    // }    
    // getKey();
    while(1)
    {
        clrscr();
        cout<<"*************************************************************"<<endl;
        cout<<"*************************************************************"<<endl;
        cout <<"\t Servant 목 록" << endl;        
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        if(list.empty()){
            cout << "Servant를 가지고 있지 않습니다." << endl;
            cout << "Press any key to return..." << endl;
            if(getKey())
            {
                return;
            }
        }else{
            for(int i = 0;i<list.size();i++)
            {
                cout << i+1 << ". " <<split(list.at(i),' ')[0] << endl;
            }       
            // cout <<"1st Servant" << endl;        
            // cout <<"2nd Servant" << endl;        
            // cout <<"3rd Servant" << endl;
            // cout <<"4th Servant" << endl;   
            cout <<"0: 나가기" << endl;       
            cout <<"선택 : ";            
            ch = getKey();
            if(ch-'0'<=list.size())
            {
                if (ch == '1')
                {
                    clrscr();                    
                    cout <<"====="<<split(list.at(0),' ')[0] << "의 기술목록"<<"=====" <<endl;
                    cout <<  "==============================" << endl;
                    cout << "이름  피해  정확도" << endl;
                    cout.setf(ios::right);
                    for(int i = 0;i<skillList[0].size();i++){                        
                        cout << skillList[0].at(i).toString();
                    }
                    cout <<  "==============================" << endl;
                    if(getKey())
                        continue;
                        
                }else if(ch=='2')
                {
                    clrscr();
                    cout <<"====="<<split(list.at(1),' ')[0] << "의 기술목록"<<"=====" <<endl;
                    cout <<  "==============================" << endl;
                    cout << "이름  피해  정확도" << endl;
                    cout.setf(ios::right);
                    for(int i = 0;i<skillList[1].size();i++){                        
                        cout << skillList[1].at(i).toString();
                    }
                    cout <<  "==============================" << endl;
                    if(getKey())
                        continue;
                        
                }else if(ch=='3')
                {
                    clrscr();
                    cout <<"====="<<split(list.at(2),' ')[0] << "의 기술"<<"=====" <<endl;
                    cout <<  "==============================" << endl;
                    cout << "이름  피해  정확도" << endl;
                    cout.setf(ios::right);
                    for(int i = 0;i<skillList[2].size();i++){                        
                        cout << skillList[2].at(i).toString();
                    }
                    cout <<  "==============================" << endl;
                    if(getKey())
                        continue;
                        
                }
                else if(ch == '0')
                    
                return;
            }else
            {
                cout << "잘못된 선택입니다!!" << endl;
                cout << "Press Any Key to Return" ;
                if(getKey())
                    continue;                    
            }
        }
        
    }
}

void Menu::battle_menu()
{    
    Servant tempServ,selectedServant;
    Skill tempSkill;
    vector<string> tempList;
    vector<Skill> tempSkills;
    vector<Servant> servList;
    //tempServ = enemy.getServant().at(0);  
    tempServ.setName("썬다람쥐");
    tempServ.setLevel(5);    
    string temp,psName,eName,esName;
    int i;
    char ch;        
    bool is_win;
    //Enemy 설정
    tempSkill = Skill("100만볼트",40,80,5);
    tempSkills.emplace_back(tempSkill);
    tempSkill = Skill("번개박치기",30,90,2);
    tempSkills.emplace_back(tempSkill);
    tempServ.setSkills(tempSkills);
    servList.emplace_back(tempServ);
    enemy.setServant(servList);
    //enemy.setServantStatus(0,1);
    servList.clear();
    tempSkills.clear();
    //user 불러오기
    ifstream readServant;
    readServant.open("Player.txt", ios::in);
    if(!readServant.is_open()){
        cout << "Servant가 없습니다." << endl;
        cout << "Press any key to return..." << endl;
        getKey();
        return;
    }else{
    while (readServant.peek()!=EOF)
    {
       getline(readServant,temp);
        tempList.emplace_back(temp);
    } 
    readServant.close();    
    }
    readServant.open("ServSkill.txt", ios::in);
    if(!readServant.is_open())
    {
        cout << "File Open ERROR!!" << endl;
        cout << "Press Any Key to Return..." << endl;
        getKey();
        return;
    }

    for(i = 0; i<tempList.size();i++)
    {
        do
        {          
            getline(readServant,temp);
            // cout << "check  "<<i<<" "<< temp << endl;             
            if(temp=="====================")
                break;
            tempSkill.setName(split(temp,' ')[0]);
            tempSkill.setDamage(stof(split(temp,' ')[1]));
            tempSkill.setAccuracy(stof(split(temp,' ')[2]));         
            tempSkills.emplace_back(tempSkill);
            
        } while (temp!="===================="||readServant.peek()!=EOF); 
        tempServ.setName(split(tempList[i], ' ')[0]);
        tempServ.setLevel(stoi(split(tempList[i], ' ')[1]));
        tempServ.setSkills(tempSkills);        
        tempSkills.clear();
        servList.emplace_back(tempServ);                      
    }    
    player.setServant(servList); 

    eName = enemy.getName();
    //cout << "Check" << endl; 
    //cout << "eName : " << eName << endl;    
    esName = enemy.getServant().at(0).getName();
                        
    while(1){
        clrscr();        
        //cout << "lastbattle " << lastbattle << endl;
        bool can_fight = false;
        bool is_auto = false;        
        for(i = 0;i<player.getServant().size();i++)
        {
           // cout << player.getServantStatus().at(i) << endl;
            if(player.getServantStatus().at(i))
                can_fight=true;
        }
        if(!can_fight){
            cout << "===========================" << endl;
            cout << "Servant가 모두 기절했습니다." << endl;
            cout << "       도전 실패" << endl;
            cout << "===========================" << endl;            
            if(getKey())
            {
                remove("Player.txt");
                remove("ServSkill.txt");
                return;
            }
               
        }
        if(!enemy.getServantStatus().at(0))
        {
            lastbattle = 150;
            cout << "===========================" << endl;
            cout << "       축 하 합 니 다" << endl;
            cout << "       도 전 성 공 !!" << endl;
            cout << "===========================" << endl;
            if(getKey())
                break;
        }
        cout << "==========B A T T L E==========" << endl;
        cout << eName << " 에게 도전합니다." << endl;        
        cout << eName << "가 " << esName <<" 를 내보냅니다." <<endl;        
        //Enemy의 스킬 출력
        // cout << esName << "'s Skill " << endl;
        // for(int i = 0;i<enemy.getServant()[0].getSkills().size();i++){
        //     if(!enemy.getServant()[0].getSkills().empty())               
        //             cout << enemy.getServant()[0].getSkills().at(i).toString();
        //     }
            cout <<"어떤 Servant를 내보낼까요??" << endl;        
            for(i=0;i<player.getServant().size();i++)
            {            
                cout << i+1 << ". "<< player.getServant().at(i).getName() << endl;
            }   
            cout <<"==============================="<< endl;
            
            ch= getKey();
            int point = ch-'0';
            //cout << "point => " << point<< endl;
            if(point <= player.getServant().size())
            {
                if(ch =='0')
                    return; 
                selectedServant = player.getServant().at(point-1);
                psName = selectedServant.getName();
                if(!player.getServantStatus().at(point-1))
                {
                    cout << "내보낼 수 없는 Servant입니다." << endl;
                    sleep(1);
                    continue;
                }else{
                    clrscr();
                    while(ch!='Y'&&ch!='N'){
                    cout << "==========B A T T L E==========" << endl;
                    cout << "자동전투를 진행하시겠습니까?(Y/N)" << endl;
                    cout <<"================================"<< endl;
                    ch = getKey();
                    ch = toupper(ch);
                    if(ch =='Y')
                        is_auto = true;
                    if(ch =='N')
                        is_auto = false;                        
                    }
                    clrscr();    
                    cout << "==========B A T T L E==========" << endl;
                    cout << "가라 " << psName <<" !!" << endl;
                    cout <<"================================"<< endl;
                    //enemy.getServant()[0].setHitPoints(lastbattle); 
                    //cout << "HitPoint " << enemy.getServant()[0].getHitPoints() << endl;   
                    sleep(1);
                    if(!is_auto)                                             
                        is_win = on_battle(selectedServant,enemy.getServant()[0]); 
                    else
                        is_win = on_AutoBattle(selectedServant,enemy.getServant()[0]);   
                    player.setServantStatus(point-1,is_win);
                    enemy.setServantStatus(0,!is_win);
                    //cout << "Result => " << player.getServantStatus().at(point-1) << " " <<enemy.getServantStatus().at(0) << endl;
                    // getKey();
                    }                
                }else{
                cout << "잘못 된 입력입니다!!" << endl;                    
                    if(getKey())
                        continue;
                }  
            }   
        
    }


bool Menu::on_battle(Servant pServ, Servant eServ)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> eSkill(0,1);
    eServ.setHitPoints(lastbattle);
    string psName = pServ.getName();
    string esName = eServ.getName();
    int i,temp;
    char ch;       
    while(1)
    {
        clrscr();
        cout << "==========B A T T L E==========" << endl;
        cout << psName << "에게 어떤기술을 쓰게할까요? " << endl;
        for(i=0;i<pServ.getSkills().size();i++)
        {
            cout << i+1 << ". " << pServ.getSkills().at(i).getName() << endl;
        }
        cout <<"==============================="<< endl;        
        ch = getKey();
        if(ch =='0')
            break;
        int point = ch-'0'-1;
        clrscr();        
        if(point< pServ.getSkills().size())
        {
            cout << "==========B A T T L E==========" << endl;
            cout << psName << " 의 " << pServ.getSkills().at(point).getName() << endl;
            eServ.isAttacked(pServ,pServ.getSkills().at(point));
            if(eServ.getHitPoints()==0){
                sleep(1);
                cout << eServ.getName() <<" 가 기절했습니다." << endl;
                cout <<"==============================="<< endl;
                sleep(1);            
                return true;
          }else{
            cout <<"==============================="<< endl;
            sleep(1);
          }
        }else{
           cout << "잘못된 입력입니다." << endl;                    
            if(getKey())
                continue;   
        }
        temp = eSkill(gen);
        clrscr();
        cout << "==========B A T T L E==========" << endl;
        cout << esName << " 의 " << eServ.getSkills().at(temp).getName() << endl;
        pServ.isAttacked(eServ,eServ.getSkills().at(temp));               
        if(pServ.getHitPoints()==0){
           // cout << "HitPoint => " <<eServ.getHitPoints() << endl;
            lastbattle = eServ.getHitPoints();
           // cout << "lastbattle " << lastbattle << endl;
            sleep(1); 
            cout << pServ.getName() <<" 가 기절했습니다. " << endl;
            cout <<"==============================="<< endl;   
            sleep(1);
            return false;            
        }else
        {
            cout <<"==============================="<< endl;
            sleep(1); 
        }

    }
    return true;
}

bool Menu::on_AutoBattle(Servant pServ, Servant eServ)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> eSkill(0,1);
    uniform_int_distribution<int> pSkill(0,pServ.getSkills().size()-1);
    eServ.setHitPoints(lastbattle);
    string psName = pServ.getName();
    string esName = eServ.getName();
    int i,temp;
    char ch;       
    while(1)
    {
        clrscr();
        int point = pSkill(gen);
        // cout << "==========B A T T L E==========" << endl;
        // cout << "Which Skill " << psName << " Use? " << endl;
        // for(i=0;i<pServ.getSkills().size();i++)
        // {
        //     cout << i+1 << ". " << pServ.getSkills().at(i).getName() << endl;
        // }
        // cout <<"==============================="<< endl;        
        // ch = getKey();
        // if(ch =='0')
        //     break;
        // int point = ch-'0'-1;
        // clrscr();        
        // if(point< pServ.getSkills().size())

            cout << "==========B A T T L E==========" << endl;
            cout << psName << " 의 " << pServ.getSkills().at(point).getName() << endl;
            eServ.isAttacked(pServ,pServ.getSkills().at(point));
            if(eServ.getHitPoints()==0){
                sleep(1);
                cout << eServ.getName() <<" 가 기절했습니다. " << endl;
                cout <<"==============================="<< endl;
                sleep(1);            
                return true;
          }else{
            cout <<"==============================="<< endl;
            sleep(1);
          }

        temp = eSkill(gen);
        clrscr();
        cout << "==========B A T T L E==========" << endl;
        cout << esName << " 의 " << eServ.getSkills().at(temp).getName() << endl;
        pServ.isAttacked(eServ,eServ.getSkills().at(temp));               
        if(pServ.getHitPoints()==0){
           // cout << "HitPoint => " <<eServ.getHitPoints() << endl;
            lastbattle = eServ.getHitPoints();
           // cout << "lastbattle " << lastbattle << endl;
            sleep(1); 
            cout << pServ.getName() <<" 가 기절했습니다. " << endl;
            cout <<"==============================="<< endl;   
            sleep(1);
            return false;            
        }else
        {
            cout <<"==============================="<< endl;
            sleep(1); 
        }

    }
    return true;
}