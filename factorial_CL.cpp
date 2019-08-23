
// C++ program to compute factorial of big numbers
#include<iostream>
#include <cstdlib>   // atof

using std::cout;
using std::cin;

// Maximum number of digits in output
#define MAX 500

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    cout << n << "! = ";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];

    cout << std::endl << std::endl;
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function may value of res_size and returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
    int carry = 0;  // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry  = prod/10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

// Driver program
int main(int argc, char *argv[])  {

    if (argc!= 2)  {
	   std::cout << "[USE] : " << argv[0] << " <integer to find factorial of>";
       std::cout << "\nYou cannot have " << argc - 1 << " parameters.\n\n";
	   return -1;
   }
    int N = atof(argv[1]);
    factorial(N);
    return 0;
}
