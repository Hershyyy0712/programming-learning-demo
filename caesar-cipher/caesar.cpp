#include <iostream>
#include <string>
using namespace std;
//加密
string caesarEncrypt(string text, int key) {
    string res = "";
    for (char c : text) {
        if (isupper(c)) {
            res += (char)((c - 'A' + key) % 26 + 'A');
        } else if (islower(c)) {
            res += (char)((c - 'a' + key) % 26 + 'a');
        } else {
            res += c;
        }
    }
    return res;
}

// 解密
string caesarDecrypt(string text, int key) {
    return caesarEncrypt(text, 26 - key % 26);
}

int main() {
    string plain = "HELLO";
    int key = 3;

    string cipher = caesarEncrypt(plain, key);
    cout << "明码:    " << plain << endl;
    cout << "密码:    " << cipher << endl;
    cout << "解密:  " << caesarDecrypt(cipher, key) << endl;

    return 0;
}
