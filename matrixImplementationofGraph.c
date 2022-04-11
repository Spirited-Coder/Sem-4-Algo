#include<stdio.h>
#include<stdlib.h>

void display(int *,int);
int main(){
	int v,e,*graph,i,j;
	printf("Enter the number of vertices and edges: ");
	scanf("%d%d",&v,&e);
	graph=(int*)malloc(v*sizeof(int));
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			*(graph+i*v+j) = 0;
		}
	}
	printf("Enter the edges\n");
	while(e!=0){
		scanf("%d%d",&i,&j);
		*(graph+i*v+j) = *(graph+j*v+i) = 1;
		e--;
	}
	display(graph,v);
	return 0;
}

void display(int *graph,int v){
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("%d ",*(graph+i*v+j));
		}
		printf("\n");
	}
		
}