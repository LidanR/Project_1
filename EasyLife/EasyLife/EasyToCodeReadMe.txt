var Class - Versatile variable Wrapper

The var class provides a flexible data container that can hold different types of values, including int, float, double, char, bool, and char*.
This class makes it easier to work with variables of varying types without needing to define separate variables for each type.

Features
- Supports Multiple Data Types: The var class can hold integers, floats, doubles, characters, booleans, and character pointers.
- Automatic Type Detection: The type is automatically set when assigning a value.
- Basic Arithmetic Operations: Supports addition, subtraction, multiplication, and division for compatible types.
- Comparison Operators: Supports comparison operators (==, !=, <, >, <=, >=).
- Stream Output: Provides an operator<< for easy output using std::cout.
- Type Conversion Methods: Methods to convert var to specific types (e.g., toInt(), toFloat(), toDouble(), etc.).
- Type Information: Method to get the type of the stored value.

Usage

1. Creating and Assigning Values to var
You can create var instances with various types as follows:

--------------------------------------------------------------------------------------------------
var var1 = 42;         // Holds an int
var var2 = 3.14f;      // Holds a float
var var3 = 2.718;      // Holds a double
var var4 = 'A';        // Holds a char
var var5 = true;       // Holds a bool
var var6 = "Hello";    // Holds a char* (string)
--------------------------------------------------------------------------------------------------

Alternatively, you can use assignment after creating an empty var:

--------------------------------------------------------------------------------------------------
var var;
var = 100;            // Assign an int
var = 1.618f;         // Assign a float
var = "World";        // Assign a char* (string)
--------------------------------------------------------------------------------------------------

2. Printing Values
To print the value held by a var object, use std::cout:

--------------------------------------------------------------------------------------------------
std::cout << var1 << std::endl; // Output depends on the type held by var1
--------------------------------------------------------------------------------------------------

3. Arithmetic Operations
The var class supports arithmetic operations between compatible types (e.g., int with float, double with int).
When performing operations on two var objects, the result type will depend on the types being operated on:

--------------------------------------------------------------------------------------------------
var var1 = 5;
var var2 = 10.5;
var result = var1 + var2;   // result now holds 15.5 (float)
result = var1 - var2;       // result now holds -5.5 (float)
result = var1 * var2;       // result now holds 52.5 (float)
result = var1 / var2;       // result now holds 0.47619 (float)
--------------------------------------------------------------------------------------------------

For char* (strings), + performs concatenation.

4. Comparison Operations
The var class supports comparison operations:

--------------------------------------------------------------------------------------------------
var var1 = 5;
var var2 = 10;
bool isEqual = (var1 == var2);   // false
bool isNotEqual = (var1 != var2); // true
bool isLess = (var1 < var2);     // true
--------------------------------------------------------------------------------------------------

5. Type Conversion
You can convert a var object to a specific type using the provided methods:

--------------------------------------------------------------------------------------------------
var var = 42;
int intValue = var.toInt();      // intValue is 42
--------------------------------------------------------------------------------------------------

6. Clearing and Reassigning Types
The var class automatically clears the previous value when a new type is assigned. For example:

--------------------------------------------------------------------------------------------------
var var = 123;
var = "New string";   // Clears the int and sets var to hold a char*
--------------------------------------------------------------------------------------------------

7. Getting Type Information
You can get the type of the stored value using the getType() method:

--------------------------------------------------------------------------------------------------
var var = 42;
Parameters type = var.getType(); // type is INT
--------------------------------------------------------------------------------------------------

Example Usage:

--------------------------------------------------------------------------------------------------
#include <iostream>
#include "EasyToCode.h"

int main() {
    var var1 = 5;
    var var2 = 10.5;
    var result = var1 + var2;   // result is 15.5

    var greeting = "Hello, ";
    var name = "World!";
    var message = greeting + name; // Concatenates strings

    std::cout << "Result: " << result << std::endl;      // Output: 15.5
    std::cout << "Message: " << message << std::endl;    // Output: Hello, World!
}
--------------------------------------------------------------------------------------------------

Notes
- Character Pointer (char*) Management: If you use char*, be cautious about memory management since each new string assignment allocates memory.
- Destruction: The destructor automatically clears any allocated memory for char* types.
Thank you for using EasyToCode!
