#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";

    // Concatenation without strcat
    int len1 = 0;
    while (str1[len1] != '\0') len1++;
    int len2 = 0;
    while (str2[len2] != '\0') len2++;
    for (int i = 0; i < len2; i++) {
        str1[len1 + i] = str2[i];
    }
    str1[len1 + len2] = '\0';
    printf("Concatenated string (without strcat): %s\n", str1);

    // Length without strlen
    int length = 0;
    while (str1[length] != '\0') {
        length++;
    }
    printf("Length of concatenated string (without strlen): %d\n", length);

    // Copy without strcpy
    char str3[20];
    int i = 0;
    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }
    str3[i] = '\0';
    printf("Copied string (without strcpy): %s\n", str3);

    // Comparison without strcmp
    int cmp = 0;
    for (int j = 0; str1[j] != '\0' || str2[j] != '\0'; j++) {
        if (str1[j] != str2[j]) {
            cmp = str1[j] - str2[j];
            break;
        }
    }
    if (cmp == 0) {
        printf("Strings are equal (without strcmp).\n");
    } else if (cmp > 0) {
        printf("str1 is greater than str2 (without strcmp).\n");
    } else {
        printf("str1 is less than str2 (without strcmp).\n");
    }

    // Reset strings for standard functions
    strcpy(str1, "Hello");
    strcpy(str2, "World");

    // Concatenation with strcat
    strcat(str1, str2);
    printf("Concatenated string (with strcat): %s\n", str1);

    // Length with strlen
    length = strlen(str1);
    printf("Length of concatenated string (with strlen): %d\n", length);

    // Copy with strcpy
    strcpy(str3, str1);
    printf("Copied string (with strcpy): %s\n", str3);

    // Comparison with strcmp
    cmp = strcmp(str1, str2);
    if (cmp == 0) {
        printf("Strings are equal (with strcmp).\n");
    } else if (cmp > 0) {
        printf("str1 is greater than str2 (with strcmp).\n");
    } else {
        printf("str1 is less than str2 (with strcmp).\n");
    }

    return 0;
}
 