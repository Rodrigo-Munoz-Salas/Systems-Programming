#include <stdio.h>
#include <math.h>
#include <string.h>
#define square(a) ((a) * (a))
#define PRECISION 1e-5
typedef struct
{
    double x, y;
} xy_point;
typedef struct
{
    xy_point a, b, c;
} triangle;
double euclidean_distance(xy_point a, xy_point b)
{
    return sqrt(square(a.x - b.x) + square(a.y - b.y));
}
double perimeter(triangle t)
{
    double ab = euclidean_distance(t.a, t.b);
    double ac = euclidean_distance(t.a, t.c);
    double bc = euclidean_distance(t.b, t.c);
    return ab + ac + bc;
}
char *tostr(triangle t)
{
    char *rv = (char *)malloc(1000);
    sprintf(rv, "(%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)",
            t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y);
    return rv;
}
int triangle_cmp(triangle *t1, triangle *t2)
{
    double p1 = perimeter(*t1);
    double p2 = perimeter(*t2);
    if (p1 > p2 + PRECISION)
        return 1;
    else if (p1 < p2 - PRECISION)
        return -1;
    else
        return 0;
}
void generic_qsort(void *v[], int left, int right,
                   int (*comp)(void *, void *), int type_size)
{
    void swap(void *v[], int i, int j, int type_size)
    {
        char temp[type_size];
        char *bytes = (char *)v;
        memcpy(temp, bytes + (type_size * i), type_size);
        memcpy(bytes + (type_size * i), bytes + (type_size * j), type_size);
        memcpy(bytes + (type_size * j), temp, type_size);
    }
    char *bytes = (char *)v;
    int i, last;
    if (left >= right)
        return;                                   // base case
    swap(v, left, (left + right) / 2, type_size); // pivot
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(bytes + (i * type_size), bytes + (left * type_size)) < 0)
            swap(v, ++last, i, type_size);
    swap(v, left, last, type_size);
    generic_qsort(v, left, last - 1, comp, type_size);
    generic_qsort(v, last + 1, right, comp, type_size);
}
int str_cmp(char **str1, char **str2)
{
    return strcmp(*str1, *str2);
}
void main(void)
{
    triangle list[] =
        {
            0., 0., 2., 0., 0., 2.,
            0., 0., .5, 0., 0., 1.,
            0., 0.5, 1., 0.5, 0., 1.5,
            0.1, 0., 2., 0., 0., 2.,
            0.1, 0., .5, 0., 0., 1.,
            0.1, 0.5, 1., 0.5, 0., 1.5,
            0.2, 0., 2., 0., 0., 2.,
            0.2, 0., .5, 0., 0., 1.,
            0.2, 0.5, 1., 0.5, 0., 1.5,
            0.3, 0., 2., 0., 0., 2.,
            0.3, 0., .5, 0., 0., 1.,
            0.3, 0.5, 1., 0.5, 0., 1.5,
            0.4, 0., 2., 0., 0., 2.,
            0.4, 0., .5, 0., 0., 1.,
            0.4, 0.5, 1., 0.5, 0., 1.5};
    for (int i = 0; i < 15; i++)
        printf("%s: %.2f\n", tostr(list[i]), perimeter(list[i]));
    generic_qsort(list, 0, 14, triangle_cmp, sizeof(triangle));
    printf("after sorting: \n");
    for (int i = 0; i < 15; i++)
        printf("%s: %.2f\n", tostr(list[i]), perimeter(list[i]));
    printf("Now, we sort a sequence of strings with the same generic_qsort: \n");
    char *fruit[] = {"orange", "banana", "strawberry", "apple", "kiwi"};
    for (int i = 0; i < 5; i++)
        printf("%s ", fruit[i]);
    printf("\nAfter sorting: \n");
    generic_qsort(fruit, 0, 4, str_cmp, sizeof(char *));
    for (int i = 0; i < 5; i++)
        printf("%s ", fruit[i]);
    printf("\n");
}