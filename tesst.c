#include <malloc.h>
#include <stdio.h>

void main(int argc,char** argv) {
    char *in = "threshold_dipText2.pgm";
    char magic[3];
    int width, height, maxVal;

    FILE *fp = fopen(in, "rb");

    fscanf(fp, "%s\n", magic);
    fscanf(fp, "%d %d\n", &width, &height);
    fscanf(fp, "%d\n", &maxVal);

    unsigned char **data = malloc(height * sizeof(unsigned char **));
    for (int i = 0; i < height; i++) {
        data[i] = malloc(width * sizeof(unsigned char));
        fread(data[i], width, 1, fp);
    }


    unsigned char **data2 = malloc(height*sizeof(unsigned char **));
    for(int i = 0;i < height;i++)
        data2[i] = malloc(width*sizeof(unsigned char *));


    int textLine = 0;
    int x = 0;
    int y = 0;
    int sum = 0;
    for (int i = 0; i < height; i++) {
        sum = 0;
        for(int j = 0;j < width;j++){
            sum += data[i][j];
            data2[x][y++] = data[i][j];
        }
        x++;
        float avg = sum/width;
        printf("%f avg\r",avg);
        if(avg < 200){
            if(textLine){
                FILE *fp2 = fopen("nice.pgm","wb");
                fprintf(fp2, "%s\n", magic);
                fprintf(fp2, "%d %d\n", x, y);
                fprintf(fp2, "%d\n", maxVal);

                for (int i = 0; i < x; i++)
                    fwrite(data2[i], y * sizeof(unsigned char), 1, fp2);
                fclose(fp2);

                for(int i = 0;i < x;i++)
                    for(int j = 0;j < y;j++)
                        data2[i][j] = 255;
                x = 0; y = 0;
            }
            textLine = 0;
        }
        else{
            textLine = 1;
        }
    }
    fclose(fp);
}
