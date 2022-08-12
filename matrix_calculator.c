#include <stdio.h>

// Declaration of the functions.
void readMatrix(float *matrix, int row, int col);
void printMatrix(float *matrix, int row, int col);
void sumMatrix(float *matrix1, float *matrix2, int row, int col);
void subMatrix(float *matrix1, float *matrix2, int row, int col);
void scalarMulMatrix(float *matrix, float scalar, int row, int col);
void mulMatrix(float *matrix1, float *matrix2, int row1, int col1row2, int col2);
void determinant2Matrix(float *matrix);
void determinant3Matrix(float *matrix);

int main() {
    // Declaring the required variables used to perform the given calculations.
    float matrix1[10][10], matrix2[10][10];
    float scalar;
    int choice, row1, col1, row2, col2;
    char c;

    // Creating a loop to perform the operations.
    do {
        printf("\n MATRIX CALCULATOR\n");
        printf("\n Matrix Calculator Menu :\n");
        printf("  Press 1 for Sum of Matrix.\n");
        printf("  Press 2 for Subtraction of Matrix.\n");
        printf("  Press 3 for Scalar Multiplication.\n");
        printf("  Press 4 for Matrix Multiplication.\n");
        printf("  Press 5 to find Determinant of 2x2 Matrix.\n");
        printf("  Press 6 to find Determinant of 3x3 Matrix.\n");

        printf("\n Enter choice(1-6) : ");
        scanf("%d", &choice);

        // Switch case according to the given choice.
        switch (choice) {

            // Case 1 for addition of 2 matrices.
            case 1:
                printf("\n**Number of rows and columns of both matrix should be same**\n\n");
                printf("Enter number of rows and columns of matrix:\n");
                scanf("%d%d", &row1, &col1);

                // Taking inputs in the 2 matrices.
                printf("\nEnter the values of 1st matrix:\n");
                readMatrix((float *)matrix1, row1, col1);
                printf("\nEnter the values of 2nd matrix:\n");
                readMatrix((float *)matrix2, row1, col1);

                // Calling the sumMatrix function to perform addition of the above matrices.
                sumMatrix((float *)matrix1, (float *)matrix2, row1, col1);
                break;
            
            // Case 2 for subtraction of the matrices.
            case 2:
                printf("\n**Number of rows and columns of both matrix should be same**\n\n");
                printf("Enter number of rows and columns of matrix:\n");
                scanf("%d%d", &row1, &col1);

                // Taking inputs in the 2 matrices.
                printf("\nEnter the values of 1st matrix:\n");
                readMatrix((float *)matrix1, row1, col1);
                printf("\nEnter the values of 2nd matrix:\n");
                readMatrix((float *)matrix2, row1, col1);

                // Calling the subMatrix function to perform subtraction of the above matrices.
                subMatrix((float *)matrix1, (float *)matrix2, row1, col1);
                break;

            // Case 3 for scalar multiplication on a matrix.
            case 3:
                printf("\nEnter the number to multiply the matrix with: ");
                scanf("%f", &scalar);
                printf("\nEnter number of rows and columns of the matrix:\n");
                scanf("%d%d", &row1, &col1);

                // Taking inputs in the matrix.
                printf("\nEnter the values of the matrix:\n");
                readMatrix((float *)matrix1, row1, col1);

                // Calling the scalarMulMatrix function to perform scalar multiplication on the above matrix.
                scalarMulMatrix((float *)matrix1, scalar, row1, col1);
                break;

            // Case 4 for multiplication of 2 matrices.
            case 4:
                printf("\n**Number of columns of 1st matrix should be equal to the number of rows of 2nd matrix**\n\n");
                x:
                printf("Enter number of rows and columns of 1st matrix:\n");
                scanf("%d%d", &row1, &col1);
                printf("\nEnter number of rows and columns of 2nd matrix:\n");
                scanf("%d%d", &row2, &col2);

                // Checking for the multiplication rule of matrix.
                if (col1 != row2) {
                    printf("\nError!! Number of columns of 1st matrix is not equal to number of rows of 2nd matrix.\n");
                    goto x;
                }

                // Taking inputs in the 2 matrices.
                printf("\nEnter the values of 1st matrix:\n");
                readMatrix((float *)matrix1, row1, col1);
                printf("\nEnter the values of 2nd matrix:\n");
                readMatrix((float *)matrix2, row2, col2);

                // Calling the mulMatrix function to perform multiplication of the above matrices.
                mulMatrix((float *)matrix1, (float *)matrix2, row1, col1, col2);
                break;

            // Case 5 for determinant of 2x2 matrix.
            case 5:
                // Taking inputs in the matrix.
                printf("\nEnter the values of the matrix:\n");
                readMatrix((float *)matrix1, 2, 2);

                // Calling the determinant2Matrix function to find determinant of the above matrix.
                determinant2Matrix((float *)matrix1);
                break;

            // Case 6 for determinant of 3x3 matrix.
            case 6:
                // Taking inputs in the matrix.
                printf("\nEnter the values of the matrix:\n");
                readMatrix((float *)matrix1, 3, 3);

                // Calling the determinant3Matrix function to find determinant of the above matrix.
                determinant3Matrix((float *)matrix1);
                break;

            // Default case.
            default:
                printf("\nIncorrect Choice\n\n");
                break;
        }

        // Asking to do more calculations.
        fflush(stdin);
        printf("Do you want to do more calculations? [Y/N]:\t");
        scanf("%c", &c);
        if(c==78 || c==110)
            choice = 0;

    } while (choice != 0);

    return 0;
}

// Function to read matrix.
void readMatrix(float *matrix, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            scanf("%f", matrix);
            matrix++;
        }
    }
}

// Function to print matrix.
void printMatrix(float *matrix, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf("%.2f\t", *matrix);
            matrix++;
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add 2 matrix.
void sumMatrix(float *matrix1, float *matrix2, int row, int col) {
    float matrixSum[row][col];

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            matrixSum[i][j] = *matrix1 + *matrix2;
            matrix1++;
            matrix2++;
        }
    }
    printf("\nSum of the matrices:\n");
    printMatrix((float *)matrixSum, row, col);
}

// Function to subtract a matrix from another.
void subMatrix(float *matrix1, float *matrix2, int row, int col) {
    float matrixSub[row][col];

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            matrixSub[i][j] = *matrix1 - *matrix2;
            matrix1++;
            matrix2++;
        }
    }
    printf("\nSubtraction of 2nd matrix from 1st matrix:\n");
    printMatrix((float *)matrixSub, row, col);
}

// Function for scalar multiplication of a matrix.
void scalarMulMatrix(float *matrix, float scalar, int row, int col) {
    float matrixScalar[row][col];

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            matrixScalar[i][j] = *matrix * scalar;
            matrix++;
        }
    }
    printf("\nScalar multiplication of the matrix:\n");
    printMatrix((float *)matrixScalar, row, col);
}

// Function to multiply 2 matrix.
void mulMatrix(float *matrix1, float *matrix2, int row1, int col1row2, int col2) {
    float mat1[row1][col1row2], mat2[col1row2][col2];
    float matrixMul[row1][col2];

    for (int i=0; i<row1; i++) {
        for (int j=0; j<col1row2; j++) {
            mat1[i][j] = *matrix1;
            matrix1++;
        }
    }

    for (int i=0; i<col1row2; i++) {
        for (int j=0; j<col2; j++) {
            mat2[i][j] = *matrix2;
            matrix2++;
        }
    }

    for (int i=0; i<row1; i++) {
        for (int j=0; j<col2; j++) {
            for (int k=0; k<col1row2; k++) {
                matrixMul[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
   }
            
    printf("\nMultiplication of the matrices:\n");
    printMatrix((float *)matrixMul, row1, col2);
}

// Function to find determinant of 2x2 matrix.
void determinant2Matrix(float *matrix) {
    float mat[2][2];
    float determinant;

    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            mat[i][j] = *matrix;
            matrix++;
        }
    }
    determinant = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];

    printf("\nDeterminant of the above matrix:\t%.2f\n\n", determinant);
}

// Function to find determinant of 3x3 matrix.
void determinant3Matrix(float *matrix) {
    float mat[3][3];
    float determinant;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            mat[i][j] = *matrix;
            matrix++;
        }
    }
    for(int i=0; i<3; i++)
        determinant += (mat[0][i]*(mat[1][(i+1)%3]*mat[2][(i+2)%3] - mat[1][(i+2)%3]*mat[2][(i+1)%3]));

    printf("\nDeterminant of the above matrix:\t%.2f\n\n", determinant);
}