% Theodora Archontaki - sdi2000014
function [A] = createA(rows, cols)     % Ftiaxnoume enan sugkekrimeno A (Pei matrix)
    A = zeros(rows, cols);
    for j = 1:rows
        for i = 1:cols
            if i == j
                A(i,j) = rows;
            else
                A(i,j) = 1;
            end
        end
    end
end