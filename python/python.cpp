#include <python.h>

int main(void)
{
	Py_Initialize();
	if(Py_IsInitialized())
	{
		char *str1 = "tmp2 = 20\nprint tmp2";

		PyRun_SimpleString("print (\'Hello, Python!\')");
		PyRun_SimpleString("tmp1 = 10");
		PyRun_simpleString("print tmp1");
		PyRun_SimpleString(str1);

		cout << endl;

		PyRun_SimpleString("from time import time,ctime \n" "print('Today is',ctime(time()))\n");

		Py_Finalize();

	}
	return 0;
}
