// sdi2000014 - Theodora Archontaki //
#include "Functions.h"
using namespace std;

vector<vector<long double>> choleskyDecomposition(vector<vector<long double>> A)                  //Kanei thn paragontopoihsh LL
{
    const int n = A.size();
    const long double epsilon = 1e-9; 
    vector<vector<long double>> L(n, vector<long double>(n, 0.0));

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j <= i; ++j) 
        {
            long double sum = 0.0;
            if (j == i) 
            {
                for (int k = 0; k < j; ++k)
                    sum += L[j][k] * L[j][k];
                L[j][j] = sqrtl(abs(A[j][j] - sum) + epsilon);
            } 
            else 
            {
                for (int k = 0; k < j; ++k)
                    sum += (L[i][k] * L[j][k]);
                if (L[j][j] == 0) 
                {
                    L[i][j] = (A[i][j] - sum) / (L[j][j] + epsilon);                               
                } 
                else 
                {
                    L[i][j] = (A[i][j] - sum) / L[j][j];
                }
            }
        }
    }
    return L;
}

vector<long double> solveUsingCholesky(vector<vector<long double>> A, vector<long double> b)       //Lunei ena grammiko susthma Ax = b
{
    const int n = A.size();
    vector<vector<long double>> L = choleskyDecomposition(A);

    vector<long double> y(n, 0);
    for (int i = 0; i < n; ++i)                                                                    //Kanoume pros ta mprosta antikatastash gia na lusoume to Ly = b
    {
        long double sum = 0;
        for (int j = 0; j < i; ++j)
            sum += L[i][j] * y[j];
        y[i] = (b[i] - sum) / L[i][i];
    }

    vector<long double> x(n, 0);
    for (int i = n - 1; i >= 0; --i)                                                               //Kanoume pros ta pisw antikatastash gia na lusoume to L^Tx = y
    { 
        long double sum = 0;
        for (int j = i + 1; j < n; ++j)
            sum += L[j][i] * x[j];
        x[i] = (y[i] - sum) / L[i][i];
    }

    return x;
}