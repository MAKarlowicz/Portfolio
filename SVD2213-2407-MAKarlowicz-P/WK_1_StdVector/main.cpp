#include "Lab2.h"
#include <iostream>

int main() {
    Lab2<int> lab;  // Create Lab2 instance

    int arr[] = {123, 121, 456, 454, 789};  // Array of values
    lab.FillFromArray(arr, 5);  // Fill from array

    std::cout << "Contains 121: " << lab.Contains(121) << std::endl;  // Check if contains 121

    lab.Sort(true);  // Sort ascending
    std::cout << "Sorted values: ";
    for (size_t i = 0; i < lab.getSize(); ++i) {  // Loop through values
        std::cout << lab[i] << " ";  // Print sorted values
    }
    std::cout << std::endl;

    lab.MovePalindromes();  // Move palindromes
    std::cout << "Values after moving palindromes: ";
    for (size_t i = 0; i < lab.getSize(); ++i) {  // Loop through values
        std::cout << lab[i] << " ";  // Print values after moving palindromes
    }
    std::cout << std::endl;

    lab.Clear();  // Clear values
    std::cout << "Values after clearing: " << lab.getSize() << std::endl;  // Check size after clearing

    lab.FillFromFile("data.bin");  // Fill from binary file
    std::cout << "Values after filling from file: ";
    for (size_t i = 0; i < lab.getSize(); ++i) {  // Loop through values
        std::cout << lab[i] << " ";  // Print values after filling from file
    }
    std::cout << std::endl;

    return 0;
}