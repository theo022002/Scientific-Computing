// sdi2000014 - Theodora Archontaki //
#include "Process_data.h"
#include <numeric>

void initializeA(vector<vector<long double>> &A, int n)                             //Arxikopoioume ton A
{
    A.resize(n);
    for (int i = 0; i < n; ++i) 
        A[i].resize(n);
    return;
}

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
    if(Flag_x == 1)                                                                 //An o xrhsths thelei na diabastei to b
    {
        getline(inputfile, line);                                                   //Diabazoume thn epomenh grammh h opoia einai kenh 
        getline(inputfile, line);                                                   //Proxwrame sthn epomenh gramma pou tha periexei ton pinaka b
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

void createb(vector<vector<long double>> A, vector<long double> &b, int n)
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

int random_number(int a, int b)                                                     //Ftiaxnei tuxaious arithmous sto diasthma [a,b]
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(a, b);

    int randomNumber = distribution(gen);
    return randomNumber;                                                            //Epistrefei ton tuxaio arithmo 
}

void create_A_Pei_Matrix(vector<vector<long double>> &A, int n)
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

vector<vector<long double>> generateRandomLowerTriangularMatrix(int size)           //Briskoume enan tuxaio pinaka katw trigwniko
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<long double> dis(0.0, 20.0);

    vector<vector<long double>> matrix(size, vector<long double>(size));
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j <= i; ++j) 
        {
            if (i == j) 
            {
                matrix[i][j] = abs(dis(gen));                                       //Sigoureuomaste oti o pinakas einai thetika orismenos
            } 
            else 
            {
                matrix[i][j] = dis(gen);
            }
        }
    }

    return matrix;
}

vector<vector<long double>> transpose(vector<vector<long double>> matrix)           //Briskoume ton anastrofo enos pinaka
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<long double>> result(cols, vector<long double>(rows));

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Flag_x = 0;
int F = 0;

void readingData(vector<vector<long double>> &A, vector<long double> &b)            //Analoga me to ti tha zhthsei o xrhsths diabazei analoga ta dedomena
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
            for(int j = 0; j < n; j++)                                                  //Diabazoume ta stoixeia tou b
            {
                cout << "Give b[" << j << "]: ";
                cin >> b[j];
                cout << endl;
            }
        }
        else if(Flag_x == 2)
        {
            createb(A,b,n);
        }
    }

    if (flag == 2)                                                                  //An o xrhsths thelei na ftiaksei enan tuxaio pinaka / na xrthsimopoihsei enan etoimo
    {        
        cout << "If you want to use a random array press 1, else press 2 and we use the Pei array: ";
        cin >> F;
        cout << endl << "Give the dimension n of the array: ";                      //Zhtame na mas dwsei to megethos n tou pinaka
        cin >> n;
        if(F == 2)                                                                  //An thelei na xrhsimopoihsei enan etoimo pinaka        
        {       
            create_A_Pei_Matrix(A,n);
            if(Flag_x == 1) 
            {     
                // n = 4;      
                // A = 
                // {   
                //     {5,7,6,5},
                //     {7,10,8,7},
                //     {6,8,10,9},
                //     {5,7,9,10}
                // };
                // b = {23, 32, 33, 31};
                b.resize(n);
                for(int i = 0; i < n; i++)
                    b[i] = i;
            }
            else if(Flag_x == 2)
            {
                createb(A,b,n);
                // n = 4;
                // A = 
                // {   
                //     {5,7,6,5},
                //     {7,10,8,7},
                //     {6,8,10,9},
                //     {5,7,9,10}
                // };
            }
        }
        else if(F == 1)                                                             //An thelei na dhmiourghthei enas random pinakas                
        {
            b.resize(n);                                                            //Arxikopoioume ton pinaka b
            initializeA(A, n);                                                      //Arxikopoioume ton pinaka A
            vector<vector<long double>> L = generateRandomLowerTriangularMatrix(n);
            vector<vector<long double>> L_t = transpose(L);
            A = matrixMultiplication(L, L_t);

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
        {    
            createb(A,b,n);
        }
    }
}