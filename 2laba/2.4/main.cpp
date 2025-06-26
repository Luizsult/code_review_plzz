#include "circular_linked_list.h"
#include <iostream>

int main() {
  try {
    CircularLinkedList list;
    int n;

    std::cout << "Enter the number of elements to add to the list: ";
    std::cin >> n;
    
    if (n <= 0) {
      throw std::invalid_argument("Number of elements must be positive");
    }

    for (int i = 0; i < n; ++i) {
      int value;
      std::cout << "Enter element " << i + 1 << ": ";
      std::cin >> value;
      list.Append(value);
    }

    std::cout << "Original list: ";
    list.Display();

    list.RemoveNodesWithEqualNeighbors();
    
    std::cout << "Modified list: ";
    list.Display();

    if (!list.IsEmpty()) {
      std::cout << "Last node value: " << list.last_node()->value << "\n";
    }

  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}
