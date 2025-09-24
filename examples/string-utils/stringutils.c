#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Reverse a string in place
void reverse_string(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

// Check if a string is a palindrome
int is_palindrome(const char *s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return 0; // not palindrome
        }
        left++;
        right--;
    }
    return 1; // palindrome
}

// Count the number of vowels in a string
int count_vowels(const char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// Convert string to uppercase
void to_uppercase(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = toupper(s[i]);
    }
}

// Apply a Caesar cipher with given shift
void caesar_cipher(char *s, int shift) {
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            char base = islower(s[i]) ? 'a' : 'A';
            s[i] = (s[i] - base + shift) % 26 + base;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <operation> <string> [shift]\n", argv[0]);
        printf("Operations: reverse, palindrome, vowels, uppercase, caesar\n");
        return 1;
    }

    char *operation = argv[1];
    char str[256];
    strncpy(str, argv[2], sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';

    if (strcmp(operation, "reverse") == 0) {
        reverse_string(str);
        printf("%s\n", str);

    } else if (strcmp(operation, "palindrome") == 0) {
        printf("%s\n", is_palindrome(str) ? "Yes" : "No");

    } else if (strcmp(operation, "vowels") == 0) {
        printf("%d\n", count_vowels(str));

    } else if (strcmp(operation, "uppercase") == 0) {
        to_uppercase(str);
        printf("%s\n", str);

    } else if (strcmp(operation, "caesar") == 0) {
        if (argc < 4) {
            printf("Error: caesar requires a shift value.\n");
            return 1;
        }
        int shift = atoi(argv[3]);
        caesar_cipher(str, shift);
        printf("%s\n", str);

    } else {
        printf("Unknown operation: %s\n", operation);
        return 1;
    }

    return 0;
}
