///MUHAMMAD DAFFA ABIYYU RAHMAN
///2916100010
///TMJ KELAS A

#include <stdio.h>
#include <stdlib.h>

///FUNCTIONS
int Check(int op);
void AddCount();
void SubCount();
void MultiCount();
void InsertMatrix();

///GLOBALS
int mat1s[2], mat2s[2], mat3s[2];
float mat1[999][999], mat2[999][999], mat3[999][999];

///PROGRAM
int main()
{
    int state;
    char filter, opr;

    printf("Matrix 1 Size : ");scanf("%d%c%d",&mat1s[0], &filter, &mat1s[1]);
    printf("Matrix 2 Size : ");scanf("%d%c%d",&mat2s[0], &filter, &mat2s[1]);
    printf("Operator : ");scanf("%s", &opr);

    switch(opr){
        case '+' : state=Check(1);break;
        case '-' : state=Check(2);break;
        case 'x' : state=Check(3);break;
        default  : printf("Invalid Operator!");state=0;break;
    }

    if (state==0){
        printf("PRESS ANY KEY TO RESET PROGRAM");getch();
        system("cls");
        main();
    }

    InsertMatrix();

    printf("\n\nAfter some calculations...\n\n");
    switch(opr){
        case '+' : AddCount();break;
        case '-' : SubCount();break;
        case 'x' : MultiCount();break;
    }

    return 0;
}

int Check(int op){
     int i, state=1;

     if (mat1s[0]<1 || mat1s[1]<1 || mat2s[0]<1 || mat2s[0]<1){
        printf("\nWhat Matrix is this? Matrix must have positive values above zero!\n");
        state=0;
     }

     if (op!=3){
        for (i=0;i<2;i++){
            if (mat1s[i] != mat2s[i]){
                printf("\nMatrix Size must be equal for addition and subtraction in both row and columns!\n");
                state=0;
                break;
            }else{
                mat3s[i] = mat1s[i];
            }
        }
     }else{
        if (mat1s[1] != mat2s[0]){
            printf("\nColumn of Matrix 1 must be equal to Row of Matrix 2\n");
            state=0;
        }else{
            mat3s[0] = mat1s[0];
            mat3s[1] = mat2s[1];
            printf("Size of resultant Matrix : %d x %d\n\n", mat3s[0], mat3s[1]);
        }
     }
     return state;
}

void AddCount(){
    int i, j;
    for (i=0;i<mat3s[0];i++){
        for (j=0;j<mat3s[1];j++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
            printf("%.3f ", mat3[i][j]);
        }
        printf("\n");
    }
}

void SubCount(){
    int i, j;
    for (i=0;i<mat3s[0];i++){
        for (j=0;j<mat3s[1];j++){
            mat3[i][j] = mat1[i][j] - mat2[i][j];
            printf("%.3f ", mat3[i][j]);
        }
        printf("\n");
    }
}

void MultiCount(){
    int i, j, k;
    for (i=0;i<mat3s[0];i++){
        for (j=0;j<mat3s[1];j++){
            mat3[i][j]=0;
        }
    }

    for (i=0;i<mat3s[0];i++){
        for (j=0;j<mat3s[1];j++){
            for (k=0;k<mat1s[1];k++){
                mat3[i][j] = mat3[i][j] + (mat1[i][k]*mat2[k][j]);
            }
            printf("%.3f ", mat3[i][j]);
        }
        printf("\n");
    }
}

void InsertMatrix(){
    int i, j;
    for (i=0;i<mat1s[0];i++){
        for (j=0;j<mat1s[1];j++){
            printf("Insert Value of Matrix Element %d %d : ", i+1, j+1);
            scanf("%f", &mat1[i][j]);
        }
        printf("\n");
    }
    printf ("Form of Matrix 1 is : \n");
    for (i=0;i<mat1s[0];i++){
        for (j=0;j<mat1s[1];j++){
            printf("%.3f ", mat1[i][j]);
        }
        printf("\n");
    }

    for (i=0;i<mat2s[0];i++){
        for (j=0;j<mat2s[1];j++){
            printf("Insert Value of Matrix Element %d %d : ", i+1, j+1);
            scanf("%f", &mat2[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf ("Form of Matrix 2 is : \n");
    for (i=0;i<mat2s[0];i++){
        for (j=0;j<mat2s[1];j++){
            printf("%.3f ", mat2[i][j]);
        }
        printf("\n");
    }
}
