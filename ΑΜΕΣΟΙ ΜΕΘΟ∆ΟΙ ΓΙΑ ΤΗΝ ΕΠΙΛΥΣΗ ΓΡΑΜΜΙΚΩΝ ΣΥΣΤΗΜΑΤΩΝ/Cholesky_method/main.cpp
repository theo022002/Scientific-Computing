// sdi2000014 - Theodora Archontaki //
#include "Functions.h"

vector<long double> x;

void print_Array(vector<vector<long double>> A)                           //Sunarthsh gia na ektupwnoume enan  pinaka
{
    for (int i = 0; i < A.size(); i++) 
    {
        for (int j = 0; j < A.size(); j++) 
        {
            cout <<  setprecision(2) << setw(4) << A[i][j] << "  ";
        }
        cout << endl;
    }
}

int main(void)
{
    vector<long double> b;
    vector<vector<long double>> A;
    vector<vector<long double>> A_inverse;
    
    initializeA(A_inverse, A.size());                                         //Arxikopoioume ton A
    readingData(A,b);   

    high_resolution_clock::time_point start_time_inverse = high_resolution_clock::now();
    InverseMatrix(A, A_inverse);                                              //Briskoume ton antistrofo tou A
    high_resolution_clock::time_point end_time_inverse = high_resolution_clock::now();

    high_resolution_clock::time_point start_time_system = high_resolution_clock::now();
    x = solveUsingCholesky(A, b);                                             //Lunoume to susthma Ax = b
    high_resolution_clock::time_point end_time_system = high_resolution_clock::now();

    duration<double> elapsed_time_system = end_time_system - start_time_system;
    duration<double> elapsed_time_inverse = end_time_inverse - start_time_inverse;

    cout << endl << "A is: " << endl;
    print_Array(A);         
    cout << endl << "Inverse of A is: " << endl;
    print_Array(A_inverse);        

    cout << endl << "Solution:" << endl;
    for (int i = 0; i < x.size(); ++i) 
    {
        cout << "x[" << i << "] = " << x[i] << endl;                          //Tupwnoume thn lush tou susthmatos
    }
    
    cout << endl << endl << "CPU time for solving a linear system: " << elapsed_time_system.count() << " seconds" << endl;
    cout << "CPU time for finding the inverse matrix: " << elapsed_time_inverse.count() << " seconds" << endl;

    if(Flag_x == 2 && F == 2)                                                 //An o xrhsths den dwsei to b kai an xrhsimopoihsei san A enan etoimo pinaka (Pei matrix)
    {
        Error_residual(A, b);
        Absolute_relative_error(x, b, A);

        ConditionNumber(A, A_inverse);
        Error_residual_inverse(A, A_inverse);
    }

    return 0;
}