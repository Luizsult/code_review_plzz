#ifndef LIST_OPERATIONS_H_
#define LIST_OPERATIONS_H_

#include <list>
#include <stdexcept>

enum class InputMethod {
    kKeyboard,
    kRandom,
    kFile
};

void InputList(std::list<int>& list, int size, InputMethod method, 
               const std::string& filename = "");
void PrintList(const std::list<int>& list);
void MoveMiddleToOtherList(std::list<int>& source, std::list<int>& destination);

#endif  
