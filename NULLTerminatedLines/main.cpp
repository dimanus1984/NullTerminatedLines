#include<iostream>
#include<Windows.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void ASCII();
void Input(char str[], const int n);
int StringLength(char str[]);      //Выводит количество символов
void to_upper(char str[]);         //Переводит строку в верхний регистр
void to_lower(char str[]);         //Переводит строку в нижний регистр
void capitalize(char str[]);       //Первую букву каждого слова в предложении делает заглавной
void shrink(char str[]);           //Удаляет из строки лишние пробелы, например:
								   //Хорошо      живет   на  свете   Винни   Пух
//bool is_palindrome(char str[]);  //Определяет, является ли строка палиндромом
//bool is_int_number(char str[]);  //Определяет, является ли строка целым числом
								   //Строка является целым числом, когда она состоит только из цифр.
//int to_int_number(char str[]);   //Если строка - целое число, функция вернет его числовое значение.

//bool is_bin_number(char str[]);  //Проверяет, является ли строка двоичным числом
//int bin_to_dec(char str[]);      //Если строка - двоичное число, функция вернет его десятичное значение.
//??? dec_to_bin(int decimal);     //Функция принимает десятичное число, и возвращает его двоичное значение.

//bool is_hex_number(char str[]);  //Проверяет, является ли функция шестнадцатеричным числом
//int hex_to_dec(char str[]);      //Если строка - Шестнадцатеричное число, функция вернет его десятичное значение.
//??? dec_to_hex(int decimal);     //Функция принимает десятичное число, и возвращает его Шестнадцатеричное значение.

//bool is_mac_address(char str[]); //Проверяет, является ли строка MAC-адресом
//bool is_ip_address(char str[]);  //Проверяет, является ли строка IP-адресом

//Hardcore:
//Если строка - целое число, функция вернет его письменное значение кириллицей.

/* *** Строки ***
* Строка в языке С представляет собой массив элементов типа char.
* Последним элементом этого массива всегда является ASCII - символ с кодом 0 '\0'
* Этот ноль является терминирующим, т.е. он показывает конец строки.
* Строки в языке С называют NULL terminated lines или стороки заканчивающиеся нулем.
*/
//#define STRING_DECLARATION //Объявление строк
//Фрагмент кода #define - Ctrl+K+S
//Ctrl+Shift+U - переводит буквы в заглавные
//Ctrl+U - переводит заглавные буквы в маленькие

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef STRING_DECLARATION
	'H';     //Символьная константа (типа char).
	"Hello"; //Строковая константа - это последовательность символов заключенная в двойные ковычки.
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 }; //Все что идет после нуля игнорируется
	//1 вариант вывода - как не надо делать:
	//for (int i = 0; i < sizeof(str); i++)cout << str[i]; cout << endl;
	//2 вариант вывода:
	//cout << str << endl;
	//Оператор sizeof возвращает размер в байтах.

	char str[] = "Hello";
	str[1] = 'E';
	cout << str << endl;
	cout << sizeof(str) << endl;
	cout << sizeof("Hello") << endl;
	cout << sizeof(double) << endl; //sizeoff возвращает размер типа данных
#endif // STRING_DECLARATION

	//ASCII();
	//cout << (int)'a' - (int)'A' << endl;
	//cout << 'a' - 'A' << endl;
	const int n = 150;
	char str[n] = {};
	cout << "Введите строку: ";	//cin >> str;
	Input(str, n);
	//SetConsoleCP(866);
	//cout << str << endl; //CP866

	cout << "Line Length: " << StringLength(str) << " characters" << endl;
	//cout << '0' << endl;      //Выведит char 0
	//cout << (int)'0' << endl; //Выведит код '0' - 48

	to_upper(str);
	cout << "   to_upper: " << str << endl;

	to_lower(str);
	cout << "   to_lower: " << str << endl;

	capitalize(str);
	cout << " capitalize: " << str << endl;

	shrink(str);
	cout << "     shrink: " << str << endl;
}

void Input(char str[], const int n)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//cin.getline - принимает два параметра - это буффер и размер буффера, третий параметр разделитель.
	cin.getline(str, n); //CP1251
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
	//1 способ через for
	for (; str[i]; i++);
	//2 способ через while
	//while (str[i])i++;
	return i;
	/*
	* -------------------------------------------------------
	* false - это 0
	* true - все что НЕ 0
	* for - это цикл c предусловием.
	for(Counter; Condition; Expression) //Counter - объявляется и инициализируется счетчик.
										//Condition - условие.
	{
	}
	* -------------------------------------------------------
	*/
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ( //Если символ
			str[i] >= 'a' && str[i] <= 'z' || //маленькая английская буква ИЛИ
			str[i] >= 'а' && str[i] <= 'я'    //маленькая русская буква
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
				str[i] >= 'А' && str[i] <= 'Я')
				str[i] += 32;
		}
	}
}

void capitalize(char str[])
{
	to_lower(str); //Перевести сначала все буквы в нижний регистр
	//Первую букву каждого слова в предложении делает заглавной
	if ( //Проверяет нулевой символ начальный
		str[0] >= 'a' && str[0] <= 'z' ||
		str[0] >= 'а' && str[0] <= 'я')
		str[0] -= 32;
	for (int i = 1; str[i]; i++) //Поскольку начальный символ уже проверили, то можно начинать с единицы int i = 1.
	{
		if (str[i - 1] == ' ') //Если предыдущий смвол пробел.
		{
			if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
				str[i] -= 32; //Тогда отнимаем 32.
		}
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//Если пробел и следующий пробел или
		while ((str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0)) || str[0] == ' ')
		{
			//То сдвигаем в лево строку
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}