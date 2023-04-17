#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void main(int argc,char** argv) {
    char *in = argv[1];
    char *op = argv[2];

    char magic[3];
    char temp2[10];
    int width, height, maxVal, k = 0, numberOfBlackPixels = 0,lastIndex = 0;
    float normalize = 0;
    FILE *fp = fopen(in, "rb");

    fscanf(fp, "%s\n", magic);
    fscanf(fp, "%d %d\n", &width, &height);
    fscanf(fp, "%d\n", &maxVal);

    unsigned char **data = malloc(height * sizeof(unsigned char **));
    for (int i = 0; i < height; i++) {
        data[i] = malloc(width * sizeof(unsigned char));
        fread(data[i], width, 1, fp);
    }

    fclose(fp);
    char temp[10];
    strcpy(temp,op);
    fp = fopen(temp, "wb");

    fprintf(fp, "%s\n", magic);
    fprintf(fp, "%d %d\n", width, k);
    fprintf(fp, "%d\n", maxVal);


    unsigned char **data2 = malloc(height * sizeof(unsigned char **));
    for (int i = 0; i < height; i++)
        data2[i] = malloc(width * sizeof(unsigned char));

    for (int i = 0; i < height; i++) {
        numberOfBlackPixels = 0;
        for (int j = 0; j < width; j++)
            if(data[i][j] == 0)
                numberOfBlackPixels++;
        normalize = (float) numberOfBlackPixels/width;
        if(normalize > 0.14){
            for (int j = 0; j < width; j++)
                data2[k][j] = data[i][j];
            k++;
        }else{
            for(int l = lastIndex;l <= k;l++)
                fwrite(data2[l], width * sizeof(unsigned char), 1, fp);
            lastIndex = k;
            fclose(fp);
            strcpy(temp,op);
            sprintf(temp2,"%d",k);
            strcat(temp,temp2);
            fp = fopen(temp, "wb");
            fprintf(fp, "%s\n", magic);
            fprintf(fp, "%d %d\n", width, k);
            fprintf(fp, "%d\n", maxVal);
        }
    }

    for (int i = 0; i < k; i++)
        fwrite(data2[i], width * sizeof(unsigned char), 1, fp);
    fclose(fp);
}
