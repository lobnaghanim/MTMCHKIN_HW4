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

//class DeckFileFormatError : public std::exception {
//private:
//    int lineNumber;
//
//public:
//    explicit DeckFileFormatError(int lineNumber) : lineNumber(lineNumber) {}
//
//    const char* what() const noexcept override {
//        string error = "Deck File Error: File format error in line " + to_string(lineNumber);
//        return error.c_str();
//    }
//};

class DeckFileInvalidSize : public std::exception {
public:
    const char* what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif
//
//class DeckFileException{
//public:
//    virtual void what() const = 0;
//};
//
//class DeckFileNotFound : public DeckFileException{
//public:
//    DeckFileNotFound() = default;
//    void what() const override {
//        cout<<"Deck File Error: File not found"<<endl;
//    };
//};
//
////void DeckFileNotFound::what() const{
////    cout<<"Deck File Error: File not found"<<endl;
////}
//
//class DeckFileFormatError : public DeckFileException {
//public:
//    DeckFileFormatError() = default;
//
//    void what() const override{
//        cout<<"Deck File Error: File format error in line <lineNumberInDeckfile>"<<endl;
//    };
//};
////
////void DeckFileFormatError::what() const{
////    cout<<"Deck File Error: File format error in line <lineNumberInDeckfile>"<<endl; //@TODO get line number
////}
//
//class DeckFileInvalidSize : public DeckFileException{
//public:
//    DeckFileInvalidSize()=default;
//    void what() const override{
//        cout<<"Deck File Error: Deck size is invalid"<<endl;
//    };
//};
//
////void DeckFileInvalidSize::what() const {
////    cout<<"Deck File Error: Deck size is invalid"<<endl;
////}
//
//#endif