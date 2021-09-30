#include "pch.h"
#include <stdio.h>
#include "G:\LabsCourse2\Lab1\vector_c2l1/Vector.h"
#include "G:\LabsCourse2\Lab1\vector_c2l1/Vector.cpp"
#define DEBUG_LINES

TEST(Vector, Constructor) {
	vector a;
	EXPECT_EQ(0, a.GetSize());
}

TEST(Vector, ConstructorParam) {
	vector a(10);
	EXPECT_EQ(10, a.GetSize());
}

TEST(Vector, ConstructorCopy) {
	vector a(2);
	a[0] = 1;
	a[1] = 2;
	vector b = a;
	EXPECT_EQ(a[0], b[0]);
	EXPECT_EQ(a[1], b[1]);
}

TEST(Vector, GetSize) {
	vector a;
	EXPECT_EQ(0, a.GetSize());
}

TEST(Vector, SquareBrackets) {
	vector a(10);
	EXPECT_THROW(a[1000], const char*);
}

TEST(Vector, OperatorPlusEqual) {
	vector a(3);
	vector b(3);
	b[0] += a[0];
	b[1] += 2;
	b[2] += a[2];
	EXPECT_EQ(0, b[0]);
	EXPECT_EQ(2, b[1]);
	EXPECT_EQ(0, b[2]);
}

TEST(Vector, OperaportEqual) {
	vector a(3);
	vector b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	a = b;
	EXPECT_EQ(1, a[0]);
	EXPECT_EQ(2, a[1]);
	EXPECT_EQ(3, a[2]);
}

TEST(Vector, OperatorPlus) {
	vector a(3);
	vector b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	vector c = a + b;
	EXPECT_EQ(1, c[0]);
	EXPECT_EQ(3, c[1]);
	EXPECT_EQ(3, c[2]);
}

TEST(Vector, OperatorMinusEqual) {
	vector a(3);
	vector b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	a -= b;
	EXPECT_EQ(-1, a[0]);
	EXPECT_EQ(-1, a[1]);
	EXPECT_EQ(-3, a[2]);
}

TEST(Vector, OperatorMinus) {
	vector a(3);
	vector b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	vector c = a - b;
	EXPECT_EQ(-1, c[0]);
	EXPECT_EQ(-1, c[1]);
	EXPECT_EQ(-3, c[2]);
}

TEST(Vector, OperatorScalarMullti) {
	vector a(3);
	vector b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	double x = a * b;
	EXPECT_EQ(2, x);
}

TEST(Vector, OperatorMulltipliedEqualVector) {
	vector a(3);
	vector b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	a *= b;
	EXPECT_EQ(0, a[0]);
	EXPECT_EQ(2, a[1]);
	EXPECT_EQ(0, a[2]);
}

TEST(Vector, OperatorMulltipliedEqualNumber) {
	vector a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	a *= 3;
	EXPECT_EQ(0, a[0]);
	EXPECT_EQ(3, a[1]);
	EXPECT_EQ(0, a[2]);
}

TEST(Vector, OperatorMultipliedbyNumberReturnNew) {
	vector a(3);
	vector b(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	b = a * 3;
	EXPECT_EQ(0, b[0]);
	EXPECT_EQ(3, b[1]);
	EXPECT_EQ(0, b[2]);
	b = b * 0;
	EXPECT_EQ(0, b[1]);
}

TEST(Vector, OperatorDivideEqual) {
	vector a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	a /= 2;
	EXPECT_EQ(0, a[0]);
	EXPECT_EQ(0.5, a[1]);
	EXPECT_EQ(0, a[2]);
	EXPECT_THROW(a / 0, const char*);
}

TEST(Vector, OperatorDivide) {
	vector a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	a = a / 2;
	EXPECT_EQ(0, a[0]);
	EXPECT_EQ(0.5, a[1]);
	EXPECT_EQ(0, a[2]);
	EXPECT_THROW(a / 0, const char*);
}

TEST(Vector, OperatorIsEqual) {
	vector a(3);
	vector b(3);
	vector c(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	b = a * 3;
	c = b / 3;
	EXPECT_EQ(false, a == b);
	EXPECT_EQ(true, c == a);
}

TEST(Vector, OperatorNotEqual) {
	vector a(3);
	vector b(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	b = a * 3;
	EXPECT_EQ(true, a != b);
}

TEST(Vector, MethodErase) {
	vector a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	a.Erase(1);
	EXPECT_EQ(0, a[0]);
	EXPECT_EQ(0, a[1]);
	a.Erase(0);
	EXPECT_EQ(1, a.GetSize());
}

TEST(Vector, MethodPushBack) {
	vector a(3);
	a[0] = 0;
	a[1] = 1;
	a[2] = 0;
	a.PushBack(1);
	EXPECT_EQ(1, a[3]);
	EXPECT_EQ(4, a.GetSize());
}


