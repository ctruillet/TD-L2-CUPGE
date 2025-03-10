#include <stdio.h>
#include "point.h"
#include "vector.h"

int main() {
    Point p1 = create_point(1.0, 2.0);
    Point p2 = create_point(4.0, 6.0);

    printf("Point 1 : %s \n", point_to_string(p1));
    printf("Point 2 : %s \n", point_to_string(p2));


    Vector v = create_vector(p1, p2);
    printf("Vector from P1 to P2 : %s\n", vector_to_string(v));

    Point p3 = translate_point(p1, v);
    printf("Translated Point : %s \n", point_to_string(p3));

    return 0;
}
