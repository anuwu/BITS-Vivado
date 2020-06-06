#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std ;


#define NO_TRAINING 5000
#define ALPHA 0.01
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
				ele += trainData[i][k] * theta1[j][k] ;   // X * theta1^T

			mid[i][j+1] = sigmoid (ele) ; 
		}
	}
	//cout << "Created X1 of dimensions " << NO_TRAINING << " x " << HIDDEN_NEURONS + 1 << " (with bias term)\n" ;

	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= HIDDEN_NEURONS ; k++)
				ele += mid[i][k] * theta2[j][k] ;		// A * theta2^T

			output[i][j] = sigmoid (ele) ;
		}
	}
	//cout << "Created X2 of dimensions " << NO_TRAINING << " x " << OUTPUT_SIZE << " (no bias required)\n\n" ;
}

void backward (float **trainData, float** theta1, float** theta2, float** grad2, float **del2, float** mid, float** output)
{
	int i, j, k ;
	float ele = 0 ;


	// Grad2
	for (i = 0 ; i < OUTPUT_SIZE ; i++)
	{
		for (j = 0 ; j <= HIDDEN_NEURONS ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k < NO_TRAINING ; k++)
				ele += output[k][i] * mid[k][j] ;

			grad2[i][j] = ele/NO_TRAINING ;
		}
	}

	// Del2
	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		for (j = 0 ; j < HIDDEN_NEURONS ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k < OUTPUT_SIZE ; k++)
				ele += output[i][k] * theta2[k][j] ;

			del2[i][j] = ele * (j == 0 ? 0 : mid[i][j-1] * (1 - mid[i][j-1]))  ;
		}
	}

	// Grad1 and new theta1
	for (i = 0 ; i < HIDDEN_NEURONS ; i++)
	{
		for (j = 0 ; j <= featDim ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k < NO_TRAINING ; k++)
				ele += del2[k][i+1] * trainData[k][j] ;

			//grad1[i][j] = ele ;
			theta1[i][j] -= ALPHA * ele/NO_TRAINING ;
		}
	}

	// New theta2
	for (i = 0 ; i < OUTPUT_SIZE ; i++)
	{
		for (j = 0 ; j <= HIDDEN_NEURONS ; j++)
				theta2[i][j] -= ALPHA * grad2[i][j] ;
	}

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

float getLoss (float* labelData, float** output)
{
	int i, j ;
	float loss = 0 ;

	for (i = 0 ; i < NO_TRAINING ; i++)	
	{
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			if (j == labelData[i])
			{
				loss += -(log (output[i][j])) ;
				output[i][j] -= 1 ;
			}
			else
				loss += -(log (1 - output[i][j])) ;
		}
	}

	loss /= NO_TRAINING ;
	return loss ;
}

int main (int argc, char** argv)
{
	srand (time(0)) ;

	FILE *fp ;
	char buf[5] ;
	unsigned char pix ;
	int i, j, x, epochs ;

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

	float **theta1, **theta2, **grad2 ;
	float epsRand = sqrt((float)6/(featDim + 1 + HIDDEN_NEURONS)) ;

	theta1 = (float **) malloc (sizeof (float *) * HIDDEN_NEURONS) ;
	for (i = 0 ; i < HIDDEN_NEURONS ; i++)
	{
		theta1[i] = (float *) malloc (sizeof (float) * (featDim + 1)) ;
		for (j = 0 ; j <= featDim ; j++)
			theta1[i][j] = 2 * epsRand * (getRand () - 0.5) ;
	}
	cout << "Created theta1 of dimensions " << HIDDEN_NEURONS << " x " << featDim + 1 << "\n" ;

	theta2 = (float **) malloc (sizeof (float *) * OUTPUT_SIZE) ;
	grad2 = (float **) malloc (sizeof (float *) * OUTPUT_SIZE) ;
	for (i = 0 ; i < OUTPUT_SIZE ; i++)
	{
		theta2[i] = (float *) malloc (sizeof (float) * (HIDDEN_NEURONS + 1)) ;
		grad2[i] = (float *) malloc (sizeof (float) * (HIDDEN_NEURONS + 1)) ;

		for (j = 0 ; j <= HIDDEN_NEURONS ; j++)
			theta2[i][j] = 2 * epsRand * (getRand () - 0.5) ;
	}
	cout << "Created theta2 of dimensions " << OUTPUT_SIZE << " x " << HIDDEN_NEURONS + 1 << "\n\n" ;

	/* --------------------------------------------------------------------------------------------------------------------- */

	float loss, **mid, **output, **del2 ;
	mid = (float**) malloc (sizeof (float*) * NO_TRAINING) ;
	output = (float**) malloc (sizeof (float*) * NO_TRAINING) ;
	del2 = (float**) malloc (sizeof (float *) * NO_TRAINING) ;

	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		output[i] = (float*) malloc(sizeof (float) * OUTPUT_SIZE) ;
		del2[i] = (float *) malloc (sizeof (float) * (HIDDEN_NEURONS + 1)) ;

		mid[i] = (float*) malloc (sizeof (float) * (HIDDEN_NEURONS + 1)) ;
		mid[i][0] = 1 ;
	}

	for (epochs = 1 ; epochs <= atoi(argv[1]) ; epochs++)
	{
		forward (trainData, theta1, theta2, mid, output) ;
		loss = getLoss (labelData, output) ;
		//cout << "Epoch " << epochs << " : Loss = " << loss << "\n" ;
		printf ("Epoch %d : Loss = %f\n", epochs, loss) ;
		backward (trainData, theta1, theta2, grad2, del2, mid, output) ;
	}

	/* --------------------------------------------------------------------------------------------------------------------- */

	int correct = 0 ;
	float max, predLabel ;
	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		max = output[i][0] ;
		for (j = 1 ; j < OUTPUT_SIZE ; j++)
		{
			if (output[i][j] > max)
			{
				max = output[i][j] ;
				predLabel = j ;
			}
		}

		if (labelData[i] == predLabel)
			correct++ ;

		// cout << "\nTruth : " << labelData[i] << " Prediction : " << predLabel ;
	}

	cout << "Training accuracy = " << correct/NO_TRAINING * 100 ;

	/* --------------------------------------------------------------------------------------------------------------------- */

	cout << "\nFreeing training data\n" ;
	freeMatrix ((void **)trainData, NO_TRAINING) ;

	cout << "Freeing training labels\n" ;
	free (labelData) ;

	cout << "Freeing theta1\n" ;
	freeMatrix ((void **)theta1, HIDDEN_NEURONS) ;

	cout << "Freeing mid\n" ;
	freeMatrix ((void**)mid, NO_TRAINING) ;

	cout << "Freeing theta2\n" ;
	freeMatrix ((void**)theta2, OUTPUT_SIZE) ;

	cout << "Freeing grad2\n" ;
	freeMatrix ((void**)grad2, OUTPUT_SIZE) ;

	cout << "Freeding del2\n" ;
	freeMatrix ((void**)del2, NO_TRAINING) ;

	cout << "Freeing output\n" ;
	freeMatrix ((void**)output, NO_TRAINING) ;

	return 0 ;
}