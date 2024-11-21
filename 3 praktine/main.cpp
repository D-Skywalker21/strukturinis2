#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string vigenereEncrypt(const string& text, const string& key) {
    string encryptedText = "";
    int n = 26;

    int KeyIndex = 0;
    for (int i = 0; i < text.length(); i++) {
        char currentLetter = toupper(text[i]);
        if (currentLetter < 'A' || currentLetter > 'Z') {
            encryptedText += currentLetter;
            continue;
        }
        int m = currentLetter - 'A';
        char KeyChar = toupper(key[KeyIndex % key.length()]);
        int k = KeyChar - 'A';
        int c = (m + k) % n;
        encryptedText += 'A' + c;
        KeyIndex++;
    }
    return encryptedText;
}

string vigenereDecrypt(const string& encryptedText, const string& key) {
    string decryptedText = "";
    int n = 26;

    int raktoIndeksas = 0;
    for (int i = 0; i < encryptedText.length(); i++) {
        char currentLetter = toupper(encryptedText[i]);
        if (currentLetter < 'A' || currentLetter > 'Z') {
            continue;
        }

        int c = currentLetter - 'A';
        char raktasChar = toupper(key[raktoIndeksas % key.length()]);
        int k = raktasChar - 'A';
        int m = (c - k + n) % n;

        decryptedText += 'A' + m;
        raktoIndeksas++;
    }
    return decryptedText;
}

string vigenereEncryptAscii(const string& text, const string& key) {
    string encryptedText = "";
    int keyIndex = 0;

    for (int i = 0; i < text.length(); i++) {
        char currentLetter = text[i];

        int m = currentLetter;
        int k = key[keyIndex % key.length()];
        int c = (m + k) % 256;

        encryptedText += char(c);
        keyIndex++;
    }

    return encryptedText;
}

string vigenereDecryptAscii(const string& encryptedText, const string& key) {
    string decryptedText = "";
    int keyIndex = 0;

    for (int i = 0; i < encryptedText.length(); i++) {
        char currentLetter = encryptedText[i];

        int c = currentLetter;
        int k = key[keyIndex % key.length()];
        int m = (c - k + 256) % 256;

        decryptedText += char(m);
        keyIndex++;
    }

    return decryptedText;
}

int main() {

    int choice = 1;

    string text, key;
    while (choice != 3) {
        cout << "Vigenere sifravimo programa" << endl;
        cout << "Pasirinkite opcija:" << endl;
        cout << "1. Sifruoti/Desifruoti naudojant anglu abecele" << endl;
        cout << "2. Sifruoti/Desifruoti naudojant ASCII vertes" << endl;
        cout << "Pasirinkite (1 ar 2): ";

        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Iveskite ka norite uzsifruoti/desifruoti: ";
            getline(cin, text);
            cout << "Iveskite rakta: ";
            getline(cin, key);

            int action;
            cout << "Pasirinkite veiksma (1 - uzsifruoti, 2 - desifruoti): ";
            cin >> action;

            if (action == 1) {
                string encryptedText = vigenereEncrypt(text, key);
                cout << "Uzsifruotas tekstas: " << encryptedText << endl;
            } else if (action == 2) {
                string decryptedText = vigenereDecrypt(text, key);
                cout << "Desifruotas tekstas: " << decryptedText << endl;
            }
        } else if (choice == 2) {
            cout << "Iveskite ka norite uzsifruoti/desifruoti: ";
            getline(cin, text);
            cout << "Iveskite rakta: ";
            getline(cin, key);

            int action;
            cout << "Pasirinkite veiksma (1 - uzsifruoti, 2 - desifruoti): ";
            cin >> action;

            if (action == 1) {
                string encryptedText = vigenereEncryptAscii(text, key);
                cout << "Uzsifruotas tekstas: " << encryptedText << endl;
            } else if (action == 2) {
                string decryptedText = vigenereDecryptAscii(text, key);
                cout << "Desifruotas tekstas: " << decryptedText << endl;
            }
        } else {
            cout << "Klaida!" << endl;
        }
    }
    return 0;
}