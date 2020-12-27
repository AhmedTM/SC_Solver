#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
#include<vector>
template <typename T>
class vector
{
    protected:
        int size_;
        std::vector<T> data_;

    public:
        vector();
        vector(const int& size);
        vector(const std::vector<T>& data);
        vector(const vector<T>& v2);
        int size();
        void print();
        void push_back(const T& new_element);
        vector<T> add(vector<T> other);
        std::pair<T,int> max();
        T& operator[](int index);
        vector<T> operator+(vector<T> other);

        vector<T> operator+(T other);
        vector<T> operator-(vector<T> other);
        vector<T> operator-(T other);
        std::vector<T> to_vector();
        vector<T> operator/(vector<T> other);
        vector<T> operator/(T other);
        vector<T> operator*(vector<T> other);
        vector<T> operator*(T other);
        /*void operator=(vector<T> other)
        {
            data_ = other.data_;
            size_ = other.size_;
        }
        void operator=(std::vector<T> other)
        {
            data_ = other;
            size_ = other.size();
        }*/

        
};
#endif