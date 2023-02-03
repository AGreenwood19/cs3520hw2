#include "Matrix.hpp"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image::print produces the correct output.
TEST(test_print_basic) {
  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image img(2, 2);
  img.set_pixel(0, 0, red);
  img.set_pixel(0, 1, green);
  img.set_pixel(1, 0, blue);
  img.set_pixel(1, 1, white);

  // Capture our output
  ostringstream actual;
  img.print(actual);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(correct.str(), actual.str());
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.
TEST(test_get_pixel_and_set_pixel){
  Image img(2,2);
  const Pixel red = {255,0,0};
  const Pixel green = {0,255,0};
  const Pixel blue = {0,0,255};
  const Pixel white = {255,255,255};
  img.set_pixel(0,0,red);
  img.set_pixel(0,1,green);
  img.set_pixel(1,0,blue);
  img.set_pixel(1,1,white);

  //Capture our output
  ostringstream actual;
  actual << img.get_pixel(0,1).r<<img.get_pixel(0,1).g<<img.get_pixel(0,1).b <<"\n";
  actual << img.get_pixel(1,1).r<<img.get_pixel(1,1).g<<img.get_pixel(1,1).b <<"\n";

  //Correct output
  ostringstream correct;
  correct<< "0 255 0\n";
  correct<<"255 255 255\n";
  ASSERT_EQUAL(correct.str(),actual.str());
}

TEST(test_get_height){
  Image img(23,10);

  //Capture our output
  ostringstream actual;
  actual<<img.get_height()<<endl;

  //Correct output
  ostringstream correct;
  correct<<"10\n";
  ASSERT_EQUAL(correct.str(),actual.str());
}

TEST(test_get_width){
  Image img(193,122);

  //Capture our output
  ostringstream actual;
  actual<<img.get_height()<<endl;

  //Correct output
  ostringstream correct;
  correct<<"193\n";
  ASSERT_EQUAL(correct.str(),actual.str());
}

TEST(test_read_ppm){

  //Capture our output
  string input = "P3 2 2\t255 255 0 0\n0\n255 0 \n0 0 255 255 255 255 \n";
  istringstream ss_input(input);
  Image img_act = Image::read_ppm(ss_input);
  ostringstream ss_output;
  string actual = ss_output.str();
  cout<<actual<<endl;

  //Correct output
  string output_correct = "P3\n2 2\n255\n255 0 0 0 255 0 \n0 0 255 255 255 255 \n";
  ASSERT_EQUAL(output_correct,actual);
  
}

// This is some macro magic that adds a main() function that runs the test cases
// defined in this file. Do not add your own main() function.
TEST_MAIN()
