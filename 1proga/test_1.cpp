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

SUITE(test_1) {
    TEST(key) {
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
//-------------------------------------------------------------------------------------------
SUITE(test_2) {
    TEST(key) {
        bool exception_caught = false;
        try {
            modAlphaCipher k(L"КЛЮЧ");
            std::wstring cipherText = k.encrypt(L"");
        } catch (const cipher_error& e) {
            exception_caught = true;
        }
        CHECK(exception_caught);
    }
};
//-------------------------------------------------------------------------------------------
SUITE(test_3) {
    TEST(key) {
        bool exception_caught = false;
        try {
            modAlphaCipher k(L"КЛЮЧ");
            std::wstring cipherText = k.encrypt(L"123");
        } catch (const cipher_error& e) {
            exception_caught = true;
        }
        CHECK(exception_caught);
    }
};
//-------------------------------------------------------------------------------------------
SUITE(test_4) {
    TEST(key) {
        bool exception_caught = false;
        try {
            modAlphaCipher k(L"КЛЮЧ");
            std::wstring cipherText = k.decrypt(L"");
        } catch (const cipher_error& e) {
            exception_caught = true;
        }
        CHECK(exception_caught);
    }
};
//-------------------------------------------------------------------------------------------
SUITE(test_5) {
    TEST(key) {
        bool exception_caught = false;
        try {
            modAlphaCipher k(L"КЛЮЧ");
            std::wstring cipherText = k.decrypt(L"123");
        } catch (const cipher_error& e) {
            exception_caught = true;
        }
        CHECK(exception_caught);
    }
};
//-------------------------------------------------------------------------------------------



SUITE(test_z_1) {
	modAlphaCipher cipher(L"КЛЮЧ");
    TEST(CHECK_1) { CHECK_EQUAL(wstring_to_string(L"ХЪРТ"), wstring_to_string(cipher.encrypt(L"КОТЫ")));};};

SUITE(test_z_2) {
    modAlphaCipher cipher(L"Ключ");
    TEST(CHECK_2) { CHECK_EQUAL(wstring_to_string(L"ХОТЫ"), wstring_to_string(cipher.encrypt(L"КОТЫ")));};};

SUITE(test_z_3) {
    modAlphaCipher cipher(L"КЛЮЧ");
    TEST(CHECK_1) { CHECK_EQUAL(wstring_to_string(L"ХЪРТ"), wstring_to_string(cipher.encrypt(L"КО ТЫ")));};};

SUITE(test_z_4) {
    modAlphaCipher cipher(L"КЛЮЧ");
    TEST(CHECK_1) { CHECK_EQUAL(wstring_to_string(L"ХЪРТ"), wstring_to_string(cipher.encrypt(L"коты")));};};



SUITE(test_n_1) { 
	modAlphaCipher cipher(L"КЛЮЧ");
    TEST(CHECK_1) { CHECK_EQUAL(wstring_to_string(L"КОТЫ"), wstring_to_string(cipher.decrypt(L"ХЪРТ")));};};

SUITE(test_n_2) {
    modAlphaCipher cipher(L"КЛЮЧ");
    TEST(CHECK_1) { CHECK_EQUAL(wstring_to_string(L"КОТЫ"), wstring_to_string(cipher.decrypt(L"ХЪ РТ")));};};
    
SUITE(test_n_3) {
    modAlphaCipher cipher(L"КЛЮЧ");
    TEST(CHECK_1) { CHECK_EQUAL(wstring_to_string(L"КОТЫ"), wstring_to_string(cipher.decrypt(L"ХЪРТ")));};};

int main(int argc, char** argv) {
    return UnitTest::RunAllTests();
}

