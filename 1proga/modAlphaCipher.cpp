#include "header.h"
#include <locale>
#include <codecvt>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

//loc

modAlphaCipher::modAlphaCipher(const wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++)
        alphaNum[numAlpha[i]] = i;
    key = convert(getValidKey(skey));
}

wstring modAlphaCipher::encrypt(const wstring& open_text) {
    vector<int> work = convert(getValidOpenText(open_text));
    for (unsigned i = 0; i < work.size(); i++)
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    return convert(work);
}

wstring modAlphaCipher::decrypt(const wstring& cipher_text) {
    vector<int> work = convert(getValidCipherText(cipher_text));
    for (unsigned i = 0; i < work.size(); i++)
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    return convert(work);
}

inline vector<int> modAlphaCipher::convert(const wstring& s) {
    wstring ws = s;
    vector<int> result;
    for (auto c : ws)
        result.push_back(alphaNum[c]);
    return result;
}//string char

inline wstring modAlphaCipher::convert(const vector<int>& v) {
    wstring ws;
    for (auto i : v)
        ws.push_back(numAlpha[i]);
    return ws;
}

inline std::wstring modAlphaCipher::getValidKey(const std::wstring& s) {
    if (s.empty()) {
        throw cipher_error("нулевой ключ");
    }

    std::wstring rez = L"";
    for (wchar_t c : s) {
        // Проверяем код символа (может потребовать расширения диапазонов)
        if ((c >= L'А' && c <= L'Я') || (c >= L'а' && c <= L'я') ||
            (c >= L'A' && c <= L'Z') || (c >= L'a' && c <= L'z') ||
            (c >= L'0' && c <= L'9')) { //добавлено для цифр
            rez += towupper(c);
        }
    }
    if (rez.empty()) {
        throw cipher_error("Ключ содержит недопустимые символы");
    }
    return rez;
}



inline wstring modAlphaCipher::getValidOpenText(const wstring& s) {
    wstring ws = s;
    wstring tmp;

    for (auto c : ws) {
        if ((c >= L'А' && c <= L'Я') || (c >= L'а' && c <= L'я')) {
            if (c >= L'а' && c <= L'я')
                tmp.push_back(c -= 32); // Приведение к верхнему регистру
            else
                tmp.push_back(c);
        } else if (c == L' ') {
            tmp.push_back(c); // Разрешаем пробелы
        } else {
            throw cipher_error("Недопустимый символ в тексте");
        }
    }

    if (tmp.empty())
        throw cipher_error("Надо текст!"); 
    return tmp;
}

inline wstring modAlphaCipher::getValidCipherText(const wstring& s) {
    wstring ws = s;
    if (ws.empty())
        throw cipher_error("Empty cipher text");

    for (auto c : ws) {
        if ((c < L'А' || c > L'Я') && c != L'Ё')
            throw cipher_error("Неверный зашифрованный текст ");
    }

    return ws;
}
