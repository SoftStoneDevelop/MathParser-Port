#pragma once

#include "..\Records\Operator.hpp"
#include "..\Enums\ChunkType.hpp"
#include "..\Enums\Associativity.hpp"
#include "..\Records\Function.hpp"
#include "..\Records\Operand.hpp"
#include <stdexcept>

namespace ParserHelper
{
    static const char Numbers[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    bool IsMultiplication(
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

    static MathEngine::Operator* CreateMultiplication()
    {
        return new MathEngine::Operator(MathEngine::ExpressionType::Multiplication, 3, MathEngine::Associativity::Left);
    }

    bool IsDivision(
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

    static MathEngine::Operator* CreateDivision()
    {
        return new MathEngine::Operator(MathEngine::ExpressionType::Division, 3, MathEngine::Associativity::Left);
    }

    bool IsAddition(
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

    static MathEngine::Operator* CreateAddition()
    {
        return new MathEngine::Operator(MathEngine::ExpressionType::Addition, 2, MathEngine::Associativity::Left);
    }

    bool IsSubtraction(
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

    static MathEngine::Operator* CreateSubtraction()
    {
        return new MathEngine::Operator(MathEngine::ExpressionType::Subtraction, 2, MathEngine::Associativity::Left);
    }

    bool IsSin(
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
            chars[startIndex + 1] == 'i'&&
            chars[startIndex + 2] == 'n'
            )
        {
            skipLength = 3;
            return true;
        }

        return false;
    }

    static MathEngine::Function* CreateSin()
    {
        return new MathEngine::Function(MathEngine::ExpressionType::Sin, 0, MathEngine::Associativity::None, 1);
    }

    static MathEngine::Operator* CreateLeftBracket()
    {
        return new MathEngine::Operator(MathEngine::ExpressionType::LeftBracket, 0, MathEngine::Associativity::None);
    }

    static MathEngine::Operator* CreateRightBracket()
    {
        return new MathEngine::Operator(MathEngine::ExpressionType::RightBracket, 0, MathEngine::Associativity::None);
    }

    static MathEngine::Operand* CreateNumber()
    {
        return new MathEngine::Operand(MathEngine::ExpressionType::Number);
    }

    static int IsNumber(const char* chars, const int& size, int startIndex)
    {
        int payload = size - startIndex;
        if (payload < 1)
        {
            throw std::runtime_error("Empty array");
        }

        const char* number = std::find(std::begin(Numbers), std::end(Numbers), chars[startIndex]);
        if (number == std::end(Numbers))
        {
            return -1;
        }

        if (payload > 2 && chars[startIndex] == '0' && chars[startIndex + 1] == '0')
        {
            throw std::runtime_error("Incorrect number");
        }

        bool findSeparator = false;
        int i = startIndex;
        for (; i < size; i++)
        {
            if (chars[i] == ' ')
            {
                break;
            }

            number = std::find(std::begin(Numbers), std::end(Numbers), chars[i]);
            if (number != std::end(Numbers))
            {
                continue;
            }
            else if(chars[i] == ',' || chars[i] == '.')
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