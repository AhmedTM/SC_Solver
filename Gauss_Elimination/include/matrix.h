#ifndef MATRIX_H_
#define MATRIX_H_
#include<iostream>
#include<vector>
#include"vector.h"
template <typename T>
class matrix
{
    private:
        int rows_;
        int cols_;
        std::vector<std::vector<T>> data_;

    public:
        matrix(){}
        matrix(const int& rows,const int& cols) : rows_(rows),cols_(cols)  
        {
            data_.resize(rows);
            for (int i = 0; i < rows; ++i)
            {
                data_[i].resize(cols);
            }
            for(int i =0;i<data_.size();i++)
            {
                for(int j=0;j<data_[0].size();j++)
                {
                    data_[i][j] = 0;
                }
            }
        }
        matrix(const std::vector<std::vector<T>>& data) : data_(data) , rows_(data.size()) , cols_(data[0].size()) {}
        matrix(const matrix<T>& m2): data_(m2.data_),rows_(m2.rows_),cols_(m2.cols_){}
        void add_column(const std::vector<T>& col)
        {
            if(col.size() != rows_)
            {
                throw "Column size does not match";
            }
            //std::cout<<"hello"<<std::endl;
            //std::cout<<data_[0].size()<<std::endl;
            for(int i =0;i<cols_;i++)
            {
                //std::cout<<"hello"<<std::endl;
                data_[i].push_back(col[i]);
            }
            cols_ = data_[0].size();
        }
        std::pair<int,int> size()
        {
            std::pair<int,int> size = {rows_,cols_};
            return size;
        }
        void add_row(const std::vector<T>& row)
        {
            if(cols_ != row.size())
            {
                throw "Row size does not match";
            }
            data_.push_back(row);
            rows_ = data_.size();
        }
        vector<T> row(int rowIndex)
        {
            return vector<T>(data_[rowIndex]);
        }
        std::vector<T> column(int columnIndex)
        {
            std::vector<T> col;
            for(int i =0;i<data_.size();i++)
            {
                col.push_back(data_[i][columnIndex]);
            }
            return col;
        }
        matrix<T> add(const matrix<T>& other)
        {
            if(rows_ != other.rows_ || cols_ != other.cols_)
            {
                throw "Matrices sizes does not match";
            }
            std::vector<std::vector<T>> result;
            result.resize(rows_);
            for (int i = 0; i < rows_; ++i)
            {
                result[i].resize(cols_);
            }
            for(int i =0;i<data_.size();i++)
            {
                for(int j=0;j<data_[0].size();j++)
                {
                    result[i][j] = data_[i][j] + other.data_[i][j];
                }
            }
            return matrix<T>(result);
        }
        matrix<T> operator+(const matrix<T>& other)
        {
            if(rows_ != other.rows_ || cols_ != other.cols_)
            {
                throw "Matrices sizes does not match";
            }
            std::vector<std::vector<T>> result;
            result.resize(rows_);
            for (int i = 0; i < rows_; ++i)
            {
                result[i].resize(cols_);
            }
            for(int i =0;i<data_.size();i++)
            {
                for(int j=0;j<data_[0].size();j++)
                {
                    result[i][j] = data_[i][j] + other.data_[i][j];
                }
            }
            return matrix<T>(result);
        }
        T& operator()(int row,int column)
        {
            return data_[row][column];
        }
        void print()
        {
            std::cout << "matrix<"<<rows_<<","<<cols_<<">"<<std::endl;
            std::cout << "{";
            for(int i =0;i<data_.size();i++)
            {
                for(int j=0;j<data_[0].size();j++)
                {
                    if(i==rows_-1 && j==cols_-1)
                    {
                        std::cout << data_[i][j]<<"}"<<std::endl;
                    }
                    else
                    {
                        std::cout << data_[i][j]<<" , ";
                    }

                }
                std::cout << "\n";
            }
        }
        std::vector<T>& operator[](int index)
        {
            return data_[index];
        }

        
};
#endif