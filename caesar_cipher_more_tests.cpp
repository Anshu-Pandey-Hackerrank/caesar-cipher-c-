#include <array>
#include <string>
#include <vector>
#include <iostream>

#include "caesar_cipher.h"

std::vector<std::string> errors;


void not_equal(std::string value, std::string expected, std::string error) {
    if (value != expected) {
        errors.push_back("FAILED: " + error + " -- " + value + " != " + expected);
    }
}


int main() {
    not_equal(CaesarCipher(1).rotate("HAL"), "IBM", "rotate +1");
    not_equal(CaesarCipher(-1).rotate("IBM"), "HAL", "rotate -1");
    not_equal(CaesarCipher(1).rotate("HALL"), "IBMM", "rotate +1");
    not_equal(CaesarCipher(-1).rotate("IBMM"), "HALL", "rotate -1");
    not_equal(CaesarCipher(5).rotate("HAL"), "MFQ", "rotate +5");
    not_equal(CaesarCipher(-5).rotate("MFQ"), "HAL", "rotate -5");
    not_equal(CaesarCipher(5).rotate("YAS"), "DFX", "rotate +5");
    not_equal(CaesarCipher(-5).rotate("DFX"), "YAS", "rotate -5");
    not_equal(CaesarCipher(13).rotate("NFL"), "ASY", "rotate +13");
    not_equal(CaesarCipher(25).rotate("NBA"), "MAZ", "rotate +25");
    not_equal(CaesarCipher(100).rotate("PGA"), "LCW", "rotate +100");
    not_equal(CaesarCipher(1000).rotate("CBS"), "ONE", "rotate +1000");
    not_equal(CaesarCipher(-50).rotate("ABCD"), "CDEF", "rotate -50");
    not_equal(CaesarCipher(-500).rotate("ABCD"), "UVWX", "rotate -500");

    std::cout << ((errors.size() < 1) ? "Everything passed" : join('\n', errors)) << std::endl;

    return 0;
}
