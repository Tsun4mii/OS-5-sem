﻿#include <iostream>
#include<Windows.h>
#include <process.h>
using namespace std;

int main()
{
    LPCWSTR chp1 = L"E:\\3rd-course\\1st-sem\\ОС\\Lab_3\\OS03_02_01\\Debug\\OS03_02_01.exe"; //длинный указатель на постоянную строку
    LPCWSTR chp2 = L"E:\\3rd-course\\1st-sem\\ОС\\Lab_3\\OS03_02_02\\Debug\\OS03_02_02.exe";
    // Структура STARTUPINFO используется функцией CreateProcess для определения свойств главного окна,
    // если новое окно создаётся для нового процесса
    STARTUPINFO w1;
    STARTUPINFO w2;
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;
    ZeroMemory(&w1, sizeof(STARTUPINFO)); w1.cb = sizeof(STARTUPINFO);
    ZeroMemory(&w2, sizeof(STARTUPINFO)); w2.cb = sizeof(STARTUPINFO);

    if (CreateProcess(chp1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &w1, &pi1))
        cout << "-- Process OS03_02_1 created" << endl;
    else {
        cout << "-- Process OS03_02_1 not created" << endl;
    }

    if (CreateProcess(chp2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &w2, &pi2))
        cout << "-- Process OS03_02_2 created" << endl;
    else {
        cout << "-- Process OS03_02_2 not created" << endl;
    }

    for (int i = 0; i < 100; i++) {
        cout << i << "  OS03_02 " << " PID:" << _getpid() << endl;;
        Sleep(1000);
    }

    WaitForSingleObject(
        pi1.hProcess, // идентификатор объекта
        INFINITE      // время ожидания в милисекундах
    );
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);
}


