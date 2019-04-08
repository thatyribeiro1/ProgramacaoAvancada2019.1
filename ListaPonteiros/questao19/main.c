#include <stdio.h>
#include <stdlib.h>

float get_matrix_element(float* A, int ncols, int row, int col)
{
    return A[(row*ncols) + col];
}

void set_matrix_element(float* A, int ncols, int row, int col, float value)
{
    A[(row*ncols) + col] = value;
}

void print_matrix(float* A, int nrows, int ncols)
{
    for(int row=0; row < nrows; row++)
    {
        for(int col=0; col < ncols; col++)
        {
            printf("%f ",  get_matrix_element(A, ncols, row, col) );
        }
        printf("\n");
    }
}

void mat_mult(float *A, float *B, float *C, int A_nrows, int A_ncols, int B_ncols)
{
    int B_rows = A_ncols;
    int C_nrows = A_nrows;
    int C_ncols = B_ncols;
    float value = 0;
    for(int row=0; row<A_nrows; row++)
    {
        for(int k=0; k<B_ncols; k++)
        {
            value = 0;
            for(int col=0; col<A_ncols; col++)
            {
                value += get_matrix_element(A, A_ncols, row, col) * get_matrix_element(B, B_ncols, col, k);
            }
            set_matrix_element(C, C_ncols, row, k, value);
        }
    }
}

int main()
{
    int A_nrows = 2;
    int A_ncols = 1;
    float* A = (float*) malloc(sizeof(float) * A_nrows* A_ncols);

    int B_nrows = A_ncols;
    int B_ncols = 2;
    float* B = (float*) malloc(sizeof(float) * B_nrows* B_ncols);

    int C_nrows = A_nrows;
    int C_ncols = B_ncols;
    float* C = (float*) malloc(sizeof(float) * C_nrows* C_ncols);

    set_matrix_element(A, A_ncols, 0, 0, 1);
    set_matrix_element(A, A_ncols, 1, 0, 2);

    set_matrix_element(B, B_ncols, 0, 0, 3);
    set_matrix_element(B, B_ncols, 0, 1, 4);

    set_matrix_element(C, C_ncols, 0, 0, 0);
    set_matrix_element(C, C_ncols, 0, 1, 0);
    set_matrix_element(C, C_ncols, 1, 0, 0);
    set_matrix_element(C, C_ncols, 1, 1, 0);

    printf("A\n");
    print_matrix(A, A_nrows, A_ncols);
    printf("\n");

    printf("B\n");
    print_matrix(B, B_nrows, B_ncols);
    printf("\n");

    printf("C\n");
    print_matrix(C, C_nrows, C_ncols);
    printf("\n");

    mat_mult(A, B, C, A_nrows, A_ncols, B_ncols);

    printf("C\n");
    print_matrix(C, C_nrows, C_ncols);
    printf("\n");

    return 0;
}


