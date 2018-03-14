#include "IntArray_h.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include <cstring>

void help();
void write (IntArray array);
void move (IntArray array , int direct);
void sort (IntArray array, int direct);
void put (IntArray array, int index, int value);
void reverse (IntArray array);
IntArray newArray (IntArray array);

int main(int argc, char *argv[]) {
    int size;
    std::cout << "Enter array length" << std::endl;
    std::cout << ">>";
    std::cin >> size;
    std::cout << std::endl;
    IntArray array = create(size);
    srand(time(0));
    char answer[100];

    for (int i = 0; i < size; ++i) {
        setItem(array, i, rand() % 201 - 100);
    }

    while (strcmp(answer, "quit") != 0){
        std::cout<< "Type command. Type 'help' for help" << std::endl;
        std::cout << ">>";
        std::cin >> answer;

        if (strcmp(answer, "help") == 0) {
            help();
        }

        if (strcmp(answer, "write") == 0) {
            write(array);
        }

        if (strcmp(answer, "mover") == 0) {
            std::cout << "Enter the number of moves" << std::endl;
            int count;
            std::cout << ">>";
            std::cin >> count;

            for (int i = 0; i < count; ++i) {
               move(array, 1);
            }

            std::cout << std::endl;
        }

        if (strcmp(answer, "movel") == 0) {
            std::cout << "Enter the number of moves" << std::endl;
            int count;
            std::cout << ">>";
            std::cin >> count;

            for (int i = 0; i < count; ++i) {
                move(array, -1);
            }

            std::cout << std::endl;
        }

        if (strcmp(answer, "sortu") == 0) {
            sort(array, 1);
            std::cout << std::endl;
        }

        if (strcmp(answer, "sortd") == 0) {
            sort(array, -1);
            std::cout << std::endl;
        }

        if(strcmp(answer, "put") == 0) {
            std::cout << "Enter position" << std::endl;
            int index = 0;
            std::cout << ">>";
            std::cin >> index;

            std::cout << "Enter new value" << std::endl;
            int value;
            std::cout << ">>";
            std::cin >> value;

            put(array, index, value);
        }

        if(strcmp(answer, "reverse") == 0){
            reverse(array);
            std::cout << std::endl;
        }

        if (strcmp(answer, "new") == 0) {
            array = newArray(array);
        }

    }

    return 0;
}

void write (IntArray array) {
    int result;
    for (int i = 0; i < *array.size; ++i)
    {
        if (getItem(array, i, result)) {
            std::cout << result << " ";
        } else {
            std::cout << "Error: out of bounds";
            break;
        }
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void sort (IntArray array, int direct) {
    int result1, result2;

    if (direct == 1){

        for (int i = 0; i < *array.size; ++i)
        {

            for (int j = 0; j < *array.size - 1 - i; ++j)
            {

                if ((getItem(array,j,result1)) && (getItem(array, j+1, result2))) {

                    if (result1 > result2) {
                        setItem(array, j, result2);
                        setItem(array, j+1, result1);
                    }

                } else {
                    std::cout << "Error: out of bounds";
                }

            }

        }

    } else {

        for (int i = 0; i < *array.size; ++i)
        {

            for (int j = 0; j < *array.size - 1 - i; ++j)
            {

                if ((getItem(array,j,result1)) && (getItem(array, j+1, result2))) {

                    if (result1 < result2) {
                        setItem(array, j, result2);
                        setItem(array, j+1, result1);
                    }

                } else {
                    std::cout << "Error: out of bounds";
                }

            }

        }

    }
}

void help(){
    std::cout << "Type 'new' to delete old and create new array" << std::endl;
    std::cout << "Type 'write' to output array" << std::endl;
    std::cout << "Type 'mover' to move array to the right" << std::endl;
    std::cout << "Type 'movel' to move array to the left" << std::endl;
    std::cout << "Type 'sortu' to sort array in ascending order" << std::endl;
    std::cout << "Type 'sortd' to sort an array in descending order" << std::endl;
    std::cout << "Type 'put' to to change one value in array" << std::endl;
    std::cout << "Type 'reverse' to reverse array" << std::endl;
    std::cout << "Type 'quit' for quit" << std::endl;
    std::cout << std::endl;

}

void move(IntArray array, int direct) {

    if(direct == 1){
        int tmp;
        getItem(array, *array.size - 1, tmp);

            for (int i = *array.size - 2; i >= 0; i--) {
                int result;

                if (getItem(array, i, result)) {

                    if(!setItem(array, i+1, result)) {
                        std::cout << "Error: out of bounds" << std::endl;
                    }

                } else {
                    std::cout << "Error: out of bounds" << std::endl;
                }

            }

            setItem(array, 0 ,tmp);

    } else {
        int tmp;
        getItem(array, 0, tmp);

        for (int i = 0; i <= *array.size - 2; ++i) {
            int result;

            if (getItem(array, i+1, result)) {
                
                if(!setItem(array, i, result)) {
                    std::cout << "Error: out of bounds" << std::endl;
                }

            } else {
                std::cout << "Error: out of bounds" << std::endl;
            }

        }

        setItem(array, *array.size - 1, tmp);
    }
}

void put (IntArray array, int index, int value) {
    if(!setItem(array, index - 1, value)) {
        std::cout << "Error: out of bounds" << std::endl;
    }
}

void reverse (IntArray array) {

    for (int i = 0; i < *array.size/2; ++i) {
        int tmp1, tmp2;
        
        if((getItem(array, i, tmp1)) && (getItem(array, *array.size - i -1, tmp2))) {
            setItem(array, i , tmp2);
            setItem(array, *array.size -i - 1, tmp1);
        } else {
            std::cout << "Error: out of bounds" << std::endl;
        }
    }
}

IntArray newArray (IntArray array) {
    remove(array);
    int size;
    std::cout << "Enter array length" << std::endl;
    std::cout << ">>";
    std::cin >> size;
    std::cout << std::endl;
    IntArray result = create(size);

    for (int i = 0; i < size; ++i) {
        setItem(result, i, rand() % 201 - 100);
    }

    return result;
}
