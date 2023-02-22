/*
 * Author  : ����(Axin Chen)
 * E-mail  : axin.chen@raythinktech.com, m13647412733@163.com
 * Mobile  : (+86)136 4741 2733
 * Comment : ��Ⱦ���泣����ѧ��
 */

#pragma once
#include <cmath>
#include <memory>

class Mathf;
class Vec2;
class Vec3;
class Vec4;
class Matrix2x2;
class Matrix3x3;
class Matrix4x4;
class Quaternion;

class Mathf final
{
public:
	/// <summary>
	/// �����ֵ
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	static inline float Abs(float num) {
		return fabsf(num);
	}

	/// <summary>
	/// ��eΪ������n�Ķ���
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	static inline float Loge(float num) {
		return logf(num);
	}

	/// <summary>
	/// ����fΪ������p�Ķ���
	/// </summary>
	/// <param name="f"></param>
	/// <param name="p"></param>
	/// <returns></returns>
	static inline float Log(float f, float p) {
		return logf(p) / logf(f);
	}

	/// <summary>
	/// ����10Ϊ������n�Ķ���
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	static inline float Log10(float num) {
		return log10f(num);
	}

	/// <summary>
	/// ����2Ϊ������n�Ķ���
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	static inline float Log2(float num) {
		return log2f(num);
	}

	/// <summary>
	/// ��ƽ����
	/// (�������ƽ�����㷨�ƺ���û�����ƣ����ܱ�׼���Ѿ����Ż���)
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	static inline float Sqrt(float num) {
		return sqrtf(num);
	}

	/// <summary>
	/// ��n��p����
	/// </summary>
	/// <param name="n"></param>
	/// <param name="p"></param>
	/// <returns></returns>
	static inline float Pow(float n, float p) {
		return powf(n, p);
	}

	/// <summary>
	/// ��n��p����
	/// �����ݣ�Ҫ��p>=0
	/// </summary>
	/// <param name="n"></param>
	/// <param name="p"></param>
	/// <returns></returns>
	static float FPow(float n, int p);

	/// <summary>
	/// ��n��p����
	/// �����ݣ�Ҫ��p>=0
	/// </summary>
	/// <param name="n"></param>
	/// <param name="p"></param>
	/// <returns></returns>
	static int FPow(int n, int p);

	/// <summary>
	/// ����num�ķ�Χ
	/// </summary>
	/// <param name="num">����</param>
	/// <param name="min">С�߽�</param>
	/// <param name="max">��߽�</param>
	/// <returns></returns>
	static float Clamp(float num, float min, float max);

	/// <summary>
	/// ����num�ķ�Χ��0.0��1.0֮��
	/// </summary>
	/// <param name="num"></param>
	/// <returns></returns>
	static inline float Saturate(float num) {
		return Clamp(num, 0.0f, 1.0f);
	}

	/// <summary>
	/// ���Բ�ֵ
	/// </summary>
	/// <param name="from">���</param>
	/// <param name="to">�յ�</param>
	/// <param name="k">ϵ��</param>
	/// <param name="limit">�Ƿ�����ϵ����0-1</param>
	/// <returns></returns>
	static float Lerp(float from, float to, float k, bool limit = true);

	static const float PI;			//Բ����
	static const float Deg2Rad;		//�Ƕ�ת����ϵ��
	static const float Rad2Deg;		//����ת�Ƕ�ϵ��

	/// <summary>
	/// ��Ƕ�sinֵ
	/// </summary>
	/// <param name="rad">�Ƕ�(����)</param>
	/// <returns></returns>
	static inline float Sin(float rad) {
		return sinf(rad);
	}

	/// <summary>
	/// ��Ƕ�cosֵ
	/// </summary>
	/// <param name="rad">�Ƕ�(����)</param>
	/// <returns></returns>
	static inline float Cos(float rad) {
		return cosf(rad);
	}

	/// <summary>
	/// ��Ƕ�tanֵ
	/// </summary>
	/// <param name="rad">�Ƕ�(����)</param>
	/// <returns></returns>
	static inline float Tan(float rad) {
		return tanf(rad);
	}

	/// <summary>
	/// ��sinֵ��Ӧ�ĽǶ�
	/// </summary>
	/// <param name="num">sinֵ</param>
	/// <returns>�Ƕ�(����)</returns>
	static inline float Asin(float num) {
		return asinf(num);
	}

	/// <summary>
	/// ��cosֵ��Ӧ�ĽǶ�
	/// </summary>
	/// <param name="num">cosֵ</param>
	/// <returns>�Ƕ�(����)</returns>
	static inline float Acos(float num) {
		return acosf(num);
	}

	/// <summary>
	/// ��tanֵ��Ӧ�ĽǶ�
	/// </summary>
	/// <param name="num">tanֵ</param>
	/// <returns>�Ƕ�(����)</returns>
	static inline float Atan(float num) {
		return atanf(num);
	}

	/// <summary>
	/// ��(x, y)������x����н�
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	static inline float Atan2(float x, float y) {
		return atan2f(y, x);
	}
};

/// <summary>
/// 2D����, ��ά��������ʽת��Ϊ��ά�����������ע��������ѧ����
/// </summary>
class Vec2 final
{
private:
	float m_x, m_y;
public:
	/// <summary>
	/// (0, 0)
	/// </summary>
	Vec2();
	Vec2(float x, float y);
	Vec2(const Vec2& other);

	/// <summary>
	/// (o.x, o.y)
	/// </summary>
	/// <param name="other"></param>
	/// 
	Vec2(const Vec3& other);

	/// <summary>
	/// (o.x, o.y, o.z)
	/// </summary>
	/// <param name="other"></param>
	Vec2(const Vec4& other);

	inline float& operator[](int n) {
		return *((float*)this + n);
	}
	inline const float& operator[](int n) const {
		return *((float*)this + n);
	}
	inline float GetX() const {
		return m_x;
	}
	inline float GetY() const {
		return m_y;
	}
	inline void SetX(float x) {
		m_x = x;
	}
	inline void SetY(float y) {
		m_y = y;
	}
	inline void Set(float x, float y) {
		SetX(x);
		SetY(y);
	}

	/// <summary>
	/// ������ģ����ƽ��
	/// </summary>
	/// <returns></returns>
	inline float LenSquare() const {
		return m_x * m_x + m_y * m_y;
	}

	/// <summary>
	/// ������ģ��
	/// </summary>
	/// <returns></returns>
	inline float Len() const {
		return Mathf::Sqrt(LenSquare());
	}

	/// <summary>
	/// ���һ������������������С��1E-05ʱ��������������
	/// </summary>
	/// <returns></returns>
	Vec2 Normalized() const;

	/// <summary>
	/// ����һ��ľ���ƽ��
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline float DistSquare(const Vec2& other) const {
		float x = m_x - other.m_x, y = m_y - other.m_y;
		return x * x + y * y;
	}

	/// <summary>
	/// ����һ��ľ���
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline float Dist(const Vec2& other) const {
		return Mathf::Sqrt(DistSquare(other));
	}

	/// <summary>
	/// �������
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline float Dot(const Vec2& other) const {
		return this->m_x * other.m_x + this->m_y * other.m_y;
	}

	/// <summary>
	/// �������Բ�ֵ
	/// </summary>
	/// <param name="other">��ΪĿ�ĵ�</param>
	/// <param name="k">��ֵϵ��</param>
	/// <param name="limit">�Ƿ�����ϵ����0-1</param>
	/// <returns>��ֵ��</returns>
	Vec2 Lerp(const Vec2& other, float k, bool limit = true) const;
	
	inline Vec2 operator-() const {
		return Vec2(-m_x, -m_y);
	}
	inline Vec2 operator+(const Vec2& other) const {
		return Vec2(this->m_x + other.m_x, this->m_y + other.m_y);
	}
	inline Vec2 operator+(float num) const {
		return Vec2(this->m_x + num, this->m_y + num);
	}
	inline Vec2 operator-(const Vec2& other) const {
		return Vec2(this->m_x - other.m_x, this->m_y - other.m_y);
	}
	inline Vec2 operator-(float num) const {
		return Vec2(this->m_x - num, this->m_y - num);
	}
	inline Vec2 operator*(const Vec2& other) const {
		return Vec2(this->m_x * other.m_x, this->m_y * other.m_y);
	}
	inline Vec2 operator*(float num) const {
		return Vec2(this->m_x * num, this->m_y * num);
	}

	static Vec2 Zero() {
		return Vec2();
	}
	static Vec2 One() {
		return Vec2(1.0f, 1.0f);
	}
	static Vec2 Up() {
		return Vec2(0.0f, 1.0f);
	}
	static Vec2 Down() {
		return Vec2(0.0f, -1.0f);
	}
	static Vec2 Right() {
		return Vec2(1.0f, 0.0f);
	}
	static Vec2 Left() {
		return Vec2(-1.0f, 0.0f);
	}
};

/// <summary>
/// 3D����, ��ά��������ʽת��Ϊ��ά�����������ע��������ѧ����
/// </summary>
class Vec3 final
{
private:
	float m_x, m_y, m_z;
public:
	/// <summary>
	/// (0, 0, 0)
	/// </summary>
	Vec3();
	Vec3(float x, float y, float z);

	/// <summary>
	/// (o.x, o.y, 0)
	/// </summary>
	/// <param name="other"></param>
	explicit Vec3(const Vec2& other);
	Vec3(const Vec3& other);
	
	/// <summary>
	/// (o.x, o.y, o.z)
	/// </summary>
	/// <param name="other"></param>
	Vec3(const Vec4& other);

	inline float& operator[](int n) {
		return *((float*)this + n);
	}
	inline const float& operator[](int n) const {
		return *((float*)this + n);
	}
	inline float GetX() const {
		return m_x;
	}
	inline float GetY() const {
		return m_y;
	}
	inline float GetZ() const {
		return m_z;
	}
	inline void SetX(float x) {
		this->m_x = x;
	}
	inline void SetY(float y) {
		this->m_y = y;
	}
	inline void SetZ(float z) {
		this->m_z = z;
	}
	inline void Set(float x, float y, float z) {
		SetX(x);
		SetY(y);
		SetZ(z);
	}

	/// <summary>
	/// ������ģ��ƽ��
	/// </summary>
	/// <returns></returns>
	inline float LenSquare() const {
		return m_x * m_x + m_y * m_y + m_z * m_z;
	}

	/// <summary>
	/// ������ģ��
	/// </summary>
	/// <returns></returns>
	inline float Len() const {
		return Mathf::Sqrt(LenSquare());
	}

	/// <summary>
	/// ��һ���������������ģ��С��1E-05��������������
	/// </summary>
	/// <returns></returns>
	Vec3 Normalized() const;

	/// <summary>
	/// ����һ��ľ���ƽ��
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline float DistSquare(const Vec3& other) const {
		float x = m_x - other.m_x, y = m_y - other.m_y, z = m_z - other.m_z;
		return x * x + y * y + z * z;
	}

	/// <summary>
	/// ����һ��ľ���
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline float Dist(const Vec3& other) const {
		return Mathf::Sqrt(DistSquare(other));
	}

	/// <summary>
	/// �������
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline float Dot(const Vec3& other) const {
		return this->m_x * other.m_x + this->m_y * other.m_y + this->m_z * other.m_z;
	}

	/// <summary>
	/// �������
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline Vec3 Cross(const Vec3& other) const {
		return Vec3(
			m_y * other.m_z - m_z * other.m_y,
			m_z * other.m_x - m_x * other.m_z,
			m_x * other.m_y - m_y * other.m_x
		);
	}

	/// <summary>
	/// �������Բ�ֵ
	/// </summary>
	/// <param name="other">��ΪĿ�ĵ�</param>
	/// <param name="k">��ֵϵ��</param>
	/// <param name="limit">�Ƿ����Ʋ�ֵϵ����0-1</param>
	/// <returns>��ֵ��</returns>
	Vec3 Lerp(const Vec3& other, float k, bool limit = true) const;

	inline Vec3 operator-() const {
		return Vec3(-m_x, -m_y, -m_z);
	}
	inline Vec3 operator+(const Vec3& other) const {
		return Vec3(this->m_x + other.m_x, this->m_y + other.m_y, this->m_z + other.m_z);
	}
	inline Vec3 operator+(float num) const {
		return Vec3(this->m_x + num, this->m_y + num, this->m_z + num);
	}
	inline Vec3 operator-(const Vec3& other) const {
		return Vec3(this->m_x - other.m_x, this->m_y - other.m_y, this->m_z - other.m_z);
	}
	inline Vec3 operator-(float num) const {
		return Vec3(this->m_x - num, this->m_y - num, this->m_z - num);
	}
	inline Vec3 operator*(const Vec3& other) const {
		return Vec3(this->m_x * other.m_x, this->m_y * other.m_y, this->m_z * other.m_z);
	}
	inline Vec3 operator*(float num) const {
		return Vec3(this->m_x * num, this->m_y * num, this->m_z * num);
	}

	static Vec3 Zero() {
		return Vec3();
	}
	static Vec3 One() {
		return Vec3(1.0f, 1.0f, 1.0f);
	}
	static Vec3 Up() {
		return Vec3(0.0f, 1.0f, 0.0f);
	}
	static Vec3 Down() {
		return Vec3(0.0f, -1.0f, 0.0f);
	}
	static Vec3 Right() {
		return Vec3(1.0f, 0.0f, 0.0f);
	}
	static Vec3 Left() {
		return Vec3(-1.0f, 0.0f, 0.0f);
	}
	static Vec3 Front() {
		return Vec3(0.0f, 0.0f, 1.0f);
	}
	static Vec3 Back() {
		return Vec3(0.0f, 0.0f, -1.0f);
	}
};

/// <summary>
/// 4D����, ��ά��������ʽת��Ϊ��ά�����������ע��������ѧ����
/// </summary>
class Vec4 final
{
private:
	float m_x, m_y, m_z, m_w;
public:
	/// <summary>
	/// (0, 0, 0, 0)
	/// </summary>
	Vec4();
	Vec4(float x, float y, float z, float w);

	/// <summary>
	/// (o.x, o.y, 0, 0)
	/// </summary>
	/// <param name="other"></param>
	explicit Vec4(const Vec2& other);

	/// <summary>
	/// (o.x, o.y, o.z, 0)
	/// </summary>
	/// <param name="other"></param>
	explicit Vec4(const Vec3& other);
	Vec4(const Vec4& other);

	inline float& operator[](int n) {
		return *((float*)this + n);
	}
	inline const float& operator[](int n) const {
		return *((float*)this + n);
	}
	inline float GetX() const {
		return m_x;
	}
	inline float GetY() const {
		return m_y;
	}
	inline float GetZ() const {
		return m_z;
	}
	inline float GetW() const {
		return m_w;
	}
	inline void SetX(float x) {
		this->m_x = x;
	}
	inline void SetY(float y) {
		this->m_y = y;
	}
	inline void SetZ(float z) {
		this->m_z = z;
	}
	inline void SetW(float w) {
		this->m_w = m_w;
	}
	inline void Set(float x, float y, float z, float w) {
		SetX(x);
		SetY(y);
		SetZ(z);
		SetW(w);
	}

	inline Vec4 operator-() const {
		return Vec4(-m_x, -m_y, -m_z, -m_w);
	}
	inline Vec4 operator+(const Vec4& other) const {
		return Vec4(this->m_x + other.m_x, this->m_y + other.m_y, this->m_z + other.m_z, this->m_w + other.m_w);
	}
	inline Vec4 operator+(float num) const {
		return Vec4(this->m_x + num, this->m_y + num, this->m_z + num, this->m_w + num);
	}
	inline Vec4 operator-(const Vec4& other) const {
		return Vec4(this->m_x - other.m_x, this->m_y - other.m_y, this->m_z - other.m_z, this->m_w - m_w);
	}
	inline Vec4 operator-(float num) const {
		return Vec4(this->m_x - num, this->m_y - num, this->m_z - num, this->m_w - num);
	}
	inline Vec4 operator*(const Vec4& other) const {
		return Vec4(this->m_x * other.m_x, this->m_y * other.m_y, this->m_z * other.m_z, this->m_w * other.m_w);
	}
	inline Vec4 operator*(float num) const {
		return Vec4(this->m_x * num, this->m_y * num, this->m_z * num, this->m_w * num);
	}

	static Vec4 Zero() {
		return Vec4();
	}
	static Vec4 One() {
		return Vec4(1.0f, 1.0f, 1.0f, 1.0f);
	}
};

/// <summary>
/// 2x2������ע�����˷���˳���Խ�����Ӱ��
/// </summary>
class Matrix2x2 final
{
private:
	float m_p[2][2];
public:
	/// <summary>
	/// ����ȫ������
	/// </summary>
	Matrix2x2();
	Matrix2x2(const Matrix2x2& other);

	/// <summary>
	/// ȡ��������2x2
	/// </summary>
	/// <param name="other"></param>
	Matrix2x2(const Matrix3x3& other);

	/// <summary>
	/// ȡ��������2x2
	/// </summary>
	/// <param name="other"></param>
	Matrix2x2(const Matrix4x4& other);

	inline float*& operator[](int row) {
		float* res = (float*)(m_p + row);
		return res;
	}
	inline const float*& operator[](int row) const {
		const float* res = (float*)(m_p + row);
		return res;
	}

	Matrix2x2 operator+(const Matrix2x2& other) const;
	Matrix2x2 operator-(const Matrix2x2& other) const;
	Matrix2x2 operator*(const Matrix2x2& other) const;
	Vec2 operator*(const Vec2 vec) const;

	/// <summary>
	/// ��ȡת�þ���
	/// </summary>
	/// <returns></returns>
	Matrix2x2 Trans() const;

	static Matrix2x2 Zero() {
		return Matrix2x2();
	}
	static Matrix2x2 One() {
		Matrix2x2 res;
		res[1][1] = res[0][0] = 1;
		return res;
	}
};

/// <summary>
/// 3x3������ע�����˷���˳���Խ�����Ӱ��
/// </summary>
class Matrix3x3 final
{
private:
	float m_p[3][3];
public:
	/// <summary>
	/// ����ȫ������
	/// </summary>
	Matrix3x3();

	/// <summary>
	/// ����2x2���ָ��ƣ�[2][2]ȡ1������ȡ0
	/// </summary>
	/// <param name="other"></param>
	explicit Matrix3x3(const Matrix2x2& other);
	Matrix3x3(const Matrix3x3& other);

	/// <summary>
	/// ȡ����3x3����
	/// </summary>
	/// <param name="other"></param>
	Matrix3x3(const Matrix4x4& other);

	inline float*& operator[](int row) {
		float* res = (float*)(m_p + row);
		return res;
	}
	inline const float*& operator[](int row) const {
		const float* res = (float*)(m_p + row);
		return res;
	}

	Matrix3x3 operator+(const Matrix3x3& other) const;
	Matrix3x3 operator-(const Matrix3x3& other) const;
	Matrix3x3 operator*(const Matrix3x3& other) const;
	Vec3 operator*(const Vec3& vec) const;

	/// <summary>
	/// ��ȡת�þ���
	/// </summary>
	/// <returns></returns>
	Matrix3x3 Trans() const;

	static Matrix3x3 Zero() {
		return Matrix3x3();
	}
	static Matrix3x3 One() {
		Matrix3x3 res;
		res[2][2] = res[1][1] = res[0][0] = 1;
		return res;
	}
};

/// <summary>
/// 4x4������ע�����˷���˳���Խ�����Ӱ��
/// </summary>
class Matrix4x4 final
{
private:
	float m_p[4][4];
public:
	/// <summary>
	/// ����ȫ������
	/// </summary>
	Matrix4x4();

	/// <summary>
	/// ����2x2���ָ��ƣ�[2][2]��[3][3]ȡ1������ȡ0
	/// </summary>
	/// <param name="other"></param>
	explicit Matrix4x4(const Matrix2x2& other);

	/// <summary>
	/// ����3x3���ָ��ƣ�[3][3]ȡ1������ȡ0
	/// </summary>
	/// <param name="other"></param>
	explicit Matrix4x4(const Matrix3x3& other);
	Matrix4x4(const Matrix4x4& other);

	inline float*& operator[](int row) {
		float* res = (float*)(m_p + row);
		return res;
	}
	inline const float*& operator[](int row) const {
		const float* res = (float*)(m_p + row);
		return res;
	}

	Matrix4x4 operator+(const Matrix4x4& other) const;
	Matrix4x4 operator-(const Matrix4x4& other) const;
	Matrix4x4 operator*(const Matrix4x4& other) const;
	Vec4 operator*(const Vec4& vec) const;

	/// <summary>
	/// ��ȡת�þ���
	/// </summary>
	/// <returns></returns>
	Matrix4x4 Trans() const;

	static Matrix4x4 Zero() {
		return Matrix4x4();
	}
	static Matrix4x4 One() {
		Matrix4x4 res;
		res[3][3] = res[2][2] = res[1][1] = res[0][0] = 1;
		return res;
	}
};

/// <summary>
/// ��ʾ��ת����Ԫ��������ͳһֻ�ܵõ���λ��Ԫ��������
/// </summary>
class Quaternion final
{
private:
	float m_w, m_x, m_y, m_z;
public:
	/// <summary>
	/// Ĭ�ϵ�λ��Ԫ��
	/// </summary>
	Quaternion();
	Quaternion(float x, float y, float z, float w);
	Quaternion(const Quaternion& other);

	/// <summary>
	/// ��ŷ����(Degree)ת����Ԫ��
	/// </summary>
	/// <param name="euler"></param>
	explicit Quaternion(const Vec3& euler);

	/// <summary>
	/// ����ת����ת����Ԫ��
	/// </summary>
	/// <param name="matrix"></param>
	explicit Quaternion(const Matrix3x3& matrix);

	/// <summary>
	/// ��Ԫ��תŷ����
	/// </summary>
	/// <returns></returns>
	Vec3 ToEuler() const;

	/// <summary>
	/// ��Ԫ��ת��ת����
	/// </summary>
	/// <returns></returns>
	Matrix3x3 ToMatrix() const;

	/// <summary>
	/// ��λ�������ڱ����ۻ����
	/// ��Ԫ����Ĭ������ֵģ��1����˵����ܳ������ʱ�����ֶ����ô˺���
	/// </summary>
	void Normalize();

	/// <summary>
	/// ��ת�����Ȳ�ֵ
	/// </summary>
	/// <param name="to">��ΪĿ����ת��</param>
	/// <param name="k">��ֵϵ��</param>
	/// <param name="limit">�Ƿ�ϵ�����Ƶ�0-1</param>
	/// <returns>��ֵ���</returns>
	Quaternion Slerp(const Quaternion& to, float k, bool limit = true) const;

	/// <summary>
	/// ȡ�෴��ת��
	/// </summary>
	/// <returns></returns>
	inline Quaternion operator-() const {
		return Quaternion(m_x, m_y, m_z, -m_w);
	}

	/// <summary>
	/// ����ת���ӣ���ת����������ת������
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	inline Quaternion operator*(const Quaternion& other) const {
		return Quaternion(
			m_w * other.m_x + m_x * other.m_w + m_z * other.m_y - m_y * other.m_z,
			m_w * other.m_y + m_y * other.m_w + m_x * other.m_z - m_z * other.m_x,
			m_w * other.m_z + m_z * other.m_w + m_y * other.m_x - m_x * other.m_y,
			m_w * other.m_w - m_x * other.m_x - m_y * other.m_y - m_z * other.m_z
		);
	}

	/// <summary>
	/// ����ת��ֵ���Ӽ�����������
	/// </summary>
	/// <param name="other">������</param>
	/// <returns>��ת��ֵ</returns>
	inline Quaternion operator-(const Quaternion& other) const {
		return Quaternion(
			m_w * other.m_x - m_x * other.m_w + m_z * other.m_y - m_y * other.m_z,
			m_w * other.m_y - m_y * other.m_w + m_x * other.m_z - m_z * other.m_x,
			m_w * other.m_z - m_z * other.m_w + m_y * other.m_x - m_x * other.m_y,
			-m_w * other.m_w - m_x * other.m_x - m_y * other.m_y - m_z * other.m_z
		);
	}

	static inline Quaternion Identity() {
		return Quaternion();
	}
};