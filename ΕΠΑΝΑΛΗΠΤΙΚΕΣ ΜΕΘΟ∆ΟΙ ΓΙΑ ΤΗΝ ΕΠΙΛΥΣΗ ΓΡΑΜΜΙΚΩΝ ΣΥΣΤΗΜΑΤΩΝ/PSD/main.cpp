// sdi2000014 - Theodora Archontaki //
#include "Functions.h"

int main(void)
{
    vector<long double> b;
    vector<vector<long double>> A;
    //Arxikopoihsh timwn
    long double omega_min = 0.1;
    long double omega_max = 1.9;
    long double omega_step = 0.1;
    long double tau_min = 0.1;
    long double tau_max = 1.9;
    long double tau_step = 0.1;
    long double min_error = numeric_limits<double>::max();
    long double omega_optimal = 0.0;
    long double tau_optimal = 0.0;

    readingData(A,b);    
    high_resolution_clock::time_point start_time = high_resolution_clock::now();                   // Ypologizoume ton xrono pou xreiazetai gia na luthei to susthma me tis optimal parametrous
    for (double omega = omega_min; omega <= omega_max; omega += omega_step)                        // Epanalambanoume gia oles tis times tou omega
    {
        for (double tau = tau_min; tau <= tau_max; tau += tau_step)                                // Epanalambanoume gia oles tis times tou t
        {
            vector<long double> solution = psdNiethammer(A, b, 0, omega, tau);                     // Lunoume to susthma 
            double error = 0.0;
            for (size_t i = 0; i < b.size(); ++i)                                                  // Ypologizoume to error
            {
                error += abs(b[i] - dotProduct(A[i], solution));
            }

            if (error < min_error)                                                                 // Enhmerwnoume tis times twn optimal parametrwn
            {
                min_error = error;
                omega_optimal = omega;
                tau_optimal = tau;
            }
        }
    }
    high_resolution_clock::time_point end_time = high_resolution_clock::now();
    duration<double> duration = end_time - start_time;

    cout << endl << "A is: " << endl << endl;
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    vector<long double> solution = psdNiethammer(A, b, 1, omega_optimal, tau_optimal);             // Lunoume to susthma me tis beltistes times twn parametrwn w,t
    cout << "Solution:" << endl;                                                          
    for (size_t i = 0; i < solution.size(); ++i)                                                   // Ektupwnoume thn lush
    { 
        cout << "x[" << i << "] = " << solution[i] << endl;
    }
    // Ektupwnoume ton xrono, tis beltistes parametrous kai thn fasmatikh aktina
    cout << endl << "Optimal omega: " << omega_optimal << endl;
    cout << "Optimal tau: " << tau_optimal << endl;
    cout << "CPU-time is: " << duration.count() << " seconds." << endl;
    cout << "The spectral radius is: " << omega_optimal - 1 << ".\n";

    return 0;
}