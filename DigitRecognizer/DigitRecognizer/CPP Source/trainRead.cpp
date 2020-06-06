#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std ;


#define NO_TRAINING 64
#define HIDDEN_NEURONS 25
#define OUTPUT_SIZE 10

int noTrain, noRow, noCol, featDim ;

int ReverseInt (int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1=i&255;
    ch2=(i>>8)&255;
    ch3=(i>>16)&255;
    ch4=(i>>24)&255;
    return((int)ch1<<24)+((int)ch2<<16)+((int)ch3<<8)+ch4;
}

float getRand ()
{
	return rand() / (float) RAND_MAX ;
}

void freeMatrix (void** mat, int rows)
{
	int i ;

	for (i = 0 ; i < rows ; i++)
		free (mat[i]) ;
	
	free(mat) ;
}

float sigmoid (float in)
{
	return 1.0/(1 + exp(-in)) ;
}

// Done only upto the hidden layer for now
void forward (float** trainData, float** theta1, float **theta2, float **mid, float **output)
{
	int i, j, k ;
	float ele ;

	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		for (j = 0 ; j < HIDDEN_NEURONS ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= featDim ; k++)
				ele += trainData[i][k] * theta1[j][k] ;

			mid[i][j+1] = sigmoid (ele) ; 
		}
	}
	cout << "Created X1 of dimensions " << NO_TRAINING << " x " << HIDDEN_NEURONS + 1 << " (with bias term)\n" ;

	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= HIDDEN_NEURONS ; k++)
				ele += mid[i][k] * theta2[j][k] ;

			output[i][j] = sigmoid (ele) ;
		}
	}
	cout << "Created X2 of dimensions " << NO_TRAINING << " x " << OUTPUT_SIZE << " (no bias required)\n\n" ;
}

void printMat (float** mat, int row, int col)
{
	int i, j ;

	for (i = 0 ; i < row ; i++)
	{
		for (j = 0 ; j < col ; j++)
			printf ("%f ", mat[i][j]) ;
		
		printf ("\n") ;
	}
}


int main ()
{
	srand (time(0)) ;

	FILE *fp ;
	char buf[5] ;
	unsigned char pix ;
	int i, j, x ;

	ifstream dataFile ("Train\\train_data", ios::in | ios::binary) ;
	if (!dataFile)
	{
		perror ("Error in reading input data file\n") ;
		exit (1) ;
	}

	dataFile.read ((char *)&x, sizeof(int)) ;
	x = ReverseInt (x) ;
	cout << "Magic number = " << x << "\n" ;

	dataFile.read ((char *)&noTrain, sizeof(int)) ;
	noTrain = ReverseInt (noTrain) ;
	cout << "No items = " << noTrain << "\n" ;

	dataFile.read ((char *)&noRow, sizeof(int)) ;
	noRow = ReverseInt (noRow) ;
	cout << "No rows = " << noRow << "\n" ;

	dataFile.read ((char *)&noCol, sizeof(int)) ;
	noCol = ReverseInt (noCol) ;
	cout << "No columns = " << noCol << "\n" ;

	featDim = noRow * noCol ;

	float** trainData = (float **) malloc (sizeof (float *) * NO_TRAINING) ;
	for (int i = 0 ; i < NO_TRAINING ; i++)
	{
		trainData[i] = (float *) malloc (sizeof (float) * (featDim + 1)) ;
		trainData[i][0] = 1 ;

		for (int j = 1 ; j <= featDim ; j++)
		{
			dataFile.read ((char *)&pix, sizeof(unsigned char)) ;
			trainData[i][j] = (pix - 255.0/2) / 255 ;
		}
	}
	cout << "Loaded " << NO_TRAINING << " training examples\n\n" ;

	/* --------------------------------------------------------------------------------------------------------------------- */

	ifstream labelFile ("Train\\train_label", ios::in | ios::binary) ;
	if (!labelFile)
	{
		perror ("Error in reading input label file\n") ;
		exit (1) ;
	}

	labelFile.read ((char *)&x, sizeof(int)) ;
	x = ReverseInt (x) ;
	cout << "Magic number = " << x << "\n" ;

	labelFile.read ((char *)&noTrain, sizeof(int)) ;
	noTrain = ReverseInt (noTrain) ;
	cout << "No items = " << noTrain << "\n" ;

	float *labelData = (float *) malloc (sizeof (float) * NO_TRAINING) ;
	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		labelFile.read ((char*)&pix, sizeof(unsigned char)) ;
		labelData[i] = (float) pix ;
	}
	cout << "Loaded " << NO_TRAINING << " labels\n\n" ;

	/* --------------------------------------------------------------------------------------------------------------------- */

	cout << "Created X0 of dimensions " << NO_TRAINING << " x " << featDim + 1 << " (with bias term)\n" ;
	dataFile.close () ;

	float epsRand = sqrt((float)6/(featDim + 1 + HIDDEN_NEURONS)) ;
	float** theta1 = (float **) malloc (sizeof (float *) * HIDDEN_NEURONS) ;
	for (i = 0 ; i < HIDDEN_NEURONS ; i++)
	{
		theta1[i] = (float *) malloc (sizeof (float) * (featDim + 1)) ;

		for (j = 0 ; j <= featDim ; j++)
			theta1[i][j] = 2 * epsRand * (getRand () - 0.5) ;
	}
	cout << "Created theta1 of dimensions " << HIDDEN_NEURONS << " x " << featDim + 1 << "\n" ;

	float** theta2 = (float **) malloc (sizeof (float *) * OUTPUT_SIZE) ;
	for (i = 0 ; i < OUTPUT_SIZE ; i++)
	{
		theta2[i] = (float *) malloc (sizeof (float) * (HIDDEN_NEURONS + 1)) ;

		for (j = 0 ; j <= HIDDEN_NEURONS ; j++)
			theta2[i][j] = 2 * epsRand * (getRand () - 0.5) ;
	}
	cout << "Created theta2 of dimensions " << OUTPUT_SIZE << " x " << HIDDEN_NEURONS + 1 << "\n\n" ;

	/* --------------------------------------------------------------------------------------------------------------------- */

	float loss, **mid, **output ;
	mid = (float**) malloc (sizeof (float*) * NO_TRAINING) ;
	output = (float**) malloc (sizeof (float*) * NO_TRAINING) ;
	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		output[i] = (float*) malloc(sizeof (float) * OUTPUT_SIZE) ;
		mid[i] = (float*) malloc (sizeof (float) * (HIDDEN_NEURONS + 1)) ;
		mid[i][0] = 1 ;
	}

	loss = 0.0 ;
	cout << "Doing one forward pass\n" ;
	forward (trainData, theta1, theta2, mid, output) ;

	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		free (mid[i]) ;
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			if (j == labelData[i])
				loss += -(log (output[i][j])) ;
			else
				loss += -(log (1 - output[i][j])) ;
		}
	}

	free (mid) ;
	loss /= NO_TRAINING ;
	printf ("Total loss = %f\n", loss) ;

	/* --------------------------------------------------------------------------------------------------------------------- */

	cout << "Freeing training data\n" ;
	freeMatrix ((void **)trainData, NO_TRAINING) ;

	cout << "Freeing theta1\n" ;
	freeMatrix ((void **)theta1, HIDDEN_NEURONS) ;

	cout << "Freeing theta2\n" ;
	freeMatrix ((void**)theta2, OUTPUT_SIZE) ;

	cout << "Freeing output\n" ;
	freeMatrix ((void**)output, NO_TRAINING) ;
	return 0 ;
}