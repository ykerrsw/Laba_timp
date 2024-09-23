
#include "modAlphaCiper.h"
#include <cctype>
#include <iostream>
#include <locale>
#include <string>
using namespace std;


bool isValid(const wstring& s) {          // проверка, чтобы строка состояла только из прописных букв
  locale loc("ru_RU.UTF-8");              // Устанавливаем локаль для русского языка
  for (auto c : s) {
    if (!isalpha(c, loc) || !isupper(c, loc)) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv)
{   locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned op;
    wcout << L"Введите ключ: ";
    wcin >> key;
    if(!isValid(key)) {
        wcerr << L"Был введён некорректный ключ\n"<<endl;
        return 1;
    }
    
    wcout << L"ключ был загружен\n"<<endl;
    
    modAlphaCipher cipher(key);
    do {
        wcout << L"Что вы хотите сделать?(0-выйти, 1-зашифровать, 2-расшифровать): ";
        wcin >> op;
        if(op > 2) {
            wcout << L"Неверная функция\n";
        } else if(op > 0) {
            wcout << L"Введите текст: ";
            wcin >> text;
            if(isValid(text)) {
                if(op == 1) {
                    wcout << L"Вот расшифрованый текст: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Введите текст, который хотите расшифровать: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Операция прервана\n";
            }
        }
    } while(op != 0);
    return 0;
}
