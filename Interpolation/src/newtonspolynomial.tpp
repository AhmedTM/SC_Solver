#include "newtonspolynomial.h"
template <typename T>
newtoninterpolation<T>::newtoninterpolation(){}
template <typename T>
vector<T> newtoninterpolation<T>::fit(vector<T> x,vector<T> y)
{
    x_ = x;
    coeff_ = y;
    if(x.size()!=y.size())
    {
        throw std::runtime_error("x and y sizes is not equal");
    }
    for(int i = 0;i<x.size() - 1;i++)
    {
        for(int j = x.size() -1;j>i;j--)
        {
            coeff_[j] = (coeff_[j]-coeff_[j-1])/(x[j]-x[j-i-1]);
        }
    }
    coeff_.print();
    return coeff_;
        
}
template <typename T>
T newtoninterpolation<T>::interpolate(T x)
{
    if(coeff_.to_vector().empty())
    {
        throw std::runtime_error("please calculate the coeffs first");
    }
    T result = coeff_[0];

    for(int i = 1;i<coeff_.size();i++)
    {
        T temp = 1;
        for(int j = 0;j<i;j++)
        {
            //std::cout<<"I Number "<<j<<std::endl;
            temp *= (x-x_[j]);
            //std::cout<<"difference = "<<temp<<std::endl;
        }
        //std::cout<<temp<<std::endl;
        //std::cout<<"\n";
        //std::cout<<"temp = "<<temp<<std::endl;
        //std::cout<<"coeff = " <<coeff_[i]<<std::endl;
        //std::cout<<"result = " <<result<<std::endl;
        //std::cout<<"coeff*temp = " <<(coeff_[i]*temp)<<std::endl;
        
        result+=(temp*coeff_[i]);
        //std::cout<<"result = "<<result<<" iter_number = "<<i<<"\n"<<std::endl;
    }
    //std::cout<<"Result = "<<result<<std::endl;
    return result;
}