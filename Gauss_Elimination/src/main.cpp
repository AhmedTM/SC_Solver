#include"matrix.h"
#include"vector.h"
#include "gauss_elimination.h"
#include"read_csv.h"


int main(int argc, char *argv[])
{
    std::string filename = "/home/ahmedtarek/Scientific_Computing/SC_Solver/Gauss_Elimination/src/Housing.csv";
    std::vector<std::vector<std::string>> array = read_csv(filename);
    std::vector<std::vector<double>> matrix_data;
    for(int i = 1;i<array.size();i++)
    {
        std::vector<double> temp;
        for(int j = 1;j<6;j++)
        {
            temp.push_back(std::stod(array[i][j]));
        }
        matrix_data.push_back(temp);
    }
    matrix<double> mat(matrix_data);
    //mat.print();
    std::vector<std::vector<double>> A_data = {{2,1,-1},{1,4,3},{-1,2,7}};
    std::vector<double> b_data = {0,14,30};
    std::vector<double> a_data = {0,0,0};
    std::vector<double> x_data = {0,0,0};

    Solvers::gaussSPP<double> solver;
    Solvers::gaussSeidel<double> gssolver;
    matrix<double> A(A_data);
    vector<double> b(b_data);
    vector<double> a(a_data);
    vector<double> x_1(x_data);
    A.print();
    solver.Init(A,b,a);
    gssolver.Init(A,b,x_1,100,0.0000001);
    vector<double> solution = gssolver.Solve();
    solution.print();

    bool valid_solution = solver.valid_solution;
    if(valid_solution == true)
    {
        std::cout<<"The system is well conditioned\n"<<std::endl;
    }
    else
    {
        std::cout<<"The system is ill conditioned\n"<<std::endl;
    }
    vector<double> result = solver.Solve();
    std::cout<<"Solution"<<std::endl;
    result.print();
    
}