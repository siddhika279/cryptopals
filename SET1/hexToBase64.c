#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal character to its integer value
int hexCharToInt(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return -1;  // Invalid character
}

// Function to convert a hexadecimal string to binary string
void hexToBinary(const char* hexString, char* binaryString) {
    int i, j = 0;
    for (i = 0; i < strlen(hexString); i++) {
        int val = hexCharToInt(hexString[i]);
        binaryString[j++] = (val & 8) ? '1' : '0';
        binaryString[j++] = (val & 4) ? '1' : '0';
        binaryString[j++] = (val & 2) ? '1' : '0';
        binaryString[j++] = (val & 1) ? '1' : '0';
    }
    binaryString[j] = '\0';
}

// Function to convert a binary string to base64
void binaryToBase64(const char* binaryString, char* base64String) {
    const char* base64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    int i, j = 0;
    for (i = 0; i < strlen(binaryString); i += 6) {
        int val = 0;
        int k;
        for (k = 0; k < 6; k++) {
            val <<= 1;
            if (binaryString[i + k] == '1')
                val |= 1;
        }
        base64String[j++] = base64chars[val];
    }

    // Padding
    while (j % 4 != 0) {
        base64String[j++] = '=';
    }
    base64String[j] = '\0';
}

int main() {
    const char* hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    char binaryString[1000];
    char base64String[1000];

    hexToBinary(hexString, binaryString);
    binaryToBase64(binaryString, base64String);

    printf("Base64: %s\n", base64String);

    return 0;
}
