﻿#include <iostream>
#include<Windows.h>
#include<TlHelp32.h>
#include<iomanip>
#include <process.h>
#include<string>
using namespace std;
int main()
{
    DWORD pid = GetCurrentProcessId();                        //извлечение ID  вызывающего процесса

    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);//cоздает снапшот запущенных 
                                                              //процессов, модулей, нитей и так далее

    PROCESSENTRY32 peProcessEntry;                            //Описывает запись из списка процессов, 
                                                              //находящихся в системном адресном пространстве при создании моментального снимка.

    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
    cout << L"Current PID = " << pid << endl << L"-------------------" << endl;
    try {
        if (!Process32First(snap, &peProcessEntry))
            throw L"Process32First";

        do {
            wcout << L"Name = " << peProcessEntry.szExeFile << endl
                << L"PID = " << peProcessEntry.th32ProcessID
                << L", Parent PID = " << peProcessEntry.th32ParentProcessID;

            if (peProcessEntry.th32ProcessID == pid)
                wcout << " --> current process";

            wcout << endl << L"----------------------" << endl;

        } while (Process32Next(snap, &peProcessEntry));
    }
    catch (char* msg) {
        wcout << L"Error : " << msg << endl;
    }
    system("pause");
    return 0;
}