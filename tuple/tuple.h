#include <stdlib.h>
#include <iostream>

template <typename ...Values>
class tuple;

template<>
class tuple<>{};

template<typename Head, typename... Tail>
class tuple<Head, Tail...> :private tuple<Tail...>{
	using inherited = tuple<Tail...>;
public:
	tuple(){}
	tuple(Head h, Tail... t) : m_Data(h), inherited(t...) {}
	Head head() { return m_Data; }
	inherited& tail() { return *this; }
protected:
	Head m_Data;
};

template<typename Head, typename... Tail>
std::ostream& operator<<(std::ostream& os, tuple<Head, Tail...>& tpe){
	os << tpe.head() << ",";
	operator<<(os, tpe.tail());
	return os;
}
template<typename T>
std::ostream& operator<<(std::ostream& os, tuple<T>& tpe){
	os << tpe.head();
	return os;
}