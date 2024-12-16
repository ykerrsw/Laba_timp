#include <stdexcept> 
#include <iostream>   
#include <cctype>   
#include <locale>   
#include <string>   
#include <cmath>   
#include <vector>  
#pragma once
using namespace std;   
  
class Ciper{   
private:    
/** @brief матрица для заполнения
 * @details С помощью данного атрибута совершается маршрутная перестановка
 * Размер матрицы определяется длиной введённого текста
 */
    vector<vector<wchar_t>> matrix; 
 /** @brief Ключ (количество столбцов матрицы)
 * @details передаётся в качестве аргумента
 */
    int key;  
/** @brief количество строк матрицы
 * @details передаётся в качестве аргумента
 */                    
    int stroki;   
/** результирующая строка, которая должна быть возвращена после шифрования/дешифрования
 * @details возвращается шифратором/дешифратором
 */
    wstring result; 
/** @brief Исходный текст
 * @details передаётся в качестве аргумента. Текст, который подвергнется шифрованию/дешифрованию
 */ 
    wstring ish;  
public:    
    Ciper() = delete;  
    Ciper(const wstring& text, const int keys);  
    wstring shifr();  
    wstring rasshifr();  
    wstring check(); 
    }; 
     
class size_error: public std::logic_error { 
public: 
    explicit size_error(const std::string& message) : std::logic_error(message) {};  //конструктор исключения, после двоеточия происх. ИНИЦИАЛИЗАЦИЯ родительского класса!! сообщением переданным 
};
