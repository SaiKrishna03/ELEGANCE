#include<iostream>
#include<vector>
#include<queue>
#include<iterator>
#include<stack>

using namespace std;
 
class graph
{
	private:
		vector<int> a[100];
		int sem;
	public:
		void in_out();
		void calling(int in[100],vector<int> a[100],int n);
};

void graph::calling(int in[100],vector<int> a[100],int n)

{
		stack<int>s;
		vector<int>::iterator it;

	for(int i=1;i<=n;i++)
		{
			if(in[i]==0)
				{
					s.push(i);	
				}			
		}
	if(s.empty())
	{
		cout<<sem<<endl;
		return;
	}
	while(!s.empty())
	{
		int i=s.top();
	 	s.pop();
		in[i]=-1;
			for(it=a[i].begin();it!=a[i].end();it++)
					in[*it]=in[*it]-1;
	}
	sem++;	
	calling(in,a,n);
}
void graph::in_out()
{
int v,e,n,uout[100],in[100],count=0;
	stack<int>s;
	vector<int>::iterator it;
	vector<int> b[100];
	vector<int> od[100];
	vector<int> id[100];

	for(int i=1;i<=n;i++)
		{
			in[i]=0;
			out[i]=0;
		}
	cout<<"enter the no of vertices:";
		cin>>n;
	cout<<"\nenter the no of edges:";
		cin>>e;
	cout<<"enter the edges:"<<endl;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		a[u].push_back(v);
		id[v].push_back(u);
		od[u].push_back(v);
	}
	cout<<"\nadjacency matrix is:\n";
	for(int i=0;i<10;i++)
		{
			if(!a[i].empty())
				{
					cout<<"["<<i<<"]"<<"-->";
					for(it=a[i].begin();it!=a[i].end();it++)
							cout<<*it<<"-->";
					cout<<"NULL"<<endl;
			}
		}

	for(int i=0;i<10;i++)
		{
			count=0;
			if(!id[i].empty())
			{
				for(it=id[i].begin();it!=id[i].end();it++)
					{
						count++;
						in[i]=count;
					}
			}
		}
	for(int i=1;i<=n;i++)
		cout<<"indegree of "<<i<<" is "<<in[i]<<endl;
	sem=0;
	calling(in,a,n);
}

int main()
{
graph g;
g.in_out();
return 0;	
}
