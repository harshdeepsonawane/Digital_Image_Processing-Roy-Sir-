#include<stdio.h>
#include<malloc.h>

typedef struct Pixel{
	unsigned char r,g,b;
}Pixel;

void main(){
	char *in = "3_4.ppm";
	char *op = "my_3_4.pgm";
	char magic[3];
	int width,height,maxVal;
	
	FILE *fp = fopen(in,"rb");

	fscanf(fp,"%s\n",&magic);
	fscanf(fp,"%d %d\n",&width,&height);
	fscanf(fp,"%d\n",&maxVal);

	Pixel **data = malloc(height*sizeof(Pixel **));
	for(int i = 0;i < height;i++){
		data[i] = malloc(width*sizeof(Pixel *));
		fread(data[i],width*sizeof(Pixel),1,fp);
	}
	
	unsigned char ** data2 = malloc(height*sizeof(unsigned char **));
	for(int i = 0;i < height;i++)
		data2[i] = malloc(width*sizeof(unsigned char*));

	for(int i = 0;i < height;i++)
		for(int j = 0;j < width;j++)
			data2[i][j] = (data[i][j].r+data[i][j].g+data[i][j].b)/3;
	fclose(fp);

	fp = fopen(op,"wb");
	fprintf(fp,"P5\n");
	fprintf(fp,"%d %d\n",width,height);
	fprintf(fp,"%d\n",maxVal);

	for(int i = 0;i < height;i++)
		fwrite(data2[i],width,1,fp);
	fclose(fp);
}
