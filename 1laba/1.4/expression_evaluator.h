#ifndef EXPRESSION_EVALUATOR_H_
#define EXPRESSION_EVALUATOR_H_

#include <string>
#include <stdexcept>

int ParseNumber(const std::string& expression, size_t& pos);
int EvaluateTerm(const std::string& expression, size_t& pos);
int EvaluateExpression(const std::string& expression, size_t& pos);

#endif 
