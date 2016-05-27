#include "hw7.h"

/*
	Samyukta Satish Rao
	5924873657
	Hw7 - Randomness Tests

*/

double alpha1 = 3.8415; // Alpha for x1

/*Function to convert characters read to their decimal equivalent.*/

int * dec2bin(unsigned char c)
{
	unsigned long int decimalNumber,quotient;
	int * binaryNumber = calloc(100, 4);
	int i=1, k;
	for(k=0;k<10;k++)
		binaryNumber[k] = 0;

	decimalNumber = (unsigned int)c;
    quotient = decimalNumber;
    while(quotient!=0)
    {
         binaryNumber[i++]= quotient % 2;
         quotient = quotient / 2;
    }

    return binaryNumber;

}


/* x1 test */
void x1(char * filename)
{
	FILE * fp;
	int i, k;


	char * temp = calloc(256, 1);

	if(filename==NULL)
		fp = stdin;
	else	
		fp = fopen(filename, "rb");
	if(fp==NULL)
	{
		fprintf(stderr, "File %s does not exist.\n", filename );
		exit(0);
	}
	int c0=0, c1=0;
	int n;
	int print = 1;
	while((n = fread(temp, sizeof(char), 256, fp))!=0)
	{

		int * ret = calloc(8, 4);
		for(i=0;i<8;i++)
			ret[i] = 0;
		if(n==0)
			break;

		if(n==256)
		{
			if(print==1) // print only first 256
			{
				for(i=0;i<256;i++)
				{
					if(i%16==0 && i!=0)
						printf("\n");		
					printf("%02x", (unsigned char)temp[i]);
				}
				print=0;
			}
			for(i=0;i<256;i++)
			{
				
				ret = dec2bin((unsigned char)temp[i]);

				for(k=1;k<9;k++)
				{
					
					if(ret[k]==1)
					{
						c1+=1;
						
					}
					else if(ret[k]==0)
					{
						c0+=1;
						
					}
				}
			
				for(k=0;k<8;k++)
					ret[k] = 0;
				
			}
		
		}

		else
		{
			if(print==1) // length less than 256 condition. 
			{
				for(i=0;i<n;i++)
				{
					if(i%16==0)
						printf("\n");
					printf("%02x", (unsigned char)temp[i]);
				}
				print = 0;
			}

			for(i=0;i<n;i++)
			{
				
				ret = dec2bin((unsigned char)temp[i]);
				for(k=1;k<9;k++)
				{
					if(ret[k]==1)
						c1+=1;
					else if(ret[k]==0)
						c0+=1;
				}
				
			}
			printf("\nn = %d\nn0 = %d\nn1 = %d\n", c0+c1, c0, c1 );
		}
		
		temp[n] = '\0';


	}

	double numer = pow((c0-c1), 2) ;
	double denr = c0+c1;
	double x1 = numer/denr;
	printf("x1 = %f\n", numer/denr );
	if(x1<alpha1)
		printf("pass/fail = pass\n");
	else
		printf("pass/fail = fail\n");
}
