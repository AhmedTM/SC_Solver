#include <stdio.h>
#include <dirent.h>
#include <string>
#include <filesystem>
#include <iomanip>
#include "converters.h"

std::vector<double> arrayToVector(double* array, int size){
	 std::vector<double> vec;
         for(int i = 0; i < size ; i++){
		 vec.push_back(array[i]);
                        }
	return vec;

}

std::vector<std::vector<double>> arrayToMatrix(double* array, int rows, int cols){
	std::vector<std::vector<double>> matrix;
	 for(int i = 0; i < rows; i++){
		 std::vector<double> vec;
		 for(int j = 0; j < cols; j++){
			 vec.push_back( *(array+i*cols+j) );
                                }
		 matrix.push_back(vec);
                        }
	 return matrix;

}
/*
double * vectorToArray(std::vector<double> vec){
	int size = vec.size();
	double arr[size];
	for(int i = 0; i < size; i++){
		arr[i] = vec[i];
	}

	return arr;
}
*/
/*
double** matrixToArray(std::vector<std::vector<double> matrix){	
	int rows = matrix.size();
	int cols = matrix[0].size();
	for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
	       	}
                        }
         return matrix;
}
*/

