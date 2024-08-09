/*
File: project2func.c

Created: 24-03-27

Author: 이찬규
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

// 도서 등록 함수
void addBook(headnode* h, char* title, int id, char* author, char* publisher) {
    // 새로운 노드를 동적 할당하여 생성
    book* newBook = (struct Book*)malloc(sizeof(struct Book));
    // 제목과 id를 설정, 다음 노드를 현재의 head로 설정
    strcpy(newBook->title, title);
    newBook->id = id;
    strcpy(newBook->author, author);
    strcpy(newBook->publisher, publisher);
    newBook->next = NULL;
    strcpy(newBook->renter, "none");
    // head를 새로운 노드로 갱신해 새로운 도서가 첫 번째에 추가되도록 함.
    if (h->head == NULL)
    {
        h->head = newBook;
        printf("첫번째 책\n");
    } //return;
    else
    {
        book* temp = h->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newBook;
        printf("두번째이상 책\n");
    }
}

// 도서 검색 함수

void searchtitle(char* title, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    // 연결 리스트를 순회하며 도서 ID가 일치하는지 확인
    printf("\n");
    printf("도서명: %s 로 검색된 도서들을 출력하겠습니다.", title);
    printf("\n");
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            printf("\n");
            printf("도서명: %s, 도서ID: %d, 작가: %s, 출판사: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\n찾으시는 도서가 존재하지 않습니다.");
    }
}

void searchid(int id, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    printf("\n");
    printf("ID: %d 로 검색된 도서들을 출력하겠습니다.", id);
    printf("\n");
    while (current != NULL) {
        if (current->id == id) {
            printf("\n");
            printf("도서명: %s, 도서ID: %d, 작가: %s, 출판사: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\n찾으시는 도서가 존재하지 않습니다.");
    }
}

void searchauthor(char* author, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    printf("\n");
    printf("작가: %s 로 검색된 도서들을 출력하겠습니다.", author);
    printf("\n");
    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
            printf("\n");
            printf("도서명: %s, 도서ID: %d, 작가: %s, 출판사: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\n찾으시는 도서가 존재하지 않습니다.");
    }
}

void searchpublisher(char* publisher, headnode* h) {
    struct Book* current = h->head;
    int i = 0;
    printf("\n");
    printf("출판사: %s 로 검색된 도서들을 출력하겠습니다.", publisher);
    printf("\n");
    while (current != NULL) {
        if (strcmp(current->publisher, publisher) == 0) {
            printf("\n");
            printf("도서명: %s, 도서ID: %d, 작가: %s, 출판사: %s",
                current->title, current->id, current->author, current->publisher);
            i++;
        }
        current = current->next;
    }
    if (i == 0) {
        printf("\n찾으시는 도서가 존재하지 않습니다.");
    }
}
// 도서 대여 함수
void rentbook(int id, char* renter, headnode* h) {
    struct Book* current = h->head;
    int select;
    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "none") == 0) {
                printf("\n대여 가능한 책입니다\n");
                printf("\n대여 하시겠습니까? 네:1 /아니오:0\n");
                scanf("%d", &select);

                if (select == 1) {
                    strcpy(current->renter, renter); // renter 입력받기
                    printf("\n%s 대여 완료했습니다.", current->title);
                }

                else if (select == 0) {
                    printf("\n대여하지 않겠습니다.");
                    //return;
                }

                else {
                    //return;
                }
            }

            else {
                printf("\n해당 도서는 이미 대여중입니다.\n");
            }
            return;
        }
        current = current->next;
    }
    printf("\n해당 도서를 찾을 수 없습니다.\n");
}


// 도서 반납 함수
void returnbook(int id, char* renter, headnode* h) {
    struct Book* current = h->head;

    while (current != NULL) {
        if (current->id == id) {
            if (strcmp(current->renter, "none") != 0) {
                strcpy(current->renter, "none");
                printf("\n%s 가 반납되었습니다.", current->title);

            }
            else {
                printf("\n%s 는 이미 반납되었습니다.", current->title);
            }
            return;
        }
        current = current->next;
    }
    printf("\n해당 도서를 찾을 수 없습니다.\n");
}

// 도서 삭제 함수
void deleteBook(int id, headnode* h) {
    struct Book* current = h->head;
    struct Book* prev = NULL;

    // 연결 리스트를 순회하며 삭제할 도서를 찾음
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                // 삭제할 노드가 첫 번째 노드인 경우 head를 다음 노드로 갱신
                h->head = current->next;
            }
            else {
                // 이전 노드의 next를 삭제할 노드의 next로 연결하여 노드 삭제
                prev->next = current->next;
            }
            free(current); // 메모리 해제
            printf("도서 삭제 완료\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("해당 도서를 찾을 수 없습니다.\n");
}

// 도서 목록 출력 함수
void printBooks(headnode* h) {
    book* current = h->head;
    //  printf("-----1-----\n");
    //  printf("도서 제목: %s", current->title);
    //  printf("도서 ID: %d\n",current->id);


    if (current == NULL) {
        printf("도서가 없습니다.\n");
        return;
    }

    printf("도서 목록\n");
    while (current != NULL) {
        printf("도서 제목: %s", current->title);
        printf(" 도서 ID: %d", current->id);
        printf(" 도서 작가: %s", current->author);
        printf(" 도서 출판사: %s\n", current->publisher);
        current = current->next;
    }

}

// 메뉴 출력 함수
void printMenu() {
    printf("\n");
    printf("\n*****메뉴*****\n");
    printf("1. 도서 구입(등록)\n");
    printf("2. 도서 검색\n");
    printf("3. 도서 삭제\n");
    printf("4. 도서 출력\n");
    printf("5. 도서 대여\n");
    printf("6. 도서 반납\n");
    printf("0. 종료\n");
    printf("**************\n");
    printf("\n");
}

void printMenu2() {
    printf("\n");
    printf("\n*****메뉴*****\n");
    printf("1. 제목\n");
    printf("2. ID\n");
    printf("3. 작가\n");
    printf("4. 출판사\n");
    printf("**************\n");
    printf("\n");
}

