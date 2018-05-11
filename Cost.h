template <typename T>
class Cost{
public:
	virtual T func(T activation_value, T actual_value) = 0;
	virtual T delta(T forward, T activation_value, T actual_value) = 0;
}
