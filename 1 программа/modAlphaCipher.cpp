#include "modAlphaCiper.h"

modAlphaCipher::modAlphaCipher(const std::wstring& skey)            //конструктор для установки ключа с константой ссылочного типа
{
    for(unsigned i = 0; i < numAlpha.size(); i++) {                 //от нуля до размера альфавита. то есть выведем номер порядковый
        alphaNum[numAlpha[i]] = i;                                  //словарь alphaNum по ключу iтого элемента из строки numAlpha
    }
    key = convert(skey); }



    wstring modAlphaCipher::encrypt(const wstring& open_text)       //закидываем текст в вектор, циклом фор меняем этот вектор на
{                                                                   //вектор из зашифрованого текста
        vector <int> work = convert(open_text);
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size(); // тут с iтым символом вектора ворк складывается символ ключа, порядковый
    }                                                               // номер которого зациклен чтобы выводить более короткое слово неск. раз
    return convert(work);}
    

    wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
        vector <int> work = convert(cipher_text);
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();                                                                                                       
    }   
    return convert(work);
}


inline vector <int> modAlphaCipher::convert(const wstring& s)        //метод класса из строки в вектор
{
    vector <int> result;
    for(auto c : s) {
        result.push_back(alphaNum[c]);                              //т.е. получается вектор из порядковых номеров
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v)        //метод класса из числового вектора в строку
{
    wstring result;
    for(auto i : v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
