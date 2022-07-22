#pragma once

#include "..\Records\Operator.hpp"
#include "..\Enums\ChunkType.hpp"
#include "..\Enums\Associativity.hpp"
#include "..\Records\Function.hpp"
#include "..\Records\Operand.hpp"
#include <memory>

namespace MathEngine
{
    class ParserHelper
    {
    public:
        ParserHelper();
        ~ParserHelper();

        ParserHelper(const ExpressionItem& other) = delete;
        ParserHelper(ExpressionItem&& other) = delete;

        ParserHelper& operator=(ExpressionItem&& other) = delete;
        ParserHelper& operator=(const ExpressionItem& other) = delete;

        bool IsMultiplication(
            const char* chars,
            const int& size,
            const int& startIndex,
            int& skipLength
        );

        bool IsDivision(
            const char* chars,
            const int& size,
            const int& startIndex,
            int& skipLength
        );

        bool IsAddition(
            const char* chars,
            const int& size,
            const int& startIndex,
            int& skipLength
        );

        bool IsSubtraction(
            const char* chars,
            const int& size,
            const int& startIndex,
            int& skipLength
        );

        bool IsSin(
            const char* chars,
            const int& size,
            const int& startIndex,
            int& skipLength
        );

        bool CanBeNegativeNumber(const ExpressionType& lastType);

        int IsNumber(const char* chars, const int& size, int startIndex, const bool& canBeNagative);

        const std::shared_ptr<Operator> Multiplication;
        const std::shared_ptr<Operator> Division;
        const std::shared_ptr<Operator> Addition;
        const std::shared_ptr<Operator> Subtraction;

        const std::shared_ptr<Function> Sin;

        const std::shared_ptr<Operator> LeftBracket;
        const std::shared_ptr<Operator> RightBracket;
        const std::shared_ptr<Operand> Number;
    private:
        const char* _numbers;
        const int _numbersSize;
    };
}