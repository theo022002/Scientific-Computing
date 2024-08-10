% Theodora Archontaki - sdi2000014
function [A] = readingData()                % Diabazoume ta dedomena
    prompt = 'Enter 1 to input matrix, 2 to create specific/random matrix, 3 to input from file: ';
    choice = input(prompt);
    
    if choice == 1                          % An o xrhsths thelei na dwsei ta dedomena
        A = input('Enter the matrix A: ');  % Perimenoume ton xrhsth na dwsei ton pinaka
    elseif choice == 2                      % An o xrhsths thelei na xrhsimopoihsei tuxaio pinaka / ena sugkekrimeno pinaka
        prompt2 = 'Enter 1 to create a random matrix or 2 to create a specific A: ';
        choice2 = input(prompt2);
        m = input('\nEnter the number of rows: ');         % O xrhsths dinei ton arithmo twn grammwn 
        n = input('Enter the number of columns: ');      % O xrhsths dinei ton arithmo twn sthlwn 
        if choice2 == 1                     % An o xrhsths thelei na ftiaxtei enas tuxaios pinaka
            A = 5*rand(m, n);               % Ftiaxnoume enan tuxaio pinaka
        elseif choice2 == 2                 % An o xrhsths thelei na xrhsimopoihsei enan sugkekrimeno pinaka
            A = createA(m,n);               % Kaloume thn antistoixh sunarthsh
        else 
            error('Invalid choice');
        end
    elseif choice == 3                      % An o xrhsths thelei na diabasei ton pinaka apo ena arxeio                   
        filename = input('Enter the filename: ', 's');   % Dinei to onoma tou arxeiou 
        A = load(filename);                 % Diabazoume ton pinaka apo to arxeio 
    else
        error('Invalid choice');
    end
    A = double(A);
end