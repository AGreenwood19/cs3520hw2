#include "processing.hpp"

using namespace std;

namespace {
  // The implementation of squared_difference is provided for you.
  int squared_difference(Pixel p1, Pixel p2);
}

// Implement the functions declared in processing.hpp here.

namespace {
  // The implementation of squared_difference is provided for you.
  int squared_differsence(Pixel p1, Pixel p2) {
    int dr = p2.r - p1.r;
    int dg = p2.g - p1.g;
    int db = p2.b - p1.b;
    // Divide by 100 is to avoid possible overflows
    // later on in the algorithm.
    return (dr*dr + dg*dg + db*db) / 100;
  }
}

Image rotate_left(const Image& img){
  int width = img.get_height();
  int height = img.get_width();
  Image new_image(width,height);
  Matrix new_red_channel(img.get_height(),img.get_width());
  Matrix new_green_channel(img.get_height(),img.get_width());
  Matrix new_blue_channel(img.get_height(),img.get_width());
  Pixel p;
  int row=0;
  int col=0;

  for(int j=height-1;j>=0;j++){
    for(int i=0;i<width;i++){
      new_red_channel.at(row,col)=img.get_pixel(i,j).r;
      new_green_channel.at(row,col)=img.get_pixel(i,j).g;
      new_blue_channel.at(row,col)=img.get_pixel(i,j).b;
      col++;
    }
    row++;
  }

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      p.r = new_red_channel.at(i,j);
      p.g = new_green_channel.at(i,j);
      p.b = new_blue_channel.at(i,j);
      new_image.set_pixel(i,j,p);
    }
  }

  return new_image;
}

Image rotate_right(const Image& img){
  int width = img.get_height();
  int height = img.get_width();
  Image new_image(width,height);
  Matrix new_red_channel(img.get_height(),img.get_width());
  Matrix new_green_channel(img.get_height(),img.get_width());
  Matrix new_blue_channel(img.get_height(),img.get_width());
  Pixel p;
  int row=0;
  int col=0;

  for(int j=0;j<height;j++){
    for(int i=width-1;i>=0;i--){
      new_red_channel.at(row,col)=img.get_pixel(i,j).r;
      new_green_channel.at(row,col)=img.get_pixel(i,j).g;
      new_blue_channel.at(row,col)=img.get_pixel(i,j).b;
      col++;
    }
    row++;
  }

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      p.r = new_red_channel.at(i,j);
      p.g = new_green_channel.at(i,j);
      p.b = new_blue_channel.at(i,j);
      new_image.set_pixel(i,j,p);
    }
  }

  return new_image;
}

Matrix compute_energy_matrix(const Image& img){
  int width = img.get_width();
  int height = img.get_height();
  Matrix energy_matrix(width,height);
  int energy_max=0;
  int x_energy=0;

  for(int i=1;i<height-1;i++){
    for(int j=1;j<width-1;j++){
      energy_matrix.at(i,j) = squared_difference(img.get_pixel(i,j-1),img.get_pixel(i,j+1)) + squared_difference(img.get_pixel(i-1,j),img.get_pixel(i+1,j));
      if(x_energy>energy_max)
        energy_max=x_energy;
    }
  }

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      if(i==0||j==0||i==height-1||j==width-1)
        energy_matrix.at(i,j) = energy_max;
    }
  }

  return energy_matrix;
}

Matrix compute_vertical_cost_matrix(const Image& img){
  Matrix e_mat;
  e_mat = compute_energy_matrix(img);
  int width=e_mat.get_width();
  int height = e_mat.get_height();
  Matrix cost(width,height);
  int pixel_cost;
  compute_energy_matrix(img);

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      if(i==0){
        pixel_cost=e_mat.at(i,j);
      }
      else {
        pixel_cost=e_mat.at(i,j)+min({cost.at(i-1,j-1),cost.at(i-1,j),cost.at(i-1,j+1)});
      }
      cost.at(i,j)=pixel_cost;
    }
  }
  return cost;
}

vector<int> find_minimal_vertical_seam(const Matrix& cost){
  int width = cost.get_width();
  int height = cost.get_height();
  vector<int> seam(height);
  int min_cost = 0;
  Matrix::Slice s;
  int min_cost_col;
  int min_cost_row;
  
  for(int i=height-1;i>=0;i--){
    for(int j=0;j<width;j++){
      if(i==(height-1)){
        if(cost.at(i,j)<min_cost){
          min_cost=cost.at(i,j);
          min_cost_col=j;
          min_cost_row=i;
        }
        else if(min_cost==cost.at(i,j)&&j<min_cost_col){
          min_cost_col=j;
          min_cost_row=i;
        }
      }
    }
  }

  for(int i=0;i<height;i++){
    s = cost.get_row_slice(min_cost_row-1,min_cost_col-1,min_cost_col+2);
    if(cost.at(s.row,s.col_start)<cost.at(s.row,s.col_start+1)&&cost.at(s.row,s.col_start)<cost.at(s.row,s.col_end-1)){
      seam.push_back(s.col_start);
      min_cost_col = s.col_start;
    }
    else if(cost.at(s.row,s.col_start+1)<cost.at(s.row,s.col_start)&&cost.at(s.row,s.col_start+1)<cost.at(s.row,s.col_end-1)){
      seam.push_back(s.col_start+1);
      min_cost_col = s.col_start+1;
    }
    else if(cost.at(s.row,s.col_end-1)<cost.at(s.row,s.col_start+1)&&cost.at(s.row,s.col_end-1)<cost.at(s.row,s.col_start)){
      seam.push_back(s.col_end-1);
      min_cost_col = s.col_end-1;
    }
    min_cost_row = s.row;
  }
  return seam;
}

Image remove_vertical_seam(const Image& img, const std::vector<int>& seam){
  int width = img.get_width();
  int height = img.get_height();
  Image new_img(width-1,height);
  int counter;

  for(int i=0;i<height;i++){
    counter =0;
    for(int j=0;j<width;j++){
      if(j==seam[i]){
        counter=1;
      }
      if(counter==0){
        new_img.set_pixel(i,j,img.get_pixel(i,j));
      }
      else if(counter==1){
        counter=2;
      }
      else if(counter ==2){
        new_img.set_pixel(i,j-1,img.get_pixel(i,j));
      }
    }
  }

  return new_img;
}

Image seam_carve_width(const Image& img, int new_width){
  int curr_width = img.get_width();
  Matrix e_mat;
  Matrix cost;
  vector<int> seam(img.get_height());
  Image curr_img = img;

  while(curr_width!=new_width){
    e_mat = compute_energy_matrix(curr_img);
    cost = compute_vertical_cost_matrix(curr_img);
    seam = find_minimal_vertical_seam(cost);
    curr_img = remove_vertical_seam(curr_img,seam);
    curr_width = curr_img.get_width();
  }

  return curr_img;
}

Image seam_carve_height(const Image& img, int new_height){
  Image curr_img=img;
  curr_img = seam_carve_width(curr_img,new_height);
  curr_img = rotate_right(curr_img);

  return curr_img;
}

Image seam_carve(const Image& img, int newWidth, int newHeight){
  Image curr_img = img;
  curr_img = seam_carve_width(curr_img, newWidth);
  curr_img = seam_carve_height(curr_img,newHeight);

  return curr_img;
}

