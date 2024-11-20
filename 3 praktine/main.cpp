#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string vigenereEncrypt(const string& text, const string& key) {
    string sypheredText = "";
    int n = 26;

    int KeyIndex = 0;
    for(int i= 0; i<text.length(); i++){
        char currentLetter = toupper(text[i]);
        if(currentLetter < 'A' || currentLetter>'Z'){
            sypheredText += currentLetter;
            continue;
        }
            int m = currentLetter - 'A';
            char KeyChar = toupper(key[KeyIndex % key.length()]);
            int k = KeyChar - 'A';
            int c =(m+k) % n;
            sypheredText += 'A' + c;
            KeyIndex++;
        }
        return sypheredText;

}

    return 0;
}
