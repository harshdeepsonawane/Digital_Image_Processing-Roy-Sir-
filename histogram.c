#include <malloc.h>
#include <stdio.h>

void main() {
	char *in = "gccText.pgm";
	char magic[3];
	int width, height, maxVal;
	int freq[256] = {0};
	FILE *fp = fopen(in, "rb");

	fscanf(fp, "%s\n", magic);
	fscanf(fp, "%d %d\n", &width, &height);
	fscanf(fp, "%d\n", &maxVal);

	unsigned char **data = malloc(height * sizeof(unsigned char **));
	for (int i = 0; i < height; i++) {
		data[i] = malloc(width * sizeof(unsigned char));
		fread(data[i], width, 1, fp);
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			freq[data[i][j]]++;
		}
	}

	for(int i = 0;i <= 255;i++)
		printf("%u %u\n",i,freq[i]);
}
