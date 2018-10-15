#include <stdio.h>
#include <stdlb.h>
#include "graphJRB.h"

Graph createGraph(){
  return make_jrb();
}

void addEdge(Graph graph, int v1, int v2){
  Graph g1 = jrb_find_int(v1);
  Graph G2 = jrb_find_int(v2);
  Graph newGraph = createGraph();

  if(g1==NULL && g2==NULL){
    jrb_insert_int(g, v1, new_jval_v(newGraph));
    jrb_insert_int(newGraph, v2, new_jval_i(1));
  }else if(g1==NULL){
    
  }else if(g2==NULL){

  }else{
   
  }
}

int adjacent(Graph graph, int v1, int v2){
  
}

int getAdjacentVertices (Graph graph, int v, int* output);

void printGraph(Graph graph){
  JRB tmp;
  jrb_traverse(tmp, graph){
    printf("\n(%d %d)\n", jval_i(tmp->key), jval_i(tmp->val));
  }
}

void dropGraph(Graph graph);
