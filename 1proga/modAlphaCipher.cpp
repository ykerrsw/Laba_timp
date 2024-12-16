#include "header.h"
#include <locale>
#include <codecvt>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

/** @brief Класс для шифровки текста
 * @details Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
 * @warning Реализация для русскогоg языка
 */
modAlphaCipher::modAlphaCipher(const wstring& skey) {
    for (unsigned i = 0; i < numAlpha.size(); i++)
        alphaNum[numAlpha[i]] = i;
    key = convert(getValidKey(skey));
}

/** @brief Метод для шифровки текста 
 * @details Передаётся текст, который преобразуется в шифр методом прибавления к каждому символу ключа. Для того, чтобы не выходить за границы алфавита, используется деление по модулю.
 */
wstring modAlphaCipher::encrypt(const wstring& open_text) {
    vector<int> work = convert(getValidOpenText(open_text));
    for (unsigned i = 0; i < work.size(); i++)
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    return convert(work);
}

/*
 * @brief Метод конвертации текста в вектор из порядковых номеров
 * @details Каждый символ текста заменяется на соответствующую цифру и добавляется в вектор
 * возвращается вектор
 */
inline vector<int> modAlphaCipher::convert(const wstring& s) {
    wstring ws = s;
    vector<int> result;
    for (auto c : ws)
        result.push_back(alphaNum[c]);
    return result;
}
/*
 * @brief Метод конвертации вектора в текст
 * @details Каждый порядковый номер переводится в символ и добавляется к результирующей строке.
 * возвращается строка
 */
inline wstring modAlphaCipher::convert(const vector<int>& v) {
    wstring ws;
    for (auto i : v)
        ws.push_back(numAlpha[i]);
    return ws;
}
/*
 * @brief Проверяет и нормализует ключ шифрования.
 *
 * @param s Строка, представляющая ключ.
 * @return Нормализованная строка ключа, содержащая только допустимые символы в верхнем регистре (буквы русского алфавита, латинские буквы и цифры).
 * @details Метод проверяет, что переданная строка не пуста. Если строка пуста, генерируется исключение `cipher_error` с сообщением "нулевой ключ".
 *           Метод итерируется по символам входной строки.
 *           Если символ является буквой русского или латинского алфавита или цифрой, он преобразуется в верхний регистр и добавляется в результирующую строку.
 *           В противном случае генерируется исключение `cipher_error` с сообщением "Ключ содержит недопустимые символы".
 *           Если в результате все символы недопустимы, выбрасывается исключение.
 * @exception cipher_error Если входная строка пуста или содержит недопустимые символы (не буквы русского и латинского алфавита, не цифры).
 */
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

/*
 * @brief Проверяет и нормализует ключ шифрования.
 *
 * @param s Строка, представляющая ключ.
 * @return Нормализованная строка ключа, содержащая только допустимые символы в верхнем регистре (буквы русского алфавита, латинские буквы и цифры).
 * @details Метод проверяет, что переданная строка не пуста. Если строка пуста, генерируется исключение `cipher_error` с сообщением "нулевой ключ".
 *           Метод итерируется по символам входной строки.
 *           Если символ является буквой русского или латинского алфавита или цифрой, он преобразуется в верхний регистр и добавляется в результирующую строку.
 *           В противном случае генерируется исключение `cipher_error` с сообщением "Ключ содержит недопустимые символы".
 *           Если в результате все символы недопустимы, выбрасывается исключение.
 * @exception cipher_error Если входная строка пуста или содержит недопустимые символы (не буквы русского и латинского алфавита, не цифры).
 */

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

/*
 * @brief Проверяет и нормализует зашифрованный текст.
 *
 * @param s Строка, представляющая зашифрованный текст.
 * @return Нормализованная строка зашифрованного текста, содержащая только буквы русского алфавита в верхнем регистре.
 * @details Метод проверяет, что переданная строка не пуста. Если строка пуста, генерируется исключение `cipher_error` с сообщением "Empty cipher text".
 *           Метод итерируется по символам входной строки.
 *           Если символ не является буквой русского алфавита (за исключением буквы Ё) в верхнем регистре, генерируется исключение `cipher_error` с сообщением "Неверный зашифрованный текст ".
 * @exception cipher_error Если входная строка пуста или содержит недопустимые символы (не буквы русского алфавита, за исключением Ё, в верхнем регистре).
 */

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
