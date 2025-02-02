/*
File:			DynArray.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Purpose:		A dynamically-allocated resizeable array (similar to std::vector)
Notes:			Property of Full Sail University 2406
*/

// Header protection
#pragma once

/***********/
/* Defines */
/***********/

/*
How to use:

	When working on a lab, turn that lab's #define from 0 to 1

		Example:	#define LAB_1	1

	When working on an individual unit test, turn that #define from 0 to 1

		Example:	#define DYNARRAY_DEFAULT_CTOR	1

NOTE: If the unit test is not on, that code will not be compiled!
*/

// Main toggle
#define LAB_1	1

// Individual unit test toggles
#define LAB1_DEFAULT_CONSTRUCTOR_NO_ARGS			1
#define LAB1_DEFAULT_CONSTRUCTOR_WITH_ARGS			1
#define LAB1_BRACKET_OPERATOR						0
#define LAB1_SIZE_ACCESSOR							0
#define LAB1_CAPACITY_ACCESSOR						0
#define LAB1_RESERVE_EMPTY							0
#define LAB1_RESERVE_DOUBLE_CAPACITY				0
#define LAB1_RESERVE_LARGER_CAPACITY				0
#define LAB1_RESERVE_SMALLER_CAPACITY				0
#define LAB1_APPEND_NO_RESIZE						0
#define LAB1_APPEND_RESIZE							0
#define LAB1_CLEAR									0
#define LAB1_DESTRUCTOR								1
#define LAB1_ASSIGNMENT_OPERATOR					0
#define LAB1_COPY_CONSTRUCTOR						1

// Our implementation of a vector (simplified)
template<typename Type>
class DynArray {

	// Gives access to test code
	friend class UnitTests_Lab1;

	// Data members
	// NOTE: All values set to -1 for unit test purposes
	Type* mArray = reinterpret_cast<Type*>(-1);
	size_t mSize = -1;
	size_t mCapacity = -1;

public:

	DynArray(size_t _startingCap = 0) {
		if (_startingCap == 0) {               // If 0, no allocation
			mArray = nullptr;                  // No array allocated
			mCapacity = 0;                     // Capacity set to 0
		} else {
			mArray = new Type[_startingCap];   // Allocate array
			mCapacity = _startingCap;          // Set capacity
		}
		mSize = 0;                             // Initial size is 0
	};

	~DynArray() {
		delete[] mArray;                      // Clean up memory
	}

	DynArray(const DynArray& _copy) {
		mCapacity = _copy.mCapacity;          // Copy capacity
		mSize = _copy.mSize;                  // Copy size
		mArray = new Type[mCapacity];         // Allocate new array
		for (size_t i = 0; i < mSize; ++i) {  // Copy elements
			mArray[i] = _copy.mArray[i];      // Element copy
		}
	}

	DynArray& operator=(const DynArray& _assign) {
		// TODO: Implement this method

	}

	void Clear() {
		// TODO: Implement this method

	}

	Type& operator[](size_t _index) {
		// TODO: Implement this method
	
	}

	size_t Size() const {
		// TODO: Implement this method

	}

	size_t Capacity() const {
		// TODO: Implement this method
	
	}

	void Append(const Type& _data) {
		// TODO: Implement this method
	
	}

	void Reserve(size_t _newCapacity = 0) {
		// TODO: Implement this method

	}
};