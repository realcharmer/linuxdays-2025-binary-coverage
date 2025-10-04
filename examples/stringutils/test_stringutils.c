#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Helper to run ./stringutils with arguments and capture output
char *run_program(const char *cmd, const char *arg) {
    char full_cmd[256];
    snprintf(full_cmd, sizeof(full_cmd), "./stringutils %s %s", cmd, arg);

    FILE *pipe = popen(full_cmd, "r");
    if (!pipe) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }

    static char buffer[128];
    if (!fgets(buffer, sizeof(buffer), pipe)) {
        perror("no output from program");
        pclose(pipe);
        exit(EXIT_FAILURE);
    }

    pclose(pipe);

    // Remove trailing newline, if any
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
}

void test_reverse(void) {
    char *output = run_program("reverse", "hello");
    assert(strcmp(output, "olleh") == 0);
    printf("test_reverse passed\n");
}

void test_palindrome_yes(void) {
    char *output = run_program("palindrome", "level");
    assert(strcmp(output, "Yes") == 0);
    printf("test_palindrome_yes passed\n");
}

void test_palindrome_no(void) {
    char *output = run_program("palindrome", "world");
    assert(strcmp(output, "No") == 0);
    printf("test_palindrome_no passed\n");
}

int main(void) {
    test_reverse();
    test_palindrome_yes();
    test_palindrome_no();
    printf("All tests passed ✅\n");
    return 0;
}
