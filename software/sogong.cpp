// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <cstring>
// #include <User.h>
// #include <Client.h>
// #include <Company.h>
#include "CreateUserAccountUI.h"
#include "CreateCompAccountUI.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void program_exit();

// // 변수 선언
// FILE *in_fp, *out_fp;

int main()
{
    // // 파일 입출력을 위한 초기화
    // in_fp = fopen("input.txt", "r+");
    // out_fp = fopen("output.txt", "w+");

    // ...

    doTask();

    // ...

    return 0;
}

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        freopen("software/input.txt", "r", stdin);
        freopen("software/output.txt", "w", stdout);
        // fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        scanf("%d %d", &menu_level_1, &menu_level_2);

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1: // "1.1. 회원가입“ 메뉴 부분
            {
                // join() 함수에서 해당 기능 수행
                join();

                break;
            }
            case 2:
            {
                // ...
                break;
            }
            }
        // ....
        case 7:
        {
            switch (menu_level_2)
            {
            case 1: // "6.1. 종료“ 메뉴 부분
            {
                // ..
                program_exit();
                is_program_exit = 1;
                break;
                ;
            }
            }
        }

            // .......

            return;
        }
        }
    }
}
void join()
{
    /*            !!!!!!!       중요        !!!!!!!!!
     * 단순히 파일을 통해 입출력하는 방법을 보이기 위한 코드이므로 이 함수에서 그대로 사용하면 안됨.
     * control 및 boundary class를 이용해서 해당 기능이 구현되도록 해야 함.
     */
    CreateUserAccountUI Boundary_cua;
    CreateCompAccountUI Boundary_cca;

    int cmp;
    char user_type[MAX_STRING], name[MAX_STRING], personalID[MAX_STRING],
        ID[MAX_STRING], password[MAX_STRING];

    // fscanf(in_fp, "%d", &cmp);
    scanf("%d", &cmp);
    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    scanf("%s %s %s %s", name, personalID, ID, password);
    // fscanf(in_fp, "%s %s %s %s", name, personalID, ID, password);

    // 해당 기능 수행
    if (cmp == 1)
    {
        Boundary_cca.createAccount(name, personalID, ID, password);
    }
    else if (cmp == 2)
    {
        Boundary_cua.createAccount(name, personalID, ID, password);
    }
    //    ...

    // // 출력 형식
    // printf("1.1. 회원가입\n");
    // printf("%s %s %s %s\n", name, personalID, ID, password);
    // fprintf(out_fp, "1.1. 회원가입\n");
    // fprintf(out_fp, "%s %s %s %s\n", name, personalID, ID, password);
}

void program_exit()
{
    // ....
}
