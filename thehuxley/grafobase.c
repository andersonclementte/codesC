#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node* next;
}Node;

typedef struct graph{
    Node* vertice[100];
    short visited[100];
}Graph;

Graph* creategraph()
{
    Graph* new_graph = (Graph*) malloc(sizeof(Graph));
    int i;
    for (i = 1; i<= 100 - 1; i++){
        new_graph->vertice[i] = NULL;
        new_graph->visited[i] = 0;
    }
    return new_graph;
}

Node* create_adj_list(int item)
{
    Node* new_adj_list = (Node*)malloc(sizeof(Node));
    new_adj_list->item = item;
    new_adj_list->next = NULL;
    return new_adj_list;
}

void add_edge(Graph* graph, int vert1, int vert2)
{   
    //unidirecional
    Node* vertex = create_adj_list(vert2);
    vertex->next = graph->vertice[vert1];
    graph->vertice[vert1] = vertex;//

    //undirected graph
    vertex = create_adj_list(vert1);
    vertex->next = graph->vertice[vert2];
    graph->vertice[vert2] = vertex;
}

void dfs(Graph* graph, int source)
{
    graph->visited[source];
    printf("%d\n", source);

    Node* adj_list = graph->vertice[source];
    while(adj_list != NULL){
        if (!graph->visited[adj_list->item]){
            dfs(graph, adj_list->item);
        }
        adj_list = adj_list->next;
    } 
}

void bfs(Graph* graph, int source)
{
    Queue* queue = create_queue();
    int dequeued;
    Node* node = graph->vertice[source];
    graph->visited[source] = 1;
    enqueue(queue, source);

    while(!is_empty(queue)){
        dequeued = dequeue(queue);
        node = graph->vertice[dequeued];
        while(node!=NULL){
            printf("%d\n", node->item);
            graph->visited[node->item] = 1;
            enqueue(queue, node->item);
        }
        node = node->next;
    }
}