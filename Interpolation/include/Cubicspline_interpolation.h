#ifndef CUBIC_H_
#define CUBIC_H_
#include<iostream>
#include<vector>
#include"vector.h"
#include"matrix.h"
#include "gauss_elimination.h"


class Cubicspline_interpolation
{
public:
	Cubicspline_interpolation();
	void fit(std::vector<double> x, std::vector<double> y);
	double interpolate(double x);
	~Cubicspline_interpolation();
private:
    
    std::vector<double> si_;
	std::vector<double> x_;
    std::vector<double> a_;
    std::vector<double> b_;
    std::vector<double> c_;
    std::vector<double> d_;
    std::vector<double> h_;
    matrix<double> *S_;

    void gen_trimat(std::vector<double> y_func, int n);
    void gaussElim(matrix<double> a,std::vector<double> &x);
    void Calc_Coeff(std::vector<double> y);
};

#endif