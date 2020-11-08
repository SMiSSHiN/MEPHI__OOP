#include <iostream>
#include "vector.h"

using namespace Data_Types;

int main(int argc, char*argv[]){
    Vector a(10, 8), b(10, 1), c, d;

    Vector test = b;
    c = b;
    std::cout << "Your vector adress --> " << &test << "--" << &b << "--" << &c << std::endl;
    std::cout << "Your vector  --> " << c << test << b << std::endl;

    Vector vector(3, -1);
    int size, fl1 = 1, fl2 = 1;

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

                std::cout << "Your vector --> " << vector << std::endl;

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
        Vector elements(test_vector);
        std::cout << "Vector[..] + Elements[..] --> " << vector + elements << std::endl;

        int s_index, len;

        std::cout << std::endl << "Enter s_index and len --> ";
        try{
            getNum(s_index);
            getNum(len);
            std::cout << "Copied vector --> " << vector.copy(elements, s_index, len) << std::endl;
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

        std::cout << "------------------------------------------------------";
    }

    return 0;
}
