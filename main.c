#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>

void helpme()
{
    printf("\n|HELP|MENU|");
    printf("\t-h : display help menu\n");
    printf("\t-i <filename> : select input filename. defaults to input.dat\n");
    printf("\t-o <filename> : select output filename. defaults to output.dat\n");
    printf("\t-t <time> : specify maximum runtime duration. defaults to 10 seconds\n");
}

int main(int argc, char *argv[])
{
    int ch;
    int duration;
    int tdefault = 10;
    char* ifilename = NULL;
    char* ofilename = NULL;
    
    while( (ch = getopt(argc,argv,"hi:o:t:")) != -1 )
    {
        switch(ch)
        {
            case 'h':
                helpme();
                return 0;
            case 'i':
                ifilename = optarg;
                if(ifilename == NULL)
                {
                    ifilename = "input.dat";
                }
                break;
            case 'o':
                ofilename = optarg;
                if(ofilename == NULL)
                {
                    ofilename = "output.dat";
                }
                break;
            case 't':
                tm = atoi(optarg);
                if(tm > 0)
                {
                    tdefault = duration;
                }
                break;
            /* if getopt() finds      
               an option charact
               er in argv that w
               as not included i
               n optstring, or i
               f it detects a mi
               ssing option argu
               ment, it returns
               '?' and sets the 
               external variable
               optopt to the act
               ual option char*/
            case '?': 
                printf("logParse: missing or invalid argument\n");
                return;
        }
    }

    printf("\nlogParse: input file: %s\nlogParse: output file: %s", ifilename, ofilename);
    FILE* ifile = fopen(ifilename, "r");
    FILE* ofile = fopen(ofilename, "w");

    if(ifile == NULL)
    {
        perror("logParse: error");
        exit(EXIT_FAILURE);
    }

    if(ofile == NULL)
    {
        perror("logParse: error");
        exit(EXIT_FAILURE);
    }

    fclose(ofile);
    return 0;
}