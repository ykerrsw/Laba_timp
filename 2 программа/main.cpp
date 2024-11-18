#include "header.h"

#include <cctype>
#include <cmath>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;

// void check(const wstring& text, int key_=1) {
// if (text.length()<=key_) {
// throw size_error("текст неккоректного размера, он должен быть больше ключа!");}
// else if (key_==0){
// throw size_error("нулевой ключ!");}}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int keys;
    wstring text;
    unsigned op;
    //передается ключ для конструктора с параметром
    try {
        wcout << L"Введите количество столбцов:" << endl;
        wcin >> keys;
        wstring text2;

    zanovo:
        wcout << L"Введите нужную опцию (0-выйти, 1-зашифровать, 2-расшифровать):" << endl;
        wcin >> op;
        int k = 0;
        if(op != 0) {
            if(op == 1) {
                wcout << L"Введите текст:" << endl;
                wcin >> text;

                Ciper test1(text, keys);
                wstring rez;
                rez = test1.check(); //тут ошибку выдаст

                Ciper stroka(text, keys);
                text.clear();
                text += stroka.shifr();
                wcout << L"Зашифрованый текст:" << text << endl;
                k++;
                goto zanovo;
            } else if(op == 2) {
                wcout << L"Введите текст:" << endl;
                ;
                wcin >> text;
                Ciper stroka2(text, keys);
                wcout << L"Расшифрованый текст:" << stroka2.rasshifr() << endl;
                text.clear();
                text += stroka2.rasshifr();
                goto zanovo;
            }

            else {
                wcout << L"Неверная опция, попробуйте ещё раз" << endl;
                goto zanovo;
            }
        } else {
            return 0;
        }
    } catch(const size_error& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    catch(const invalid_argument& e){
            cerr << "Ошибка: " << e.what() << endl;
            return 1;}  
}
