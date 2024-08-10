// sdi2000014 - Theodora Archontaki //
#include "Functions.h"
using namespace std;

void LU_decomposition(vector<vector<long double>> A, vector<vector<long double>> &L, vector<vector<long double>> &U, vector<int> &P)             //Kanei thn LU paragontopoihsh se enan pinaka A
{
    int n = A.size();                                                                              //Arxikopoioume to n me to megethos tou A
    L = vector<vector<long double>>(n, vector<long double>(n, 0.0));                               //Arxikopoioume ton L
    U = A;                                  
    for (int i = 0; i < n; ++i)                                                                    //Arxokopoioume to P
        P[i] = i;

    for (int k = 0; k < n - 1; ++k) 
    {
        int pivot_index = k;
        long double pivot_value = abs(U[k][k]);                                                    //Arxikopoioume to odhgo stoixeio              
        for (int i = k + 1; i < n; ++i)                                                            //Psaxnoume to odhgo stoixeio
        {
            if (abs(U[i][k]) > pivot_value) 
            {
                pivot_value = abs(U[i][k]);
                pivot_index = i;
            }
        }

        if (pivot_index != k)                                                                      //An xreiastei na kanoume swap grammes
        {
            swap(P[k], P[pivot_index]);                                                            //Allazoume tis grammes tou P
        }

        for (int i = k + 1; i < n; ++i) 
        {
            L[i][k] = static_cast<long double>(U[i][k]) / static_cast<long double>(U[k][k]);
            for (int j = k; j < n; ++j)
                U[i][j] -= L[i][k] * U[k][j];
        }
    }

    for (int i = 0; i < n; ++i)                                                                    //Kanoume thn diagwnio tou L = 1
        L[i][i] = 1.0;
    return;
}

void forward_substitution(vector<vector<long double>> L, vector<long double> b, vector<long double> &y)  //Pros ta mprosta antikatastash Ly = b
{
    int n = L.size();
    y.resize(n);

    for (int i = 0; i < n; ++i) 
    {
        y[i] = b[i];
        for (int j = 0; j < i; ++j) 
        {
            y[i] -= L[i][j] * y[j];
        }
    }
    return;
}

void backward_substitution(vector<vector<long double>> U, vector<long double> y, vector<long double> &x) //Pros ta pisw antikatastash Ux = y
{
    int n = U.size();
    x.resize(n);

    for (int i = n - 1; i >= 0; --i) 
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; ++j) 
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
    return;
}

vector<long double> solveLinearSystem(vector<vector<long double>> A, vector<long double> b)                //Lunei to susthma Ax = b
{
    int n = A.size();
    vector<vector<long double>> L, U;
    vector<long double> y(n);
    vector<int> P(n);
    
    LU_decomposition(A, L, U, P);                                                                          //Kanoume LU paragontopoihsh                                                    
    forward_substitution(L, b, y);                                                                         //Pros ta mprosta antikatastash
    backward_substitution(U, y, x);                                                                        //Pros ta pisw antikatastash

    return x;
}