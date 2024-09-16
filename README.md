# Scientific Computing - Overview:  
  
## Direct Methods for Linear Systems:  
This part of the project focuses on direct methods for solving linear systems. 
We have the implementation of two key algorithms:
1.	LU Factorization (with partial pivoting): The LU method decomposes a matrix into a product of lower and upper triangular matrices.
2.	Cholesky Factorization (LLT): This method is used for symmetric positive-definite matrices, decomposing the matrix into the product of a lower triangular matrix and its transpose.
   
Both algorithms have been implemented C++ and used to solve a linear system Ax=b and compute the inverse of matrix A.
The project  requires a performance evaluation of the algorithm, including computation time (cputime), the condition number of matrix A, and error analysis.  
  
## Iterative Methods for Pentadiagonal Systems:
This part of the assignment delves into iterative methods for solving linear systems, 
specifically focusing on a pentadiagonal matrix (a matrix with nonzero entries on the main diagonal and two diagonals above and below it).
We have the implementation of the following algorithms:
1.	ESOR (Extended Successive Over-Relaxation).
2.	PSD (Projected Successive Over-Relaxation) using Niethammer's scheme.
   
The task involves solving the linear system Ax=bAx  using these methods,
tuning parameters for optimal performance, and studying the convergence of the methods.
The assignment asks for experiments across various matrix sizes and conditions
to evaluate the number of iterations, the spectral radius of the iterative matrix, and computation time.
  
 
## Numerical computation of eigenvalues and eigenvectors of a matrix  
This part of the project focuses on the numerical computation of eigenvalues and eigenvectors 
of a matrix using the QR factorization method with Householder transformations.  

### Objective:  
We have implemented the QR factorization algorithm for a real m×n matrix A, utilizing Householder transformations.
This method is used to decompose a matrix A into an orthogonal matrix Q and an upper triangular matrix R such that A=QR. The
implementation is in MATLAB using double precision arithmetic for accuracy.

### Key Requirements:
The program should allow:  
1. Manual input of data.
2. Generation of a specific or random matrix.
3. Input from a file.

Performance Evaluation:
1. Execution time (cputime).  
2. Condition number of matrix R.  
3. Error metrics:    
    ∣∣A−QR∣∣∞∣∣A−QR∣∣∞​  
    ∣∣trans(Q)*Q−I∣∣∞∣∣trans(Q)*Q−I∣∣∞​    
    ∣∣A*inv(R)−Q∣∣∞∣∣A*inv(R)−Q∣∣∞​  

