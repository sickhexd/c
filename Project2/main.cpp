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
	cout << "Введите ваше имя: ";
	cin >> a;
	cout << "Введите вашу фамилию: ";
	cin >> b;
	cout << "Введите ваш пол: ";
	cin >> c;
	cout << "Введите вашу дату рождения: ";
	cin >> d;
	struct p_atribute pers = {
		{{a} , {b}}, c, d
	};
	cout << "Имя: " << pers.p.name << endl;
	cout << "Фамилия: " << pers.p.last_name << endl;
	cout << "Пол: " << pers.sex << endl;
	cout << "Дата рожения: " << pers.bdate << endl;
	cout << "Вам присвоен id: ";
	id_gen();

	fstream f;
	f.open("1.xls", ios::out);
	f << "Имя" << "\t" << "Фамилия" << "\t" << "Пол" << "\t" << "Дата рождения" << "\t" << "ID" << endl;
	f << pers.p.name << "\t" << pers.p.last_name << "\t" << pers.sex << "\t" << pers.bdate << "\t" << id_gen();
	f.close();
	return 0;
}