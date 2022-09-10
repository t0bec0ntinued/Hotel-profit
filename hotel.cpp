



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

//���������� ��� �������. ������������ �����, ������� ��������� ���������
string name;
string surname;
int salary = 0;
int reward = 0;
int fine = 0;
int purity = 0;
int  tips;
int num_of_negative;

// ������� ����������
Administrator admin;
Hotel_manager hmanager;
Placement_manager pmanager;
Doorman dman;
Maid md;
Concierge conc;
Security sec;
Cook ck;

//�����
Guest gs;
string phone;
int num = 0;
int numtp;
Numtype nt;
int days;



void AddEmployer(){
	int e;
	cout << "���� ��������?\n";
	cout << "1. �������������\n2. �����������\n3. �������� �� ����������\n4. �������\n5. ���������\n6. ��������\n7. ������\n8. �����\n9. �����\n"<<endl;

	do {
		cin >> e;

	if (e == 1) {

		string path = "admin.txt";
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (fine < 0);
		cout << "���������� ���������� �������:\n";
		do {
			cin >> num_of_negative;
			if (num_of_negative < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
	//������ �� ����������
	if (e == 2) {
		string path = "hotel manager.txt";
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (fine < 0);
		cout << "������:\n";
		do {
			cin >> tips;
			if (tips < 0){
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (fine < 0);
		cout << "����������� ������� �� 1 �� 5:\n";
		do {
			cin >> purity;
			if (purity < 1 || purity > 5){
				cout << "������ ������ ����� �����������\n";
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
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "��������:\n";
		do {
			cin >> salary;
			if (salary < 12000) {
				cout << "������ ��������� �������� ���� ������������ ��������.\n";
			}
		} while (salary < 12000);
		cout << "������:\n";
		do {
			cin >> reward;
			if (reward < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
			}
		} while (reward < 0);
		cout << "�����:\n";

		do {
			cin >> fine;
			if (fine < 0) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
		cout << "��� ����� ���������, ���������� �����.\n";
	}
	} while (e != 9);
}



void CardList(int mode) {
	if (mode == 1) {
		int i;
		cout << "�������� ���������:\n1. ��������������\n2. �����������\n3. ��������� �� ����������\n4. ��������\n5. ���������\n6. ���������\n7. ���������\n8. ������\n9. �����\n" << endl;

		do {
			cin >> i;
			if (i < 1 || i > 9) {
				cout << "��� ����� ���������";
			}
			if (i == 1) {
				ifstream fin;
				cout << "+------------------------------+\n" << "��������������:\n" << endl;
				string path = "admin.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&admin, sizeof(Administrator))) {
						cout << "���: " << admin.name << endl;
						cout << "�������: " << admin.surname << endl;
						cout << "��������: " << admin.salary << endl;
						cout << "������: " << admin.reward << endl;
						cout << "�����: " << admin.fine << endl;
						cout << "���������� ���������� �������: " << admin.num_of_negative << endl;
						cout << "������ ��������: " << admin.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 2) {
				ifstream fin;
				cout << "+------------------------------+\n" << "�����������:\n" << endl;
				string path = "hotel manager.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&hmanager, sizeof(Hotel_manager))) {
						cout << "���: " << hmanager.name << endl;
						cout << "�������: " << hmanager.surname << endl;
						cout << "��������: " << hmanager.salary << endl;
						cout << "������: " << hmanager.reward << endl;
						cout << "�����: " << hmanager.fine << endl;
						cout << "������ ��������: " << hmanager.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 3) {
				ifstream fin;
				cout << "+------------------------------+\n" << "��������� �� ����������:\n" << endl;
				string path = "placement manager.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&pmanager, sizeof(Placement_manager))) {
						cout << "���: " << pmanager.name << endl;
						cout << "�������: " << pmanager.surname << endl;
						cout << "��������: " << pmanager.salary << endl;
						cout << "������: " << pmanager.reward << endl;
						cout << "�����: " << pmanager.fine << endl;
						cout << "������ ��������: " << pmanager.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 4) {
				ifstream fin;
				cout << "+------------------------------+\n" << "��������:\n" << endl;
				string path = "doorman.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&dman, sizeof(Doorman))) {
						cout << "���: " << dman.name << endl;
						cout << "�������: " << dman.surname << endl;
						cout << "��������: " << dman.salary << endl;
						cout << "������: " << dman.reward << endl;
						cout << "�����: " << dman.fine << endl;
						cout << "������ ��������: " << dman.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 5) {
				ifstream fin;
				cout << "+------------------------------+\n" << "���������:\n" << endl;
				string path = "maid.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&md, sizeof(Maid))) {
						cout << "���: " << md.name << endl;
						cout << "�������: " << md.surname << endl;
						cout << "��������: " << md.salary << endl;
						cout << "������: " << md.reward << endl;
						cout << "�����: " << md.fine << endl;
						cout << "����������� �������: " << md.purity_factor << endl;
						cout << "������ ��������: " << md.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 6) {
				ifstream fin;
				cout << "+------------------------------+\n" << "���������:\n" << endl;
				string path = "concierge.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&conc, sizeof(Concierge))) {
						cout << "���: " << conc.name << endl;
						cout << "�������: " << conc.surname << endl;
						cout << "��������: " << conc.salary << endl;
						cout << "������: " << conc.reward << endl;
						cout << "�����: " << conc.fine << endl;
						cout << "������ ��������: " << conc.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 7) {
				ifstream fin;
				cout << "+------------------------------+\n" << "���������:\n" << endl;
				string path = "security.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&sec, sizeof(Security))) {
						cout << "���: " << sec.name << endl;
						cout << "�������: " << sec.surname << endl;
						cout << "��������: " << sec.salary << endl;
						cout << "������: " << sec.reward << endl;
						cout << "�����: " << sec.fine << endl;
						cout << "������ ��������: " << sec.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}
			if (i == 8) {
				ifstream fin;
				cout << "+------------------------------+\n" << "������:\n" << endl;
				string path = "cook.txt";
				fin.open(path);
				if (!fin.is_open()) {
					cout << "open error\n";
				}
				else {

					while (fin.read((char *)&ck, sizeof(Cook))) {
						cout << "���: " << ck.name << endl;
						cout << "�������: " << ck.surname << endl;
						cout << "��������: " << ck.salary << endl;
						cout << "������: " << ck.reward << endl;
						cout << "�����: " << ck.fine << endl;
						cout << "������ ��������: " << ck.full_salary() << endl;
						cout << "+------------------------------+\n";
					}

				}
				fin.close();
			}

		} while (i != 9);
	}
	if (mode == 2) {
		ifstream fout;
		cout << "+------------------------------+\n" << "�����:\n" << endl;
		string path = "guest.txt";
		fout.open(path);
		if (!fout.is_open()) {
			cout << "open error\n";
		}
		else {

			while (fout.read((char *)&gs, sizeof(Guest))) {
				cout << "���: " << gs.name << endl;
				cout << "�������: " << gs.surname << endl;
				cout << "����� ��������: " << gs.phone << endl;
				cout << "��������� ������: " << gs.numtype << endl;
				cout << "�������: " << gs.num << endl;
				cout << "���������� ���� ����������: " << gs.days << endl;
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

		cout << "������ �������:\n";

		for (int i = 1; i < 34; i++) {
			if (status[i] != '1') {
				cout << "�" << i << " - ��������" << endl;
			}
			else {
				cout << "�" << i << " - �������������" << endl;
			}
		}
	}
	fin.close();
	if (mode == 2) {
		if (numtp == 1) {
			for (int i = 1; i < 11; i++) {
				if (status[i] != '1' ) {
					cout << "�" << i << " - ��������" << endl;
				}
				else {
					cout << "�" << i << " - �������������" << endl;
				}
			}
			do {
				cout << "�������� �����\n";
				cin >> n;
				if (status[n] != '1' && (n<11)) {
					cout << "������� �������������\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "�������� ����������, ������� �������������.\n";
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
					cout << "�" << i << " - ��������" << endl;
				}
				else {
					cout << "�" << i << " - �������������" << endl;
				}
			}
			do {
				cout << "�������� �����\n";
				cin >> n;
				if (status[n] != '1' && n>10 && n < 21) {
					cout << "������� �������������\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "�������� ����������, ������� �������������.\n";
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
					cout << "�" << i << " - ��������" << endl;
				}
				else {
					cout << "�" << i << " - �������������" << endl;
				}
			}
			do {
				cout << "�������� �����\n";
				cin >> n;
				if (status[n] != '1' && n > 20 && n<31) {
					cout << "������� �������������\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "�������� ����������, ������� �������������.\n";
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
					cout << "�" << i << " - ��������" << endl;
				}
				else {
					cout << "�" << i << " - �������������" << endl;
				}
			}
			do {
				cout << "�������� �����\n";
				cin >> n;
				if (status[n] != '1'&& n>30 && n <34) {
					cout << "������� �������������\n";
					status[n] =  '1' ;
					break;
				}
				else {
					cout << "�������� ����������, ������� �������������.\n";
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
		cout << "���:\n";
		cin >> name;

		cout << "�������:\n";
		cin >> surname;

		cout << "�������:\n";
		cin >> phone;

		do {
			cout << "�������� ������� ��������� ������:\n1. ������.\n2. �������.\n3. �������.\n4. ����" << endl;
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
				cout << "����� ��������� ���." << endl;
			}
		} while (numtp < 1 || numtp>4);



		num = Rooms(2,numtp);
		cout << "���������� ���� ����������:\n";
		do {
			cin >> days;
			if (days < 1) {
				cout << "���������� ��������� ��������. ������������� ��������.\n";
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
		cout << "������ ����� ����������. ���������: " << res << endl;
	}
	if (res > 100000 && res < 1000000) {
		cout << "������ ����������. ���������: " << res << endl;
	}
	if (res >= 0 && res <100000) {
		cout << "������ �������� � ���� ���� � ����������� ��������. ���������: " << res << endl;
	}
	if (res < 0) {
		cout << "������ ���������. ���������: " << res << endl;
	}

}



int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int n;
	do {
		cout << "�������� �����:\n1. �������� ���������.\n2. ���������� ������ ����������.\n3. �������� �����.\n4. ���������� ���� ������.\n5. ���������� ��� ������.\n6. ��������� �������.\n7. �����.\n"<<endl;
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
			cout << "��� ����� �����.\n";
		}
	} while (n != 7);


	return 1;
	system("pause");
}
