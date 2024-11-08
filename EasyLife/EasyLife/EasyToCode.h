#include <iostream>
#include <cstring>
#include <string>

#pragma once
class var {
private:
    enum Parameters {
        NONE, INT, FLOAT, DOUBLE, CHAR, BOOL, CHAR_PTR
    };
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

    // Clear any allocated memory
    void clear() {
        if (typeOfParameter == CHAR_PTR) {
            delete[] type.charPtr;
        }
        typeOfParameter = NONE;
    }

public:
    // Constructors
    var() : typeOfParameter(NONE) {}
    var(int other) : typeOfParameter(INT) { type.intNum = other; }
    var(float other) : typeOfParameter(FLOAT) { type.floatNum = other; }
    var(double other) : typeOfParameter(DOUBLE) { type.doubleNum = other; }
    var(char other) : typeOfParameter(CHAR) { type.charVal = other; }
    var(bool other) : typeOfParameter(BOOL) { type.boolVal = other; }
    var(const char* other) : typeOfParameter(CHAR_PTR) {
        type.charPtr = new char[std::strlen(other) + 1];
        strcpy_s(type.charPtr, std::strlen(other) + 1, other);
    }
    // Comparison Operators
    bool operator==(const var& other) const {
        if (this->typeOfParameter != other.typeOfParameter) return false;
        switch (this->typeOfParameter) {
        case NONE: return true;
        case INT: return this->type.intNum == other.type.intNum;
        case FLOAT: return this->type.floatNum == other.type.floatNum;
        case DOUBLE: return this->type.doubleNum == other.type.doubleNum;
        case CHAR: return this->type.charVal == other.type.charVal;
        case BOOL: return this->type.boolVal == other.type.boolVal;
        case CHAR_PTR: return std::strcmp(this->type.charPtr, other.type.charPtr) == 0;
        }
        return false;
    }

    bool operator!=(const var& other) const {
        return !(*this == other);
    }


    // Greater than or equal to operator
    bool operator>=(const var& other) const {
        if (this->typeOfParameter != other.typeOfParameter) return false;
        switch (this->typeOfParameter) {
        case NONE: return true;
        case INT: return this->type.intNum >= other.type.intNum;
        case FLOAT: return this->type.floatNum >= other.type.floatNum;
        case DOUBLE: return this->type.doubleNum >= other.type.doubleNum;
        case CHAR: return this->type.charVal >= other.type.charVal;
        case BOOL: return this->type.boolVal >= other.type.boolVal;
        case CHAR_PTR: return std::strcmp(this->type.charPtr, other.type.charPtr) >= 0;
        }
        return false;
    }

    // Less than or equal to operator
    bool operator<=(const var& other) const {
        if (this->typeOfParameter != other.typeOfParameter) return false;
        switch (this->typeOfParameter) {
        case NONE: return true;
        case INT: return this->type.intNum <= other.type.intNum;
        case FLOAT: return this->type.floatNum <= other.type.floatNum;
        case DOUBLE: return this->type.doubleNum <= other.type.doubleNum;
        case CHAR: return this->type.charVal <= other.type.charVal;
        case BOOL: return this->type.boolVal <= other.type.boolVal;
        case CHAR_PTR: return std::strcmp(this->type.charPtr, other.type.charPtr) <= 0;
        }
        return false;
    }



    // Comparison Operators with int
    bool operator<=(int other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum <= other;
        case FLOAT: return this->type.floatNum <= other;
        case DOUBLE: return this->type.doubleNum <= other;
        case CHAR: return this->type.charVal <= other;
        case BOOL: return this->type.boolVal <= other;
        default: return false;
        }
    }

    bool operator>=(int other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum >= other;
        case FLOAT: return this->type.floatNum >= other;
        case DOUBLE: return this->type.doubleNum >= other;
        case CHAR: return this->type.charVal >= other;
        case BOOL: return this->type.boolVal >= other;
        default: return false;
        }
    }

    bool operator<(int other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum < other;
        case FLOAT: return this->type.floatNum < other;
        case DOUBLE: return this->type.doubleNum < other;
        case CHAR: return this->type.charVal < other;
        case BOOL: return this->type.boolVal < other;
        default: return false;
        }
    }

    bool operator>(int other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum > other;
        case FLOAT: return this->type.floatNum > other;
        case DOUBLE: return this->type.doubleNum > other;
        case CHAR: return this->type.charVal > other;
        case BOOL: return this->type.boolVal > other;
        default: return false;
        }
    }

    // Comparison Operators with float
    bool operator<=(float other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum <= other;
        case FLOAT: return this->type.floatNum <= other;
        case DOUBLE: return this->type.doubleNum <= other;
        case CHAR: return this->type.charVal <= other;
        case BOOL: return this->type.boolVal <= other;
        default: return false;
        }
    }

    bool operator>=(float other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum >= other;
        case FLOAT: return this->type.floatNum >= other;
        case DOUBLE: return this->type.doubleNum >= other;
        case CHAR: return this->type.charVal >= other;
        case BOOL: return this->type.boolVal >= other;
        default: return false;
        }
    }

    bool operator<(float other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum < other;
        case FLOAT: return this->type.floatNum < other;
        case DOUBLE: return this->type.doubleNum < other;
        case CHAR: return this->type.charVal < other;
        case BOOL: return this->type.boolVal < other;
        default: return false;
        }
    }

    bool operator>(float other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum > other;
        case FLOAT: return this->type.floatNum > other;
        case DOUBLE: return this->type.doubleNum > other;
        case CHAR: return this->type.charVal > other;
        case BOOL: return this->type.boolVal > other;
        default: return false;
        }
    }

    // Comparison Operators with double
    bool operator<=(double other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum <= other;
        case FLOAT: return this->type.floatNum <= other;
        case DOUBLE: return this->type.doubleNum <= other;
        case CHAR: return this->type.charVal <= other;
        case BOOL: return this->type.boolVal <= other;
        default: return false;
        }
    }

    bool operator>=(double other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum >= other;
        case FLOAT: return this->type.floatNum >= other;
        case DOUBLE: return this->type.doubleNum >= other;
        case CHAR: return this->type.charVal >= other;
        case BOOL: return this->type.boolVal >= other;
        default: return false;
        }
    }

    bool operator<(double other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum < other;
        case FLOAT: return this->type.floatNum < other;
        case DOUBLE: return this->type.doubleNum < other;
        case CHAR: return this->type.charVal < other;
        case BOOL: return this->type.boolVal < other;
        default: return false;
        }
    }

    bool operator>(double other) const {
        switch (this->typeOfParameter) {
        case INT: return this->type.intNum > other;
        case FLOAT: return this->type.floatNum > other;
        case DOUBLE: return this->type.doubleNum > other;
        case CHAR: return this->type.charVal > other;
        case BOOL: return this->type.boolVal > other;
        default: return false;
        }
    }
    // Copy Constructor
    var(const var& other) : typeOfParameter(other.typeOfParameter) {
        switch (other.typeOfParameter) {
        case NONE: break;
        case INT: type.intNum = other.type.intNum; break;
        case FLOAT: type.floatNum = other.type.floatNum; break;
        case DOUBLE: type.doubleNum = other.type.doubleNum; break;
        case CHAR: type.charVal = other.type.charVal; break;
        case BOOL: type.boolVal = other.type.boolVal; break;
        case CHAR_PTR:
            type.charPtr = new char[std::strlen(other.type.charPtr) + 1];
            strcpy_s(type.charPtr, std::strlen(other.type.charPtr) + 1, other.type.charPtr);
            break;
        }
    }

    // Move Constructor
    var(var&& other) noexcept : typeOfParameter(other.typeOfParameter), type(other.type) {
        other.typeOfParameter = NONE;
        other.type.charPtr = nullptr;
    }

    // Move Assignment Operator
    var& operator=(var&& other) noexcept {
        if (this != &other) {
            clear();
            typeOfParameter = other.typeOfParameter;
            type = other.type;
            other.typeOfParameter = NONE;
            other.type.charPtr = nullptr;
        }
        return *this;
    }

    // Destructor
    ~var() {
        clear();
    }

    operator bool() const {
        switch (typeOfParameter) {
        case BOOL:
            return type.boolVal;
        case INT:
            return type.intNum != 0;
        case FLOAT:
            return type.floatNum != 0.0f;
        case DOUBLE:
            return type.doubleNum != 0.0;
        case CHAR:
            return type.charVal != '\0';
        case CHAR_PTR:
            return type.charPtr != nullptr && type.charPtr[0] != '\0';
        default:
            return false;
        }
    }

    var operator+(const var& other)
    {
        var temp;

        // Check that both types are the same
        if (this->typeOfParameter == other.typeOfParameter)
        {
            temp.typeOfParameter = this->typeOfParameter;

            switch (this->typeOfParameter) {
            case NONE:
                // No operation needed for NONE type
                break;

            case INT:
                temp.type.intNum = this->type.intNum + other.type.intNum;
                break;

            case FLOAT:
                temp.type.floatNum = this->type.floatNum + other.type.floatNum;
                break;

            case DOUBLE:
                temp.type.doubleNum = this->type.doubleNum + other.type.doubleNum;
                break;

            case CHAR:
                // Char addition results in int (ASCII addition)
                temp.type.intNum = this->type.charVal + other.type.charVal;
                temp.typeOfParameter = INT;  // Resulting type is INT
                break;

            case BOOL:
                // Bool addition treats true as 1 and false as 0
                temp.type.intNum = static_cast<int>(this->type.boolVal) + static_cast<int>(other.type.boolVal);
                temp.typeOfParameter = INT;  // Resulting type is INT
                break;

            case CHAR_PTR:
                // Concatenate the two char* strings
                if (this->type.charPtr && other.type.charPtr) {
                    size_t len1 = std::strlen(this->type.charPtr);
                    size_t len2 = std::strlen(other.type.charPtr);

                    temp.type.charPtr = new char[len1 + len2 + 1];  // Allocate memory for concatenated string
                    strcpy_s(temp.type.charPtr, len1 + len2 + 1, this->type.charPtr);
                    strcat_s(temp.type.charPtr, len1 + len2 + 1, other.type.charPtr);

                    temp.typeOfParameter = CHAR_PTR;
                }
                else {
                    temp.typeOfParameter = NONE;  // Set to NONE if one of the pointers is null
                }
                break;
            }
        }
        else if ((this->typeOfParameter == INT && (other.typeOfParameter == FLOAT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == FLOAT && (other.typeOfParameter == INT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == DOUBLE && (other.typeOfParameter == FLOAT || other.typeOfParameter == INT)))
        {
            temp.typeOfParameter = this->typeOfParameter;
            switch (this->typeOfParameter)
            {
            case INT:
                if(other.typeOfParameter==FLOAT)
                    temp.type.intNum = this->type.intNum + other.type.floatNum;
                else
                    temp.type.intNum = this->type.intNum + other.type.doubleNum;
                break;

            case FLOAT:
                if (other.typeOfParameter == INT)
                    temp.type.floatNum = this->type.floatNum + other.type.intNum;
                else
                    temp.type.floatNum = this->type.floatNum + other.type.doubleNum;
                break;

            case DOUBLE:
                if (other.typeOfParameter == FLOAT)
                    temp.type.doubleNum = this->type.doubleNum + other.type.floatNum;
                else
                    temp.type.doubleNum = this->type.doubleNum + other.type.intNum;
                break;
            default:
                break;
            }
        }
        else
        {
            std::cerr << "Addition requires both operands to be of the same type." << std::endl;
            temp.typeOfParameter = NONE;
        }

        return temp;
    }


    // Assignment Operators
    var& operator=(int other) {
        clear();
        type.intNum = other;
        typeOfParameter = INT;
        return *this;
    }
    var& operator=(float other) {
        clear();
        type.floatNum = other;
        typeOfParameter = FLOAT;
        return *this;
    }
    var& operator=(double other) {
        clear();
        type.doubleNum = other;
        typeOfParameter = DOUBLE;
        return *this;
    }
    var& operator=(char other) {
        clear();
        type.charVal = other;
        typeOfParameter = CHAR;
        return *this;
    }
    var& operator=(bool other) {
        clear();
        type.boolVal = other;
        typeOfParameter = BOOL;
        return *this;
    }
    var& operator=(const char* other) {
        clear();
        type.charPtr = new char[std::strlen(other) + 1];
        strcpy_s(type.charPtr, std::strlen(other) + 1, other);
        typeOfParameter = CHAR_PTR;
        return *this;
    }
    var& operator=(var& other)
    {
        switch (other.typeOfParameter) {
        case NONE:
            // No operation needed for NONE type
            clear();
            break;

        case INT:
            *this = other.type.intNum;
            break;

        case FLOAT:
            *this = other.type.floatNum;
            break;
        case DOUBLE:
            *this = other.type.doubleNum;
            break;

        case CHAR:
            *this = other.type.charVal;
            break;

        case BOOL:
            *this = other.type.boolVal;
            break;

        case CHAR_PTR:
            *this = other.type.charPtr;
            break;
        }
        this->typeOfParameter = other.typeOfParameter;
        return *this;
    }

    // Addition Assignment Operators for var class
    var& operator+=(const var& other) {
        if (this->typeOfParameter == other.typeOfParameter) {
            switch (this->typeOfParameter) {
            case NONE:
                break;
            case INT:
                this->type.intNum += other.type.intNum;
                break;
            case FLOAT:
                this->type.floatNum += other.type.floatNum;
                break;
            case DOUBLE:
                this->type.doubleNum += other.type.doubleNum;
                break;
            case CHAR:
                this->type.charVal += other.type.charVal;  // ASCII addition
                break;
            case BOOL:
                this->type.boolVal = this->type.boolVal || other.type.boolVal;  // Logical OR for bool
                break;
            case CHAR_PTR:
                if (this->type.charPtr && other.type.charPtr) {
                    size_t len1 = std::strlen(this->type.charPtr);
                    size_t len2 = std::strlen(other.type.charPtr);
                    char* newStr = new char[len1 + len2 + 1];
                    strcpy_s(newStr, len1 + len2 + 1, this->type.charPtr);
                    strcat_s(newStr, len1 + len2 + 1, other.type.charPtr);
                    delete[] this->type.charPtr;
                    this->type.charPtr = newStr;
                }
                break;
            }
        }
        else if ((this->typeOfParameter == INT && (other.typeOfParameter == FLOAT || other.typeOfParameter == DOUBLE)) ||
            (this->typeOfParameter == FLOAT && (other.typeOfParameter == INT || other.typeOfParameter == DOUBLE)) ||
            (this->typeOfParameter == DOUBLE && (other.typeOfParameter == FLOAT || other.typeOfParameter == INT))) {
            switch (this->typeOfParameter) {
            case INT:
                if (other.typeOfParameter == FLOAT)
                    this->type.intNum += static_cast<int>(other.type.floatNum);
                else
                    this->type.intNum += static_cast<int>(other.type.doubleNum);
                break;
            case FLOAT:
                if (other.typeOfParameter == INT)
                    this->type.floatNum += other.type.intNum;
                else
                    this->type.floatNum += static_cast<float>(other.type.doubleNum);
                break;
            case DOUBLE:
                if (other.typeOfParameter == FLOAT)
                    this->type.doubleNum += other.type.floatNum;
                else
                    this->type.doubleNum += other.type.intNum;
                break;
            default:
                break;
            }
        }
        else {
            std::cerr << "Addition assignment requires compatible types." << std::endl;
        }
        return *this;
    }

    // Addition Assignment Operators for primitive types
    var& operator+=(int other) {
        *this += var(other);
        return *this;
    }

    var& operator+=(float other) {
        *this += var(other);
        return *this;
    }

    var& operator+=(double other) {
        *this += var(other);
        return *this;
    }

    var& operator+=(char other) {
        *this += var(other);
        return *this;
    }

    var& operator+=(bool other) {
        *this += var(other);
        return *this;
    }
    var& operator+=(const char* other) {
        *this += var(other);
        return *this;
    }

    // Output operator <<
    friend std::ostream& operator<<(std::ostream& input, const var& var) {
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
    friend std::istream& operator>>(std::istream& is, var& v) {
        v.clear();  // Clear any existing value

        std::string input;
        is >> input;

        // Try to determine the type of input
        if (input == "true" || input == "false") {
            v.typeOfParameter = var::BOOL;
            v.type.boolVal = (input == "true");
        }
        else if (input.length() == 1 && std::isalpha(input[0])) {
            v.typeOfParameter = var::CHAR;
            v.type.charVal = input[0];
        }
        else if (input.find_first_of("+-*%$@#!^():;'><[]{}|=~`?/ ") != std::string::npos) {
            // If input contains operators, treat it as a char*
            v.typeOfParameter = var::CHAR_PTR;
            v.type.charPtr = new char[input.length() + 1];
            strcpy_s(v.type.charPtr, input.length() + 1, input.c_str());
        }
        else if (input.find('.') != std::string::npos) {
            bool isValidFloat = (input.back() == 'f') && std::isdigit(input[0]) && input.find_first_not_of("0123456789.f") == std::string::npos;
            bool isValidDouble = (input.find('f') == std::string::npos) && std::isdigit(input[0]) && input.find_first_not_of("0123456789.") == std::string::npos;

            if (isValidFloat) {
                v.typeOfParameter = var::FLOAT;
                v.type.floatNum = std::stof(input);
            }
            else if (isValidDouble) {
                v.typeOfParameter = var::DOUBLE;
                v.type.doubleNum = std::stod(input);
            }
            else {
                // If it doesn't match a standard float or double pattern, treat as char*
                v.typeOfParameter = var::CHAR_PTR;
                v.type.charPtr = new char[input.length() + 1];
                strcpy_s(v.type.charPtr, input.length() + 1, input.c_str());
            }
        }
        else {
            try {
                v.typeOfParameter = var::INT;
                v.type.intNum = std::stoi(input);
            }
            catch (...) {
                v.typeOfParameter = var::CHAR_PTR;
                v.type.charPtr = new char[input.length() + 1];
                strcpy_s(v.type.charPtr, input.length() + 1, input.c_str());
            }
        }

        return is;
    }


    
    // Subtraction Operator
    var operator-(const var& other) {
        var temp;

        if (this->typeOfParameter == other.typeOfParameter) {
            temp.typeOfParameter = this->typeOfParameter;

            switch (this->typeOfParameter) {
            case NONE:
                break;
            case INT:
                temp.type.intNum = this->type.intNum - other.type.intNum;
                break;
            case FLOAT:
                temp.type.floatNum = this->type.floatNum - other.type.floatNum;
                break;
            case DOUBLE:
                temp.type.doubleNum = this->type.doubleNum - other.type.doubleNum;
                break;
            case CHAR:
                temp.type.intNum = this->type.charVal - other.type.charVal;
                temp.typeOfParameter = INT;
                break;
            case BOOL:
                temp.type.intNum = static_cast<int>(this->type.boolVal) - static_cast<int>(other.type.boolVal);
                temp.typeOfParameter = INT;
                break;
            case CHAR_PTR:
                std::cerr << "Subtraction not supported for char* type." << std::endl;
                temp.typeOfParameter = NONE;
                break;
            }
        }
        else if ((this->typeOfParameter == INT && (other.typeOfParameter == FLOAT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == FLOAT && (other.typeOfParameter == INT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == DOUBLE && (other.typeOfParameter == FLOAT || other.typeOfParameter == INT))) {
            temp.typeOfParameter = this->typeOfParameter;
            switch (this->typeOfParameter) {
            case INT:
                if (other.typeOfParameter == FLOAT)
                    temp.type.intNum = this->type.intNum - other.type.floatNum;
                else
                    temp.type.intNum = this->type.intNum - other.type.doubleNum;
                break;
            case FLOAT:
                if (other.typeOfParameter == INT)
                    temp.type.floatNum = this->type.floatNum - other.type.intNum;
                else
                    temp.type.floatNum = this->type.floatNum - other.type.doubleNum;
                break;
            case DOUBLE:
                if (other.typeOfParameter == FLOAT)
                    temp.type.doubleNum = this->type.doubleNum - other.type.floatNum;
                else
                    temp.type.doubleNum = this->type.doubleNum - other.type.intNum;
                break;
            default:
                break;
            }
        }
        else {
            std::cerr << "Subtraction requires both operands to be of the same type." << std::endl;
            temp.typeOfParameter = NONE;
        }

        return temp;
    }

    // Multiplication Operator
    var operator*(const var& other) {
        var temp;

        if (this->typeOfParameter == other.typeOfParameter) {
            temp.typeOfParameter = this->typeOfParameter;

            switch (this->typeOfParameter) {
            case NONE:
                break;
            case INT:
                temp.type.intNum = this->type.intNum * other.type.intNum;
                break;
            case FLOAT:
                temp.type.floatNum = this->type.floatNum * other.type.floatNum;
                break;
            case DOUBLE:
                temp.type.doubleNum = this->type.doubleNum * other.type.doubleNum;
                break;
            case CHAR:
                temp.type.intNum = this->type.charVal * other.type.charVal;
                temp.typeOfParameter = INT;
                break;
            case BOOL:
                temp.type.intNum = static_cast<int>(this->type.boolVal) * static_cast<int>(other.type.boolVal);
                temp.typeOfParameter = INT;
                break;
            case CHAR_PTR:
                std::cerr << "Multiplication not supported for char* type." << std::endl;
                temp.typeOfParameter = NONE;
                break;
            }
        }
        else if ((this->typeOfParameter == INT && (other.typeOfParameter == FLOAT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == FLOAT && (other.typeOfParameter == INT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == DOUBLE && (other.typeOfParameter == FLOAT || other.typeOfParameter == INT))) {
            temp.typeOfParameter = this->typeOfParameter;
            switch (this->typeOfParameter) {
            case INT:
                if (other.typeOfParameter == FLOAT)
                    temp.type.intNum = this->type.intNum * other.type.floatNum;
                else
                    temp.type.intNum = this->type.intNum * other.type.doubleNum;
                break;
            case FLOAT:
                if (other.typeOfParameter == INT)
                    temp.type.floatNum = this->type.floatNum * other.type.intNum;
                else
                    temp.type.floatNum = this->type.floatNum * other.type.doubleNum;
                break;
            case DOUBLE:
                if (other.typeOfParameter == FLOAT)
                    temp.type.doubleNum = this->type.doubleNum * other.type.floatNum;
                else
                    temp.type.doubleNum = this->type.doubleNum * other.type.intNum;
                break;
            default:
                break;
            }
        }
        else {
            std::cerr << "Multiplication requires both operands to be of the same type." << std::endl;
            temp.typeOfParameter = NONE;
        }

        return temp;
    }

    // Division Operator
    var operator/(const var& other) {
        var temp;

        if (this->typeOfParameter == other.typeOfParameter) {
            temp.typeOfParameter = this->typeOfParameter;

            switch (this->typeOfParameter) {
            case NONE:
                break;
            case INT:
                if (other.type.intNum != 0) {
                    temp.type.intNum = this->type.intNum / other.type.intNum;
                }
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            case FLOAT:
                if (other.type.floatNum != 0.0f) {
                    temp.type.floatNum = this->type.floatNum / other.type.floatNum;
                }
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            case DOUBLE:
                if (other.type.doubleNum != 0.0) {
                    temp.type.doubleNum = this->type.doubleNum / other.type.doubleNum;
                }
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            case CHAR:
                if (other.type.charVal != 0) {
                    temp.type.intNum = this->type.charVal / other.type.charVal;
                    temp.typeOfParameter = INT;
                }
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            case BOOL:
                if (other.type.boolVal) {
                    temp.type.intNum = static_cast<int>(this->type.boolVal) / static_cast<int>(other.type.boolVal);
                    temp.typeOfParameter = INT;
                }
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            case CHAR_PTR:
                std::cerr << "Division not supported for char* type." << std::endl;
                temp.typeOfParameter = NONE;
                break;
            }
        }
        else if ((this->typeOfParameter == INT && (other.typeOfParameter == FLOAT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == FLOAT && (other.typeOfParameter == INT || other.typeOfParameter == DOUBLE))
            || (this->typeOfParameter == DOUBLE && (other.typeOfParameter == FLOAT || other.typeOfParameter == INT))) {
            temp.typeOfParameter = this->typeOfParameter;
            switch (this->typeOfParameter) {
            case INT:
                if (other.typeOfParameter == FLOAT && other.type.floatNum != 0.0f)
                    temp.type.intNum = this->type.intNum / other.type.floatNum;
                else if (other.typeOfParameter == DOUBLE && other.type.doubleNum != 0.0)
                    temp.type.intNum = this->type.intNum / other.type.doubleNum;
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            case FLOAT:
                if (other.typeOfParameter == INT && other.type.intNum != 0)
                    temp.type.floatNum = this->type.floatNum / other.type.intNum;
                else if (other.typeOfParameter == DOUBLE && other.type.doubleNum != 0.0)
                    temp.type.floatNum = this->type.floatNum / other.type.doubleNum;
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            case DOUBLE:
                if (other.typeOfParameter == FLOAT && other.type.floatNum != 0.0f)
                    temp.type.doubleNum = this->type.doubleNum / other.type.floatNum;
                else if (other.typeOfParameter == INT && other.type.intNum != 0)
                    temp.type.doubleNum = this->type.doubleNum / other.type.intNum;
                else {
                    std::cerr << "Division by zero." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                break;
            default:
                break;
            }
        }
        else {
            std::cerr << "Division requires both operands to be of the same type." << std::endl;
            temp.typeOfParameter = NONE;
        }

        return temp;
    }

    // Subtraction Assignment Operator
    var& operator-=(const var& other) {
        *this = *this - other;
        return *this;
    }

    // Multiplication Assignment Operator
    var& operator*=(const var& other) {
        *this = *this * other;
        return *this;
    }

    // Division Assignment Operator
    var& operator/=(const var& other) {
        *this = *this / other;
        return *this;
    }

    // Subtraction Assignment Operators for primitive types
    var& operator-=(int other) {
        *this -= var(other);
        return *this;
    }

    var& operator-=(float other) {
        *this -= var(other);
        return *this;
    }

    var& operator-=(double other) {
        *this -= var(other);
        return *this;
    }

    var& operator-=(char other) {
        *this -= var(other);
        return *this;
    }

    var& operator-=(bool other) {
        *this -= var(other);
        return *this;
    }

    var& operator-=(const char* other) {
        *this -= var(other);
        return *this;
    }

    // Multiplication Assignment Operators for primitive types
    var& operator*=(int other) {
        *this *= var(other);
        return *this;
    }

    var& operator*=(float other) {
        *this *= var(other);
        return *this;
    }

    var& operator*=(double other) {
        *this *= var(other);
        return *this;
    }

    var& operator*=(char other) {
        *this *= var(other);
        return *this;
    }

    var& operator*=(bool other) {
        *this *= var(other);
        return *this;
    }

    var& operator*=(const char* other) {
        *this *= var(other);
        return *this;
    }

    // Division Assignment Operators for primitive types
    var& operator/=(int other) {
        *this /= var(other);
        return *this;
    }

    var& operator/=(float other) {
        *this /= var(other);
        return *this;
    }

    var& operator/=(double other) {
        *this /= var(other);
        return *this;
    }

    var& operator/=(char other) {
        *this /= var(other);
        #pragma once

        #include <iostream>
        #include <cstring>

        class var {
        private:
            enum Parameters {
                NONE, INT, FLOAT, DOUBLE, CHAR, BOOL, CHAR_PTR
            };

            union Type {
                int intNum;
                float floatNum;
                double doubleNum;
                char charVal;
                bool boolVal;
                char* charPtr;

                Type() { intNum = 1; }   // Default constructor for the union
                ~Type() {}  // Destructor for the union
            } type;

            Parameters typeOfParameter;

            // Clear any allocated memory
            void clear() {
                if (typeOfParameter == CHAR_PTR) {
                    delete[] type.charPtr;
                }
                typeOfParameter = NONE;
            }

        public:
            // Constructors
            var() : typeOfParameter(NONE) {}
            var(int other) : typeOfParameter(INT) { type.intNum = other; }
            var(float other) : typeOfParameter(FLOAT) { type.floatNum = other; }
            var(double other) : typeOfParameter(DOUBLE) { type.doubleNum = other; }
            var(char other) : typeOfParameter(CHAR) { type.charVal = other; }
            var(bool other) : typeOfParameter(BOOL) { type.boolVal = other; }
            var(const char* other) : typeOfParameter(CHAR_PTR) {
                type.charPtr = new char[std::strlen(other) + 1];
                strcpy_s(type.charPtr, std::strlen(other) + 1, other);
            }

            // Copy Constructor
            var(const var& other) : typeOfParameter(other.typeOfParameter) {
                switch (other.typeOfParameter) {
                case NONE: break;
                case INT: type.intNum = other.type.intNum; break;
                case FLOAT: type.floatNum = other.type.floatNum; break;
                case DOUBLE: type.doubleNum = other.type.doubleNum; break;
                case CHAR: type.charVal = other.type.charVal; break;
                case BOOL: type.boolVal = other.type.boolVal; break;
                case CHAR_PTR:
                    type.charPtr = new char[std::strlen(other.type.charPtr) + 1];
                    strcpy_s(type.charPtr, std::strlen(other.type.charPtr) + 1, other.type.charPtr);
                    break;
                }
            }

            // Move Constructor
            var(var&& other) noexcept : typeOfParameter(other.typeOfParameter), type(other.type) {
                other.typeOfParameter = NONE;
                other.type.charPtr = nullptr;
            }

            // Move Assignment Operator
            var& operator=(var&& other) noexcept {
                if (this != &other) {
                    clear();
                    typeOfParameter = other.typeOfParameter;
                    type = other.type;
                    other.typeOfParameter = NONE;
                    other.type.charPtr = nullptr;
                }
                return *this;
            }

            // Destructor
            ~var() {
                clear();
            }

            // Conversion Operator to bool
            operator bool() const {
                switch (typeOfParameter) {
                case BOOL:
                    return type.boolVal;
                case INT:
                    return type.intNum != 0;
                case FLOAT:
                    return type.floatNum != 0.0f;
                case DOUBLE:
                    return type.doubleNum != 0.0;
                case CHAR:
                    return type.charVal != '\0';
                case CHAR_PTR:
                    return type.charPtr != nullptr && type.charPtr[0] != '\0';
                default:
                    return false;
                }
            }

            // Comparison Operators
            bool operator==(const var& other) const {
                if (this->typeOfParameter != other.typeOfParameter) return false;
                switch (this->typeOfParameter) {
                case NONE: return true;
                case INT: return this->type.intNum == other.type.intNum;
                case FLOAT: return this->type.floatNum == other.type.floatNum;
                case DOUBLE: return this->type.doubleNum == other.type.doubleNum;
                case CHAR: return this->type.charVal == other.type.charVal;
                case BOOL: return this->type.boolVal == other.type.boolVal;
                case CHAR_PTR: return std::strcmp(this->type.charPtr, other.type.charPtr) == 0;
                }
                return false;
            }

            bool operator!=(const var& other) const {
                return !(*this == other);
            }

            // Addition Operator
            var operator+(const var& other) {
                var temp;
                if (this->typeOfParameter == other.typeOfParameter) {
                    temp.typeOfParameter = this->typeOfParameter;
                    switch (this->typeOfParameter) {
                    case NONE: break;
                    case INT: temp.type.intNum = this->type.intNum + other.type.intNum; break;
                    case FLOAT: temp.type.floatNum = this->type.floatNum + other.type.floatNum; break;
                    case DOUBLE: temp.type.doubleNum = this->type.doubleNum + other.type.doubleNum; break;
                    case CHAR: temp.type.intNum = this->type.charVal + other.type.charVal; temp.typeOfParameter = INT; break;
                    case BOOL: temp.type.intNum = static_cast<int>(this->type.boolVal) + static_cast<int>(other.type.boolVal); temp.typeOfParameter = INT; break;
                    case CHAR_PTR:
                        if (this->type.charPtr && other.type.charPtr) {
                            size_t len1 = std::strlen(this->type.charPtr);
                            size_t len2 = std::strlen(other.type.charPtr);
                            temp.type.charPtr = new char[len1 + len2 + 1];
                            strcpy_s(temp.type.charPtr, len1 + len2 + 1, this->type.charPtr);
                            strcat_s(temp.type.charPtr, len1 + len2 + 1, other.type.charPtr);
                            temp.typeOfParameter = CHAR_PTR;
                        } else {
                            temp.typeOfParameter = NONE;
                        }
                        break;
                    }
                } else if ((this->typeOfParameter == INT && (other.typeOfParameter == FLOAT || other.typeOfParameter == DOUBLE))
                    || (this->typeOfParameter == FLOAT && (other.typeOfParameter == INT || other.typeOfParameter == DOUBLE))
                    || (this->typeOfParameter == DOUBLE && (other.typeOfParameter == FLOAT || other.typeOfParameter == INT))) {
                    temp.typeOfParameter = this->typeOfParameter;
                    switch (this->typeOfParameter) {
                    case INT:
                        if (other.typeOfParameter == FLOAT)
                            temp.type.intNum = this->type.intNum + other.type.floatNum;
                        else
                            temp.type.intNum = this->type.intNum + other.type.doubleNum;
                        break;
                    case FLOAT:
                        if (other.typeOfParameter == INT)
                            temp.type.floatNum = this->type.floatNum + other.type.intNum;
                        else
                            temp.type.floatNum = this->type.floatNum + other.type.doubleNum;
                        break;
                    case DOUBLE:
                        if (other.typeOfParameter == FLOAT)
                            temp.type.doubleNum = this->type.doubleNum + other.type.floatNum;
                        else
                            temp.type.doubleNum = this->type.doubleNum + other.type.intNum;
                        break;
                    default: break;
                    }
                } else {
                    std::cerr << "Addition requires both operands to be of the same type." << std::endl;
                    temp.typeOfParameter = NONE;
                }
                return temp;
            }

            // Assignment Operators
            var& operator=(int other) {
                clear();
                type.intNum = other;
                typeOfParameter = INT;
                return *this;
            }
            var& operator=(float other) {
                clear();
                type.floatNum = other;
                typeOfParameter = FLOAT;
                return *this;
            }
            var& operator=(double other) {
                clear();
                type.doubleNum = other;
                typeOfParameter = DOUBLE;
                return *this;
            }
            var& operator=(char other) {
                clear();
                type.charVal = other;
                typeOfParameter = CHAR;
                return *this;
            }
            var& operator=(bool other) {
                clear();
                type.boolVal = other;
                typeOfParameter = BOOL;
                return *this;
            }
            var& operator=(const char* other) {
                clear();
                type.charPtr = new char[std::strlen(other) + 1];
                strcpy_s(type.charPtr, std::strlen(other) + 1, other);
                typeOfParameter = CHAR_PTR;
                return *this;
            }
            var& operator=(var other) {
                switch (other.typeOfParameter) {
                case NONE: clear(); break;
                case INT: *this = other.type.intNum; break;
                case FLOAT: *this = other.type.floatNum; break;
                case DOUBLE: *this = other.type.doubleNum; break;
                case CHAR: *this = other.type.charVal; break;
                case BOOL: *this = other.type.boolVal; break;
                case CHAR_PTR: *this = other.type.charPtr; break;
                }
                this->typeOfParameter = other.typeOfParameter;
                return *this;
            }

            // Addition Assignment Operator
            var& operator+=(const var& other) {
                if (this->typeOfParameter == other.typeOfParameter) {
                    switch (this->typeOfParameter) {
                    case NONE: break;
                    case INT: this->type.intNum += other.type.intNum; break;
                    case FLOAT: this->type.floatNum += other.type.floatNum; break;
                    case DOUBLE: this->type.doubleNum += other.type.doubleNum; break;
                    case CHAR: this->type.charVal += other.type.charVal; break;
                    case BOOL: this->type.boolVal = this->type.boolVal || other.type.boolVal; break;
                    case CHAR_PTR:
                        if (this->type.charPtr && other.type.charPtr) {
                            size_t len1 = std::strlen(this->type.charPtr);
                            size_t len2 = std::strlen(other.type.charPtr);
                            char* newStr = new char[len1 + len2 + 1];
                            strcpy_s(newStr, len1 + len2 + 1, this->type.charPtr);
                            strcat_s(newStr, len1 + len2 + 1, other.type.charPtr);
                            delete[] this->type.charPtr;
                            this->type.charPtr = newStr;
                        }
                        break;
                    }
                } else if ((this->typeOfParameter == INT && (other.typeOfParameter == FLOAT || other.typeOfParameter == DOUBLE)) ||
                    (this->typeOfParameter == FLOAT && (other.typeOfParameter == INT || other.typeOfParameter == DOUBLE)) ||
                    (this->typeOfParameter == DOUBLE && (other.typeOfParameter == FLOAT || other.typeOfParameter == INT))) {
                    switch (this->typeOfParameter) {
                    case INT:
                        if (other.typeOfParameter == FLOAT)
                            this->type.intNum += static_cast<int>(other.type.floatNum);
                        else
                            this->type.intNum += static_cast<int>(other.type.doubleNum);
                        break;
                    case FLOAT:
                        if (other.typeOfParameter == INT)
                            this->type.floatNum += other.type.intNum;
                        else
                            this->type.floatNum += static_cast<float>(other.type.doubleNum);
                        break;
                    case DOUBLE:
                        if (other.typeOfParameter == FLOAT)
                            this->type.doubleNum += other.type.floatNum;
                        else
                            this->type.doubleNum += other.type.intNum;
                        break;
                    default: break;
                    }
                }
                return *this;
            }
        };
        return *this;
    }

    var& operator/=(bool other) {
        *this /= var(other);
        return *this;
    }

    var& operator/=(const char* other) {
        *this /= var(other);
        return *this;
    }

    mutable std::string tempStr;  // Temporary storage for conversions

    char& operator[](std::size_t index) {
        static char dummy = '-';

        switch (typeOfParameter) {
        case CHAR_PTR:
            if (type.charPtr != nullptr) {
                return type.charPtr[index];
            }
            break;
        case INT:
            tempStr = std::to_string(type.intNum);
            break;
        case FLOAT:
            tempStr = std::to_string(type.floatNum);
            break;
        case DOUBLE:
            tempStr = std::to_string(type.doubleNum);
            break;
        case CHAR:
            tempStr = std::string(1, type.charVal);
            break;
        case BOOL:
            tempStr = type.boolVal ? "true" : "false";
            break;
        default:
            return dummy;
        }

        if (index < tempStr.size()) {
            return tempStr[index];
        }
        return dummy;
    }

    const char& operator[](std::size_t index) const {
        static char dummy = '-';

        switch (typeOfParameter) {
        case CHAR_PTR:
            if (type.charPtr != nullptr) {
                return type.charPtr[index];
            }
            break;
        case INT:
            tempStr = std::to_string(type.intNum);
            break;
        case FLOAT:
            tempStr = std::to_string(type.floatNum);
            break;
        case DOUBLE:
            tempStr = std::to_string(type.doubleNum);
            break;
        case CHAR:
            tempStr = std::string(1, type.charVal);
            break;
        case BOOL:
            tempStr = type.boolVal ? "true" : "false";
            break;
        default:
            return dummy;
        }

        if (index < tempStr.size()) {
            return tempStr[index];
        }
        return dummy;
    }

    // Prefix increment operator
    var& operator++() {
        switch (typeOfParameter) {
        case INT:
            ++type.intNum;
            break;
        case FLOAT:
            ++type.floatNum;
            break;
        case DOUBLE:
            ++type.doubleNum;
            break;
        case CHAR:
            ++type.charVal;
            break;
        case BOOL:
            type.boolVal = !type.boolVal;
            break;
        case CHAR_PTR:
            for (size_t i = 0; i < std::strlen(type.charPtr); ++i) {
                ++type.charPtr[i];
            }
            break;
        default:
            break;
        }
        return *this;
    }

    // Prefix decrement operator
    var& operator--() {
        switch (typeOfParameter) {
        case INT:
            --type.intNum;
            break;
        case FLOAT:
            --type.floatNum;
            break;
        case DOUBLE:
            --type.doubleNum;
            break;
        case CHAR:
            --type.charVal;
            break;
        case BOOL:
            type.boolVal = !type.boolVal;
            break;
        case CHAR_PTR:
            for (size_t i = 0; i < std::strlen(type.charPtr); ++i) {
                --type.charPtr[i];
            }
            break;
        default:
            break;
        }
        return *this;
    }

    // Postfix increment operator
    var operator++(int) {
        var temp = *this;
        ++(*this);
        return temp;
    }

    // Postfix decrement operator
    var operator--(int) {
        var temp = *this;
        --(*this);
        return temp;
    }

    std::size_t size() const {
        std::string str;
        switch (typeOfParameter) {
        case INT:
            str = std::to_string(type.intNum);
            break;
        case FLOAT:
            str = std::to_string(type.floatNum);
            break;
        case DOUBLE:
            str = std::to_string(type.doubleNum);
            break;
        case CHAR:
            str = std::string(1, type.charVal);
            break;
        case BOOL:
            str = type.boolVal ? "true" : "false";
            break;
        case CHAR_PTR:
            if (type.charPtr != nullptr) {
                str = std::string(type.charPtr);
            }
            break;
        default:
            return 0;
        }
        return str.size();
    }

    void print() const {
		std::cout << "Type: ";
        switch (typeOfParameter) {
        case NONE:
            std::cout << "None";
            break;
        case INT:
            std::cout << "int";
            break;
        case FLOAT:
            std::cout << "float";
            break;
        case DOUBLE:
            std::cout << "double";
            break;
        case CHAR:
            std::cout << "char";
            break;
        case BOOL:
            std::cout << "bool";
            break;
        case CHAR_PTR:
            std::cout << "char*/string";
            break;
        default:
            std::cout << "Unknown type";
            break;
        }
        std::cout <<std::endl<< "value: ";
        switch (typeOfParameter) {
        case NONE:
            std::cout << "- - -";
            break;
        case INT:
            std::cout << type.intNum;
            break;
        case FLOAT:
            std::cout << type.floatNum;
            break;
        case DOUBLE:
            std::cout << type.doubleNum;
            break;
        case CHAR:
            std::cout << type.charVal;
            break;
        case BOOL:
            std::cout << (type.boolVal ? "true" : "false");
            break;
        case CHAR_PTR:
            std::cout << type.charPtr;
            break;
        default:
            std::cout << "Unknown type";
            break;
        }
        std::cout << std::endl;
    }
};



