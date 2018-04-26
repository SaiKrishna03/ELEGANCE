#include<iostream>
#include<cstdlib>

using namespace std;


int a[20][20],vis[20],stack[20],q[20],front=-1,rear=-1; 
int top=-1;

int delete1(); 
void add(int item); 
void bfs(int s,int n); 
void dfs(int s,int n); 
void push(int item); 
int pop();

int main() 
{ 
	int n,i,s,ch,j; 
	char c,dummy; 

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


	do 
	{ 
		for(i=1;i<=n;i++) 
			vis[i]=0; 

		cout<<"MENU\n"; 

		cout<<"1.B.F.S\n"; 

		cout<<"2.D.F.S\n"; 

		cout<<"ENTER YOUR CHOICE\n"; 

		cin>>ch; 

		cout<<"ENTER THE SOURCE VERTEX :"; 

		cin>>s; 


		switch(ch) 
		{ 
			case 1:
				bfs(s,n); 
			break; 

			case 2: 
				dfs(s,n); 
			break; 

		} 

		cout<<endl<<"DO U WANT TO CONTINUE(y/n) ?\n"; 

		cin>>c; 

	}while((c=='y')||(c=='Y')); 
	
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

		cout<<p; 

	while(p!=0) 
	{ 
		for(i=1;i<=n;i++) 
			if((a[p][i]!=0)&&(vis[i]==0)) 
			{ 
				add(i); 
				vis[i]=1; 
			} 

		p=delete1(); 

		if(p!=0) 
			cout<<"  "<<p; 
	} 

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



//***************DFS(depth-first search) code******************// 
void dfs(int s,int n) 
{ 
	int i,k; 
	push(s); 
	vis[s]=1; 

	k=pop();

	if(k!=0) 
		cout<<k; 

	while(k!=0) 
	{ 
		for(i=1;i<=n;i++) 
			if((a[k][i]!=0)&&(vis[i]==0)) 
			{ 
				push(i); 
				vis[i]=1; 
			} 

		k=pop(); 

		if(k!=0) 
			cout<<"  "<<k; 

	} 

	for(i=1;i<=n;i++) 
		if(vis[i]==0) 
			dfs(i,n); 
} 

void push(int item) 
{ 
	if(top==19) 
		cout<<"Stack overflow "; 

	else 
		stack[++top]=item; 
} 

int pop() 
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

