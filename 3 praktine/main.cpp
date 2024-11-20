#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string vigenereEncrypt(const string& text, const string& key) {
    string encryptedText = "";
    int n = 26;

    int KeyIndex = 0;
    for(int i= 0; i<text.length(); i++){
        char currentLetter = toupper(text[i]);
        if(currentLetter < 'A' || currentLetter>'Z'){
            encryptedText += currentLetter;
            continue;
        }
            int m = currentLetter - 'A';
            char KeyChar = toupper(key[KeyIndex % key.length()]);
            int k = KeyChar - 'A';
            int c =(m+k) % n;
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


string vigenereEncryptAscii(const string& text, const string& key){
    string encryptedText = "";
    int keyIndex = 0;

    for (int i = 0; i < text.length(); i++) {
        char currentLetter = text[i];

        int m = static_cast<int>(currentLetter);
        int k = static_cast<int>(key[keyIndex % key.length()]);
        int c = (m + k) % 256;

        encryptedText += static_cast<char>(c);
        keyIndex++;
    }

    return encryptedText;
}

    return 0;
}
