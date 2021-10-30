#include "../include/for_you_to_do.h"

int get_block_size(){
    //return the block size you'd like to use 
    /*add your code here */
    return 2;
  
}

/**
 * 
 * this function computes LU factorization
 * for a square matrix
 * 
 * syntax 
 *  
 *  input : 
 *      A     n by n , square matrix
 *      ipiv  1 by n , vector
 *      n            , length of vector / size of matrix
 *  
 *  output :
 *      return -1 : if the matrix A is singular (max pivot == 0)
 *      return  0 : return normally 
 * 
 **/


int mydgetrf(double *A, int *ipiv, int n)
{
    /* add your code here */

        int i = 0, t = 1, j, k;
        for (i = 0; i < n-1;i++)
        {
                int max_ind = i;
                int max = abs(A[i,i]);
                for (t = i+1; t < n; t ++)
                {
                        if (abs(A[t,i]) >max )
                        {
                                max_ind = t;
                                max = abs(A[t,i]);
                        }

                }

                if (max==0)
                {
                        return -1;
                }
                else
                {
                        if (max_ind!=i)
                        {
                                double temps;
                                temps = ipiv[i];
                                ipiv[i] = ipiv[max_ind];
                                ipiv[max_ind] = temps;
                                double *tempv = (double *) malloc(sizeof(double) * n);
                                int temp_iter = 0;
                                for (temp_iter = 0; temp_iter<n; temp_iter++)
                                {
                                        tempv[temp_iter] = A[i*n+temp_iter];
                                }

                                for (temp_iter = 0; temp_iter<n; temp_iter++)
                                {
                                        A[i*n+temp_iter] = A[max_ind*n+temp_iter];
                                }


                                for (temp_iter = 0; temp_iter<n; temp_iter++)
                                {
                                        A[max_ind*n+temp_iter] = tempv[temp_iter];
                                }
                        }


                }

                for (j = i+1;j < n; j++)
                {
                        A[j*n+i] = A[j*n+i] / A[i*n+i];
                        for (k = i+1; k < n;k++)
                        {
                                A[j*n+k] = A[j*n+k] - A[j*n+i]*A[i*n+k];
                        }
                }
        }


    return 0;
}


/**
 * 
 * this function computes triangular matrix - vector solver
 * for a square matrix . according to lecture slides, this
 * function computes forward AND backward subtitution in the
 * same function.
 * 
 * syntax 
 *  
 *  input :
 *      UPLO  'L' or 'U' , denotes whether input matrix is upper
 *                         lower triangular . ( forward / backward
 *                         substitution )
 * 
 *      A     n by n     , square matrix
 * 
 *      B     1 by n     , vector
 * 
 *      ipiv  1 by n     , vector , denotes interchanged index due
 *                                  to pivoting by mydgetrf()
 * 
 *      n                , length of vector / size of matrix
 *  
 *  output :
 *      none
 * 
 **/
void mydtrsv(char UPLO, double *A, double *B, int n, int *ipiv)
{

        double *y = (double *) malloc(sizeof(double) * n);
        double *x = (double *) malloc(sizeof(double) * n);

        int i, j;
        double temp = 0;

    /* add your code here */
        if (UPLO == 'L')
        {
                y[0] = B[ipiv[0]];

                for (i = 1; i < n; i++)
                {
                        y[i] = B[ipiv[i]];

                        for (j = 1; j < i; j++) 
                        {
                                y[i] -= y[j] * A[i*n + j]; 
                        }

                }


                for (i = 1; i < n; i++)
                {
                       B[i] = y[i];
                }

        }

        else
        {
                
                for (i = 1; i < n; i++)
                {
                       y[i] = B[i];
                }

                x[n-1] = y[n-1] / A[n*n-1] ;

                for (i = n-2; i > 0; i--)
                {
                        x[i] = y[i];

                        for (j = i+1; j < n; j++) 
                        {
                                x[i] -= (x[j] * A[i*n + j] )/ A[i*n+i] ; 
                        }
                }


                for (i = 1; i < n; i++)
                {
                       B[i] = x[i];
                }

                
        }
        free(y);
        free(x);


    return;
}

/**
 * 
 * Same function as what you used in lab1, cache_part4.c : optimal( ... ).
 * 
 **/
void mydgemm(double *A, double *B, double *C, int n, int i, int j, int k, int b)
{
    /* add your code here */
    /* please just copy from your lab1 function optimal( ... ) */
    return;
}

/**
 * 
 * this function computes LU decomposition
 * for a square matrix using block gepp introduced in course
 * lecture .
 * 
 * just implement the block algorithm you learned in class.
 * 
 * syntax 
 *  
 *  input :
 *      
 * 
 *      A     n by n     , square matrix
 * 
 *    
 * 
 *      ipiv  1 by n     , vector , denotes interchanged index due
 *                                  to pivoting by mydgetrf()
 * 
 *      n                , length of vector / size of matrix
 *     
 *      b                , block size   
 *  output :
 *      return -1 : if the matrix A is singular (max pivot == 0)
 *      return  0 : return normally 
 * 
 **/
int mydgetrf_block(double *A, int *ipiv, int n, int b) 
{
    return 0;
}

