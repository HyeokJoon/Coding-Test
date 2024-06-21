#include <stdio.h>

int main(){
    int p[3] = {1,2,3};
    printf("%p %p \n", p, &p[1]);
    printf("%d %d %d\n", *p , *(p+1), *(p+2));


    printf("---------------------------\n");

    int p2[3][2] = {{1,2},{3,4},{5,6}};

    printf("%p %p \n", p2+1, *p2+1);
    printf("%d\n", **p2);

    printf("%d\n", *(*(p2+1)+1));


}