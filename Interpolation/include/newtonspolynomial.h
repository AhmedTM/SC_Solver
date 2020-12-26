#ifndef NEWTON_H_
#define NEWTON_H_
#include<iostream>
#include<vector>
#include"vector.h"
#include"matrix.h"
template <typename T>
class newtoninterpolation
{
    private:
        vector<T> x_;
        vector<T> y_;
        vector<T> coeff_;
    public:
        newtoninterpolation();
        void Init(vector<T> x,vector<T> y);
        vector<T> Solve();
};

#endif