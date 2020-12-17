#include "matrix.h"

template <typename T>
void matrix<T>::add_column(const std::vector<T>& col)
{
    
}
template <typename T>
void matrix<T>::add_row(const std::vector<T>& row)
{

}
template <typename T>
vector<T>& matrix<T>::row(int rowIndex)
{
    return 0;
}
template <typename T>
vector<T>& matrix<T>::column(int columnIndex)
{
    return 0;
}
template <typename T>
matrix<T> matrix<T>::add(const matrix<T>& other)
{
    return 0;
}
template <typename T>
matrix<T> matrix<T>::operator+(const matrix<T>& other)
{
    return 0;
}
template <typename T>
vector<T>& matrix<T>::operator[](int index)
{
    return vector<T>(data_[index]);
}