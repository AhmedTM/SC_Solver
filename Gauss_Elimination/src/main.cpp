#include "vector.h"

int main(int argc, char *argv[])
{
    int size = 5;
    //std::cout << "h"<<std::endl;
    vector<double> a(size);
    //std::cout << "e"<<std::endl;
    vector<double> b(size);
    //std::cout << "l"<<std::endl;

    for(int i =0; i < size;i++)
    {
        //std::cout << "o"<<std::endl;
        a.push_back((double)12);
        //std::cout << "w"<<std::endl;
        b.push_back((double)24);
        //std::cout << "r"<<std::endl;
    }
    //std::cout << a.size()<<std::endl;
    //std::cout << b.size()<<std::endl;

    vector<double> c(5);
    c=a+b;

    std::cout << "vec a + b = \n"<<std::endl;
    c.print();
    c[0] = 25;
    std::cout << "\nc[0] = "<< c[0] <<std::endl;
    c.push_back((double)10);
    std::cout << "\nc new size = " << c.size()<<std::endl;
    c.print();
    
}