#include<stdio.h>
#include<stdlib.h>
int main()
{
	int cross[3][3],zero[3][3],g[3][3];
	int n,m,x,i,j,crossTurn=1,gameOver=0,k=1;
	for(i=0;i<3;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("\t%d",k);
			cross[i][j]=0;
			zero[i][j]=0;
			g[i][j]=k;
			k++;
		}printf("\n");
	}
	k=0;
	while(!gameOver)
	{
		if(crossTurn)
		{
			printf("\nEnter pos(X):\n");
			scanf("%d",&x);
			if(x < 1 || x > 9) {
				printf("\nInvalid Input\n");
			    continue;
		    }
			if(x%3 == 0)
			{
				m=x/3-1;
				n=2;
			}
			else
			{
				m=x/3;
				n=x%3-1;
			}
			if(g[m][n]==0)
			{
				printf("\nPosition filled\n");
				continue;
			}
			else
			{
				k += 1;
				g[m][n]=0;
				cross[m][n]=1;
				crossTurn=0;
			}
		}
		else
		{
					
			printf("\nEnter pos(0):\n");
			scanf("%d",&x);
			if(x < 1 || x > 9) {
				printf("\nInvalid Input\n");
			    continue;
		    }
			if(x%3 == 0)
			{
				m=x/3-1;
				n=2;
			}
			else
			{
				m=x/3;
				n=x%3-1;
			}
			if(g[m][n]==0)
			{
				printf("\nPosition failed\n");
				continue;
			}
			else
			{
				k += 1;
				g[m][n]=0;
				zero[m][n]=1;
				crossTurn=1;
			}
		
		}
		// now code for update
		system("@cls||clear");
		for(i=0;i<3;i++)
		{
			printf("\n");
			for(j=0;j<3;j++)
			{
				if(g[i][j]==0)
				{
					if(cross[i][j]==0)
					{
						printf("\t0");
					}
					else
					{
						printf("\tX");
					}
				}
				else
				{
					printf("\t%d",g[i][j]);
				}
			}
			printf("\n");
		}
		
		if((cross[0][0]==1 && cross[1][0]==1 && cross[2][0]==1) ||
		(cross[0][1]==1 && cross[1][1]==1 && cross[2][1]==1) ||
		(cross[0][2]==1 && cross[1][2]==1 && cross[2][2]==1) ||
		(cross[0][0]==1 && cross[0][1]==1 && cross[0][2]==1) ||
		(cross[1][0]==1 && cross[1][1]==1 && cross[1][2]==1) ||
		(cross[2][0]==1 && cross[2][1]==1 && cross[2][2]==1) ||
		(cross[0][0]==1 && cross[1][1]==1 && cross[2][2]==1) ||
		(cross[0][2]==1 && cross[1][1]==1 && cross[2][0]==1))
		{
			printf("\n\nX is Winner\n\n");
			gameOver = 1;
		}
		else if((zero[0][0]==1 && zero[1][0]==1 && zero[2][0]==1) ||
		(zero[0][1]==1 && zero[1][1]==1 && zero[2][1]==1) ||
		(zero[0][2]==1 && zero[1][2]==1 && zero[2][2]==1) ||
		(zero[0][0]==1 && zero[0][1]==1 && zero[0][2]==1) ||
		(zero[1][0]==1 && zero[1][1]==1 && zero[1][2]==1) ||
		(zero[2][0]==1 && zero[2][1]==1 && zero[2][2]==1) ||
		(zero[0][0]==1 && zero[1][1]==1 && zero[2][2]==1) ||
		(zero[0][2]==1 && zero[1][1]==1 && zero[2][0]==1))
		{
			printf("\n\n0 is Winner\n\n");
			gameOver = 1;
		}
		else
		{
			if(k == 9){
				gameOver = 1;
				printf("\n\nMatch Draw\n\n");
			}
		}
	}
}
