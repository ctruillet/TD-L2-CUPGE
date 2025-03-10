#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector{
    double x;
    double y;
};

Vector create_vector(Point start, Point end) {
    Vector v = (Vector)malloc(sizeof(Vector));
    v->x = get_x(end) - get_x(start);
    v->y = get_y(end) - get_y(start);
    return v;
}

Point translate_point(Point p, Vector v) {
    Point new_p = create_point(get_x(p) - v->x, get_y(p) - v->y);
    return new_p;
}

char * vector_to_string(Vector v) {
    char * str = (char *)malloc(100 * sizeof(char));
    sprintf(str, "(%.2f, %.2f)", v->x, v->y);
    return str;
}

void print_vector(Vector v) {
    printf("(%.2f, %.2f)\n", v->x, v->y);
}
