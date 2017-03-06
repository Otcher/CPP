#include "Fraction.h"

Fraction::Fraction(int num, int denom)
{
	this->numerator = num;
	if (denom == 0)
		throw DIVISION_BY_ZERO_EXCEPTION;
	this->denominator = denom;
}

//Base operations 

Fraction Fraction::operator* (const Fraction & other) const
{
	return (Fraction(this->numerator * other.getNumerator(), this->denominator * other.getDenominator()));
}

Fraction Fraction::operator/(const Fraction & other) const
{
	return (Fraction(this->numerator * other.getDenominator(), this->denominator * other.getNumerator()));
}

Fraction Fraction::operator+(const Fraction & other) const
{
	return (Fraction(this->numerator * other.getDenominator() + other.getNumerator() *this->denominator, this->denominator * other.getDenominator()));
}

Fraction Fraction::operator-(const Fraction & other) const
{
	return (Fraction(this->numerator * other.getDenominator() - other.getNumerator() * this->denominator, this->denominator *other.getDenominator()));
}

// x= operations (x = the operation type)

Fraction & Fraction::operator+=(const Fraction & rval) 
{
	Fraction f = (*this) + rval;
	int a = f.getNumerator();
	int b = f.getDenominator();
	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

Fraction& Fraction::operator+= (int num)  {
	*this += Fraction(num);
	return *this;
}

Fraction & Fraction::operator-=(const Fraction & rval) 
{
	Fraction f = (*this) - rval;
	int a = f.getNumerator();
	int b = f.getDenominator();
	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

Fraction & Fraction::operator-=(int num) 
{
	*this -= Fraction(num);
	return *this;
}

Fraction & Fraction::operator*=(const Fraction & rval) 
{
	Fraction f = (*this) * rval;
	int a = f.getNumerator();
	int b = f.getDenominator();
	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

Fraction & Fraction::operator*=(int num) 
{
	*this *= Fraction(num);
	return *this;
}

Fraction & Fraction::operator/=(const Fraction & rval) 
{
	Fraction f = (*this) / rval;
	int a = f.getNumerator();
	int b = f.getDenominator();
	this->setNumerator(a);
	this->setDenominator(b);

	return *this;
}

Fraction & Fraction::operator/=(int num) 
{
	if (num == 0)
		throw DIVISION_BY_ZERO_EXCEPTION;
	*this /= Fraction(num);
	return *this;
}

bool Fraction::operator==(const Fraction & rval) const
{
	return ((this->getNumerator() == rval.getNumerator()) && (this->getDenominator() == rval.getDenominator()));
}

bool operator==(const Fraction & lval, int num)
{
	return lval == Fraction(num);
}

bool operator==(int num, const Fraction & rval)
{
	return rval == num;
}

bool operator!=(const Fraction & lval, const Fraction & rval)
{
	return !(lval == rval);
}

bool operator!=(const Fraction & lval, int num)
{
	return !(lval == num);
}

bool operator!=(int num, const Fraction & rval)
{
	return !(rval == num);
}

bool operator<(const Fraction & lval, const Fraction & rval)
{
	Fraction f = lval - rval;
	return f.getNumerator() < 0;
}

bool operator<(const Fraction & lval, int num)
{
	return lval < Fraction(num);
}

bool operator<(int num, const Fraction & rval)
{
	return Fraction(num) < rval;
}

bool operator<=(const Fraction & lval, const Fraction & rval)
{
	return !(rval < lval);
}

bool operator<=(const Fraction & lval, int num)
{
	return !(num < lval);
}

bool operator<=(int num, const Fraction & rval)
{
	return !(rval < num);
}

bool operator>(const Fraction & lval, const Fraction & rval)
{
	return !(lval < rval);
}

bool operator>(const Fraction & lval, int num)
{
	return lval > Fraction(num);
}

bool operator>(int num, const Fraction & rval)
{
	return !(rval > num);
}

bool operator>=(const Fraction & lval, const Fraction & rval)
{
	return !(rval > lval);
}

bool operator>=(const Fraction & lval, int num)
{
	return lval >= Fraction(num);
}

bool operator>=(int num, const Fraction & rval)
{
	return !(rval >= num);
}

Fraction operator+(Fraction lval, int num)
{
	lval += num;
	return lval;
}

Fraction operator+(int num, const Fraction & rval)
{
	return rval+num;
}

Fraction operator-(Fraction lval, int num)
{
	lval -= num;
	return lval;
}

Fraction operator-(int num, const Fraction & rval)
{
	Fraction tempFrac = Fraction(num);
	tempFrac -= rval;
	return tempFrac;
}

Fraction operator*(Fraction lval, int num)
{
	lval *= Fraction(num);
	return lval;
}

Fraction operator*(int num, const Fraction & rval)
{
	return rval * num;
}

Fraction operator/(Fraction lval, int num)
{
	lval /= Fraction(num);
	return lval;
}

Fraction operator/(int num, const Fraction & rval)
{
	Fraction tempFrac = Fraction(num);
	tempFrac /= rval;
	return tempFrac;
}

Fraction::~Fraction()
{
}