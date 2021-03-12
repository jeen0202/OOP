#include <iostream>
using namespace std;

class Rectangle
{
	private:
		int width;
		int height;
		int area;

	public:
		void calculateArea(int vow, int voh);
		int getWidth();
		int getHeight();
		int getArea();
};

void Rectangle::calculateArea(int vow, int voh)
{
	width = vow;
	height = voh;
	area = width * height;
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getHeight()
{
	return height;
}

int Rectangle::getArea()
{
	return area;
}
void outputRectangle(Rectangle RectangleObject);

int main()
{
	Rectangle rect1;

	rect1.calculateArea(20,30);

	outputRectangle(rect1);

	return 0;
}
void outputRectangle(Rectangle RectangleObject)
{
	cout << "직사각형의 폭은 : " << RectangleObject.getWidth() << endl;
	cout << "직사각형의 길이는 : " << RectangleObject.getHeight() << endl;
	cout << "직사각형의 넓이는 : " << RectangleObject.getArea() << endl;
}
