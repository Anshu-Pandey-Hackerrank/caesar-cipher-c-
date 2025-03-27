#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "include/caesar_cipher.h"

// Simple JSON parsing function
std::string getValue(const std::string& json, const std::string& key) {
    std::string searchKey = "\"" + key + "\"";
    size_t pos = json.find(searchKey);
    if (pos == std::string::npos) return "";
    
    pos = json.find(":", pos);
    if (pos == std::string::npos) return "";
    
    pos = json.find_first_not_of(" \t\n\r", pos + 1);
    if (pos == std::string::npos) return "";
    
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

// Helper function to convert string to vector of strings for forward()
std::vector<std::string> stringToVec(const std::string& text) {
    std::vector<std::string> result;
    for (char c : text) {
        result.push_back(std::string(1, c));
    }
    return result;
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
    std::string text = getValue(json, "text");
    std::string method = getValue(json, "method");
    
    // Process based on chosen method
    std::string result;
    CaesarCipher cipher;
    
    if (method == "up1") {
        result = CaesarCipher::up1(text);
    }
    else if (method == "backward") {
        result = CaesarCipher::backward(text);
    }
    else if (method == "forward") {
        result = cipher.forward(stringToVec(text));
    }
    else if (method == "two_down") {
        result = cipher.two_down(text);
    }
    else if (method == "plus_five") {
        result = cipher.plus_five(text);
    }
    else if (method == "fourLess") {
        result = cipher.fourLess(text);
    }
    else if (method == "fourMore") {
        result = CaesarCipher::fourMore(text);
    }
    else {
        // Default to a method that works with any text length
        if (operation == "encrypt") {
            result = CaesarCipher::up1(text);
        } else {
            result = CaesarCipher::backward(text);
        }
    }
    
    // Output result
    std::cout << "Input: " << text << std::endl;
    std::cout << "Operation: " << operation << " using method: " << 
        (method.empty() ? "default" : method) << std::endl;
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}