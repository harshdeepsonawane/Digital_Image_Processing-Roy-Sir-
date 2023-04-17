#include<stdio.h>
#include<malloc.h>

void main(int argc,char **argv){
	char *in = argv[1];
	char *op = argv[2];

	FILE *fp1 = fopen(in,"rb");
	char magic[3];
	int width,height;
	int maxVal;
	
	fscanf(fp1,"%s\n",magic);
	fscanf(fp1,"%d %d\n",&width,&height);
	fscanf(fp1,"%d\n",&maxVal);

	unsigned char** data = malloc(height*sizeof(unsigned char **));
	for(int i = 0;i < height;i++)
		data[i] = malloc(width*sizeof(unsigned char *));
	
	for(int i = 0;i < height;i++)
		fread(data[i],1,width*sizeof(unsigned char),fp1);

	fclose(fp1);

	FILE *fp2 = fopen(op,"wb");
	fprintf(fp2,"%s\n",magic);
	fprintf(fp2,"%d %d\n",height,width);
	fprintf(fp2,"%d\n",maxVal);
	
	unsigned char** data2 = malloc(width*sizeof(unsigned char **));
	for(int i = 0;i < width;i++)
		data2[i] = malloc(height*sizeof(unsigned char *));

	for(int i = 0;i < height;i++){
		for(int j = 0;j < width;j++){
				data2[j][height - i - 1] = data[i][j];
		}
	}

	for(int i = 0;i < width;i++)
		fwrite(data2[i],1,height*sizeof(unsigned char),fp2);
	fclose(fp2);
}
