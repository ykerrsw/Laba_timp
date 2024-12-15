#include <UnitTest++/UnitTest++.h>
#include <codecvt>
#include <locale>
#include <string> // Не забудьте включить <string>
#include "header.h"

// Функция для преобразования wstring в string (используя UTF-8)
std::string wstring_to_string(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wstr);
}


SUITE(Keytest1) {
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

SUITE(Keytest2) {
    TEST(text_never) {
        modAlphaCipher k(L"Ключ");
        CHECK_THROW((k.encrypt(L"123123")), cipher_error);
    }};


SUITE(Keytest3) {
    TEST(text_never) {
        modAlphaCipher k(L"КЛЮ4ИК");
        CHECK_THROW((k.encrypt(L"123123")), cipher_error);
    }};


SUITE(Test_text1) {
    TEST(text_never) {
        modAlphaCipher k(L"КЛЮЧ");
        CHECK_THROW((k.encrypt(L"123123")), cipher_error);
    }

    TEST(text_s_probelami) {
        modAlphaCipher k(L"КЛЮЧ");
        CHECK_EQUAL(wstring_to_string(L"ХЪЮИЕ"), wstring_to_string(k.encrypt(L"КО ТЫ")));
    }

    TEST(text_normalni) {
        modAlphaCipher k(L"КЛЮЧ");
        CHECK_EQUAL(wstring_to_string(L"ХЪРТ"), wstring_to_string(k.encrypt(L"КОТЫ")));
    }
};


int main(int argc, char** argv) {
    return UnitTest::RunAllTests();
}
