#include "hw7.h"
/*

Samyukta Satish Rao
University Of Southern California.

*/



/*

 	hw7 rc4 -p=pphrase [-l=len]
    hw7 x1 [file]
    hw7 x2 [file]
    hw7 x3 [file]
    hw7 x4 [file]
    hw7 x5 -d=dval [file]


*/


int main(int argc, char * argv[])
{

	char * input_pphrase;
	char * input;
	//char * in_len;
    char * filename;

	int len;
	if(argc==1)
    {
        fprintf(stderr, "Error: Information given is not enough.\n");
        exit(0);
    }
    else
    {
    	if(strcmp(argv[1], "rc4")==0)
    	{
    		if(argc<3)
    		{
    			fprintf(stderr, "Usage: hw7 rc4 -p=pphrase [-l=len]\n" );
    			exit(0);
    		}
    		else
    		{
    			if(argc==3)
    			{
    				if(argv[2][0]=='-' && argv[2][1]=='p')
    				{
    					input = strchr(argv[2], '=');
    					input++;
                        input_pphrase = input;
    					//printf("%s\n", input);
    				}
                    else
                    {
                        fprintf(stderr, "Incorrect command usage\n");
                        exit(0);
                    }
    				len = 0;
                    //printf("Len: %d\nPphrase: %s\n", len, input_pphrase );

    			}
    			else
    			{
    				if(argv[2][0]=='-' && argv[2][1]=='p')
    				{
    					input_pphrase = strchr(argv[2], '=');
    					input_pphrase++;
    				}

    				if(argv[3][0]=='-' && argv[3][1]=='l')
    				{
    					input = strchr(argv[3], '=');
    					input++;
    					len = atoi(input);
    				}
                    else
                    {
                        fprintf(stderr, "Incorrect command usage\n");
                        exit(0);
                    }
    			}
    			
    			rc4(input_pphrase, len);
    		}
    	}

    	else if(strcmp(argv[1], "x1")==0)
    	{
    		if(argc==3)
    		{
    			x1(argv[2]);
    		}
    		else if(argc==2)
    		{
    			x1(NULL);
    		}
    		else
    		{
    			fprintf(stderr, "Usage: hw7 x1 [file]\n");
    		}
    	}
    	else if(strcmp(argv[1], "x2")==0)
    	{
    		if(argc==3)
    		{
    			x2(argv[2]);
    		}
    		else if(argc==2)
    		{
    			x2(NULL);
    		}
    		else
    		{
    			fprintf(stderr, "Usage: hw7 x2 [file]\n");
    		}
    	}
    	else if(strcmp(argv[1], "x3")==0)
    	{
    		if(argc==3)
    		{
    			x3(argv[2]);
    		}
    		else if(argc==2)
    		{
    			x3(NULL);
    		}
    		else
    		{
    			fprintf(stderr, "Usage: hw7 x3 [file]\n");
    		}
    	}
        else if(strcmp(argv[1], "x5")==0)
        {
            if(argc==4)
            {
                if(argv[2][0]=='-' && argv[2][1]=='d')
                {
                    input = strchr(argv[2], '=');
                    input++;
                    len = atoi(input);
                }
                else
                    {
                        fprintf(stderr, "Incorrect command usage\n");
                        exit(0);
                    }

                filename = argv[3];
            }
            else if(argc==3)
            {
                if(argv[2][0]=='-' && argv[2][1]=='d')
                {
                    input = strchr(argv[2], '=');
                    input++;
                    len = atoi(input);
                }
                else
                    {
                        fprintf(stderr, "Incorrect command usage\n");
                        exit(0);
                    }
                filename = NULL;

            }
            else
            {
                fprintf(stderr, "Usage: hw7 x5 -d=dval [file]\n");
                exit(0);
            }
            x5(len, filename);
        }
        else
        {
            fprintf(stderr, "Incorrect comand. \n");
            exit(0);
        }
    }
    return 0;
}



