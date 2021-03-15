#include <iostream>
#include "Snack.h"

int main()
{
    Snack inven1(10,20,30,40);
    Snack::sum(10,20,30,40);
    Snack::show_amount();

    Snack inven2(1,2,3,4);
    Snack::sum(1,2,3,4);
    Snack::show_amount();

    return 0;
}