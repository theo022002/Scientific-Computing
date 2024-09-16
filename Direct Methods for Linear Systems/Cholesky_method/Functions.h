// sdi2000014 - Theodora Archontaki //
#include "Process_data.h"
using namespace std;

vector<vector<long double>> choleskyDecomposition(vector<vector<long double>> );                   //Sunarthsh paragontopoihshs enos pinaka me thn methodo LL
vector<long double> solveUsingCholesky(vector<vector<long double>> , vector<long double> );        //Lunei ena susthma afou exei kanei thn LL paragontopoihsh
void InverseMatrix(vector<vector<long double>> , vector<vector<long double>> & );                  //Briskei ton antistrofo tou A

void Error_residual(vector<vector<long double>> , vector<long double> );                           //Ypologizei to absolute relative residual 
void Absolute_relative_error(vector<long double> , vector<long double> , vector<vector<long double>> );  //Ypologizei to absolute relative error 

void ConditionNumber(vector<vector<long double>> , vector<vector<long double>> );                  //Ypologizei to condition number
void Error_residual_inverse(vector<vector<long double>> , vector<vector<long double>> );           //Ypologizei to apoluto sxetiko upoloipo kai sfalma ston upologissmo tou antistrofou 