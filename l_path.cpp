#include<iostream>
#include<cstdlib>

using namespace std;


int q[20],front=-1,rear=-1,a[20][20],vis[20],stack[20]; 

int t[20][20];
int parent[20];
int count=0;


int delete1(); 
void add(int item); 
void bfs(int s,int n); 
void dfs(int s,int n); 

int main() 
{ 
	int n,i,s,ch,j,k; 
	char c; 
	int length=0;
	int len;

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

	k=1;		//giving source vertex as 1

	int r;

	for(i=1;i<=n;i++) 
		vis[i]=0; 	//every time when new root is taken array 'vis[]' should be 0

	count=0;		//count is to find no.of components


	bfs(k,n); 		//calling bfs on given vertex			
	
	for(i=1;i<=n;i++)
	{
		j=i;
		len=0;	//'len' stores local_maximum length of chain
		
		if(i!=k)
		{
			int l=j;

			while(j!=k && j!=0)	//finding deepest vertex of given tree from given source
			{
				j=parent[j];
				len=len+1;
			}
			
			if(len>length)		//'length' stores global maximum length of chain
			{
				length=len;
				r=l;		//'l' is deepest vertex in given tree
			}			
		}			
	}			
			
	front=-1;
	rear=-1;


//	cout<<"r is:"<<r<<endl;
	count=0;

	
	for(i=1;i<=n;i++) 
	{		
		vis[i]=0; 
		parent[i]=0;
	}
	
	bfs(r,n);		//again run bfs with source vertex r(which is deepest vertex)

	int end;		//end stores end index of longest path

	for(i=1;i<=n;i++)	//for every vertex in tree with root (r) checking the depth
	{
		if(i!=r)
		{
			j=i;
			len=0;	//len is length of each vertex from root	
			int r2=j;
		
			while(j!=r && j!=0)	
			{
			
				j=parent[j];
				len=len+1;	
			}
			if(len>length)
			{
				length=len;	//length stores the maximum length
				end=r2;		//end stores the vertex with maximum length from root (r)
			}
		}
	}			
	
	
//	cout<<"parent array is:";

//	for(i=1;i<=n;i++)
//		cout<<parent[i]<<"  ";
//	cout<<endl;

//	cout<<"end is:"<<end<<endl;
	  
	j=end;

	cout<<"longest path in tree is:"<<j;
	
	while(j!=r && j!=0)			//printing the path with longest chain
	{
		cout<<"-->"<<parent[j];
		j=parent[j];
	}
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

	//cout<<endl<<"DOING BFS WITH "<<s<<endl;
	
	//if(p!=0) 
	//	cout<<"component "<<++count<<" is:"<<p; 

	
	while(p!=0) 
	{ 
		for(i=1;i<=n;i++) 
		{
			
			if((a[p][i]!=0)&&(vis[i]==0)) 
			{ 
				add(i); 
				vis[i]=1;
				t[p][i]=1;	//adding edge to tree matrix
				parent[i]=p;	//storing  parent of 'i' in index 'i'
			}

			t[i][p]=t[p][i]; 
		}

		p=delete1(); 

	//	if(p!=0) 
	//		cout<<"  "<<p; 
	} 

	cout<<endl;

	for(i=1;i<=n;i++) 	
		if(vis[i]==0) 		//if there are more than one component run bfs on them also 
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



