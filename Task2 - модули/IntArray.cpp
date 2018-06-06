// ���������� ������������ ���� � ������������
#include "IntArrHeader.h"
// ����������� ������ �����-������ ����� ��� ��� ������������ ����������, ����� ������� ��� ������ �������
#include <iostream>
// ������ ��� ������ � �������� free;
#include <cstdlib>
using namespace std;

IntArray CreateArray(int size)
{
    cout << "Create array with length = " << size << endl;

    // ����� �����-������ ����������� ���������
    IntArray array;

    array.data = 0;
    *array.size = size;

    return array;
}


void DeleteArray(IntArray array)
{
    cout << "Delete your array" << endl;
    delete array.data; //�������� ������ ��������� ��� ���������� �� ���������
    delete array.size;
}


bool Return (IntArray array, int index, int& result)
{
    if ((*array.size <= index) || (index < 0))
    {
        return false;       /* ���� ���������� �������� ����� ������ ��� ����� ������� � ���������� ������� ����� ������ ����,
                             �� ���������� false*/ }
    result = *(array.data + index); /* ��������� ����� ���������� ��������� � �� ��������, ���������� true,
                                      �.�. ������ �� ����� �� ��������  */
    return true;
}


bool Assignment (IntArray array, int index, int value)
{
    if ((*array.size <= index) || (index < 0))
    {
        return false;  }

    value = *(array.data + index);
    return true;
}
