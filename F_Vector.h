#pragma once
#include <iostream>
#include <vector>

template <typename T>
class F_Vector {
public:
	F_Vector(unsigned int size) { this->size = size; };
	F_Vector(const F_Vector<T> &other);

public:
	F_Vector<T> operator+(const F_Vector<T> &other) const;
	F_Vector<T> operator-(const F_Vector<T> &other) const;
	F_Vector<T> operator*(const F_Vector<T> &other) const;
	F_Vector<T> operator*=(const T &value) const;
	F_Vector<T> operator+=(const T &value) const;
	F_Vector<T> operator-=(const T &value) const;
	F_Vector<T> operator/=(const T &value) const;

public:
	T* toArray();

public:
	T getElement(int index) { return this->vec[index]; }

private:
	int size;
	std::vector<T> vec;
};
