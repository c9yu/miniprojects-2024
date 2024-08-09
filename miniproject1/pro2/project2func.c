/*
File: project2func.c

Created: 24-03-27

Author: ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project2.h"

headnode* createhead()
{
    headnode* h = malloc(sizeof(book));
    h->head = NULL;
    return h;
}

// ���� ��� �Լ�
void addBook(headnode* h, char* title, int id, char* author, char* publisher) {
    // ���ο� ��带 ���� �Ҵ��Ͽ� ����
    book* newBook = (struct Book*)malloc(sizeof(struct Book));
    // ����� id�� ����, ���� ��带 ������ head�� ����
    strcpy(newBook->title, title);
    newBook->id = id;
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    newBook->next = NULL;
    strcpy(newBook->renter, "none");
    // head�� ���ο� ���� ������ ���ο� ������ ù ��°�� �߰��ǵ��� ��.
    if (h->head == NULL)
    {
        h->head = newBook;
        printf("ù��° å\n");
    } //return;
    else
    {
        book* temp = h->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newBook;
        printf("�ι�°�̻� å\n");
    }
}

// ���� �˻� �Լ�

void searchtitle(char* title, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    // ���� ����Ʈ�� ��ȸ�ϸ� ���� ID�� ��ġ�ϴ��� Ȯ��
    printf("\n");
    printf("������: %s �� �˻��� �������� ����ϰڽ��ϴ�.", title);
    printf("\n");
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("\n");
            printf("������: %s, ����ID: %d, �۰�: %s, ���ǻ�: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\nã���ô� ������ �������� �ʽ��ϴ�.");
    }
}

void searchid(int id, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    printf("\n");
    printf("ID: %d �� �˻��� �������� ����ϰڽ��ϴ�.", id);
    printf("\n");
    while (current != NULL) {
        if (current->id == id) {
            printf("\n");
            printf("������: %s, ����ID: %d, �۰�: %s, ���ǻ�: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\nã���ô� ������ �������� �ʽ��ϴ�.");
    }
}

void searchauthor(char* author, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    printf("\n");
    printf("�۰�: %s �� �˻��� �������� ����ϰڽ��ϴ�.", author);
    printf("\n");
    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
            printf("\n");
            printf("������: %s, ����ID: %d, �۰�: %s, ���ǻ�: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\nã���ô� ������ �������� �ʽ��ϴ�.");
    }
}

void searchpublisher(char* publisher, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    printf("\n");
    printf("���ǻ�: %s �� �˻��� �������� ����ϰڽ��ϴ�.", publisher);
    printf("\n");
    while (current != NULL) {
        if (strcmp(current->publisher, publisher) == 0) {
            printf("\n");
            printf("������: %s, ����ID: %d, �۰�: %s, ���ǻ�: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\nã���ô� ������ �������� �ʽ��ϴ�.");
    }
}
// ���� �뿩 �Լ�
void rentbook(int id, char* renter, headnode* h) {
    struct Book* current = h->head;
    int select;
    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "none") == 0) {
                printf("\n�뿩 ������ å�Դϴ�\n");
                printf("\n�뿩 �Ͻðڽ��ϱ�? ��:1 /�ƴϿ�:0\n");
                scanf("%d", &select);

                if (select == 1) {
                    strcpy(current->renter, renter); // renter �Է¹ޱ�
                    printf("\n%s �뿩 �Ϸ��߽��ϴ�.", current->title);
                }

                else if (select == 0) {
                    printf("\n�뿩���� �ʰڽ��ϴ�.");
                    //return;
                }

                else {
                    //return;
                }
            }

            else {
                printf("\n�ش� ������ �̹� �뿩���Դϴ�.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("\n�ش� ������ ã�� �� �����ϴ�.\n");
}


// ���� �ݳ� �Լ�
void returnbook(int id, char* renter, headnode* h) {
    struct Book* current = h->head;

    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "none") != 0) {
                strcpy(current->renter, "none");
                printf("\n%s �� �ݳ��Ǿ����ϴ�.", current->title);

            }
            else {
                printf("\n%s �� �̹� �ݳ��Ǿ����ϴ�.", current->title);
            }
            return;
        }
        current = current->next;
    }
    printf("\n�ش� ������ ã�� �� �����ϴ�.\n");
}

// ���� ���� �Լ�
void deleteBook(int id, headnode* h) {
    struct Book* current = h->head;
    struct Book* prev = NULL;

    // ���� ����Ʈ�� ��ȸ�ϸ� ������ ������ ã��
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                // ������ ��尡 ù ��° ����� ��� head�� ���� ���� ����
                h->head = current->next;
            }
            else {
                // ���� ����� next�� ������ ����� next�� �����Ͽ� ��� ����
                prev->next = current->next;
            }
            free(current); // �޸� ����
            printf("���� ���� �Ϸ�\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("�ش� ������ ã�� �� �����ϴ�.\n");
}

// ���� ��� ��� �Լ�
void printBooks(headnode* h) {
    book* current = h->head;
    //  printf("-----1-----\n");
    //  printf("���� ����: %s", current->title);
    //  printf("���� ID: %d\n",current->id);


    if (current == NULL) {
        printf("������ �����ϴ�.\n");
        return;
    }

    printf("���� ���\n");
    while (current != NULL) {
        printf("���� ����: %s", current->title);
        printf(" ���� ID: %d", current->id);
        printf(" ���� �۰�: %s", current->author);
        printf(" ���� ���ǻ�: %s\n", current->publisher);
        current = current->next;
    }

}

// �޴� ��� �Լ�
void printMenu() {
    printf("\n");
    printf("\n*****�޴�*****\n");
    printf("1. ���� ����(���)\n");
    printf("2. ���� �˻�\n");
    printf("3. ���� ����\n");
    printf("4. ���� ���\n");
    printf("5. ���� �뿩\n");
    printf("6. ���� �ݳ�\n");
    printf("0. ����\n");
    printf("**************\n");
    printf("\n");
}

void printMenu2() {
    printf("\n");
    printf("\n*****�޴�*****\n");
    printf("1. ����\n");
    printf("2. ID\n");
    printf("3. �۰�\n");
    printf("4. ���ǻ�\n");
    printf("**************\n");
    printf("\n");
}

