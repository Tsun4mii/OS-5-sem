#include <iostream>
#include <Windows.h>

#define KB (1024)
#define PG (4 * KB)

using namespace std;

int main() {
    int pages = 256;
    int countItems = pages * PG / sizeof(int);

    LPVOID addr = VirtualAlloc(NULL, pages * PG, MEM_COMMIT, PAGE_READWRITE);
    int* arr = (int*)addr;
    for (int i = 0; i < countItems; i++) {
        arr[i] = i;
    }
    cout << endl;

    getchar();



    system("pause");
}

//Ш (216dec) D8 hex
//У (211dec) D3 hex
//С (209dec) D1 hex
//Page: D8 = 216dec, offset = D3D1 = 54225
//adress 216 * PG + 54225 = 938 961 (3AA)
//009e00000 + 3AA = 009e03AA