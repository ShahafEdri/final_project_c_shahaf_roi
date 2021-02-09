#include <stdio.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

int countLines (char* filename);
void letterFrequency (char* filename, int counts[]); 
void removeSpaces (char* infile, char* outfile);
void print_letter_frequency (int counts[]);

//void main() 
//{
//	int numLines, counts[26];
//	FILE *out;
//	out = fopen("input.txt", "w");
//
//	if  (out == NULL )
//	{
//		printf( "File could not be opened.\n" );
//		return;
//	}
//
//	fprintf (out, "It was a bright cold day in April, and the clocks were striking thirteen.\n");
//	fprintf (out, "Winston Smith, his chin nuzzled into his breast in an effort to escape the \n");
//	fprintf (out, "vile wind, slipped quickly through the glass doors of Victory Mansions, \n");
//	fprintf (out, "though not quickly enough to prevent a swirl of gritty dust from entering \n");
//	fprintf (out, "along with him. \n");
//	fclose(out);
//
//	numLines=countLines("input.txt"); 
//	printf("The number of lines is %d\n", numLines);
//	letterFrequency("input.txt", counts);
//	print_letter_frequency(counts);
//	removeSpaces("input.txt", "output.txt");
//}


int countLines (char* filename) 
{
	FILE *f = fopen(filename,"r");
	int c;
	int count = 0;
	if (!f)
		return -1;
	while ((c = fgetc(f)) != EOF) 
		if (c == '\n') 
			count++;
	fclose(f);
	return count;
}


void letterFrequency (char* filename, int counts[]) 
{
	int i,c;
	FILE *f = fopen(filename,"r"); 
	for (i = 0; i < 26; i++)
		counts[i] = 0;
	if (!f)
		return;
	while ((c = fgetc(f)) != EOF)
		if (isalpha(c))
			counts[tolower(c)-'a']++;
	fclose(f);
}


void removeSpaces (char* infile, char* outfile) 
{
	int c;
	FILE *f = fopen(infile,"r");
	FILE *g = fopen(outfile,"w");
	if (f && g)
		while ((c = fgetc(f)) != EOF) 
			if (c != ' ') 
				fputc(c,g);
	if (f)
		fclose(f);
	if (g)
		fclose(g);
}

void print_letter_frequency (int counts[])
{
	char c;
	for (c='a'; c<='z'; c++)
		printf ("%c - %d times\n", c, counts[c-'a']);
}







