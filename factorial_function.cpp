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
        {++currentMax;
         factorialTable[currentMax] 
         = currentMax * factorialTable[currentMax-1];}
 
   return factorialTable[n];     //  (Result) 
}