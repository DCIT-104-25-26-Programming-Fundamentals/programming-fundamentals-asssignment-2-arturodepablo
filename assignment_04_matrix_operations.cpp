// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void readMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int mat[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int rA, int cA, int cB) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[10][10], b[10][10], result[10][10];
    int rA, cA, rB, cB;

    // PART A: Transpose
    cout << "--- PART A: TRANSPOSE ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rA;
    cout << "Enter number of columns: ";
    cin >> cA;
    readMatrix(a, rA, cA);

    cout << endl << "Original Matrix:" << endl;
    printMatrix(a, rA, cA);

    transposeMatrix(a, result, rA, cA);
    cout << endl << "Transposed Matrix:" << endl;
    printMatrix(result, cA, rA);

    // PART B: Addition
    cout << endl << "--- PART B: ADDITION ---" << endl;
    cout << "Enter Matrix A elements:" << endl;
    readMatrix(a, rA, cA);
    cout << "Enter Matrix B elements:" << endl;
    readMatrix(b, rA, cA);

    addMatrices(a, b, result, rA, cA);
    cout << endl << "Sum of Matrices:" << endl;
    printMatrix(result, rA, cA);

    // PART C: Multiplication
    cout << endl << "--- PART C: MULTIPLICATION ---" << endl;
    cout << "Enter rows for Matrix A: ";
    cin >> rA;
    cout << "Enter columns for Matrix A: ";
    cin >> cA;
    cout << "Enter rows for Matrix B: ";
    cin >> rB;
    cout << "Enter columns for Matrix B: ";
    cin >> cB;

    if (cA != rB) {
        cout << "Error: Columns of Matrix A must equal rows of Matrix B." << endl;
    } else {
        cout << "Enter Matrix A elements:" << endl;
        readMatrix(a, rA, cA);
        cout << "Enter Matrix B elements:" << endl;
        readMatrix(b, rB, cB);

        multiplyMatrices(a, b, result, rA, cA, cB);
        cout << endl << "Product of Matrices:" << endl;
        printMatrix(result, rA, cB);
    }

    return 0;
}
