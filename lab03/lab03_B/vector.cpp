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

    std::istream &operator >>(std::istream &in, Vector &vector)
    {
        Vector tmp = vector;

        for(int i = 0; i < vector.qsz; i++){
            in >> vector.ar[i];
            if(!in.good()){
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                vector = tmp;
                throw std::runtime_error("Invalid input");
            }
        }

        return in;
    }

    const Vector Vector::operator +(const Vector &vector) const
    {
        Vector tmp;

        int size = (qsz < vector.qsz) ? qsz : vector.qsz;
        tmp.qsz = size;

        for(int i = 0; i < size; i++)
            tmp.ar[i] = ar[i] + vector.ar[i];

        return tmp;
    }
    
    Vector &Vector::copy(Vector &vector, int s_index, int len) const
    {
        if(s_index < 0)
            throw std::runtime_error("Invalid index");

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

    Vector &Vector::operator +=(int a)
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

    std::ostream &operator <<(std::ostream &out, const Vector &vector)
    {   
        int i = 0;
        out << "[" << vector.ar[i]; 

        for(i = 1 ; i < vector.qsz; i++)
            out << ", " << vector.ar[i];
        
        out << "]";
        
        return out;
    }

    void Vector::swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
}
