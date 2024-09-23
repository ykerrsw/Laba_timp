#include "modAlphaCiper.h"


//-----------------------------------------------------------------------------------------------------------
Ciper::Ciper(const wstring& text, const int keys){
    key = keys;  
        ish=text; 
        //учитываем, что может быть неполная строка  
        if (ish.length() % key != 0){ 
            stroki = ish.length()/key+1;
        } else {
            stroki = ish.length()/key;
        } 
  
        //указали количество строк  
        matrix.resize(stroki); // Выделяем память для строк в матрице
        if (ish.length()%key==0){                    //если все строки полные  
            for (int i = 0; i < stroki; ++i) {          // изменили размер каждой строки  
                matrix[i].resize(key); 
            }  
        }                  // задаём каждой строке размер key 
             
        else{ 
           for (int i = 0; i < stroki-1; ++i) {          // изменили размер каждой строки до key 
        matrix[i].resize(key);} 
        matrix[stroki-1].resize(ish.length()%key);}     //изменили размер неполной строки 
  }
  
//-----------------------------------------------------------------------------------------------------------
  wstring Ciper:: shifr(){ 
  // тут мы типо ну заполняем матрицу слева направо и сверху вниз  
    int row = 0, col = 0; 
  for (wchar_t ch : ish) { 
    matrix[row][col++] = ch;        //цикл идет по строке 
    if (col == key) {               //если количество символов уже равняется столбцам то  
      col = 0;                      //прибавим 1 к строке, переходя на другую 
      row++; 
    } 
  } 
  
    // Идем по столбцам справа налево    
    for (int j = key - 1; j >= 0; --j) { 
        // Идем по строкам сверху вниз 
        for (int i = 0; i < stroki; ++i) { 
            // Проверяем, есть ли символ в текущей позиции матрицы 
            if (i < matrix.size() and j < matrix[i].size()) { 
                result += matrix[i][j]; 
            } 
        } 
    } 
    return result; 
}
//-----------------------------------------------------------------------------------------------------------
wstring Ciper:: rasshifr(){ 
        
        int n=0;
        for (int j = key-1; j >= 0; --j){
            for (int i = 0; i < stroki; ++i) { 
                matrix[i][j]=ish[n];
                n++;
        }}
      
        
        
    //считали матрицу слева направо сверху вниз
        for (int i=0; i<stroki; i++){
            for (int j=0; j<key; j++){
    result+=matrix[i][j];}}
      // тут мы типо ну заполняем матрицу слева направо и сверху вниз  
       return result;
}
    
