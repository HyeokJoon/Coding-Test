#include <iostream>

int main()
{
    char str[50];
    int idx = 0;

    printf("문자열 입력: ");
    scanf("%s", str);
    printf("\n입력 받은 문자열: %s \n\n", str);

    printf("문자 단위 출력: ");
    while (str[idx] != '\0')
    {
        printf("%c", str[idx]);
        idx++;
    }
    printf("\n\n");
}