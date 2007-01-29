#include <math/Math.h>
#include <math/Matrix4x4.h>

namespace Math {

std::ostream &operator<<(std::ostream &os, Matrix4x4 &v)
{
	os << "[ " << v.val[0] << " " << v.val[1] << " " << v.val[2] << " " << v.val[3] << " ]" << std::endl;
	os << "[ " << v.val[4] << " " << v.val[5] << " " << v.val[6] << " " << v.val[7] << " ]" << std::endl;
	os << "[ " << v.val[8] << " " << v.val[9] << " " << v.val[10] << " " << v.val[11] << " ]" << std::endl;
	os << "[ " << v.val[12] << " " << v.val[13] << " " << v.val[14] << " " << v.val[15] << " ]";
	return os;
}

Matrix4x4::Matrix4x4(const Matrix4x4 &m)
{
	for (int i = 0; i < 16; i++)
		val[i] = m.val[i];
}

Matrix4x4 &Matrix4x4::operator=(const Matrix4x4 &m)
{
	if (this == &m)
		return *this;

	for (int i = 0; i < 16; i++)
		val[i] = m.val[i];

	return *this;
}

Matrix4x4 &Matrix4x4::SetIdentity()
{
	val[0] = 1;
	val[1] = 0;
	val[2] = 0;
	val[3] = 0;
	val[4] = 0;
	val[5] = 1;
	val[6] = 0;
	val[7] = 0;
	val[8] = 0;
	val[9] = 0;
	val[10] = 1;
	val[11] = 0;
	val[12] = 0;
	val[13] = 0;
	val[14] = 0;
	val[15] = 1;
	return *this;
}

Matrix4x4 &Matrix4x4::SetScaling(float scale)
{
	val[0] = scale;
	val[1] = 0;
	val[2] = 0;
	val[3] = 0;
	val[4] = 0;
	val[5] = scale;
	val[6] = 0;
	val[7] = 0;
	val[8] = 0;
	val[9] = 0;
	val[10] = scale;
	val[11] = 0;
	val[12] = 0;
	val[13] = 0;
	val[14] = 0;
	val[15] = 1;
	return *this;
}


Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &m) const
{
	Matrix4x4 result;

	for (int i = 0; i < 16; i++)
		result.val[i] = val[i] + m.val[i];

	return result;
}

Matrix4x4 &Matrix4x4::operator+=(const Matrix4x4 &m)
{
	for (int i = 0; i < 16; i++)
		val[i] += m.val[i];

	return *this;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &m) const
{
	Matrix4x4 result;

	for (int i = 0; i < 16; i++)
		result.val[i] = val[i] - m.val[i];

	return result;
}

Matrix4x4 &Matrix4x4::operator-=(const Matrix4x4 &m)
{
	for (int i = 0; i < 16; i++)
		val[i] -= m.val[i];

	return *this;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &m) const
{
	Matrix4x4 result;

	result.val[0] = val[0] *  m.val[0] +
					val[4] *  m.val[1] +
					val[8] *  m.val[2] +
					val[12] * m.val[4];
	result.val[1] = val[1] *  m.val[0] +
					val[5] *  m.val[1] +
					val[9] *  m.val[2] +
					val[13] * m.val[4];
	result.val[2] = val[2] *  m.val[0] +
					val[6] *  m.val[1] +
					val[10] * m.val[2] +
					val[14] * m.val[4];
	result.val[3] = val[3] *  m.val[0] +
					val[7] *  m.val[1] +
					val[11] * m.val[2] +
					val[15] * m.val[4];

	result.val[4] = val[0] *  m.val[4] +
					val[4] *  m.val[5] +
					val[8] *  m.val[6] +
					val[12] * m.val[7];
	result.val[5] = val[1] *  m.val[4] +
					val[5] *  m.val[5] +
					val[9] *  m.val[6] +
					val[13] * m.val[7];
	result.val[6] = val[2] *  m.val[4] +
					val[6] *  m.val[5] +
					val[10] * m.val[6] +
					val[14] * m.val[7];
	result.val[7] = val[3] *  m.val[4] +
					val[7] *  m.val[5] +
					val[11] * m.val[6] +
					val[15] * m.val[7];

	result.val[8] = val[0] *  m.val[8] +
					val[4] *  m.val[9] +
					val[8] *  m.val[10] +
					val[12] * m.val[11];
	result.val[9] = val[1] *  m.val[8] +
					val[5] *  m.val[9] +
					val[9] *  m.val[10] +
					val[13] * m.val[11];
	result.val[10] = val[2] *  m.val[8] +
					 val[6] *  m.val[9] +
					 val[10] * m.val[10] +
					 val[14] * m.val[11];
	result.val[11] = val[3] *  m.val[8] +
					 val[7] *  m.val[9] +
					 val[11] * m.val[10] +
					 val[15] * m.val[11];

	result.val[12] = val[0] *  m.val[12] +
					val[4] *  m.val[13] +
					val[8] *  m.val[14] +
					val[12] * m.val[15];
	result.val[13] = val[1] *  m.val[12] +
					val[5] *  m.val[13] +
					val[9] *  m.val[14] +
					val[13] * m.val[15];
	result.val[14] = val[2] *  m.val[12] +
					 val[6] *  m.val[13] +
					 val[10] * m.val[14] +
					 val[14] * m.val[15];
	result.val[15] = val[3] *  m.val[12] +
					 val[7] *  m.val[13] +
					 val[11] * m.val[14] +
					 val[15] * m.val[15];

	return result;
}

Matrix4x4 &Matrix4x4::operator*=(const Matrix4x4 &m)
{
	Matrix4x4 result;

	result.val[0] = val[0] *  m.val[0] +
					val[4] *  m.val[1] +
					val[8] *  m.val[2] +
					val[12] * m.val[4];
	result.val[1] = val[1] *  m.val[0] +
					val[5] *  m.val[1] +
					val[9] *  m.val[2] +
					val[13] * m.val[4];
	result.val[2] = val[2] *  m.val[0] +
					val[6] *  m.val[1] +
					val[10] * m.val[2] +
					val[14] * m.val[4];
	result.val[3] = val[3] *  m.val[0] +
					val[7] *  m.val[1] +
					val[11] * m.val[2] +
					val[15] * m.val[4];

	result.val[4] = val[0] *  m.val[4] +
					val[4] *  m.val[5] +
					val[8] *  m.val[6] +
					val[12] * m.val[7];
	result.val[5] = val[1] *  m.val[4] +
					val[5] *  m.val[5] +
					val[9] *  m.val[6] +
					val[13] * m.val[7];
	result.val[6] = val[2] *  m.val[4] +
					val[6] *  m.val[5] +
					val[10] * m.val[6] +
					val[14] * m.val[7];
	result.val[7] = val[3] *  m.val[4] +
					val[7] *  m.val[5] +
					val[11] * m.val[6] +
					val[15] * m.val[7];

	result.val[8] = val[0] *  m.val[8] +
					val[4] *  m.val[9] +
					val[8] *  m.val[10] +
					val[12] * m.val[11];
	result.val[9] = val[1] *  m.val[8] +
					val[5] *  m.val[9] +
					val[9] *  m.val[10] +
					val[13] * m.val[11];
	result.val[10] = val[2] *  m.val[8] +
					 val[6] *  m.val[9] +
					 val[10] * m.val[10] +
					 val[14] * m.val[11];
	result.val[11] = val[3] *  m.val[8] +
					 val[7] *  m.val[9] +
					 val[11] * m.val[10] +
					 val[15] * m.val[11];

	result.val[12] = val[0] *  m.val[12] +
					val[4] *  m.val[13] +
					val[8] *  m.val[14] +
					val[12] * m.val[15];
	result.val[13] = val[1] *  m.val[12] +
					val[5] *  m.val[13] +
					val[9] *  m.val[14] +
					val[13] * m.val[15];
	result.val[14] = val[2] *  m.val[12] +
					 val[6] *  m.val[13] +
					 val[10] * m.val[14] +
					 val[14] * m.val[15];
	result.val[15] = val[3] *  m.val[12] +
					 val[7] *  m.val[13] +
					 val[11] * m.val[14] +
					 val[15] * m.val[15];

	for (unsigned int i = 0; i < 16; i++)
		val[i] = result.val[i];

	return *this;
}

}

