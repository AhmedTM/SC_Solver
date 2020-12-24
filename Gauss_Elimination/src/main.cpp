#include"matrix.h"
#include"vector.h"
#include "gauss_elimination.h"


int main(int argc, char *argv[])
{
    int size = 11;
    int rows = 11,cols = 11;
    double x = 1;
    std::vector<std::vector<double>> A_data = {{2,1,-1},{1,4,3},{-1,2,7}};
    std::vector<double> b_data = {0,14,30};
    std::vector<double> a_data = {1,1,1};

    //std::cout<<"hello"<<std::endl;
    Solvers::LSSolver<double> solver;
    //std::cout<<"hello"<<std::endl;
    matrix<double> mat(rows,cols);
    //std::cout<<"hell"<<std::endl;
    matrix<double> mat2(rows,cols);
    //std::cout<<"hell"<<std::endl;
    matrix<double> A(A_data);
    //std::cout<<"hel"<<std::endl;
    vector<double> b(b_data);
    //std::cout<<b.size()<<std::endl;
    vector<double> a(a_data);
    for(int i =0;i<rows;i++)
    {
        //std::cout<<i<<std::endl;
        for(int j=0;j<cols;j++)
        {
            //std::cout<<j<<std::endl;
            mat2(i,j) = x;
            mat(i,j) = x;
            x++; 
        }
        //b.push_back(x);
        //a.push_back(1);
        //std::cout<<b[i]<<std::endl;
    }
    //A = mat+mat2;
    //double y = mat2(0,0);
    //y = 5;
    //std::cout<<y<<" x test"<<std::endl;
    //std::cout<<mat2(0,0)<<" mat2 test"<<std::endl;
    //mat.print();
    //mat2.print();
    A.print();
    //b.print();
    //a.print();
    solver.Init(A,b,a,1);
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
    //std::vector<double> col={1,2,3,4,5,6,7,8,9,10};
    //A.add_column(col);
    //A.print();
    //std::vector<double> row={1,2,3,4,5,6,7,8,9,10,11};
    //A.add_row(row);
    //A.print();
    //vector<double> row1(row);
    //A[1] = (A.row(1)+A.row(3)).to_vector();
    //A.print();

    //std::cout << "h"<<std::endl;
    //vector<double> a(size);
    //std::cout << "e"<<std::endl;
    //vector<double> b(size);
    //std::cout << "l"<<std::endl;

    //for(int i =0; i < size;i++)
    //{
        //std::cout << "o"<<std::endl;
    //    a.push_back((double)12);
        //std::cout << "w"<<std::endl;
    //    b.push_back((double)24);
        //std::cout << "r"<<std::endl;
    //}
    //std::cout << a.size()<<std::endl;
    //std::cout << b.size()<<std::endl;

    //vector<double> c(5);
    //c=a+b;

    //std::cout << "vec a + b = \n"<<std::endl;
    //c.print();
    //c[0] = 25;
    //std::cout << "\nc[0] = "<< c[0] <<std::endl;
    //c.push_back((double)10);
    //std::cout << "\nc new size = " << c.size()<<std::endl;
    //c.print();
    
}