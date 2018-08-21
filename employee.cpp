#include<iostream>
#include<string>
const int grades[9] = { 0, 500,600,750,1000,1400,2000,2800,4000 };
class employee {
protected:
	int latedays;
	std::string name;
	int ID;
	int grade;
	double salary;
	double base_salary;
public:
	employee(std::string, int, int);
	virtual void pay();
	void show();
	void show_salary();
	double getsalary();
};
class manager :virtual protected employee {
protected:
	int bonus;
public:
	manager(std::string, int, int);
	void pay();
	void show();
	double getsalary() { return salary; }
};
class technician :virtual protected employee {
protected:
	int workhours;
	int extra_hours;
	int extra_salary;
public:
	technician(std::string, int, int, int);
	void pay();
	void show();
	double getsalary() { return salary; }
};
class saler :virtual protected employee {
protected:
	double sum_sale;
	double career_salary;
public:
	saler(std::string, int, int, double);
	void pay();
	void show();
	double getsalary() { return salary; }
};
employee::employee(std::string name = "name", int ID = 0, int grade = 0) {
	this->name = name;
	this->ID = ID;
	this->grade = grade;
	latedays = 0;
	base_salary = grades[grade];
	salary = 0;
}
void employee::pay() {
	std::cout << "please import late days:" ;
	std::cin >> latedays;
	salary = base_salary - 50 * latedays;
}
void employee::show() {
	std::cout << "name:" << name << std::endl
		<< "ID ;" << ID << std::endl
		<< "base_salary is;" << base_salary << std::endl
		<< "late days is:" << latedays << std::endl;
}
void employee::show_salary() {
	std::cout << "salary is:" << salary << std::endl;
}
double employee::getsalary() {
	return salary;
}
manager::manager(std::string name = "name", int ID = 0, int grade = 0) :employee(name, ID, grade) {
	bonus = grades[grade];
}
void manager::pay() {
	std::cout << "please import late days:" ;
	std::cin >> latedays;
	salary = base_salary - 50 * latedays + bonus;
}
void manager::show() {
	employee::show();
	std::cout << "bonus is:" << bonus << std::endl;
	employee::show_salary();
}
technician::technician(std::string name = "name", int ID = 0, int grade = 0, int workhours = 0) :employee(name, ID, grade) {
	this->workhours = workhours;
	extra_salary = 50;
}
void technician::pay() {
	std::cout << "please import late days:";
	std::cin >> latedays;
	extra_salary = extra_hours * workhours;
	salary = base_salary - 50 * latedays + extra_salary;
}
void technician::show() {
	employee::show();
	std::cout << "extra_salary is:" << extra_salary << std::endl;
	employee::show_salary();
}
saler::saler(std::string name = "name", int ID = 0, int grade = 0, double sum_sale = 0) :employee(name, ID, grade) {
	this->sum_sale = sum_sale;
	career_salary = sum_sale / 10;
}
void saler::pay() {
	std::cout << "please import late days:";
	std::cin >> latedays;
	salary = base_salary - 50 * latedays + career_salary;
}
void saler::show() {
	employee::show();
	std::cout << "career_salary:" << career_salary << std::endl;
	employee::show_salary();
}
class company {
	std::string name;
	std::string adress;
	std::string tele;
	manager *m;
	technician *t;
	saler *s;
public:
	company(int, int, int, std::string, std::string, std::string);
	void sum_salary(int, int, int);
};
company::company(int m1, int t1, int s1, std::string name = "company", std::string adress = "adress", std::string tele = "110") {
	m = new manager[m1];
	t = new technician[t1];
	s = new saler[s1];
	this->name = name;
	this->adress = adress;
	this->tele = tele;
	int i = 0;
	for (i = 0; i < m1; i++) {
		std::string name;
		int man,g;
		std::cout << std::endl<<"please import manager's name,ID,grade:";
		std::cin >> name >> man >> g;
		if(g>8||g<1){
			std::cout<<std::endl<<"grade's round 1-8"<<std::endl;
			exit(0);
		}
		m[i]=manager(name, man, g);
		m[i].pay();
	}
	for (i = 0; i < t1; i++) {
		std::string name;
		int m, g, w;
		std::cout <<std::endl<< "please import technician's name,ID,grade£¬workhours:";
		std::cin >> name >> m >> g >> w;
		if(g>8||g<1){
			std::cout<<std::endl<<"grade's round 1-8"<<std::endl;
			exit(0);
		}
		t[i]=technician(name, m, g, w);
		t[i].pay();
	}
	for (i = 0; i < s1; i++) {
		std::string name;
		int m, g, sa;
		std::cout <<std::endl<< "please import saler's name,ID,grade,total sales:";
		std::cin >> name >> m >> g >> sa;
		if(g>8||g<1){
			std::cout<<std::endl<<"grade's round 1-8"<<std::endl;
			exit(0);
		}
		s[i]=saler(name, m, g, sa);
		s[i].pay();
	}
}
void company::sum_salary(int m1, int t1, int s1) {
	double sum = 0;
	int i;
	for (i = 0; i < m1; i++) {
		sum = m[i].getsalary() + sum;
	}
	for (i = 0; i < t1; i++) {
		sum = t[i].getsalary() + sum;
	}
	for (i = 0; i < s1; i++) {
		sum = s[i].getsalary() + sum;
	}
	std::cout << "sum salary is:"<<sum<<std::endl;
}
int main() {
	std::cout << "please import number of managers,tecgnicians,salers:" ;
	int m, t, s;
	std::cin >> m >> t >> s;
	company c(m, t, s);
	c.sum_salary(m,t,s);
	return 0;
}