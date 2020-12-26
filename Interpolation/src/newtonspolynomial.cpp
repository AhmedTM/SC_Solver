#include "newtonspolynomial.h"

void newtoninterpolation::Init(vector<T> x,vector<T> y)
{
    x = newtoninterpolation::x_;
    y = newtoninterpolation::y_;
}
vector<T> newtoninterpolation::Solve()
{
    
    return newtoninterpolation::coeff_;
}