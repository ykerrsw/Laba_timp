#include <UnitTest++/UnitTest++.h>
#include <codecvt>
#include <locale>
#include "header.h" // Включаем только заголовочный файл
wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;

/*SUITE(Keytest) {
    TEST(null_key) {
        Ciper k(L"ААА", 0);
        CHECK_THROW( codec.to_bytes(k.check()), size_error);
    }
};*/

SUITE(Keytest) {
    TEST(null_key) {
        bool exception_caught = false;
        try {
            Ciper k(L"ААА", 0); 
        } catch (const size_error& e) {
            exception_caught = true;
        }
        CHECK(exception_caught); 
    }
};

SUITE(shifr_test) {
    TEST(text_m_key) {
        Ciper k(L"иии", 4);
        CHECK_THROW(codec.to_bytes(k.check()), size_error);
    }
    TEST(text_r_key) {
        Ciper k(L"ииии", 4);
        CHECK_THROW(codec.to_bytes(k.check()), size_error);
    }
    TEST(text_numb) {
        Ciper k(L"иии123", 4);
        CHECK_THROW(codec.to_bytes(k.check()), invalid_argument);
    }
    TEST(text_lat_alf) {
        Ciper k(L"fffff", 4);
        CHECK_THROW(codec.to_bytes(k.check()), invalid_argument);
    }
   TEST(text_b_key) {
        Ciper k(L"абвгде", 4);
        CHECK_EQUAL( codec.to_bytes(L"гвбеад"), codec.to_bytes(k.shifr()));
    }
};

SUITE(rasshifr_test) {
    TEST(text_m_key) {
        Ciper k(L"иии", 4);
        CHECK_THROW(codec.to_bytes(k.check()), size_error);
    }
    TEST(text_r_key) {
        Ciper k(L"ииии", 4);
        CHECK_THROW(codec.to_bytes(k.check()), size_error);
    }
    TEST(text_numb) {
        Ciper k(L"иии123", 4);
        CHECK_THROW(codec.to_bytes(k.check()), invalid_argument);
    }
    TEST(text_lat_alf) {
        Ciper k(L"fffff", 4);
        CHECK_THROW(codec.to_bytes(k.check()), invalid_argument);
    }
    TEST(text_b_key) {
        Ciper k(L"виртпе", 4);
        CHECK_EQUAL( codec.to_bytes(L"првети"), codec.to_bytes(k.rasshifr())); // Используем rasshifr()
    }
};

int main(int argc, char** argv) {
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    return UnitTest::RunAllTests();
}
