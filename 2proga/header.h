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
    vector<vector<wchar_t>> matrix; 
    int key;                      
    int stroki;   
    wstring result;  
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