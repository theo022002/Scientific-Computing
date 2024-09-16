// sdi2000014 - Theodora Archontaki //
#include "Functions.h"
using namespace std;

long double dotProduct(vector<long double> a, vector<long double> b)                               // Ypologizei to ginomeno vector me vector 
{
    long double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) 
    {
        result += a[i] * b[i];
    }
    return result;
}

vector<long double> ESOR(const vector<vector<long double>>& A, const vector<long double>& b, long double omega, long double tau, int flag_print) 
{
    long double epsilon = 0.5e-6;                                                                  // Arxikopoioume thn epithimuth akribeia                                                                            
    const int n = b.size();                                                                        // Briskoume to megethos tou pinaka
    vector<long double> x(n, 0.0), x_old(n), r(n), z(n), p(n);
    long double error = 1.0;                                                                       // Arxikopoioume to error          
    int it_count = 0;                                                                              // Arithmos epanalhpsewn
    x = b;                                                                                         // Arxikopoioume to x_0 me b

    while (error > epsilon)                                                                        // Ekteloume thn methodo oso to error einai megalutero apo epsilon
    {
        x_old = x;
        for (size_t i = 0; i < n; ++i)                                                             // Ypologizoume to residual r = b - Ax
        {
            r[i] = b[i] - dotProduct(A[i], x);
        }
        for (size_t i = 0; i < n; ++i)                                                             // Ypologizoume to z = (1 - tau) * x + tau * (x + omega * r)
        {
            z[i] = (1 - tau) * x[i] + tau * (x[i] + omega * r[i]);
        }
        for (size_t i = 0; i < n; ++i)                                                             // Ypologizoume to p = z - x_old
        {
            p[i] = z[i] - x_old[i];
        }
        for (size_t i = 0; i < n; ++i)                                                             // Enhmerwnoume to x = z + omega*p
        {
            x[i] = z[i] + omega * p[i];
        }
        error = sqrt(dotProduct(r, r));                                                            // Ypologizoume to error
        it_count++;                                                                                // Ypologizoume tis epanalipseis tou algorithmou
    } 

    if (flag_print == 1)
        cout << "\nWe have done " << it_count << " iterations.\n\n";

    return x;                                                                                      // Epistrefoume thn lush x
}