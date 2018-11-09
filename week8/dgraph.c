#include <stdio.h>
#include <stdlib.h>
#include "dgraph.h"

Graph createGraph(){
	Graph graph;
	graph.vertices = make_jrb();
	graph.edges = make_jrb();
	return graph;
}

void addVertex(Graph graph, int id, char* name){
	JRB node = jrb_find_int(graph.vertices, id);
	if(node == NULL)
		jrb_insert_int(g.vertices, id, new_jval_s(strdup(name)));
}

char *getVertex(Graph graph, int id){
	JRB node = jrb_find_int(graph.vertices, id);
	if(node == NULL)
		return NULL;
	else
		return jval_s(node->val);
}

void addEdge(Graph graph, int vi, int v2){
	JRB node, tree;

	if(jrb_find_int(v1)==NULL) return;
	if(jrb_find_int(v2)==NULL) return;

	node = jrb_find_int(g.edges, v1);
	if(node == NULL){
		tree = make_jrb();
		jrb_insert_int(g.edges, v1, new_jval_v(tree));
	} else tree = (JRB)jval_v(node->val);

	if(jrb_find_int(tree, v2) == NULL)
		jrb_insert_int(tree, v2, new_jval_s(0));
}

int hasEdge(Graph graph, int v1, int v2){
	JRB node = jrb_find_int(graph.edges, v1);
	if(node == NULL)
		return 0;
	else 
		if(jrb_find_int((JRB)jval_v(node->val), v2) == NULL)
			return 0;
		return 1;
}

int indegree(Graph graph, int v, int* output){

}


int outdegree(Graph graph, int v, int* output){

	
}