/*
File: project2v2.c

Created: 24-03-27

Author: 이찬규
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

      // 메뉴를 반복하여 출력하고, 사용자의 선택에 따라 동작 수행
    while (1) {
        printMenu();
        printf("메뉴를 선택하세요: \n");
        scanf("%d", &choice); // break 반복 횟수가 정해져 있더라도
        // 바로 반복문을 빠져나가게 한다.
        if (choice == 1) {
            printf("도서 제목을 입력하세요:");
            scanf("%s", btitle);
            printf("도서 ID를 입력하세요:");
            scanf("%d", &id);
            printf("도서 작가를 입력하세요:");
            scanf("%s", author);
            printf("도서 출판사를 입력하세요:");
            scanf("%s", publisher);
            addBook(head, btitle, id, author, publisher);
        }

        else if (choice == 2) {
            printMenu2();
            printf("검색할 방법을 선택하세요.: ");
            scanf("%d", &choice2);
            if (choice2 == 1) {
                printf("검색할 도서의 제목을 입력하세요: ");
                scanf("%s", btitle);
                searchtitle(btitle, head);
            }
            if (choice2 == 2) {
                printf("검색할 도서의 ID를 입력하세요: ");
                scanf("%d", &id);
                searchid(id, head);
            }
            if (choice2 == 3) {
                printf("검색할 도서의 작가를 입력하세요: ");
                scanf("%s", author);
                searchauthor(author, head);
            }
            if (choice2 == 4) {
                printf("검색할 도서의 출판사를 입력하세요: ");
                scanf("%s", publisher);
                searchpublisher(publisher, head);
            }
        }

        else if (choice == 3) {
            printf("삭제할 도서의 id를 입력하세요: \n");
            scanf("%d", &id); // scanf에서 &를 사용하지 않으면 segmentation fault 에러가 발생 하기도 한다.
            deleteBook(id, head);
        }

        else if (choice == 4) {
            printBooks(head);
        }

        else if (choice == 5) {
            printf("대여하고자 하는 책의 id를 입력해 주세요: ");
            scanf("%d", &id);
            printf("대여를 위해 대여자명을 입력해 주세요: ");
            scanf("%s", renter);
            rentbook(id, renter, head);
        }

        else if (choice == 6) {
            printf("반납하고자 하는 책의 id를 입력해 주세요: ");
            scanf("%d", &id);
            printf("반납을 위해 대여자명을 입력해 주세요: ");
            scanf("%s", renter);
            returnbook(id, renter, head);
        }

        else if (choice == 0) {
            printf("프로그램을 종료합니다.\n");
            exit(0);
        }

        else {
            printf("잘못된 입력입니다.\n");
        }
    }
    return 0;
}
