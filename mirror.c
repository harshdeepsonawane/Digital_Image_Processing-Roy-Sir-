#include<stdio.h>
#include<malloc.h>

typedef struct Pixel{
	unsigned char r,g,b;
}Pixel;

void main(){
	char *in = "bird.ppm";
	char *op = "mirror_bird.ppm";
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
	
	Pixel ** data2 = malloc(height*sizeof(Pixel **));
	for(int i = 0;i < height;i++)
		data2[i] = malloc(width*sizeof(Pixel *));

	for(int i = 0;i < height;i++)
		for(int j = 0;j < width;j++)
			data2[i][width - 1 - j] = data[i][j];
	fclose(fp);

	fp = fopen(op,"wb");
	fprintf(fp,"%s\n",magic);
	fprintf(fp,"%d %d\n",width,height);
	fprintf(fp,"%d\n",maxVal);

	for(int i = 0;i < height;i++)
		fwrite(data2[i],width*sizeof(Pixel),1,fp);
	fclose(fp);
}
