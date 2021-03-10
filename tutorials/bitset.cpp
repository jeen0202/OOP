#include <iostream>
#include <bitset>
#include <iomanip>

int main()
{
    using namespace std;

    int i;
    while(cin >>i)
        cout << dec << i << "=="
            << hex << "0x" << i << "=="
            <<bitset<8*sizeof(int)>(i) <<endl;
    return 0;
}
