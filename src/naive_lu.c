#include "../include/lu_functions.h"
#include "../include/for_you_to_do.h"

void naive_lu(double *A, double *B, int n)
{
    int ipiv[n], i;
    for (i = 0; i < n; i++) {
        ipiv[i] = i;
    }

    printf("\n\n\n Before ipiv is \n\n\n");
    print_matrix(ipiv, n, n);
    int success = mydgetrf(A, ipiv, n);


    printf("\n\n\n After ipiv is \n\n\n");
    print_matrix(ipiv, n, n);

    if (success) 
    {
        printf("LU factoration failed: coefficient matrix is singular.\n");
        return;
    }

    mydtrsv('L', A, B, n, ipiv);


    printf("\n\n\n After forward substitution A is \n\n\n");
    print_matrix(A, n, n);

    printf("\n\n After forward substitution, B is \n\n");

    print_matrix(B, n, 1);

    mydtrsv('U', A, B, n, ipiv);

    printf("\n\n\n After backward substitution, A is \n\n\n");
    print_matrix(A, n, n);

    printf("\n\n After backward substitution, B is \n\n");

    print_matrix(B, n, 1);

}