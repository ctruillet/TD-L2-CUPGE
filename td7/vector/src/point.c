#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point{
    double x;
    double y;
};


Point create_point(double x, double y) {
    Point p = (Point)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}


double get_x(Point p) {
    return p->x;
}

double get_y(Point p) {
    return p->y;
}

void print_point(Point p){
    printf("(%.2f, %.2f)\n", p->x, p->y);
}

char * point_to_string(Point p){
    char * str = (char *)malloc(100 * sizeof(char));
    sprintf(str, "(%.2f, %.2f)", p->x, p->y);
    return str;
}
