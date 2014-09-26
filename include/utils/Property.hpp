#pragma once

#include <iostream>
#include <set>
#include <functional>

template <class T>
class Property
{
	std::set<std::function<void(const T&)>> m_callbacks;
	T m_val;
public:
	Property()             : m_val(T()) {}
	Property(const T& rhs) : m_val(rhs) {}
	Property(T&& rhs)      : m_val(rhs) {}
	Property(Property&&) = default;
/*
	Property<T> &operator= (const T& rhs)
	{ 
		m_val = rhs; 
//		for(auto f : m_callbacks) f();
		return *this;
	}

	T getValue()   const { return m_val; }
	T operator()() const { return m_val; }
*/
	T &getValue()   { return m_val; }
/*	T &operator()() { return m_val; }
*/
	Property &operator=(const T& rhs) { return m_val = rhs; }
	Property &operator=(T&& rhs) { return m_val = rhs; }
/*
	Property &operator=(const Property& rhs)
	{
		m_val = rhs.getValue();
		return *this; 
	}

	operator T&() { return m_val; }
*/
};
