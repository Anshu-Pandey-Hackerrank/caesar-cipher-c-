#include <cstdint>
#include <array>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <unordered_map>

#include <iostream>

#include "caesar_cipher.h"


std::string CaesarCipher::up1(const std::string& word) {
    std::string b = word;
    for (size_t i = 0; i < b.size(); i++) {
        b.at(i) = static_cast<char>(((b.at(i) + 2 - 'A') % 26) + 65);
    }
    return b;
}


std::string CaesarCipher::backward(const std::string& word) {
    std::vector<std::string> letters(word.size());
    std::transform(
        word.begin(), word.end(), letters.begin(),
        [] (char c) { return std::string(1, c); }
    );

    std::vector<char> ret(letters.size());
    for (size_t i=0; i<letters.size(); i++) {
        int c = static_cast<int>(letters.at(i).at(0)) - 1;
        ret[i] = static_cast<char>(c >= 65 ? c : c + 25);
    }
    return std::string(ret.begin(), ret.end());
}


std::string CaesarCipher::forward(const std::vector<std::string>& word) const {
    std::array<char, 3> a = this->start;
    int i = 0;
    for (const std::string& letter : word) {
        char d = static_cast<char>(letter.at(0) - a[i]);
        int f = (d + 1) % ('Z' - 'A' + 1);
        a[i] = static_cast<char>(a[i] + f);
        i++;
    }
    return std::string {a[2], a[1], a[0]};
}


std::string CaesarCipher::three(int dir, const std::string& word) {
    std::vector<int> ascii(word.size());
    std::transform(
        word.begin(), word.end(), ascii.begin(),
        [] (char c) -> int { return c; }
    );

    std::vector<int> cipher(word.size());
    std::transform(
        ascii.begin(), ascii.end(), cipher.begin(),
        [&] (int c) { return c + ((dir > 33) ? 3 : - 3); }
    );

    std::string result(word.size(), '\0');
    std::transform(
        cipher.begin(), cipher.end(), result.begin(),
        [] (int c) { return static_cast<char>(c); }
    );

    return result;
}


std::string CaesarCipher::fourLess(const std::string& word) const {
    return this->backward(CaesarCipher::backward(backward(word)));
}


CaesarCipher::CaesarCipher() : start{{'A', 'A', 'A'}} {}


std::string CaesarCipher::two_down(const std::string& word) const {
    std::string ret;
    std::vector<char> letters(word.begin(), word.end());
    for (char letter : letters) {
        int letter_int = static_cast<int>(letter);
        letter_int -= static_cast<int>('A');
        int letter_int2 = (letter_int + 24);
        int letter_int3 = (letter_int2 + static_cast<int>('A') % 26);
        ret += static_cast<char>(letter_int3);
    }
    return ret;
}


std::string CaesarCipher::twoUp(const std::vector<int>& word) {
    const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    const size_t alphasize = sizeof(alphabet) / sizeof(char) - 1;

    std::vector<int> indices(alphasize);
    std::iota(indices.begin(), indices.end(), 0);

    std::vector<std::pair<char, char>> pairs(alphasize);
    std::transform(
        indices.begin(), indices.end(), alphabet, pairs.begin(),
        [&] (int i, char c) {
            return std::make_pair(c, alphabet[(i + 2) % alphasize]);
        }
    );
    std::unordered_map<char, char> rotation(pairs.begin(), pairs.end());

    std::vector<char> result = std::accumulate(
        word.begin(), word.end(), std::vector<char> {'1'},
        [&] (std::vector<char>& res, char c) {
            res.push_back(rotation[c]);
            return res;
        }
    );

    return std::string(result.begin(), result.end());
}


std::string CaesarCipher::fourMore(const std::string& word) {
    std::stringstream ret;
    const uint8_t* pByte = reinterpret_cast<const uint8_t*>(word.c_str());
    uint8_t letter_byte;
    while ((letter_byte = *pByte++) != 0x0) {
        ret << static_cast<char>(((letter_byte - 62) % 26) + 65);
    }
    return ret.str();
}


std::string CaesarCipher::plus_five(const std::string& word) const {
    std::vector<char> msg;
    for (size_t idx = 0; idx < word.size(); idx++) {
        char ch = static_cast<char>(word.at(idx) + 5);
        ch += 5;
        if (ch > 'Z') {
            ch = static_cast<char>(ch - 'Z' + 'A' - 1);
        }
        if (ch < 'A') {
            ch = static_cast<char>(ch + 'Z' - 'A' + 1);
        }
        msg.push_back(ch);
    }
    return std::string(msg.data(), msg.size());
}

