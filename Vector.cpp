#include <iostream>
#include "Vector.h"
double vector::accuracy = 0.01;

vector::vector() {  // CONSTRUCTION
	grow_size = 10;
	size = 0;
	capacity = 10;
	v = NULL;
}

vector::vector(const size_t size) {  // CONSTRUCTION PARAM
	grow_size = 10;
	capacity = grow_size;
	while (size > capacity) {
		capacity += grow_size;
	}
	this->size = size;
	v = new double[capacity];
	for (size_t i = 0; i < size; ++i) {
		v[i] = 0;
	}
}
vector::vector(const vector& vec) {   // ConstructorCopy
	grow_size = 10;
	capacity = vec.capacity;
	size = vec.size;
	v = new double[vec.capacity];
	if (size < capacity)
	{
		for (size_t i = 0; i < vec.capacity; ++i) {
			v[i] = vec.v[i];
		}
	}
}
size_t vector::GetSize() const {  //GetSize
	return size;
}

double& vector::operator[] (const size_t index) {
	if (index > size) throw ("Index is out of range");
	return v[index];
}

double vector::operator[] (const size_t index) const {       // SquareBrackets
	if (index > size) throw("Index is out of ragne");
	return v[index];
}

vector vector::operator+= (const vector& vec) {                        // OperatorPlusEqual
	if (size != vec.size) throw("Difference between sizes");
	for (size_t i = 0; i < size; ++i) {
		v[i] += vec.v[i];
	}
	return *this;
}

vector vector::operator+ (const vector& vec) {     //OperatorPlus
	if (size != vec.size) throw("Difference between sizes");
	vector Newbie(*this);
	Newbie += vec;
	return Newbie;
}

vector& vector::operator= (const vector& vec) { //OperatorEqual
	if (this == &vec) return *this;
	if (size != vec.size)
	{
		delete[] v;
		size = vec.size;
		capacity = vec.capacity;
		v = new double[size];
		for (size_t i = 0; i < size; ++i)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			v[i] = vec.v[i];
		}
		return *this;
	}
}

vector vector::operator- (const vector& vec) {   // OperatorMinus
	vector Newbie = *this;
	Newbie -= vec;
	return Newbie;
}

vector vector::operator-= (const vector& vec) {    //OperatorMinusEqual
	if (size != vec.size) throw("Difference between sizes");
	for (size_t i = 0; i < size; ++i) {
		v[i] = v[i] - vec.v[i];
	}
	return *this;
}


double vector::operator* (const vector& vec) {   // OperatorScalarMullti
	if (size != vec.size) throw("Difference between sizes");
	double result = 0;
	for (size_t i = 0; i < size; ++i) {
		result += vec.v[i] * v[i];
	}
	return result;
}

vector vector::operator*= (const vector& vec) {  //OperatorMulltipliedEqualVector
	for (size_t i = 0; i < size; ++i) {
		v[i] = v[i] * vec.v[i];
	}
	return *this;
}

vector vector::operator*= (const double x) {   //OperatorMulltipliedEqualNumber
	for (size_t i = 0; i < size; ++i) {
		v[i] = v[i] * x;
	}
	return *this;
}

vector vector::operator* (const double x) {  // OperatorMultipliedbyNumberReturnNew
	vector Newbie = *this;
	Newbie *= x;
	return Newbie;
}

vector vector::operator/= (const double x) {   // OperatorDivideEqual
	if (x == 0) throw("Cant divide by zero");
	for (size_t i = 0; i < size; ++i) {
		v[i] /= x;
	}
	return *this;
}

vector vector::operator/ (const double x) {    // OperatorDivide
	if (x == 0) throw("Cant divide by zero");
	vector Newbie = *this;
	Newbie /= x;
	return Newbie;
}

bool vector::operator== (const vector& vec) {    //OperatorIsEqual
	if (size != vec.size) return false;
	for (size_t i = 0; i < size; ++i) {
		if (abs(v[i] != vec.v[i]) >= accuracy) return false;
	}
	return true;
}

bool vector::operator!= (const vector& vec) {     // OperatorNotEqual
//	if (size != vec.size) return true;
//	for (size_t i = 0; i < size; ++i) {
//		if (v[i] != vec.v[i]) return true;
//	}
//	return false;
	return (!(*this == vec));
}

void vector::Erase(const size_t index) {  //MethodErase
	if (index > size) throw ("Index is out of range");
	for (size_t i = index; i < size - 1; ++i) {
		v[i] = v[i + 1];
	}
	size--;
}

void vector::PushBack(const double data) { //MethodPushBack
	if (capacity <= size + 1) {
		capacity += grow_size;
		double* temp = new double[capacity];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = 0;
		}
		if (size < capacity)
		{
			for (size_t i = 0; i < size; ++i) {
				temp[i] = v[i];
			}
		}
		delete[] v;
		v = new double[capacity];
		if (size < capacity)
		{
			for (size_t i = 0; i < size; ++i)
			{
				v[i] = temp[i];
			}
			v[size] = data;
		}
		size++;
		delete[] temp;
	}
	else {
		v[size] = data;
		size++;
	}
}
vector::~vector() {
	delete[] v;
}
std::ostream& operator<<(std::ostream& stream, const vector& v) {
	stream << "Size : " << v.GetSize() << std::endl;
	for (size_t i = 0; i < v.GetSize(); ++i) {
		stream << i + 1 << " : " << v[i] << std::endl;
	}
	return stream;
}
vector operator* (const double x, vector& vec) {  //
	vector result(vec);
	for (size_t i = 0; i < vec.GetSize(); ++i) {
		result[i] = x * vec[i];
	}
	return result;
}
vector operator*= (const double x, vector& vec)
{
	vec = vec * x;
	return vec;
}


//class ComplexNumber {
//	double _re;
//	double _im;
//public:
//	...
//	ComplexNumber operator+ (const ComplexNumber& rhs)
//	{
//		_re += rhs._re;
//		_im += rhs._im;
//		return *this;
//	}
//};

//class Point //объ€вление класса 
//{
//private:
//	double x, y; // пол€ класса
//public:
//	Point() :x(3), y(3) {}
//	void Print() { std::cout << "Its your point(x,y) - " << x << " " << y << std::endl; }//метод класса
//};
//int main()
//{
//	Point my;//ќбъект класса
//}
