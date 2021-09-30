// CMAKE_TYPE.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
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
		for (size_t i = 0; i < capacity; i++)
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

bool StrToLong(const std::string str, long int* value)
{
	char* endptr = NULL;
	*value = strtol(str.c_str(), &endptr, 0);
	if (endptr == str)return false;
	if ((*value == LONG_MIN || *value == LONG_MAX) && errno == ERANGE) return false;
	if (*endptr != str[strlen(str.c_str())]) return false;
	return true;
}
bool StrToLong(const std::string str, double* value)
{
	char* endptr = NULL;
	*value = strtod(str.c_str(), &endptr);
	if (endptr == str) return false;
	if (errno == ERANGE) return false;
	if (*endptr != str[strlen(str.c_str())]) return false;
	return true;
}
long int Number_needed(const long int left_border, const long int right_border, const std::string condition)
{
	std::cout << "\n" << condition;
	long int dif = 0;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (StrToLong(str, &dif) == 1) break;
		else
		{
			std::cout << "Wrong input, try again\n";
		}
	}
	while (true)
	{
		if (dif >= left_border && dif <= right_border) return dif;
		else
		{
			std::cout << "\nWrong input, try again: " << condition;
			while (true)
			{
				std::cin >> str;
				if (StrToLong(str, &dif) == 1) break;
				else
				{
					std::cout << "Wrong input, try again\n";
				}
			}
		}
	}
}
double Number_needed(const std::string condition)
{
	std::cout << "\n" << condition;
	double dif = 0;
	std::string str;
	while (true)
	{
		std::cin >> str;
		if (StrToLong(str, &dif) == 1) break;
		else
		{
			std::cout << "Wrong input, try again\n";
		}
	}
	return dif;
}
void PrintChoices()
{
	std::cout << "  Press 1 - work with first vector\n  Press 2 - work with second vector\n  Press 3 - Vector addition\n";
	std::cout << "  Press 4 - Vector difference\n  Press 5 - Scalar product of these vectors\n  Press 6 - vectors are equal?\n  Press 0 - for exit programm";
}
void PrintChoicesAdditional()
{
	std::cout << "  Press 1 - edit element\n  Press 2 - multiply by number\n  Press 3 - divide by number\n";
	std::cout << "  Press 4 - pushabck new element\n  Press 5 - erase element\n";
	std::cout << "  Press 0 - for back in menu";
}

int main()
{
	vector a(3);
	vector b(3);
	bool work = true;
	while (work)
	{
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		PrintChoices();
		long int key = Number_needed(0, 6, "Enter a number in range 0-6: ");
		switch (key)
		{
		case 0: // exit
		{
			work = false;
			break;
		}
		case 1: // work with first
		{
			bool work2 = true;
			while (work2)
			{
				system("cls");
				std::cout << "You are working with first vector" << std::endl;
				std::cout << a << std::endl;
				PrintChoicesAdditional();
				long int key2 = Number_needed(0, 5, "Enter a number in range 0-5: ");
				switch (key2)
				{
				case 0: // exit
				{
					work2 = false;
					break;
				}
				case 1: // edit element
				{
					try {
						long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
						double value = Number_needed("\nInput your number: ");
						a[index - 1] = value;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2: // multiply by number
				{
					double value = Number_needed("\nInput your number: ");
					a *= value;
					break;
				}
				case 3: // divide by number
				{
					double value = Number_needed("\nInput your number: ");
					try { a /= value; }
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 4: //pushback
				{
					double value = Number_needed("\nInput your number: ");
					a.PushBack(value);
					break;
				}
				case 5: //erase
				{
					if (a.GetSize() != 0)
					{
						try {
							long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
							a.Erase(index - 1);
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							system("pause");
						}
					}
					else
					{
						std::cout << "\nNo more elements\n";
						system("pause");
					}
					break;
				}
				}
			}
			system("cls");
			break;
		}
		case 2: // work with second
		{
			bool work2 = true;
			while (work2)
			{
				system("cls");
				std::cout << "You are working with second vector" << std::endl;
				std::cout << b << std::endl;
				PrintChoicesAdditional();
				long int key2 = Number_needed(0, 5, "Enter a number in range 0-5: ");
				switch (key2)
				{
				case 0: // exit
				{
					work2 = false;
					break;
				}
				case 1: // edit element
				{
					try {
						long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
						double value = Number_needed("\nInput your number: ");
						b[index - 1] = value;
					}
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 2: // multiply by number
				{
					double value = Number_needed("\nInput your number: ");
					b *= value;
					break;
				}
				case 3: // divide by number
				{
					double value = Number_needed("\nInput your number:");
					try { b /= value; }
					catch (const char* err)
					{
						std::cout << err << std::endl;
						system("pause");
					}
					break;
				}
				case 4: //pushback
				{
					double value = Number_needed("\nInput your number: ");
					b.PushBack(value);
					break;
				}
				case 5: //erase
				{
					if (b.GetSize() != 0) {
						try {
							long int index = Number_needed(LONG_MIN, LONG_MAX, "\nInput index: ");
							b.Erase(index - 1);
						}
						catch (const char* err)
						{
							std::cout << err << std::endl;
							system("pause");
						}
					}
					else
					{
						std::cout << "\nNo more elements\n";
						system("pause");
					}
					break;
				}
				}
			}
			system("cls");
			break;
		}
		case 3: // Vector addition
		{
			system("cls");
			try
			{
				vector c = a + b;
				std::cout << "vector " << a << "\n+" << "vector" << b << "\n = " << c;
			}
			catch (const char* err)
			{
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 4: // Vector difference
		{
			system("cls");
			try {
				vector c = a - b;
				std::cout << "vector " << a << "\n-" << "vector" << b << "\n = " << c;
			}
			catch (const char* err)
			{
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 5: // Scalar
		{
			system("cls");
			try {
				std::cout << "vector " << a << "\n*" << "vector" << b << "\n = " << a * b << "\n";
			}
			catch (const char* err) {
				std::cout << err << std::endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 6: // Equals
		{
			system("cls");
			std::string answer = a == b ? "Yes" : "No";
			std::cout << a;
			std::cout << b;
			std::cout << "vector a  = vector b? - " << answer << "\n";
			system("pause");
			system("cls");
			break;
		}
		}
	}
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

//class Point //объявление класса 
//{
//private:
//	double x, y; // поля класса
//public:
//	Point() :x(3), y(3) {}
//	void Print() { std::cout << "Its your point(x,y) - " << x << " " << y << std::endl; }//метод класса
//};
//int main()
//{
//	Point my;//Объект класса
//}

