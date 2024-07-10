#include <iostream>
#include "DList.h"

int main() {
    DList list; // Create doubly linked list
    list.addHead(10); // Add 10 at head
    list.addTail(20); // Add 20 at tail
    list.addTail(30); // Add 30 at tail

    std::cout << "List after adding 10, 20, 30: ";
    for (Iterator it = list.begin(); it != list.end(); ++it) { // Iterate through list
        std::cout << *it << " "; // Print each element
    }
    std::cout << std::endl;

    list.insert(list.begin(), 5); // Insert 5 at beginning
    list.insert(list.end(), 35); // Insert 35 at end

    std::cout << "List after inserting 5 at beginning and 35 at end: ";
    for (Iterator it = list.begin(); it != list.end(); ++it) { // Iterate through list
        std::cout << *it << " "; // Print each element
    }
    std::cout << std::endl;

    return 0;
}
