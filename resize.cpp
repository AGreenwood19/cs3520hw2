//Alex Greenwood
//HW 2
//2/2/23

#include <iostream>
#include <sstream>
//#include <string>
#include "Matrix.hpp"
#include "Image.hpp"
#include "processing.hpp"

using namespace std;

int main() {
    string new_height;
    int new_width;
    Image img;
    Image new_image;
    string filename;
    string new_filename;
    cin>>filename>>new_filename>>new_width;
    istringstream input_file(filename);
    ostringstream output_file(new_filename);

    img = Image::read_ppm(input_file);

     if(stoi(new_height)==0) {
        new_image = seam_carve_width(img,new_width);
     }
     else{
        new_image = seam_carve(img,new_width,stoi(new_height));
     }

     new_image.print(output_file);


    return 0;
}