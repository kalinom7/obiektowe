#include <iostream>
#include <cstdlib>


double **allocate(int rows, int columns) 
{
    double **matrix = (double**)malloc(rows * sizeof(double*)); 
    for (int a=0; a<rows;a++) 
    {
        *(matrix +a) =(double*)malloc(columns * sizeof(double)); 
    }
    return matrix;
}


void free(double **matrix, int rows, int columns) 
{
    for (int a=0;a<rows;a++) 
    {
        free(*(matrix +a));
    }
    free(matrix);
}


void copy(double **matrix2, double **matrix1, int rows, int columns) 
{
    for (int a=0;a<rows; a++) 
    {
        for (int b=0;b<columns;b++) {
            *(*(matrix2+a)+ b) = *(*(matrix1+a) + b);
        }
    }
}

void scan(double *matrix[], int rows, int columns) {
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			std::cin >> matrix[row][column];
		}
	}
}

void print(double *matrix[], int rows, int columns) {
	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			std::cout << matrix[row][column];
		}
		std::cout << std::endl;
	}
}


int main(int argc, char* argv[]) {
	int rows = std::atoi(argv[1]);
	int columns = std::atoi(argv[2]);
	
	double **matrix1 = allocate(rows, columns);
	scan(matrix1, rows, columns);
	
	double **matrix2 = allocate(rows, columns);
	copy(matrix2, matrix1, rows, columns);
	
	print(matrix2, rows, columns);
	free(matrix2, rows, columns);
	free(matrix1, rows, columns);
	return 0;
}