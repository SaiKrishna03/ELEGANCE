#include <iostream>
#include <cstdlib>

using namespace std;

struct graph
{
	int v;
	int e;
	int mat[20][20];
};

struct graph *t = (struct graph *) malloc(sizeof(struct graph));

struct graph *rev(struct graph *g)
{
	int i,j;
	t->v = g->v;
	t->e = g->e;
	for(i=0;i<g->v;i++)
		{
		for(j=0;j<g->v;j++)
			{
			if(g->mat[i][j] == 1 || i==j)
				t->mat[i][j]=0;
				
			else
				t->mat[i][j]=1;	
			}
		}
	return t;
}

bool ver(struct graph *g)
{
	int i,j,k;
	
	for(i=0;i<g->v;i++)
		{
		for(j=0;j<=i;j++)
			{
			if(g->mat[i][j]==1)
			{
				for(k=0;k<g->v;k++)
					{
					if(k!=i && k!=j)
					{
						if(g->mat[i][k]==1 && g->mat[j][k]==1)
						{
								return true;
                	                                        break;
						}
					}	
					}
			}
			}	
		}
	return false;
}


int main()
{
	struct graph *g,*t;
	int i,x,y,j;
	bool frnd,enemy;
	
	g = (struct graph *)malloc(sizeof(struct graph));
	t = (struct graph *)malloc(sizeof(struct graph));
	
	cout<<"enter the no of vertices: ";
	cin >> g->v;
	
	if(g->v > 6)
	{
		cout<<"\t  ramsey for group of 6 persons  .......\n\n";
		return 0;
	}	
	
	cout<<" enter the no of edges: ";
	cin >> g->e;
	
	for(i=1; i<= g->e; i++)
	{
		cout << "enter the edge "<<i<<": ";
		cin>>x>>y;
		
		g->mat[x][y] = 1;
		g->mat[y][x] = 1;		
	}	
	
	frnd = ver(g);
	
	if(frnd == true)
		cout<<"there exist three mutual friends\n";
		
	else
	{
		t = rev(g);
		enemy = ver(t);
	}		  
	
	if(enemy == true)
		cout<<"there exist three mutual enemies\n";	
}
