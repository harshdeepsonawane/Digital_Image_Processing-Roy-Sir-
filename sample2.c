#include<stdio.h>
#include<malloc.h>

void main(){
    int height = 10;
    int width = 12;
    int **data = malloc(height*sizeof(int **));
    for(int i = 0;i < height;i++)
        data[i] = malloc(width*sizeof(int *));

    int k =1;
    for(int i = 0;i < height;i++){
        for(int j= 0;j < width;j++){
            data[i][j] = k++;
        }
    }


    int **data2 = malloc(height*sizeof(int **));
    for(int i = 0;i < height;i++)
        data2[i] = malloc(width*sizeof(int *));

    int textLine = 0;
    int x= 0;
    int y = 0;
    for(int i = 0;i < height;i++){
        int sum = 0;
        for(int j = 0;j < width;j++){
            sum += data[i][j];
            data2[x++][y++] = data[i][j];
        }
        float avg = sum/width;

        if(avg < 0.5){
            if(textLine){
                FILE *fp2 = fopen("nice.pgm", "wb");
                fprintf(fp2, "%s\n", magic);
                fprintf(fp2, "%d %d\n", x, y);
                fprintf(fp2, "%d\n", maxVal);

                for (int i = 0; i < x; i++)
                    fwrite(data2[i], y * sizeof(unsigned char), 1, fp2);
                fclose(fp2);
                x = 0;
                y = 0;
                free(data2);
            }
            textLine = 0;
        }
        else{
            textLine = 1;
        }
    }


    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            data[i][j] = data2[i][j];
        }
    }


    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            printf("%d\t",data[i][j]);
        }
        printf("\n");
    }
}
