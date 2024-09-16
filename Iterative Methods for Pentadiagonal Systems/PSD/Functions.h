// sdi2000014 - Theodora Archontaki //
#include "Process_data.h"
using namespace std;

vector<long double> MatrixVectorMultiplication(vector<vector<long double>> , vector<long double> );                         // Pollaplasiazei pinaka me vector
long double dotProduct(vector<long double> , vector<long double> );                                                         // Pollaplasiazei vector me vector
vector<long double> psdNiethammer(vector<vector<long double>> , vector<long double> , int , long double , long double );    // Epiluei to grammiko susthma 