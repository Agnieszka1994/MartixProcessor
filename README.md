# Matrix Processor 

This program allows you to perform a variety of operations on matrices including addition, multiplication, finding the determinant, and dealing with inverse matrices.

**The program supports:**

- addition
- multiplication by number
- matrix by matrix multiplication
- transposition along the main diagonal
- transposition along the side diagonal
- transposition along the vertical line
- transposition along the horizontal line
- finding the determinant
- finding the inverse of a matrix

**The program executes the below steps:**
- Prints a menu consisting of 4 options. 
- Reads the user's choice.
- Reads all data (matrices, constants) needed to perform the chosen operation. 
- Calculates the result and outputs it. 
- Repeats all these steps.

## Sample usage
**Multiply matrix by a constant**
```
1. Add matrices
2. Multiply matrix by a constant
3. Multiply matrices
4. Transpose matrix
5. Calculate a determinant
6. Inverse matrix
0. Exit
Enter your choice:
2
Enter size of matrix:
5 5
Enter matrix:
2.6 6.6 8.8 8 5
2 2 2 2 2
2.25 0.5 9 88 5
2 1 5 6 5
0 2 3 1 2
Enter constant:
0.5

 1.3  3.3  4.4    4  2.5
   1    1    1    1    1
 1.1 0.25  4.5   44  2.5
   1  0.5  2.5    3  2.5
   0    1  1.5  0.5    1
```
**Transpose matrix about the side diagonal**
```
1. Add matrices
2. Multiply matrix by a constant
3. Multiply matrices
4. Transpose matrix
5. Calculate a determinant
6. Inverse matrix
0. Exit
Enter your choice:
4
1. Main diagonal
2. Side diagonal
3. Vertical line
4. Horizontal line
0. Back to main menu
Enter your choice:
2
Enter size of matrix:
12 5
Enter matrix:
1 0 0 0 0
2 0 0 0 0
3 0 0 0 0
4 0 0 0 0
5 0 0 0 0
6 0 0 0 0
7 0 0 0 0
8 0 0 0 0
9 0 0 0 0
10 0 0 0 0
11 0 0 0 0
12 0 0 0 0

   0    0    0    0    0    0    0    0    0    0    0    0
   0    0    0    0    0    0    0    0    0    0    0    0
   0    0    0    0    0    0    0    0    0    0    0    0
   0    0    0    0    0    0    0    0    0    0    0    0
  12   11   10    9    8    7    6    5    4    3    2    1
```