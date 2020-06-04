#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std ;


#define NO_TRAINING noTrain

int ReverseInt (int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1=i&255;
    ch2=(i>>8)&255;
    ch3=(i>>16)&255;
    ch4=(i>>24)&255;
    return((int)ch1<<24)+((int)ch2<<16)+((int)ch3<<8)+ch4;
}

void freeTrainData (int** data, int ex)
{
	int i ;

	for (i = 0 ; i < ex ; i++)
		free (data[i]) ;
	
	free(data) ;
}


int main ()
{
	FILE *fp ;
	char buf[5] ;
	int noTrain, noRow, noCol, magicNo ;
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

	int** trainData = (int **) malloc (sizeof (int *) * NO_TRAINING) ;

	for (int i = 0 ; i < NO_TRAINING ; i++)
	{
		trainData[i] = (int *) malloc (sizeof (int) * 28 * 28) ;
		for (int j = 0 ; j < 28*28 ; j++)
		{
			myFile.read ((char *)&pix, sizeof(unsigned char)) ;
			trainData[i][j] = (int) pix ;
		}
	}


	cout << "Done reading " << NO_TRAINING << " training examples\n" ;
	myFile.close () ;

	freeTrainData (trainData, NO_TRAINING) ;

	return 0 ;
}