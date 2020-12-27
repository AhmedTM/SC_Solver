#include<iostream>
#include "cubicspline.tpp"
//#include "newtonspolynomial.h"
#include "newtonspolynomial.tpp"
int main()
{
    std::vector<double> x_data = {-9.7979797979798,-8.58585858585859,-7.57575757575758,-7.37373737373737,-4.54545454545455,-3.93939393939394,0.505050505050505,2.32323232323232,4.74747474747475,8.78787878787879};
    std::vector<double> y_data = {98.1628240367145,38.5844878743563,2.83468291732757,-2.9177707077921,-41.4650638617581,-41.0421014553246,20.3303208598587,59.3541681481688,106.087803862521,127.252413946629};
    vector<double> x(x_data);
    vector<double> y(y_data);
    double test = 10;
    newtoninterpolation<double> interpolator;
    interpolator.fit(x,y);
    double result = interpolator.interpolate(test);
    std::cout<<"result = "<<result<<std::endl;

    return 0;
}