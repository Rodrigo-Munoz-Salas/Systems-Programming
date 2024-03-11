#include <stdio.h>
#include <string.h>
#define MAX_DATES 1000
// YYYY/MM/DD
char *dates[MAX_DATES];
void swap(void *v[], int first, int second)
{
    void *temp = v[first];
    v[first] = v[second];
    v[second] = temp;
}
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, left + (right - left) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);             // move the pivot to the middle
    qsort(v, left, last - 1, comp);  // sorting the LHS of pivot
    qsort(v, last + 1, right, comp); // sorting the RHS of pivot
}
int compare_euro_dates(char *date1, char *date2)
{
    int d1, d2, y1, y2, m1, m2;
    sscanf(date1, "%d/%d/%d", &d1, &m1, &y1);
    sscanf(date2, "%d/%d/%d", &d2, &m2, &y2);
    // return (y2-y1) * 371 + 31 * (m2-m1) + (d2-d1);
    return (y2 != y1) ? (y1 - y2) : (m2 != m1) ? (m1 - m2)
                                               : (d1 - d2);
}
int compare_us_dates(char *date1, char *date2)
{
    int d1, d2, y1, y2, m1, m2;
    sscanf(date1, "%d/%d/%d", &m1, &d1, &y1);
    sscanf(date2, "%d/%d/%d", &m2, &d2, &y2);
    // return (y2-y1) * 371 + 31 * (m2-m1) + (d2-d1);
    return (y2 != y1) ? (y1 - y2) : (m2 != m1) ? (m1 - m2)
                                               : (d1 - d2);
}
int main(int argc, char *argv[])
{
    char date[25] = "1/1/1";
    int day, month, year, euro;
    if (argc > 1 && strcmp(argv[1], "-euro") == 0)
        euro = 1;
    int counter = 0;
    while (fgets(date, 25, stdin))
    {
        date[strlen(date) - 1] = '\0';
        dates[counter++] = strdup(date);
    }
    qsort((void **)dates, 0, counter - 1, (int (*)(void *, void *))(euro ? compare_euro_dates : compare_us_dates));
    printf("The sorted list of given dates are: \n");
    for (int i = 0; i < counter; i++)
    {
        printf("%s\n", dates[i]);
    }
}