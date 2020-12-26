#ifndef GAUSS_H_
#define GAUSS_H_
#include <cmath>
#include"matrix.h"
#include"vector.h"
namespace Solvers{
    //***************************************** Checking ill condition***********************
    template<typename T>
    static bool check_solution(matrix<T> A)
    {
        std::vector<std::vector<T>> A_inverse;
        matrix<T> augmented_ = A;
        for(int i = 0; i<augmented_.size().first;i++)
        {
            augmented_[i] = (augmented_.row(i)/A.row(i).max().first).to_vector();
        }
        matrix<T> aug_cop = augmented_;
        std::vector<std::vector<T>> I_vec(A.size().first, std::vector<T>(A.size().second, 0));
        for(int i =0 ; i<A.size().first;i++)
        {
            for(int j =0 ; j<A.size().second;j++)
            {
                if(i==j)
                {
                    I_vec[i][j] = 1;
                }
                else
                {
                    I_vec[i][j] = 0;
                }
            }
        }
        matrix<T> I(I_vec);
        for(int z = 0; z<I.size().second;z++)
        {
            augmented_ = aug_cop;
            vector<T> b = I.column(z);
            augmented_.add_column(b.to_vector());
            int rows,cols;
            rows = augmented_.size().first;
            cols = augmented_.size().second;
            //********************************Scaling*******************************
            for(int i = 0; i<augmented_.size().first;i++)
            {
                augmented_[i] = (augmented_.row(i)/A.row(i).max().first).to_vector();
            }
            //***********************************************************************
            for(int i = 0; i<augmented_.size().first;i++)
            {
                //*********************************Pivoting*******************************
                int pivot_index = -1;
                T pivot_num = -10000;
                for(int k = i;k<augmented_.size().first;k++)
                {
                    if(augmented_(i,k)>pivot_num)
                    {
                        pivot_num = augmented_[i][k];
                        pivot_index = k;
                    }
                }
                vector<T> pivot(augmented_.row(pivot_index));
                augmented_.swap_rows(pivot_index,i);
                //*************************************************************************
                //***************************** Forward Elimination ***********************
                for(int j =i+1;j<augmented_.size().first;j++)
                {
                    T coeff = augmented_(j,i)/pivot[i];
                    vector<T> res = pivot*coeff;
                    res = augmented_.row(j) - res;
                    augmented_[j] = res.to_vector();
                }
            }
            //********************************************************************************

            //********************************* Backward Substitution ************************
            vector<T> x_sol;
            for(int i = 0; i<b.size();i++)
            {
                x_sol.push_back(1);
            }
            T x_0 = augmented_((rows-1),(cols-1))/augmented_((rows-1),(cols-2));
            x_sol[cols-2]=x_0;
            int col_change = cols - 3;
            std::vector<T> result;
            for(int i = rows -1;i>=0;i--)
            {
                double x=0;
                for(int j = cols-1;j>col_change;j--)
                {
                    if(j == cols-1)
                    {
                        x = augmented_(i,j);
                    }
                    else if(j == col_change+1)
                    {
                        x = x/augmented_(i,j);
                    }
                    else
                    {
                        x = x - (augmented_(i,j)*x_sol[j]);
                    }
                }
                x_sol[i]=x;
                
                col_change--;
            }
            A_inverse.push_back(x_sol.to_vector());
            //*********************************************************************************
        }
        matrix<T> A_inv(A_inverse);
        bool condition;
        for(int i = 0;i<A_inv.size().first;i++)
        {
            for(int j = 0;j<A_inv.size().second;j++)
            {
                if(A_inv(i,j)>1)
                {
                    condition = false;
                }
                else
                {
                    condition = true;
                }
            }
        }
        return condition;
    }
    //***************************************************************************************
    //************************************Scaled Partial Pivoting****************************
    template <typename T>
    class gaussSPP
    {
        private:
            matrix<T> A_;
            matrix<T> augmented;
            vector<T> b_;
            vector<T> x_;
        public:
            bool valid_solution = true;
        public:
            void Init(matrix<T> A,vector<T> b,vector<T> x)
            {
                valid_solution = check_solution(A);
                A_ = A;
                b_=b;
                x_ = x;
            }
            vector<T> Solve()
            {
                augmented = A_;
                augmented.add_column(b_.to_vector());
                int rows,cols;
                rows = augmented.size().first;
                cols = augmented.size().second;
                //********************************Scaling*******************************
                for(int i = 0; i<augmented.size().first;i++)
                {
                    augmented[i] = (augmented.row(i)/A_.row(i).max().first).to_vector();
                }
                //***********************************************************************
                for(int i = 0; i<augmented.size().first;i++)
                {
                    //*********************************Pivoting*******************************
                    int pivot_index = -1;
                    T pivot_num = -10000;
                    for(int k = i;k<augmented.size().first;k++)
                    {
                        if(augmented(i,k)>pivot_num)
                        {
                            pivot_num = augmented[i][k];
                            pivot_index = k;
                        }
                    }

                    vector<T> pivot(augmented.row(pivot_index));
                    augmented.swap_rows(pivot_index,i);
                    //*************************************************************************
                    //***************************** Forward Elimination ***********************
                    for(int j =i+1;j<augmented.size().first;j++)
                    {
                        T coeff = augmented(j,i)/pivot[i];
                        vector<T> res = pivot*coeff;
                        res = augmented.row(j) - res;
                        augmented[j] = res.to_vector();
                    }
                }
                //********************************************************************************
             
                //********************************* Backward Substitution ************************
                T x_0 = augmented((rows-1),(cols-1))/augmented((rows-1),(cols-2));
                x_[cols-2]=x_0;
                //std::cout<<"x_0 = "<<x_0<<std::endl;
                int col_change = cols - 3;
                std::vector<T> result;
                for(int i = rows -1;i>=0;i--)
                {
                    double x=0;
                    for(int j = cols-1;j>col_change;j--)
                    {
                        if(j == cols-1)
                        {
                            x = augmented(i,j);
                        }
                        else if(j == col_change+1)
                        {
                            x = x/augmented(i,j);
                        }
                        else
                        {
                            x = x - (augmented(i,j)*x_[j]);
                        }
                    }
                    x_[i]=x;
                    
                    col_change--;
                }
                //*********************************************************************************
                return x_;

            }
            

    };
    //****************************************************************************************

    //***************************************** Gauss Siedel *********************************
    template <typename T>
    class gaussSeidel
    {
        private:
            matrix<T> A_;
            vector<T> x_;
            vector<T> b_;
            int iterations = 100;
            double eps;
        public:
            bool valid_solution=true;

        public:
            gaussSeidel(){}
            void Init(matrix<T> A,vector<T> b,vector<T> x,int max_iters,double epsilon)
            {
                valid_solution = check_solution(A);
                A_ = A;
                b_ = b;
                x_ = x;
                iterations = max_iters;
                eps = epsilon;
            }
            vector<T> Solve()
            {
                 for(int i = 0; i<A_.size().first; i++)
                {
                    double sum = 0;
                    for(int j = 0; j<A_.size().second; j++)
                    {
                        if(i == j)
                        {
                            continue;
                        }
                        else if(i!=j)
                        {
                            sum += (A_(i,j)*x_[j]);
                        }
                    }
                    x_[i] = (b_[i] - sum)/A_(i,i);
                }
                vector<T> x_old;
                for(int i = 1; i<iterations; i++)
                {
                    x_old = x_;
                    double epsilon=0;
                    for(int j = 0; j<A_.size().first; j++)
                    {
                        double sum = 0;
                        for(int k = 0; k<A_.size().second; k++)
                        {

                            if(j == k)
                            {
                                continue;
                            }
                            else if(j!=k)
                            {
                                sum += (A_(j,k)*x_[k]);
                            }
                        }
                        x_[j] = (b_[j] - sum)/A_(j,j);
                    }
                    x_old = (x_-x_old)/x_;
                    for(int j = 0;j<x_old.size();j++)
                    {
                        epsilon += x_old[j];
                    }
                    epsilon = std::abs(epsilon);
                    if(epsilon<eps)
                    {
                        std::cout<<"Converged Epsilon = "<<epsilon<<std::endl;
                        iterations = i;
                        break;
                    }
                }
                std::cout<<"iters "<<iterations<<std::endl;
                return x_;
            }
    };
    //***************************************************************************************
}
#endif