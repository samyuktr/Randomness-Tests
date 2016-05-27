#include "hw7.h"
/*

Samyukta Satish Rao
University Of Southern California.

*/

char bin_str[2222220];
char bin_str2[2222220];
double pos_alpha5 = 1.9600;
double neg_alpha5 = -1.9600;

void x5(int len, char * filename)
{
	FILE * fp;
	if(filename==NULL)
		fp = stdin;
	else
		fp = fopen(filename, "rb");

		
	if(fp==NULL)
	{
		fprintf(stderr, "File %s does not exist.\n", filename );
		exit(0);
	}

 	int n;
    char * ch = calloc(1, 1);
    int filesize = 0;
    int ctr = 0;
    char * temp = calloc(8, 1);
    while(!(feof(fp)))
    {
      //  memset(temp, NULL, 8);
        temp[0] = '\0';

        ch[0]=(unsigned char)fgetc(fp);
        filesize++;
        if(filesize<257 )
        {
            if((filesize-1)%16==0 && filesize!=1)
                printf("\n");
            printf("%02x", (unsigned char)ch[0]);
        }
        if(feof(fp))
            break;

        temp = char_2_bin_old(ch[0]);
        strncat(&bin_str[ctr], temp, 8);
        ctr=ctr+8;

    }

    filesize--;
    printf("\n");

    n = filesize*8;
    printf("n = %d\n", filesize*8 );
    printf("d = %d\n", len );
   // int m = 1;
    int i, j;
    strncpy(bin_str2, bin_str, strlen(bin_str));
   // strcpy(bin_str, "1110001100010001010011101111001001001001");
    //strcpy(bin_str2, "1110001100010001010011101111001001001001");
    for(i=1;i<=len; i++)
    {
    	for(j=0;j<strlen(bin_str2)-i; j++)
    	{
    		bin_str2[j] = bin_str2[j+1];
    	}
    }
    int n1= 0;
    //printf("First: %s\n", bin_str );
    //printf("Changed: %s\n", bin_str2 );
   // bin_str // original
   // bin_str2 // changed 
    for(i=0;i<(strlen(bin_str2)-len);i++)
    {
    	if(((bin_str[i]-48)^(bin_str2[i]-48))==1)
    	{
    		n1++;
    	}
    
    	//printf("%d", (bin_str[i]-48)^(bin_str2[i]-48));
    	//getchar();
    }
    printf("A(d) = %d\n", n1 );
   double answer =  (2*( (n1-(n-len)/2.0) )) / sqrt(n-len);
   printf("x5 = %6f\n", answer);

    if((neg_alpha5< answer ) && (answer<pos_alpha5))
    	printf("pass/fail = pass\n");
  else
    	printf("pass/fail = fail\n");




}


