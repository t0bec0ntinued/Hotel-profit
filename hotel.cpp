



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <fstream>
#include <windows.h>
using namespace std;



enum Post {
	administrator,
	doorman,
	maid,
	concierge,
	hotel_manager,
	placement_manager,
	security,
	cook
};



class Employee{
public:
	string name;
	string surname;
	Post post;
	int salary;
	int reward;
	int fine;
	virtual int full_salary() = 0;
};



class Administrator:public Employee {
public:
	int num_of_negative;


	Administrator(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0,int  num_of_negativeN = 0, Post postN = administrator) {
		 name = nameN;
		 surname = surnameN;
		 post = postN;
		 salary = salaryN;
		 reward = rewardN;
		 if (num_of_negativeN > 5) {
			 reward = 0;
		 }
		 fine = fineN;
		 num_of_negative = num_of_negativeN;

	}

	int full_salary() {

		double fs = 0;
		if (num_of_negative < 3) {
			fs = 1.5*salary + reward - fine;
		}
		if (num_of_negative >= 3 && num_of_negative <= 5) {
			fs = salary + reward - fine;
		}
		if (num_of_negative > 5) {

			fs = 0.5 * salary - fine;
		}
		return fs;
	}
};



class Doorman :public Employee {
public:
	int tips;


	Doorman(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0, int tipsN = 0, Post postN = doorman) {
		name = nameN;
		surname = surnameN;
		post = postN;
		salary = salaryN;
		reward = rewardN;
		fine = fineN;
		tips = tipsN;
	}

	int full_salary() {
		int fs = 0;
		fs = salary + reward - fine;
		return fs;
	}
};



class Hotel_manager:public Employee {
public:

	    Hotel_manager(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0, Post postN = hotel_manager) {
		name = nameN;
		surname = surnameN;
		post = postN;
		salary = salaryN;
		reward = rewardN;
		fine = fineN;

	}

	int full_salary() {
		int fs = 0;
		fs = salary + reward - fine;
		return fs;
	}
};



class Placement_manager :public Employee {
public:

	Placement_manager(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0, Post postN = placement_manager) {
		name = nameN;
		surname = surnameN;
		post = postN;
		salary = salaryN;
		reward = rewardN;
		fine = fineN;

	}

	int full_salary() {
		int fs = 0;
		fs = salary + reward - fine;
		return fs;
	}
};



class Maid :public Employee {
public:
	int purity_factor;
	Maid(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0,int purity_factorN = 5, Post postN = maid) {
		name = nameN;
		surname = surnameN;
		post = postN;
		salary = salaryN;
		reward = rewardN;
		purity_factor = purity_factorN;
		if (purity_factorN < 4) {
			reward = 0;
		}
		fine = fineN;

	}

	int full_salary() {
		int fs = 0;
		fs = salary + reward - fine;
		return fs;
	}
};



 class Concierge :public Employee {
 public:

	 Concierge(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0, Post postN = concierge) {
		name = nameN;
		surname = surnameN;
		post = postN;
		salary = salaryN;
		reward = rewardN;
		fine = fineN;

	}

	int full_salary() {
		int fs = 0;
		fs = salary + reward - fine;
		return fs;
	}
};



class Security :public Employee {
public:

	Security(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0, Post postN = security) {
		name = nameN;
		surname = surnameN;
		post = postN;
		salary = salaryN;
		reward = rewardN;
		fine = fineN;

	}

	int full_salary() {
		int fs = 0;
		fs = salary + reward - fine;
		return fs;
	}
};



class Cook :public Employee {
public:

	Cook(string nameN = "none", string surnameN = "none", int salaryN = 0, int rewardN = 0, int fineN = 0, Post postN = cook) {
		name = nameN;
		surname = surnameN;
		post = postN;
		salary = salaryN;
		reward = rewardN;
		fine = fineN;

	}

	int full_salary() {
		int fs = 0;
		fs = salary + reward - fine;
		return fs;
	}
};



enum Numtype {
	none = 0,
	cheap,
	normal,
	expensive,
	lux
};


class Guest {
public:
	string name;
	string surname;
	string phone;
	int num;
	int days;
	Numtype numtype;
	int summ = 0;




	Guest(string nameX = "none", string surnameX = "none", string phoneX = "none", int numX = 0, int daysX = 0,Numtype numtypeX = none) {
		name = nameX;
		surname = surnameX;
		phone = phoneX;
		num = numX;
		days = daysX;
		numtype = numtypeX;
	}
	int Summ() {

		if (numtype == cheap) {
			summ = days * 500;
		}
		if (numtype == normal) {
			summ = days * 1200;
		}
		if (numtype == expensive) {
			summ = days * 5700;
		}
		if (numtype == lux) {
			summ = days * 10000;
		}
		return summ;
	}

};

//Переменные для функций. Используются часто, поэтому объявляем глобально
string name;
string surname;
int salary = 0;
int reward = 0;
int fine = 0;
int purity = 0;
int  tips;
int num_of_negative;

// Объекты работников
Administrator admin;
Hotel_manager hmanager;
Placement_manager pmanager;
Doorman dman;
Maid md;
Concierge conc;
Security sec;
Cook ck;

//Гость
Guest gs;
string phone;
int num = 0;
int numtp;
Numtype nt;
int days;



void AddEmployer(){
	int e;
	cout << "Кого добавить?\n";
	cout << "1. Администратор\n2. Управляющий\n3. Менеджер по размещению\n4. Швейцар\n5. Горничная\n6. Консьерж\n7. Охрана\n8. Повар\n9. Выход\n"<<endl;

	do {
		cin >> e;

	if (e == 1) {

		string path = "admin.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);
		cout << "Количество негативных отзывов:\n";
		do {
			cin >> num_of_negative;
			if (num_of_negative < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (num_of_negative < 0);
		admin = Administrator(name, surname, salary, reward, fine, num_of_negative);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&admin, sizeof(Administrator));

		}
		fout.close();
	}
	//Дальше всё аналогично
	if (e == 2) {
		string path = "hotel manager.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);

		hmanager = Hotel_manager(name, surname, salary, reward, fine);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&hmanager, sizeof(Hotel_manager));

		}
		fout.close();
	}
	if (e == 3) {
		string path = "placement manager.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);

		pmanager = Placement_manager(name, surname, salary, reward, fine);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&pmanager, sizeof(Placement_manager));

		}
		fout.close();
	}
	if (e == 4) {
		string path = "doorman.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);
		cout << "Чаевые:\n";
		do {
			cin >> tips;
			if (tips < 0){
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (tips < 0);
		dman = Doorman(name, surname, salary, reward, tips, fine);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&dman, sizeof(Doorman));

		}
		fout.close();
	}
	if (e == 5) {
		string path = "maid.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);
		cout << "Коэффициент чистоты от 1 до 5:\n";
		do {
			cin >> purity;
			if (purity < 1 || purity > 5){
				cout << "Нельзя ввести такой коэффициент\n";
			}
		} while (purity < 1 || purity > 5);
		md = Maid(name, surname, salary, reward,  fine, purity);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&md, sizeof(Maid));

		}
		fout.close();
	}
	if (e == 6) {
		string path = "concierge.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);

		conc = Concierge(name, surname, salary, reward, fine);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&conc, sizeof(Concierge));

		}
		fout.close();
	}
	if (e == 7) {
		string path = "security.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);

		sec = Security(name, surname, salary, reward, fine);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&sec, sizeof(Security));

		}
		fout.close();
	}
	if (e == 8) {
		string path = "cook.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Зарплата:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "Нельзя назначить зарплату ниже прожиточного минимума.\n";
			}
		} while (salary < 12000);
		cout << "Премия:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (reward < 0);
		cout << "Штраф:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		} while (fine < 0);

		ck = Cook(name, surname, salary, reward, fine);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&ck, sizeof(Cook));

		}
		fout.close();
	}
	if (e < 1 || e>9) {
		cout << "Нет такой должности, попробуйте снова.\n";
	}
	} while (e != 9);
}



void CardList(int mode) {
	if (mode == 1) {
		int i;
		cout << "Выберите должность:\n1. Администраторы\n2. Управляющие\n3. Менеджеры по размещению\n4. Швейцары\n5. Горничные\n6. Консьержи\n7. Охранники\n8. Повара\n9. Выход\n" << endl;

		do {
			cin >> i;
			if (i < 1 || i > 9) {
				cout << "Нет такой должности";
			}
			if (i == 1) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Администраторы:\n" << endl;
				string path = "admin.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&admin, sizeof(Administrator))) {
						cout << "Имя: " << admin.name << endl;
						cout << "Фамилия: " << admin.surname << endl;
						cout << "Зарплата: " << admin.salary << endl;
						cout << "Премия: " << admin.reward << endl;
						cout << "Штраф: " << admin.fine << endl;
						cout << "Количество негативных отзывов: " << admin.num_of_negative << endl;
						cout << "Полная зарплата: " << admin.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 2) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Управляющие:\n" << endl;
				string path = "hotel manager.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&hmanager, sizeof(Hotel_manager))) {
						cout << "Имя: " << hmanager.name << endl;
						cout << "Фамилия: " << hmanager.surname << endl;
						cout << "Зарплата: " << hmanager.salary << endl;
						cout << "Премия: " << hmanager.reward << endl;
						cout << "Штраф: " << hmanager.fine << endl;
						cout << "Полная зарплата: " << hmanager.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 3) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Менеджеры по размещению:\n" << endl;
				string path = "placement manager.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&pmanager, sizeof(Placement_manager))) {
						cout << "Имя: " << pmanager.name << endl;
						cout << "Фамилия: " << pmanager.surname << endl;
						cout << "Зарплата: " << pmanager.salary << endl;
						cout << "Премия: " << pmanager.reward << endl;
						cout << "Штраф: " << pmanager.fine << endl;
						cout << "Полная зарплата: " << pmanager.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 4) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Швейцары:\n" << endl;
				string path = "doorman.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&dman, sizeof(Doorman))) {
						cout << "Имя: " << dman.name << endl;
						cout << "Фамилия: " << dman.surname << endl;
						cout << "Зарплата: " << dman.salary << endl;
						cout << "Премия: " << dman.reward << endl;
						cout << "Штраф: " << dman.fine << endl;
						cout << "Полная зарплата: " << dman.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 5) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Горничные:\n" << endl;
				string path = "maid.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&md, sizeof(Maid))) {
						cout << "Имя: " << md.name << endl;
						cout << "Фамилия: " << md.surname << endl;
						cout << "Зарплата: " << md.salary << endl;
						cout << "Премия: " << md.reward << endl;
						cout << "Штраф: " << md.fine << endl;
						cout << "Коэффициент чистоты: " << md.purity_factor << endl;
						cout << "Полная зарплата: " << md.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 6) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Консьержи:\n" << endl;
				string path = "concierge.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&conc, sizeof(Concierge))) {
						cout << "Имя: " << conc.name << endl;
						cout << "Фамилия: " << conc.surname << endl;
						cout << "Зарплата: " << conc.salary << endl;
						cout << "Премия: " << conc.reward << endl;
						cout << "Штраф: " << conc.fine << endl;
						cout << "Полная зарплата: " << conc.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 7) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Охранники:\n" << endl;
				string path = "security.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&sec, sizeof(Security))) {
						cout << "Имя: " << sec.name << endl;
						cout << "Фамилия: " << sec.surname << endl;
						cout << "Зарплата: " << sec.salary << endl;
						cout << "Премия: " << sec.reward << endl;
						cout << "Штраф: " << sec.fine << endl;
						cout << "Полная зарплата: " << sec.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 8) {
				ifstream fin;
				cout << "+------------------------------+\n" << "Повара:\n" << endl;
				string path = "cook.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&ck, sizeof(Cook))) {
						cout << "Имя: " << ck.name << endl;
						cout << "Фамилия: " << ck.surname << endl;
						cout << "Зарплата: " << ck.salary << endl;
						cout << "Премия: " << ck.reward << endl;
						cout << "Штраф: " << ck.fine << endl;
						cout << "Полная зарплата: " << ck.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}

		} while (i != 9);
	}
	if (mode == 2) {
		ifstream fout;
		cout << "+------------------------------+\n" << "Гости:\n" << endl;
		string path = "guest.txt";
		fout.open(path);
		if (!fout.is_open()) {
			cout << "open error\n";
		}
		else {

			while (fout.read((char *)&gs, sizeof(Guest))) {
				cout << "Имя: " << gs.name << endl;
				cout << "Фамилия: " << gs.surname << endl;
				cout << "Номер телефона: " << gs.phone << endl;
				cout << "Категория номера: " << gs.numtype << endl;
				cout << "Комната: " << gs.num << endl;
				cout << "Количество дней проживания: " << gs.days << endl;
				cout << "+------------------------------+\n";
			}

		}
		fout.close();
	}
}



int Rooms(int mode, int numtp) {



	int n=0;
	char status [35];
	fstream fin;


	fin.open("room.txt");
	fin.get(status, 35);


	if (mode == 1) {

		cout << "Список номеров:\n";

		for (int i = 1; i < 34; i++) {
			if (status[i] != '1') {
				cout << "№" << i << " - Свободно" << endl;
			}
			else {
				cout << "№" << i << " - Забронировано" << endl;
			}
		}
	}
	fin.close();
	if (mode == 2) {
		if (numtp == 1) {
			for (int i = 1; i < 11; i++) {
				if (status[i] != '1' ) {
					cout << "№" << i << " - Свободно" << endl;
				}
				else {
					cout << "№" << i << " - Забронировано" << endl;
				}
			}
			do {
				cout << "Выберите номер\n";
				cin >> n;
				if (status[n] != '1' && (n<11)) {
					cout << "Успешно забронировано\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "Действие невозможно, комната забронирована.\n";
				}
			} while (status[n] == '1');
			fin.open("room.txt");
			for (int i = 0; i < 35; i++) {
				fin.write((char *)&status[i], sizeof(status[35]));
			}
			fin.close();

		}
		if (numtp == 2) {
			for (int i = 11; i < 21; i++) {
				if (status[i] != '1') {
					cout << "№" << i << " - Свободно" << endl;
				}
				else {
					cout << "№" << i << " - Забронировано" << endl;
				}
			}
			do {
				cout << "Выберите номер\n";
				cin >> n;
				if (status[n] != '1' && n>10 && n < 21) {
					cout << "Успешно забронировано\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "Действие невозможно, комната забронирована.\n";
				}
			} while (status[n] == '1');
			fin.open("room.txt");
			for (int i = 0; i < 35; i++) {
				fin.write((char *)&status[i], sizeof(status[35]));
			}
			fin.close();
		}
		if (numtp == 3) {
			for (int i = 21; i < 31; i++) {
				if (status[i] != '1') {
					cout << "№" << i << " - Свободно" << endl;
				}
				else {
					cout << "№" << i << " - Забронировано" << endl;
				}
			}
			do {
				cout << "Выберите номер\n";
				cin >> n;
				if (status[n] != '1' && n > 20 && n<31) {
					cout << "Успешно забронировано\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "Действие невозможно, комната забронирована.\n";
				}
			} while (status[n] == '1');
			fin.open("room.txt");
			for (int i = 0; i < 35; i++) {
				fin.write((char *)&status[i], sizeof(status[35]));
			}
			fin.close();
		}
		if (numtp == 4) {
			for (int i = 31; i < 34; i++) {
				if (status[i] != '1') {
					cout << "№" << i << " - Свободно" << endl;
				}
				else {
					cout << "№" << i << " - Забронировано" << endl;
				}
			}
			do {
				cout << "Выберите номер\n";
				cin >> n;
				if (status[n] != '1'&& n>30 && n <34) {
					cout << "Успешно забронировано\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "Действие невозможно, комната забронирована.\n";
				}
			} while (status[n] == '1');
			fin.open("room.txt");
			for (int i = 0; i < 35; i++) {
				fin.write((char *)&status[i], sizeof(status[35]));
			}
			fin.close();
		}
		}

	return (n);
	}



void AddGuest() {
		string path = "guest.txt";
		cout << "Имя:\n";
		cin >> name;

		cout << "Фамилия:\n";
		cin >> surname;

		cout << "Телефон:\n";
		cin >> phone;

		do {
			cout << "Выберите ценовую категорию номера:\n1. Эконом.\n2. Обычные.\n3. Дорогие.\n4. Люкс" << endl;
			cin >> numtp;
			if (numtp == 1) {
				nt = cheap;
			}
			if (numtp == 2) {
				nt = normal;
			}
			if (numtp == 3) {
				nt = expensive;
			}
			if (numtp == 4) {
				nt = lux;
			}
			if (numtp < 1 || numtp>4) {
				cout << "Такой категории нет." << endl;
			}
		} while (numtp < 1 || numtp>4);



		num = Rooms(2,numtp);
		cout << "Количество дней проживания:\n";
		do {
			cin >> days;
			if (days < 1) {
				cout << "Невозможно выполнить действие. Отрицательное значение.\n";
			}
		}while(days < 1);
		gs = Guest(name, surname, phone,num, days,nt);

		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open()) {
			cout << "Open error\n";
		}
		else {

			fout.write((char *)&gs, sizeof(Guest));

		}
		fout.close();


}



void Profit() {
	fstream fout;
	string path;
	long minus = 0;
	long profit = 0;

	int res;

	for (int i = 1; i < 9; i++) {
		if (i == 1) {
			path = "admin.txt";
			fout.open(path);
			while( fout.read((char *)&admin, sizeof(Administrator))) {
				minus = minus + admin.full_salary();
			}
			fout.close();
		}
		if (i == 2) {
			path = "hotel manager.txt";
			fout.open(path);
			while( fout.read((char *)&hmanager, sizeof(Hotel_manager))) {
				minus = minus + hmanager.full_salary();
			}
			fout.close();
		}
		if (i == 3) {
			path = "placement manager.txt";
			fout.open(path);
			while( fout.read((char *)&pmanager, sizeof(Placement_manager))) {
				minus = minus + pmanager.full_salary();
			}
			fout.close();
		}
		if (i == 4) {
			path = "doorman.txt";
			fout.open(path);
			while(fout.read((char *)&dman, sizeof(Doorman))) {
				minus = minus + dman.full_salary();
			}
			fout.close();
		}
		if (i == 5) {
			path = "maid.txt";
			fout.open(path);
			while(fout.read((char *)&md, sizeof(Maid))) {
				minus = minus + md.full_salary();
			}
			fout.close();
		}
		if (i == 6) {
			path = "concierge.txt";
			fout.open(path);
		while(fout.read((char *)&conc, sizeof(Concierge))) {
				minus = minus + conc.full_salary();
			}
			fout.close();
		}
		if (i == 7) {
			path = "security.txt";
			fout.open(path);
			while( fout.read((char *)&sec, sizeof(Security))) {
				minus = minus + sec.full_salary();
			}
			fout.close();
		}
		if (i == 8) {
			path = "cook.txt";
			fout.open(path);
			while( fout.read((char *)&ck, sizeof(Cook))) {
				minus = minus + ck.full_salary();
			}
			fout.close();
		}
	}

	path = "guest.txt";
	fout.open(path);
	while (fout.read((char *)&gs, sizeof(Guest))) {

		profit = profit + gs.Summ();
	}
	fout.close();
	res = profit - minus;
	if (res > 1000000) {
		cout << "Бизнес очень прибыльный. Результат: " << res << endl;
	}
	if (res > 100000 && res < 1000000) {
		cout << "Бизнес прибыльный. Результат: " << res << endl;
	}
	if (res >= 0 && res <100000) {
		cout << "Бизнес работает в ноль либо с минимальной прибылью. Результат: " << res << endl;
	}
	if (res < 0) {
		cout << "Бизнес утыточный. Результат: " << res << endl;
	}

}



int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int n;
	do {
		cout << "Выберите опцию:\n1. Добавить работника.\n2. Посмотреть списки работников.\n3. Добавить гостя.\n4. Посмотреть всех гостей.\n5. Посмотреть все номера.\n6. Посчитать прибыль.\n7. Выход.\n"<<endl;
		cin >> n;

		if (n == 1) {
			AddEmployer();
		}
		if (n == 2) {
			CardList(1);
		}
		if (n == 3) {
			AddGuest();
		}
		if (n == 4) {
			CardList(2);
		}
		if (n == 5) {
			Rooms(1,0);
		}
		if (n == 6) {
			Profit();
		}
		if (n < 1 || n>7) {
			cout << "Нет такой опции.\n";
		}
	} while (n != 7);


	return 1;
	system("pause");
}
