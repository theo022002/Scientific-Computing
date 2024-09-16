// sdi2000014 - Theodora Archontaki //
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
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

void initializeA(vector<vector<long double>> & , int );                                //Sunarthsh gia na arxikopoioume ena pinaka A me megethos n
void ReadFromFile(vector<vector<long double>> & , vector<long double> & , int & );     //Sunarthsh gia na diabazoume apo ena arxeio .txt ta dedomena
double random_number(double , double );                                                //Dhmiourgei enan akeraio mesa se ena diasthma [a,b]
void readingData(vector<vector<long double>> & , vector<long double> & );              //Diabazei ta dedomena me ton tropo pou zitaei o xrhsths
void createA(vector<vector<long double>> & , double , double , double , double , int );// Ftiaxnei ton pinaka A me sugkekrimena a,b,c,d