#include "Matrix4x4.h"

namespace Math{


	Matrix4x4 Matrix4x4::getMatrixIndentity()const
	{
		Matrix4x4 indentityMatrix(*this);
		indentityMatrix.identity();
		return indentityMatrix;
	}


	std::ostream& operator<<(std::ostream& stream, const Matrix4x4 & Matrix)
	{
		const int wide = 4;
		for (int i = 0; i < wide; i++)
		{
			for (int j = 0; j < wide; j++)
			{
				stream << "Matrix4x4[" << i << "][" << j << "] is " << Matrix.matrix[i][j] << std::endl;
			}
		}
		return stream;
	}
}