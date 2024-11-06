#include <iostream>
#include <cstring>

#pragma once

enum Parameters {
    NONE, INT, FLOAT, DOUBLE, CHAR, BOOL, CHAR_PTR
};

class Var {
public:
    Var();
    Var(int);
    Var(float);
    Var(double);
    Var(char);
    Var(bool);
    Var(const char*);

    friend std::ostream& operator<<(std::ostream& input, const Var& var);

    Var& operator=(int other);
    Var& operator=(float other);
    Var& operator=(double other);
    Var& operator=(char other);
    Var& operator=(bool other);
    Var& operator=(const char* other);
    operator bool() const
    {
        if (typeOfParameter == BOOL) return type.boolVal;
        if (typeOfParameter == INT) return type.intNum;
        return false;
    }

    ~Var();

private:
    union Type {
        int intNum;
        float floatNum;
        double doubleNum;
        char charVal;
        bool boolVal;
        char* charPtr;

        Type() { intNum = 1; }   // Default constructor for the union  
        //the int is in order to disable the warnings
        ~Type() {}  // Destructor for the union
    } type;

    Parameters typeOfParameter;

    void clear();
};

// Constructors
Var::Var() : typeOfParameter(NONE) {}
Var::Var(int other) : typeOfParameter(INT) { type.intNum = other; }
Var::Var(float other) : typeOfParameter(FLOAT) { type.floatNum = other; }
Var::Var(double other) : typeOfParameter(DOUBLE) { type.doubleNum = other; }
Var::Var(char other) : typeOfParameter(CHAR) { type.charVal = other; }
Var::Var(bool other) : typeOfParameter(BOOL) { type.boolVal = other; }
Var::Var(const char* other) : typeOfParameter(CHAR_PTR) {
    type.charPtr = new char[std::strlen(other) + 1];
    strcpy_s(type.charPtr, std::strlen(other) + 1, other);
}

// Destructor
Var::~Var() {
    clear();
}

// Clear any allocated memory
void Var::clear() {
    if (typeOfParameter == CHAR_PTR) {
        delete[] type.charPtr;
    }
    typeOfParameter = NONE;
}

// Assignment Operators
Var& Var::operator=(int other) {
    clear();
    type.intNum = other;
    typeOfParameter = INT;
    return *this;
}
Var& Var::operator=(float other) {
    clear();
    type.floatNum = other;
    typeOfParameter = FLOAT;
    return *this;
}
Var& Var::operator=(double other) {
    clear();
    type.doubleNum = other;
    typeOfParameter = DOUBLE;
    return *this;
}
Var& Var::operator=(char other) {
    clear();
    type.charVal = other;
    typeOfParameter = CHAR;
    return *this;
}
Var& Var::operator=(bool other) {
    clear();
    type.boolVal = other;
    typeOfParameter = BOOL;
    return *this;
}
Var& Var::operator=(const char* other) {
    clear();
    type.charPtr = new char[std::strlen(other) + 1];
    strcpy_s(type.charPtr, std::strlen(other) + 1, other);
    typeOfParameter = CHAR_PTR;
    return *this;
}

// Output operator <<
std::ostream& operator<<(std::ostream& input, const Var& var) {
    switch (var.typeOfParameter) {
    case NONE:
        input << "- - -";
        break;
    case INT:
        input << var.type.intNum;
        break;
    case FLOAT:
        input << var.type.floatNum;
        break;
    case DOUBLE:
        input << var.type.doubleNum;
        break;
    case CHAR:
        input << var.type.charVal;
        break;
    case BOOL:
        input << (var.type.boolVal ? "true" : "false");
        break;
    case CHAR_PTR:
        input << var.type.charPtr;
        break;
    }
    return input;
}
