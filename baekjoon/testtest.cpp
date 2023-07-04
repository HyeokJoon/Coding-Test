#include <stdio.h>
void print_binary(int x);

int main()
{
    int x = 10;
    int arr[5] = {0, 1, 2, 3, 4};
    int *ptr = arr;

    printf("%d\n", *ptr);
}

void print_binary(int x)
{
    if (x > 0)
    {
        print_binary(x / 2);
        printf("%d", x % 2);
    }
    printf("\n%d", x);
}