#pragma once
#include<iostream>
#include<vector>
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
        matrix<T> add(const matrix<T> other);
        matrix<T> operator+(const matrix<T>* other);

        
};