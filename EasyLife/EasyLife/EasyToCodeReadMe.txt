
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

Notes
- Character Pointer (char*) Management: If you use char*, be cautious about memory management since each new string assignment allocates memory.
- Destruction: The destructor automatically clears any allocated memory for char* types.
Thank you for using EasyToCode!

Example usage of the var class:
-------------------------------------------------------------------------------------------
#include <iostream>
#include "EasyToCode.h"

using namespace std;

int main() {
    // Creating and Assigning Values to var
    var var1 = 42;         // Holds an int
    var var2 = 3.14f;      // Holds a float
    var var3 = 2.718;      // Holds a double
    var var4 = 'A';        // Holds a char
    var var5 = true;       // Holds a bool
    var var6 = "Hello";    // Holds a char* (string)

    // Printing Values
    cout << "var1: " << var1 << endl;
    cout << "var2: " << var2 << endl;
    cout << "var3: " << var3 << endl;
    cout << "var4: " << var4 << endl;
    cout << "var5: " << var5 << endl;
    cout << "var6: " << var6 << endl;

    // Arithmetic Operations
    var var7 = var1 + var2;   // result is 45.14 (float)
    var var8 = var1 - var2;   // result is 38.86 (float)
    var var9 = var1 * var2;   // result is 131.88 (float)
    var var10 = var1 / var2;  // result is 13.3758 (float)

    cout << "var7 (var1 + var2): " << var7 << endl;
    cout << "var8 (var1 - var2): " << var8 << endl;
    cout << "var9 (var1 * var2): " << var9 << endl;
    cout << "var10 (var1 / var2): " << var10 << endl;

    // String Concatenation
    var greeting = "Hello, ";
    var name = "World!";
    var message = greeting + name; // Concatenates strings

    cout << "Message: " << message << endl;

    // Comparison Operations
    var var11 = 5;
    var var12 = 10;
    bool isEqual = (var11 == var12);   // false
    bool isNotEqual = (var11 != var12); // true
    bool isLess = (var11 < var12);     // true

    cout << "isEqual (var11 == var12): " << isEqual << endl;
    cout << "isNotEqual (var11 != var12): " << isNotEqual << endl;
    cout << "isLess (var11 < var12): " << isLess << endl;

    // Type Conversion
    var var13 = 42;
    int intValue = var13.toInt();      // intValue is 42
    cout << "intValue: " << intValue << endl;

    // Clearing and Reassigning Types
    var var14 = 123;
    cout << "var14 before: " << var14 << endl;
    var14 = "New string";   // Clears the int and sets var to hold a char*
    cout << "var14 after: " << var14 << endl;

    // Getting Type Information
    var var15 = 42;
    Parameters type = var15.getType(); // type is INT
    cout << "var15 type: " << type << endl;

    // Accessing Characters
    var var16 = "Hello";
    cout << "var16[1]: " << var16[1] << endl; // Output: e

    // Getting Length
    var var17 = 1234;
    cout << "Length of var17: " << var17.length() << endl; // Output: 4

    var var18 = 23.45f;
    cout << "Length of var18: " << var18.length() << endl; // Output: 5

    var var19 = true;
    cout << "Length of var19: " << var19.length() << endl; // Output: 4

    var var20 = false;
    cout << "Length of var20: " << var20.length() << endl; // Output: 5

    return 0;
}
-------------------------------------------------------------------------------------------
*/
