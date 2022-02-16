#include<stdio.h>
#define srow 50
#define mrow 20
#define mcolumn 20
void add(int sparse1[100][3],int sparse2[100][3],int p,int s);

//Begin of main
int main()
{
	int mat1[mrow][mcolumn],sparse1[srow][3],mat2[mrow][mcolumn],sparse2[srow][3];
	int i,j,nzero=0,mzero=0,mr,mc,nr,nc,sr,s,pr,p,a[100][3],b[100][3];

	//taking inputprintf("\n First Matrix \n");
	printf("Enter number of rows : ");
	scanf("%d",&mr);
	printf("Enter number of columns : ");
	scanf("%d",&mc);

	for(i=0;i<mr;i++)
		for(j=0;j<mc;j++)
		{
			//taking inputs of rows and columns
			printf("Enter element for row1 %d,column1 %d : ",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}

	//printing entered matrix
	printf("Entered matrix is : \n");
	for(i=0;i<mr;i++)
	{
		for(j=0;j<mc;j++)
		{
			printf("%6d",mat1[i][j]);
			if(mat1[i][j]!=0)
				nzero++;
		}
	printf("\n");
	}

	sr=nzero+1;
	sparse1[0][0]=mr;
	sparse1[0][1]=mc;
	sparse1[0][2]=nzero;
	s=1;

	for(i=0;i<mr;i++)
  {
		for(j=0;j<mc;j++)
		{
			if(mat1[i][j]!=0)
			{
				sparse1[s][0]=i+1;
				sparse1[s][1]=j+1;
				sparse1[s][2]=mat1 [i][j];
				s++;
			}
    }
	}

	//printing first sparse matrix
	printf("Sparse matrix 1 is :\n");
	for(i=0;i<sr;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",sparse1[i][j]);
		printf("\n");
  }
  printf("\n Second Matrix \n");
  printf("Enter number of rows : ");
	scanf("%d",&nr);
	printf("Enter number of columns : ");
	scanf("%d",&nc);

	for(i=0;i<nr;i++)
		for(j=0;j<nc;j++)
		{
			//taking inputs of rows and columns
			printf("Enter element for row2 %d,column2 %d : ",i+1,j+1);
			scanf("%d",&mat2[i][j]);
		}

	//printing entered matrix
	printf("Entered matrix is : \n");
	for(i=0;i<nr;i++)
	{
		for(j=0;j<nc;j++)
		{
			printf("%6d",mat2[i][j]);
			if(mat2[i][j]!=0)
				mzero++;
		}
	printf("\n");
  }
  pr=mzero+1;
	sparse2[0][0]=nr;
	sparse2[0][1]=nc;
	sparse2[0][2]=mzero;
	p=1;

	for(i=0;i<nr;i++)
  {
		for(j=0;j<nc;j++)
		{
			if(mat2[i][j]!=0)
			{
				sparse2[p][0]=i+1;
				sparse2[p][1]=j+1;
				sparse2[p][2]=mat2 [i][j];
				p++;
			}
	  }
  }

	//printing second sparse matrix
	printf("Sparse matrix 2 is :\n");
	for(i=0;i<pr;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",sparse2[i][j]);
		printf("\n");
	}
  add(sparse1,sparse2,s,p);
  return 0;
}
//End of main

void add(int sparse1[100][3],int sparse2[100][3],int s,int p)
{
  int c[10][3],i=0,j=0,x=0;
  if((sparse1[0][0]==sparse2[0][0])&&(sparse1[0][1]==sparse2[0][1]))
  {
    while(i<s && j<p)
    {
      if((sparse1[i][0]==sparse2[j][0])&&(sparse1[i][1]==sparse2[i][1]))
       {
          c[x][0]=sparse1[i][0];
          c[x][1]=sparse1[i][1];
          c[x][2]=sparse1[i][2]+sparse2[j][2];
          i++;
          j++;
          x++;
       }
       else if(sparse1[i][0]==sparse2[j][0])
         {
           if(sparse1[i][1]<sparse2[j][1])
           {
             c[x][0]=sparse1[i][0];
             c[x][1]=sparse1[i][1];
             c[x][2]=sparse1[i][2];
             i++;
             x++;
           }
           else
           {
             c[x][0]=sparse2[j][0];
             c[x][1]=sparse2[j][1];
             c[x][2]=sparse2[j][2];
             j++;
             x++;  
           }
         }
      else
      {
        if(sparse1[i][0]<sparse2[j][0])
        {
          c[x][0]=sparse1[i][0];
          c[x][1]=sparse1[i][1];
          c[x][2]=sparse1[i][2];
          i++;
          x++;
        }
        else
        {
          c[x][0]=sparse2[j][0];
          c[x][1]=sparse2[j][1];
          c[x][2]=sparse2[j][2];
          j++;
          x++;
        }
      }
    }
    while(i<s)
    {
      c[x][0]=sparse1[i][0];
      c[x][1]=sparse1[i][1];
      c[x][2]=sparse1[i][2];
      i++;
      x++;
    }
    while(j<p)
    {
      c[x][0]=sparse2[j][0];
      c[x][1]=sparse2[j][1];
      c[x][2]=sparse2[j][2];
      j++;
      x++;
    }
         c[0][0]=sparse1[0][0];
         c[0][1]=sparse1[0][1];
         c[0][2]=x;
   printf("Sparse matrix after addition is :\n");

	for(i=0;i<x;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",c[i][j]);
		printf("\n");
	}
}
  else
  {
    printf("Addition not possible!");
  }
}