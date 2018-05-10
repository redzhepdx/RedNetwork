#include "F_Vector.h"
#include <algorithm>
#include <memory>


template <typename T>
F_Vector<T>::F_Vector(const F_Vector<T> &other) {
	this->size = other.size;
	this->vec  = other.vec;
}

template F_Vector<int>::F_Vector(const F_Vector<int> &other);
template F_Vector<float>::F_Vector(const F_Vector<float> &other);
template F_Vector<uint8_t>::F_Vector(const F_Vector<uint8_t> &other);

template <typename T>
F_Vector<T>::F_Vector(F_Vector<T> && rhs) _NOEXCEPT{
	this->size = std::move(rhs.size);
	this->vec  = std::move(rhs.vec);
	rhs.reset();
}

template F_Vector<int>::F_Vector(F_Vector<int> && rhs) _NOEXCEPT;
template F_Vector<float>::F_Vector(F_Vector<float> && rhs) _NOEXCEPT;
template F_Vector<uint8_t>::F_Vector(F_Vector<uint8_t> && rhs) _NOEXCEPT;
template F_Vector<size_t>::F_Vector(F_Vector<size_t> && rhs) _NOEXCEPT;

template <typename T>
F_Vector<T>::F_Vector(unsigned int size, bool init) {
	this->size = size;
	if (init) {
		this->vec.resize(size, 0);
	}
}
template F_Vector<int>::F_Vector(unsigned int size, bool init);
template F_Vector<float>::F_Vector(unsigned int size, bool init);
template F_Vector<uint8_t>::F_Vector(unsigned int size, bool init);

template <typename T>
T* F_Vector<T>::toArray() {
	T * arr = new T[this->size];
	for (unsigned int i = 0; i < this->size; i++) {
		arr[i] = this->vec[i];
	}
	return arr;
}

template int* F_Vector<int>::toArray();
template float* F_Vector<float>::toArray();
template uint8_t* F_Vector<uint8_t>::toArray();

template <typename T>
F_Vector<T> & F_Vector<T>::operator=(const F_Vector<T> &other){
	this->size = other.size;
	this->vec = other.vec;
	return *this;
}

template F_Vector<int> & F_Vector<int>::operator=(const F_Vector<int> &other);
template F_Vector<size_t> & F_Vector<size_t>::operator=(const F_Vector<size_t> &other);
template F_Vector<float> & F_Vector<float>::operator=(const F_Vector<float> &other);
template F_Vector<uint8_t> & F_Vector<uint8_t>::operator=(const F_Vector<uint8_t> &other);

template <typename T>
void F_Vector<T>::reset(){
	this->size = 0;
	this->vec.clear();
}

template void F_Vector<int>::reset();
template void F_Vector<float>::reset();
template void F_Vector<uint8_t>::reset();
template void F_Vector<size_t>::reset();


template <typename T>
F_Vector<T> F_Vector<T>::operator+(const F_Vector<T> &other) const {
	F_Vector<T> _vec(this->size, false);
	try {
		if (this->size == other.size) {
			throw NoProperVector;
		}
		for (unsigned int i = 0; i < this->size; i++) {
			_vec.vec[i] = this->vec[i] + other.vec[i];
		}
		return _vec;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return _vec;
	
}

template F_Vector<int> F_Vector<int>::operator+(const F_Vector<int> &other) const;
template F_Vector<float> F_Vector<float>::operator+(const F_Vector<float> &other) const;
template F_Vector<uint8_t> F_Vector<uint8_t>::operator+(const F_Vector<uint8_t> &other) const;
template F_Vector<size_t> F_Vector<size_t>::operator+(const F_Vector<size_t> &other) const;

template <typename T>
F_Vector<T> & F_Vector<T>::operator=(F_Vector<T> && rhs) _NOEXCEPT{
	if(this != &rhs){
		this->size = std::move(rhs.size);
		this->vec  = std::move(rhs.vec);
		rhs.reset();
	}
	return *this;
}

template F_Vector<int> & F_Vector<int>::operator=(F_Vector<int> && rhs) _NOEXCEPT;
template F_Vector<float> & F_Vector<float>::operator=(F_Vector<float> && rhs) _NOEXCEPT;
template F_Vector<uint8_t> & F_Vector<uint8_t>::operator=(F_Vector<uint8_t> && rhs) _NOEXCEPT;
template F_Vector<size_t> & F_Vector<size_t>::operator=(F_Vector<size_t> && rhs) _NOEXCEPT;

template <typename T>
F_Vector<T> F_Vector<T>::operator-(const F_Vector<T> &other) const {
	F_Vector<T> _vec(this->size, false);
	try{
		if (this->size == other.size) {
			throw NoProperVector;
		}
		for (unsigned int i = 0; i < this->size; i++) {
			_vec.vec[i] = this->vec[i] - other.vec[i];
		}
		return _vec;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return _vec;
}

template F_Vector<int> F_Vector<int>::operator-(const F_Vector<int> &other) const;
template F_Vector<float> F_Vector<float>::operator-(const F_Vector<float> &other) const;
template F_Vector<uint8_t> F_Vector<uint8_t>::operator-(const F_Vector<uint8_t> &other) const;

template <typename T>
F_Vector<T> F_Vector<T>::operator*(const F_Vector<T> &other) const {
	F_Vector<T> _vec(this->size, false);
	try {
		if (this->size == other.size) {
			throw NoProperVector;
		}
		for (unsigned int i = 0; i < this->size; i++) {
			_vec.vec[i] = this->vec[i] * other.vec[i];
		}
		return _vec;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return _vec;
}

template F_Vector<int> F_Vector<int>::operator*(const F_Vector<int> &other) const;
template F_Vector<float> F_Vector<float>::operator*(const F_Vector<float> &other) const;
template F_Vector<uint8_t> F_Vector<uint8_t>::operator*(const F_Vector<uint8_t> &other) const;

template <typename T>
void F_Vector<T>::operator*=(const T &value)  {
	for (unsigned int i = 0; i < this->size; i++) {
		this->vec[i] *= value;
	}
}


template void F_Vector<int>::operator*=(const int &value) ;
template void F_Vector<float>::operator*=(const float &value) ;
template void F_Vector<uint8_t>::operator*=(const uint8_t &value) ;

template <typename T>
void F_Vector<T>::operator+=(const T &value)  {
	for (unsigned int i = 0; i < this->size; i++) {
		this->vec[i] += value;
	}
}

template void F_Vector<int>::operator+=(const int &value) ;
template void F_Vector<float>::operator+=(const float &value) ;
template void F_Vector<uint8_t>::operator+=(const uint8_t &value) ;

template <typename T>
void F_Vector<T>::operator-=(const T &value)  {
	for (unsigned int i = 0; i < this->size; i++) {
		this->vec[i] -= value;
	}
}

template void F_Vector<int>::operator-=(const int &value) ;
template void F_Vector<float>::operator-=(const float &value) ;
template void F_Vector<uint8_t>::operator-=(const uint8_t &value) ;

template <typename T>
void F_Vector<T>::operator/=(const T &value)  {
	for (unsigned int i = 0; i < this->size; i++) {
		this->vec[i] /= value;
	}
}

template void F_Vector<int>::operator/=(const int &value) ;
template void F_Vector<float>::operator/=(const float &value) ;
template void F_Vector<uint8_t>::operator/=(const uint8_t &value) ;

template <typename T>
void F_Vector<T>::printVec() {
	for (int i = 0; i < this->size; i++) {
		std::cout << this->vec[i] << " ";
	}
	std::cout << std::endl;
}

template void F_Vector<int>::printVec();
template void F_Vector<float>::printVec();
template void F_Vector<uint8_t>::printVec();
