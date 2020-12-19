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
        vector() {}
        vector(const int& size) : size_(size) {
            for(int i =0;i<data_.size();i++)
            {
                data_[i] = 0;
            }
        }
        vector(const std::vector<T>& data) : data_(data) , size_(data.size()) {}
        vector(const vector<T>& v2) : data_(v2.data_) , size_(v2.size_) {}
        int size()
        {
            return size_;
        }
        void print()
        {
            std::cout<< "vector<"<<size_<<">"<<std::endl;
            for(int i=0; i<size_;i++)
            {
                std::cout<<data_[i]<<std::endl;
            }
            std::cout<< "\n";
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
            std::vector<T> result;
            //other.print();
            
            for(int i = 0; i<size_; i++)
            {
                result.push_back(data_[i] + other[i]);
            }
            
            return vector<T>(result);
        }
        T& operator[](int index)
        {
            return data_[index];
        }
        vector<T> operator+(vector<T> other)
        {
            if(size_ != other.size_)
            {
                throw "Vector sizes does not match";
                return -1;
            }
            std::vector<T> result;
            //std::cout << result.size()<<std::endl;
            //other.print();
            
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
        vector<T> operator+(T other)
        {
            std::vector<T> result;
            //std::cout << result.size()<<std::endl;
            //other.print();
            
            for(int i = 0; i<size_; i++)
            {
                //std::cout << result[i] <<std::endl;
                //std::cout << data_[i] <<std::endl;
                //std::cout << other[i] <<std::endl;
                //std::cout << "hi"<<std::endl;
                result.push_back(data_[i] + other);
                //std::cout << result[i]<<std::endl;
            }
            
            return vector<T>(result);
        }
        vector<T> operator-(vector<T> other)
        {
            if(size_ != other.size_)
            {
                throw "Vector sizes does not match";
                return -1;
            }
            std::vector<T> result;
            //std::cout << result.size()<<std::endl;
            //other.print();
            
            for(int i = 0; i<size_; i++)
            {
                //std::cout << result[i] <<std::endl;
                //std::cout << data_[i] <<std::endl;
                //std::cout << other[i] <<std::endl;
                //std::cout << "hi"<<std::endl;
                result.push_back(data_[i] - other[i]);
                //std::cout << result[i]<<std::endl;
            }
            
            return vector<T>(result);
        }
        vector<T> operator-(T other)
        {
            std::vector<T> result;
            //std::cout << result.size()<<std::endl;
            //other.print();
            
            for(int i = 0; i<size_; i++)
            {
                //std::cout << result[i] <<std::endl;
                //std::cout << data_[i] <<std::endl;
                //std::cout << other[i] <<std::endl;
                //std::cout << "hi"<<std::endl;
                result.push_back(data_[i] - other);
                //std::cout << result[i]<<std::endl;
            }
            
            return vector<T>(result);
        }
        std::vector<T> to_vector()
        {
            return data_;
        }
        vector<T> operator/(vector<T> other)
        {
            std::vector<T> result;
            if(size_ != other.size_)
            {
                throw "Vector sizes does not match";
                return result;
            }
            for(int i = 0; i<size_; i++)
            {
                //std::cout << result[i] <<std::endl;
                //std::cout << data_[i] <<std::endl;
                //std::cout << other[i] <<std::endl;
                //std::cout << "hi"<<std::endl;
                result.push_back(data_[i] / other[i]);
                //std::cout << result[i]<<std::endl;
            }
            
            return vector<T>(result);

        }
        vector<T> operator/(T other)
        {
            std::vector<T> result;
            for(int i = 0; i<size_; i++)
            {
                //std::cout << result[i] <<std::endl;
                //std::cout << data_[i] <<std::endl;
                //std::cout << other[i] <<std::endl;
                //std::cout << "hi"<<std::endl;
                result.push_back(data_[i] / other);
                //std::cout << result[i]<<std::endl;
            }
            
            return vector<T>(result);

        }
        vector<T> operator*(vector<T> other)
        {
            std::vector<T> result;
            if(size_ != other.size_)
            {
                throw "Vector sizes does not match";
                return result;
            }
            for(int i = 0; i<size_; i++)
            {
                //std::cout << result[i] <<std::endl;
                //std::cout << data_[i] <<std::endl;
                //std::cout << other[i] <<std::endl;
                //std::cout << "hi"<<std::endl;
                result.push_back(data_[i] * other[i]);
                //std::cout << result[i]<<std::endl;
            }
            
            return vector<T>(result);

        }
        vector<T> operator*(T other)
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

        }
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