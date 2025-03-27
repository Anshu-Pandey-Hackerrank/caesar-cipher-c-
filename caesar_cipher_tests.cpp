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
    not_equal(CaesarCipher::up1("HAL"), "IBM", "up1");
    not_equal(CaesarCipher::backward("IBM"), "HAL", "backward");
    not_equal(CaesarCipher().forward(std::vector<std::string> {"H", "A", "L"}), "IBM", "forward");
    not_equal(CaesarCipher().two_down("TOEFL"), "RMCDJ", "two_down");
    not_equal(CaesarCipher::twoUp(std::vector<int> {'R', 'M', 'C', 'D', 'J'}), "TOEFL", "twoUp");
    not_equal(CaesarCipher::backward("ABC"), "ZAB", "backward");
    not_equal(CaesarCipher().forward(std::vector<std::string> {"Z", "A", "B"}), "ABC", "forward");
    not_equal(CaesarCipher().plus_five("HAL"), "MFQ", "plus_five");
    not_equal(CaesarCipher().plus_five("YAGNI"), "DFLSN", "plus_five");
    not_equal(CaesarCipher().two_down("AWC"), "YUA", "two_down");
    not_equal(CaesarCipher::twoUp(std::vector<int> {'Y', 'U', 'A'}), "AWC", "twoUp");
    not_equal(CaesarCipher::three(33, "A"), "D", "three +");
    not_equal(CaesarCipher::three(-11, "D"), "A", "three -");
    not_equal(CaesarCipher::three(22, "YYY"), "BBB", "three +");
    not_equal(CaesarCipher::three(-1, "BBB"), "YYY", "three -");
    not_equal(CaesarCipher().fourLess("TUVWXYZ"), "PQRSTUV", "fourLess");
    not_equal(CaesarCipher::fourMore("PQRSTUV"), "TUVWXYZ", "fourMore");
    not_equal(CaesarCipher().fourLess("ABCDEFG"), "WXYZABC", "fourLess");
    not_equal(CaesarCipher::fourMore("WXYZABC"), "ABCDEFG", "fourMore");

    std::cout << ((errors.size() < 1) ? "Everything passed" : join('\n', errors)) << std::endl;

    return 0;
}
