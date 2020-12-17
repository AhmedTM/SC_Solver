#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
#include<vector>
template <typename T>
class vector
{
    private:
        int size_;
        std::vector<T> data_;

    public:
        vector(const int& size) : size_(size) {
            for(int i =0;i<data_.size();i++)
            {
                data_[i] = 0;
            }
        }
        vector(const std::vector<T>& data) : data_(data) , size_(data.size()) {}
        int size()
        {
            return size_;
        }
        void print()
        {
             for(int i=0; i<size_;i++)
            {
                std::cout<<data_[i]<<std::endl;
            }
        }
        void push_back(const T& new_element)
        {
            data_.push_back(new_element);
            size_ = data_.size();
        }
        vector<T> add(vector<T> other)
        {
            if(size_ != other.size_)
            {
                throw "Vector sizes does not match";
                return -1;
            }
            vector<T> result(size_);
            for(int i = 0; i<size_; i++)
            {
                result[i] = this->data_[i]+other.data_[i];
            }
            return result;
        }
        T& operator[](int index)
        {
            return data_[index];
        }
        vector<T> operator+(vector<T>& other)
        {
            if(size_ != other.size_)
            {
                throw "Vector sizes does not match";
                return -1;
            }
            std::vector<T> result;
            //std::cout << result.size()<<std::endl;
            other.print();
            
            for(int i = 0; i<size_; i++)
            {
                //std::cout << result[i] <<std::endl;
                //std::cout << data_[i] <<std::endl;
                //std::cout << other[i] <<std::endl;
                //std::cout << "hi"<<std::endl;
                result.push_back(data_[i] + other[i]);
                //std::cout << result[i]<<std::endl;
            }
            
            return vector<T>(result);
        }

        
};
#endif