/*
File: project2.h

Created: 24-03-27

Author: ÀÌÂù±Ô
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
	char title[100];
	int id;
	char author[100];
	char publisher[100];
	char renter[100];
	struct Book* next;
}book;

typedef struct HEADNODE {
	book* head;
}headnode;

headnode* createhead();


void addBook(headnode* h, char* title, int id, char* author, char* publisher);
void searchtitle(char* title, headnode* h);
void searchid(int id, headnode* h);
void searchauthor(char* author, headnode* h);
void searchpublisher(char* publisher, headnode* h);
void rentbook(int id, char* renter, headnode* h);
void returnbook(int id, char* renter, headnode* h);
void deleteBook(int id, headnode* h);
void printBooks(headnode* h);
void printMenu();
void printMenu2();

