#ifndef __MATRIX4X4_H
#define __MATRIX4X4_H

namespace Math {

template <class T>
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
	Matrix4x4 &SetScaling(T scale);

	/* operators */
	Matrix4x4 operator+(const Matrix4x4 &v) const;
	Matrix4x4 &operator+=(const Matrix4x4 &v);
	Matrix4x4 operator-(const Matrix4x4 &v) const;
	Matrix4x4 &operator-=(const Matrix4x4 &v);
	Matrix4x4 operator*(const Matrix4x4 &v) const;
	Matrix4x4 &operator*=(const Matrix4x4 &v);

	/* data */
	T val[16];
};

typedef Matrix4x4<float> Matrix4x4f;
typedef Matrix4x4<double> Matrix4x4d;

/* debugging */
template <class T>
std::ostream &operator<<(std::ostream &os, Matrix4x4<T> &v)
{
	os << "[ " << v.val[0] << " " << v.val[1] << " " << v.val[2] << " " << v.val[3] << " ]" << std::endl;
	os << "[ " << v.val[4] << " " << v.val[5] << " " << v.val[6] << " " << v.val[7] << " ]" << std::endl;
	os << "[ " << v.val[8] << " " << v.val[9] << " " << v.val[10] << " " << v.val[11] << " ]" << std::endl;
	os << "[ " << v.val[12] << " " << v.val[13] << " " << v.val[14] << " " << v.val[15] << " ]";
	return os;
}

}

#endif

