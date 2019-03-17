#define _USE_MATH_DEFINES

#include<iostream>
#include<math.h>

using namespace std;

class Circle
{
private:
	double *radius;
	int *x;
	int *y;
	int *z;
public:
	Circle();
	Circle(double radius, int x, int y, int z);
	Circle(const Circle &one);
	~Circle();

	void SetRadius(double cradius);
	double GetRadius();
	double Square();
	double Length();
	void SetX(int X);
	void SetY(int Y);
	void SetZ(int Z);
	int GetX();
	int GetY();
	int GetZ();
};

Circle::Circle()
{
	this->radius = new double(0);
	this->x = new int(0);
	this->y = new int(0);
	this->z = new int(0);
}

Circle::Circle(double radius, int x, int y, int z)
{
	this->radius = new double(radius);
	this->x = new int(x);
	this->y = new int(y);
	this->z = new int(z);
}

Circle::Circle(const Circle &one)
{
	radius = new double(*one.radius);
	x = new int(*one.x);
	y = new int(*one.y);
	z = new int(*one.z);
}

Circle::~Circle()
{
	delete radius;
	delete z;
	delete y;
	delete x;
}

void Circle::SetRadius(double cradius)
{
	if (cradius <= 0)
	{
		throw "Incorrect radius";
	}

	*radius = cradius;

}

double Circle::GetRadius()
{
	return *radius;
}

double Circle::Square() {
	return (*radius * *radius * M_PI);
}

double Circle::Length()
{
	return (2 * *radius * M_PI);
}

void Circle::SetX(int X)
{
	*x = X;
}

void Circle::SetY(int Y)
{
	*y = Y;
}

void Circle::SetZ(int Z)
{
	*z = Z;
}

int Circle::GetX()
{
	return *x;
}

int Circle::GetY()
{
	return *y;
}

int Circle::GetZ()
{
	return *z;
}


int main(void)
{
	int X, Y, Z;
	double cradius;
	Circle *one = new Circle;
	cout << "Coordinates of the centre:" << endl;
	cout << "x = ";
	cin >> X;
	cout << "y = ";
	cin >> Y;
	cout << "z = ";
	cin >> Z;
	cout << "Radius:" << endl;
	cin >> cradius;
	one->SetX(X);
	one->SetY(Y);
	one->SetZ(Z);
	one->SetRadius(cradius);
	cout << endl << "------------------" << endl;
	cout << "Coordinates of the centre:" << endl;
	cout << "O(" << one->GetX() << ";" << one->GetY() << ";" << one->GetZ() << ")" << endl << endl;
	cout << "Radius:" << endl << one->GetRadius() << endl << endl;
	cout << "Length:" << endl << one->Length() << endl << endl;
	cout << "Square:" << endl << one->Square() << endl << endl;
	cout << "------------------" << endl << endl;
	system("pause");
	return 0;
}