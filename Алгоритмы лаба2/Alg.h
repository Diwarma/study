using namespace std;

// ������� ��� ����������� ����������� ������������� ��������
void russia();
// ������� ��������
string alphabet(string);
// ������� ��� ����� 1 ����� �� ��������� 
string replace(string);
// ������� ������������ ����� � ��� �
string yesno(string);
//������� ������ �������
string deletespace(string);
//������� ��������� �� ������� ����
bool checknum(string);
//������� ��������� �� ������� ����
bool checkalpha(string);
//������� ��������� �� ������� ����������� ��������
bool checkspecial(string);
//��������� ���������� ����� �� ��������� ������
bool checkfilecorrect(string);
//������� �������� ��������� � ����������� ��������, ���� � ����� �� �����
string checkandstopnum(string);
//�������� ����� �� �������������
string openfile(string);
// ������� ������������ �������������� ����� � ������� �����.�����.���_����.������.��������
string time();

//��������� �������������� ���������
struct AddElm;
//��������� �������� ���������
struct MainElm;

//�������� �� �������
bool isempty(MainElm*);
//�������� ���������
MainElm* cleare(MainElm*);
//����� ��������� �� �����
void write(MainElm*);
//�������� ����� �� ���������� � ��������� ������������� �����
bool searchnum(AddElm*, int);
//���� ���������� � ��������� �� �����
MainElm* searchalpha(MainElm*, string);
//������� ������ ������������� ���� � ���������
void searchdouble(MainElm*,int);
//���������� �������� �������� ���������
void sortList(MainElm*);
//����� ��������� �� �����
MainElm* fromfile(MainElm*);
//������������ ������ ���������(�����)
void branch(MainElm*);
// ������� �������� � �����
void branchpush(MainElm*,string);
//������������ ������(�����)
void steam(MainElm*);
//������� ����� ��������� �����������
void deletealpha(MainElm*,string);
//�������� ����������� �������� � ������
void deletenumber(MainElm*,string);
//���������� ��������� � ����
void keep(MainElm*);

// ������� ������ �������� �� ����������
void menu();
