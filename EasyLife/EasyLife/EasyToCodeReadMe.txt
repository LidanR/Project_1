Var Class - Versatile Variable Wrapper

The Var class provides a flexible data container that can hold different types of values, including int, float, double, char, bool, and char*.
This class makes it easier to work with variables of varying types without needing to define separate variables for each type.

Features
Supports Multiple Data Types: The Var class can hold integers, floats, doubles, characters, booleans, and character pointers.
Automatic Type Detection: The type is automatically set when assigning a value.
Basic Arithmetic Operation: Supports addition for compatible types.
Stream Output: Provides an operator<< for easy output using std::cout.


Usage

1. Creating and Assigning Values to Var
You can create Var instances with various types as follows:

--------------------------------------------------------------------------------------------------
Var var1 = 42;         // Holds an int
Var var2 = 3.14f;      // Holds a float
Var var3 = 2.718;      // Holds a double
Var var4 = 'A';        // Holds a char
Var var5 = true;       // Holds a bool
Var var6 = "Hello";    // Holds a char* (string)
--------------------------------------------------------------------------------------------------

Alternatively, you can use assignment after creating an empty Var:

--------------------------------------------------------------------------------------------------
Var var;
var = 100;            // Assign an int
var = 1.618f;         // Assign a float
var = "World";        // Assign a char* (string)
--------------------------------------------------------------------------------------------------

2. Printing Values
To print the value held by a Var object, use std::cout:

--------------------------------------------------------------------------------------------------
std::cout << var1 << std::endl; // Output depends on the type held by var1
--------------------------------------------------------------------------------------------------

3. Adding Var Instances
The Var class supports addition between compatible types (e.g., int with float, double with int).
When adding two Var objects, the result type will depend on the types being added:

--------------------------------------------------------------------------------------------------
Var var1 = 5;
Var var2 = 10.5;
Var result = var1 + var2;   // result now holds 15.5 (float)
--------------------------------------------------------------------------------------------------
For char* (strings), + performs concatenation.

4. Clearing and Reassigning Types
The Var class automatically clears the previous value when a new type is assigned. For example:

--------------------------------------------------------------------------------------------------
Var var = 123;
var = "New string";   // Clears the int and sets var to hold a char*
--------------------------------------------------------------------------------------------------
#include <iostream>
#include "EasyToCode.h"

int main() {
    Var var1 = 5;
    Var var2 = 10.5;
    Var result = var1 + var2;   // result is 15.5

    Var greeting = "Hello, ";
    Var name = "World!";
    Var message = greeting + name; // Concatenates strings

    std::cout << "Result: " << result << std::endl;      // Output: 15.5
    std::cout << "Message: " << message << std::endl;    // Output: Hello, World!
}
--------------------------------------------------------------------------------------------------

Notes
Character Pointer (char*) Management: If you use char*, be cautious about memory management since each new string assignment allocates memory.
Destruction: The destructor automatically clears any allocated memory for char* types.
thank u for using EasyToCode!