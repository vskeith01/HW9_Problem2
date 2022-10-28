#include <iostream>
#include <iomanip>

using namespace std;

/////////////// Function Prototypes ////////////
void average(int matrix[][7], int row);
void printMatrix7(int matrix[][7], int N_ROWS, int N_COLUMNS);
void weightedAverage(int matrix[][7], int row);

int main() {


  int grades [][7]{
                  {1,100,100,100,100},
                  {2,100,0,100,0},
                  {3,82,94,73,86},
                  {4,64,74,84,94},
                  {5,94,84,74,64} };

  for (int row = 0; row < 5; row++){
    average(grades, row);
    weightedAverage(grades, row);
    }
  

  printMatrix7(grades, 5, 7);

  return 0;
}


///////////// User Defined Functions ///////////

/* Function that calculates average for one row*/

void average(int matrix[][7], int row)
{

  double ave;
  ave = (matrix[row][1] + matrix[row][2] + matrix[row][3] + matrix[row][4] ) / 4;

  matrix[row][5] = ave;
  
  return;
}

/* This function calculates the weighted average for one row */
void weightedAverage(int matrix[][7], int row)
{

  double W_ave;
  W_ave = (0.2 * matrix[row][1]) + (0.3 * matrix[row][2]) + (0.3 * matrix[row][3]) + (0.2 * matrix[row][4]);

  matrix[row][6] = W_ave;

  return;
}


/* This function prints a matrix with 7 collums*/
void printMatrix7(int matrix[][7], int N_ROWS, int N_COLUMNS)
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
