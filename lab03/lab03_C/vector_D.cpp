/*
    Если имя файла в угловых скобочках <>, то подклюаемый файл ищется в системных каталогах,
    если в "", то сначала в текущей директории, а потом в системных.
*/ 

/*
    Если в классе динамически выделяется память: при "поверхностном копировании" указателя 
    копируется только адрес указателя — никаких действий по содержимому адреса указателя 
    не предпринимается.
*/

#include "vector_D.h"
#include <limits.h>

namespace Data_Types{
    Vector::Vector(int size, int value) :SZ(QUOTA)
    {
        if(size < 0)
            throw std::runtime_error("Invalid size");

        if(size > 100)
            throw std::bad_alloc();

        while(size > SZ)
            SZ += QUOTA;
        while(size < SZ - QUOTA)
            SZ -= QUOTA;

        qsz = size;
        ar = new int[SZ];
        for(int i = 0; i < SZ; i ++)
            ar[i] = value;
    }

    Vector::Vector(const Vector &vector) : SZ(vector.SZ), qsz(vector.qsz)
    {
        ar = new int[SZ];
        for(int i = 0; i < SZ; i++)
            ar[i] = vector.ar[i];
    }

    Vector::Vector(int *vector, int size)
    {   
        if(size < 0)
            throw std::runtime_error("Invalid size");

        if(size > 100)
            throw std::bad_alloc();

        while(size > SZ)
            SZ += QUOTA;
        while(size < SZ - QUOTA)
            SZ -= QUOTA;
        
        qsz = size;
        ar = new int[SZ];
        int i, value = 0;

        // Инициализация элементами переданного вектора
        for(i = 0; i < qsz; i++)
            ar[i] = vector[i];
        // Присваивание созданным элементам значения "value"
        for(i ; i < SZ; i++)
            ar[i] = value;
    }

    Vector::Vector(Vector &&vector) :SZ(vector.SZ), qsz(vector.qsz), ar(vector.ar)
    {
        vector.ar = nullptr;
    }


    Vector &Vector::operator =(const Vector &vector)
    {
        if(this != &vector){
            SZ = vector.SZ;
            qsz = vector.qsz;
            delete[] ar;
            ar = new int[SZ];
            for(int i = 0; i < SZ; i ++)
                ar[i] = vector.ar[i];
        }

        return *this;
    }

    Vector &Vector::operator =(Vector &&vector)
    {
        if(&vector != this){
            SZ = vector.SZ;
            qsz = vector.qsz;
            delete[] ar;
            
            vector.SZ = 0;
            vector.qsz = 0;
            vector.ar = nullptr;
        }

        return *this;
    }

    Vector &Vector::operator +=(int a)
    {   
        if(qsz == SZ){
            int *old = ar;
            //...
            SZ += QUOTA;
            ar = new int[SZ];

            int i;
            int element = 0;

            // Копирование старой части вектора
            for(i = 0; i < qsz; i++)
                ar[i] = old[i];
            delete[] old;

            // Добавление нового
            ar[i++] = a;
            qsz += 1;

            // SZ += QUOTA;
            // Присваивание созданным элементам значения "value"
            for(i ; i < SZ; i++)
                ar[i] = element;
        }else
            ar[qsz++] = a;

        return *this;
    }
    
    const Vector Vector::operator +(const Vector &vector) const
    {
        int size = (qsz < vector.qsz) ? qsz : vector.qsz;

        Vector new_vector(size);

        for(int i = 0; i < size; i++)
            new_vector.ar[i] = ar[i] + vector.ar[i];

        return new_vector;
    }


    Vector &Vector::setSize(int size)
    {
        if(size < 0)
            throw std::runtime_error("Invalid size");
        if(size > 100)
            throw std::bad_alloc();
        
        int OLD_SZ = SZ;

        while(size > SZ)
            SZ += QUOTA;
        while(size < SZ - QUOTA)
            SZ -= QUOTA;

        if(OLD_SZ != SZ){
            int *old = ar;
            // ...
            ar = new int[SZ];

            int i;
            int value = 0;

            // Копирование старой части вектора
            int tmp_qsz = (SZ < qsz) ? SZ : qsz;
            for(i = 0; i < tmp_qsz; i++)
                ar[i] = old[i];
            delete[] old;
            qsz = size;

            // Присваивание созданным элементам значения "value"
            for(i ; i < qsz; i++)
                ar[i] = value;
        }else
            qsz = size;

        return *this;
    }
    
    Vector &Vector::copy(Vector &vector, int s_index, int len) const
    {
        if(s_index < 0)
            throw std::runtime_error("Invalid index");

        if(len < 0)
            throw std::runtime_error("Invalid lenght");

        if(s_index + len > qsz)
            throw std::runtime_error("Invalid lenght or start index");
        
        int e_index = s_index + len;
        int j = 0;

        vector.qsz = len;

        for(int i = s_index; i < e_index; i ++)
            vector.ar[j++] = ar[i];

        return vector;
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
