#ifndef NEWTON_H_
#define NEWTON_H_
#include<iostream>
#include<vector>
#include"vector.h"
#include"matrix.h"
template <typename T>
T f(T x1,T y1,T x2,T y2)
{
    return (y2-y1);
}
template <typename T>
class newtoninterpolation
{
    private:
        vector<T> x_;
        vector<T> coeff_;
    public:
        newtoninterpolation();
        vector<T> fit(vector<T> x,vector<T> y);
       
        T interpolate(T x);
};
#endif