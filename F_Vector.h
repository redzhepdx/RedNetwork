#pragma once
#include <iostream>
#include <vector>

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

public:
	F_Vector<T> operator+(const F_Vector<T> &other) const;
	F_Vector<T> operator-(const F_Vector<T> &other) const;
	F_Vector<T> operator*(const F_Vector<T> &other) const;
	F_Vector<T> & operator=(const F_Vector<T> &other);
	void operator*=(const T &value);
	void operator+=(const T &value);
	void operator-=(const T &value);
	void operator/=(const T &value);

public:
	T* toArray();

public:
	T getElement(int index) { return this->vec[index]; }
	void printVec();
public:
	int size;
	std::vector<T> vec;
};
