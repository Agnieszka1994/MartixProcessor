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
## Matrix class - usage examples
Here are some examples to give you an idea how to use the class.

The class works on double type data. 
```cpp
using namespace mtx;
//you can create an empty matrix
Matrix a{};

//or initialize it with a vector
std::vector<std::vector<double>> vec = {
  {1, 6, 8},
  {5, 7, 8},
  {6, 9, 2}
}
Matrix b(vec);

//in order to addign a vector to an existing matrix, use round brackets
a(vec);

// you can also override the existing matrix by adding new values from vector
b({
  {3, 3, 7},
  {3, 3, 3},
  {6, 2, 2}
});
```
Thanks to the overloaded operators, you can use the class just like the built-in type.
```cpp
using namespace mtx;
Matrix a({
  {7, 8, 9, 6, 4, 6},
  {9, 9, 9, 8, 7, 6},
  {4, 5, 6, 5, 7, 8}
});

Matrix b({
  {1, 2, 3, 4, 5, 6},
  {1, 2, 3, 4, 5, 6},
  {6, 5, 4, 3, 2, 1}
});

Matrix c = a + b;

std::cout << a << b << c << std::flush; 
```
Output below:
```
7   8   9   6   4   6
9   9   9   8   7   6
4   5   6   5   7   8

1   2   3   4   5   6
1   2   3   4   5   6
6   5   4   3   2   1

 8  10  12  10   9  12
10  11  12  12  12  12
10  10  10   8   9   9
```
You can use addition assignment, subtraction assignment and multiplication assignment operators.
All operations will be performed according to the matrix operation rules.
```cpp
using namespace mtx;
Matrix a({
  {8, 9, 9},
  {5, 6, 7}
});

Matrix b({
  {2, 2},
  {2, 2},
  {2, 2}
});

a *= b;
std::cout << a << std::flush;
/* Output:
52   52
34   34
*/

Matrix c({
  {8, 9, 9, 9},
  {5, 6, 7, 4}
});

Matrix d({
  {2, 2, 1},
  {2, 2, 1},
  {2, 2, 1}
});

c *= d; // IMPOSSIBLE - throw exception! 
```
The class also contains some useful functions:
```cpp
using namespace mtx;

Matrix a({
  {7, 8, 9, 6, 4, 6},
  {9, 9, 9, 8, 7, 6},
  {4, 5, 6, 5, 7, 8}
});
// Transpose matrix about main diagonal
std::cout << a.transposeMain() << std::flush;
/* Output:
7    9    4
8    9    5
9    9    6
6    8    5
4    7    7
6    6    8
*/

// Transpose matrix about secondary diagonal
std::cout << a.transposeSide() << std::flush;
/* Output:
8    7    5    6    5    4
6    7    8    9    9    9
6    4    6    9    8    7
*/

// Transpose matrix about horizontal line
std::cout << a.transposeHorizontal() << std::flush;
/* Output:
6    4    6    9    8    7
6    7    8    9    9    9
8    7    5    6    5    4
*/

// Transpose matrix about vertical line
std::cout << a.transposeVertical() << std::flush;
/* Output:
7    8    9    6    4    6
9    9    9    8    7    6
4    5    6    5    7    8
*/

// finds an inverse matrix
Matrix f({
  { 1, 0,  4},
  {-1, 2,  1},
  { 1, 4, -2}
});
std::cout << f.inverse() << std::flush;
/* Output:
  -8   16   -8
  -1   -6   -5
  -6   -4    2
*/

// calculate determinant 
std::cout << f.calculateDeterminant() << std::flush;
/* Output: -32
*/
```

## Main Menu - Sample usage
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