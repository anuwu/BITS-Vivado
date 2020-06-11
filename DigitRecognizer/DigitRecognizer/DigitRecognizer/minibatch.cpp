/*
Run 1 - no_batch 200, alpha 0.01, lambda 0 --> Epoch 40, loss = 2.30
Run 2 - no_batch 200, alpha 0.01, lambda 1 --> Epoch 40, loss = 2.26
Run 3 - no_batch 200, alpha 0.05, lambda 10 --> Epoch 40, loss = 2.74
Run 4 - no_batch 200, alpha 0.01, lambda 10 --> Epoch 40, loss = 3.1
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
using namespace std ;

#define NO_TRAINING 60000
#define NO_BATCH 200
#define ALPHA 0.01
#define LAMBDA 1
#define HIDDEN_NEURONS 25
#define OUTPUT_SIZE 10



float sigmoid (float in)
{
	return 1.0/(1 + exp(-in)) ;
}

void forwardInf (float** allData, float** theta1, float **theta2, float **midInf, float **outputInf)
{
	int i, j, k ;
	float ele ;

	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		for (j = 0 ; j < HIDDEN_NEURONS ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= 784 ; k++)
				ele += allData[i][k] * theta1[j][k] ;   // X * theta1^T

			midInf[i][j+1] = sigmoid (ele) ; 
		}
	}
	//cout << "Created X1 of dimensions " << NO_TRAINING << " x " << HIDDEN_NEURONS + 1 << " (with bias term)\n" ;

	for (i = 0 ; i < NO_TRAINING ; i++)
	{
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= HIDDEN_NEURONS ; k++)
				ele += midInf[i][k] * theta2[j][k] ;		// A * theta2^T

			outputInf[i][j] = sigmoid (ele) ;
		}
	}
	//cout << "Created X2 of dimensions " << NO_TRAINING << " x " << OUTPUT_SIZE << " (no bias required)\n\n" ;
}


// Done only upto the hidden layer for now
void forward (float** batchData, float** theta1, float **theta2, float **mid, float **output)
{
	int i, j, k ;
	float ele ;

	for (i = 0 ; i < NO_BATCH ; i++)
	{
		for (j = 0 ; j < HIDDEN_NEURONS ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= 784 ; k++)
				ele += batchData[i][k] * theta1[j][k] ;   // X * theta1^T

			mid[i][j+1] = sigmoid (ele) ; 
		}
	}
	//cout << "Created X1 of dimensions " << NO_BATCH << " x " << HIDDEN_NEURONS + 1 << " (with bias term)\n" ;

	for (i = 0 ; i < NO_BATCH ; i++)
	{
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k <= HIDDEN_NEURONS ; k++)
				ele += mid[i][k] * theta2[j][k] ;		// A * theta2^T

			output[i][j] = sigmoid (ele) ;
		}
	}
	//cout << "Created X2 of dimensions " << NO_BATCH << " x " << OUTPUT_SIZE << " (no bias required)\n\n" ;
}

void backward (float **batchData, float** theta1, float** theta2, float** grad2, float **del2, float** mid, float** output)
{
	int i, j, k ;
	float ele = 0 ;


	// Grad2
	for (i = 0 ; i < OUTPUT_SIZE ; i++)
	{
		for (j = 0 ; j <= HIDDEN_NEURONS ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k < NO_BATCH ; k++)
				ele += output[k][i] * mid[k][j] ;

			grad2[i][j] = (ele + LAMBDA * (j == 0 ? 0 : theta2[i][j]))/NO_BATCH ;
		}
	}

	// Del2
	for (i = 0 ; i < NO_BATCH ; i++)
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
		for (j = 0 ; j <= 784 ; j++)
		{
			ele = 0 ;
			for (k = 0 ; k < NO_BATCH ; k++)
				ele += del2[k][i+1] * batchData[k][j] ;

			//grad1[i][j] = ele ;
			theta1[i][j] -= ALPHA * (ele + LAMBDA*(j == 0 ? 0 : theta1[i][j]))/NO_BATCH ;
		}
	}

	// New theta2
	for (i = 0 ; i < OUTPUT_SIZE ; i++)
	{
		for (j = 0 ; j <= HIDDEN_NEURONS ; j++)
				theta2[i][j] -= ALPHA * grad2[i][j] ;
	}

}

float getLossInf (float* allLabel, float** outputInf)
{
	int i, j ;
	float loss = 0 ;

	for (i = 0 ; i < NO_TRAINING ; i++)	
	{
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			if (j == allLabel[i])
				loss += -(log (outputInf[i][j])) ;
			else
				loss += -(log (1 - outputInf[i][j])) ;
		}
	}

	loss /= NO_TRAINING ;
	return loss ;
}

float getLoss (float* batchLabel, float** output)
{
	int i, j ;
	float loss = 0 ;

	for (i = 0 ; i < NO_BATCH ; i++)	
	{
		for (j = 0 ; j < OUTPUT_SIZE ; j++)
		{
			if (j == batchLabel[i])
			{
				loss += -(log (output[i][j])) ;
				output[i][j] -= 1 ;
			}
			else
				loss += -(log (1 - output[i][j])) ;
		}
	}

	loss /= NO_BATCH ;
	return loss ;
}
