// -lgmpxx -lgmp
// void mpz_fac_ui(mpz_t rop, unsigned long int n)
// Set rop to the factorial of n


#include<iostream>
#include <cstdio>    // for atoi()
#include <iomanip>
#include <cmath>  // for lgamma()
#include <gmpxx.h>   // g++ -lgmpxx -lgmp -g nPk_gmp.cpp -std=c++17 -o nPk


using namespace std;

// Using this fact:  n! = lgamma(n+1)  or (n-1)! = lgamma(n)
// nCk = n! / (k! * (n - k)!) ----> nCk = exp(lgamma(n+1)-lgamma(k+1)-lgamma(n-k+1))
// nPk = n! / (n-k)!  ----->  nPk = exp(lgamma(n+1)-lgamma(n-k+1))

mpz_class factorial(unsigned int n)
{
    mpz_class result(n); // initialize an arbitrary-sized integer with 'n'
    if (n == 0) return 1;
    while(n-- > 1) result *= n; // compute the product with every integers < n
    return result;
}

int main(int argc, char *argv[])
{
    if (argc!= 2)  {
       std::cout << "[USE] : " << argv[0] << " <integer to find factorial of>";
       std::cout << "\nYou cannot have " << argc - 1 << " parameters.\n\n";
	   return -1;
    }
    unsigned int a = atoi(argv[1]);

    cout << "\n" << a << "! = " << factorial(a) << '\n' << std::endl;

}