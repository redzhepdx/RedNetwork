#pragma once
#include <iostream>
#include <cmath>

template <typename T>
class Activation{

public:
	virtual T act(T);
	virtual T prime(T);

public:
	T one_x = static_cast<T>(this->one);
	T zero_x = static_cast<T>(this->zero);

private:
	int one = 1;
	int zero = 0;
};

template <typename T>
class Linear : public Activation<T>{
public:
	Linear();
	T act(T value);
	T prime(T value);
};

template <typename T>
Linear<T>::Linear() {

}

template Linear<int>::Linear();
template Linear<float>::Linear();
template Linear<uint8_t>::Linear();

template <typename T>
T Linear<T>::act(T value) {
	return value;
}

template int Linear<int>::act(int value);
template float Linear<float>::act(float value);
template uint8_t Linear<uint8_t>::act(uint8_t value);

template <typename T>
T Linear<T>::prime(T value) {
	return this->one_x;
}

template int Linear<int>::prime(int value);
template float Linear<float>::prime(float value);
template uint8_t Linear<uint8_t>::prime(uint8_t value);

template <typename T>
class Sigmoid : public Activation<T>{
public:
	Sigmoid();
	T act(T value);
	T prime(T value);
};

template <typename T>
Sigmoid<T>::Sigmoid(){

}

template <typename T>
T Sigmoid<T>::act(T value){
	T sig_val = this->one_x / (this->one_x + std::exp(-value));
	return sig_val;
}

template <typename T>
T Sigmoid<T>::prime(T value){
	return this->act(value) * (this->one_x - this->act(value));
}

template <typename T>
class Tanh : public Activation<T>{
public:
	Tanh();
	T act(T value);
	T prime(T value);
};

template <typename T>
Tanh<T>::Tanh(){

}

template <typename T>
T Tanh<T>::act(T value){
	T tan_val = (this->one_x * 2) / (this->one_x + std::exp(-(2 * value))) - 1;
}

template <typename T>
T Tanh<T>::prime(T value){
	return this->one_x - (this->act(value) * this->act(value));
}

template <typename T>
class Relu : public Activation<T>{
public:
	Relu();
	T act(T value);
	T prime(T value);
};

template <typename T>
Relu<T>::Relu(){

}

template <typename T>
T Relu<T>::act(T value){
	return std::max(value, this->zero_x);
}

template <typename T>
T Relu<T>::prime(T value){
	if (value < this->zero_x) {
		return this->zero_x;
	}
	return this->one_x;
}
