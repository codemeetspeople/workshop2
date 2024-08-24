#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    void (*set)(struct Point*, int, int);
    void (*print)(struct Point*);
} Point;

void Point_set(Point* this, int x, int y) {
    this->x = x;
    this->y = y;
}

void Point_print(Point* this) {
    printf("(%d, %d)\n", this->x, this->y);
}

Point* Point_new(int x, int y) {
    Point* p = (Point*)malloc(sizeof(Point));

    p->x = x;
    p->y = y;
    p->set = Point_set;
    p->print = Point_print;

    return p;
}

void Point_delete(Point* p) {
    free(p);
}

int main() {
    Point* p = Point_new(0, 0);

    printf("Point x = %d\n", p->x);
    printf("Point y = %d\n", p->y);
    
    p->print(p);
    p->set(p, 5, 10);
    p->print(p);

    Point_delete(p);

    return 0;
}
