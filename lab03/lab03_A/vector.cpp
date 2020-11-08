#include "vector.h"
#include <limits.h>

namespace Data_Types{
    Vector::Vector(int size, int value)
    {
        if(size < 0 || size > SZ)
            throw std::runtime_error("Invalid size");

        qsz = size;

        for(int i = 0; i < SZ; i++)
            ar[i] = value;
    }

    Vector &Vector::setSize(int size)
    {
        if(size < 0 || size > SZ)
            throw std::bad_alloc();

        qsz = size;

        return *this;
    }

    Vector &Vector::setArray(int *array, int size)
    {
        if(size < 0 || size > SZ)
            throw std::runtime_error("Invalid size");

        qsz = size;

        for(int i = 0; i < size; i++)
            ar[i] = array[i];

        return *this;
    }

    Vector &Vector::input()
    {   
        int size;

        std::cin >> size;
        if(!std::cin.good())
            throw std::runtime_error("Invalid data");

        if(size > SZ || size < 0)
            throw std::runtime_error("Invalid size");
        qsz = size;

        std::cout << "Enter vector elements --> ";
        for(int i = 0; i < size; i++){
            std::cin >> ar[i];
            if(!std::cin.good())
                throw std::runtime_error("Invalid data");
        }

        return *this;
    }

    Vector &Vector::add(const Vector &vector)
    {
        int size = (qsz < vector.qsz) ? qsz : vector.qsz;

        for(int i = 0; i < size; i++)
            ar[i] += vector.ar[i];

        return *this;
    }
    
    Vector &Vector::copy(Vector &vector, int s_index, int len) const
    {
        if(s_index + len > qsz)
            throw std::runtime_error("Invalid lenght");
        
        int e_index = s_index + len;
        int j = 0;

        vector.qsz = len;

        for(int i = s_index; i < e_index; i ++){
            vector.ar[j] = ar[i];
            j++;
        }

        return vector;
    }

    Vector &Vector::push(int a)
    {
        if(qsz == SZ)
            throw std::runtime_error("Vector overflow");
        
        ar[qsz] = a;
        qsz += 1;

        return *this;
    }

    Vector &Vector::sort()
    {
        int i, j;

        for(i = 0; i < qsz - 1; i++){
            for(j = 0; j < qsz - i - 1; j++)
                if(ar[j] > ar[j + 1])
                    swap(ar[j], ar[j + 1]);
        }

        return *this;
    }

    int Vector::max() const
    {       
        int max = INT_MIN;

        for(int i = 0; i < qsz; i++)
            if (ar[i] > max) max = ar[i];

        return max;
    }

    std::ostream &Vector::print(std::ostream &s) const
    {   
        int i = 0;
        s << "[" << ar[i]; 

        for(i = 1 ; i < qsz; i++)
            s << ", " << ar[i];
        
        s << "]" << std::endl;
        
        return s;
    }

    void Vector::swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
}
