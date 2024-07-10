#ifndef DLIST_H
#define DLIST_H

// Node Structure
struct Node {
    int data; // value stored
    Node* next; // pointer to next node
    Node* prev; // pointer to previous node

    Node(int val) : data(val), next(nullptr), prev(nullptr) {} // Constructor to initialize data members
};

class DList; // Forward declaration

class Iterator {
public:
    Node* mCurr; // current node pointer

    Iterator(Node* ptr = nullptr) : mCurr(ptr) {} // Constructor

    Iterator& operator++() { // Pre-fix increment
        if (mCurr) mCurr = mCurr->next; // Move to next node
        return *this; // Return iterator
    }

    Iterator operator++(int) { // Post-fix increment
        Iterator temp = *this; // Store current state
        if (mCurr) mCurr = mCurr->next; // Move to next node
        return temp; // Return old state
    }

    Iterator& operator--() { // Pre-fix decrement
        if (mCurr) mCurr = mCurr->prev; // Move to prev node
        return *this; // Return iterator
    }

    Iterator operator--(int) { // Post-fix decrement
        Iterator temp = *this; // Store current state
        if (mCurr) mCurr = mCurr->prev; // Move to prev node
        return temp; // Return old state
    }

    int& operator*() { // Dereference operator
        return mCurr->data; // Return data of current node
    }

    bool operator!=(const Iterator& other) const { // Inequality operator
        return mCurr != other.mCurr; // Check if not same node
    }

    bool operator==(const Iterator& other) const { // Equality operator
        return mCurr == other.mCurr; // Check if same node
    }
};

class DList {
private:
    Node* mHead; // front node pointer
    Node* mTail; // back node pointer
    size_t mSize; // number of nodes

    void clearHelper(Node* node) { // Recursive clear function
        if (node) { // If node exists
            clearHelper(node->next); // Clear next node
            delete node; // Delete current node
        }
    }

public:
    DList() : mHead(nullptr), mTail(nullptr), mSize(0) {} // Constructor

    ~DList() { clear(); } // Destructor

    void clear() { // Clear list
        clearHelper(mHead); // Clear all nodes
        mHead = mTail = nullptr; // Reset head and tail
        mSize = 0; // Reset size
    }

    void addHead(int value) { // Add node to front
        Node* newNode = new Node(value); // Create new node
        if (!mHead) { // If list is empty
            mHead = mTail = newNode; // Set head and tail to new node
        } else { // If list is not empty
            newNode->next = mHead; // New node points to current head
            mHead->prev = newNode; // Current head points back to new node
            mHead = newNode; // Update head
        }
        ++mSize; // Increment size
    }

    void addTail(int value) { // Add node to back
        Node* newNode = new Node(value); // Create new node
        if (!mTail) { // If list is empty
            mHead = mTail = newNode; // Set head and tail to new node
        } else { // If list is not empty
            newNode->prev = mTail; // New node points back to current tail
            mTail->next = newNode; // Current tail points to new node
            mTail = newNode; // Update tail
        }
        ++mSize; // Increment size
    }

    Iterator begin() { return Iterator(mHead); } // Return iterator to head
    Iterator end() { return Iterator(nullptr); } // Return iterator to end

    void insert(Iterator it, int value) { // Function to insert a node at iterator's position
        if (it == begin()) { // If iterator is at head
            addHead(value); // Use addHead method
            it = begin(); // Update iterator to new head
        } else if (it == end()) { // If iterator is at end
            addTail(value); // Use addTail method
            it = Iterator(mTail); // Update iterator to new tail
        } else { // If iterator is somewhere in middle
            Node* newNode = new Node(value); // Dynamically allocate a new node
            Node* curr = it.mCurr; // Get current node from iterator
            newNode->next = curr; // Set new node's next to current node
            newNode->prev = curr->prev; // Set new node's previous to current node's previous
            curr->prev->next = newNode; // Link previous node's next to new node
            curr->prev = newNode; // Link current node's previous to new node
            it = Iterator(newNode); // Update iterator to new node
            ++mSize; // Increment size of list
        }
    }

    void erase(Iterator& it) { // Function to erase a node at iterator's position
        if (it == end()) return; // If iterator is at end, do nothing

        Node* curr = it.mCurr; // Get current node from iterator
        if (curr == mHead) { // If current node is head
            mHead = mHead->next; // Update head to next node
            if (mHead) mHead->prev = nullptr; // Set new head's previous to null
        } else if (curr == mTail) { // If current node is tail
            mTail = mTail->prev; // Update tail to previous node
            if (mTail) mTail->next = nullptr; // Set new tail's next to null
        } else { // If current node is somewhere in middle
            curr->prev->next = curr->next; // Link previous node's next to current node's next
            curr->next->prev = curr->prev; // Link next node's previous to current node's previous
        }
        it++; // Move iterator to next node
        delete curr; // Delete current node
        --mSize; // Decrement size of list
    }

    DList& operator=(const DList& other) { // Assignment operator
        if (this != &other) { // Check for self-assignment
            clear(); // Clear current list
            for (Node* curr = other.mHead; curr != nullptr; curr = curr->next) { // Loop through other list
                addTail(curr->data); // Add each node to end
            }
        }
        return *this; // Return updated list
    }

    DList(const DList& other) : mHead(nullptr), mTail(nullptr), mSize(0) { // Copy constructor
        for (Node* curr = other.mHead; curr != nullptr; curr = curr->next) { // Loop through other list
            addTail(curr->data); // Add each node to end
        }
    }

    size_t size() const { return mSize; } // Return size
};

#endif // DLIST_H
