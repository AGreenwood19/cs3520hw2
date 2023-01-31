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

int main() {
    Pixel fill;
    int width, height;
    string filename; 
    cout<<"What is the name of the file you want to read?"<<endl;
    cin>>filename;
    std::ifstream fs_input(filename);
    Image initial = Image::read_ppm(fs_input);
    return 0;
}

Image(){
    
}

Image(int width, int height){
    
}

Image(int width, int height, const Pixel& fill){

}

static Image Image::read_ppm(std::istream& is){
    // ifstream fin;
    // istream.open(is);
    int j=0 i=0;
    Pixel p;
    Image initial_img;
    while(!inputFile.eof()){ //this checks if it is the end of the file.
        fin>>initial_img[i][j];
    }
    return initial_img;
}

void Image::print(std::ostream& os) const{

}

int Image::get_width() const {
    return m_width;
}

int Image::get_height() const {
    return m_height;
}

// Pixel Image::get_pixel(int row, int column) const{

// }


void Image::set_pixel(int row, int column, const Pixel& color){

}