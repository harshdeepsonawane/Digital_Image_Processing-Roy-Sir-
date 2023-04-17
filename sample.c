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


    int **temp = malloc(height*sizeof(int **));
    for(int i = 0;i < height;i++)
        temp[i] = malloc(width*sizeof(int *));
    
    k = 2;
    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            int sum = 0;
            int n = 0;
            for(int p = -k/2;p <= k/2;p++){
                for(int q = -k/2;q <= k/2;q++){
                    int x = i+p;
                    int y = j+q;
                    if(x >= 0 && x < height && y >= 0 && y < width){
                            sum += data[x][y];
                            n++;
                    }
                }
            }
            temp[i][j] = sum/n;
        }
    }


   for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            data[i][j] = temp[i][j];
        }
    }


    for(int i = 0;i < height;i++){
        for(int j = 0;j < width;j++){
            printf("%d\t",data[i][j]);
        }
        printf("\n");
    }
}
