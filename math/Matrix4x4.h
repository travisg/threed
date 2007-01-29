#ifndef __MATRIX4X4_H
#define __MATRIX4X4_H

namespace Math {

class Matrix4x4
{
public:
	inline Matrix4x4() {}
	inline ~Matrix4x4() {}

	/* constructors */
	Matrix4x4(const Matrix4x4 &v);
	Matrix4x4 &operator=(const Matrix4x4 &v);

	/* set the matrix to various ops */
	Matrix4x4 &SetIdentity();
	Matrix4x4 &SetScaling(float scale);

	/* operators */
	Matrix4x4 operator+(const Matrix4x4 &v) const;
	Matrix4x4 &operator+=(const Matrix4x4 &v);
	Matrix4x4 operator-(const Matrix4x4 &v) const;
	Matrix4x4 &operator-=(const Matrix4x4 &v);
	Matrix4x4 operator*(const Matrix4x4 &v) const;
	Matrix4x4 &operator*=(const Matrix4x4 &v);

	/* data */
	float val[16];
};

/* debugging */
std::ostream &operator<<(std::ostream &os, Matrix4x4 &v);

}

#endif

