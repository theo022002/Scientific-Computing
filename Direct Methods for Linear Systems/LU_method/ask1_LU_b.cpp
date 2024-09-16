// sdi2000014 - Theodora Archontaki //
#include "Functions.h"

void InverseMatrix(vector<vector<long double>> A, vector<vector<long double>> &A_inverse)  //Briskei ton antistrofo tou A
{
    int n = A.size();
    vector<vector<long double>> identity(n, vector<long double>(n, 0));                            

    for (int i = 0; i < n; ++i) 
    {
        identity[i][i] = 1.0;                                                            //Ftiaxnoume ton monadiaio pinaka I
    }
    initializeA(A_inverse, n);

    for(int i = 0; i < n; ++i)
    {
        vector<long double> b = identity[i];
        x = solveLinearSystem(A, b);                                                     //Lunoume to susthma Ax = b opou b = I
        for(int j = 0; j < n; ++j)                                                       //Lunoume to susthma A*A^(-1) = I gia kathe sthlh tou I gia na broume thn antistoixh sthlh tou A_inverse
        {
            A_inverse[j][i] = x[j];
        }
    }
    return;
}