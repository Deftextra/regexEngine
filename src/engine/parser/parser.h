#ifndef PARSER_H
#define PARSER_H

#include <string>

namespace Parser {
enum Operators
{
    Union = '|',
    closure = '*',
    concat = '.'
};

std::string
convertToExplictConcatPostFixExpression(std::string regex);

std::string
insertExplicitConcatOperator(std::string exp);

std::string
toPostFixExpression(std::string exp);

inline bool
isOperator(char token)
{
    return (token == Union || token == closure || token == concat);
}

inline bool
isBinary(char token)
{
    return (token == Union || token == concat);
}

inline bool
isUnary(char token)
{
    return (token == closure);
}
}

#endif // PARSER_H
