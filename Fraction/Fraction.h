#ifndef _H_FRACTION
#define _H_FRACTION

#include <iostream>

class Fraction
{
public:
	Fraction(int num = 0, int denom = 1);
	void setNumerator(const int num) { this->numerator = num; }
	void setDenominator(const int denom) { this->denominator = denom; }
	int getNumerator() const { return this->numerator; };
	int getDenominator() const { return this->denominator; };

	//Operator Handling
	Fraction operator* (const Fraction &other) const;
	Fraction operator/ (const Fraction &other) const;
	Fraction operator+ (const Fraction &other) const;
	Fraction operator- (const Fraction &other) const;

	Fraction& operator+= (const Fraction& rval); 
	Fraction& operator+= (int num); 

	Fraction& operator-= (const Fraction& rval);
	Fraction& operator-= (int num);

	Fraction& operator*= (const Fraction& rval);
	Fraction& operator*= (int num);

	Fraction& operator/= (const Fraction& rval);
	Fraction& operator/= (int num);

	bool operator== (const Fraction& rval) const;


	~Fraction();

private:
	//Exception consts
	const int DIVISION_BY_ZERO_EXCEPTION = 0;

	//Fraction members
	int numerator;
	int denominator;
};

bool operator== (const Fraction& lval, int num); //lval==num
bool operator== (int num, const Fraction& rval); //num==rval

bool operator!= (const Fraction& lval, const Fraction& rval); //lval!=rval
bool operator!= (const Fraction& lval, int num); //lval==num
bool operator!= (int num, const Fraction& rval); //num==rval

bool operator< (const Fraction& lval, const Fraction& rval);
bool operator< (const Fraction& lval, int num); //lval<num
bool operator< (int num, const Fraction& rval); //num<rval

bool operator<= (const Fraction& lval, const Fraction& rval); //lval<=rval
bool operator<= (const Fraction& lval, int num); //lval<=num
bool operator<= (int num, const Fraction& rval); //num<=rval

bool operator> (const Fraction& lval, const Fraction& rval); //lval>rval
bool operator> (const Fraction& lval, int num); //lval>num
bool operator> (int num, const Fraction& rval); //num>rval

bool operator>= (const Fraction& lval, const Fraction& rval); //lval>=rval
bool operator>= (const Fraction& lval, int num); //lval>=num
bool operator>= (int num, const Fraction& rval); //num>=rval

Fraction operator+ (Fraction lval, int num); //lval+num
Fraction operator+ (int num, const Fraction& rval); //num+rval

Fraction operator- (Fraction lval, int num); //lval-num
Fraction operator- (int num, const Fraction& rval); //num-rval

Fraction operator* (Fraction lval, int num); //lval*num
Fraction operator* (int num, const Fraction& rval); //num*rval

Fraction operator/ (Fraction lval, int num); // lval/num
Fraction operator/ (int num, const Fraction& rval); // num/rval


#endif
