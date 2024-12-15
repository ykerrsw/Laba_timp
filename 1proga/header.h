#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class modAlphaCipher {
private:
    const wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; // Алфавит
    map<wchar_t, int> alphaNum; // Соответствие букв и индексов  string char
    vector<int> key; // Ключ шифрования

    vector<int> convert(const wstring& s); // Преобразование строки в вектор индексов
    wstring convert(const vector<int>& v); // Преобразование вектора индексов в строку
    wstring getValidKey(const wstring& s); // Проверка и получение валидного ключа
    wstring getValidOpenText(const wstring& s); // Проверка и получение валидного открытого текста
    wstring getValidCipherText(const wstring& s); // Проверка и получение валидного зашифрованного текста

public:
    modAlphaCipher() = delete; // Удаляем конструктор по умолчанию
    explicit modAlphaCipher(const wstring& skey); // Конструктор с ключом
    wstring encrypt(const wstring& open_text); // Шифрование текста
    wstring decrypt(const wstring& cipher_text); // Дешифрование текста
};

class cipher_error : public std::invalid_argument {
public:
    explicit cipher_error(const std::string& what_arg) : std::invalid_argument(what_arg) {}
    explicit cipher_error(const char* what_arg) : std::invalid_argument(what_arg) {}
};
