//c++ program to find shortest path from fixed vertex using bfs
#include<iostream>
#include<cstdlib>

using namespace std;


	



int q[100],front=-1,rear=-1,wt[100][100],a[100][100],vis[100],stack[100]; 
int wt2[100][100],a2[100][100];
int t[100][100];	//tree matrix stores the edges in tree
int count=0;	//count gives the no.of components in given graph
int parent[100];//parent array stores parents of each vertex

int delete1(); 
void add(int ); 
void bfs(int ,int ); 

int main() 
{ 
	int n,i,s,ch,j; 

	cout<<"ENTER THE NUMBER VERTICES:"; 

	
	cin>>n;

	for(i=1;i<=n;i++)
	{ 
		for(j=i+1;j<=n;j++)
		{ 
			if(a[i][j]==0 && i!=j)
			{
				cout<<"ENTER 1 IF "<<i<<" HAS A NODE WITH "<<j<<" ELSE 0 "; 
				cout<<endl; 
				cin>>a[i][j];
				
				if(a[i][j]==1)
				{
					cout<<endl<<"ENTER weight of edge b/t "<<i<<" and "<<j<<":";
					cin>>wt[i][j];
					cout<<endl;
				}				

				else
					wt[i][j]=0;;
					 
				a[j][i]=a[i][j];
				wt[j][i]=wt[i][j];
			} 
		} 
	}

	cout<<"THE ADJACENCY MATRIX IS\n"; 

	for(i=1;i<=n;i++) 
	{ 
		for(j=1;j<=n;j++) 
		{ 
			cout<<"  "<<a[i][j]<<","<<wt[i][j]<<"   "; 
			a2[i][j]=a[i][j];

			wt2[i][j]=wt[i][j];
		} 

		cout<<endl; 
	} 

	
	int n2=n;

	for(i=1;i<=n2;i++) 
		vis[i]=0; 


	for(i=1;i<=n2;i++) 
	{ 
		for(j=1;j<=n2;j++) 
		{ 

			if(wt2[i][j]>1 && a2[i][j]==1)
			{

//				cout<<"i is:"<<i<<"  j is"<<j<<endl;
				n2=n2+1;
				
				a2[i][j]=0;
				a2[j][i]=0;

				a2[i][n2]=1;
				a2[n2][i]=1;

				a2[n2][j]=1;			
				a2[j][n2]=1;			
				
				wt2[n2][j]=wt2[i][j]-1;			
				wt2[j][n2]=wt2[j][i]-1;			

				wt2[i][j]=0;
				wt2[j][i]=0;

				wt2[i][n2]=1;
				wt2[n2][i]=1;

				
			}
		}
	}
/*
	cout<<"n2 is:"<<n2<<endl;
	cout<<"THE ADJACENCY MATRIX(REFINED) IS:"<<endl; 

	for(i=1;i<=n2;i++) 
	{ 
		for(j=1;j<=n2;j++) 
		{ 
			cout<<"  "<<a2[i][j]<<","<<wt2[i][j]<<"   "; 
		} 

		cout<<endl; 
	} 
*/	

	cout<<"ENTER THE SOURCE VERTEX :"; 

	cin>>s; 
	
	for(i=1;i<=n2;i++) 
		parent[i]=0;		


	bfs(s,n2); 

	cout<<endl;
	cout<<"tree matrix is:"<<endl;
	for(i=1;i<=n2;i++)
	{
		for(j=1;j<=n2;j++)
		{
			cout<<"  "<<t[i][j];
		}
		cout<<endl;
	}
	
	for(i=1;i<=n;i++)
	{
		j=i;
	
		if(i!=s)	
		{
			cout<<"shortest path from "<<i<<" to "<<s<<" is:"<<i;
			
			while(j!=s)	
			{
				if(parent[j]<=n)
					cout<<"-->"<<parent[j];
				
				j=parent[j];
			}
		}
		cout<<endl;
	}			
			
	cout<<endl;

	return 0;
}


//**************BFS(breadth-first search) code**************// 

void bfs(int s,int n2) 
{ 
	int p,i; 

	add(s); 

	vis[s]=1; 


	p=delete1(); 

	if(p!=0) 
		cout<<"component "<<++count<<" is:"<<p; 

	
	while(p!=0) 
	{ 
		for(i=1;i<=n2;i++) 
		{
			
			if((a2[p][i]!=0)&&(vis[i]==0)) 
			{ 
				add(i); 
				vis[i]=1;
				t[p][i]=1;
				parent[i]=p;
			}

			t[i][p]=t[p][i]; 
		}

		p=delete1(); 

		if(p!=0) 
			cout<<"  "<<p; 
	} 

	cout<<endl;

	for(i=1;i<=n2;i++) 
		if(vis[i]==0) 
			bfs(i,n2); 
			
}

void add(int item) 
{ 
	if(rear==19) 
		cout<<"QUEUE FULL"; 
	
	else 
	{ 
		if(rear==-1) 
		{ 
			q[++rear]=item; 
			front++; 
		} 
		else 
			q[++rear]=item; 
	} 
} 

int delete1() 
{ 

	int k; 

	if((front>rear)||(front==-1)) 
		return(0); 

	else 
	{ 
		k=q[front++]; 
			return(k); 
	} 
} 


