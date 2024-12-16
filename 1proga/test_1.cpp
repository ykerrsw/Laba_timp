#include <UnitTest++/UnitTest++.h>
#include <codecvt>
#include <locale>
#include <string>
#include "header.h"
//-------------------------------------------------------------------------------------------
// Функция для преобразования wstring в string (используя UTF-8)
std::string wstring_to_string(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}
//-------------------------------------------------------------------------------------------
wstring check(const wstring& text, const wstring& key, bool destructCipherText = false) {
	wstring rez1;
	for (auto i:text){
        if (not(i==L' ')){
           rez1+=i;}}
        modAlphaCipher cipher(key);
        wstring cipherText = cipher.encrypt(rez1);
        if (destructCipherText) {
            cipherText += L" "; 
        }
        //wcout << L"Введенный текст: " <<text <<endl; 
        wstring rez = cipherText + L" " + cipher.decrypt(cipherText); 
        return rez;}
//-------------------------------------------------------------------------------------------

SUITE(test_1) {
    TEST(null_key) {
        bool exception_caught = false;
        try {
            modAlphaCipher k(L"");
            std::wstring cipherText = k.encrypt(L"КОТЫКОТЫ");
        } catch (const cipher_error& e) {
            exception_caught = true;
        }
        CHECK(exception_caught);
    }
};


SUITE(test_z_1) {
    TEST(CHECK_1) { CHECK_EQUAL(wstring_to_string(L"ХЪРТ КОТЫ"), wstring_to_string(check(L"КОТЫ",L"КЛЮЧ")));}};

SUITE(test_z_2) {
    TEST(CHECK_2) { CHECK_EQUAL(wstring_to_string(L"ХОТЫ КОТЫ"), wstring_to_string(check(L"КОТЫ",L"Ключ")));}};


SUITE(test_z_3) {
    TEST(CHECK_3) { CHECK_EQUAL(wstring_to_string(L"ХЪРТ КОТЫ"), wstring_to_string(check(L"КО ТЫ",L"КЛЮЧ")));}};

SUITE(test_z_4) {
	TEST(CHECK_4) { CHECK_THROW(wstring_to_string(check(L"102", L"КЛЮЧ")), cipher_error);}};
     

int main(int argc, char** argv) {
    return UnitTest::RunAllTests();
}

