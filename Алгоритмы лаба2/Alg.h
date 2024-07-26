using namespace std;

// Функция для корректного отображения кириллических символов
void russia();
// счетчик алфавита
string alphabet(string);
// Функция для смены 1 буквы на заглавную 
string replace(string);
// Функция корректности ввода Д или Н
string yesno(string);
//Удаляет лишние пробелы
string deletespace(string);
//Функция проверяет на наличие цифр
bool checknum(string);
//Функция проверяет на наличие букв
bool checkalpha(string);
//Функция проверяет на наличие специальных символов
bool checkspecial(string);
//Проверяет содержание файла на корректне данные
bool checkfilecorrect(string);
//Функция проверки смешанных и специальных символов, букв и выход из ввода
string checkandstopnum(string);
//Проверка файла на существование
string openfile(string);
// Функция отображающая действительное время в формате «день.месяц.год_часы.минуты.секунды»
string time();

//Структура дополнительных элементов
struct AddElm;
//Структура основных элементов
struct MainElm;

//проверка на пустоту
bool isempty(MainElm*);
//Очищение структуры
MainElm* cleare(MainElm*);
//Вывод структуры на экран
void write(MainElm*);
//Проверка цифры на совпадение в введенной пользователем букве
bool searchnum(AddElm*, int);
//Ищет совпадение в структуре по букве
MainElm* searchalpha(MainElm*, string);
//Функция поиска повторяющихся цифр в структуре
void searchdouble(MainElm*,int);
//Сортировка основных элеметов структуры
void sortList(MainElm*);
//Вывод структуры из файла
MainElm* fromfile(MainElm*);
//Формирование ветвей структуры(цифры)
void branch(MainElm*);
// Вставка элемента в ветвь
void branchpush(MainElm*,string);
//Формирование основы(буквы)
void steam(MainElm*);
//Удаляет ветвь введенную пользоватем
void deletealpha(MainElm*,string);
//Удаление конкретного элемента в строке
void deletenumber(MainElm*,string);
//Сохранение структуры в файл
void keep(MainElm*);

// Функция выбора действий со структурой
void menu();
