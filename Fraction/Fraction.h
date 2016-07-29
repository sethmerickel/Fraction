#pragma once

#include <iostream>

// Helper functions

// Greatest Common Divisor
inline int gcd(int a, int b)
{
   a = std::abs(a);
   b = std::abs(b);
   int r = 0;
   while (a != 0) {
      r = a;
      a = b%a;
      b = r;
   }
   return b;
}

//--------------------------------------------------------------------------

inline int sign(int a)
{
   return a < 0 ? -1 : 1; // zero is +1
}

//--------------------------------------------------------------------------
// Reduce a fraction.  Sign goes in numerator
inline void reduce(int& num, int& den)
{
   int g = gcd(num, den);
   num = sign(num) * sign(den) * std::abs(num) / g;
   den = std::abs(den) / g;
}

// Fraction class
// Invariants: 
//     1) Should always be reduced
//     2) Denominator should never be zero
//     3) Numerator should always carry the sign

class Fraction
{
public:

   //--------------------------------------------------------------------------

   Fraction()
      :m_num(0), m_den(1)
   {}
   
   //--------------------------------------------------------------------------

   Fraction(int num, int den = 1)
      :m_num(num), m_den(den)
   {      
      reduce(m_num, m_den);
   }

   //--------------------------------------------------------------------------

   Fraction& operator=(const Fraction& f) = default;

   //--------------------------------------------------------------------------

   int getNumerator() const 
   {
      return m_num; 
   }

   //--------------------------------------------------------------------------

   int getDenominator() const 
   {
      return m_den; 
   }

private:

   // Members
   int m_num; // Numerator
   int m_den; // Denominator

   // Friends

   // Compare
   friend bool operator==(const Fraction& f1, const Fraction& f2);
   friend bool operator!=(const Fraction& f1, const Fraction& f2);
   friend bool operator<(const Fraction& f1, const Fraction& f2);
   friend bool operator>(const Fraction& f1, const Fraction& f2);

   // Math
   friend Fraction operator+(const Fraction& f1, const Fraction& f2);
   friend Fraction operator-(const Fraction& f1, const Fraction& f2);
   friend Fraction operator*(const Fraction& f1, const Fraction& f2);
   friend Fraction operator/(const Fraction& f1, const Fraction& f2);

   // Display
   friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

//--------------------------------------------------------------------------

inline bool operator==(const Fraction& f1, const Fraction& f2)
{
   return (f1.m_num == f2.m_num) && (f1.m_den == f2.m_den);
}

//--------------------------------------------------------------------------

inline bool operator!=(const Fraction & f1, const Fraction & f2)
{
   return !(f1 == f2);
}

//--------------------------------------------------------------------------

inline bool operator<(const Fraction& f1, const Fraction& f2)
{
   Fraction diff = f1 - f2;
   return diff.m_num < 0;
}

//--------------------------------------------------------------------------

inline bool operator>(const Fraction& f1, const Fraction& f2)
{
   Fraction diff = f1 - f2;
   return diff.m_num > 0;
}

//--------------------------------------------------------------------------

inline Fraction operator+(const Fraction& f1, const Fraction& f2)
{
   int num = f1.m_num*f2.m_den + f2.m_num*f1.m_den;
   int den = f1.m_den * f2.m_den;
   return Fraction(num, den);
}

//--------------------------------------------------------------------------

inline Fraction operator-(const Fraction& f1, const Fraction& f2)
{
   int num = f1.m_num*f2.m_den - f2.m_num*f1.m_den;
   int den = f1.m_den * f2.m_den;
   return Fraction(num, den);
}

//--------------------------------------------------------------------------

inline Fraction operator*(const Fraction& f1, const Fraction& f2)
{
   int num = f1.m_num * f2.m_num;
   int den = f1.m_den * f2.m_den;
   return Fraction(num, den);
}

//--------------------------------------------------------------------------

inline Fraction operator/(const Fraction& f1, const Fraction& f2)
{
   int num = f1.m_num * f2.m_den;
   int den = f1.m_den * f2.m_num;
   return Fraction(num, den);
}

inline std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
   os << f.m_num << "/" << f.m_den;
   return os;
}

//--------------------------------------------------------------------------