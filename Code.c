#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift) {
    int i;
    char c;
    for (i = 0; i < strlen(text); i++) {
        c = text[i];
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + shift) % 26;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + shift) % 26;
        }
        text[i] = c;
    }
}

void decrypt(char *text, int shift) {
    int i;
    char c;
    for (i = 0; i < strlen(text); i++) {
        c = text[i];
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' - shift + 26) % 26;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' - shift + 26) % 26;
        }
        text[i] = c;
    }
}

int main() {
    char text[100];
    int shift, choice;
    printf("Enter the text to encrypt/decrypt: ");
    fgets(text, 100, stdin);
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    while (1) {
        printf("Enter 1 to encrypt, 2 to decrypt, or 3 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            encrypt(text, shift);
            printf("Encrypted text: %s\n", text);
        }
        else if (choice == 2) {
            decrypt(text, shift);
            printf("Decrypted text: %s\n", text);
        }
        else if (choice == 3) {
            printf("Exiting...\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
