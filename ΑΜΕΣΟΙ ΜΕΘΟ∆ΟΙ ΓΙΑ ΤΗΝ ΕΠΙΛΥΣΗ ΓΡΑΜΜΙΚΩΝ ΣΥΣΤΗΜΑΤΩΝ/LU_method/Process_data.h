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
int random_number(int , int );                                                         //Dhmiourgei enan akeraio mesa se ena diasthma [a,b]
void readingData(vector<vector<long double>> & , vector<long double> & );              //Diabazei ta dedomena me ton tropo pou zitaei o xrhsths