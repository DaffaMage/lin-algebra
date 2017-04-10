#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=3,y=3,iKanan=x, iBawah=y,i,j,pivot,pivot_col, pivot_offset=0,z;

    float iData[iBawah][iKanan];
    float iHasil[iBawah], faktor, temp;

    iData[0][0]=1;iData[0][1]=-2;iData[0][2]=1; ///Row 1
    iData[1][0]=0;iData[1][1]=2;iData[1][2]=-8; ///Row 2
    iData[2][0]=-4;iData[2][1]=5;iData[2][2]=9; ///Row 3

    iHasil[0]=0;iHasil[1]=8;iHasil[2]=-9; ///Result 1*/

    /*iData[0][0]=0;iData[0][1]=-3;iData[0][2]=-6;iData[0][3]=4; ///Row 1
    iData[1][0]=-1;iData[1][1]=-2;iData[1][2]=-1;iData[1][3]=3; ///Row 2
    iData[2][0]=-2;iData[2][1]=-3;iData[2][2]=0;iData[2][3]=3; ///Row 3
    iData[3][0]=1;iData[3][1]=4;iData[3][2]=5;iData[3][3]=-9; ///Row 4

    iHasil[0]=9;iHasil[1]=1;iHasil[2]=-1;iHasil[3]=-7; ///Result*/

    for (i=0;i<iBawah;i++)
    {
        for (j=0;j<iKanan+1;j++)
        {
            if (j!=iKanan)
                printf("%.2f",iData[i][j]);
            else
                printf("|\t%.2f",iHasil[i]);
            printf("\t");
        }
        printf("\n");
    }

    ///Eliminate Lower Triangle
    for(pivot=0;pivot<iBawah;pivot++)
    {
        printf("off = %d ", pivot_offset);
        pivot_col= pivot+pivot_offset;
        printf("val = %.2f ",iData[pivot][pivot_col]);
        if (iData[pivot][pivot_col]==0)
        ///Exchange Row
        {
            i=pivot;
            printf("i = %d ", i);
            temp=0;
            while (temp==0)
            {
                if (i<iBawah)
                {
                    i++; ///Moving Row
                    temp = iData[i][pivot_col];
                }
                if (i>=iBawah)
                {
                    pivot_col++;
                    pivot_offset++;
                    i=pivot;
                    temp = iData[i][pivot_col];
                }
                printf("val = %.2f ",temp);
            }
            printf("val = %.2f ",temp);
            printf("i = %d ", i);

            for(j=0;j<iKanan;j++)
            {
                temp = iData[pivot][j];
                iData[pivot][j] = iData[i][j];
                iData[i][j] = temp;
            }

            temp = iHasil[pivot];
            iHasil[pivot] = iHasil[i];
            iHasil[i] = temp;
        }

        ///Set to 1 for Pivot
        printf("pivot = %.2f ",iData[pivot][pivot_col]);
        faktor=1/iData[pivot][pivot_col];
        for (j=0;j<iBawah;j++)
        {
            iData[pivot][j]= faktor*iData[pivot][j];
        }
        iHasil[pivot]=faktor*iHasil[pivot];

        ///Eliminate
        for(i = pivot+1;i<iBawah;i++)
        {
            faktor=iData[i][pivot_col];
            for (j=0;j<iKanan;j++)
            {
                iData[i][j] -= faktor*iData[pivot][j];
            }
            iHasil[i] -= faktor*iHasil[pivot];
        }

        printf("\n");

        ///Output
        for (i=0;i<iBawah;i++)
        {
            for (j=0;j<iKanan+1;j++)
            {
                if (j!=iKanan)
                    printf("%.2f",iData[i][j]);
                else
                    printf("|\t%.2f",iHasil[i]);
                printf("\t");
            }
            printf("\n");
        }
    }

    ///Eliminate Upper Triangle
    for(pivot=iBawah-1;pivot>0;pivot--)
    {

        pivot_col = pivot;
        for (j=0;j<iKanan;j++)
        {
            if(iData[pivot][j]==1)
            {
                pivot_col = j;
                break;
            }
        }
        printf("pivot col : %d ", pivot_col);

        for(i = pivot-1;i>=0;i--)
        {
            faktor=iData[i][pivot_col];

            for (j=0;j<iKanan;j++)
            {
                iData[i][j] -= faktor*iData[pivot][j];
            }
            iHasil[i] -= faktor*iHasil[pivot];
        }

        ///Output
        printf("\n");
        for (i=0;i<iBawah;i++)
        {
            for (j=0;j<iKanan+1;j++)
            {
                if (j!=iKanan)
                    printf("%.2f",iData[i][j]);
                else
                    printf("|\t%.2f",iHasil[i]);
                printf("\t");
            }
            printf("\n");
        }
    }

    printf("\n");
    for (i=0;i<iBawah;i++)
    {
        for (j=0;j<iKanan+1;j++)
        {
            if (j!=iKanan)
                printf("%.2f",iData[i][j]);
            else
                printf("|\t%.2f",iHasil[i]);
            printf("\t");
        }
        printf("\n");
    }

    for (i=0;i<iBawah;i++)
    {
        z=0;
        temp=0;
        for (j=0;j<iKanan;j++)
        {
            temp += iData[i][j];
        }
        if (temp==0)
        {
            if (iHasil[i]!=0)
                z=1;
        }
        if (z==0)
            printf("equation %d is consistent\n", i+1);
        else
            printf("equation %d is not consistent\n", i+1);
    }

    z=0;
    for(i=0;i<iBawah;i++)
    {
        if (iData[i][i]==0)
        {
            z=1;
            break;
        }
    }

    if (z==0)
        printf("Solution is unique\n");
    else
        printf("Solution is not unique\n");

    return 0;
}
