#include<iostream>
#include<string>
#define MAX 7
using namespace std;
struct side{
	int num;
	side *next;
};
struct ver{
	string vertex;
	side *first;
};
class graph{
	int edges;
	ver adjlist[MAX];
	int visited[MAX];
public:
	graph(string*,int);
	void depth(int);
};
graph::graph(string v[],int edges){
	int i;
	this->edges=edges;
	for(i=0;i<MAX;i++){
		adjlist[i].vertex=v[i];
		adjlist[i].first=NULL;
	}
	for(i=0;i<this->edges;i++){
		int k=0,j=0;
		cout<<"please input vertex's num which has contect"<<endl;
		cin>>k>>j;
		side *s=new side;
		s->num=j;
		s->next=adjlist[k].first;
		adjlist[k].first=s;
		side *p=new side;
		p->num=k;
		p->next=adjlist[j].first;
		adjlist[j].first=p;
	}
	for(i=0;i<MAX;i++)
		visited[i]=0;
}
void graph::depth(int v){
	int i;
	cout<<adjlist[v].vertex;
	visited[v]=1;
	side*p=adjlist[v].first;
	while(p!=NULL){
		if(visited[p->num]==0)
			depth(p->num);
		p=p->next;
	}
	for(i=0;i<MAX;i++)
		if(visited[i]!=1)
			depth(i);
}
int main(){
	string str[7]={"v0","v1","v2","v3","v4","v5","v6"};
	graph mygraph(str,7);
	mygraph.depth(1);
	return 0;
}

