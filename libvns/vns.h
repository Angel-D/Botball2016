#ifndef vns
#define vns
#include <kovan/kovan.h>
#include <stdlib.h>
#include <math.h>
#define K          10
typedef struct vars{
  double area;
  double height;
  double width;
  double normal_width;
  double easy_distance;
  double angle;
  double true_distance;
  int errors;
}vars;
vars x;
int k = 10;
int setup();

double get_area(vars input);
double get_height();
double get_width();
double get_normal_width(vars input);
double get_easy_distance(vars input);
double get_angle(vars input);
double get_true_distance(vars input);
int error;

vars set_vars();
#endif
