#!/bin/sh
g++ caesar_cipher.cpp caesar_cipher_tests.cpp -g -O0 -Wall -Werror -pedantic -std=c++11 && ./a.out && rm -rf a.out*
