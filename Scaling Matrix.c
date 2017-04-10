#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrow,matcol,i,j;
    float scale;
    char c;

    printf("Insert Scale : ");scanf("%f", &scale);
    printf("\n");
    printf("Insert Matrix Size (RowXColumn) : ");scanf("%d%c%d", &matrow, &c, &matcol);
    printf("\n");

    float matrixval[matrow][matcol];

    for (i=0;i<matrow;i++)
        for (j=0;j<matcol;j++)
        {
            printf("Insert value of matrix at %d %d : ", i+1, j+1);scanf("%f",&matrixval[i][j]);
        }

    for (i=0;i<matrow;i++){
        for (j=0;j<matcol;j++)
            printf("%.3f ",matrixval[i][j]);
        printf("\n");
    }

    ///Scaling

    printf("After Scaling : \n");

    for (i=0;i<matrow;i++){
        for (j=0;j<matcol;j++){
            matrixval[i][j]*=scale;
            printf("%.3f ",matrixval[i][j]);
        }
        printf("\n");
    }
    return 0;
}
