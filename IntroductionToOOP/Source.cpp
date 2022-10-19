#include<iostream>
using namespace std;

#define tab "\t"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	Point()
	{
		x = y = double();
		//double() - значение по умолчанию дл€ типа double
		cout << "Constructors:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;

	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructors:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT
//#define GET_SET_CHECK

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;  //объ€вление переменной 'a' типа 'int'
	Point A;//объ€вление переменной 'A' типа 'Point'
			//объ€вление объекта 'A' структуры 'Point'
			//объ€вление экземпл€ра 'A' структуры 'Point'
	A.x = 2.2;
	A.y = 3.3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
#endif STRUCT_POINT

#ifdef GET_SET_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;

	Point B;
	A.set_x(5);
	A.set_y(7);
	cout << B.get_x() << tab << B.get_y() << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << tab;
	}
	cout << endl;
#endif GET_SET_CHECK

	Point A;    //Default constructor
	A.print();

	Point B = 5;//Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();
}