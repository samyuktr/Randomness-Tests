#include "hw7.h"


/*

Samyukta Satish Rao
University Of Southern California.

*/

// x2 functionality
void x2(char * filename)
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


       int i=0, count=0, n1=0, n0=0, n00=0, n01=0, n10=0, n11=0, bit=0;
       unsigned char ch=' ';
       int temp[8]={0};
       int prev_bit=8;
       while(!feof(fp))
       {

            ch=(unsigned char)fgetc(fp);
            if(feof(fp))
            {
                  break;
            }
            if(count<256) // printing hexdump of forst 256 characters 
            {
                fprintf(stdout, "%02x",(unsigned char)ch);
                if((count+1)%16==0)
                fprintf(stdout, "\n");
            }
            count++;
                
            for(i=0;i<8;++i)
            {
                bit=((ch>>i)&1);
                if(bit==0)
                {
                    n0++;
                }
                else
                {
                    n1++;
                }
                temp[7-i]=bit;  
            }
                
            if(prev_bit==0)
            {
                if(temp[0]==0)
                {
                    n00++;
                }
                else
                {
                    n01++;
                }
            }
                
            else if(prev_bit!=8)
            {
                if(temp[0]==0)
                {
                    n10++;
                }
                else
                {
                    n11++;
                }
            }     
              
            for(i=0;i<7;++i)
            {
            	if(temp[i]==0)
                {
                  	if(temp[i+1]==0)
                  		n00++;
                    else
	                    n01++;
                }
                else
                {
                    if(temp[i+1]==0)
                        n10++;
                    else
                        n11++;
                }
            }
             
            prev_bit=temp[7]; // store last bit from previous byte


                
                
        }

        int n=n0+n1;
        double x2=((pow(n00,2)+pow(n01,2)+pow(n10,2)+pow(n11,2))*4/(double)(n-1)) - ((pow(n1,2)+pow(n0,2))*2/(double)n) +1;
        

        double alpha2=5.9915;
        fprintf(stdout,"n = %d\nn0 = %d\nn1 = %d\nn00 = %d\nn01 = %d\nn10 = %d\nn11 = %d\nx2 = %6f\n",n,n0,n1,n00,n01,n10,n11,x2);
        if(x2<alpha2)
          fprintf(stdout, "pass/fail = pass\n");
        else
          fprintf(stdout, "pass/fail = fail\n");

}
