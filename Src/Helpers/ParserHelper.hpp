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
    static const MathEngine::Operator Operators[] = 
    { 
        MathEngine::Operator(MathEngine::ChunkType::Multiplication, "*", 3, MathEngine::Associativity::Left),//0
        MathEngine::Operator(MathEngine::ChunkType::Division,       "/", 3, MathEngine::Associativity::Left),//1
        MathEngine::Operator(MathEngine::ChunkType::Addition,       "+", 2, MathEngine::Associativity::Left),//2
        MathEngine::Operator(MathEngine::ChunkType::Subtraction,    "-", 2, MathEngine::Associativity::Left)//3
    };

    static const MathEngine::Operator& GetMultiplication()
    {
        return Operators[0];
    }

    static const MathEngine::Operator& GetDivision()
    {
        return Operators[1];
    }

    static const MathEngine::Operator& GetAddition()
    {
        return Operators[2];
    }

    static const MathEngine::Operator& GetSubtraction()
    {
        return Operators[3];
    }

    static const MathEngine::Function Functions[] =
    {
        MathEngine::Function(MathEngine::ChunkType::Sin, "sin", 0, MathEngine::Associativity::None, 1),//0
    };

    static const MathEngine::Function& GetSin()
    {
        return Functions[0];
    }

    static const MathEngine::Operator LeftBracket(MathEngine::ChunkType::None, "(", 0, MathEngine::Associativity::None);
    static const MathEngine::Operator RightBracket(MathEngine::ChunkType::None, "(", 0, MathEngine::Associativity::None);
    static const MathEngine::Operand NumberOperand(MathEngine::ChunkType::Number);

    static int IsNumber(const char* chars, const int& size)
    {
        if (size < 1)
        {
            throw std::runtime_error("Empty array");
        }

        int i = 0;

        const char* number = std::find(std::begin(Numbers), std::end(Numbers), chars[i]);
        if (number == std::end(Numbers))
        {
            return -1;
        }

        if (size > 2 && chars[0] == '0' && chars[1] == '0')
        {
            throw std::runtime_error("Incorrect number");
        }

        bool findSeparator = false;
        for (; i < size; i++)
        {
            if (chars[i] == ' ')
            {
                return i;
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
                return i;
            }
        }
    }
}