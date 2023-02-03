//Alex Greenwood
// Homework 2
// CS3520

#include <iostream>

#include "Image.hpp"

using namespace std;
// using std::get;
// using std::cout;
// using std::endl;
// using std::string;
// using std::cin;

// int main() {
//     /*Pixel fill;
//     int width, height;
//     string filename;
//     cout<<"What is the name of the file you want to read?"<<endl;
//     cin>>filename;
//     std::ifstream fs_input(filename);
//     Image initial = Image::read_ppm(fs_input);
//     */
//    return 0;
// }

Image::Image(){
    m_width = 0;
    m_height = 0;
}

Image::Image(int width, int height){
    m_width = width;
    m_height = height;
    for(int i=0;i<m_height;i++){
        for(int j=0;j<m_width;j++){
            m_red_channel.at(i,j) = 0;
            m_green_channel.at(i,j) = 0;
            m_blue_channel.at(i,j) = 0;
        }
    }
}

Image::Image(int width, int height, const Pixel& fill){
    m_width = width;
    m_height = height;
    for(int i=0;i<m_height;i++){
        for(int j=0;j<m_width;j++){
            m_red_channel.at(i,j) = fill.r;
            m_green_channel.at(i,j) = fill.g;
            m_blue_channel.at(i,j) = fill.b;
        }
    }
}

Image Image::read_ppm(std::istream& is){
    /*
    What needs to happen here
    read in the file "whatever type it is"
    get each pixel at each location in the file
        - this will use the set pixel func
    turn this into an Image class image
    return image
    */
    int width, height;
    int throwaway1, throwaway2;
    Pixel p;
    is>>throwaway1>>width>>height>>throwaway2;
    Image initial_img(width,height);
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            is>>p.r>>p.g>>p.b;
            initial_img.set_pixel(i,j,p);
        }
    }
    return initial_img;
}

void Image::print(std::ostream& os) const{
    /*
     takes in an "open output stream"
     prints header
     prints width height
     prints 255
    */
   
   os<<"P3"<<endl<<m_width<<" "<<m_height<<endl<<"255"<<endl;
   for(int i=0;i<m_height;i++){
    for(int j=0;j<m_height;j++){
        os<<m_red_channel.at(i,j)<<m_green_channel.at(i,j)<<m_blue_channel.at(i,j);
    }
    os<<endl;
   }
}

int Image::get_width() const {
    return m_width;
}

int Image::get_height() const {
    return m_height;
}

Pixel Image::get_pixel(int row, int column) const{
    Pixel p;

    p.r = m_red_channel.at(row,column);
    p.g = m_green_channel.at(row,column);
    p.b = m_blue_channel.at(row,column);
    return p;
}

void Image::set_pixel(int row, int column, const Pixel& color){
    m_red_channel.at(row,column) = color.r;
    m_green_channel.at(row,column) = color.g;
    m_blue_channel.at(row,column) = color.b;
}