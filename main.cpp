#include "Vector.h"
#include <iostream>
#include <string>
#include <cstring>
#include <climits>

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

