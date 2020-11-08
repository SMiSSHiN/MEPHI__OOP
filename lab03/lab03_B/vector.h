#ifndef _VECTOR_H_
#define _VECTOR_H_ 

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
            static const int SZ = 10;
            int qsz;
            int ar[SZ];
            void swap(int &, int &);
        public:
            Vector(int size = 0, int value = 0);

            template <size_t size>
            Vector(const int (&elements)[size])
            {
                if(size > SZ)
                    throw std::runtime_error("Invalid size");

                qsz = size;
                int i;

                for(i = 0; i < size; i++)
                    ar[i] = elements[i];
                for(i; i < SZ ; i++)
                    ar[i] = 0;
            }

            Vector &setSize(int );
            friend std::istream &operator >>(std::istream &, Vector &);
            Vector &input();
            const Vector operator +(const Vector &) const;
            Vector &copy(Vector &, int, int) const;
            Vector &operator +=(int );
            Vector &sort();
            int max() const;
            friend std::ostream &operator <<(std::ostream &, const Vector &);
    };
}

#endif