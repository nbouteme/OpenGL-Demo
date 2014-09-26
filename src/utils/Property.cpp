#include <utils/Property.hpp>

T  Property::getValue()   const 
{
	return m_val;
}

T  Property::operator()() const
{
	return m_val;
}

T &Property::getValue()
{
	return m_val;
}

T &Property::operator()()
{
	return m_val;
}

T &Property::operator=(T& rhs)
{
	return m_val = rhs;
}

Property &Property::operator=(const Property& rhs)
{
	m_val = rhs.getValue();
	return *this; 
}

Property::operator T&()
{
	return m_val;
}

