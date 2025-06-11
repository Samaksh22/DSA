#include <iostream>
#include "list.hpp"

int main()
{
    NodeList myList;

    std::cout << "--- Initial State ---" << std::endl;
    myList.printList();

    std::cout << "\n--- Inserting Elements ---" << std::endl;
    myList.insertBack(10);
    myList.insertFront(5);
    myList.insertBack(20);
    myList.insertFront(1);
    myList.printList();

    std::cout << "\n--- Iterating and Accessing Elements ---" << std::endl;
    Iterator it = myList.begin();
    std::cout << "First element: " << *it << std::endl;

    ++it;
    std::cout << "After increment: " << *it << std::endl;

    ++ ++it;
    std::cout << "After chained increment: " << *it << std::endl;

    --it;
    std::cout << "After decrement: " << *it << std::endl;

    std::cout << "\n--- Inserting using Iterator ---" << std::endl;
    myList.insert(it, 15);
    myList.printList();

    std::cout << "\n--- Erasing Elements ---" << std::endl;
    myList.eraseFront();
    myList.printList();

    myList.eraseBack();
    myList.printList();

    it = myList.begin();
    ++it; // Move to the second element (which is 5 now)
    std::cout << "Iterator points to before erase: " << *it << std::endl;
    myList.erase(it); // Erase 5
    myList.printList();

    std::cout << "\n--- Emptying the list ---" << std::endl;
    myList.eraseFront(); // Erase 1
    myList.eraseBack();  // Erase 10
    myList.printList();
    // myList.eraseFront(); // CAUTION: Calling this now will result in undefined behavior (crash)

    return 0;
}
