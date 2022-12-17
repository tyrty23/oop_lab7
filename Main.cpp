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
        cout << "\t |            Выберите, что Вы хотите сделать              |\n";
        cout << "\t ----------------------------------------------------------\n";
        cout << "\t   1-добавить работника в конец\n\t   2-распечатать таблицу\n\t   3-найти работников департамента\n"
             << "\t   4-сортировать по уменьшению оклада\n\t   5-найти сотрудника по фамилии\n"   
             << "\t   6-добавить работника в определенную позицию\n\t   7-удалить работника из начала списка\n"
             << "\t   8-завершить работу\n";
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
            cout << "неверная команда" << endl;
        }
    }
}