#include<iostream>
#include<Windows.h>
using namespace std;

void ASCII();
int StringLength(char str[]);
void to_upper(char str[]);         //Переводит строку в верхний регистр
void to_lower(char str[]);         //Переводит строку в нижний регистр
void capitalize(char str[]);       //Первую букву каждого слова в предложении делает заглавной
//void shrink(char str[]);         //Удаляет из строки лишние пробелы, например:
                                   //Хорошо      живет   на  свете   Винни   Пух
//bool is_palindrome(char str[i]); //Определяет, является ли строка палиндромом
//bool is_int_number(char str[]);  //Определяет, является ли строка целым числом
                                   //Строка является целым числом, когда она состоит только из цифр.
//int to_int_number(char str[]);   //Если строка - целое число, функция вернет его числовое значение.
//bool is_bin_number(char str[]);  //Проверяет, является ли строка двоичным числом
//int bin_to_dec(char str[]);      //Если строка - двоичное число, функция вернет его десятичное значение.
//??? dec_to_bin(int decimal);     //Функция принимает десятичное число, и возвращает его двоичное значение.

//bool is_hex_number(char str[]);  //Проверяет, является ли функция шестнадцатеричным числом
//int hex_to_dec(char str[]);      //Если строка - Шестнадцатеричное число, функция вернет его десятичное значение.
//??? dec_to_hex(int decimal);     //Функция принимает десятичное число, и возвращает его Шестнадцатеричное значение.

//bool is_mac_address(char str[]); //

//Hardcore:
//Если строка целое число, функция вернет его письменное значение кирилицей.

/* *** Строки ***
* Строка в языке С представляент собой массив элементов типа char.
* Последним элементом этого массива всегда является ASCII - символ с кодом 0 '\0'
* Этот ноль является терминирующим, т.е. он показывает конец строки.
*/

//#define STRING_DECLARATION //Объявление строк
//Фрагмент кода #define - Ctrl+K+S
void main()
{
	setlocale(LC_ALL, "ru");
#ifdef STRING_DECLARATION
	'H'; //Символьная константа (типа char).
	"Hello"; //Строковая константа.
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//for (int i = 0; i < sizeof(str); i++)cout << str[i]; cout << endl;
	char str[] = "Hello";
	str[1] = 'E';
	cout << str << endl;
	cout << sizeof("Hello") << endl;
	cout << sizeof(double) << endl;
#endif // STRING_DECLARATION

	//ASCII();
	cout << (int)'a' - (int)'A' << endl;
	cout << 'a' - 'A' << endl;
	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n); //CP1251
	//SetConsoleCP(866);
	cout << str << endl; //CP866
	cout << StringLength(str) << endl;
	//cout << (int)'0' << endl;
	to_upper(str);
	cout << str << endl;
	capitalize(str);
	cout << str << endl;
}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
	/*
	* -------------------------------------------------------
	* false - это 0
	* true - все что НЕ 0
	for(Counter; Condition; Expression) //Condition - условие
	{

	}
	* -------------------------------------------------------
	*/
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if( //Если символ
			str[i]>='a' && str[i] <= 'z' || //маленькая английская буква ИЛИ
			str[i]>='а' && str[i] <= 'я'    //маленькая русская буква
			)//тогда переводим в верхний регистр
			str[i] -= ' ';
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		{
			if (
				str[i] >= 'A' && str[i] <= 'Z' ||
				str[i] >= 'А' && str[i] <= 'Я'
				)
				str[i] += 32;
		}
	}
}

void capitalize(char str[])
{
	to_lower(str);
	//Первую букву каждого слова в предложении делает заглавной
	if (
		str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= 'а' && str[0] <= 'я')
		str[0] -= 32;
	for (int i = 0; str[i]; i++)
	{
		if (str[i - 1] == ' ')
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
				str[i] -= 32;
		}

	}
}