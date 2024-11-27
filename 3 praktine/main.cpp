#include <iostream>
#include <cstring>
using namespace std;

const char Alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const int ASCII_MIN = 33, ASCII_MAX = 126;
const int ASCII_RANGE = ASCII_MAX - ASCII_MIN + 1;

int findAlphabetIndex(char letter) {
    letter = toupper(letter);
    for (int i = 0; i < 26; i++) {
        if (Alphabet[i] == letter) {
            return i;
        }
    }
    return -1;
}

int findAsciiIndex(char character) {
    return static_cast<int>(character) - ASCII_MIN;
}

char getAlphabetChar(int index) {
    return Alphabet[index % 26];
}

char getAsciiChar(int index) {
    return static_cast<char>(index + ASCII_MIN);
}

void VigenereEncrypt(bool isAlphabet, const char key[], const char input[]) {
    int key_len = strlen(key);
    int input_len = strlen(input);
    char extended_key[input_len];

    for (int i = 0; i < input_len; i++) {
        extended_key[i] = key[i % key_len];
    }

    char result[input_len];

    for (int i = 0; i < input_len; i++) {
        char currentChar = input[i];
        char keyChar = extended_key[i];
        int newIndex;

        if (isAlphabet) {
            int currentIndex = findAlphabetIndex(currentChar);
            int keyIndex = findAlphabetIndex(keyChar);

            if (currentIndex == -1 || keyIndex == -1) {
                result[i] = currentChar;
                continue;
            }

            newIndex = (currentIndex + keyIndex) % 26;
            result[i] = getAlphabetChar(newIndex);
        } else {
            int currentIndex = findAsciiIndex(currentChar);
            int keyIndex = findAsciiIndex(keyChar);

            newIndex = (currentIndex + keyIndex) % ASCII_RANGE;
            result[i] = getAsciiChar(newIndex);
        }
    }

    cout << "Uzsifruotas zodis: ";
    for (int i = 0; i < input_len; i++) {
        cout << result[i];
    }
    cout << endl;
}

void VigenereDecrypt(bool isAlphabet, const char key[], const char input[]) {
    int key_len = strlen(key);
    int input_len = strlen(input);
    char extended_key[input_len];

    for (int i = 0; i < input_len; i++) {
        extended_key[i] = key[i % key_len];
    }

    char result[input_len];

    for (int i = 0; i < input_len; i++) {
        char currentChar = input[i];
        char keyChar = extended_key[i];
        int newIndex;

        if (isAlphabet) {
            int currentIndex = findAlphabetIndex(currentChar);
            int keyIndex = findAlphabetIndex(keyChar);

            if (currentIndex == -1 || keyIndex == -1) {
                result[i] = currentChar;
                continue;
            }

            newIndex = (currentIndex - keyIndex + 26) % 26;
            result[i] = getAlphabetChar(newIndex);
        } else {
            int currentIndex = findAsciiIndex(currentChar);
            int keyIndex = findAsciiIndex(keyChar);

            newIndex = (currentIndex - keyIndex + ASCII_RANGE) % ASCII_RANGE;
            result[i] = getAsciiChar(newIndex);
        }
    }

    cout << "Desifruotas zodis: ";
    for (int i = 0; i < input_len; i++) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int option;
    while (true) {
        cout << "1. Sifravimas" << endl;
        cout << "2. Desifravimas" << endl;
        cout << "3. Isejimas" << endl;
        cout << "Pasirinkite: ";
        cin >> option;

        if (option == 3) break;

        bool isAlphabet;
        cout << "Pasirinkite sifravimo/desifravimo buda: " << endl;
        cout << "1. Abecele" << endl;
        cout << "2. ASCII" << endl;
        int methodOption;
        cin >> methodOption;

        if (methodOption == 1) {
            isAlphabet = true;
        } else if (methodOption == 2) {
            isAlphabet = false;
        } else {
            cout << "Klaida! Pasirinkite teisingą metodą." << endl;
            continue;
        }

        char key[50], input[50];
        cout << "Iveskite rakta: ";
        cin >> key;
        cout << "Iveskite pradini zodi: ";
        cin >> input;

        if (option == 1) {
            VigenereEncrypt(isAlphabet, key, input);
        } else if (option == 2) {
            VigenereDecrypt(isAlphabet, key, input);
        }
    }

    return 0;
}