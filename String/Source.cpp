#include"String.h"

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK
//#define WAYS_TO_CALL_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1; //пустая строка размером 80 Байт
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
	String str3 = str1 + str2;
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;
	String str4 = str1;
	cout << str4 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef WAYS_TO_CALL_CONSTRUCTORS
	String str1;		//DefaultConstructor
	str1.print();
	String str2(5);		//Single-argumant type 'int'
	str2.print();
	String str3 = "Hello";//Single-argument type 'const char*'
	str3.print();
	String str4();	//Это выражение НЕ создает объект, а просто объявляет функцию str4(),
					//которая ничего не принимает, и возвращает значение типа 'String'.
	//str4.print();
	//Если нужно явно вызвать конструктор по умолчанию, то это можно сделать так:
	String str5{};	//Явный вызов конструктора по умолчанию
	str5.print();
	String str6{ 7 };
	str6.print();
	String str7{ "Hello" };
	str7.print();
#endif // WAYS_TO_CALL_CONSTRUCTORS
}