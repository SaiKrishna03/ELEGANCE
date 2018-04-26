#include<iostream>
#include<cstdlib>

using namespace std;

int loop=1,top=-1;

int stack[20],count[20],temp1[20][20],vis[20]; 

class DFS
{

public:

int dfs(int,int,int[],int a[20][20]);

void push(int); 

int pop();

int art_points(int[],int a[20][20],int);

int bridge(int[],int a[20][20],int);

};

int DFS::dfs(int s,int n,int array[20],int a[20][20]) 	
{ 
	int i,k,j; 
	push(s); 
	vis[s]=1; 

	k=pop();

	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		temp1[i][j]=0;
	}

	if(k!=0) 
	
		++count[loop];
		
	while(k!=0) 
	{ 
		for(i=1;i<=n;i++) 
			if((a[k][i]!=0)&&(vis[i]==0)) 
			{ 
				push(i); 

				vis[i]=1;
				
				temp1[k][i]=1;

				temp1[i][k]=1; 
			} 

		k=pop(); 
		
	} 

	for(i=1;i<=n;i++) 
		if(vis[i]==0) 
			dfs(i,n,array,a);
	 
return count[loop];
} 

void DFS::push(int item) 
{ 
	if(top==19) 
		cout<<"Stack overflow "; 

	else 
		stack[++top]=item; 
} 

int DFS::pop() 
{ 
	int k; 

	if(top==-1) 
		return 0; 

	else 
	{ 
		k=stack[top--]; 
		return k; 
	} 
}

int DFS::art_points(int array1[20],int a1[20][20],int n)
{
int i,j,k,l,s,t,res;

int temp[20],m_graph[20][20];


	for(i=1;i<=n;i++) 
	
		for(j=1;j<=n;j++) 
		
			m_graph[i][j]=0;
			 

for(k=1;k<=n;k++)
{
	l=1;

	for(i=1;i<=n;i++)
	{
		if(i!=k)
		{
			temp[l]=array1[i];	
			l++;
		}
	}

	s=0;

	for(i=1;i<=n;i++)
	{
			if(i!=k)
			{	
				s=s+1;

				t=0;

				for(j=1;j<=n;j++)
					{
			
						if(j!=k)
						{
							t=t+1;
							m_graph[s][t]=a1[i][j];
						}

					}

			}
		

	}


	for(i=1;i<n;i++) 
			vis[i]=0; 

	res=dfs(1,n-1,temp,m_graph);
	
	if(res!=1)

		cout<<" "<<array1[k];
		
		loop++;
}		
return 0;
}

int DFS::bridge(int array1[20],int a1[20][20],int n)
{
int j,k;

	for(k=1;k<n;k++) 
			vis[k]=0; 

	dfs(1,n,array1,a1);

for(k=1;k<=n;k++)
{
	for(j=1;j<=n;j++)
		{
			if(temp1[k][j]!=0 && k<j)
			{
				if(count[j]!=1)

					cout<<" "<<array1[k]<<"-"<<array1[j]<<" ";
			}
				
		}
}
return 0;
}

int main() 
{ 
DFS object;

	int array1[20],a1[20][20],m_graph[20][20],temp[20];

	int n,i,j,k,l,s,t; 

	cout<<"ENTER THE NUMBER OF VERTICES:"; 
	
	cin>>n;

	cout<<"enter the vertices:\n";

	for(i=1;i<=n;i++)

	cin>>array1[i];

	for(i=1;i<=n;i++)
	{ 
		for(j=1;j<=n;j++)
		{ 
			if(a1[i][j]!=1 && i!=j)
			{
				cout<<"ENTER 1 IF "<<i<<" HAS A NODE WITH "<<j<<" ELSE 0 "; 

				cout<<endl; 

				cin>>a1[i][j];

				a1[j][i]=a1[i][j];
			}
		
		} 
	}

	
	for(i=1;i<=n;i++)
	{ 
		for(j=1;j<=n;j++)
		{ 
			if(i==j)

			a1[i][j]=0;
		
		} 
	}


	cout<<"\narticulation points are:"<<endl;

	object.art_points(array1,a1,n);

	cout<<"\nbridges are:\n";

	object.bridge(array1,a1,n);

	cout<<endl;

return 0;
}

