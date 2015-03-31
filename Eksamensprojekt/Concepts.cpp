#include <iostream>
#include <type_traits>

// boilerplate code from Stroustrup, 800
struct substitution_failure{};

template<typename T>
struct substitution_succeeded : std::true_type{};

template<>
struct substitution_succeeded<substitution_failure>
	: std::false_type
{};


// less than concept
template<typename T>
struct get_less_than_result;

template<typename T>
struct has_less_than
	: substitution_succeeded < typename get_less_than_result<T>::type >
{};

template<typename T>
struct get_less_than_result
{
private:
	template<typename X>
	static auto check(X const& x) -> decltype(x < x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
constexpr bool Has_Less_Than()
{
	return has_less_than<T>::value;
}





// output operator concept
template<typename T>
struct get_output_result;

template<typename T>
struct has_output
	: substitution_succeeded < typename get_output_result<T>::type >
{};

template<typename T>
struct get_output_result
{
private:
	template<typename X>
	static auto check(X const& x) -> decltype(std::cout << x);
	static substitution_failure check(...);
public:
	using type = decltype(check(std::declval<T>()));
};

template<typename T>
constexpr bool Has_Output()
{
	return has_output<T>::value;
}