//Alex Greenwood
// Homework 2
// CS3520

//standard notes for my variables, I always use I as rows and j as collumns

#include "Matrix.hpp"

using std::get;
using std::cout;
using std::endl;
using std::string;

int main() {
    Matrix initial()
    int m_width, m_height;
    m_height = initial.get_width();
    for (i=0;i<m_height;i++){

    }

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