#include <iostream>
#include <cmath>
using namespace std;

void plusone(int a, int b){
	a=a+1;
	b=a+1;
	cout<<"После выполнения функции plusone значения а и б изменились"<<endl;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int a =0;
    int b =1; //пусть имеются 2 проинициализированные переменные
    cout<<"начальные значения:";
    cout<<"a ="<<a<<endl;
    cout<<"b ="<<b<<endl;
    plusone(a,b);
    cout<<"Конечные значения:"<<endl;
    cout<<"a ="<<a<<endl;
    cout<<"b ="<<b<<" ";

}
