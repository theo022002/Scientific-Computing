// sdi2000014 - Theodora Archontaki //
#include "Process_data.h"

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

int random_number(int a, int b)                                                     //Ftiaxnei tuxaious arithmous sto diasthma [a,b]
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(a, b);

    int randomNumber = distribution(gen);
    return randomNumber;                                                            //Epistrefei ton tuxaio arithmo 
}

void initializeA(vector<vector<long double>> &A, int n)                             //Arxikopoioume ton A
{
    A.resize(n);
    for (int i = 0; i < n; ++i) 
        A[i].resize(n);
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void createb(vector<vector<long double>> A, vector<long double> &b, int n)          //An to x = (1,...1) tote to bi tha einai to athroisma tvn aij
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

void create_A_Pei_Matrix(vector<vector<long double>> &A, int n)                     //Ftiaxnoume ton Pei matrix
{
    initializeA(A,n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                A[i][j] = n;
            else
                A[i][j] = 1;
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
        cout << "If you want to use a random array press 1, else press 2 and we will use as A the Pei matrix: ";
        cin >> F;
        cout << endl << "Give the dimension n of the array: ";                      //Zhtame na mas dwsei to megethos n tou pinaka
        cin >> n;
        if(F == 2)                                                                  //An thelei na xrhsimopoihsei enan etoimo pinaka        
        {       
            create_A_Pei_Matrix(A,n); 
            if(Flag_x == 1) 
            {      
                b.resize(n);
                for(int i = 0; i < n; i++)
                    b[i] = i;
                // A = {{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
                // b = {8, -11, -3};
                // A = {{2,1,-3,4,2},{-3,2,5,-3,1},{8,1,-3,2,4},{-4,2,3,-1,5},{6,2,1,-5,9}};
                // b = {3,15,11,18,26};
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
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    A[i][j] = random_number(-10,10);                                //Gemizoume ton A me tuxaia stoixeia
            }
            if(Flag_x == 1)
            {
                for(int i = 0; i < n; i++)
                {
                    b[i] = random_number(-10,10);                                   //Gemizoume ton b me tuxaia stoixeia
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