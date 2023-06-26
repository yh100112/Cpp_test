#include <iostream>
using namespace std;

int main()
{
    // 1바이트만큼 heap에 공간 할당
    char *pchar = new char;
    *pchar = 'a';
    cout << "메모리주소 :" << (void *)pchar << " 값 :" << *pchar << endl; // char만 좀 특별하게 void*써줘야 포인터변수가 담고있는 주소값이 보임
    delete pchar;

    // 4바이트만큼 heap에 공간 할당
    int *pnum = new int;
    *pnum = 3;
    cout << "메모리주소 :" << pnum << " 값 :" << *pnum << endl;
    delete pnum;

    // 8바이트만큼 heap에 공간 할당
    double *pdouble = new double;
    *pdouble = 3.1415;
    cout << "메모리주소 :" << pdouble << " 값 :" << *pdouble << endl;
    delete pdouble;

    // string 동적할당
    string *line = new string;
    *line = "hello";
    cout << *line << endl;
    delete line;
}