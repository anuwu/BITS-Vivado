#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std ;


#define NO_TRAINING noTrain
#define HIDDEN_NEURONS 25

int noTrain, noRow, noCol, magicNo, featDim ;

int ReverseInt (int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1=i&255;
    ch2=(i>>8)&255;
    ch3=(i>>16)&255;
    ch4=(i>>24)&255;
    return((int)ch1<<24)+((int)ch2<<16)+((int)ch3<<8)+ch4;
}

double getRand ()
{
	return rand() / (double) RAND_MAX ;
}

void freeMatrix (void** mat, int rows)
{
	int i ;

	for (i = 0 ; i < rows ; i++)
		free (mat[i]) ;
	
	free(mat) ;
}

// Done only upto the hidden layer for now
void forward (int** trainData, double** theta1)
{
	int i, j, k ;
	double ele ;

	for (i = 0 ; i < HIDDEN_NEURONS ; i++)
	{
		for (j = 0 ; j < noTrain ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= featDim ; k++)
				ele += theta1[i][k] * trainData[j][k] ;

			printf ("%d ", ele) ;
		}

		printf ("\n-------------------\n") ;
	}
}



int main ()
{
	srand (time(0)) ;

	FILE *fp ;
	char buf[5] ;
	unsigned char pix ;

	ifstream myFile ("Train\\train_data", ios::in | ios::binary) ;

	if (!myFile)
	{
		perror ("Error in reading input file\n") ;
		exit (1) ;
	}

	myFile.read ((char *)&magicNo, sizeof(int)) ;
	magicNo = ReverseInt (magicNo) ;
	cout << "Magic number = " << magicNo << "\n" ;

	myFile.read ((char *)&noTrain, sizeof(int)) ;
	noTrain = ReverseInt (noTrain) ;
	cout << "No items = " << noTrain << "\n" ;

	myFile.read ((char *)&noRow, sizeof(int)) ;
	noRow = ReverseInt (noRow) ;
	cout << "No rows = " << noRow << "\n" ;

	myFile.read ((char *)&noCol, sizeof(int)) ;
	noCol = ReverseInt (noCol) ;
	cout << "No columns = " << noCol << "\n" ;

	featDim = noRow * noCol ;

	int** trainData = (int **) malloc (sizeof (int *) * NO_TRAINING) ;
	for (int i = 0 ; i < NO_TRAINING ; i++)
	{
		trainData[i] = (int *) malloc (sizeof (int) * (featDim + 1)) ;
		trainData[i][0] = 1 ;

		for (int j = 1 ; j <= featDim ; j++)
		{
			myFile.read ((char *)&pix, sizeof(unsigned char)) ;
			trainData[i][j] = (int) pix ;
		}
	}

	cout << "Done reading " << NO_TRAINING << " training examples\n" ;
	myFile.close () ;

	double epsRand = sqrt((double)6/(featDim + HIDDEN_NEURONS + 1)) ;
	double** theta1 = (double **) malloc (sizeof (double *) * HIDDEN_NEURONS) ;
	for (int i = 0 ; i < HIDDEN_NEURONS ; i++)
	{
		theta1[i] = (double *) malloc (sizeof (double) * (featDim + 1)) ;

		for (int j = 0 ; j <= featDim ; j++)
			theta1[i][j] = 2 * epsRand * (getRand () - 0.5) ;
	}

	cout << "Created theta1 of dimensions " << HIDDEN_NEURONS << " x " << featDim + 1 << "\n" ;

	forward (trainData, theta1) ;

	freeMatrix ((void **)trainData, NO_TRAINING) ;
	freeMatrix ((void **)theta1, HIDDEN_NEURONS) ;
	return 0 ;
}