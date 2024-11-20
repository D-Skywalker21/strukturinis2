#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char ALPHABET[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

// Encrypt function using Vigenere cipher
void vigenereEncrypt(char text[], char key[], char result[]) {
    int textLength = strlen(text);
    int keyLength = strlen(key);
    int k = 0;

    for (int i = 0; i < textLength; i++) {
        if (isalpha(text[i])) {
            // Convert the text character to uppercase
            char textChar = toupper(text[i]);
            char keyChar = toupper(key[k % keyLength]);

            // Find the positions of the letters in the alphabet
            int m = textChar - 'A';
            int r = keyChar - 'A';

            // Encrypt the character
            int c = (m + r) % 26;
            result[i] = ALPHABET[c];

            k++;  // Move to the next character in the key
        } else {
            result[i] = text[i];  // Non-alphabetic characters remain unchanged
        }
    }
    result[textLength] = '\0';  // Null-terminate the result string
}

// Decrypt function using Vigenere cipher
void vigenereDecrypt(char encryptedText[], char key[], char decryptedText[]) {
    int encryptedTextLength = strlen(encryptedText);
    int keyLength = strlen(key);
    int l = 0;

    for (int i = 0; i < encryptedTextLength; i++) {
        if (isalpha(encryptedText[i])) {
            // Convert the encrypted character to uppercase
            char encryptedChar = toupper(encryptedText[i]);
            char keyChar = toupper(key[l % keyLength]);

            // Find the positions of the letters in the alphabet
            int c = encryptedChar - 'A';
            int r = keyChar - 'A';

            // Decrypt the character
            int m = (c - r + 26) % 26;
            decryptedText[i] = ALPHABET[m];

            l++;  // Move to the next character in the key
        } else {
            decryptedText[i] = encryptedText[i];  // Non-alphabetic characters remain unchanged
        }
    }
    decryptedText[encryptedTextLength] = '\0';  // Null-terminate the decrypted text
}

int main() {
    char text[50];
    char result[50];
    char encryptedText[50];
    char decryptedText[50];
    char key[50];

    // Open the file and read the input text
    ifstream inputFile;
    inputFile.open("input.txt");
    inputFile.getline(text, 50);  // Read the text
    inputFile.close();

    cout << "Enter encryption key: ";
    cin >> key;  // Enter the encryption key

    // Encrypt the text
    vigenereEncrypt(text, key, result);
    cout << "Encrypted text: " << result << endl;

    // Save the encrypted text to a file
    ofstream resultFile;
    resultFile.open("result.txt");
    resultFile << result;
    resultFile.close();

    // Read the encrypted text from the file
    ifstream decryptFile;
    decryptFile.open("result.txt");
    decryptFile.getline(encryptedText, 50);  // Read the encrypted text
    decryptFile.close();

    // Decrypt the text
    vigenereDecrypt(encryptedText, key, decryptedText);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}