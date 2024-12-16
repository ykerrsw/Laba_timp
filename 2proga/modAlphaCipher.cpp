#include "header.h"
#include <cstdint>
//-----------------------------------------------------------------------------------------------------------
/** @brief Шифрование методом маршрутной перестановки
 * @details заполняется пустая матрица, которая добавляет к тексту точки
 * Для зашифровывания и расшифровывания предназначены методы shifr и rasshifr.
 * @warning Реализация для русскогоg языка
 */

Ciper::Ciper(const wstring& text, const int keys)
{
    key = keys;
    if(key == 0) {
        throw size_error("нулевой ключ!");
    } //исключение кинули
    ish = text;
    int razn;
    //учитываем, что может быть неполная строка
    if(ish.length() % key != 0) {
        stroki = ish.length() / key + 1;
        razn = key - ish.length() % key;
        for(int i = 0; i < razn; ++i) {
            ish += L".";
        }
    } else {
        stroki = ish.length() / key;
    }

    //указали количество строк
    matrix.resize(stroki);                // Выделяем память для строк в матрице
    if(ish.length() % key == 0) {         //если все строки полные
        for(int i = 0; i < stroki; ++i) { // изменили размер каждой строки
            matrix[i].resize(key);
        }
    } // задаём каждой строке размер key

    else {
        for(int i = 0; i < stroki - 1; ++i) { // изменили размер каждой строки до key
            matrix[i].resize(key);
        }
        matrix[stroki - 1].resize(ish.length() % key);
    } //изменили размер неполной строки
}

//-----------------------------------------------------------------------------------------------------------
/** @brief функция шифрования
 * @details создается матрица необходимого размера и заполняется справа налево
 * Пропуск дополняется точками
 */
wstring Ciper::shifr()
{
        wstring result1;
        
    // тут мы типо ну заполняем матрицу слева направо и сверху вниз
    int row = 0, col = 0;
    for(wchar_t ch : ish) {
        matrix[row][col++] = ch; //цикл идет по строке
        if(col == key) { //если количество символов уже равняется столбцам то
            col = 0;     //прибавим 1 к строке, переходя на другую
            row++;
        }
    }

    // Идем по столбцам справа налево
    for(int j = key - 1; j >= 0; --j) {
        // Идем по строкам сверху вниз
        for(int i = 0; i < stroki; ++i) {
            // Проверяем, есть ли символ в текущей позиции матрицы
            if(i < static_cast<int>(matrix.size()) and j < static_cast<int>(matrix[i].size())) {
                result1 += matrix[i][j];
            }
        }
    }
    ish=result1;
    for(int i = 0; i < static_cast<int>(result1.length()); ++i) {
        if(result1[i] == '.') { //дополняем точками пропуск
            result1.erase(i, 1);
            --i;
        }
    }
    return result1;
}
//-----------------------------------------------------------------------------------------------------------
/** @brief функция дешифрования
 * @details матрица заполняется права налево и сверху вниз
 * Пропуск дополняется точками
 */
wstring Ciper::rasshifr()
{
        wstring result2;

int n=0;
        for (int j = key-1; j >= 0; --j){
            for (int i = 0; i < stroki; ++i) { 
                matrix[i][j]=ish[n];
                n++;
        }}

    //считали матрицу слева направо сверху вниз
        for (int i=0; i<stroki; i++){
            for (int j=0; j<key; j++){
    result2+=matrix[i][j];}}
    
ish = result2;
      for (int i = 0; i < result2.length(); ++i) { 
        if (result2[i] == '.') {                                    //точки уберем 
            result2.erase(i, 1); 
    --i;}} 
       return result2;  
}

//-----------------------------------------------------------------------------------------------------------
/** @brief функция проверки
 * @details создается 3 алфавита: 1 - русский, 2 - латинский, 3 - цифровой. Переданный текст и ключ проверяются на содержание в них запрещённых символов (латинский, цифра).
 */
wstring Ciper::check()
{

    if(static_cast<int>(ish.length())<=key) {
        throw size_error("ключ неккоректного размера, он должен быть строго меньше текста!");
    }

    wstring r_alf = L"абвгдеёжзийклмнопрстуфхцчшщэюяьъыФБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЭЮЯЪЬЫ";
    wstring a_alf = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wstring z_alf = L"1234567890";
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    for(auto i : ish) {
        for(auto k : r_alf) {
            if(i == k) {
                n1++;
            }
        }
    }

    for(auto i : ish) {
        for(auto k : a_alf) {
            if(i == k) {
                n2++;
            }
        }
    }

    for(auto i : ish) {
        for(auto k : z_alf) {
            if(i == k) {
                n3++;
            }
        }
    }

    if((n1 > 0 or n1 == 0) and n2 > 0 and (n3 > 0 or n3 == 0)) {
        throw invalid_argument("Введённый текст имеет символы латинского алфавита");
    }

    else if((n1 > 0 or n1 == 0) and (n2 == 0 or n2 > 0) and n3 > 0) {
        throw invalid_argument("В тeксте есть запрещённые символы");
    }

    wstring rz = L"все круто";
    return rz;
}
