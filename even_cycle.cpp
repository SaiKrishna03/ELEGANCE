//c++ program to test graph is bi_partite or not using bfs
#include<iostream>
#include<cstdlib>

using namespace std;


int q[20],front=-1,rear=-1,a[20][20],vis[20],stack[20]; 

int t[20][20];	//tree matrix stores the edges in tree
int count=0;	//count gives the no.of components in given graph
int parent[20];//parent array stores parents of each vertex
int source[20];//stores source vertex for every vertex

int delete1(); 
void add(int item); 
void bfs(int s,int n); 

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

	for(i=1;i<=n;i++) 
		vis[i]=0; 


//	cout<<"ENTER THE SOURCE VERTEX :"; 

//	cin>>s; 

	s=1;	//assigning source vertex as 1
	
	for(i=1;i<=n;i++) 
		parent[i]=0;		


	bfs(s,n); 

	cout<<endl;
	cout<<"tree matrix is:"<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<"  "<<t[i][j];
		}
		cout<<endl;
	}
	int check=0;
	int even=0;
	
//	cout<<"source array is:";
//	for(i=1;i<=n;i++)
//		cout<<source[i]<<"  ";
//	cout<<endl;


	for(i=1;i<=n;i++)
	{
		s=source[i];
		for(j=1;j<=n;j++)
		{
			int cnt1=0,cnt2=0;		
	
			if(a[i][j]!=t[i][j])	//if tree matrix differ from adjecency matrix then there is a non_tree edge in graph
			{
				int i1,j1;
				i1=i;	//i1 and j1 is non_tree edge
				j1=j;
				check=1;	//if check is one then there are cycles in graph
				while(i1!=s)	
				{
					i1=parent[i1];
					cnt1=cnt1+1;		//cnt1 is length of i1 from source vertex
				}

				while(j1!=s)	
				{
					j1=parent[j1];
					cnt2=cnt2+1;		//cnt2 is length of j1 from source vertex
				}
			if(cnt1!=cnt2)			//if cnt1==cnt2 then there are even_cycle in the graph
				even=1;		
			}
		}
	}

	
	
	if(even==0)
		cout<<endl<<"given graph is even_cycle free"<<endl;		
	else
		cout<<endl<<"given graph is contains a even_cycle"<<endl;		
	
	

	cout<<endl;

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
				source[i]=s;
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



