/*Define a structure Book with title (string), author(string), and 
pages (integer). 
Write a program that dynamically allocates an array of 5 Book structures,
initializes them with user input, and then prints the details of all 
books.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    int pages;
} Book;

int main() {
    int n;
    printf("enter total number of books");
    scanf("%d",n);
    Book *books = (Book *)malloc(n * sizeof(Book));
    for (int i = 0; i < n; i++) {
        printf("Enter title: ");
        scanf(" %[^\n]", books[i].title);
        printf("Enter author: ");
        scanf(" %[^\n]", books[i].author);
        printf("Enter pages: ");
        scanf("%d", &books[i].pages);
    }
    for (int i = 0; i < n; i++) {
        printf("Book %d\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
    }
    free(books);
return 0;
}