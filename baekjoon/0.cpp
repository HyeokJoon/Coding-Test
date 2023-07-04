#include <stdio.h>

int main()
{
    printf("<영화 예매 프로그램>\n\n");
    printf("\t\t 영화제목\n");
    printf("------------------------------------------------\n");
    char c = 'A';
    for (int i = 1; i < 10; i++)
    {
        printf("|");
        for (int j = 1; j < 10; j++)
        {
            printf(" %c%d |", c, j);
        }
        c++;
        printf("\n");
    }
    printf("\n");
    printf("------------------------------------------------\n");
}