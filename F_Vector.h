#pragma once
#include <iostream>
#include <vector>
#include "Setup.h"

template <typename T>
class F_Vector {
public:

#pragma pack(push, 1)
	struct NoProperVectorSize : public std::exception {
		const char* what() const throw() {
			return "Vector Sizes Aren't Equal For This Operation, Check Sizes Again!\n";
		}
	}NoProperVector;
#pragma pack(pop)

	F_Vector() {};
	F_Vector(unsigned int size, bool init);
	F_Vector(const F_Vector<T> &other);
	F_Vector(F_Vector<T> && rhs) _NOEXCEPT;

public:
	F_Vector<T> operator+(const F_Vector<T> &other) const;
	F_Vector<T> operator-(const F_Vector<T> &other) const;
	F_Vector<T> operator*(const F_Vector<T> &other) const;
	F_Vector<T> & operator=(const F_Vector<T> &other);
	F_Vector<T> & operator=(F_Vector<T> && other) _NOEXCEPT;
	void operator*=(const T &value);
	void operator+=(const T &value);
	void operator-=(const T &value);
	void operator/=(const T &value);

public:
	T* toArray();
	void reset();
public:
	T getElement(int index) { return this->vec[index]; }
	void printVec();
public:
	int size;
	std::vector<T> vec;
};
