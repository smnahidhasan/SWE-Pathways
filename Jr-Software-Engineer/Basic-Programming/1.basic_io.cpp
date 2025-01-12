/*
    This program demonstrates the input and output of various data types in C++.
    It covers the following:
    1. Basic data types: int, float, double, char, string, and bool.
    2. Dynamic input and output of arrays using vectors.
    3. Use of constants for fixed values.
    4. Handling input buffers and multiple inputs.
    Each section of the program takes input from the user, processes it, and displays it back.
*/

#include <iostream>  // Required for input and output operations
#include <string>    // Required for string data type
#include <vector>    // Required for dynamic array (vector) management
using namespace std; // Allows usage of standard library names without `std::` prefix

int main() {
    // Integer
    int intVar;  // Declares an integer variable
    cout << "Enter an integer: ";  // Prompts user to input an integer
    cin >> intVar;  // Reads the integer input from the user
    cout << "You entered the integer: " << intVar << endl;  // Displays the input integer

    // Floating-point number
    float floatVar;  // Declares a float variable
    cout << "Enter a floating-point number: ";  // Prompts user to input a float
    cin >> floatVar;  // Reads the float input from the user
    cout << "You entered the floating-point number: " << floatVar << endl;  // Displays the input float

    // Double
    double doubleVar;  // Declares a double variable
    cout << "Enter a double: ";  // Prompts user to input a double
    cin >> doubleVar;  // Reads the double input from the user
    cout << "You entered the double: " << doubleVar << endl;  // Displays the input double

    // Character
    char charVar;  // Declares a character variable
    cout << "Enter a character: ";  // Prompts user to input a character
    cin >> charVar;  // Reads the character input from the user
    cout << "You entered the character: " << charVar << endl;  // Displays the input character

    // String
    cin.ignore();  // Clears the newline character left in the buffer by previous inputs
    string stringVar;  // Declares a string variable
    cout << "Enter a string: ";  // Prompts user to input a string
    getline(cin, stringVar);  // Reads the string input, including spaces
    cout << "You entered the string: \"" << stringVar << "\"" << endl;  // Displays the input string with quotes

    // Boolean
    bool boolVar;  // Declares a boolean variable
    cout << "Enter a boolean value (0 for false, 1 for true): ";  // Prompts user to input a boolean value
    cin >> boolVar;  // Reads the boolean input
    cout << "You entered the boolean: " << (boolVar ? "true" : "false") << endl;  // Displays true or false

    // Array of integers
    int arraySize;  // Declares a variable for array size
    cout << "Enter the size of the array: ";  // Prompts user to input array size
    cin >> arraySize;  // Reads the array size
    vector<int> intArray(arraySize);  // Creates a vector (dynamic array) of the given size
    cout << "Enter " << arraySize << " integers: ";  // Prompts user to input array elements
    for (int i = 0; i < arraySize; ++i) {  // Loops to read each integer
        cin >> intArray[i];  // Reads each element into the vector
    }
    cout << "You entered the array: ";  // Displays the array
    for (int i = 0; i < arraySize; ++i) {  // Loops through the vector
        cout << intArray[i] << " ";  // Prints each element
    }
    cout << endl;  // Ends the array output

    // Constants
    const double pi = 3.14159;  // Declares a constant value for pi
    cout << "Constant example: The value of pi is " << pi << endl;  // Displays the constant value

    return 0;  // Indicates successful program execution
}



/*

Inputs: 
12
2.3
23.3
f
This is a text
1
3
1
2
3


Outputs:
Enter an integer: You entered the integer: 12
Enter a floating-point number: You entered the floating-point number: 2.3
Enter a double: You entered the double: 23.3
Enter a character: You entered the character: f
Enter a string: You entered the string: "This is a text"
Enter a boolean value (0 for false, 1 for true): You entered the boolean: true
Enter the size of the array: Enter 3 integers: You entered the array: 1 2 3 
Constant example: The value of pi is 3.14159
*/
