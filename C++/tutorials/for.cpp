#include <termios.h>
#include <iostream>
#include <array> //arr.size()
#include <string>
#include <random>
#include <sstream>
#include <algorithm>
#include <unistd.h>
using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    int skillcount[4] = {-1,-1,-1,-1};    
    int i,j,maxSkill =0;
    uniform_int_distribution<int> diskill(1,4);
    uniform_int_distribution<int> skill(0,3);    
    uniform_int_distribution<int> dis(0,4);
    maxSkill = diskill(gen);
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
                    break;
                    
                    }                      
                };
        }
    cout << "maxSkill => " << maxSkill << endl;
    for(i=0;i<4;i++)
    {
        
        cout << skillcount[i] << "\t" ;
    }
    cout << endl;
}

