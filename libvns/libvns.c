#include <kovan/kovan.h>
#include <stdlib.h>
#include <math.h>
#include "vns.h"

vars set_vars(){
  vars y;
  y.height = 0;
  y.width = 0;
  y.height = get_height();
  y.width = get_width();
  y.area = get_area(y);
  if(y.height == 0){
    y.normal_width = 100;
  }
  else{
    y.normal_width = get_normal_width(y);
  }
  if(y.height == 0 || y.normal_width >= 1 || y.normal_width <= -1 || k == 0){
    y.errors = 1;
    y.easy_distance = 0;
    y.angle = 0;
    y.true_distance = 0;   
  }  
  else{
    y.errors = 0;
    y.angle = get_angle(y);
    y.true_distance = get_true_distance(y);
    y.easy_distance = get_easy_distance(y);
  }
  return y;
}

double get_area(vars input){
  double h = get_height(input);
  double w = get_width(input);
  return w * h;
}

double get_height(vars input){
  if(input.height == 0){
    rectangle box;
    box = get_object_bbox(0, 0);
    return box.height;
  }
  else{
    return input.height;
  }
}

double get_width(vars input){
  if(input.width == 0){
    rectangle box;
    box = get_object_bbox(0, 0);
    return box.width;
  }
  else{
    return input.width;
  }
}

double get_normal_width(vars input){
  double h = get_height(input);
  double w = get_width(input);
  return w / h;
}

double get_easy_distance(vars input){
  double h = get_height(input);
  return 1 / h;
}

double get_angle(vars input){
  double angle = acos(get_normal_width(input));
  return angle;
}

double get_true_distance(vars input){
  double h = get_height(input);
  double fish = 1/tan(h / K);
  return fish;
}

int setup(){
 retry:
  error = camera_open();
  if(error == 0) goto retry;
  return 0;
}
