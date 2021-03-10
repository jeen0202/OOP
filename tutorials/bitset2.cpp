#include <iostream>
#include <bitset>

int main()
{
    using namespace std;

    const int max = 8;
    bitset<max> b;
    while(cin >> b) {
        cout << b << endl;
        for(int i = 0; i < max ; ++i)
            cout << b[i];
        cout << endl;
        
    }
    return 0;
}
