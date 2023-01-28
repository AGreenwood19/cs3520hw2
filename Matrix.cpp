//Alex Greenwood
// Homework 2
// CS3520

#include <iostream>

#include "Matrix.hpp"

using std::get;
using std::cout;
using std::endl;
using std::string;

int main() {

return 0;
}

int Matrix::get_width() const{
    return m_width;
}

int Matrix::get_height() const{
    return m_height;
}

Matrix::Slice Matrix::get_row_slice(int row, int col_start, int col_end) const{

}

const int& Matrix::at(int row, int column) const {

}

int& Matrix::at(int row, int column){

}

void Matrix::print(std::ostream& os) const{

}