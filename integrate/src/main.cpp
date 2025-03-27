#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "include/caesar_cipher.h"

// Simple JSON parsing (without external libraries)
std::string getValue(const std::string& json, const std::string& key) {
    std::string searchKey = "\"" + key + "\"";
    size_t pos = json.find(searchKey);
    if (pos == std::string::npos) {
        return "";
    }
    
    pos = json.find(":", pos);
    if (pos == std::string::npos) {
        return "";
    }
    
    pos = json.find_first_not_of(" \t\n\r", pos + 1);
    if (pos == std::string::npos) {
        return "";
    }
    
    // Check if value is a string
    if (json[pos] == '"') {
        size_t start = pos + 1;
        size_t end = json.find("\"", start);
        return json.substr(start, end - start);
    }
    
    // Value is a number or other primitive
    size_t end = json.find_first_of(",}\n", pos);
    return json.substr(pos, end - pos);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <json_file>" << std::endl;
        return 1;
    }
    
    // Read JSON file
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }
    
    std::string json((std::istreambuf_iterator<char>(file)), 
                      std::istreambuf_iterator<char>());
    
    // Parse JSON
    std::string operation = getValue(json, "operation");
    std::string shiftStr = getValue(json, "shift");
    std::string text = getValue(json, "text");
    
    // Convert shift to integer
    int shift = 0;
    try {
        shift = std::stoi(shiftStr);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid shift value" << std::endl;
        return 1;
    }
    
    // Process with Caesar Cipher
    CaesarCipher cipher(shift);
    std::string result;
    
    if (operation == "encrypt") {
        result = cipher.rotate(text);
    } else if (operation == "decrypt") {
        result = CaesarCipher(-shift).rotate(text);
    } else {
        std::cerr << "Error: Invalid operation, must be 'encrypt' or 'decrypt'" << std::endl;
        return 1;
    }
    
    // Output result
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}