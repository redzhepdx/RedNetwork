#include "F_Vector.h"

template <typename T>
F_Vector<T>::F_Vector(const F_Vector<T> &other) {
	this->size = other.size;
	this->vec  = other.vec;
}

template F_Vector<int>::F_Vector(const F_Vector<int> &other);
template F_Vector<float>::F_Vector(const F_Vector<float> &other);
template F_Vector<uint8_t>::F_Vector(const F_Vector<uint8_t> &other);


template <typename T>
F_Vector<T>::F_Vector(unsigned int size, bool init=false) {
	this->size = size;
	if (init) {
		this->vec.resize(size, 0);
	}
}
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
F_Vector<T> F_Vector<T>::operator+(const F_Vector<T> &other) const {
	try {
		if (this->size == other.size) {
			throw NoProperVector;
		}
		F_Vector<T> _vec(this->size);
		for (unsigned int i = 0; i < this->size; i++) {
			_vec = this->vec[i] + other.vec[i];
		}
		return _vec;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return NULL;
	
}

template F_Vector<int> F_Vector<int>::operator+(const F_Vector<int> &other) const;
template F_Vector<float> F_Vector<float>::operator+(const F_Vector<float> &other) const;
template F_Vector<uint8_t> F_Vector<uint8_t>::operator+(const F_Vector<uint8_t> &other) const;

template <typename T>
F_Vector<T> F_Vector<T>::operator-(const F_Vector<T> &other) const {
	try{
		if (this->size == other.size) {
			throw NoProperVector;
		}
		F_Vector<T> _vec(this->size);
		for (unsigned int i = 0; i < this->size; i++) {
			_vec = this->vec[i] - other.vec[i];
		}
		return _vec;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return NULL;
}

template F_Vector<int> F_Vector<int>::operator-(const F_Vector<int> &other) const;
template F_Vector<float> F_Vector<float>::operator-(const F_Vector<float> &other) const;
template F_Vector<uint8_t> F_Vector<uint8_t>::operator-(const F_Vector<uint8_t> &other) const;


template <typename T>
F_Vector<T> F_Vector<T>::operator*(const F_Vector<T> &other) const {
	try {
		if (this->size == other.size) {
			throw NoProperVector;
		}
		F_Vector<T> _vec(this->size);
		for (unsigned int i = 0; i < this->size; i++) {
			_vec = this->vec[i] * other.vec[i];
		}
		return _vec;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return NULL;
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