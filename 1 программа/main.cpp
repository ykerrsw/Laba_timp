#include <iostream>
#include <string>
#include "header.h"

using namespace std;

void check(const string& text, const string& key, bool destructCipherText = false) {
    try {
        modAlphaCipher cipher(key);
        string cipherText = cipher.encrypt(text);

        if (destructCipherText) {
            cipherText += static_cast<char>(32); // Добавляем пробел, если destructCipherText == true
        }

        string decryptedText = cipher.decrypt(cipherText);
        cout << "Ключ = " << key << endl;
        cout << "Открытый текст: " << text << endl;
        cout << "Зашифрованный текст: " << cipherText << endl;
        cout << "Расшифрованный текст: " << decryptedText << endl;
    } catch (const cipher_error &e) {
        cerr << "Ошибка: " << e.what() << endl;
    } catch (const std::exception &e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}

int main() {
    check("КОТЫ", "КЛЮЧ");
    cout << "испытание 1\n" << endl;
    check("КОТЫ", "Ключ");
    cout << "испытание 2\n" << endl;
    check("КОТЫ", "");
    cout << "испытание 3\n" << endl;
    check("КОТЫ", "Клю4ик");
    cout << "испытание 4\n" << endl;
    check("КО ТЫ", "КЛЮЧ");
    cout << "испытание 5\n" << endl;
    check("102", "КЛЮЧ");
    cout << "испытание 6\n" << endl;
    check("КОТЫ", "КЛЮЧ", true);
    cout << "испытание 7\n" << endl;

    return 0;
}
