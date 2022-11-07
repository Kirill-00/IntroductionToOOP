#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	size_t size; //������ ������ � ������
	char* str;   //��������� �� ������ � ������������ ������
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	size_t get_size()const
	{
		return size;
	}
	//              Constructors
	explicit String(size_t size=80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other)
	{
		//Shallow copy:
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}
	//               Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const		//i - index
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//                Methods:
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1; //������ ������ �������� 80 ����
	str1.print();
	cout << str1 << endl;

	String str2(22);
	str2.print();

	String str3 = "Hello";
	str3.print();

	String str4 = str3;  //CopyConstructor
	cout << str4 << endl;

	String str5;  //DefaultConstructor
	str5 = str4;  //Copy assignment
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	/*String str3;
	str3 = str1 + str2;
	cout << str3 << endl;*/
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK
}