#pragma once
#include <iostream>
#include <cmath>
#include "Activation.h"
#include "F_Vector.h"
#include "M_Matrix.h"
#include "utils.h"

template <typename T>
class Cost{
public:
	virtual T func(F_Vector<T> activation_value, F_Vector<T> actual_value);
	virtual F_Vector<T> delta(F_Vector<T> forward, F_Vector<T> activation_value, F_Vector<T> actual_value, const Activation<T> act_func);
};

template <typename T>
class QuadraticCost : public Cost<T> {
	QuadraticCost();
	T func(F_Vector<T> activation_value, F_Vector<T> actual_value);
	F_Vector<T> delta(F_Vector<T> forward, F_Vector<T> activation_value, F_Vector<T> actual_value, const Activation<T> act_func);
};

template<typename T>
QuadraticCost<T>::QuadraticCost() {

};

template<typename T>
T QuadraticCost<T>::func(F_Vector<T> activation_value, F_Vector<T> actual_value) {
	F_Vector<T> diff = activation_value - actual_value;
	T norm = frobenius_norm(diff.vec);
	return 0.5 * norm * norm;
}

template<typename T>
F_Vector<T> QuadraticCost<T>::delta(F_Vector<T> forward, F_Vector<T> activation_value, F_Vector<T> actual_value, const Activation<T> act_func) {
	F_Vector<T> prime_non_active(forward);
	for (int i = 0; i < forward.size(); i++) {
		prime_non_active.vec[i] = act_func.prime(forward.vec[i]);
	}
	return (activation_value - actual_value) * prime_non_active;
}


template <typename T>
class CrossEntropyCost : public Cost<T> {
	CrossEntropyCost();
	T func(F_Vector<T> activation_value, F_Vector<T> actual_value);
	F_Vector<T> delta(F_Vector<T> forward, F_Vector<T> activation_value, F_Vector<T> actual_value, const Activation<T> act_func);
};

template<typename T>
CrossEntropyCost<T>::CrossEntropyCost() {
	
}

template<typename T>
T CrossEntropyCost<T>::func(F_Vector<T> activation_value, F_Vector<T> actual_value) {
	F_Vector<T> logged(activation_value);
	F_Vector<T> ones(activation_value.size, true);
	ones = ones + 1;
	F_Vector<T> f_logged = -actual_value * log_sp(activation_value);
	F_Vector<T> s_logged = (ones - actual_value) * log_sp(ones - activation_value);
	return f_logged - s_logged;
}

template<typename T>
F_Vector<T> CrossEntropyCost<T>::delta(F_Vector<T> forward, F_Vector<T> activation_value, F_Vector<T> actual_value, const Activation<T> act_func) {
	return activation_value - actual_value;
}