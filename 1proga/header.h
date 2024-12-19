#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class modAlphaCipher {
private:
/*
 * @brief Алфавит из русских букв
* @details используется для шифрования/дешифрования
 */
    const wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; // Алфавит
/*
 * @brief Массив, содержащий русские буквы и соответствующие им порядковые номера
* @details  используется для шифрования/дешифрования
 */
    map<wchar_t, int> alphaNum; // Соответствие букв и индексов  string char
/*
 * @brief Ключ в виде вектора
 * @details используется для шифрования
 */
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
    wstring probeli(const wstring& open_text);
};
/*
 * @brief Класс для обработки ошибок
 * @details 
 */
class cipher_error : public std::invalid_argument {
public:
/*
   * @brief Конструктор класса исключений cipher_error.
   *
   * @param what_arg Строковое сообщение об ошибке.
   */
    explicit cipher_error(const std::string& what_arg) : std::invalid_argument(what_arg) {}
     /*
   * @brief Конструктор класса исключений cipher_error.
   *
   * @param what_arg Символьная строка об ошибке.
   */
    explicit cipher_error(const char* what_arg) : std::invalid_argument(what_arg) {}
};
