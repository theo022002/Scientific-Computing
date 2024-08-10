% Theodora Archontaki - sdi2000014
A = readingData();               % Diabazoume ta dedomena

tic;
[Q, R] = ask3_QR_HOUS(A);        % Kanoume thn QR paragontopoihsh 
execution_time = toc;            % Ypologizoume ton xrono 

% Ypologizoume ta error kai to condition number tou R
error1 = norm(A - Q*R, 'inf');
error2 = norm(transpose(Q)*Q - eye(size(Q, 2)), 'inf');
error3 = norm(A/R - Q, 'inf');
condR = cond(R);

% Ektupwnoume ta apotelesmata
fprintf('\n||A - QR||_inf: %e\n', error1);
fprintf('||Q^TQ - I||_inf: %e\n', error2);
fprintf('||AR^-1 - Q||_inf: %e\n', error3);
fprintf('Condition number of R: %e\n', condR);
fprintf('Execution time: %f seconds\n', execution_time);