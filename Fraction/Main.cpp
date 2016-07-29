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
void expect_ne(const T& expected, const T& result)
{
   if (expected == result)
   {
      std::cout << "FAILED: " << expected << " == " << result << std::endl;
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

   return 0;
}