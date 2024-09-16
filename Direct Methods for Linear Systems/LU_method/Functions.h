// sdi2000014 - Theodora Archontaki //
#include "Process_data.h"
using namespace std;

typedef vector<vector<long double>> Matrix;

void LU_decomposition(Matrix , Matrix & , Matrix & , vector<int> & );                      //Sunarthsh paragontopoihshs enos pinaka me thn methodo LU
vector<long double> solveLinearSystem(Matrix , vector<long double> );                      //Lunei ena susthma afou exei kanei thn LU paragontopoihsh
void InverseMatrix(vector<vector<long double>> , vector<vector<long double>> & );          //Briskei ton antistrofo enos pinaka A

void Error_residual(vector<vector<long double>> , vector<long double> );                   //Ypologizei to absolute relative residual 
void Absolute_relative_error(vector<long double> , vector<long double> , vector<vector<long double>> );  //Ypologizei to absolute relative error 

void ConditionNumber(vector<vector<long double>> , vector<vector<long double>> );          //Ypologizei to condition number
void Error_residual_inverse(vector<vector<long double>> , vector<vector<long double>> );   //Ypologizei to apoluto sxetiko upoloipo ston upologissmo tou antistrofou 