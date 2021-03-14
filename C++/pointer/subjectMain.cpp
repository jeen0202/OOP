#include <iostream>
#include "Subject.h"
using std::cout;
using std::endl;

int main()
{
    Subject *myR = new Subject(100,90,70);
    Subject *hisR = new Subject(90,80,70);

    myR->funSum();
    myR->funAve();
    hisR->funSum();
    hisR->funAve();

    cout << " ::::my Result:::: " << endl;
    myR->output();
    cout << " ::::his Result:::: " << endl;
    hisR->output();
    
    delete myR;
    delete hisR;
    myR = hisR = NULL;
    return 0; 
}