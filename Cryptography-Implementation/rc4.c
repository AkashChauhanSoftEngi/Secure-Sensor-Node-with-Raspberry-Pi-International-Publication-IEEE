#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <time.h>
unsigned char *S;
unsigned char *T;
long keylen;

void init(unsigned char *key, long key_size)
{
	S = malloc(sizeof(unsigned char)*256);
	T = malloc(sizeof(unsigned char)*256);

	keylen = key_size;
	int i;
	for (i = 0; i < 256; i++)
	{
		S[i] = (unsigned char) i;
		T[i] = key[i % keylen];
	}
	int j = 0;
	for (i = 0; i < 256; i++)
	{
		j = (j + S[i] + T[i]) & 0xFF;
		S[i] ^= S[j];
		S[j] ^= S[i];
		S[i] ^= S[j];
	}
}

void crypt(unsigned char *inputText, long input_size, unsigned char *outputText, long output_size)
{
	int i = 0, j = 0, k, t, counter;
	for (counter = 0; counter < input_size; counter++)
	{
		i = (i + 1) & 0xFF;
		j = (j + S[i]) & 0xFF;
		S[i] ^= S[j];
		S[j] ^= S[i];
		S[i] ^= S[j];
		t = (S[i] + S[j]) & 0xFF;
		k = S[t];
		outputText[counter] = (unsigned char) (inputText[counter] ^ k);
	}
	
	free(S);
	free(T);
}

void process(char *key_path, char *input_path, char *output_path)
{
	long key_size, input_size, output_size;
	unsigned char *key_buffer, *input_buffer, *output_buffer = NULL;
	
	FILE *key = fopen(key_path, "rb");
	FILE *input = fopen(input_path, "rb");
	
	if(key == NULL || input == NULL)
	{
		printf("File I/O error occurred");
		return;
	}
	
	// read key file in a buffer
	fseek(key, 0, SEEK_END);
	key_size = ftell(key);
	fseek(key, 0, SEEK_SET);
	key_buffer = (unsigned char*)malloc(key_size+1);
	fread(key_buffer, key_size, 1, key);
	fclose(key);
		
	// read input file in a buffer
	fseek(input, 0, SEEK_END);
	input_size = ftell(input);
	fseek(input, 0, SEEK_SET);
	input_buffer = (unsigned char*)malloc(input_size+1);
	fread(input_buffer, input_size, 1, input);
	fclose(input);
		
	// prepare output buffer
	output_size = input_size;
	output_buffer = (unsigned char*)malloc(output_size+1);
	
	// initialize rc4
	init(key_buffer, key_size);
	
	// proceed with rc4 cryptography
	crypt(input_buffer, input_size, output_buffer, output_size);
		
	// store result in file
	FILE *output = fopen(output_path, "wb");
	fwrite(output_buffer, 1, output_size, output);
	fclose(output);
}

int main()
{	
	char *key_path ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\key.txt";//argv[1];
	char *input_path1 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\plain1.txt";//argv[2];
	char *input_path2 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\plain2.txt";//argv[2];
	char *input_path3 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\plain3.txt";//argv[2];
	char *cipher_path1 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\cipher1.txt";//argv[3];
	char *cipher_path2 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\cipher2.txt";//argv[3];
	char *cipher_path3 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\cipher3.txt";//argv[3];
	char *output_path1 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\output1.txt";//argv[3];
	char *output_path2 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\output2.txt";//argv[3];
	char *output_path3 ="C:\\Academics\\M.tech\\M.tech,3\\major project1\\rc4\\output3.txt";//argv[3];
	printf("\n\t-:RC4 ALGORITHM PERFORMANCE FOR DIFFERENT AMOUNTS OF DATA:-\n\n\n");
    //calculating time for 10 data entries
    clock_t start=clock();
	process(key_path, input_path1, cipher_path1);
	process(key_path, cipher_path1, output_path1);
	clock_t finish=clock();
    printf("\n Time taken by RC4 algorithm for 10 input data Entries= %fseconds\n",(float)(finish-start)/CLOCKS_PER_SEC);
    printf("\n\n");
    //calculating time for 100 data entries
    clock_t start2=clock();
	process(key_path, input_path2, cipher_path2);
	process(key_path, cipher_path2, output_path2);
	clock_t finish2=clock();
    printf(" Time taken by RC4 algorithm for 100 input data Entries= %fseconds\n",(float)(finish2-start2)/CLOCKS_PER_SEC);
    printf("\n\n");
    //calculating time for 1000 data entries
    clock_t start3=clock();
	process(key_path, input_path3, cipher_path3);
	process(key_path, cipher_path3, output_path3);
	clock_t finish3=clock();
    printf(" Time taken by RC4 algorithm for 1000 input data Entries= %fseconds\n",(float)(finish3-start3)/CLOCKS_PER_SEC);
    printf("\n");
    //store performance into the a file;
      FILE *performance2=fopen("C:\\Academics\\M.tech\\M.tech,3\\major project1\\graph_comparison\\RC4_performance.txt","wb");
      float t1,t2,t3;
      t1=(float)(finish-start)/CLOCKS_PER_SEC;
      t1=t1*1000;//convert data into milliseconds.
      t2=(float)(finish2-start2)/CLOCKS_PER_SEC;
      t2=t2*1000;//convert data into milliseconds.
      t3=(float)(finish3-start3)/CLOCKS_PER_SEC;
      t3=t3*1000;//convert data into milliseconds.
      //printf("\n%.3f MS",t1);
      fprintf(performance2, "%.4f", t1);
      fputc(',',performance2);
      //printf("\n%.3f MS",t2);
      fprintf(performance2, "%.4f", t2);
      fputc(',',performance2);
      //printf("\n%.3f MS",t3);
      fprintf(performance2, "%.4f", t3);
      //fputc(',',performance1);
      fclose(performance2);
      //end
      //getch();
      return 0;
}
