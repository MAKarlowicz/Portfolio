#pragma once
#include <vector>  // std::vector class
#include <string>  // String for palindrome checks
#include <algorithm>  // std::sort for sorting
#include <fstream>  // std::ifstream for file I/O
#include <iterator>  // Iterators for vectors

template <typename T>
class Lab2 {
private:
    std::vector<T> mValues;  // Main vector used
    std::vector<T> mPalindromes;  // Vector for MovePalindromes

public:
    bool IsPalindromeNumber(T value);  // Checks if value is palindrome

    void FillFromFile(const std::string& filename);  // Fill from binary file

    void FillFromArray(const T* arr, size_t size);  // Fill from array

    void Clear();  // Clear vector

    void Sort(bool ascending = true);  // Sort vector

    T operator[](size_t index) const;  // Array subscript operator

    bool Contains(T value) const;  // Check if contains value

    void MovePalindromes();  // Move palindromes

    size_t getSize() const;  // Get size of vector
};

template <typename T>
bool Lab2<T>::IsPalindromeNumber(T value) {  // Checks if value is palindrome
    std::string str = std::to_string(value);  // Convert number to string
    std::string rev_str = std::string(str.rbegin(), str.rend());  // Reverse string
    return str == rev_str;  // Check if palindrome
}

template <typename T>
void Lab2<T>::FillFromFile(const std::string& filename) {  // Fill from binary file
    std::ifstream infile(filename, std::ios::binary);  // Open file in binary mode
    if (!infile) return;  // Check if file opened
    int numValues;  // Number of values in file
    infile.read(reinterpret_cast<char*>(&numValues), sizeof(int));  // Read 4 byte header
    mValues.resize(numValues);  // Resize vector to number of values
    infile.read(reinterpret_cast<char*>(&mValues[0]), numValues * sizeof(int));  // Read values
}

template <typename T>
void Lab2<T>::FillFromArray(const T* arr, size_t size) {  // Fill from array
    mValues.assign(arr, arr + size);  // Assign array to vector
}

template <typename T>
void Lab2<T>::Clear() {  // Clear vector
    mValues.clear();  // Remove all elements
    mValues.shrink_to_fit();  // Decrease capacity to 0
}

template <typename T>
void Lab2<T>::Sort(bool ascending) {  // Sort vector
    if (ascending) {
        std::sort(mValues.begin(), mValues.end());  // Sort ascending order
    } else {
        std::sort(mValues.rbegin(), mValues.rend());  // Sort descending order
    }
}

template <typename T>
T Lab2<T>::operator[](size_t index) const {  // Array subscript operator
    return mValues[index];  // Return element at index
}

template <typename T>
bool Lab2<T>::Contains(T value) const {  // Check if contains value
    return std::find(mValues.begin(), mValues.end(), value) != mValues.end();  // Find value
}

template <typename T>
void Lab2<T>::MovePalindromes() {  // Move palindromes
    for (auto it = mValues.begin(); it != mValues.end(); ) {  // Iterate through values
        if (IsPalindromeNumber(*it)) {  // Check if value is palindrome
            mPalindromes.push_back(*it);  // Add to palindromes vector
            it = mValues.erase(it);  // Remove from values vector
        } else {
            ++it;  // Move to next element
        }
    }
}

template <typename T>
size_t Lab2<T>::getSize() const {  // Get size of the vector
    return mValues.size();  // Return size of values vector
}