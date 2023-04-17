#include<stdio.h>
#include<malloc.h>

void main(int argc,char **argv){
	char *in = argv[1];
	char *op = argv[2];
	char magic[3];
	int width,height,maxVal;
	
	FILE *fp = fopen(in,"rb");

	fscanf(fp,"%s\n",magic);
	fscanf(fp,"%d %d\n",&width,&height);
	fscanf(fp,"%d\n",&maxVal);

	unsigned char **data = malloc(height*sizeof(unsigned char **));
	for(int i = 0;i < height;i++){
		data[i] = malloc(width*sizeof(unsigned char));
		fread(data[i],width,1,fp);
	}
	
	unsigned char ** data2 = malloc(height*sizeof(unsigned char **));
	for(int i = 0;i < height;i++)
		data2[i] = malloc(width*sizeof(unsigned char));

	for(int i = 0;i < height;i++){
		for(int j = 0;j < width;j++){
			data2[i][j] = maxVal - data[i][j];
		}
	}
	fclose(fp);

	fp = fopen(op,"wb");
	fprintf(fp,"%s\n",magic);
	fprintf(fp,"%d %d\n",width,height);
	fprintf(fp,"%d\n",maxVal);

	for(int i = 0;i < height;i++)
		fwrite(data2[i],width*sizeof(unsigned char),1,fp);
	fclose(fp);
}
