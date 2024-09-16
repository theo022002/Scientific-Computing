// sdi2000014 - Theodora Archontaki //
#include "Functions.h"

vector<long double> matrixVectorProduct(vector<vector<long double>> A, vector<long double> x)                          //Kanei ton pollaplasiasmo enos nxn pinaka me enan nx1 pinaka
{
    size_t m = A.size();
    size_t n = A[0].size(); 
    vector<long double> result(m, 0.0);

    for (size_t i = 0; i < m; ++i) 
    {
        for (size_t j = 0; j < n; ++j) 
        {
            result[i] += A[i][j] * x[j];
        }
    }

    return result;
}

vector<vector<long double>> matrixMultiplication(vector<vector<long double>> A, vector<vector<long double>> B)         //Kanei ton pollaplasiasmo enos nxn pinaka me enan nxn pinaka
{
    int m = A.size();
    int n = B[0].size();
    int p = B.size();
    
    vector<vector<long double>> result(m, vector<long double>(n, 0.0));

    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            for (int k = 0; k < p; ++k) 
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

long double InfinityNorm2D(vector<vector<long double>> matrix)                                                         //Ypologizei thn apeirh norma enos nxn pinaka
{
    long double maxSum = 0.0;

    for (const auto& row : matrix) 
    {
        long double rowSum = 0.0;
        for (const auto& element : row) 
        {
            rowSum += abs(element);
        }
        maxSum = max(maxSum, rowSum);
    }

    return maxSum;
}

long double vectorNorm(vector<long double> v)                                                                          //Ypologizei thn apeirh norma enos nx1 pinaka
{
    long double sum_of_squares = 0.0;

    for (size_t i = 0; i < v.size(); ++i) 
    {
        sum_of_squares += v[i] * v[i];
    }

    return sqrt(sum_of_squares);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Error_residual(vector<vector<long double>> A, vector<long double> b)                                              //Ypologizei to apoluto sxetiko upoloipo
{
    vector<long double> Ax = matrixVectorProduct(A, x);                                                                //Ypologizei to A*x
    vector<long double> r;
    for (size_t i = 0; i < b.size(); ++i) 
    {
        r.push_back(b[i] - Ax[i]);
    }

    long double relative_residual = vectorNorm(r) / vectorNorm(b);

    cout << endl << "Absolute relative residual: " << relative_residual << endl;
    return;
}

void Absolute_relative_error(vector<long double> x, vector<long double> b, vector<vector<long double>> A)              //Ypologizei to apoluto sxetiko sfalma
{
    vector<long double> x_actual(A.size());                                                                            //Briskei to x_actual
    vector<long double> dx(A.size());
    for(int i = 0; i < A.size(); i ++)
        x_actual[i] = 1;

    for(int i = 0; i < A.size(); i++)
        dx[i] = x_actual[i] - x[i];                                                                                    //Ypologizei to dx = x_actual - x

    long double x_actual_norm = vectorNorm(x_actual);
    long double dx_norm = vectorNorm(dx);      
    long double error = (long double) dx_norm / x_actual_norm;

    cout << "Absolute relative error is: " << error << endl << endl;
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<long double>> inverse(vector<vector<long double>> matrix)                                                //Ypologizei ton Actual inverse tou pinaka A
{
    int n = matrix.size();
    vector<vector<long double>> inv(n, vector<long double>(n));

   for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                inv[i][j] = (long double) 2.0 / (long double) (2*n-1);
            }
            else
                inv[i][j] = (long double) -1.0 / (long double) ((n-1)*(2*n-1));
        }
    }

    return inv;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Error_residual_inverse(vector<vector<long double>> A, vector<vector<long double>> A_inverse)                      //Ypologizei to apoluto sxetiko upoloipo kai sfalma ston upologissmo tou antistrofou 
{
    vector<vector<long double>> AA_inv = matrixMultiplication(A, A_inverse);                                           //Ypologizoume to A*A_inv
    vector<vector<long double>> A_inv_actual = inverse(A);                                                             //Ypologizei ton actual inverse tou A
    vector<vector<long double>> B;
    vector<vector<long double>> B2;
    vector<vector<long double>> I;
    initializeA(I, A.size());
    initializeA(B, A.size());
    initializeA(B2, A.size());

    for (int i = 0; i < A.size(); ++i)                                                                                 //Ftiaxnoume ton pinaka I
    {
        for(int j = 0; j < A.size(); j++)
        {
            if(i == j)
                I[i][j] = 1;
            else    
                I[i][j] = 0;
        }
    }
    for (int i = 0; i < A.size(); ++i)                                                                                 //Ypologizoume ton B = A*A_inv - I
    {
        for(int j = 0; j < A.size(); j++)
        {
            B[i][j] = AA_inv[i][j] - I[i][j]; 
            B2[i][j] = A_inv_actual[i][j] - A_inverse[i][j];
        }
    }
    long double absolute_error = InfinityNorm2D(B2);
    long double absolute_residual = InfinityNorm2D(B);
    long double inf_norm = InfinityNorm2D(A_inv_actual);    
    
    long double relative_residual = absolute_residual / inf_norm;                                                      //Ypologizoume to apoluto sxetiko upoloipo
    long double relative_error = absolute_error / inf_norm;                                 //Ypologizoume to apoluto sxetiko sfalma
 
    cout << endl << "Absolute relative residual for calculating A_inverse: " << relative_residual << endl;
    cout << "Absolute relative error for calculating A_inverse: " << relative_error << endl;
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ConditionNumber(vector<vector<long double>> A, vector<vector<long double>> A_inv)                                 //Ypologizei to condition number
{
    long double norm_A = InfinityNorm2D(A);
    long double norm_A_inv = InfinityNorm2D(A_inv);
    long double cond_number = norm_A*norm_A_inv;
    cout << "The condition number is: " << cond_number << endl;
    return;
}