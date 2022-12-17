#pragma once
#include <iomanip>
#include <fstream>
#include<list>
#include "Fio.h"


using namespace std;

class Worker
{
	friend bool operator==(Worker, Fio);
	friend istream& operator >> (istream&, Worker&);
	friend ostream& operator << (ostream&, Worker&);

	Fio fio;
	int num_dep;
	double salary;
public:
	static int counter;
	Worker();
	Worker(Fio, int, double);
	void SetNum_dep(int);
	static void PrintAll(list<Worker>&);
	static void Save(list<Worker>&);
	static void Load(list<Worker>&);
	static void PrintDep(list<Worker>&);
	static void SortSalary(list<Worker>&);
	static void FindWorker(list<Worker>&);
	static int right_int();
	static double right_double();
	static void line();
	static void AddWorkerEnd(list<Worker>&);
	static void AddWorkerNum(list<Worker>&);
	static void DelWorkerBeg(list<Worker>&);
	static int right_position(int);

};

