#include <iostream>
using namespace std;
//Class의 연산자에대한 함수를 지정할 수 있다.
class Inventory
{
	private:
		int pencil;
		int notebook;
		int eraser;
		int total;

	public:
		void setPencil(int vPencil){pencil=vPencil;}
		void setNotebook(int vNotebook){notebook=vNotebook;}
		void setEraser(int vEraser){eraser = vEraser;}
		void calculateTotal();
		void output();
		//class의 연산자(+)에 대한 함수
		Inventory operator+(Inventory InventoryObject);
		//class의 연산자(--)에 대한 함수
		Inventory operator--();
		//연산자(--)함수에 대한 overloading
		Inventory operator--(int);
};
Inventory Inventory::operator+(Inventory InventoryObject)
{
	Inventory returnObject;
	returnObject.pencil = pencil + InventoryObject.pencil;
	returnObject.notebook = notebook + InventoryObject.notebook;
	returnObject.eraser = eraser + InventoryObject.eraser;
	returnObject.total = total + InventoryObject.total;

	return returnObject;
}
Inventory Inventory::operator--()
{
	--pencil;
	--notebook;
	--eraser;
	--total;
	
	return *this; // operator --
}
Inventory Inventory::operator--(int)
{
	Inventory returnObject=*this;

	--pencil;
	--notebook;
	--eraser;
	--total;

	return returnObject;
}
void Inventory::calculateTotal()
{
	total = pencil +notebook + eraser;
}

void Inventory::output()
{
	cout << "연필의 개수 " << pencil << endl;
	cout << "공책의 개수 " << notebook << endl;
	cout << "지우개의 개수 " << eraser << endl;
	cout << "총 물건의 개수 " << total << endl;
}
int main()
{
	Inventory inven1;
	inven1.setPencil(100);
	inven1.setNotebook(200);
	inven1.setEraser(300);
	inven1.calculateTotal();
	cout << "====== 1번 통계 ======" << endl;
	inven1.output();

	Inventory inven2;
	inven2 = --inven1;
	cout<< "====== Inven2 = --Inven1 =====" << endl;
	cout << ":::: Inven2 :::: \n";
	inven2.output();
	cout << ":::: Inven1 :::: \n";
	inven1.output();
	cout << "\n";
	inven1.setPencil(100);
	inven1.setNotebook(200);
	inven1.setEraser(300);
	inven1.calculateTotal();
	cout << "====== 1번 통계 ======" << endl;
	inven1.output();
	cout << "\n";

	inven2 = inven1--;
	cout << "<<< Inven2 = Inven1--; >>> " << endl;
	cout << ":::: Inven2 :::: " << endl;
	inven2.output();
	cout << ":::: Inven1 :::: " << endl;
	inven1.output();
	return 0;
}

