#include "gtest/gtest.h"
#include <parser/parser.h>
using namespace Parser;

struct Value
{
    std::string input;
    std::string expected;
};

class ConcatTest : public ::testing::TestWithParam<Value>
{};

class PostFixTest : public ::testing::TestWithParam<Value>
{};

TEST_P(ConcatTest, TurnsRegexIntoExplicitConcat)
{
    auto testValue = GetParam();

    ASSERT_EQ(insertExplicitConcatOperator(testValue.input),
              testValue.expected);
}

TEST_P(PostFixTest, TurnsRegexIntoPostfix)
{
    auto testValue = GetParam();

    ASSERT_EQ(toPostFixExpression(testValue.input), testValue.expected);
}

INSTANTIATE_TEST_CASE_P(Default,
                        ConcatTest,
                        testing::Values(Value{ "abc", "a.b.c" },
                                        Value{ "a|bc", "a|b.c" },
                                        Value{ "a*(l|k)", "a*.(l|k)" }));

INSTANTIATE_TEST_CASE_P(Default,
                        PostFixTest,
                        testing::Values(Value{ "a.b.c", "ab.c." },
                                        Value{ "a|b.c", "abc.|" },
                                        Value{ "a*.(l|k)", "a*lk|." },
                                        Value{ "(a|b).k", "ab|k." }));
