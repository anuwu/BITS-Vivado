#include <iostream>
#include <fstream>
using namespace std ;

int ReverseInt (int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1=i&255;
    ch2=(i>>8)&255;
    ch3=(i>>16)&255;
    ch4=(i>>24)&255;
    return((int)ch1<<24)+((int)ch2<<16)+((int)ch3<<8)+ch4;
}

int main ()
{
	FILE *fp ;
	char buf[5] ;
	int x ;
	unsigned char pix ;

	ifstream myFile ("Train\\train_data", ios::in | ios::binary) ;

	if (!myFile)
	{
		perror ("Error in reading input file\n") ;
		exit (1) ;
	}

	myFile.read ((char *)&x, sizeof(int)) ;
	x = ReverseInt (x) ;
	cout << "Magic number = " << x << "\n" ;

	myFile.read ((char *)&x, sizeof(int)) ;
	x = ReverseInt (x) ;
	cout << "No items = " << x << "\n" ;

	myFile.read ((char *)&x, sizeof(int)) ;
	x = ReverseInt (x) ;
	cout << "No rows = " << x << "\n" ;

	myFile.read ((char *)&x, sizeof(int)) ;
	x = ReverseInt (x) ;
	cout << "No columns = " << x << "\n" ;

	for (int i = 0 ; i < 1000 ; i++)
	{
		myFile.read ((char *)&pix, sizeof(unsigned char)) ;
		x = (int)pix ;
		cout << "Pixel = " << x << "\n" ;
	}


	myFile.close () ;

	return 0 ;
}