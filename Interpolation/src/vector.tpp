/*#include "vector.h"

template <typename T>
vector<T>::vector(){}

template <typename T>
vector<T>::vector(const int& size) : size_(size) 
{
    for(int i =0;i<data_.size();i++)
    {
        data_.push_back(0);
    }
}

template <typename T>
vector<T>::vector(const std::vector<T>& data) : data_(data) , size_(data.size()) {}

template <typename T>
vector<T>::vector(const vector<T>& v2) : data_(v2.data_) , size_(v2.size_) {}

template <typename T>
int vector<T>::size()
{
    return size_;
}

template <typename T>
void vector<T>::print()
{
    std::cout<< "vector<"<<size_<<">"<<std::endl;
    for(int i=0; i<size_;i++)
    {
        std::cout<<data_[i]<<std::endl;
    }
    std::cout<< "\n";
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
    if(size_ != other.size_)
    {
        throw "Vector sizes does not match";
        return -1;
    }
    std::vector<T> result;
    //other.print();
    
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] + other[i]);
    }
    
    return vector<T>(result);
}

template <typename T>
std::pair<T,int> vector<T>::max()
{
    T max_num = -1000;
    int index = -1;
    for(int i = 0;i<data_.size();i++)
    {
        if(data_[i]>max_num)
        {
            max_num = data_[i];
            index = i;

        }
    }
    std::pair<T,int> max = {max_num,index}; 
    return max;
}

template <typename T>
T& vector<T>::operator[](int index)
{
    return data_[index];
}

template <typename T>
vector<T> vector<T>::operator+(const vector<T>& other)
{
    if(size_ != other.size_)
    {
        throw "Vector sizes does not match";
        return -1;
    }
    std::vector<T> result;
    
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] + other[i]);
    }
    
    return vector<T>(result);
}

template <typename T>
vector<T> vector<T>::operator+(T other)
{
    std::vector<T> result;
    
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] + other);
    }
    
    return vector<T>(result);
}
template <typename T>
vector<T> vector<T>::operator-(vector<T> other)
{
    if(size_ != other.size_)
    {
        throw "Vector sizes does not match";
        return -1;
    }
    std::vector<T> result;
    
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] - other[i]);
    }
    
    return vector<T>(result);
}
template <typename T>
vector<T> vector<T>::operator-(T other)
{
    std::vector<T> result;
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] - other);
    }
    
    return vector<T>(result);
}
template <typename T>
std::vector<T> vector<T>::to_vector()
{
    return data_;
}

template <typename T>
vector<T> vector<T>::operator/(vector<T> other)
{
    std::vector<T> result;
    if(size_ != other.size_)
    {
        throw "Vector sizes does not match";
        return result;
    }
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] / other[i]);
    }
    
    return vector<T>(result);

}
template <typename T>
vector<T> vector<T>::operator/(T other)
{
    std::vector<T> result;
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] / other);
    }
    
    return vector<T>(result);

}
template <typename T>
vector<T> vector<T>::operator*(vector<T> other)
{
    std::vector<T> result;
    if(size_ != other.size_)
    {
        throw "Vector sizes does not match";
        return result;
    }
    for(int i = 0; i<size_; i++)
    {
        result.push_back(data_[i] * other[i]);
    }
    
    return vector<T>(result);

}
template <typename T>
vector<T> vector<T>::operator*(T other)
{
    std::vector<T> result;
    for(int i = 0; i<size_; i++)
    {
        //std::cout << result[i] <<std::endl;
        //std::cout << data_[i] <<std::endl;
        //std::cout << other[i] <<std::endl;
        //std::cout << "hi"<<std::endl;
        result.push_back(data_[i] * other);
        //std::cout << result[i]<<std::endl;
    }
    
    return vector<T>(result);

}*/