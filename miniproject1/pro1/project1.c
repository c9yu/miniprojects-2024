/*
File: project1.c

Created : 24 - 03 - 13

Author : ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 20

void check(char* cid, char* cpw)
{
    if (strcmp(cid, "abcd") == 0) {    // c���� ���ڿ� �񱳴� strcmp ���
        if (strcmp(cpw, "1234") == 0) {  // ���� ��� 0�� ��µȴ�.
            // myinfo ���� ����
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
            printf("pw�� ��ġ���� �ʽ��ϴ�.\n");
        }
    }
    else {
        printf("id�� ��ġ���� �ʽ��ϴ�.\n");
    }
}

void main()
{
    char id[MAX_LENGTH];
    char pw[MAX_LENGTH];

    printf("id�� �Է��ϼ���: ");
    scanf("%s", id);

    printf("pw�� �Է��ϼ���: ");
    scanf("%s", pw);

    check(id, pw);

}
