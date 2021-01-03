//Solvers Implementation
#include <iostream>
#include <cmath>
#include <iomanip>
#include "polynomial_regression.cpp"
#include "gauss_elimination.h"
#include "multlivariable_linear_regression.cpp"
#include"read_csv.h"
#include "converters.h"
#include <string>
#include <map>




int main()
{


//==================================================================================================================//
//Ploynomial Regression //

std:: cout << "Start Polynomial Regresion " << std::endl;
std::cout << "==============================================" << std::endl;
std::cout << "==============================================" << std::endl;
double x_input[10][1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
double y_input[10][1] = {2.7539933, 1.89480996, 5.66772085, 8.50870948, 10.9265186, 13.53008555, 11.83534674, 17.6239973, 21.18380426, 23.93961935 };


const int rows_x = sizeof(x_input) / sizeof(x_input[0]);
const int cols_x = sizeof(x_input[0])/sizeof(x_input[0][0]);
std::cout << "Vector x Shape : " << std::endl;
std::cout << "rows : " << rows_x << " Columns : " << cols_x << std::endl;

const int rows_y = sizeof(y_input) / sizeof(y_input[0]);
const int cols_y = sizeof(y_input[0])/sizeof(y_input[0][0]);
std::cout << "Vector y Shape : " << std::endl;
std::cout << "rows : " << rows_y << " Columns : " << cols_y << std::endl;

int m = 2;

//Set no of rows (no of data points)

PolynomialRegression poly_reg;
poly_reg.setRows(rows_x);
std::string solver_name = "GuassElimination";
std::cout << "==============================================================" << std::endl;
std::cout << "Dataset 1" << std::endl;
std::cout << "==============================================================" << std::endl;
poly_reg.fit((double*)(x_input), (double*)(y_input), m, solver_name);

double x_test[10][1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
std::cout << "Predicted and Actual Vectors for Polynomial Regression using Gauss Elimination" << std::endl;
std::vector<double> predictions_poly_elimination;
for(int i = 0; i < rows_x; i++){
        double predicted_val = poly_reg.predict(x_test[i][0], solver_name);
        predictions_poly_elimination.push_back(predicted_val);

}

//Print predicted and actual
std::cout << "Predicted" << "		" << "Actual" << std::endl; 
for(int i = 0; i < rows_x; i++){
	std::cout << predictions_poly_elimination[i] << "                   " << y_input[i][0] << std::endl; 
}

std::cout << "==============================================" << std::endl;
solver_name = "GaussSeidel";
poly_reg.fit((double*)(x_input), (double*)(y_input), m, solver_name);

std::cout << "Predicted and Actual Vectors for Polynomial Regression using Gauss Seidel" << std::endl;
std::vector<double> predictions_poly_seidel;
for(int i = 0; i < rows_x; i++){
        double predicted_val = poly_reg.predict(x_test[i][0], solver_name);
        predictions_poly_seidel.push_back(predicted_val);

}

//Print predicted and actual
std::cout << "Predicted" << "		" << "Actual" << std::endl; 
for(int i = 0; i < rows_x; i++){
	std::cout << predictions_poly_seidel[i] << "                   " << y_input[i][0] << std::endl; 
}
//======================================================================================
std::cout << "==============================================================" << std::endl;
std::cout << "Dataset 2" << std::endl;
std::cout << "==============================================================" << std::endl;
double y1_input[10][1] = {-0.50466197, -6.07975077, 5.92268482, 4.9561807, 1.55448633, 14.14332855, 22.37781082, 36.10134947, 56.35029787, 89.54115176  };
solver_name = "GaussSeidel";
poly_reg.fit((double*)(x_input), (double*)(y1_input), m, solver_name);

std::cout << "Predicted and Actual Vectors for Polynomial Regression using Gauss Seidel" << std::endl;
std::vector<double> predictions_poly_elimination_2;
for(int i = 0; i < rows_x; i++){
        double predicted_val = poly_reg.predict(x_test[i][0], solver_name);
        predictions_poly_elimination_2.push_back(predicted_val);

}

//Print predicted and actual
std::cout << "Predicted" << "		" << "Actual" << std::endl; 
for(int i = 0; i < rows_x; i++){
	std::cout << predictions_poly_elimination_2[i] << "                   " << y1_input[i][0] << std::endl; 

}


std::cout << "End Polynomial Regression" << std::endl;
std::cout << "==============================================" << std::endl;
std::cout << "==============================================" << std::endl;
//==================================================================================================================//
//Multivariable Linear Regression //


std::cout << "Start Multivariable Regression " << std::endl;

std::string filename = "/home/hesham/numerical_methods/clone/SC_Solver/datasets/Housing.csv";
std::vector<std::vector<std::string>> array = read_csv(filename);
int rows_size_house = array.size();
int cols_size_features = 4 ;
double x_mlrg_all[rows_size_house][cols_size_features];

//Matrix Housing Features:
for(int i = 1; i < array.size(); i++)
{
    for(int j = 2; j < 6; j++)
    {
	x_mlrg_all[i-1][j-2] = std::stod(array[i][j]);
	//std::cout << x_mlrg_all[i-1][j-2] << "  ";
	
	
    }
    //std::cout << std::endl;
}

double y_mlrg[rows_size_house][1] ;

//Matrix Housing Labels: 

for(int i = 1; i < rows_size_house; i++)
{
        y_mlrg[i-1][0] = std::stod(array[i][1]);
        //std::cout << y_mlrg[i-1][0] <<  std::endl;
}


std::cout << "==================================================================" << std::endl;
std::cout << "Start Selecting two features processing for Matrix Housing dataset : " << std::endl;
int features = 2;
//To remove additional count coming from header
rows_size_house = rows_size_house - 1;

double x_mlrg[rows_size_house][features];
multivariableLinearRegression multiLinearReg;
multiLinearReg.setRows(rows_size_house);
multiLinearReg.setCols(features);



std::vector<double> y_mlrg_vec;
for(int i = 0; i < rows_size_house; i++){
        y_mlrg_vec.push_back(y_mlrg[i][0]);
        }

std::map<std::string, double> gauss_elimination_errors;
std::map<std::string, double> gauss_seidel_errors;
int ms = 0;
int ks = 0;
for(ks = 0; ks < 4; ks++){
        for( ms = 0; ms < 4 ; ms++){
                if(ms == ks){
                        continue;
                }
                if (ms <= ks-1){
                        continue;
                }
				std::vector<int> selector;
				selector.push_back(ks);
				selector.push_back(ms);
				for(int i = 0; i < rows_size_house; i++)
				{
					for(int j = 0; j < 2; j++)
					{
						x_mlrg[i][j] = x_mlrg_all[i][selector[j]];
						//std::cout << x_mlrg_all[i][selector[j]] << "  ";


					}
					//std::cout << std::endl;

				}


				std::string solver_name = "GuassElimination";
				multiLinearReg.fit((double*)(x_mlrg), (double*)(y_mlrg), solver_name);

				std::vector<double> predictions_multi_gauss_elimination;
				for(int i = 0; i < rows_size_house; i++){
						double predicted_val_elimination = multiLinearReg.predict(x_mlrg[i][0], x_mlrg[i][1], solver_name);
						predictions_multi_gauss_elimination.push_back(predicted_val_elimination);

				}

				int feature_selected_1 = ks;
				int feature_selected_2 = ms;
				
				int sample = 20;
				std::cout << "==================================================================" << std::endl;
				std::cout << "Features Selected: " << feature_selected_1 << " & " << feature_selected_2 << std::endl; 
				std::cout << "==================================================================" << std::endl;
				std::cout << "Predicted and Actual First 20 Samples Vectors of Multivarible Linear Regression using Gauss Elimination Solver" << std::endl;
				std::cout << "Predicted" << "                   " << "Actual" << std::endl;
				for(int i = 0; i < sample; i++){
        				std::cout << predictions_multi_gauss_elimination[i] << "                   " << y_mlrg[i][0] << std::endl;
				}



				std::cout << "Mean Squared Error of Multivarible Linear Regression  " << std::endl;
				double mse_gauss_elimination = multiLinearReg.meanSquaredError(y_mlrg_vec, predictions_multi_gauss_elimination);
				std::cout << " Gauss Elimination Mean Squared Error " <<  feature_selected_1 << "," << feature_selected_2 << ":  " << mse_gauss_elimination << std::endl;

				std::string feature_id =  std::to_string(feature_selected_1) + " & " + std::to_string(feature_selected_2);
				gauss_elimination_errors[feature_id] = mse_gauss_elimination;

				std::cout << "==================================================================" << std::endl;

				solver_name = "GaussSeidel";
				multiLinearReg.fit((double*)(x_mlrg), (double*)(y_mlrg), solver_name);

                                std::vector<double> predictions_multi_gauss_seidel;
                                for(int i = 0; i < rows_size_house; i++){
                                                double predicted_val_seidel = multiLinearReg.predict(x_mlrg[i][0], x_mlrg[i][1], solver_name);
                                                predictions_multi_gauss_seidel.push_back(predicted_val_seidel);

                                }
				std::cout << "Predicted and Actual First 20 Samples Vectors of Multivarible Linear Regression using Gauss Seidel  Solver" << std::endl;
				std::cout << "Predicted" << "                   " << "Actual" << std::endl;
				for(int i = 0; i < sample; i++){
        				std::cout <<  predictions_multi_gauss_seidel[i] << "                   " << y_mlrg[i][0] << std::endl;
				}
				
				double mse_gauss_seidel = multiLinearReg.meanSquaredError(y_mlrg_vec, predictions_multi_gauss_elimination);
                                std::cout << " Gauss Seidel Mean Squared Error  " <<  feature_selected_1 << ", " << feature_selected_2 << ":  " << mse_gauss_seidel << std::endl;

				gauss_seidel_errors[feature_id] = mse_gauss_seidel;
                                std::cout << "==================================================================" << std::endl;





        }
}

std::cout << "Finshed Selecting two features processing for Matrix Housing dataset : " << std::endl;

double min_gauss_elimination = 10000000000;
std::string features_min_gauss_elimination = "";
std::cout << "No of calculated mean squared error values from gauss elimination: " << gauss_elimination_errors.size() << std::endl;
for(const auto& iter: gauss_elimination_errors){
        std::cout << iter.first << "  " << iter.second << std::endl;
        if (iter.second < min_gauss_elimination){
                min_gauss_elimination = iter.second;
		features_min_gauss_elimination = iter.first;
        }
}
std::cout << "Min Squared Error using Gauss Elimination: " << min_gauss_elimination << " using features " << features_min_gauss_elimination << std::endl;


double min_gauss_seidel = 10000000000;
std::string features_min_gauss_seidel = "";
std::cout << "No of calculated mean squared error values from gauss seidel: " << gauss_seidel_errors.size() << std::endl;
for(const auto& iter: gauss_seidel_errors){
	std::cout << iter.first << "  " << iter.second << std::endl;
	if (iter.second < min_gauss_seidel){
		min_gauss_seidel = iter.second;
		features_min_gauss_seidel = iter.first;
	}
}	
std::cout << "Min Squared Error using Gauss Seidel: " << min_gauss_seidel << " using features: "<< features_min_gauss_seidel << std::endl;

std::cout << "==================================================================" << std::endl;
std::cout << std::endl;

std::cout << "Check Golobal minimum between gauss elimination and gauss seidel" << std::endl;
if(min_gauss_elimination < min_gauss_elimination){
	std::cout << "gaus elimination achieved minimum with feautres: " << features_min_gauss_elimination << " and value: " << min_gauss_elimination << std::endl;
}else{

	std::cout << "gaus seidel achieved minimum with feautres: " << features_min_gauss_seidel << " and value: " << min_gauss_seidel << std::endl;
}

std::cout << "==================================================================" << std::endl;
std::cout  << std::endl;
std::cout << "End Multivariable Regression " << std::endl;

return 0;

}


