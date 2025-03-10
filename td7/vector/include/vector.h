#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"


typedef struct Vector * Vector;

Vector create_vector(Point start, Point end);
Point translate_point(Point p, Vector v);
void print_vector(Vector v);
char * vector_to_string(Vector v);

#endif // VECTOR_H
