#pragma once
#include<iostream>
#include<vector>
template <typename T>
class vector
{
    private:
        int size_;
        std::vector<T> data_;

    public:
        vector(const int& size) : size_(size) {}
        vector(const std::vector<T>& data) : data_(data) , size_(data.size()) {}
        vector<T> add(vector<T> other);
        vector<T> dot(vector<T> other);

        vector<T> operator*(const vector<T>* other);
        vector<T> operator+(const vector<T>* other);

        
};