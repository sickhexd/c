#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;


int id_gen() {
	int id1;
	string id, id2;
	for (int i = 0; i < 3; i++) {
		id1 = rand() % 10;
		id2 = char(rand() % 26 + 0x61);
		id = to_string(id1) + id2;
		cout << id;
	}
	return stoi(id);
}

struct person {
	char* name = new char[20];
	char* last_name = new char[20];
};

struct p_atribute {
	struct person p;
	char* sex = new char[10];
	char* bdate = new char[11];
};

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	srand((NULL));
	char a[20], b[20], c[10], d[11];
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
	id_gen();

	fstream f;
	f.open("1.xls", ios::out);
	f << "���" << "\t" << "�������" << "\t" << "���" << "\t" << "���� ��������" << "\t" << "ID" << endl;
	f << pers.p.name << "\t" << pers.p.last_name << "\t" << pers.sex << "\t" << pers.bdate << "\t" << id_gen();
	f.close();
	return 0;
}