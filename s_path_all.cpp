//c++ program to get shortest path between all vetices using bfs
#include<iostream>
#include<cstdlib>

using namespace std;


int q[100],front=-1,rear=-1,a[100][100],vis[100],stack[100]; 

int t[100][100];	//tree matrix stores the edges in tree
int count=0;	//count gives the no.of components in given graph
int parent[100];//parent array stores parents of each vertex


int delete1(); 
void add(int item); 
void bfs(int s,int n); 

int main() 
{ 
	int n,i,s,ch,j,k; 

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
				a[j][i]=a[i][j];
			} 
		} 
	}

	cout<<"THE ADJACENCY MATRIX IS\n"; 

	for(i=1;i<=n;i++) 
	{ 
		for(j=1;j<=n;j++) 
		{ 
			cout<<"  "<<a[i][j]; 
		} 

		cout<<endl; 
	} 



	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++) 
		{
			vis[i]=0; 
			parent[i]=0;		
		}	
	
		cout<<"SOURCE VERTEX IS:"<<k<<endl; 
	
			
	
		front=-1;
		rear=-1;
		count=0;

		bfs(k,n); 
		
		cout<<endl;
/*		cout<<"tree matrix is:"<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cout<<"  "<<t[i][j];
			}
			cout<<endl;
		}
*/		
		for(i=1;i<=n;i++)
		{
			j=i;
			
			if(i!=k)
			{
				cout<<"shortest path from "<<i<<" to "<<k<<" is:"<<i;
				
				while(j!=k)	
				{
					cout<<"-->"<<parent[j];
					j=parent[j];
				}
			}
			cout<<endl;
		}			
				
		cout<<endl;
	}
	return 0;
}	
	
//**************BFS(breadth-first search) code**************// 
void bfs(int s,int n) 
{ 
	int p,i; 

	add(s); 

	vis[s]=1; 


	p=delete1(); 

	if(p!=0) 
		cout<<"component "<<++count<<" is:"<<p; 

	
	while(p!=0) 
	{ 
		for(i=1;i<=n;i++) 
		{
			
			if((a[p][i]!=0)&&(vis[i]==0)) 
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

	for(i=1;i<=n;i++) 
		if(vis[i]==0) 
			bfs(i,n); 
			
}

void add(int item) 
{ 
	if(rear==99) 
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



