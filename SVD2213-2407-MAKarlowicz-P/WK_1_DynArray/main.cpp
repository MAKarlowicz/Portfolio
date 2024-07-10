#include <iostream>
#include "DynArray.h"  // Include your DynArray header file

int main() {
    // Create a DynArray of integers with initial capacity of 5
    DynArray<int> myArray(5);
    
    // Append some values
    myArray.append(10);
    myArray.append(20);
    myArray.append(30);
    
    // Print the values
    for (unsigned int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray[i] << std::endl;  // Print each element
    }
    
    // Test run the copy constructor
    DynArray<int> copyArray(myArray);
    
    // Print the copied values
    for (unsigned int i = 0; i < copyArray.getSize(); ++i) {
        std::cout << copyArray[i] << std::endl;  // Print each copied element
    }

    return 0;  // Return success
}
