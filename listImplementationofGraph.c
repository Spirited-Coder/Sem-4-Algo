#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node *next;
};
struct Graph{
	int numVertices;
	struct node **adjlist;
};

struct node *createnode(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->vertex = data;
	temp->next = NULL;
	return temp;
}
struct Graph *creategraph(int vertices){
	struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
	graph->numVertices = vertices;
	graph->adjlist = (struct node **)malloc(graph->numVertices*sizeof(struct node*));
	int i;
	for(i=0;i<graph->numVertices;i++){
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

int main(){
	struct Graph* graph; 
	int u,v,i,e,k;
  	printf("Enter the number of vertices and edges: ");
  	scanf("%d%d",&k,&e);
  	graph = creategraph(k);
  	printf("Enter the edges:\n");
  	for(i=0;i<e;i++){
  		scanf("%d%d",&u,&v);
  		addEdge(graph, u, v);
  	}
  
    display(graph);
  
    return 0;
}
