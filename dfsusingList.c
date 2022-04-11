/*
0 1
0 2
0 3
1 2
2 4
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node *next;
};
struct Graph{
	int numVertices;
	int *visited;
	struct node **adjlist;
};

struct node *createnode(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->vertex = data;
	newnode->next = NULL;
	return newnode;
}

struct Graph *creategraph(int vertices){
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->numVertices = vertices;
	graph->visited = (int *)malloc(sizeof(int)*vertices);
	graph->adjlist = (struct node **)malloc(sizeof(struct node *));
	int i;
	for(i=0;i<vertices;i++){
		graph->visited[i] = 0;
		graph->adjlist[i] = NULL;
	}
	return graph;
}

void addEdge(struct Graph* graph, int s, int d) {
	struct node* newNode = createnode(d);
	struct node *temp = graph->adjlist[s];
	if(temp == NULL)
  		graph->adjlist[s] = newNode;
	else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}

	newNode = createnode(s);
	temp = graph->adjlist[d];
	if(temp == NULL)
  		graph->adjlist[d] = newNode;
	else{
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void dfs(struct Graph *graph,int vertex){
	struct node *temp = graph->adjlist[vertex];
	graph->visited[vertex] = 1;
	printf("Visited %d\n",vertex);
	while(temp){
		int connected = temp->vertex;
		if(graph->visited[connected] == 0)
			dfs(graph,connected);
		temp = temp->next;
	}
}

void display(struct Graph *graph){
	int i;
	printf("The graph is:\n");
	for(i=0;i<graph->numVertices;i++){
		struct node *temp = graph->adjlist[i];
		printf("%d-->",i);
		while(temp){
			printf("%d-->",temp->vertex);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}
int main() {
  	struct Graph* graph; 
	int u,v,i,e,k;
  	printf("Enter the number of vertices and edges: ");
  	scanf("%d%d",&k,&e);
  	graph = creategraph(k);
  	/*printf("Enter the edges:\n");
  	for(i=0;i<e;i++){
  		scanf("%d%d",&u,&v);
  		addEdge(graph, u, v);
  	}*/
	addEdge(graph, 0, 1);
  	addEdge(graph, 0, 2);
  	addEdge(graph, 1, 2);
  	addEdge(graph, 2, 3);
  	display(graph);

  	//dfs(graph, 0);

  	return 0;
}