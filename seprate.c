#include<stdio.h>
#include<malloc.h>

typedef struct Pixel{
    unsigned char r,g,b;
}Pixel;

void main(int argc,char ** argv){
    char *in = argv[1];
    char magic[3];
    int width,height,maxVal;

    FILE *fp = fopen(in,"rb");

    fscanf(fp,"%s\n",magic);
    fscanf(fp,"%d %d\n",&width,&height);
    fscanf(fp,"%d\n",&maxVal);

    Pixel **data = malloc(height*sizeof(Pixel **));
    for(int i = 0;i < height;i++){
        data[i] = malloc(width*sizeof(Pixel *));
        fread(data[i],width*sizeof(Pixel),1,fp);
    }
    fclose(fp);

    unsigned char ** red = malloc(height*sizeof(unsigned char **));
    unsigned char ** green = malloc(height*sizeof(unsigned char **));
    unsigned char ** blue = malloc(height*sizeof(unsigned char **));

    for(int i = 0;i < height;i++)
        red[i] = malloc(width*sizeof(unsigned char*));

    for(int i = 0;i < height;i++)
        green[i] = malloc(width*sizeof(unsigned char*));

    for(int i = 0;i < height;i++)
        blue[i] = malloc(width*sizeof(unsigned char*));

    for(int i = 0;i < height;i++)
        for(int j = 0;j < width;j++)
            red[i][j] = data[i][j].r;

    for(int i = 0;i < height;i++)
        for(int j = 0;j < width;j++)
            green[i][j] = data[i][j].g;


    for(int i = 0;i < height;i++)
        for(int j = 0;j < width;j++)
            blue[i][j] = data[i][j].b;

    fp = fopen("red.pgm","wb");
    fprintf(fp,"P5\n");
    fprintf(fp,"%d %d\n",width,height);
    fprintf(fp,"%d\n",maxVal);

    for(int i = 0;i < height;i++)
        fwrite(red[i],width,1,fp);
    fclose(fp);

    fp = fopen("green.pgm","wb");
    fprintf(fp,"P5\n");
    fprintf(fp,"%d %d\n",width,height);
    fprintf(fp,"%d\n",maxVal);

    for(int i = 0;i < height;i++)
        fwrite(green[i],width,1,fp);
    fclose(fp);


    fp = fopen("blue.pgm","wb");
    fprintf(fp,"P5\n");
    fprintf(fp,"%d %d\n",width,height);
    fprintf(fp,"%d\n",maxVal);

    for(int i = 0;i < height;i++)
        fwrite(blue[i],width,1,fp);
    fclose(fp);

}
