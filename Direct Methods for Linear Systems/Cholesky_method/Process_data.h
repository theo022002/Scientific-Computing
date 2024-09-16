// sdi2000014 - Theodora Archontaki //
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <random>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

extern int Flag_x;
extern int F;
extern vector<long double> x;

void initializeA(vector<vector<long double>> & , int );                                //Sunarthsh gia na arxikopoioume ena pinaka A me megethos n
void ReadFromFile(vector<vector<long double>> & , vector<long double> & , int & );     //Sunarthsh gia na diabazoume apo ena arxeio .txt ta dedomena
void readingData(vector<vector<long double>> & , vector<long double> & );              //Diabazei ta dedomena me ton tropo pou zitaei o xrhsths

vector<vector<long double>> matrixMultiplication(vector<vector<long double>> , vector<vector<long double>> );       //Kanei ton pollaplasiasmo enos nxn pinaka me enan nxn pinaka