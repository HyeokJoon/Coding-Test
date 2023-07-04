/**
 * Project Untitled
 */

#ifndef _CREATEUSERACCOUNT_H
#define _CREATEUSERACCOUNT_H
#include <stdio.h>

// 파일 입출력을 위한 초기화

class CreateUserAccount
{
private:
    // FILE *out_fp = fopen("output.txt", "w+");

public:
    CreateUserAccount();
    void showResultMessage(char *name, char *personalID, char *ID, char *password);
};

#endif //_CREATEUSERACCOUNT_H