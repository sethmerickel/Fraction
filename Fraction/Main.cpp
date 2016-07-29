#include <iostream>
#include <string>

#include "Fraction.h"

template <typename T>
void expect_eq(const T& expected, const T& result)
{
   if (expected != result)
   {
      std::cout << "FAILED: " << expected << " != " << result << std::endl;
   }
}

template <typename T>
void expect_true(bool b)
{
   if (b == false)
   {
      std::cout << "FAILED: expression is false\n";
   }
}

template <typename T>
void expect_ne(const T& expected, const T& result)
{
   if (expected == result)
   {
      std::cout << "FAILED: " << expected << " == " << result << std::endl;
   }
}

template <typename T>
void expect_lt(const T& left, const T& right)
{
   if (false == (left < right))
   {
      std::cout << "FAILED: " << left << " !< " << right << std::endl;
   }
}

template <typename T>
void expect_gt(const T& left, const T& right)
{
   if (false == (left > right))
   {
      std::cout << "FAILED: " << left << " !> " << right << std::endl;
   }
}

int main()
{   
   std::cout << "Test GCD\n";
   expect_eq(2, gcd(2, 4));
   expect_eq(2, gcd(4, 2));
   expect_eq(2, gcd(-4, 2));
   expect_eq(2, gcd(4, -2));
   expect_eq(5, gcd(0, 5));  // Not sure what this should return: 0, 1, or 5
   expect_eq(5, gcd(5, 0));  // Returning 5 seems to fit the definition of gcd the best

   std::cout << "Test sign\n";
   expect_eq(1, sign(1));
   expect_eq(-1, sign(-4));
   expect_eq(1, sign(0));

   std::cout << "Test reduce\n";
   int a = 2, b = 4;
   reduce(a, b);
   expect_eq(a, 1); expect_eq(b, 2);
   a = 0; b = 4;
   reduce(a, b);
   expect_eq(a, 0); expect_eq(b, 1);
   a = 2; b = 0;
   reduce(a, b);
   expect_eq(a, 1); expect_eq(b, 0);
   a = -2; b = 4;
   reduce(a, b);
   expect_eq(-1, a); expect_eq(2, b);
   a = 2; b = -4;
   reduce(a, b);
   expect_eq(-1, a); expect_eq(2, b);

   std::cout << "Test Compare\n";
   expect_eq(Fraction(1, 2), Fraction(2, 4));
   expect_eq(Fraction(1, -2), Fraction(-1, 2));
   expect_eq(Fraction(0, 1), Fraction(0, 2));
   expect_ne(Fraction(1, 2), Fraction(1, 3));
   expect_ne(Fraction(1, 2), Fraction(-1, 2));
   expect_lt(Fraction(1, 2), Fraction(1));
   expect_lt(Fraction(1, 3), Fraction(1, 2));
   expect_lt(Fraction(-1, 2), Fraction(1, 3));

   std::cout << "Test Math\n";
   expect_eq(Fraction(1, 2) + Fraction(1, 2), Fraction(1));
   expect_eq(Fraction(1, 2) + Fraction(0), Fraction(1, 2));
   expect_eq(Fraction(1) - Fraction(1, 2), Fraction(1, 2));
   expect_eq(Fraction(1, 2) + Fraction(-1, 3), Fraction(1, 2) - Fraction(1, 3));
   expect_eq(Fraction(2, 3) + Fraction(1, 3), Fraction(1));
   expect_eq(Fraction(-1, 2) + Fraction(1, 2), Fraction(0));
   expect_eq(Fraction(1, 2) * Fraction(1, 2), Fraction(1, 4));
   expect_eq(Fraction(1, 2) / Fraction(1, 2), Fraction(1));
   expect_eq(Fraction(1, 3) * Fraction(0), Fraction(0));
   expect_eq(Fraction(-1, 3) * Fraction(1), Fraction(-1, 3));
   expect_eq(Fraction(-1, 3) / Fraction(1), Fraction(-1, 3));
   expect_eq(Fraction(1, 3) / Fraction(-1), Fraction(-1, 3));


   return 0;
}