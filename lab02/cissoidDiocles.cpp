#include <iostream>
#include <limits>

#include "cissoidDiocles.h"
// #include <libcissoid>

using namespace curves;

int main(int argc, char*argv[]){ // ???

    CissoidDiocles object(4);

    int fl1 = 1;
    double rad;
    
    while(fl1){
        std::cout << "Coefficient in the asymptote equation: " << object.k_asymptote() << std::endl;
        std::cout << "Area: " << object.area() << std::endl;
        std::cout << "Volume: " << object.volume() << std::endl;
        std::cout << "Coefficient in the parabola equation: " << object.k_parabola() << std::endl;

        int fl2 = 1;
        while(fl2){
            std::cout << "Enter x for calculate value y(x) or press ctrl+Z to quit -- > ";
            
            double x, fi;
            Point y;

            std::cin >> x;
            fl2 = std::cin.good();
            if(!fl2){
                /*
                cin.clear() очищает признак ошибки, если он у cin взвёлся (с признаком ошибки дальнейший ввод 
                не пройдёт). cin.ignore(...) пропускает во входном потоке всё до следующего \n (то есть, до конца строки)
                */
                std::cout << "You have entered incorrect data..." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                fl2 = 1;

                continue;
            }

            // Правильность ввода x
            try{
                y = object.y(x);
                std::cout << "y1 = " << y.x << ", y2 = " << y.y << std::endl;
            }
            catch(std::runtime_error &re){
                std::cout << re.what() << std::endl; 

                continue;      
            }

            while(fl2){
                std::cout << "Enter fi for calculate distance or press ctrl+Z to quit -- > ";

                std::cin >> fi;
                fl2 = std::cin.good();
                if(!fl2){
                    std::cout << "You have entered incorrect data..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    fl2 = 1;

                    continue;
                }

                // Правильность ввода fi
                try{
                    x = object.distance(fi);
                    std::cout << "distance: " << x << std::endl;
                }
                catch(std::exception &re){
                    std::cout << re.what() << std::endl; 

                    continue;    
                }

                break;
            }

            break;
        }

        while(fl2){
            std::cout << std::endl << "Enter new radius to continue or press ctrl+Z to quit --> ";
            std::cin >> rad;
            fl2 = std::cin.good();
            if(!fl2){

                std::cout << "You have entered incorrect data..." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                fl2 = 1;

                continue;
            }

            try{
                object.setRad(rad);

                break;
            }
            catch(std::runtime_error &re){
                std::cout << re.what() << std::endl;
            }
        }
        
    }

    return 0;
}
