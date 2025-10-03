#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Calculate length
int f1_length(const char *str) {
    return (int)strlen(str);
}

// Convert to uppercase
void f2_to_upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Convert to lowercase
void f3_to_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Check for palindrome
int f4_is_palindrome(const char *str) {
    int len = f1_length(str); 
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) return 0;
    }
    return 1;
}

// Print status
void f5_status(const char *mode) {
    printf("mode: %s \n", mode);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <MODE> <string>\n", argv[0]);
        fprintf(stderr, "Modes: all, len, upper, lower, palindrome\n");
        return 1;
    }

    const char *mode = argv[1];
    char *s = strdup(argv[2]);

    if (s == NULL) {
        perror("strdup failed, good luck...");
        return 1;
    }

    f5_status(mode); // Always calls 

    if (strcmp(mode, "all") == 0) {
        printf("Length: %d\n", f1_length(s));
        f2_to_upper(s);
        printf("Upper: %s\n", s);
        f3_to_lower(s);
        printf("Lower: %s\n", s);
        printf("Palindrome: %s\n", f4_is_palindrome(s) ? "Yes" : "No");

    } else if (strcmp(mode, "len") == 0) {
        printf("Length: %d\n", f1_length(s));

    } else if (strcmp(mode, "upper") == 0) {
        f2_to_upper(s);
        printf("Upper: %s\n", s);
        printf("New Len: %d\n", f1_length(s));

    } else if (strcmp(mode, "lower") == 0) {
        f3_to_lower(s);
        printf("Lower: %s\n", s);
        printf("New Len: %d\n", f1_length(s));

    } else if (strcmp(mode, "palindrome") == 0) {
        printf("Palindrome: %s\n", f4_is_palindrome(s) ? "Yes" : "No");
        
    } else {
        printf("Error: Invalid mode.\n");
    }

    free(s);
    return 0;
}
