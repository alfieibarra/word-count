#include <stdio.h>
#include <stdlib.h>

int totLineCount = 0;
int totWordCount = 0;
int totByteCount = 0;

int counter(char *filename)
{
	int lineCount = 0;
	int wordCount = 0;
	int byteCount = 0;
	FILE *ifile;
	char c;
	char prev = '\0';
	
	ifile = fopen(filename, "r");

	if(ifile)
	{
                while( (c=fgetc(ifile)) != EOF )
                {
                        if( c == '\n' )
                        {
                                lineCount++;
                        }
                        if( prev == '\0' || isspace(prev) )
                        {
                                wordCount++;
                        } 
                        byteCount++;
			prev = c;
                }
        }
        else
        {
                printf("Error opening file");
        }
	
	wordCount -= 1;
		
	totLineCount += lineCount;
	totWordCount += wordCount;
	totByteCount += byteCount;

	printf("%s:", filename);
        printf("Lines: %d ", lineCount);
        printf("Words: %d ", wordCount);
        printf("Chars: %d \n", byteCount);
        
	fclose(ifile);
}

int main(int argc, char *argv[])
{
	int i;
	
	for(i = 1; i < argc; ++i)
	{
		counter(argv[i]);
	}
	
	printf("Total Lines: %d \n", totLineCount);
	printf("Total Words: %d \n", totWordCount);
	printf("Total Chars: %d \n", totByteCount);
	
	return(0);
}
