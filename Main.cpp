#define _CRT_SECURE_NO_WARNINGS
#include <list>
#include <Windows.h>
#include "worker.h"
#include "Fio.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");

    list<Worker> ar;

    Worker::Load(ar);

    while (true) {
        cout << "==============================================================================\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t |            ��������, ��� �� ������ �������              |\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t   1-�������� ��������� � �����\n\t   2-����������� �������\n\t   3-����� ���������� ������������\n"
             << "\t   4-����������� �� ���������� ������\n\t   5-����� ���������� �� �������\n"   
             << "\t   6-�������� ��������� � ������������ �������\n\t   7-������� ��������� �� ������ ������\n"
             << "\t   8-��������� ������\n";
        cout << "==============================================================================\n";
        int t;
        t = Worker::right_int();
        if (t == 1) {
            system("cls");
            Worker::AddWorkerEnd(ar);
        }
        if (t == 2) {
            system("cls");
            Worker::PrintAll(ar);
        }
        if (t == 3) {
            system("cls");
            Worker::PrintDep(ar);
        }
        if (t == 4) {
            system("cls");
            Worker::SortSalary(ar);
        }
        if (t == 5) {
            system("cls");
            Worker::FindWorker(ar);
        }
        if (t == 6) {
            system("cls");
            Worker::AddWorkerNum(ar);
        }
        if (t == 7) {
            system("cls");
            Worker::DelWorkerBeg(ar);
        }
        if (t == 8) {
            system("cls");
            Worker::Save(ar);
            break;
        }
        if (t != 1 && t != 2 && t != 3 && t != 4 && t != 5 && t != 6 && t != 7 && t != 8) {
            cout << "�������� �������" << endl;
        }
    }
}