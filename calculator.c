#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add();
void sub();
void mul();
void divide();
void mod();
void power();

int main() {
    char operator;

    // Taking arithematic operator as input in operator variable.
    printf("\n\t\t\tCALCULATOR\n");
    printf("\n\tEnter the arithematic operation you want to perform:\n\n\t ( ' + ' , ' - ' , ' * ' , ' / ' , ' % ' , ' ^ ' )\n\n\t");
    x:
    scanf("%c", &operator);
    fflush(stdin);

    switch (operator) {
    // Switch case according to the operator entered.
        case '+':
            add();     // Calling add function.
            break;
        
        case '-':
            sub();     // Calling sub function.
            break;
        
        case '*':
            mul();     // Calling mul function.
            break;
        
        case '/':
            divide();     // Calling divide function.
            break;
        
        case '%':
            mod();     // Calling mod function.
            break;
        
        case '^':
            power();     // Calling power function.
            break;
        
        default:
            // If the operator entered is incorrect then it will ask again to input.
            printf("\n\tInvalid Operator!! Please enter only ( ' + ' , ' - ' , ' * ' , ' / ' , ' % ' , ' ^ ' )\n\n\t");
            goto x;
            break;
    }

    return 0;
}

// Function to add numbers.
void add() {
    float *ptrNum, sum=0;
    int n;

    printf("\n\t->> ADDITION <<-\n\n\tEnter the number of operands you want to add:\t");
    scanf("%d", &n);

    ptrNum = (float *) calloc(n, sizeof(float));
    if(ptrNum == NULL)
        printf("\n\tError!! Memory Allocation Failed.\n");
    else {
        for(int i=0; i<n; i++) {
            printf("\n\tEnter operand %d: ", i+1);
            scanf("%f", &ptrNum[i]);
            sum = sum + ptrNum[i];
        }

        printf("\n\t>> Result (SUM) -> %.3f\n\n", sum);
    }
    free(ptrNum);
}

// Function to subtract numbers.
void sub() {
    float num1, num2;

    printf("\n\t->> SUBTRACTION <<-\n\n\tEnter the number from which you want to subtract:\t");
    scanf("%f", &num1);
    printf("\n\tEnter the number to subtract from the above number:\t");
    scanf("%f", &num2);

    printf("\n\t>> Result (SUBTRACT) -> %.3f\n\n", num1 - num2);
}

// Function to multiply numbers.
void mul() {
    float *ptrNum, mul=1;
    int n;

    printf("\n\t->> MULTIPLICATION <<-\n\n\tEnter the number of operands you want to multiply:\t");
    scanf("%d", &n);

    ptrNum = (float *) calloc(n, sizeof(float));
    if(ptrNum == NULL)
        printf("\n\tError!! Memory Allocation Failed.\n");
    else {
        for(int i=0; i<n; i++) {
            printf("\n\tEnter operand %d: ", i+1);
            scanf("%f", &ptrNum[i]);
            mul = mul * ptrNum[i];
        }

        printf("\n\t>> Result (MULTIPLY) -> %.3f\n\n", mul);
    }
    free(ptrNum);
}

// Function to divide numbers.
void divide() {
    float num1, num2;

    printf("\n\t->> DIVISION <<-\n\n\tEnter the number to be divided (Numerator):\t");
    scanf("%f", &num1);
    printf("\n\tEnter the number to divide the above number (Denominator):\t");
    scanf("%f", &num2);

    printf("\n\t>> Result (DIVIDE) -> %.3f\n\n", num1 / num2);
}

// Function to find mod of numbers.
void mod() {
    float num1, num2;

    printf("\n\t->> MODULUS <<-\n\n\tEnter the number to be divided (Numerator):\t");
    scanf("%f", &num1);
    printf("\n\tEnter the number to divide the above number (Denominator):\t");
    scanf("%f", &num2);

    printf("\n\t>> Result (MODULUS) -> %.3f\n\n", fmod(num1, num2));
}

// Function to find power of a number.
void power() {
    float base, power;

    printf("\n\t->> POWER <<-\n\n\tEnter the number whose power you want to know (Base):\t");
    scanf("%f", &base);
    printf("\n\tEnter power:\t");
    scanf("%f", &power);

    printf("\n\t>> Result (POWER) -> %.3f\n\n", pow(base, power));
}