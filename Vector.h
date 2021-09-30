#pragma once
#pragma once
#include <iostream>
#include <string>
class vector {
private:
	size_t capacity;
	size_t size;
	size_t grow_size;
	static double accuracy;
	double* v;
public:
	vector(); //constrictopn
	vector(const size_t size);// CONSTRUCTION PARAM
	vector(const vector& vec); // ConstructorCopy
	size_t GetSize() const; //GetSize
	double& operator[] (const size_t index); //OperatorSqBrackets
	double operator[] (const size_t index) const; // SquareBrackets
	vector operator+= (const vector& vec); // OperatorPlusEqual
	vector operator+ (const vector& vec); //OperatorPlus
	vector& operator= (const vector& vec); //OperatorEqual
	vector operator- (const vector& vec); // OperatorMinus
	vector operator-= (const vector& vec); //OperatorMinusEqual
	double operator* (const vector& vec); // OperatorScalarMullti
	vector operator*= (const vector& vec); //OperatorMulltipliedEqualVector
	vector operator*= (const double x); //OperatorMulltipliedEqualNumber
	vector operator* (const double x); // OperatorMultipliedbyNumberReturnNew
	vector operator/= (const double x); // OperatorDivideEqual
	vector operator/ (const double x); // OperatorDivide
	bool operator== (const vector& vec); //OperatorIsEqual
	bool operator!= (const vector& vec); // OperatorNotEqual
	void Erase(const size_t index); //MethodErase
	void PushBack(const double data);  //MethodPushBack
	~vector();
};
std::ostream& operator<<(std::ostream& stream, const vector& v);
vector operator* (const double x, vector& vec);
vector operator*= (const double x, vector& vec);

