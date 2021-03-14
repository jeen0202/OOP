#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string i;
    string out = "exit";
    while(cin >> i){
        cout << "your input => " << i << endl;
        cout << "your input length => " << i.length() << endl;
    if(i.compare(out)){
            exit(0);
            }
    }
    return 0;
}
