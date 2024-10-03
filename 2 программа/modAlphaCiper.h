
#include <iostream>  
#include <cctype>  
#include <locale>  
#include <string>  
#include <cmath>  
#include <vector>  
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
    };