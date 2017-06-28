#include<iostream>

#define ADDAPI(a)  API + a
#define API 1
void main()
{
    using namespace std;
    cout << ADDAPI(1) << endl;
    getchar();
}