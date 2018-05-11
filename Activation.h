template <typename T>
class Activation{
public:
	virtual T act() = 0;
	virtual T prime() = 0;
};

template <typename T>
class Sigmoid : public Activation{
public:
	Sigmoid();
	T act(T value);
	T prime(T value);
}

template <typename T>
Sigmoid<T>::Sigmoid(){

}

template <typename T>
T Sigmoid<T>::act(T value){

}

template <typename T>
T Sigmoid<T>::prime(T value){

}

template <typename T>
class Tanh : public Activation{
public:
	Tanh();
	T act(T value);
	T prime(T value);
}

template <typename T>
Tanh<T>::Tanh(){

}

template <typename T>
T Tanh<T>::act(T value){

}

template <typename T>
T Tanh<T>::prime(T value){

}

template <typename T>
class Relu : public Activation{
public:
	Relu();
	T act();
	T prime();
}

template <typename T>
Relu<T>::Relu(){

}

template <typename T>
T Relu<T>::act(T value){

}

template <typename T>
T Relu<T>::prime(T value){

}
