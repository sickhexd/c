#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <Windows.h>

using namespace std;


string id_gen() {
	int id1;
	string id, id2;
	for (int i = 0; i < 3; i++) {
		id1 = rand() % 10;
		id2 = char(rand() % 26 + 0x61);
		id = to_string(id1) + id2;
		cout << id;
	}
	return id;
}

struct person {
	char* name;
	char* last_name;
};

struct p_atribute {
	struct person p;
	char* sex;
	char* bdate;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	char* a = new char[20];
	char* b = new char[20];
	char* c = new char[10];
	char* d = new char[11];
	cout << "������� ���� ���: ";
	cin >> a;
	cout << "������� ���� �������: ";
	cin >> b;
	cout << "������� ��� ���: ";
	cin >> c;
	cout << "������� ���� ���� ��������: ";
	cin >> d;
	struct p_atribute pers = {
		{{a} , {b}}, c, d
	};
	cout << "���: " << pers.p.name << endl;
	cout << "�������: " << pers.p.last_name << endl;
	cout << "���: " << pers.sex << endl;
	cout << "���� �������: " << pers.bdate << endl;
	cout << "��� �������� id: ";
	string id = id_gen();

	fstream f;
	f.open("1.xls", ios::app);
	f << "���" << "\t" << "�������" << "\t" << "���" << "\t" << "���� ��������" << "\t" << "ID" << endl;
	f << pers.p.name << "\t" << pers.p.last_name << "\t" << pers.sex << "\t" << pers.bdate << "\t" << id;
	f.close();
	free(a);
	free(b);
	free(c);
	free(d);
	return 0;	
}