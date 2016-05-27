#include "hw7.h"
/*
	Samyukta Satish Rao
	5924873657
	Hw7 - Randomness Tests
*/

void rc4(char * p,int len)
{
	int i=0;
	int j=0;
	int t=0; 
	int k=0;
	unsigned int key_str[256]={0};
	int count=0;
	unsigned char md5_buf[MD5_DIGEST_LENGTH];
	char *s=malloc(strlen(p)+3);


	// MD5 algorithm 

	for (i=0; i < 16; i++) 
	{
		sprintf(s, "%02d%s", i, p);
		MD5((unsigned char *)s, (unsigned int)(strlen(s)), (unsigned char *)md5_buf);
		
		for(j=0;j<MD5_DIGEST_LENGTH;j++)
		{
			key_str[count]=(unsigned int)md5_buf[j];
			count++;
		}

	}
	free(s);



	int state[256]={0}; // state array 

	for (i=0; i < 256; i++)  // initialise state array 
	{
		state[i] = i;
	}

	// rc4 init
	for (i=0, j=0;i < 256;i++,j=(j+1)%256) 
	{
		t = state[i];
		k+= key_str[j] + t;
		k=k%256;
		state[i] = state[k];
		state[k] = t;

	}

	int x = 0; 
	int y = 0;
	count=0;

	if(len==0) // print all 256 from state array
	{
		for(j=0;j<256;j++)
			{
				fprintf(stdout, "%c",(unsigned char)state[j]);
			}
	}
	else
	{
		while(len>0)
		{
			x=(x+1)%256;
			y = (y + state[x])%256;
			t = state[x];
			state[x] = state[y];
			state[y] = t;
			fprintf(stdout, "%c", (unsigned char) state[(state[x]+state[y])%256]);
			len--;
		}
		
	}

}
