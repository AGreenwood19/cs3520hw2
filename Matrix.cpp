//Alex Greenwood
// Homework 2
// CS3520

//standard notes for my variables, I always use I as rows and j as collumns
#include <iostream>
#include "Matrix.hpp"

using namespace std;

// using std::get;
// using std::cout;
// using std::endl;
// using std::string;

// int main() {
//     Matrix initial()
//     int m_width, m_height;
//     m_height = initial.get_width();
//     for (i=0;i<m_height;i++){

//     }

// return 0;
// }

Matrix::Matrix(){
    m_height = 0;
    m_width = 0;
}

Matrix::Matrix(int width, int height){
    m_width = width;
    m_height = height;
    for(int i=0;i<m_height;i++) {
        for(int j=0;j<m_width;j++){
            m_data.at((i*width)+j)=0;
        }
    }
}

Matrix::Matrix(int width, int height, int fill_value){
    m_width = width;
    m_height = height;
    for(int i=0;i<m_height;i++){
        for(int j=0;j<m_width;j++){
            m_data.at((i*width)+j) = fill_value;
        }
    }
}

int Matrix::get_width() const{
    return m_width;
}

int Matrix::get_height() const{
    return m_height;
}

Matrix::Slice Matrix::get_row_slice(int row, int col_start, int col_end) const{
    Slice s;
    s.row = row;
    s.col_start = col_start;
    s.col_end = col_end;
    if(col_start<0){
        col_start = 0;
    }
    if(col_end>m_width-1){
        col_end = m_width-1;
    }
    for(int i=col_start;i<col_end;i++){
        s.data.at(i) = m_data.at((row*m_width)+i);
    }
    return s;
}

const int& Matrix::at(int row, int column) const {
    return m_data.at((row*m_width)+column);
}

int& Matrix::at(int row, int column){
    return m_data.at((row*m_width)+column);
}

void Matrix::print(std::ostream& os) const{
    os<<m_width<<" "<<m_height<<endl;
    for(int i=0;i<m_height;i++){
        for(int j=0;j<m_height;j++){
            os<<m_data.at(i*m_width+j);
        }
        os<<endl;
    }
}