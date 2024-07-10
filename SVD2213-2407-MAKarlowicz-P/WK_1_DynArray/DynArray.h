#pragma once

template <typename T>
class DynArray {
private:
    T* mArray;       // Pointer to dynamic array
    unsigned int mCapacity;  // Total elements capacity
    unsigned int mSize;      // Elements currently in use

public:
    // Constructor
    DynArray(unsigned int starting_capacity = 0);  // Default capacity

    // Destructor
    ~DynArray();  // Clean memory

    // Copy Constructor
    DynArray(const DynArray& other);  // Create copy

    // Assignment Operator
    DynArray& operator=(const DynArray& other);  // Assign values

    // Overloaded Bracket Operators
    T& operator[](unsigned int index);  // Access element
    const T& operator[](unsigned int index) const;  // Access const element

    // Accessors
    unsigned int getSize() const;  // Get current size
    unsigned int getCapacity() const;  // Get total capacity

    // Modifiers
    void clear();  // Reset object
    void append(const T& data);  // Add element
    void reserve(unsigned int new_capacity = 0);  // Resize array
};

// Implementations
template <typename T>  // Constructor part of 1.2 DynArray
DynArray<T>::DynArray(unsigned int starting_capacity) {  // Constructor definition
    if (starting_capacity == 0) {  // If 0 is passed in
        mArray = nullptr;  // No memory allocated
        mCapacity = 0;  // No capacity
    } else {  // Otherwise
        mArray = new T[starting_capacity];  // Dynamically allocate array
        mCapacity = starting_capacity;  // Set capacity
    }
    mSize = 0;  // Initial size is 0
}

template <typename T>  // Destructor clean up memory
DynArray<T>::~DynArray() {  // Destructor definition
    delete[] mArray;  // Clean up memory
}

template <typename T>  // Copy Constructor create a copy
DynArray<T>::DynArray(const DynArray& other) {  // Copy constructor
    mCapacity = other.mCapacity;  // Shallow copy capacity
    mSize = other.mSize;  // Shallow copy size
    mArray = new T[mCapacity];  // Deep copy array
    for (unsigned int i = 0; i < mSize; ++i) {  // Copy elements
        mArray[i] = other.mArray[i];  // Deep copy each element
    }
}

template <typename T>  // Assignment Operator assign values
DynArray<T>& DynArray<T>::operator=(const DynArray& other) {  // Assignment operator
    if (this != &other) {  // Self-assignment check
        delete[] mArray;  // Clean up existing memory
        mCapacity = other.mCapacity;  // Shallow copy capacity
        mSize = other.mSize;  // Shallow copy size
        mArray = new T[mCapacity];  // Deep copy array
        for (unsigned int i = 0; i < mSize; ++i) {  // Copy elements
            mArray[i] = other.mArray[i];  // Deep copy each element
        }
    }
    return *this;  // Return the object
}

template <typename T>  // Overload [] operator access element
T& DynArray<T>::operator[](unsigned int index) {  // Non-const bracket operator
    return mArray[index];  // Return element
}

template <typename T>  // Overload [] operator access const element
const T& DynArray<T>::operator[](unsigned int index) const {  // Const bracket operator
    return mArray[index];  // Return const element
}

template <typename T>  // Accessor get size
unsigned int DynArray<T>::getSize() const {  // Get size method
    return mSize;  // Return current size
}

template <typename T>  // Accessor get capacity
unsigned int DynArray<T>::getCapacity() const {  // Get capacity method
    return mCapacity;  // Return total capacity
}

template <typename T>  // Modifier clear object
void DynArray<T>::clear() {  // Clear method
    delete[] mArray;  // Clean up memory
    mArray = nullptr;  // Reset pointer
    mSize = 0;  // Reset size
    mCapacity = 0;  // Reset capacity
}

template <typename T>  // Modifier append element
void DynArray<T>::append(const T& data) {  // Append method
    if (mSize == mCapacity) {  // If there is no room
        reserve();  // Double capacity
    }
    mArray[mSize++] = data;  // Add element, update size
}

template <typename T>  // Modifier resize array
void DynArray<T>::reserve(unsigned int new_capacity) {  // Reserve method
    if (new_capacity == 0) {  // If 0 is passed in
        new_capacity = (mCapacity == 0) ? 1 : mCapacity * 2;  // Set new capacity
    } else if (new_capacity <= mCapacity) {  // If new capacity is not larger
        return;  // Do nothing
    }

    T* new_array = new T[new_capacity];  // Dynamically allocate a temporary array
    for (unsigned int i = 0; i < mSize; ++i) {  // Copy over existing data
        new_array[i] = mArray[i];  // Copy each element
    }

    delete[] mArray;  // Free up the memory of the data member
    mArray = new_array;  // Re-assign to larger array
    mCapacity = new_capacity;  // Update capacity
}
