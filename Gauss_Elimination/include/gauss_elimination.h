#ifndef GAUSS_H_
#define GAUSS_H_
#define SPP_GAUSS 1
#define GAUSS_SIEDEL 2
#include"matrix.h"
#include"vector.h"
namespace Solvers{
    template<typename T>
    static bool check_solution(matrix<T> A)
    {
        //A.print();
        std::vector<std::vector<T>> A_inverse;
        matrix<T> augmented_ = A;
        //augmented_.print();
        for(int i = 0; i<augmented_.size().first;i++)
        {
            //augmented.row(i).print();
            augmented_[i] = (augmented_.row(i)/A.row(i).max().first).to_vector();
            //augmented.row(i).print();
        }
        //std::cout<<"Normalized matrix"<<std::endl;
        //augmented_.print();
        matrix<T> aug_cop = augmented_;
        //augmented_.print();
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
        //I.print();
        for(int z = 0; z<I.size().second;z++)
        {
            augmented_ = aug_cop;
            vector<T> b = I.column(z);
            //b.print();
            augmented_.add_column(b.to_vector());
            //augmented_.print();
            //std::cout<<"Augmented matrix before"<<std::endl;
            //augmented.print();
            int rows,cols;
            //std::cout<<"hello"<<std::endl;
            rows = augmented_.size().first;
            cols = augmented_.size().second;
            //********************************Scaling*******************************
            for(int i = 0; i<augmented_.size().first;i++)
            {
                //augmented.row(i).print();
                augmented_[i] = (augmented_.row(i)/A.row(i).max().first).to_vector();
                //augmented.row(i).print();
            }
            //***********************************************************************
            //std::cout<<"Augmented matrix after Scaling"<<std::endl;
            //augmented.print();
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
                //std::cout<<"pivot index "<<pivot_index<<std::endl;

                vector<T> pivot(augmented_.row(pivot_index));
                augmented_.swap_rows(pivot_index,i);
                //augmented.print();
                //std::cout<<"Pivot equation" <<std::endl;
                //pivot.print();
                //augmented_.print();
                //*************************************************************************
                //***************************** Forward Elimination ***********************
                for(int j =i+1;j<augmented_.size().first;j++)
                {
                    //std::cout<<"Pivot coeff = " <<pivot[i]<<std::endl;
                    T coeff = augmented_(j,i)/pivot[i];
                    //std::cout<<"Coeff = " <<coeff<<std::endl;
                    //std::cout<<augmented(i,i-1)<<" "<<std::endl;
                    //std::cout<<augmented(0,i-1)<<" "<<std::endl;
                    //std::cout<<coeff<<" coeff"<<std::endl;
                    //res.print();
                    vector<T> res = pivot*coeff;

                    //res.print();
                    res = augmented_.row(j) - res;
                    //std::cout<<"after subtraction"<<std::endl;
                    //res.print();
                    //std::cout<<augmented.size().first<<std::endl;
                    augmented_[j] = res.to_vector();
                }
            }
            //********************************************************************************
            //std::cout<<augmented.size().first<<std::endl;
            //std::cout<<"Augmented matrix"<<std::endl;
            //augmented.print();
            //********************************* Backward Substitution ************************
            vector<T> x_sol;
            for(int i = 0; i<b.size();i++)
            {
                x_sol.push_back(1);
            }
            T x_0 = augmented_((rows-1),(cols-1))/augmented_((rows-1),(cols-2));
            x_sol[cols-2]=x_0;
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
        //std::cout<<"Matrix Inverse"<<std::endl;
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
    template <typename T>
    class LSSolver
    {
        private:
            matrix<T> A_;
            matrix<T> augmented;
            vector<T> b_;
            vector<T> x_;
            int solver_=SPP_GAUSS;
        public:
            bool valid_solution = true;
        public:
            //std::cout<<"hello"<<std::endl;
            void Init(matrix<T> A,vector<T> b,vector<T> x, int solver)
            {
                //std::cout<<"hello"<<std::endl;
                valid_solution = check_solution(A);
                solver_ = solver;
                A_ = A;
                b_=b;
                x_ = x;
            }
            vector<T> Solve()
            {
                //std::cout<<"hello"<<std::endl;
                augmented = A_;
                augmented.add_column(b_.to_vector());
                //std::cout<<"Augmented matrix before"<<std::endl;
                //augmented.print();
                switch(solver_)
                {
                    case 1:
                        {
                            //forward elimination
                            int rows,cols;
                            //std::cout<<"hello"<<std::endl;
                            rows = augmented.size().first;
                            cols = augmented.size().second;
                            //********************************Scaling*******************************
                            for(int i = 0; i<augmented.size().first;i++)
                            {
                                //augmented.row(i).print();
                                augmented[i] = (augmented.row(i)/A_.row(i).max().first).to_vector();
                                //augmented.row(i).print();
                            }
                            //***********************************************************************
                            //std::cout<<"Augmented matrix after Scaling"<<std::endl;
                            //augmented.print();
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
                                //std::cout<<"pivot index "<<pivot_index<<std::endl;

                                vector<T> pivot(augmented.row(pivot_index));
                                augmented.swap_rows(pivot_index,i);
                                //augmented.print();
                                //std::cout<<"Pivot equation" <<std::endl;
                                //pivot.print();
                                //*************************************************************************
                                //***************************** Forward Elimination ***********************
                                for(int j =i+1;j<augmented.size().first;j++)
                                {
                                    //std::cout<<"Pivot coeff = " <<pivot[i]<<std::endl;
                                    T coeff = augmented(j,i)/pivot[i];
                                    //std::cout<<"Coeff = " <<coeff<<std::endl;
                                    //std::cout<<augmented(i,i-1)<<" "<<std::endl;
                                    //std::cout<<augmented(0,i-1)<<" "<<std::endl;
                                    //std::cout<<coeff<<" coeff"<<std::endl;
                                    //res.print();
                                    vector<T> res = pivot*coeff;

                                    //res.print();
                                    res = augmented.row(j) - res;
                                    //std::cout<<"after subtraction"<<std::endl;
                                    //res.print();
                                    //std::cout<<augmented.size().first<<std::endl;
                                    augmented[j] = res.to_vector();
                                }
                            }
                            //********************************************************************************
                            //std::cout<<augmented.size().first<<std::endl;
                            //std::cout<<"Augmented matrix"<<std::endl;
                            //augmented.print();
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
                            //x_.print();
                            break;
                        }
                    case 2:
                        break;
                }
                return x_;

            }
            

    };
}
#endif