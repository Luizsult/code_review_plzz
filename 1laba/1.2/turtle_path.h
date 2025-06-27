#ifndef TURTLE_PATH_H
#define TURTLE_PATH_H

#include <vector>
#include <string>

std::vector<std::vector<int>> ReadBoardFromFile(const std::string& filename, int& n);
int CalculateMinPath(const std::vector<std::vector<int>>& board);
void WriteResultToFile(const std::string& filename, int result);

#endif  
