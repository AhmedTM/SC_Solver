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
        matrix(const int& rows,const int& cols) : rows_(rows),cols_(cols)  
        {
            data_.resize(rows);
            for (int i = 0; i < rows; ++i)
            {
                data_[i].resize(cols);
            }
        }
        matrix(const std::vector<std::vector<T>>& data) : data_(data) , rows_(data.size()) , cols_(data[0].size()) {}
        void add_column(const std::vector<T>& col);
        void add_row(const std::vector<T>& row);
        vector<T>& row(int rowIndex);
        vector<T>& column(int columnIndex);
        matrix<T> add(const matrix<T>& other);
        matrix<T> operator+(const matrix<T>& other);
        vector<T>& operator[](int index);

        
};
#endif