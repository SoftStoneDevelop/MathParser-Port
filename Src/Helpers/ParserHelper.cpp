#pragma once

#include "ParserHelper.hpp"
#include <stdexcept>

namespace MathEngine
{
    ParserHelper::ParserHelper() :
        _numbersSize{ 10 },
        Multiplication{ std::make_shared<Operator>(MathEngine::ExpressionType::Multiplication, 3, MathEngine::Associativity::Left) },
        Division{ std::make_shared<Operator>(MathEngine::ExpressionType::Division, 3, MathEngine::Associativity::Left) },
        Addition{ std::make_shared<Operator>(MathEngine::ExpressionType::Addition, 2, MathEngine::Associativity::Left) },
        Subtraction{ std::make_shared<Operator>(MathEngine::ExpressionType::Subtraction, 2, MathEngine::Associativity::Left) },
        Sin{ std::make_shared<Function>(MathEngine::ExpressionType::Sin, 0, MathEngine::Associativity::None, 1) },
        LeftBracket{ std::make_shared<Operator>(MathEngine::ExpressionType::LeftBracket, 0, MathEngine::Associativity::None) },
        RightBracket{ std::make_shared<Operator>(MathEngine::ExpressionType::RightBracket, 0, MathEngine::Associativity::None) },
        Number{ std::make_shared<Operand>(MathEngine::ExpressionType::Number) }
    {
        _numbers = new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    }

    ParserHelper::~ParserHelper()
    {
        delete[] _numbers;
    }

    bool ParserHelper::IsMultiplication(
        const char* chars,
        const int& size,
        const int& startIndex,
        int& skipLength
    )
    {
        if (chars[startIndex] == '*')
        {
            skipLength = 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool ParserHelper::IsDivision(
        const char* chars,
        const int& size,
        const int& startIndex,
        int& skipLength
    )
    {
        if (chars[startIndex] == '/')
        {
            skipLength = 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool ParserHelper::IsAddition(
        const char* chars,
        const int& size,
        const int& startIndex,
        int& skipLength
    )
    {
        if (chars[startIndex] == '+')
        {
            skipLength = 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool ParserHelper::IsSubtraction(
        const char* chars,
        const int& size,
        const int& startIndex,
        int& skipLength
    )
    {
        if (chars[startIndex] == '-')
        {
            skipLength = 1;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool ParserHelper::IsSin(
        const char* chars,
        const int& size,
        const int& startIndex,
        int& skipLength
    )
    {
        if (size - startIndex < 3)
        {
            return false;
        }

        if (chars[startIndex] == 's' &&
            chars[startIndex + 1] == 'i' &&
            chars[startIndex + 2] == 'n'
            )
        {
            skipLength = 3;
            return true;
        }

        return false;
    }

    bool ParserHelper::CanBeNegativeNumber(const ExpressionType& lastType)
    {
        return 
            lastType != ExpressionType::RightBracket && 
            lastType != ExpressionType::Number;
    }

    int ParserHelper::IsNumber(const char* chars, const int& size, int startIndex, const bool& canBeNagative)
    {
        int payload = size - startIndex;
        if (payload < 1)
        {
            throw std::runtime_error("Empty array");
        }

        int i = startIndex;
        if (canBeNagative && chars[i] == '-')
        {
            i++;
        }

        const char* number = std::find(_numbers, _numbers + _numbersSize, chars[i]);
        if (number == _numbers + _numbersSize)
        {
            return -1;
        }

        if (payload > 2 && chars[i] == '0' && chars[i + 1] == '0')
        {
            throw std::runtime_error("Incorrect number");
        }

        bool findSeparator = false;
        for (; i < size; i++)
        {
            if (chars[i] == ' ')
            {
                break;
            }

            number = std::find(_numbers, _numbers + _numbersSize, chars[i]);
            if (number != _numbers + _numbersSize)
            {
                continue;
            }
            else if (chars[i] == ',' || chars[i] == '.')
            {
                if (findSeparator)
                {
                    throw std::runtime_error("Double separator in number");
                }

                if (i + 1 == size)
                {
                    throw std::runtime_error("Unexpected end of number");
                }

                findSeparator = true;
                continue;
            }
            else
            {
                break;
            }
        }

        return i - startIndex;
    }
}