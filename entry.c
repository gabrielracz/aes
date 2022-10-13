#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aes.c"

int main(int argc, char* argv[]) {

	FILE* f = fopen("sample", "r");
	if(f == NULL){
		perror("fopen");
		return -1;
	}
	fseek(f, 0, SEEK_END);
	size_t filelen = ftell(f);
	fseek(f, 0, SEEK_SET);
	
	char* input = malloc(filelen + 1);
	input[filelen] = '\0';

	size_t bytes_read;
	/*bytes_read = fread(input, filelen, 1, f);*/

	unsigned char* cipher = malloc(1024);

	const char* sample = "Two One Nine Two";
	const char* key    = "Thats my Kung Fu";


	aes256_encrypt(cipher, sample, key, strlen(key));

	printf("%s\n", input);

	return 0;
}
