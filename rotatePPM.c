#include<stdio.h>
#include<malloc.h>

typedef struct Pixel{
	unsigned char r,g,b;
}Pixel;

void main(int argc,char** argv){
	char *in = argv[1];
	char *op = argv[2];

	FILE *fp1 = fopen(in,"rb");
	char magic[3];
	int width,height;
	int maxVal;
	
	fscanf(fp1,"%s\n",magic);
	fscanf(fp1,"%d %d\n",&width,&height);
	fscanf(fp1,"%d\n",&maxVal);

	Pixel** data = malloc(height*sizeof(Pixel **));
	for(int i = 0;i < height;i++)
		data[i] = malloc(width*sizeof(Pixel *));
	
	for(int i = 0;i < height;i++)
		fread(data[i],1,width*sizeof(Pixel),fp1);

	fclose(fp1);

	FILE *fp2 = fopen(op,"wb");
	fprintf(fp2,"%s\n",magic);
	fprintf(fp2,"%d %d\n",height,width);
	fprintf(fp2,"%d\n",maxVal);
	
	Pixel** data2 = malloc(width*sizeof(Pixel **));
	for(int i = 0;i < width;i++)
		data2[i] = malloc(height*sizeof(Pixel *));

	for(int i = 0;i < height;i++){
		for(int j = 0;j < width;j++){
				data2[j][height - i - 1] = data[i][j];
		}
	}

	for(int i = 0;i < width;i++)
		fwrite(data2[i],1,height*sizeof(Pixel),fp2);
	fclose(fp2);
}
