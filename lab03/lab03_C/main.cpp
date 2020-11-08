#include <iostream>
#include "vector_D.h"

using namespace Data_Types;

int main(int argc, char*argv[]){
    Vector a(8, 8), b(11, -1), c;

    Vector vector(3, -1);
    int size, fl1 = 1, fl2 = 1;

    // Присваивание по умолчанию - поверхностное копирование при работе с указателями
    // поэтому перегружаем
    a = b;

    while(fl1){
        fl2 = 1;
        std::cout << std::endl << "------------------------------------------------------" << std::endl;
        while(fl2){
            std::cout << "Enter vector size --> ";  
            try{
                getNum(size);
                vector.setSize(size);
                std::cout << "Enter vector elements --> "; 
                std::cin >> vector;

                std::cout << std::endl << "Your vector --> " << vector << std::endl;

                fl2 = 0;
            }catch(std::exception &ex){
                std::cout << ex.what() << std::endl;

                fl2 = 1;
            }catch(std::bad_alloc &ba){
                std::cout << ba.what() << std::endl << "Invalid size" << std::endl;

                fl2 = 1;
            }
        }

        std::cout << "Sorted vector --> " << vector.sort() << std::endl;
        std::cout << "Max element --> " << vector.max() << std::endl;

        int test_vector[] = {-1, 0, 3, 5, 90, 23};
        Vector elements(test_vector, 6);
        std::cout << "Vector[..] + Elements[..] --> " << vector + elements << std::endl;

        int s_index, len;

        std::cout << std::endl << "Enter s_index and len --> ";
        try{
            getNum(s_index);
            getNum(len);
            Vector copy_vector = vector.copy(elements, s_index, len);
            std::cout << "Copied vector --> " << copy_vector << std::endl;
        }catch(std::exception &ex){
            std::cout << ex.what() << std::endl;
        }

        int value;

        std::cout << "Enter pushed value --> ";
        try{
            getNum(value);
            vector += value;
            std::cout << "New vector --> " << vector << std::endl;
        }catch(std::exception &ex){
            std::cout << ex.what() << std::endl;
        }

        std::cout << "------------------------------------------------------" << std::endl;
    }

    return 0;
}
