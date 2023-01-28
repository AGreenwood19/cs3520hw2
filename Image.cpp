//Alex Greenwood
// Homework 2
// CS3520

#include <iostream>

#include "Image.hpp"

using std::get;
using std::cout;
using std::endl;
using std::string;

int main() {

    return 0;
}

static Image read_ppm(std::istream& is){

}

void Image::print(std::ostream& os) const{

}

int Image::get_width() const {
    return m_width;
}

int Image::get_height() const {
    return m_height;
}

Pixel Image::get_pixel(int row, int column) const{

}


void Image::set_pixel(int row, int column, const Pixel& color){

}