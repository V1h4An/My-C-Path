        #include <stdio.h>
#include <string.h>

// Function to perform naive pattern matching
void naivePatternMatching(char *text, char *pattern) {
    int n = strlen(text);     // Length of the text
    int m = strlen(pattern);  // Length of the pattern

    // Slide the pattern over the text one character at a time
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check if the pattern matches the substring of the text starting at position i
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If the pattern matches, print the starting index
        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[] = "abcabcabc";
    char pattern[] = "abc";

    naivePatternMatching(text, pattern);
    return 0;
}
