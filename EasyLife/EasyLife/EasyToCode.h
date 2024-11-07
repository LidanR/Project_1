#include <iostream>
#include <cstring>

#pragma once



class Var {

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
    Var() : typeOfParameter(NONE) {}
    Var(int other) : typeOfParameter(INT) { type.intNum = other; }
    Var(float other) : typeOfParameter(FLOAT) { type.floatNum = other; }
    Var(double other) : typeOfParameter(DOUBLE) { type.doubleNum = other; }
    Var(char other) : typeOfParameter(CHAR) { type.charVal = other; }
    Var(bool other) : typeOfParameter(BOOL) { type.boolVal = other; }
    Var(const char* other) : typeOfParameter(CHAR_PTR) {
        type.charPtr = new char[std::strlen(other) + 1];
        strcpy_s(type.charPtr, std::strlen(other) + 1, other);
    }

    // Destructor
    ~Var() {
        clear();
    }

    Var operator+(const Var& other)
    {
        Var temp;

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
    Var& operator=(int other) {
        clear();
        type.intNum = other;
        typeOfParameter = INT;
        return *this;
    }
    Var& operator=(float other) {
        clear();
        type.floatNum = other;
        typeOfParameter = FLOAT;
        return *this;
    }
    Var& operator=(double other) {
        clear();
        type.doubleNum = other;
        typeOfParameter = DOUBLE;
        return *this;
    }
    Var& operator=(char other) {
        clear();
        type.charVal = other;
        typeOfParameter = CHAR;
        return *this;
    }
    Var& operator=(bool other) {
        clear();
        type.boolVal = other;
        typeOfParameter = BOOL;
        return *this;
    }
    Var& operator=(const char* other) {
        clear();
        type.charPtr = new char[std::strlen(other) + 1];
        strcpy_s(type.charPtr, std::strlen(other) + 1, other);
        typeOfParameter = CHAR_PTR;
        return *this;
    }
    Var& operator=(Var& other)
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

    // Addition Assignment Operators for Var class
    Var& operator+=(const Var& other) {
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
    Var& operator+=(int other) {
        *this += Var(other);
        return *this;
    }

    Var& operator+=(float other) {
        *this += Var(other);
        return *this;
    }

    Var& operator+=(double other) {
        *this += Var(other);
        return *this;
    }

    Var& operator+=(char other) {
        *this += Var(other);
        return *this;
    }

    Var& operator+=(bool other) {
        *this += Var(other);
        return *this;
    }
    Var& operator+=(const char* other) {
        *this += Var(other);
        return *this;
    }



    // Output operator <<
    friend std::ostream& operator<<(std::ostream& input, const Var& var) {
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

};


