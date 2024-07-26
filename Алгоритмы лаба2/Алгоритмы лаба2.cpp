// Алгоритмы лаба2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Алгоритмы2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <istream>
#include <vector>
#include <sstream>
#include <chrono>

#include "Alg.h"


using namespace std;

void russia()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}
//Генерация счетчика по алфавиту
string alphabet(string current)
{
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int pos = current.length() - 1;
	while (pos >= 0 and current[pos] == 'Z')
	{
		current[pos] = 'A';
		pos--;
	}
	if (pos < 0) current = "A" + current;

	else current[pos]++;

	return current;
}
//Функция проверяет на наличие цифр
bool checknum(string str)
{
	russia();
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			return true;
		
	}
	return false;
}
//Функция удаляет лишние пробелы 
string deletespace(string str)
{
	while (str[0] == ' ')
		str = str.substr(1);
	return str;
}
//Функция проверяет на наличие специальных символов
bool checkspecial(string str)
{
	string special("!%@%#&№()[{}]_:;',?/*`~$^+=<>\\\"");
	for (int i = 0; i < special.size(); i++)
	{

		if (str.find(special[i]) != -1)
		{
			cout << "Содержатся спецсимволы. " << endl;
			return true;
		}
	}
	return false;
}
//Функция проверяет на наличие букв
bool checkalpha(string str)
{
	for (int i = 0; i < (str.length() + 1); i++)
	{
		if (isalpha(str[i]))
			return true;
		
		else if ((str[i] >= 'А' and str[0] <= 'Я') or (str[i] >= 'а' and str[i] <= 'я'))
			return true;
	}
	return false;
}
//Функция поднимающая первую букву
string replace(string str)
{
	russia();
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'а' and str[i] <= 'я')
			str[i] = str[i] - 32;
		if (str[i] >= 'a' and str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	return str;
}
//Функция проверяет на ввод c консоли да и нет
string yesno(string str)
{
	russia();
	while (str != "Д" and str != "Н")
	{
		cout << "Ошибка.  " << "Введите Д/Н еще раз." << endl;
		getline(cin, str);
		str = replace(str);
	}
	return str;
}
//Проверяет содержание файла на корректне данные
bool checkfilecorrect(string filename)
{
	string str = "";


	string currentChar;
	std::ifstream file(filename);
	if (!file.is_open())
	{
		cout << "Файл не открыт." << std::endl;
		return false;
	}

	string expectedChar = "A"; // Первая ожидаемая буква

	string line;
	while (std::getline(file, line))
	{


		if (line.empty())
			continue; // Пропускаем пустые строки

		size_t pos = line.find(' ');
		if (pos != string::npos)  currentChar = line.substr(0, pos);
		else
		{
			cout << "Файл "<< filename << " некорректный." << endl;
			return false;
		}

		line = line.substr(pos, string::npos);
		//cout << line << endl;
		std::istringstream iss(line);
		string num;
		std::vector<string> digit;
		//Вносим в вектор числа строки
		while (iss >> num)
			digit.push_back(num);

		if (checkalpha(currentChar) and ((currentChar.size() == expectedChar.size() and currentChar >= expectedChar) or currentChar.size() > expectedChar.size()));

		else
		{
			cout << "Файл с некорректными данными." << endl;
			return false;
		}
		if (!empty(digit))
		{// Проверяем оставшуюся часть строки
			for (int it = 0; it < digit.size(); ++it)
			{
				if (!checknum(digit.at(it)))
				{
					cout << "Файл с некорректными данными. В ветвях содержатся не цифры." << endl;
					return false;
				}
			}
		}
		expectedChar = alphabet(currentChar); // Переходим к следующей букве
	}

	file.close();

	cout << "Файл. " << filename << " корректен." << endl;
	return true;
}


//Проверка файла на существование
string openfile(string filename)
{
	russia();
	if (filename == "/") return filename = "0";
	if (filename.length() < 4 or filename.substr(filename.length() - 4) != ".txt") filename = filename + ".txt";
	ifstream file(filename);
	while (!(file.is_open()))
	{
		cout << endl << "Файла структуры " << filename << " не существует. Хотите открыть другой файл?" << endl << "Д/Н" << endl;
		string enter;
		getline(cin, enter);
		enter = replace(enter);
		if (enter == "/") return filename = "0";
		enter = yesno(enter);
		if (enter == "Д")
		{
			cout << "Повторите ввод названия файла структуры." << endl;
			getline(cin, filename);
			if (filename == "/") return filename = "0";
			if (filename.length() < 4 or filename.substr(filename.length() - 4) != ".txt") filename = filename + ".txt";
			ifstream file(filename);
			if (file.is_open())
				break;
		}
		else if (enter == "Н") return filename = "0";
	}
	return filename;
}
//Функция проверки смешанных и специальных символов, букв и выход из ввода
string checkandstopnum(string str)
{
	russia();
	bool start = 1;
	while (start)
	{
		bool mist = 0;
		if (str == "/")
		{
			string enter;
			cout << "Прервать ввод?" << endl << "Д/Н" << endl;
			getline(cin, enter);
			enter = replace(enter);
			enter = yesno(enter);
			if (enter == "Д")
			{
				str = "/";
				return str;
			}
			else if (enter == "Н")

			{
				cout << "Повторите ввод. " << endl;
				getline(cin, str);
				continue;
			}
			start = 0;
		}
		if (str == "")
		{
			cout << "Пустой символ. " << endl;
			mist = 1;
		}
		if (str.find(".") != -1)
		{
			cout << "Содержатся спецсимволы. " << endl;
			mist = 1;
		}
		else if (checkspecial(str))mist = 1;
		if (checkalpha(str))
		{
			mist = 1;
			cout <<"Содержатся буквы." << endl;
		}
		if (mist)
		{
			cout << endl << "Повторите ввод." << endl;
			getline(cin, str);
			continue;
		}
		start = 0;
	}
	return str;
}
//Функция, которая показывает текущую дату и время
string time()
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	// Получаем текущее время в секундах с начала эпохи
	auto now = chrono::system_clock::now();
	time_t currenttime = chrono::system_clock::to_time_t(now);

	// Преобразуем время создания файла в формат "часы:минуты:секунды"
	int hours = ((currenttime + 10800) / 3600) % 24;
	int minutes = (currenttime / 60) % 60;
	int seconds = currenttime % 60;
	string shours, sminutes, sseconds, day, month;

	//Преобразуем в строчный тип
	if (hours < 10) shours = "0" + to_string(hours);
	else shours = to_string(hours);
	if (minutes < 10) sminutes = "0" + to_string(minutes);
	else sminutes = to_string(minutes);
	if (seconds < 10) sseconds = "0" + to_string(seconds);
	else sseconds = to_string(seconds);
	if (st.wDay < 10) day = "0" + to_string(st.wDay);
	else day = to_string(st.wDay);
	if (st.wMonth < 10) month = "0" + to_string(st.wMonth);
	else month = to_string(st.wMonth);

	string timenow = day + "." + month + "." + to_string(st.wYear) + "_" + shours + "." + sminutes + "." + sseconds;
	return timenow;
}




struct AddElm
{
	int number;
	AddElm* ptr;
};

struct MainElm
{
	string alpha;
	MainElm* ptrDown;
	AddElm* ptrRight;
};

MainElm* main_ptr = nullptr;

//проверка на пустоту
bool isempty(MainElm* mptr)
{
	return mptr == nullptr;
}
//Очищение структуры
MainElm* cleare(MainElm* mptr)
{
	if (isempty(mptr))
	{
		cout << "Структура пустая." << endl;
		return mptr;
	}
	if (mptr != nullptr)
	{
		while (mptr != nullptr)
		{
			MainElm* before = mptr;
			MainElm* after = nullptr;

			if (before != nullptr)
			{
				after = mptr->ptrDown;
				AddElm* ptr1 = before->ptrRight;
				AddElm* ptr2 = nullptr;
				while (ptr1 != nullptr)
				{
					ptr2 = ptr1->ptr;
					delete ptr1;
					ptr1 = ptr2;
				}
			}
			mptr = after;
			delete before;
		}
	}
	cout << "Структура очищена." << endl;
	return mptr;
}

//Вывод структуры на экран
void write(MainElm* mptr)
{
	MainElm* ptr1;//указатель для прохождения по стволу и вывода
	AddElm* ptr2;

	ptr1 = mptr;
	if (isempty(mptr)) cout << "Структура пустая." << endl;
	else
	{
		cout << endl << "Структура: " << endl;
		while (ptr1 != nullptr)
		{
			cout << ptr1->alpha << " "; //Выводим все элементы ствола

			ptr2 = ptr1->ptrRight;
			if (ptr2 != nullptr)
			{
				while (ptr2 != nullptr)
				{
					cout << ptr2->number << " "; //Выводим все элементы веток
					ptr2 = ptr2->ptr;
				}
			}
			cout << endl;
			ptr1 = ptr1->ptrDown;
		}
	}
}
//Ищет совпадение в структуре по букве
MainElm* searchalpha(MainElm* mptr, string str)
{
	MainElm* dptr = mptr;
	MainElm* ind = nullptr;
	if (dptr != nullptr)
		while (dptr != nullptr)
		{
			if (dptr->alpha == str) 
				ind = dptr;
			
			dptr = dptr->ptrDown;
		}
	return ind;
}
//Проверка цифры на повторение в введенной пользователем букве
bool searchnum(AddElm* dptr, int num)
{
	bool ind = 0;
	if (dptr != nullptr)
		while (dptr != nullptr)
		{
			if (dptr->number == num)
			{
				cout << "Цифра '" << num << "' существует. Она не будет повторно добавлена в строку." << endl;
				ind = 1;
				return ind;
			}
			dptr = dptr->ptr;
		}
	return ind;
}
//Функция поиска повторяющихся цифр в структуре
void searchdouble(MainElm* mptr, int num)
{
	bool ind = 0;
	if (isempty(mptr))
	{
		cout << "Структура пустая." << endl;
		return;
	}
	while (mptr != nullptr)
	{
		AddElm* aptr = nullptr;
		AddElm* aptr2 = nullptr;
		
		if (mptr->ptrRight != nullptr)
		{
			aptr = mptr->ptrRight;
			aptr2 = mptr->ptrRight;
		}

		while (aptr != nullptr)
		{
			if (aptr->number == num)
			{
				ind = 1;
				cout << mptr->alpha << " ";

				while (aptr2 != nullptr)
				{
					cout << aptr2->number << " "; //Выводим все элементы веток
					aptr2 = aptr2->ptr;
				}
				cout << endl;
				break;
			}
			aptr = aptr->ptr;
		}
		mptr = mptr->ptrDown;
	}
	if (ind == 0) cout << "Нет совпадений." << endl;
}
//Удаляет введенную пользователем с консоли букву
void deletealpha(MainElm* mptr, string str)
{
	MainElm* before = mptr;
	MainElm* after = nullptr;
	if (isempty(mptr))
	{
		cout << "Список пуст.";
		return;
	}

	if (before != nullptr)
	{
		after = before->ptrDown;
		AddElm* ptr1 = before->ptrRight;
		AddElm* ptr2 = nullptr;
		if (ptr1 != nullptr)
			ptr2 = ptr1->ptr;

		//для 1 элемента
		if (before->alpha == str)
		{
			while (ptr1 != nullptr)
			{
				ptr2 = ptr1->ptr;
				delete ptr1;
				ptr1 = ptr2;
			}
			main_ptr = after;
			delete before;
			cout << "Строка очищена. " << endl << endl;
			return;
		}

		if (mptr != nullptr)
			while (after != nullptr and after->alpha != str)
			{
				before = after;//переброс на следующий элемент
				after = after->ptrDown;
			}

		if (after == nullptr)
		{
			cout << "Данного элемента не существует" << endl;
			return;
		}
		else
		{
			ptr1 = after->ptrRight;
			after->ptrRight = nullptr;//обрубаем ветвь
		}

		while (ptr1 != nullptr)
		{
			ptr2 = ptr1->ptr;
			delete ptr1;
			ptr1 = ptr2;
		}

		before->ptrDown = after->ptrDown;
		delete after;
	}
	cout << "Строка очищена. " << endl << endl;
}
//Сортировка основных элеметов структуры
void sortList(MainElm* mptr) 
{
	if (mptr == nullptr || mptr->ptrDown == nullptr) return;
	
	MainElm* current = mptr;
	MainElm* index = nullptr;
	AddElm* ptrtemp;

	while (current != nullptr) 
	{
		string temp = current->alpha;
		index = current->ptrDown;

		while (index != nullptr) 
		{
			if ((current->alpha > index->alpha) and (current->alpha.size() == index->alpha.size()) or current->alpha.size() > index->alpha.size())
			{
				
				ptrtemp = current->ptrRight;
				current->ptrRight = index->ptrRight;
				current->alpha = index->alpha;
				index->ptrRight = ptrtemp;
				index->alpha = temp;

			}
			index = index->ptrDown;
		}
		current = current->ptrDown;
	}
}

//Вывод структуры из файла
MainElm* fromfile(MainElm* mptr)
{
	russia();
	MainElm* mptr1;
	AddElm* aptr = nullptr;
	MainElm* ptr;//указатель для прохождения по стволу и вывода
	AddElm* ptr2;
	string filename;

	cout << "Введите название файла структуры." << endl;
	getline(cin, filename);
	filename = openfile(filename);

	ifstream file(filename);
	if (!file.is_open())
		cout << "Файл не открыт." << endl;
	else
	{
		if (checkfilecorrect(filename))
		{
			string str = "";
			string line;
			while (getline(file, line))
			{
				//Находим в файле букву
				size_t pos = line.find(' ');
				if (pos != string::npos) str = line.substr(0, pos);
				line = line.substr(pos, string::npos);
				//cout << line << endl;
				std::istringstream iss(line);
				int num;
				std::vector<int> digit;
				//Вносим в вектор числа строки
				while (iss >> num)
				{
					digit.push_back(num);
					//cout << num << "_" << endl;
				}
				if (searchalpha(mptr,str) == nullptr) //Проверка на повтор
				{
					mptr1 = new MainElm;
					//Формируем основной ствол
					mptr1->alpha = str;
					mptr1->ptrDown = nullptr;
					mptr1->ptrRight = nullptr;
					if (mptr != nullptr)
					{
						ptr = mptr;
						while (ptr->ptrDown != nullptr) ptr = ptr->ptrDown;
						ptr->ptrDown = mptr1;//подвешивание
					}
					else
						mptr = mptr1;
				}
				//Проверка на повтор
				else
				{
					mptr1 = searchalpha(mptr,str);
					cout << endl << "Буква '" << str << "' уже существует." << endl;
				}
				//формируем ветви
				if (!empty(digit))
				{
					AddElm* add_ptr = mptr1->ptrRight;
					for (vector<int>::iterator it = digit.begin(); it != digit.end(); ++it)
					{
						if (mptr1->ptrRight == nullptr) mptr1->ptrRight = add_ptr;//Прикрепляем к стволу
						//(*mptr).alpha = str; для всего подходит
						if (searchnum(add_ptr, *it) == 0)
						{
							aptr = new AddElm;
							aptr->number = *it;
							if (add_ptr != nullptr)
							{
								ptr2 = add_ptr;
								while (ptr2->ptr != nullptr) ptr2 = ptr2->ptr;
								ptr2->ptr = aptr;//подвешивание
							}
							else
							{
								add_ptr = aptr;
								mptr1->ptrRight = add_ptr;
							}
							aptr->ptr = nullptr;
						}
					}
				}
			}
		}
	}
	file.close();
	sortList(mptr);
	write(mptr);
	return mptr;
}
//Формирование ветвей структуры(цифры)
void branch(MainElm* mptr)
{
	russia();
	AddElm* ptr2;//указатель для прохождения по стволу и вывода
	AddElm* aptr;
	AddElm* add_ptr = mptr->ptrRight;

	string num;
	do {
		cout << "Введите цифру в строку ('/' для выхода)" << endl;
		getline(cin, num);
		num= deletespace(num);
		num = checkandstopnum(num);

		if (num != "/")
		{

			int num1 = stoi(num);
			if (searchnum(add_ptr, num1) == 0) //Проверка на повтор
			{
				aptr = new AddElm;
				if (mptr->ptrRight == nullptr) mptr->ptrRight = aptr;//Прикрепляем к стволу
				//(*mptr).alpha = str; для всего подходит
				aptr->number = num1;
				aptr->ptr = nullptr;
				if (add_ptr != nullptr)
				{
					ptr2 = add_ptr;
					while (ptr2->ptr != nullptr) ptr2 = ptr2->ptr;
					ptr2->ptr = aptr;//подвешивание
				}
				else add_ptr = aptr;
			}
		}
	} while (num != "/"); 
}


//Формирование основы(буквы)
void steam(MainElm* mptr)
{
	russia();
	MainElm* mptr1;
	MainElm* ptr1;//указатель для прохождения по стволу и вывода
	string str = "";

	do {
		ptr1 = mptr;

		if (mptr != nullptr) while (ptr1 != nullptr)
		{
			str = ptr1->alpha;
			ptr1 = ptr1->ptrDown;
		}

		str = alphabet(str);

		cout << endl << "Создать букву "<< str << "? Д/Н" << endl;
		string enter;
		getline(cin, enter);
		enter = replace(enter);
		enter = yesno(enter);
		if (enter == "Н") break;
		if (enter == "Д")
		{

			if (searchalpha(mptr,str) == 0) //Проверка на повтор
			{
				mptr1 = new MainElm;
				//(*mptr).alpha = str; для всего подходит
				mptr1->alpha = str;
				mptr1->ptrDown = nullptr;
				mptr1->ptrRight = nullptr;
				if (mptr != nullptr)
				{
					ptr1 = mptr;
					while (ptr1->ptrDown != nullptr)
						ptr1 = ptr1->ptrDown;
					ptr1->ptrDown = mptr1;//подвешивание
				}
				else mptr = mptr1;

				string a;
				cout << "Хотите заполнить строку цифр? Д/Н" << endl;
				getline(cin, a);
				a = replace(a);
				a = yesno(a);
				if (a == "Д")
					branch(mptr1);
			}
		}
		if (str == "A") str = alphabet(str);
	} while (str != "/");
}

// Вставка элемента в ветвь
void branchpush(MainElm* mptr, string str)
{
	if (isempty(mptr))
	{
		cout << "Структура пустая." << endl;
		return;
	}
	getline(cin, str);
	MainElm* pptr = mptr;

	if (mptr != nullptr)
		while (pptr != nullptr and pptr->alpha != str)
			pptr = pptr->ptrDown;
	if (pptr == nullptr)
	{
		cout << "Данного элемента не существует" << endl;
		return;
	}
	cout << endl << "Строка: " << endl << pptr->alpha;
	AddElm* ptr1 = nullptr;
	if (pptr != nullptr) ptr1 = pptr->ptrRight;
	while (ptr1 != nullptr)
	{
		cout << " " << ptr1->number;
		ptr1 = ptr1->ptr;
	}
	cout << endl;
	branch(pptr);
}

//Удаление конкретного элемента в строке
void deletenumber(MainElm* mptr, string str)
{
	if (isempty(mptr))
	{
		cout << "Структура пустая." << endl;
		return;
	}

	getline(cin, str);

	MainElm* dptr = mptr;

	//пробегаем до нужного элемента-буквы
	if (mptr != nullptr)
		while (dptr != nullptr and dptr->alpha != str)
			dptr = dptr->ptrDown;

	if (dptr == nullptr)
	{
		cout << "Данного элемента не существует" << endl;
		return;
	}

	else
	{
		cout << endl << "Строка: " << endl << dptr->alpha;
		AddElm* before = nullptr;
		AddElm* after = nullptr;
		if (dptr != nullptr)
			before = dptr->ptrRight;
		if (before != nullptr)
			after = before->ptr;
		while (before != nullptr)
		{
			cout << " " << before->number;
			before = before->ptr;
		}

		if (dptr != nullptr)
			before = dptr->ptrRight;
		if (before != nullptr)
			after = before->ptr;

		cout << endl << "Введите цифру для удаления ('/' для выхода)" << endl;
		string num;
		getline(cin, num);
		checkandstopnum(num);

		if (num != "/")
		{
			int num1 = stoi(num);
			//Для 1 элемента ветви
			if (before->number == num1)
			{
				dptr->ptrRight = before->ptr;
				delete before;
				cout << "Элемент удален. " << endl << endl;
				return;
			}

			if (before != nullptr)
				while (after != nullptr and after->number != num1)
				{
					before = after;
					after = after->ptr;
				}

			if (after == nullptr and before->number != num1)
			{
				cout << "Данного элемента не существует" << endl;
				return;
			}
			//перебрасываем указатели и удаляем элемент, если он существуеn
			
			before->ptr = after->ptr;
			delete after;

			cout << "Элемент удален. " << endl << endl;
		}
	}
}

//Сохранение структуры в файл
void keep(MainElm* mptr)
{
	
	AddElm* ptr2;
	MainElm* ptr1;//указатель для прохождения по стволу и вывода
	string filename = "Struct_" + time() + ".txt";
	
	ofstream outputfile(filename);
	ptr1 = mptr;
	if (ptr1 == nullptr) cout << "Структура пустая." << endl;
	else
	{
		while (ptr1 != nullptr)
		{
			outputfile << ptr1->alpha << " "; //Выводим все элементы ствола

			ptr2 = ptr1->ptrRight;
			if (ptr2 != nullptr)
			{
				while (ptr2 != nullptr)
				{
					outputfile << ptr2->number << " "; //Выводим все элементы веток
					ptr2 = ptr2->ptr;
				}
			}
			outputfile << endl;
			ptr1 = ptr1->ptrDown;
		}

		cout << endl << "Структура сохранена в файл " << filename << endl;
	}
}

void menu()
{

	bool start = 1;
	while (start)
	{

		string str = "";
		cout << endl << "(1)Добавить структуру из файла. " << endl << "(2)Ввести структуру с консоли." << endl << "(3)Очистить элемент буквы (столбец). " << endl << "(4)Дозаписать цифры в строку."
			<< endl << "(5)Удалить цифру из строки." << endl << "(6)Вывести структуру на экран." << endl << "(7)Очистить структуру." << endl << "(8)Поиск конкретного значения по всей структуре." << endl << "(9)Сохранить структуру в файл." << endl << "Выберите 1-9 ('/' для выхода)" << endl;
		string a = "";
		getline(cin, a);
		while ((a != "1") and (a != "2") and (a != "3") and (a != "4") and (a != "5") and (a != "6") and (a != "7") and (a != "8") and (a != "9") and (a != "/"))
		{
			cout << "Ошибка ввода." << endl << "Повторите ввод. " << endl;
			getline(cin, a);
		}

		if (a == "1")
		{

			if (!isempty(main_ptr))
			{
				cout << "Структура не пустая." << endl << "(1)Очистить предыдущую структуру." << endl << "(2)Объединить структуры." << endl;
				string a;
				getline(cin, a);
				while ((a != "1") and (a != "2") and (a != "/"))
				{
					cout << "Ошибка ввода." << endl << "Повторите ввод. " << endl;
					getline(cin, a);
				}
				if (a == "1") 
				{
					main_ptr = cleare(main_ptr);
					main_ptr = fromfile(main_ptr);
				}

				else if (a == "2") main_ptr = fromfile(main_ptr);
			}
			else main_ptr = fromfile(main_ptr);	
		}
		else if (a == "2") steam(main_ptr);

		else if (a == "3")
		{
			cout << "Введите название буквы в столбце для удаления ('/' для выхода)" << endl;

			getline(cin, str);
			if (str != "/")
				deletealpha(main_ptr, str);
		}
		else if (a == "4")
		{
			cout << "Введите букву, в строке которой будет осуществляться дозапись." << endl;
			if (str != "/")
				branchpush(main_ptr,str);
			
		}
		else if (a == "5")
		{
			cout << "Введите букву, в строке которой будет произведено удаление." << endl;
			if (str != "/")
				deletenumber(main_ptr,str);
			
		}
		else if (a == "6") write(main_ptr);

		else if (a == "7")
		{
			if (!isempty(main_ptr))
			{
				cout << "Хотите очистить структуру? Д/Н " << endl;
				string p;
				getline(cin, p);
				p = replace(p);
				p = yesno(p);
				if (p == "Д")
					main_ptr = cleare(main_ptr);
				
				else if (p == "Н") cout << "Структура не очищена." << endl;
			}
			else cout << "Структура пустая." << endl;
		}
		else if (a == "8")
		{
			cout << "Введите цифру для поиска в структуре." << endl;
			getline(cin, str);
			str = deletespace(str);
			str = checkandstopnum(str);
			if (str != "/")
			{
				int num = stoi(str);
				searchdouble(main_ptr,num);
			}
		}
		else if (a == "9") keep(main_ptr);
		else if (a == "/")
			start = 0;
	}
}

int main() 
{
	russia();
	
	cout << "Старт программы формирования структуры" << endl;
	bool stop = 0;
	while(!stop)
	{
		menu();

		
		cout << "Завершить работу программы? Д/Н " << endl;
		string enter;
		getline(cin, enter);
		enter = replace(enter);
		enter = yesno(enter);
		if (enter == "Д")
		{
			stop = 1;
			cout << "Сохранить струтуру в файл? Д/Н " << endl;
			string p;
			getline(cin, p);
			p = replace(p);
			p = yesno(p);
			if (p == "Д") keep(main_ptr);
			
			else if (p == "Н");
		}
		else if (enter == "Н") stop = 0;
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
