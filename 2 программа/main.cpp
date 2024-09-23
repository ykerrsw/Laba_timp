#include "modAlphaCiper.h"
#include <iostream> 
#include <cctype> 
#include <locale> 
#include <string> 
#include <cmath> 
#include <vector> 
using namespace std; 
 
 
int main(){ 
    locale loc("ru_RU.UTF-8"); 
    locale::global(loc); 
    int keys; 
    wstring text; 
    unsigned op; 
                //передается ключ для конструктора с параметром 
    wcout<<L"Введите количество столбцов:"<<endl; 
    wcin>>keys; 
     
    zanovo: 
    wcout<<L"Введите нужную опцию (0-выйти, 1-зашифровать, 2-расшифровать):"<<endl; 
    wcin>>op; 
     
    if (op!=0){ 
        if (op==1){ 
            wcout<<L"Введите текст:"; 
            wcin>>text; 
            Ciper stroka(text,keys);  
            wcout<<L"Зашифрованый текст:"<<stroka.shifr();; 
            } 
        else if (op==2){ 
            wcout<<L"Введите текст:"; 
            wcin>>text; 
            Ciper stroka(text,keys);  
            wcout<<L"Расшифрованый текст:"<<stroka.rasshifr(); } 
        else {wcout<<L"Неверная опция, попробуйте ещё раз"<<endl; 
        goto zanovo; 
            }} 
         
    else{return 0;}}
