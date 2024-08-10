% Theodora Archontaki - sdi2000014
function [Q, R] = ask3_QR_HOUS(A)           % Ypologizoume thn housholder paragontopoihsh
    [m, n] = size(A);                       % Briskoume ton arithmo twn grammwn kai twn sthlwn tou pinaka
    Q = eye(m);                             % Q = I
    R = A;                                  % R = A
    min_value = min(n,m);
    for j = 1:min_value                     
        normx = norm(R(j:end, j));          % Ypologizoume th norma ths sthlhs pou ksekinaei apo thn grammh j
        s = -sign(R(j, j));                 % Prosdiorizoume to proshmo tou kuriarxou stoixeiou ths sugkekrimenhs sthlhs
        if s == 0                           % Elegxoume thn periptwsh pou to kuriarxo stoixeio einai mhden
            s = 1;
        end
        u1 = R(j, j) - s * normx;           % Ypologizoume to prwto stoixeio tou vector u (Householder vector)
        w = R(j:end, j) / u1;               % Ftiaxnoume to w 
        w(1) = 1;                           % Eksasfalizoume oti to prwto stoixeio tou w einai 1
        tau = -s * u1 / normx;              % Ypologizoume suntelesth tau gia ton metasxhmatismo Householder 
        
        
        R(j:end, :) = R(j:end, :) - tau * (w * (w' * R(j:end, :)));    % Enhmerwnoume to R xrhsimopoiwntas ton metasxhmatismo Householder 
        Q(:, j:end) = Q(:, j:end) - (Q(:, j:end) * w) * (tau * w)';    % Enhmerwnoume to Q xrhsimopoiwntas ton metasxhmatismo Householder 
    end
end