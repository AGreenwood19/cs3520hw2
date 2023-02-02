//Alex Greenwood
// Homework 2
// CS3520

//standard notes for my variables, I always use I as rows and j as collumns

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

}

Matrix::Matrix(int width, int height){

}

Matrix::Matrix(int width, int height, int fill_value){

}

int Matrix::get_width() const{
    return m_width;
}

int Matrix::get_height() const{
    return m_height;
}

Matrix::Slice Matrix::get_row_slice(int row, int col_start, int col_end) const{
    if(col_start<0){
        col_start = 0;
    }
    if(col_end<0){
        col_end = m_width;
    }
    for(int i=col_end;i<col_start;i=i-1){
        data.pushback(i);
    }
}

const int& Matrix::at(int row, int column) const {
    return 
}

int& Matrix::at(int row, int column){
    
}

void Matrix::print(std::ostream& os) const{

}