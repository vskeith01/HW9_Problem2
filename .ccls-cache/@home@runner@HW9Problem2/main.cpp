#include <iostream>
#include <iomanip>

using namespace std;

/////////////// Function Prototypes ////////////
void average(int matrix[][8], int row);
void printMatrix8(int matrix[][8], int N_ROWS, int N_COLUMNS);
void weightedAverage(int matrix[][8], int row);
void selectionSort(int matrix[][8], int row);
void copyMatrix8(int OGmatrix[][8], int NewMatrix[][8]);
void DroppedAverage(int matrix[][8], int row);

int main() {


  int grades [][8]{
                  {1,100,100,100,100},
                  {2,100,0,100,0},
                  {3,82,94,73,86},
                  {4,64,74,84,94},
                  {5,94,84,74,64} };

  for (int row = 0; row < 5; row++){
    average(grades, row);
    weightedAverage(grades, row);
    DroppedAverage(grades, row);
    }
  

  //printMatrix8(grades, 5, 8);

  return 0;
}


///////////// User Defined Functions ///////////

/* Function that calculates average for one row*/

void average(int matrix[][8], int row)
{

  double ave;
  ave = (matrix[row][1] + matrix[row][2] + matrix[row][3] + matrix[row][4] ) / 4;

  matrix[row][5] = ave;
  
  return;
}

/* This function calculates the weighted average for one row */
void weightedAverage(int matrix[][8], int row)
{

  double W_ave;
  W_ave = (0.2 * matrix[row][1]) + (0.3 * matrix[row][2]) + (0.3 * matrix[row][3]) + (0.2 * matrix[row][4]);

  matrix[row][6] = W_ave;

  return;
}


/* This function prints a matrix with 8 collums*/
void printMatrix8(int matrix[][8], int N_ROWS, int N_COLUMNS)
{
    int row, col;
    for (row = 0; row < N_ROWS; row++)
    {
        for(col = 0; col < N_COLUMNS; col++)
            cout << setw(6) << matrix[row][col] << " ";
        
        cout << endl;    
    }

  return;
}

/* this function sorts one row of the grades only in the matrix */

void selectionSort(int matrix[][8], int row)
{

  int index, smallestIndex, loc, temp;

  for (index = 1; index < (4 - 1); index++)
    {
      // increment through main array
      smallestIndex = index;

      // incrament through each comparison
      for (loc = index + 1; loc < 4; loc++){
        if (matrix[row][index] < matrix[row][smallestIndex])
          smallestIndex = loc;    // collums of new smallest index for this row
        }

      // make swap
      temp = matrix[row][smallestIndex];
      matrix[row][smallestIndex] = matrix[row][index];
      matrix[row][index] = temp;
    }
  
  return;
}

/* This function copies a matrix */
void copyMatrix8(int OGmatrix[][8], int NewMatrix[][8])
{

  for (int row = 0; row < 5; row++){
    for (int col = 0; col < 8; col++){
      NewMatrix[row][col] = OGmatrix[row][col];
    }
  }

  return;
}

/* This function calculates the average without the lowest value*/
void DroppedAverage(int matrix[][8], int row)
{

  int tempMatrix[][8]{};

  copyMatrix8(matrix, tempMatrix);

  selectionSort(tempMatrix, row);

  printMatrix8(tempMatrix, 5, 8);

  
  return;
}