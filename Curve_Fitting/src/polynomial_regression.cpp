//Polynomial Regression Implementation
#ifndef HEADER_H_ 
#define HEADER_H_
#include <iostream>
#include  <cmath>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <filesystem>
#include <iomanip>
#include <vector>
#include "converters.h"
#include "gauss_elimination.h"


class PolynomialRegression {
	//Initalization for loop varibles
	int i = 0;
	int j = 0;
	int k = 0;
	//Polynomial order
	int m = 0;

	//Number of data points
	int n = 0;
	bool flag = false;
	int poly_order = 0;
	double* a_coeff;
	vector<double> solution_gauss_elimination;
        vector<double> solution_gauss_seidel;
	std::string solver_name = "GuassElimination";
	bool condition;


			
        //Setters and getters methods for important parameters
        public:
                 // Setter for rows
                void setRows(int rows) {
                         n = rows;
                
		}
		
		//This function to round values
		double round(double var){
    			double value = (int)(var * 100 + .5);
    			return (double)value / 100;
			}

	public:
		//fit method to solve system of equations using polynomial regression
		bool fit(double* x_input, double* y_input,int poly_order, std::string solv_name){
			std::cout.precision(4);
			std::cout.setf(std::ios::fixed);

			m = poly_order;

                        double x_vals[n][1];
			  for(i = 0; i < n; i++){
                                x_vals[i][0] = *(x_input+i);
                        }
			
			std::cout << "=============================================" << std::endl;
		        double y_vals[n][1];
			  for(i = 0; i < n; i++){
                                y_vals[i][0] = *(y_input+i);
                        }


			int rows_x_vals = sizeof(x_vals) / sizeof(x_vals[0]);
			int cols_x_vals = sizeof(x_vals[0])/sizeof(x_vals[0][0]);

			int rows_y_vals = sizeof(y_vals) / sizeof(y_vals[0]);
			int cols_y_vals = sizeof(y_vals[0])/sizeof(y_vals[0][0]);


			if(n < m + 1){
				std::cout << "Regression is impossible because don't have enough data points to solve given degree of polynomial" << std::endl;
				std::cout << "the process will be terminated!" <<std::endl;
				return flag;
			}

			//Build Vector that has summation
			//example x = [n, sum(x), sum(x**2), ........., sum(x**2m+1)
			double x[2*m+1];
			for(i = 0; i < 2*m + 1; i++){
				x[i] = 0;
				for(j = 0; j < n; j++){
					x[i] = x[i] + pow(x_vals[j][0],i);
				}
			}

			std::cout << "Sum Vecctor:" << std::endl;
                        for( i = 0; i < 2*m + 1; i++){
                                        std::cout <<  x[i] << "     ";
                                std::cout << std::endl;
                        }

			//Coefficient vector
			double a[m+1];

			//Build Matrix that normal equations
			double X_Matrix[m+1][m+1];  
         		
			for(i = 0; i <= m; i++){
				for(j = 0; j <= m; j++){
					X_Matrix[i][j] = (x[i+j]); 
				}
			}

			std::cout << "X Matrix Polynomial Regression:" << std::endl;
                        for( i = 0; i <= m; i++){
                                for(j = 0; j <= m; j++){
                                        std::cout <<  X_Matrix[i][j] << "     ";
                                }
                                std::cout << std::endl;
                        }

			//Build Y Vector
			double y[m+1][1];
			for(i = 0; i < m+1 ; i++){
				y[i][0] = 0;
				for(j = 0; j <  n; j++){
					y[i][0] = y[i][0] + (pow(x_vals[j][0],i) * y_vals[j][0]);
				}			
			}

			std::cout << "Y Vecctor Polynomial Regression:" << std::endl;
                        for( i = 0; i < m+1 ; i++){
                                        std::cout <<  y[i][0] << "     ";
                                std::cout << std::endl;
                        }
			
			int rows_x_matix = sizeof(X_Matrix) / sizeof(X_Matrix[0]);
                        int cols_x_matrix = sizeof(X_Matrix[0])/sizeof(X_Matrix[0][0]);

                        int rows_y = sizeof(y) / sizeof(y[0]);
                        int cols_y = sizeof(y[0])/sizeof(y[0][0]);

			
			//Convert A rray to Matrix

			 std::vector<std::vector<double>> X_Mat;
			 X_Mat = arrayToMatrix((double*)(X_Matrix), rows_x_matix, cols_x_matrix);
			  
			 std::cout << "=============================================" << std::endl;
			 std::cout << " Array to Matrix Conversion    " << std::endl;
			  for( i = 0; i < X_Mat.size(); i++){
                 		for(j = 0; j < X_Mat[i].size(); j++){
                         		std::cout <<  X_Mat[i][j] << "     ";
                                }
				std::cout << std::endl;
			  }

			 std::cout << "=============================================" << std::endl;

			//Convert Y 1-D array to vector

			std::vector<double> y_vec;
			//std::cout << "=============================================" << std::endl;
			//std::cout << " Array to Vector Conversion    " << std::endl;

			y_vec = arrayToVector( (double*)(y), m+1);
			//for( i = 0; i < y_vec.size()  ; i++){
                        //                std::cout <<  y_vec[i] << "     ";
                        //        std::cout << std::endl;
                       // }


			//Calling Gauss Elimination Solver
			std::vector<double> x_data = {0,0,0};
			matrix<double> A(X_Mat);
    			vector<double> b(y_vec);
    			vector<double> x_vec(x_data);

			//A.print();
			//b.print();
			//x_vec.print();
			
			solver_name = solv_name;		
			if((solver_name.compare("GuassElimination")) == 0){
			std::cout << "=============================================" << std::endl;
			std::cout << "=============================================" << std::endl;
		        std::cout << "Calling Gauss Elimination Solver" << std::endl;
			std::cout << "=============================================" << std::endl;
			std::cout << "=============================================" << std::endl;
			Solvers::gaussSPP<double> solver;

			solver.Init(A, b, x_vec);

			condition = solver.valid_solution;
			if (condition){
				std::cout << "System is well condition Polynomial Regression" << std::endl;
			}else{

				std::cout << "System is ill condition polynomial regression" << std::endl;
			}

			std::cout << "=============================================" << std::endl;

			std::cout << "Gauss elimination solution for plolynomial regression" << std::endl;
			solution_gauss_elimination = solver.Solve();
			solution_gauss_elimination.print();

			}
			else if ((solver_name.compare("GaussSeidel")) == 0){	
			//Calling Gauss Siedel Solver
			std::cout << "=============================================" << std::endl;
			std::cout << "=============================================" << std::endl;
		        std::cout << "Calling Gauss Seidel Solver" << std::endl;
			std::cout << "=============================================" << std::endl;
			std::cout << "=============================================" << std::endl;


			std::cout << "Gauss Seidel solution for plolynomial regression" << std::endl;
			Solvers::gaussSeidel<double> solverSiedel;
			int iters = 500;
			double eps = 0.00001;
			solverSiedel.Init(A, b, x_vec, iters, eps);


			solution_gauss_seidel = solverSiedel.Solve();
			solution_gauss_seidel.print();
			}
			else
			{
				std::cout << "No valid solver has been entered !" << std::endl;
			}



			return condition;
		
		
		}

		
		double predict(double x_test, std::string solv_name){

                        double predicted_val = 0;
			std::string solver_name = solv_name;
			//Predicting using Gauss Elimination solver
			if((solver_name.compare("GuassElimination")) == 0){

		       		predicted_val = solution_gauss_elimination[0] + (solution_gauss_elimination[1] * x_test) + (solution_gauss_elimination[2] * pow(x_test,2)) ; 	
			}
			//Predicting using  Gauss Siedel Solver
			else if ((solver_name.compare("GaussSeidel")) == 0){	
		       		predicted_val = solution_gauss_seidel[0] + (solution_gauss_seidel[1] * x_test) + (solution_gauss_seidel[2] * pow(x_test,2)) ; 	
			}

			else
                        {
                                std::cout << "No valid solver has been entered !" << std::endl;
                        }


			return predicted_val;
		}	




};

#endif

