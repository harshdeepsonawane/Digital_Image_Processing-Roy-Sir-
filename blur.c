#include <malloc.h>
#include <stdio.h>

void main(int argc,char** argv) {
  char *in = argv[1];
  char *op = argv[2];
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
    
    int k = 4;
    int num = 0;
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
            n++;
            data2[i][j] = sum/n;
            printf("%d pixels remaining\r",height*width - n);
        }
    }


 fclose(fp);

  fp = fopen(op, "wb");
  fprintf(fp, "%s\n", magic);
  fprintf(fp, "%d %d\n", width, height);
  fprintf(fp, "%d\n", maxVal);

  for (int i = 0; i < height; i++)
    fwrite(data2[i], width * sizeof(unsigned char), 1, fp);
  fclose(fp);
}
