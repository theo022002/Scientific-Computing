// sdi2000014 - Theodora Archontaki //
#include "Process_data.h"
#define a1 0.1
#define b1 0.2
#define c1 0.3
#define d1 0.4

void ReadFromFile(vector<vector<long double>> &A, vector<long double> &b, int &n)   //Diabazoume ta dedomena apo ena arxeio 
{
    string filename = " ";
    string line = " ";

    cout << "Give the name of the file: ";                                          //O xrhsths dinei to onoma tou arxeiou 
    cin >> filename;
    ifstream inputfile(filename);
    
    if (!inputfile.is_open())                                                       //Elegxoume an to arxeio uparxei 
    {
        cout << "Failed to open the file." << endl;
        return;
    }
    
    getline(inputfile, line);                                                       //Pame sthn prwth grammh tou arxeiou 

    try  
    {
        n = stoi(line);                                                             //Apo thn prwth grammh diabazoume to n
    } 
    catch (const invalid_argument& e) 
    {
        cerr << "Invalid argument: " << e.what() << endl;
        return;
    } 

    b.resize(n);                                                                    //Arxikopoioume ton pinaka b
    initializeA(A,n);                                                               //Arxikopoioume ton pinaka A

    for (int i = 0; i < n; ++i)                                                     //Diabazoume tis epomenes n grammes tou arxeiou 
    {
        getline(inputfile, line);
        istringstream iss(line);
        for (int j = 0; j < n; ++j) 
        {
            if (!(iss >> A[i][j]))                                                  //Apothikeuoume ta stoixeia ston pinaka A
            {
                cerr << "Error reading number from file." << endl;
                return;
            }
        }
    }
    if(Flag_x == 1)                                                                 //Diabazoume to b apo to arxeio mono an to zhthsei o xrhsths
    {
        getline(inputfile, line);                                                   //Diabazoume thn epomenh grammh h opoia einai kenh 
        getline(inputfile, line);                                                   //Proxwrame sthn epomenh grammh pou tha periexei ton pinaka b
        istringstream iss(line);
        for (int j = 0; j < n; ++j)                                                 //Diabazoume ta n stoixeia pou tha exei h grammh 
        {
            if (!(iss >> b[j]))                                                     //Kai ta apothikeuoume ston pinaka b
            {
                cerr << "Error reading number from file." << endl;
                return;
            }
        }
    }
    inputfile.close();                                                              //Kleinoume to arxeio 
    return;
} 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double random_number(double a, double b)                                            //Ftiaxnei tuxaious arithmous sto diasthma [a,b]
{
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> distribution(a, b);

    double randomNumber = distribution(gen);
    return randomNumber;                                                      //Epistrefei ton tuxaio arithmo 
}

void initializeA(vector<vector<long double>> &A, int n)                             //Arxikopoioume ton A
{
    A.resize(n);
    for (int i = 0; i < n; ++i) 
        A[i].resize(n);
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<vector<long double>> create5_diagonal(int n)                                 // Ftiaxnoume enan tuxaio pentadiagwnio pinaka 
{
    vector<vector<long double>> A;
    initializeA(A,n);                                                               // Arxikopoioume ton pinaka
    double a = random_number(-1.0,1.0);
    double b = random_number(-1.0,1.0);
    double c = random_number(-1.0,1.0);
    double d = random_number(-1.0,1.0);
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                A[i][j] = 4;
            if(i >= 2 && i == j+2)
                A[i][j] = -a;
            if(i >= 1 && i == j+1)
                A[i][j] = -b;
            if(i <= n-2 && i == j-1)
                A[i][j] = -c;
            if(i <= n-3 && i == j-2)
                A[i][j] = -d;
        }
    }
    return A;                                                                       // Epistrefoume ton pinaka
}

void createb(vector<vector<long double>> A, vector<long double> &b, int n)          //An to x = (1,...1) tote to bi tha einai to athroisma twn aij
{
    b.resize(n);
    initializeA(A,n);
    long double sum = 0.0;
    for (int j = 0; j < n; ++j) 
    {
        for (int i = 0; i < n; ++i) 
        {
            b[j] += A[j][i];
        }
    }
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void createA(vector<vector<long double>> &A , double a, double b, double c, double d, int n)  //Ftiaxnoume ton A 
{
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                A[i][j] = 4;
            if(i >= 2 && i == j+2)
                A[i][j] = -a;
            if(i >= 1 && i == j+1)
                A[i][j] = -b;
            if(i <= n-2 && i == j-1)
                A[i][j] = -c;
            if(i <= n-3 && i == j-2)
                A[i][j] = -d;
        }
    }
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int F = 0;
int Flag_x = 0;

void readingData(vector<vector<long double>> &A, vector<long double> &b)            //Analoga me to ti tha zhthsei o xrhsths diabazoume analoga ta dedomena
{
    int flag = 0;
    int n = 0;
    cout << "If you want to give b press 1 else press 2 and we use for x = (1,..1)^T: ";
    cin >> Flag_x;
    cout << endl << "For giving data press 1.\nFor creating random data press 2.\nFor reading from a file press 3:  "; 
    cin >> flag;
    cout << endl;

    if(flag == 1)                                                                   //An o xrhsths dialeksei na dwsei ta dedomena
    {
        cout << "Give the dimension of the nxn array: ";                            //Zhtame arxika thn diastash tou pinaka
        cin >> n;
        b.resize(n);                                                                //Arxikopoioume ton pinaka b
        initializeA(A, n);                                                          //Arxikopoioume ton pinaka A
        for(int i = 0; i < n; i++)                                                  //Diabazoume ta stoixeia tou A
        {
            for(int j = 0; j < n; j++)
            {
                cout << "Give A[" << i << "][" << j << "]: ";
                cin >> A[i][j];
                cout << endl;
            }
        }
        if(Flag_x == 1)
        {
            for(int j = 0; j < n; j++)                                              //Diabazoume ta stoixeia tou b
            {
                cout << "Give b[" << j << "]: ";
                cin >> b[j];
                cout << endl;
            }
        }
        else if(Flag_x == 2)                                                        //An o xrhsths den dwsei to b          
        {
            createb(A,b,n);
        }
    }

    if (flag == 2)                                                                  //An o xrhsths thelei na ftiaksei enan tuxaio pinaka / na xrthsimopoihsei enan etoimo
    {        
        cout << "If you want to use a random array press 1, else press 2 and we will use a ready A (a = 0.1, b = 0.2, c = 0.3, d = 0.4), b[i] = i: ";
        cin >> F;
        cout << endl << "Give the dimension n of the array: ";                      //Zhtame na mas dwsei to megethos n tou pinaka
        cin >> n;
        if(F == 2)                                                                  //An thelei na xrhsimopoihsei enan etoimo pinaka        
        {       
            initializeA(A,n);                                                       // Arxikopoioume ton A
            createA(A , a1, b1, c1, d1, n);                                         // Ftiaxnoume ton A gia sugkekrimena a,b,c,d
            if(Flag_x == 1) 
            {      
                b.resize(n);
                for(int i = 0; i < n; i++)
                    b[i] = i;
            }
            else if(Flag_x == 2)
            {
                createb(A,b,n);
            }
        }
        else if(F == 1)                                                             //An thelei na dhmiourghthei enas random pinakas                
        {
            b.resize(n);                                                            //Arxikopoioume ton pinaka b
            initializeA(A, n);                                                      //Arxikopoioume ton pinaka A
            A = create5_diagonal(n);
            if(Flag_x == 1)
            {
                for(int i = 0; i < n; i++)
                {
                    b[i] = random_number(-1.0, 1.0);                               //Gemizoume ton b me tuxaia stoixeia
                }
            }
            else if(Flag_x == 2)
            {
                createb(A,b,n);
            }
        }
    }

    if(flag == 3)                                                                   //An thelei o xrhsths na diasoume ta data apo ena arxeio
    {
        ReadFromFile(A,b,n);                                                        //Diabazoume tous pinakes apo ena arxeio .txt
        if(Flag_x == 2)
            createb(A,b,n);
    }
    return;
}