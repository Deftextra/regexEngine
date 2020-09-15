#include "parser.h"
#include <algorithm>
#include <istream>
#include <sstream>
#include <stack>
#include <string>

// --------------- Notes -------------------------
// Split tokens into operator and symbols.
// Act accordingly as we traverse the regex.
//--------------------------------------------------

// TODO: create proper exception classes.

using namespace Parser;

std::string
Parser::insertExplicitConcatOperator(std::string regex)
{
    std::string output;

    std::istringstream sRegex{ regex };
    sRegex >> std::noskipws;

    char token;

    while (sRegex >> token) {
        output += token;

        if (token == '(' || token == '|')
            continue;

        const char lookAhead = sRegex.peek();

        if (lookAhead == EOF)
            continue;

        if (lookAhead == closure || lookAhead == Union || lookAhead == ')')
            continue;

        output += concat;
    }

    return output;
}

std::string
Parser::toPostFixExpression(std::string concatRegex)
{
    std::istringstream sConcatRegex{ concatRegex };
    sConcatRegex >> std::noskipws;

    std::string output;
    std::stack<char> operators;

    char token;

    if (isOperator(sConcatRegex.peek()))
        throw "Operator cannot be the start of regex";

    while (sConcatRegex >> token) {
        const char lookAhead = sConcatRegex.peek();

        if (isBinary(token) && isBinary(lookAhead))
            throw "Two binary operators cannot percede eachoter";

        if (isBinary(token) && isUnary(lookAhead))
            throw "Unary opration cannot percede a binary operator";

        if (isBinary(token) && (lookAhead == ')'))
            throw "closing bracket cannot come after binary operation";

        if (isBinary(token) && lookAhead == EOF)
            throw "expression cannot end with binary expression";

        if (token == concat || token == Union || token == closure) {
            while (!operators.empty() && operators.top() != '(' &&
                   operators.top() <= token) {
                output += operators.top();
                operators.pop();
            }

            operators.push(token);
            continue;
        }

        if (token == '(') {
            operators.push(token);
            continue;
        }

        if (token == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output += operators.top();
                operators.pop();
            }

            if (operators.empty())
                throw ") at position " + std::to_string(sConcatRegex.tellg()) +
                  " has no opening tag";

            operators.pop();
            continue;
        }

        output += token;
    }

    while (!operators.empty()) {
        // TODO: To check for errors, count the numbers of symbols in the
        // output.
        output += operators.top();
        operators.pop();
    }

    return output;
}

std::string
Parser::convertToExplictConcatPostFixExpression(std::string regex)
{
    return toPostFixExpression(insertExplicitConcatOperator(regex));
}
