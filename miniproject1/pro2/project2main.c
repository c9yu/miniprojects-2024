/*
File: project2v2.c

Created: 24-03-27

Author: ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2.h"

int main() {
    int choice;
    int choice2;
    int id;
    char renter[100];
    char btitle[100];
    char author[100];
    char publisher[100];
    headnode* head = createhead();
    //  head = NULL;

      // �޴��� �ݺ��Ͽ� ����ϰ�, ������� ���ÿ� ���� ���� ����
    while (1) {
        printMenu();
        printf("�޴��� �����ϼ���: \n");
        scanf("%d", &choice); // break �ݺ� Ƚ���� ������ �ִ���
        // �ٷ� �ݺ����� ���������� �Ѵ�.
        if (choice == 1) {
            printf("���� ������ �Է��ϼ���:");
            scanf("%s", btitle);
            printf("���� ID�� �Է��ϼ���:");
            scanf("%d", &id);
            printf("���� �۰��� �Է��ϼ���:");
            scanf("%s", author);
            printf("���� ���ǻ縦 �Է��ϼ���:");
            scanf("%s", publisher);
            addBook(head, btitle, id, author, publisher);
        }

        else if (choice == 2) {
            printMenu2();
            printf("�˻��� ����� �����ϼ���.: ");
            scanf("%d", &choice2);
            if (choice2 == 1) {
                printf("�˻��� ������ ������ �Է��ϼ���: ");
                scanf("%s", btitle);
                searchtitle(btitle, head);
            }
            if (choice2 == 2) {
                printf("�˻��� ������ ID�� �Է��ϼ���: ");
                scanf("%d", &id);
                searchid(id, head);
            }
            if (choice2 == 3) {
                printf("�˻��� ������ �۰��� �Է��ϼ���: ");
                scanf("%s", author);
                searchauthor(author, head);
            }
            if (choice2 == 4) {
                printf("�˻��� ������ ���ǻ縦 �Է��ϼ���: ");
                scanf("%s", publisher);
                searchpublisher(publisher, head);
            }
        }

        else if (choice == 3) {
            printf("������ ������ id�� �Է��ϼ���: \n");
            scanf("%d", &id); // scanf���� &�� ������� ������ segmentation fault ������ �߻� �ϱ⵵ �Ѵ�.
            deleteBook(id, head);
        }

        else if (choice == 4) {
            printBooks(head);
        }

        else if (choice == 5) {
            printf("�뿩�ϰ��� �ϴ� å�� id�� �Է��� �ּ���: ");
            scanf("%d", &id);
            printf("�뿩�� ���� �뿩�ڸ��� �Է��� �ּ���: ");
            scanf("%s", renter);
            rentbook(id, renter, head);
        }

        else if (choice == 6) {
            printf("�ݳ��ϰ��� �ϴ� å�� id�� �Է��� �ּ���: ");
            scanf("%d", &id);
            printf("�ݳ��� ���� �뿩�ڸ��� �Է��� �ּ���: ");
            scanf("%s", renter);
            returnbook(id, renter, head);
        }

        else if (choice == 0) {
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        }

        else {
            printf("�߸��� �Է��Դϴ�.\n");
        }
    }
    return 0;
}
