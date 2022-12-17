#include "worker.h"

int
Worker::counter = 0;

Worker::Worker()
{
	Fio();
	num_dep = 1;
	salary = 50000;
}

Worker::Worker(Fio fio1, int dep, double sal)
{
	fio = { fio1.GetName(),fio1.GetSurname(),fio1.GetPatronymic() };
	num_dep = dep;
	salary = sal;
}

void Worker::SetNum_dep(int n)
{
	num_dep = n;
}

void Worker::PrintAll(list<Worker>&ar)
{
	line();
	for (Worker el : ar) {
		cout << el << endl;;
	}
}

void Worker::Save(list<Worker>& ar)
{
	ofstream fout("lab3.txt");
	fout << counter;
	for (Worker el : ar)
	{
		fout << el.fio.GetName() << " "
			<< el.fio.GetSurname() << " "
			<< el.fio.GetPatronymic() << " "
			<< el.num_dep << " "
			<< el.salary;
	}
	fout.close();
}

void Worker::Load(list<Worker>& ar)
{
	ifstream fin("lab3.txt");
	if (fin.is_open() && fin.peek() != EOF) {
		string n, s, p;
		fin >> counter;	
		for(int i=0;i<counter;i++)
			ar.push_back(Worker());
		for (list<Worker>::iterator it = ar.begin(); it != ar.end(); it++) {
			fin
				>> n
				>> s
				>> p
				>> (*it).num_dep
				>> (*it).salary;
			Fio fio1 = { n, s, p };
			(*it).fio = fio1;
			
		}
	}
	else {
		ofstream fout("lab3.txt");
		cout << "������� ���-�� ����� �������: ";
		int n = right_int();
		for (int i = 0; i < n; i++) {
			AddWorkerEnd(ar);
		}
		fout.close();
	}
	fin.close();
}

void Worker::PrintDep(list<Worker>& ar)
{
	bool l = 0;
	int test;
	cout << "������ ����� ������: ";
	test = right_int();
	for (Worker el :ar)
		if (test == el.num_dep) {
			l = 1;
		}
	if (l == 0) cout << "���������� ���������� ������������ � ���� ���\n";
	else {
		cout << "��������� ������� ������ :\n";
		line();
		for (Worker el : ar) {
			if (test == el.num_dep) {
				cout << el << endl;;
			}
		}
	}
}

void Worker::SortSalary(list<Worker>& ar)
{
	for (auto it1 = ar.begin(); it1 != ar.end(); it1++)
		for (auto it2 = ar.begin(); it2 != ar.end(); it2++)
			if ((*it2).salary < (*it1).salary) {
				iter_swap(it1,it2);
			}
}

void Worker::FindWorker(list<Worker>& ar)
{
	bool l = 0;
	string test;
	Fio test1;
	cout << "������ ������� ����������: ";
	cin >> test;
	test1.SetSurname(test);
	for (Worker el : ar)
		if (el == test1) {
			l = 1;
		}
	if (l == 0) cout << "���������� ���������� ������������ � ���� ���\n";
	else {
		cout << "��������� ������� ������ :\n";
		line();
		for (Worker el : ar) {
			if (el == test1) {
				cout << el << endl;;
			}
		}
	}
}

int Worker::right_int()
{
	string buff;
	/*cout << "������� ����� �����: ";*/
	cin >> buff;
	while (true) {
		if (atoi(buff.c_str()) != false) { return atoi(buff.c_str()); }
		else {
			cout << "������� ����� �����: ";
			cin >> buff;
		}
	}
}

double Worker::right_double()
{
	string buff;
	//cout << "������� ����� ���� double: ";
	cin >> buff;
	while (true) {
		if (atof(buff.c_str()) != false) { return atof(buff.c_str()); }
		else {
			cout << "������� ����� ���� double: ";
			cin >> buff;
		}
	}
}

void Worker::line()
{
	cout << setw(25) << "��� ���������"
		<< setw(30) << "�����������"
		<< setw(15) << "����� (&)" << endl;
}

void Worker::AddWorkerEnd(list<Worker>& ar)
{
	cout << "������ ������ ��������� � ������� ���, �����, ����� ����� ������ ��� enter: \n";
	Worker w;
	cin >> w;
	ar.push_back(w);
	counter++;
}

void Worker::AddWorkerNum(list<Worker>& ar)
{
	list<Worker>::iterator it=ar.begin();
	cout << "������ ������ ��������� � ������� ���, �����, ����� ����� ������ ��� enter: \n";
	Worker w;
	cin >> w;
	cout<< "������ �������, �� ������� ��������� ������ ���������: \n";
	int n = right_position(ar.size());
	for (int i = 0; i < n-1; i++)
		it++;
	ar.insert(it,w);
	counter++;
}

void Worker::DelWorkerBeg(list<Worker>& ar)
{
	ar.pop_front();
}

int Worker::right_position(int end)
{
	string buff;
	/*cout << "������� ����� �����: ";*/
	cin >> buff;
	while (true) {
		if (atoi(buff.c_str()) != false ){
			if(0 < atoi(buff.c_str())&& atoi(buff.c_str()) < end)
				return atoi(buff.c_str());		
			else {
				cout << "������� ����� �����: ";
				cin >> buff;
				continue;
			}
		} 
		else {
			cout << "������� ����� �����: ";
			cin >> buff;
		}
	}
}

bool operator==(Worker w, Fio f)
{
	if (w.fio.GetSurname() == f.GetSurname()) {
		return true;
	}
	else {
		return false;
	}

}

istream& operator>>(std::istream& in, Worker& w)
{
	in >> w.fio >> w.num_dep >> w.salary;
	return in;
}

ostream& operator<<(std::ostream& out, Worker& w)
{
	out << w.fio
		<< setw(15) << w.num_dep
		<< setw(20) << w.salary << endl;
	return out;
}
