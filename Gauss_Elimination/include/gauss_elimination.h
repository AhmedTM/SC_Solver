#ifndef GAUSS_H_
#define GAUSS_H_
#include"matrix.h"
#include"vector.h"
template <typename T>
class LSSolver
{
    private:
        matrix<T> A_;
        matrix<T> augmented;
        vector<T> b_;
        vector<T> x_;
        int solver_=NAIVE_GAUSS;
    public:
        //std::cout<<"hello"<<std::endl;
        int NAIVE_GAUSS=1,GAUSS_SIEDEL=2,SPP_GAUSS=3;
        void Init(matrix<T> A,vector<T> b,vector<T> x, int solver)
        {
            //std::cout<<"hello"<<std::endl;
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
            std::cout<<"Augmented matrix before"<<std::endl;
            augmented.print();
            switch(solver_)
            {
                case 1:
                    {
                        //forward elimination
                        int rows,cols;
                        //std::cout<<"hello"<<std::endl;
                        rows = augmented.size().first;
                        cols = augmented.size().second;
                        for(int i = 1; i<augmented.size().first;i++)
                        {
                                T coeff = augmented(i,i-1)/augmented(0,i-1);
                                //std::cout<<augmented(i,i-1)<<" "<<std::endl;
                                //std::cout<<augmented(0,i-1)<<" "<<std::endl;
                                std::cout<<coeff<<" coeff"<<std::endl;
                                //res.print();
                                vector<T> res = augmented.row(0)*coeff;

                                res.print();
                                res = augmented.row(i) - res;
                                std::cout<<"after subtraction"<<std::endl;
                                res.print();
                                //std::cout<<augmented.size().first<<std::endl;
                                augmented[i] = res.to_vector();
                        }
                        std::cout<<augmented.size().first<<std::endl;
                        std::cout<<"Augmented matrix"<<std::endl;
                        augmented.print();
                        // backward substitution
                        T x_0 = augmented((rows-1),(cols-1))/augmented((rows-1),(cols-2));
                        x_[cols-2]=x_0;
                        std::cout<<"x_0 = "<<x_0<<std::endl;
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
                        x_.print();
                        break;
                    }
                case 2:
                    break;
                case 3:
                    break;
            }
            return x_;

        }

};
#endif