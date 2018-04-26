// A C++ program to find biconnected components in a given undirected graph

#include<iostream>
#include <list>
#include <stack>
#define NIL -1
using namespace std;
int count = 0;
class Edge
{
    public:
    int u;
    int v;
    Edge(int u, int v);
};

Edge::Edge(int u, int v)
{
    this->u = u;
    this->v = v;
}
  
class Graph
{
    int V;    
    int E;  
    list<int> *adj;    
    void BCCUtil(int u, int disc[], int low[],list<Edge> *st, int parent[]);

public:
    Graph(int V);   
    void addEdge(int v, int w);  
    void BCC();    
};
   
Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    adj = new list<int>[V];
}
   
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    E++;
}
   

void Graph::BCCUtil(int u, int disc[], int low[], list<Edge> *st,int parent[])
{
    static int time = 0;
   
    disc[u] = low[u] = ++time;
    int children = 0;
   
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i; 
   
        if (disc[v] == -1)
        {
            children++;
            parent[v] = u;
            st->push_back(Edge(u,v));
            BCCUtil(v, disc, low, st, parent);
   
            low[u]  = min(low[u], low[v]);
  
            if( (disc[u] == 1 && children > 1) ||
                (disc[u] > 1 && low[v] >= disc[u]) )
            {
                while(st->back().u != u || st->back().v != v)
                {
                    cout << st->back().u << "--" << st->back().v << " ";
                    st->pop_back();
                }
                cout << st->back().u << "--" << st->back().v;
                st->pop_back();
                cout << endl;
                count++;
            }
        }
   
        else if(v != parent[u] && disc[v] < low[u])
        {
            low[u]  = min(low[u], disc[v]);
            st->push_back(Edge(u,v));
        }
    }
}
   
void Graph::BCC()
{
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    list<Edge> *st = new list<Edge>[E];
   
    for (int i = 0; i < V; i++)
    {
        disc[i] = NIL;
        low[i] = NIL;
        parent[i] = NIL;
    }
   
    for (int i = 0; i < V; i++)
    {
        if (disc[i] == NIL)
        	BCCUtil(i, disc, low, st, parent);
          
        int j = 0;
        while(st->size() > 0)
        {
            j = 1;
            cout << st->back().u+1<< "--" << st->back().v+1<< " ";
            st->pop_back();
        }
        if(j == 1)
        {
            cout << endl;
            count++;
        }
    }
}
  
int main()
{
	int i,j,n,a[20][20];
	cout<<"give no.of vertices\n";
	cin>>n;
	Graph g(n);
	for(i=0;i<n;i++)
	{ 
		for(j=0;j<n;j++)
		{ 
			if(a[i][j]!=1 && i!=j)
			{
				cout<<"ENTER 1 IF "<<i+1<<" HAS A NODE WITH "<<j+1<<" ELSE 0 "; 
				cout<<endl; 
				cin>>a[i][j];
				a[j][i]=a[i][j];
			}
		} 
	}

	
	for(i=0;i<n;i++)
	{ 
		for(j=0;j<n;j++)
		{ 
			if(a[i][j]==1)
				g.addEdge(i,j);
		} 
	}

	cout << "below are " << count+1 << " biconnected components in graph\n";

	g.BCC();
return 0;
}
