

 //C++ Program to Find Strongly Connected Components in Graphs

 

#include<iostream>

#include<cstdlib>


void topo(int *, int am[][20], int ,int );


void topo1(int *, int am[][20], int,int);

using namespace std;

struct node_info

{

    int no;

    int lv_time, st_time;

}*q = NULL;

struct node

{

    node_info *pt;

    node *next;

}*top = NULL, *p = NULL, *np = NULL;

struct node1

{

    node1 *link;

    node_info *pt1;

}*head = NULL, *m = NULL, *n = NULL, *np1 = NULL;

int c = 0;

void push(node_info *ptr)

{

    np = new node;

    np->pt = ptr;

    np->next = NULL;

    if (top == NULL)

    {

        top = np;

    }

    else

    {

        np->next = top;

        top = np;

    }

}

node_info *pop()

{

    if (top == NULL)

    {

        cout<<"underflow\n";

    }

    else

    {

        p = top;

        top = top->next;

        return(p->pt);

        delete(p);

    }

}

void store(node_info *ptr1)

{

    np1 = new node1;

    np1->pt1 = ptr1;

    np1->link = NULL;

    if (c == 0)

    {

        head = np1;

        m = head;

        m->link = NULL;

        c++;

    }

    else

    {

        m = head;

        np1->link = m;

        head = np1;

    }

}

void remove(int x)

{

    m = head;

    if ((m->pt1)->no == x)

    {

        head = head->link;

        delete(m);

    }

    else

    {

        while ((m->pt1)->no != x && m->link != NULL)

        {

            n = m;

            m = m->link;

        }

        if ((m->pt1)->no == x)

        {

            n->link = m->link;

            delete(m);

        }

        else if (m->link == NULL)

        {

            cout<<"error\n";

        }

    }

}            

void topo(int *v, int am[][20], int i,int n)

{

    q = new node_info;

    q->no = i;

    q->st_time = c;

     push(q);

    v[i] = 1;

    for (int j = 0; j < n; j++)

    {

        if (am[i][j] == 0  || (am[i][j] == 1 && v[j] == 1))

            continue;

        else if (am[i][j] == 1 && v[j] == 0)

        {

            c++;

            topo(v,am,j,n);

        }

    }

    c++;

    q = pop();

    q->lv_time = c;

    store(q);

    return;

}

int temp[20];

void topo1(int *v, int am[][20], int i,int n)

{
	
    v[i] = 1;

    remove(i);

    cout<<i+1<<endl;

    for (int j = 0; j < n; j++)

    {

        if (am[i][j] == 0  || (am[i][j] == 1 && v[j] == 1))

        {

            continue;

        }

        else if (am[i][j] == 1 && v[j] == 0)

        {

            topo1(v,am,j,n);
	}

    }

    return;

}

int main()

{

    int n,v[20], am[20][20], amt[20][20];

	cout<<"enter no.of vertices\n";

	cin>>n;

    for (int i = 0; i <n ; i++)

        v[i] = 0;

	for(int i=0;i<n;i++)
	{ 
		for(int j=0;j<n;j++)
		{ 
			if(i!=j)
			{
				cout<<"ENTER 1 IF "<<i+1<<" HAS A NODE WITH "<<j+1<<" ELSE 0 "; 

				cout<<endl; 

				cin>>am[i][j];

			}
		
		} 
	}

    topo(v, am, 0,n);

    for (int i = 0; i < n; i++)

    {

        v[i] = 0;

        for (int j = 0; j < n; j++)

            amt[j][i] = am[i][j];

    }

    while (head != NULL)

    {

        cout<<"Strongly Connected Components:\n";                 

            topo1(v, amt, (head->pt1)->no,n);

    }


}
