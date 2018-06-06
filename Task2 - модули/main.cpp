#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstring>

// ���������� ������ ������ � ���������
#include "IntArrHeader.h"


using namespace std;

void sort(IntArray array)//���������� �������
{
    int result1;
    int result2;
    for (int i = 0; i < *array.size; ++i) //���� ����������� ���� �� �������� ��� �������� �������
        {

            for (int j = 0; j < *array.size - 1 - i; ++j) // ������� � ������� ��������
            {

                if ((Return(array,j,result1)) && (Return(array, j+1, result2))) {
                        /*���� �������� J �������� ����� �������� result1
                        � �������� ���������� �������� ����� result 2, ��*/
                    if (result1 > result2)
                        /*���� �������� ������� ������ ��� �������� �������, ��
                        ����������� �������� J �������� result2*/
                        {
                        Assignment(array, j, result2);
                        Assignment(array, j+1, result1);
                        }
                    }
                else { // � ������ ������ ����� �� �������
                    cout << "Going abroad";
                }

            }

        }

}
void mistake(IntArray array){
for ( int i=0; i > array.size; ++i){
        cout << "Error: you went beyond the array";
}


int main()
{
    int size;//�������� ������� ��� �������� ������� ��������, ������� ��� ������������
    cout << "Enter the length of the array = ";
    cin >> size;
    IntArray array = CreateArray(size);//�������� ������� ������� size

    srand(time(NULL));
    char answer[100];

    for ( int i=0; i < size; ++i){//����� ������� �� �����
        Assignment(array, i, (rand() % 201 - 100);//�������� � �������� i ������������� �������� ���������� �����
    }
    cout << "array sorting";
    void sort();
    for ( int i=0; i < size; ++i){//����� ������� �� �����
        Assignment(array, i, *array.data);
    void mistake();

    DeleteArray(array);
    return 0;
}
}


