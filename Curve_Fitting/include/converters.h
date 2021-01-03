#ifndef CONVERTERS_H_ 
#define CONVERTERS_H_
#include <vector>
#include <iostream>


std::vector<double> arrayToVector(double* array, int size);

std::vector<std::vector<double>> arrayToMatrix(double* array, int rows, int cols);

double* vectorToArray(std::vector<double> vec);

#endif

