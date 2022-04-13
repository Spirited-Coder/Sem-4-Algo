#include<stdio.h>
#include<stdlib.h>
#define size 40

struct queue{
	int front;
	int rear;
	int item[size];
};
struct queue *createqueue();
int isEmpty(struct queue *);
int isFull(struct queue *);
void printQueue(struct queue *);
void enqueue(struct queue *,int);
int dequeue(struct queue *);

struct node{
	int vertex;
	struct node *next;
};
struct node *createnode(int);

struct Graph{
	int numVertices;
	int *visited;
	struct node **adjLists;
};
struct Graph *createGraph(int);

void addEdge(struct Graph *g,int s,int d){
	struct node *newnode = createnode(d);
	struct node *last = g->adjLists[s];
	if(g->adjLists[s]==NULL){
		g->adjLists[s] = newnode;
	}
	else{
		while(last->next!=NULL){
			last = last->next;
		}
		last->next = newnode;
	}
}

struct node *createnode(int v){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->vertex = v;
	newnode->next = NULL;
	return newnode;
}

struct Graph *createGraph(int vertices){
	struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
	g->numVertices = vertices;
	g->visited = (int *)malloc(sizeof(int)*vertices);
	g->adjLists = (struct node **)malloc(sizeof(struct node *)*vertices);
	int i;
	for(i=0;i<vertices;i++){
		g->adjLists[i] = NULL;
		g->visited[i] = 0;
	}
	return g;
}

struct queue *createqueue(){
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	return q;
}
int isEmpty(struct queue *q){
	if(q->rear == -1)
		return 1;
	else
		return 0;
}
void enqueue(struct queue *q,int item){
	if (q->rear == size-1){
		printf("Full\n");
	}
	else{
		if (q->front == -1)
    		q->front = 0;
    	q->rear++;
    	q->item[q->rear] = item;
    	printf("%d enqueued to queue\n", item);
	}
}
int dequeue(struct queue *q){
	if(isEmpty(q)){
		printf("Empty");
		return -1;
	}
	int item = q->item[q->front];
    q->front ++;
    if (q->front > q->rear) {
      printf("Resetting queue\n");
      q->front = q->rear = -1;
    }
    return item;
}

void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->item[i]);
    }
    printf("\n");
  }
}

void bfs(struct Graph *g,int s){
	struct queue *q = createqueue();
	g->visited[s] = 1;
	enqueue(q,s);
	while(!isEmpty(q)){
		int curr = dequeue(q);
		printf("Visited: %d\n",curr);
		struct node *temp = g->adjLists[s];
		while(temp){
			int vert = temp->vertex;
			if(g->visited[vert] == 0){
				g->visited[vert] = 1;
				enqueue(q,vert);
			}
			temp = temp->next;
		}
	}
}

void display(struct Graph *g){
	int i;
	for(i=0;i<g->numVertices;i++){
		struct node *temp = g->adjLists[i];
		printf("%d-->",i);
		while(temp){
			printf("%d-->",temp->vertex );
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

int main(){
	struct Graph *g;
	int v,e,i,a,b,s;
	printf("Enter he nmber of vertices and edges: ");
	scanf("%d%d",&v,&e);
	g = createGraph(v);
	printf("Enter the edges:\n");
	for(i=0;i<e;i++){
		scanf("%d%d",&a,&b);
		addEdge(g,a,b);
	}
	printf("Enter the source vertex: ");
	scanf("%d",&s);
	display(g);
	printf("\n");
	bfs(g,s);

	return 0;
}