/*
	calculate number of permutations

// Using this fact:  n! = lgamma(n+1)  or (n-1)! = lgamma(n)
// nCk = n! / (k! * (n - k)!) ----> nCk = exp(lgamma(n+1)-lgamma(k+1)-lgamma(n-k+1))
// nPk = n! / (n-k)!  ----->  nPk = exp(lgamma(n+1)-lgamma(n-k+1))


/*
	The computation is straightforward: just write a simple function for each formula.
	If the formula are correct (how would you know?) all should be simple.
	C(a,b) = P(a,b)/fac(b)
*/

#include<iostream>
#include<sstream>
#include <cstdio>
#include <iomanip>
#include <cmath>  // for lgamma()


using namespace std;

struct Exit : runtime_error {
	Exit(): runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s+s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s <<": " << i;
	error(os.str());
}

/*  R E P L A C E ***********************************************************************************

//  Factorial function (copyright 2010, Information Disciplines, Inc.)
//  ------------------

double                          //  Returns N! for N <= 170
 factorial(const unsigned int N)//  Infinity or NaN for N > 170
 {
  const int factorialMax = 170; //  Largest N for which the factorial
                                //    fits in a standard double float
  static int currentMax = 18;   //  Largest N for which we trust the
                                //    compiler to convert the decimal
                                //      constant value accurately
                                //    (See table below)    

//  Table of factorials (with one extra cell for overflow value)
//  -------------------

 static double factorialTable[factorialMax+2] = {
 1, 1, 2, 6, 24,  120 ,  720 ,   5040,  40320 ,  362880 , 3628800,
 39916800, 479001600, 6227020800, 87178291200 ,     1307674368000,
   20922789888000 ,  355687428096000          ,  6402373705728000};
//  Remaining values will be generated as needed.

    int n = (N  > factorialMax) ?  //  Guard against
             factorialMax + 1 : N; //    overflow

// If the table doesn't already contain the value, compute and save it
    
    while (currentMax < n)
        {
         ++currentMax;
         factorialTable[currentMax] 
         = currentMax * factorialTable[currentMax-1];
        }

   cout << "\n" << n << "! = "  << std::fixed << std::setprecision(0) << factorialTable[n];
   return factorialTable[n];     //  (Result) 
}

double n_permutations(unsigned int a, unsigned int b)
{
	if (a<b || a<1 || b<1) error("bad permutation sizes");
	return factorial(a)/factorial(a-b);
}

double n_combinations(unsigned int a, unsigned int b)
{
	return n_permutations(a,b)/factorial(b);
}

*************************************************************************************************/


// Using this fact:  n! = lgamma(n+1)  or (n-1)! = lgamma(n)
// nCk = n! / (k! * (n - k)!) ----> nCk = exp(lgamma(n+1)-lgamma(k+1)-lgamma(n-k+1))
// nPk = n! / (n-k)!  ----->  nPk = exp(lgamma(n+1)-lgamma(n-k+1))

double nPk(double n, double k)  {
    return exp(lgamma(n+1)-lgamma(n-k+1));
}



int main(int argc, char *argv[])
try
{
    if (argc!= 3)  {
	   std::cout << "[USE] : " << argv[0] << " <number of elements n in set> <taken r at a time>";
       std::cout << "\nYou cannot have " << argc - 1 << " parameters.\n\n";
	   return -1;
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);

    cout << "\nP(" << a << ',' << b << ") = " << std::fixed << std::setprecision(0) 
         << nPk(a,b) << '\n' << std::endl;

}
catch (runtime_error e) {	
	cout << e.what() << '\n';

}
