#pragma once

#include <ratio>

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

class Fraction
{
public:
	 

   int getNumerator() const;
   int getDenominator() const;

private:
   int m_num;
   int m_den;
};
