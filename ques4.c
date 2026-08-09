#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char str[100], clean[100];
    int j = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str); // Reads string including spaces until newline

    // Step 1: Remove spaces and convert to lowercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            clean[j++] = tolower(str[i]);
        }
    }
    clean[j] = '\0'; // Null-terminate the cleaned string

    // Step 2: Check if the clean string is a palindrome
    int len = strlen(clean);
    int isPalindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (clean[i] != clean[len - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}