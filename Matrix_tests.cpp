//Alex Greenwood
//HW2

#include "Matrix.hpp"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <sstream>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix::at returns that value for each element.
TEST(test_Matrix_fill_basic)
{
  const int width = 3;
  const int height = 5;
  const int value = 42;
  auto mat = Matrix(width, height, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(mat.at(r, c), value);
    }
  }
}

TEST(test_get_width){
  Matrix mat(123,414);

  //Capture our output
  int act_width = mat.get_width();

  //Correct output
  int corr_width = 123;

  ASSERT_EQUAL(corr_width,act_width);
}

TEST(test_get_height){
  Matrix mat(413,635);
  //Capture our output
  int act_height = mat.get_height();

  //Correct output
  int corr_height = 635;

  ASSERT_EQUAL(corr_height,act_height);
}

TEST(test_at){
  Matrix mat(2,2,4);
  //Capture our output
  int act_index = mat.at(1,1);

  //Correct output
  int corr_index = 4;

  ASSERT_EQUAL(corr_index,act_index);
}

TEST(test_get_row_slice){
  Matrix mat(10,10,5);
  std::vector<int> v;  
  Matrix::Slice s;

  s = mat.get_row_slice(3,5,9);
  //Capture our output
  ostringstream actual;
  actual<<s.data[0]<<" "<<s.data[1]<<" "<<s.data[2]<<" "<<s.data[3]<<endl;

  //Correct output
  ostringstream correct;
  correct<<"5 5 5 5\n";

  ASSERT_EQUAL(correct.str(),actual.str());
}

// TEST(test_){

//   //Capture our output
//   ostringstream actual;

//   //Correct output
//   ostringstream correct;

//   ASSERT_EQUAL(correct.str(),actual.str());
// }
// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// This is some macro magic that adds a main() function that runs the test cases
// defined in this file. Do not add your own main() function.
TEST_MAIN()
