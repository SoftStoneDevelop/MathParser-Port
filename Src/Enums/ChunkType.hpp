#pragma once

namespace MathEngine
{
	enum class ExpressionType
	{
		//unique types
		None = 0,
		Number = 1,
		LeftBracket = 2,
		RightBracket = 3,

		//operators
		Multiplication = 10,
		Division = 11,
		Addition = 12,
		Subtraction = 13,

		//functions
		Sin = 100,
	};

	enum class ChunkType
	{
		//unique types
		None = 0,
		BaseExpression = 1,
		Number = 2,
		SequenceNumberOperation = 3,
	};

}//namespace MathEngine