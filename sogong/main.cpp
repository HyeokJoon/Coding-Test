// ��� ����

#include <stdio.h>
#include <string.h>
#include <cstring>
// #include <User.h>
// #include <Client.h>
// #include <Company.h>
#include "CreateUserAccountUI.h"
#include "CreateCompAccountUI.h"
#include "DeleteAccountUI.h"
#include "LoginUI.h"
#include "LogoutUI.h"
#include "ClientList.h"

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void createAccount();
void deleteAccount();
void login();
void logout();
void program_exit();

// ���� ����
FILE *in_fp, *out_fp;
CreateUserAccountUI Boundary_cua;
CreateCompAccountUI Boundary_cca;
DeleteAccountUI Boundary_delete;
LoginUI Boundary_login;
LogoutUI Boundary_logout;

ClientList clientList;

int main()
{
    // ���� ������� ���� �ʱ�ȭ
    in_fp = fopen("input.txt", "r+");
    out_fp = fopen("output.txt", "w+");

    // ...

    doTask();

    // ...

    return 0;
}

void doTask()
{
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        // fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        scanf("%d %d ", &menu_level_1, &menu_level_2);
        // scanf("%d %d", &menu_level_1, &menu_level_2);

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1: // "1.1. ȸ�����ԡ� �޴� �κ�
            {
                // join() �Լ����� �ش� ��� ����
                createAccount();

                break;
            }
            case 2: // "1.2. ȸ��Ż�� �޴� �κ�
            {
                deleteAccount();
                break;
            }
            }
            break;

        case 2:
        {
            switch (menu_level_2)
            {
            case 1: // "2.1. �α��Ρ� �޴� �κ�
            {
                // login() �Լ����� �ش� ��� ����
                login();
                break;
            }
            case 2: // "2.2. �α׾ƿ��� �޴� �κ�
            {
                logout();
                break;
            }
            }
        }
        break;
        case 7:
        {
            switch (menu_level_2)
            {
            case 1: // "6.1. ���ᡰ �޴� �κ�
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

/*            !!!!!!!       �߿�        !!!!!!!!!
 * �ܼ��� ������ ���� ������ϴ� ����� ���̱� ���� �ڵ��̹Ƿ� �� �Լ����� �״�� ����ϸ� �ȵ�.
 * control �� boundary class�� �̿��ؼ� �ش� ����� �����ǵ��� �ؾ� ��.
 */

// user_type[MAX_STRING],

// �Է� ���� : �̸�, �ֹι�ȣ, ID, Password�� ���Ϸκ��� ����
// fscanf(in_fp, "%d", &cmp);
// fscanf(in_fp, "%s %s %s %s", name, personalID, ID, password);
void createAccount()
{

    int cmp;
    char name[MAX_STRING], personalID[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

    scanf("%d", &cmp);
    scanf("%s %s %s %s", name, personalID, ID, password);

    // �ش� ��� ����
    if (cmp == 1)
    {
        Boundary_cca.createAccount(&clientList, name, personalID, ID, password);
    }
    else if (cmp == 2)
    {
        Boundary_cua.createAccount(name, personalID, ID, password);
    }
}

void deleteAccount()
{
    Boundary_delete.deleteAccount();
}

void login()
{
    char ID[MAX_STRING], password[MAX_STRING];
    scanf("%s %s", ID, password);
    Boundary_login.login(ID, password);
}

void logout()
{
    Boundary_logout.Logout();
}

void program_exit()
{
    // ....
}
