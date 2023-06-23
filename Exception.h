#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using namespace std;
#include <fstream>
#include <stdexcept>

class DeckFileNotFound : public std::exception {
public:
    const char* what() const noexcept override {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception {
private:
    string errorMessage;

public:
    explicit DeckFileFormatError(int lineNumber) {
        errorMessage = "Deck File Error: File format error in line " + to_string(lineNumber);
    }

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

class DeckFileInvalidSize : public std::exception {
public:
    const char* what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif
