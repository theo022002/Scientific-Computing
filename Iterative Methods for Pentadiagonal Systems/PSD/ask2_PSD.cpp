// sdi2000014 - Theodora Archontaki //
#include "Functions.h"
using namespace std;

vector<long double> MatrixVectorMultiplication(vector<vector<long double>> A, vector<long double> x)   // Pollaplasiasmos pinaka me di8anusma
{
    int n = A.size();
    vector<long double> b(n, 0.0);
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            b[i] += A[i][j] * x[j];
        }
    }
    return b;
}

long double dotProduct(vector<long double> a, vector<long double> b)                               // Ypologizei to ginomeno vector me vector
{
    long double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) 
    {
        result += a[i] * b[i];
    }
    return result;
}

vector<long double> psdNiethammer(vector<vector<long double>> A, vector<long double> b, int flag_print, long double omega, long double tau) 
{
    int n = A.size();
    int it_count = 0;
    vector<long double> x(n, 0.0);                                                                 // x(0) = b
    vector<long double> r = b;                                                                     // r = b
    long double error = 1.0;                                                                       // ARxikopoioume to error
    long double epsilon = 0.5e-6;                                                                  // Arxikopoioume thn epithimith akribeia

    while (error > epsilon)                                                    
    {
        vector<long double> z(n, 0.0);
        for (int i = 0; i < n; ++i) 
        {
            z[i] = r[i] / (1 + omega * tau * abs(A[i][i]));                                        
        }
        vector<long double> p = MatrixVectorMultiplication(A, z);                                  // p = A*z
        long double alpha = 0.0;
        long double beta = 0.0;
        
        for (int i = 0; i < n; ++i)                                                                // Ypologizoume to alpha kai to beta
        {
            alpha += r[i] * z[i];
            beta += p[i] * z[i];
        }
        alpha /= beta;

        for (int i = 0; i < n; ++i)                                                                // Enhmerwnoume thn lush kai to upoloipo
        {
            x[i] += alpha * z[i];
            r[i] -= alpha * p[i];
        }

        error = sqrt(dotProduct(r, r));                                                            // Ypologizoume to error
        it_count++;                                                                            
    }
    if (flag_print == 1)
        cout << "\nWe have done " << it_count << " iterations.\n\n";

    return x;                                                                                      // Epistrefoume thn lush
}