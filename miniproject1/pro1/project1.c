/*
File: project1.c

Created : 24 - 03 - 13

Author : 이찬규
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 20

void check(char* cid, char* cpw)
{
    if (strcmp(cid, "abcd") == 0) {    // c에서 문자열 비교는 strcmp 사용
        if (strcmp(cpw, "1234") == 0) {  // 같은 경우 0이 출력된다.
            // myinfo 파일 열기
            char checkidpw[MAX_LENGTH];
            FILE* fp;
            if ((fp = fopen("myinfo.txt", "r")) == NULL) {
                fprintf(stderr, "ERROR");
                exit(1);
            }
            fscanf(fp, "%s", checkidpw);
            printf("%s\n", checkidpw);

            fclose(fp);
        }
        else {
            printf("pw가 일치하지 않습니다.\n");
        }
    }
    else {
        printf("id가 일치하지 않습니다.\n");
    }
}

void main()
{
    char id[MAX_LENGTH];
    char pw[MAX_LENGTH];

    printf("id를 입력하세요: ");
    scanf("%s", id);

    printf("pw를 입력하세요: ");
    scanf("%s", pw);

    check(id, pw);

}
