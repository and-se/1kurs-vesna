#include <iostream>

using namespace std;

void setPointer (int a){
    int* pa=&a;
    cout<<"адрес копии переменной k: "<<pa<<endl;
    cout<<"a(копия k)= "<<a<<endl;
}

int main()
{
    setlocale(0, "");
    int k(9);
    int* pk=&k;
    cout<<"адрес переменной k: "<<pk<<endl;
    setPointer(k);// в переменную a копируется переменная k
    cout<<"k= "<<k<<endl;
    return 0;
}
