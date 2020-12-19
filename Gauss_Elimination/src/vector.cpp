//#include "vector.h"
/*
template <typename T>
vector<T>::vector(const int& size) : size_(size) {}

template <typename T>
vector<T>::vector(const std::vector<T>& data) : data_(data) , size_(data.size()) {}

template <typename T>
int vector<T>::size()
{
    return size_;
}

template <typename T>
void vector<T>::push_back(const T& new_element)
{
    data_.push_back(new_element);
    size_ = data_.size;
}

template <typename T>
vector<T> vector<T>::add(vector<T> other)
{
    if(this->size() != other.size())
    {
        throw "Vector sizes does not match";
        return -1;
    }
    vector<T> result(this->size());
    for(int i = 0; i<this->size(); i++)
    {
        result[i] = this->data_[i]+other.data_[i];
    }
    return result;
}

template <typename T>
T& vector<T>::operator[](int index)
{
    return data_[index];
}

template <typename T>
vector<T> vector<T>::operator+(const vector<T>& other)
{
    if(this->size() != other.size())
    {
        throw "Vector sizes does not match";
        return -1;
    }
    vector<T> result(this->size());
    for(int i = 0; i<this->size(); i++)
    {
        result[i] = this->data_[i]+other.data_[i];
    }
    return result;
}

template <typename T>
void vector<T>::print()
{
    for(int i=0; i<vector<T>::size_;i++)
    {
        std::cout<<data_[i]<<std::endl;
    }
}*/