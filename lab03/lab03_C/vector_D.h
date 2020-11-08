/* 
   Используется директива ifndef, чтобы понять, определена ли 
   переменная _VECTOR_D_H_. Если не определена, то выполняется код до endif.

   Делается это для того, чтобы если в каком-то файле повторно включен файл vector_D, то
   переменная _VECTOR_D_H_ будет уже определена и все до endif будет пропушено
*/

#ifndef _VECTOR_D_H_
#define _VECTOR__D_H_ 

#include <iostream>
#include <limits>

template <typename T>
void getNum(T &num){
    std::cin >> num;
    if(!std::cin.good()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        throw std::runtime_error("Invalid data");
    }
}

namespace Data_Types{
    class Vector{
        private:
        /*
            static означает, что сколько бы экземпляров класса мы бы не создали
            для static const будет выдклкно только одно место в памяти. Одна копия для 
            всех экземпляров класса.
        */
            static const int QUOTA = 10;
            int SZ;
            int qsz;
            int *ar;
            void swap(int &, int &);
        public:
            Vector(int size = 0, int value = 0);
            Vector(int *, int);
            Vector(const Vector &); // Конструктор копирования
            Vector(Vector &&); // Конструктор перемещения
            ~Vector(){ delete[] ar; }

            Vector &operator =(const Vector &); // Оператор присваивания копированием
            Vector &operator =(const Vector &&); // Оператор присваивания перемещением
            Vector &operator +=(int );
      const Vector operator +(const Vector &) const;

            Vector &setSize(int );
            Vector &input();
            Vector &copy(Vector &, int, int) const;
            Vector &sort();
            int max() const;

            friend std::istream &operator >>(std::istream &, Vector &);
            friend std::ostream &operator <<(std::ostream &, const Vector &);
    };
}

#endif