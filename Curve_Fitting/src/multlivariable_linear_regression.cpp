//Mutltivaribale Linear Regression Implementation
#include <iostream>
#include  <cmath>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <filesystem>
#include <iomanip>
#include "converters.h"
#include "gauss_elimination.h"
#include "linear_algerbra_ops.h"


class multivariableLinearRegression {
	//Initalization for loop varibles
        int i = 0;
        int j = 0;
        int k = 0;
	int l = 0;
	//no of rows (data points)
	int n = 0;
	//no of cloumns (features)
        int m = 0;
	//vectors that will hold predictions
	vector<double> solution_gauss_elimination; 	
	vector<double> solution_gauss_seidel;
	//Initalization for max variables
	double y_max = 0;
	double x1_max = 0;
	double x2_max = 0;
	std::string solver_name = "GuassElimination";
	bool condition;

	//Setters and getters methods for important parameters
	private:
		double getMax(double* arr){
			double max = 0;
			for(i = 0; i < n ; i++){
				if((*(arr+i)) > max){
					max = *(arr+i);
				}
			}

			return max;
		}
        public:
                 // Setter for rows
                void setRows(int rows) {
                         n = rows;
                }
                    // Setter for columns
                void setCols(int cols) {
                         m = cols;
                }


		//
	public:
		bool fit(double* x, double* y, std::string solv_name){
			 std::cout.precision(4);
                         std::cout.setf(std::ios::fixed);

			  
			  double x_features[n][m];
			  x1_max = 0;
			  x2_max = 0;
                          for(i = 0; i < n; i++){
				  for(j = 0; j < m ; j++){
                                	x_features[i][j] = *(x+i*m+j);
					
				  }
				  if(x_features[i][0] > x1_max){
					  x1_max = x_features[i][0];
				  }
				  if(x_features[i][1] > x2_max){
					  x2_max = x_features[i][1];
				  }
                        }

			//Normalize features
                        for(i = 0; i < n; i++){
                                	x_features[i][0] = x_features[i][0] / x1_max;
                                	x_features[i][1] = x_features[i][1] / x2_max;
					
			}

			int rows_x = sizeof(x_features) / sizeof(x_features[0]);
			int cols_x = sizeof(x_features[0])/sizeof(x_features[0][0]);
			//std::cout << "Matrix X features inside: " << std::endl;
			//std::cout << "rows : " << rows_x << " Columns : " << cols_x << std::endl;

			std::cout << "============================================" << std::endl;
			//Get y_ prices vector
                        double y_prices[n][1];
				
                        for(i = 0; i < n ; i++){
                                y_prices[i][0] = *(y+i)  ;
                        }
			
			// Normalize label (y actual value)
				
			y_max = getMax((double*)y_prices);
                        for(i = 0; i < n ; i++){
                                y_prices[i][0] = (*(y+i)) / y_max  ;
				//std::cout << y_prices[i][0] << std::endl;
                        }
			
		
			//Build Vector that has summation
			std::cout << "=============================================" << std::endl;
			double X_Matrix[m+1][m+1];
			double sum_x1 = 0;
			double sum_x2 = 0;
			double sum_x1_square = 0;
			double sum_x1_mul_x2 = 0;
			double sum_x2_square = 0;

                        for(j = 0; j < n; j++){
                        	sum_x1 = sum_x1 + x_features[j][0];
                        	sum_x2 = sum_x2 + x_features[j][1];
				sum_x1_square = sum_x1_square + pow(x_features[j][0],2);
				sum_x1_mul_x2 = sum_x1_mul_x2 + (x_features[j][0] * x_features[j][1]);
				sum_x2_square = sum_x2_square + pow(x_features[j][1],2);
				
			}
			
			X_Matrix[0][0]  = n;
			X_Matrix[0][1]  = sum_x1;
			X_Matrix[0][2]  = sum_x2;
			X_Matrix[1][0]  = sum_x1;
			X_Matrix[1][1]  = sum_x1_square;
			X_Matrix[1][2]  = sum_x1_mul_x2;
			X_Matrix[2][0]  = sum_x2;
			X_Matrix[2][1]  = sum_x1_mul_x2;
			X_Matrix[2][2]  = sum_x2_square;


			std::cout << "X Matrix Multivariable Linear Regression" << std::endl;
                        for( i = 0; i < m + 1; i++){
                                for(j = 0; j <  m + 1; j++){
                                        std::cout <<  X_Matrix[i][j] << "     ";
                                }
                                std::cout << std::endl;
                        }


			double Y_Matrix[m+1];
                        double sum_y = 0;
		        double sum_y_x1 = 0;
			double sum_y_x2 = 0;

			 for(j = 0; j < n; j++){
				 sum_y = sum_y + y_prices[j][0];
				 sum_y_x1 = sum_y_x1 + (y_prices[j][0] * x_features[j][0]);
				 sum_y_x2 = sum_y_x2 + (y_prices[j][0] * x_features[j][1]); 
                        }

			Y_Matrix[0] = sum_y;
			Y_Matrix[1] = sum_y_x1;
			Y_Matrix[2] = sum_y_x2;


			 std::vector<std::vector<double>> X_Mat;
                         X_Mat = arrayToMatrix((double*)(X_Matrix), m+1 , m+1);

                         //std::cout << "=============================================" << std::endl;
                         
			 //  Array to Matrix Conversion 
                          for( i = 0; i < X_Mat.size(); i++){
                                for(j = 0; j < X_Mat[i].size(); j++){
                                        //std::cout <<  X_Mat[i][j] << "     ";
                                }
                                //std::cout << std::endl;
                          }


                        //Convert Y 1-D array to vector

                        std::vector<double> y_vec;
                        std::cout << "=============================================" << std::endl;
                        
			// Array to Vector Conversion

                        y_vec = arrayToVector( (double*)(Y_Matrix), m+1);

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
                                std::cout << "System is well condition" << std::endl;
                        }else{

                                std::cout << "System is ill condition" << std::endl;
                        }


                        solution_gauss_elimination= solver.Solve();
                        solution_gauss_elimination.print();
			}
			else if ((solver_name.compare("GaussSeidel")) == 0){

                        //Calling Gauss Siedel Solver
                        std::cout << "=============================================" << std::endl;
                        std::cout << "=============================================" << std::endl;
                        std::cout << "Calling Gauss Seidel Solver" << std::endl;
                        std::cout << "=============================================" << std::endl;
                        std::cout << "=============================================" << std::endl;


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

		double predict(double x1, double x2, std::string solv_name){

                        double predicted_val = 0;
                        x1 = x1 / x1_max;
                        x2 = x2 / x2_max;

                        std::string solver_name = solv_name;
                        //Predicting using Gauss Elimination solver
                        if((solver_name.compare("GuassElimination")) == 0){

                                predicted_val = solution_gauss_elimination[0] + (solution_gauss_elimination[1] * x1) + (solution_gauss_elimination[2] * x2) ;
                        }
                        //Predicting using  Gauss Siedel Solver
                        else if ((solver_name.compare("GaussSeidel")) == 0){
                                predicted_val = solution_gauss_seidel[0] + (solution_gauss_seidel[1] * x1) + (solution_gauss_seidel[2] * x2) ;
                        }

                        else
                        {
                                std::cout << "No valid solver has been entered !" << std::endl;
                        }


                        return predicted_val * y_max;
                }



		double meanSquaredError(std::vector<double> y_actual, std::vector<double> y_predicted){
			double mse = 0;
        		double sum = 0;
        		double err = 0;
        		int data_points = y_actual.size();
        		for(int i = 0; i < data_points; i++){
                		err = y_actual[i] - y_predicted[i];
                		sum += err * err;
			}	
       			 mse = sum / data_points;
        		return mse;
		}



};

