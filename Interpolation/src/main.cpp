#include<iostream>
#include"matrix.h"
#include "newtonspolynomial.tpp"
#include "Cubicspline_interpolation.h"
#include "read_csv.h"

int main()
{
    std::string data1_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/datasets/3_dataset_1.csv";
    std::string data2_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/datasets/3_dataset_2.csv";
    //std::string output_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/output.csv";
    std::vector<std::vector<std::string>> data1_str = read_csv(data1_path);
    std::vector<std::vector<std::string>> data2_str = read_csv(data2_path);
    std::vector<std::vector<double>> data1;
    std::vector<std::vector<double>> data2;
    std::vector<double> data1_x;
	std::vector<double> data1_y;
	std::vector<double> data2_x;
	std::vector<double> data2_y;
    for(int i = 1;i<data1_str.size();i++)
    {
        data1_x.push_back(std::stod(data1_str[i][0]));
		data1_y.push_back(std::stod(data1_str[i][1]));
        std::vector<double> temp;
        for(int j = 0;j<2;j++)
        {
            temp.push_back(std::stod(data1_str[i][j]));
        }
        data1.push_back(temp);
    }
    for(int i = 1;i<data2_str.size();i++)
    {
        data2_x.push_back(std::stod(data2_str[i][0]));
		data2_y.push_back(std::stod(data2_str[i][1]));
        std::vector<double> temp;
        for(int j = 0;j<2;j++)
        {
            temp.push_back(std::stod(data2_str[i][j]));
        }
        data2.push_back(temp);
    }
    matrix<double> mat1(data1);
    matrix<double> mat2(data2);
    vector<double> x1_double;
    vector<double> x1_4times;
    vector<double> x2_double;
    vector<double> x2_4times;
    vector<double> x1 = mat1.column(0);
    vector<double> x2 = mat2.column(0);
    
    for(int i = 0;i<x1.size()-1;i++)
    {
        x1_double.push_back(x1[i]);
        x1_double.push_back(((x1[i]+x1[i+1])/2));
        if(i == x1.size()-2)
        {
            x1_double.push_back(x1[x1.size()-1]);    
        }
    }

    for(int i = 0;i<x1_double.size()-1;i++)
    {
        x1_4times.push_back(x1_double[i]);
        x1_4times.push_back(((x1_double[i]+x1_double[i+1])/2));
        if(i == x1_double.size()-2)
        {
            x1_4times.push_back(x1_double[x1_double.size()-1]);    
        }
    }
    //x1_4times.print();
    for(int i = 0;i<x2.size()-1;i++)
    {
        x2_double.push_back(x2[i]);
        x2_double.push_back(((x2[i]+x2[i+1])/2));
        if(i == x2.size()-2)
        {
            x2_double.push_back(x2[x2.size()-1]);    
        }
    }
    for(int i = 0;i<x2_double.size()-1;i++)
    {
        x2_4times.push_back(x2_double[i]);
        x2_4times.push_back(((x2_double[i]+x2_double[i+1])/2));
        if(i == x2_double.size()-2)
        {
            x2_4times.push_back(x2_double[x2_double.size()-1]);    
        }
    }



    std::vector<std::vector<double>> double_data1;
    std::vector<std::vector<double>> ftimes_data1;
    newtoninterpolation<double> interpolator;
    interpolator.fit(mat1.column(0),mat1.column(1));
    for(int i = 0;i<x1_double.size();i++)
    {
        std::vector<double> temp;
        temp.push_back(x1_double[i]);
        double result = interpolator.interpolate(x1_double[i]);
        temp.push_back(result);
        double_data1.push_back(temp);
    }
    for(int i = 0;i<x1_4times.size();i++)
    {
        std::vector<double> temp;
        temp.push_back(x1_4times[i]);
        double result = interpolator.interpolate(x1_4times[i]);
        temp.push_back(result);
        ftimes_data1.push_back(temp);
    }
    std::string double_data1_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data1_double_pointsNP.csv";
    std::string ftimes_data1_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data1_4times_pointsNP.csv";
    write_csv(double_data1_path,double_data1);
    write_csv(ftimes_data1_path,ftimes_data1);


    std::vector<std::vector<double>> double_data2;
    std::vector<std::vector<double>> ftimes_data2;
    newtoninterpolation<double> interpolator2;
    interpolator2.fit(mat2.column(0),mat2.column(1));
    for(int i = 0;i<x2_double.size();i++)
    {
        std::vector<double> temp;
        temp.push_back(x2_double[i]);
        double result = interpolator2.interpolate(x2_double[i]);
        temp.push_back(result);
        double_data2.push_back(temp);
    }
    for(int i = 0;i<x2_4times.size();i++)
    {
        std::vector<double> temp;
        temp.push_back(x2_4times[i]);
        double result = interpolator2.interpolate(x2_4times[i]);
        temp.push_back(result);
        ftimes_data2.push_back(temp);
    }
    std::string double_data2_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data2_double_pointsNP.csv";
    std::string ftimes_data2_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data2_4times_pointsNP.csv";
    write_csv(double_data2_path,double_data2);
    write_csv(ftimes_data2_path,ftimes_data2);
    
    /************************************************************************************************************/
    /**************************************CUBIC SPLINE INTERPOLATION***************************************************/
    /************************************************************************************************************/
	Cubicspline_interpolation interpolator;
	interpolator.fit(data1_x, data1_y);
	double_data1.clear();
	ftimes_data1.clear();

	for (int i = 0; i<x1_double.size(); i++)
	{
		std::vector<double> temp;
		temp.push_back(x1_double[i]);
		double result = interpolator.interpolate(x1_double[i]);
		temp.push_back(result);
		double_data1.push_back(temp);
    }
	for (int i = 0; i<x1_4times.size(); i++)
	{
		std::vector<double> temp;
		temp.push_back(x1_4times[i]);
		double result = interpolator.interpolate(x1_4times[i]);
		temp.push_back(result);
		ftimes_data1.push_back(temp);
	}
    std::string double_data2_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data1_cubicspline_double_pointsNP.csv";
    std::string ftimes_data2_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data1_cubicspline_4times_pointsNP.csv";
	write_csv(double_data1_path, double_data1);
	write_csv(ftimes_data1_path, ftimes_data1);

    double_data2.clear();
	ftimes_data2.clear();
	Cubicspline_interpolation interpolator2;
	interpolator2.fit(data2_x, data2_y);
        for(int i = 0;i<x2_double.size();i++)
    {
        std::vector<double> temp;
        temp.push_back(x2_double[i]);
        double result = interpolator2.interpolate(x2_double[i]);
        temp.push_back(result);
        double_data2.push_back(temp);
    }
    for(int i = 0;i<x2_4times.size();i++)
    {
        std::vector<double> temp;
        temp.push_back(x2_4times[i]);
        double result = interpolator2.interpolate(x2_4times[i]);
        temp.push_back(result);
        ftimes_data2.push_back(temp);
    }
    std::string double_data2_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data2_cubicspline_double_pointsNP.csv";
    std::string ftimes_data2_path = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Interpolation/output/data2_cubicspline_4times_pointsNP.csv";
    write_csv(double_data2_path,double_data2);
    write_csv(ftimes_data2_path,ftimes_data2);
    
    return 0;
}