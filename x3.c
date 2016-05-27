#include "hw7.h"
/*

Samyukta Satish Rao
University Of Southern California.

*/


char bin_str[2222220];
int alpha3 = 0;;
int m_print = 0;

int char_2_dec(char * binstring) // converting binary string to decimal. 
{
  
    int i=0;
    int sum = 0;
    int m = strlen(binstring);

  for(i=0;i<strlen(binstring);i++)
  {
    int num = (int) binstring[i] - 48;
    sum = sum + (pow(2, m-i-1)*num);
  }


  return sum;
}

void char_2_bin(int input) // converting decimal to binary. 
{
	
    int i = 0;
    int bit = 0;

    for(i=m_print-1; i>=0; i--)
    {
        bit = (input>>i)&1;
        printf("%d", bit);
    }
}

char * char_2_bin_old(char input) // char to binary string. 
{
    
    int i = 0;
    int bit = 0;
    char * output = calloc(256, 1);

    for(i=0;i<8;++i)
    {
        bit=((input>>i)&1);
        output[7-i]=bit + 48;  
    }
                

    return output;
}


void x3(char * filename)
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
       // memset(temp, NULL, 8);
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

    n = filesize*8;
    int m = 1;

    while(floor(n/m)>=5*pow(2, m))
    {
    	m++;
    }
    m = m-1;
    int i = 0;
    int k = floor(n/m);
     m_print = m;


     switch(m) // setting m value. 
    {
        case 1: alpha3 =  3.8415; break;
        case 2: alpha3 = 7.8147 ; break;
        case 3: alpha3 =  14.0671; break;
        case 4: alpha3 = 24.9958; break;
        case 5: alpha3 =  44.9853; break;
        case 6: alpha3 =  82.5287; break;
        case 7: alpha3 = 154.3015 ; break;
        case 8: alpha3 = 293.2478; break;
        case 9: alpha3 = 564.6961; break;
        case 10: alpha3 = 1098.5208; break;
        

    }

     int loop_limit = (filesize*8) - ((filesize*8)%m);
   


    char * temp_cpy = calloc(m, 1);
    
    //filesize = 5;
    int ctr_array_size = pow(2, m);
    int ctr_array[ctr_array_size];

    // initialise to zero;
    for(i=0;i<ctr_array_size;i++)
        ctr_array[i] = 0;
    printf("\nn = %d\n", filesize*8 );
    printf("m = %d\n", m);
    printf("k = %d\n", k );

    for(i=0;i<filesize*8;i+=m)
    {
        memset(temp_cpy, 0, m);
        if(i<loop_limit) // ignore nits after the multiple
        {
        	strncpy(temp_cpy, &bin_str[i], m);
            int num = char_2_dec(temp_cpy);
            ctr_array[num] +=1;
            temp_cpy[0]='\0';
        }
        else
            break;

        

    }

  for(i=0;i<ctr_array_size;i++)
  {
        
        printf("n");
        char_2_bin(i);
        printf(" = %d\n", ctr_array[i]);

  }

  double sum_big = 0;
  for(i=0;i<ctr_array_size;i++)
  {
       sum_big += pow(ctr_array[i], 2);
  }

  double x3 = ((pow(2,m)*sum_big)/(double)k)-k ;
  printf("x3 = %6f\n", x3 );
  if(x3<alpha3)
    printf("pass/fail = pass\n");
  else
    printf("pass/fail = fail\n");






}
