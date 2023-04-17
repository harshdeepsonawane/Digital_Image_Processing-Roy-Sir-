//c program that will take a pgm file and will scale it 3 times bigger

#include<stdio.h>
#include<malloc.h>

typedef struct Pixel{
	char r,g,b;
}Pixel;

void main(){
	char *in = "bird.ppm";
	char *op = "scaled_bird.ppm";

	int width,height,maxVal;
	char magic[3];

	FILE *fp1 = fopen(in,"rb");
	fscanf(fp1,"%s\n",&magic);
	fscanf(fp1,"%d %d\n",&width,&height);
	fscanf(fp1,"%d\n",&maxVal);

	Pixel **data = (Pixel **)malloc(height*sizeof(Pixel *));
	for(int i = 0;i < height;i++)
		data[i] = (Pixel *)malloc(width*sizeof(Pixel));


	for(int i = 0;i < height;i++)
		fread(data[i],1,width*sizeof(Pixel),fp1);	

	fclose(fp1);

	Pixel **scaledData = (Pixel **)malloc(height*3*sizeof(Pixel *));
	for(int i = 0;i < height*3;i++)
		scaledData[i] = (Pixel *)malloc(width*3*sizeof(Pixel));

	for(int i = 0;i < height*3;i++){
		for(int j = 0;j < width*3;j++){
				scaledData[i][j] = data[i/3][j/3];
		}
	}
	free(data);
	FILE *fp2 = fopen(op,"wb");
	fprintf(fp2,"%s\n",magic);
	fprintf(fp2,"%d %d\n",width*3,height*3);
	fprintf(fp2,"%d\n",maxVal);
	for(int i = 0;i <height*3;i++)
		fwrite(scaledData[i],width*sizeof(Pixel)*3,1,fp2);
	fclose(fp2);
}
