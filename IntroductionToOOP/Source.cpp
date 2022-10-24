#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "------------------------------------------"

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

	//Point()
	//{
	//	x = y = double();
	//	//double() - значение по умолчанию для типа double
	//	cout << "DefaultConstructors:\t" << this << endl;
	//}
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;

	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return*this;
	}
	Point operator++(int/*здесь возможен только int*/)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	//				Methods:
	double distance(const Point& other)const
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;*/
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

bool operator==(const Point& left, const Point& right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
}
bool operator!=(const Point& left, const Point& right)
{
	return !(left == right);
}
bool operator<(const Point& left, const Point& right)
{
	return left.get_x() <= right.get_x() && left.get_y() <= right.get_y();
}
bool operator<=(const Point& left, const Point& right)
{
	return left.get_x() <= right.get_x() && left.get_y() <= right.get_y();
}
ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x();
	os << "\tY = " << obj.get_y();
	return os;
}

//#define STRUCT_POINT
//#define GET_SET_CHECK
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGMENT_OPERATOR_CHECK
//#define ARITHMETIAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;  //объявление переменной 'a' типа 'int'
	Point A;//объявление переменной 'A' типа 'Point'
			//объявление объекта 'A' структуры 'Point'
			//объявление экземпляра 'A' структуры 'Point'
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

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A': " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точками 'A' и 'B': " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точками 'B' и 'A': " << distance(A, B) << endl;
	cout << delimiter << endl;
#endif DISTANCE_CHECK

#ifdef CONSTRUCTORS_CHECK
	Point A;    //Default constructor
	A.print();

	Point B = 5;//Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;//CopyConstructor
	D.print();

	Point E;   //DefaultConstructor
	E = D;     //Assigment operator(CopyAssignment)
	E.print();
#endif CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_OPERATOR_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
#endif ASSIGMENT_OPERATOR_CHECK

#ifdef ARITHMETIAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	A.print();
	B.print();
	C.print();
	Point D = C++;
	C.print();
	D.print();
#endif ARITHMETIAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS
	cout << (Point(2, 3) == Point(7, 8)) << endl;
	for (Point i = 0; i < Point(10, 10); ++i)
	{
		i.print();
	}
#endif COMPARISON_OPERATORS

	//Point A;
	////A.print();
	///*A.set_x(2);
	//A.set_y(3);*/
	//A(2, 3);
	////A.print();

	//cout << A << endl;
}