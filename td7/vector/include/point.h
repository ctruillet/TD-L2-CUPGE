#ifndef POINT_H
#define POINT_H

typedef struct Point * Point;

Point create_point(double x, double y);
void print_point(Point p);
double get_x(Point p);
double get_y(Point p);
char * point_to_string(Point p);


#endif // POINT_H
