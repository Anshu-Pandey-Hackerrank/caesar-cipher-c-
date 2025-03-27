#ifndef __CAESAR_CIPHER_H_
#define __CAESAR_CIPHER_H_

#include <array>
#include <vector>
#include <string>
#include <sstream>


class CaesarCipher {
    public:
        static std::string up1(const std::string& word);
        static std::string backward(const std::string& word);
        std::string forward(const std::vector<std::string>& word) const;
        static std::string three(int dir, const std::string& word);
        std::string fourLess(const std::string& word) const;

    public:
        CaesarCipher() {}

        std::string two_down(const std::string& word) const;
        static std::string twoUp(const std::vector<int>& word);
        static std::string fourMore(const std::string& word);
        std::string plus_five(const std::string& word) const;
};


inline std::string join(char delimiter, const std::vector<std::string>& strings) {
    std::stringstream result;

    std::vector<std::string>::const_iterator it = strings.begin();
    if (it != strings.end()) {
        result << *it++;
    }

    while (it != strings.end()) {
        result << delimiter << *it++;
    }

    return result.str();
}

#endif
