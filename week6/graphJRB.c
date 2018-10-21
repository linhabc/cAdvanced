#include <stdio.h>
#include <stdlb.h>
#include "graphJRB.h"

Graph createGraph(){
  return make_jrb();
}

void addEdge(Graph graph, int v1, int v2){
  JRB tree = make_jrb();

  Graph g1 = jrb_find_int(graph, v1);            //find if key v1 exist
  if(g1==NULL){
    tree = creatGraph();                         //create new tree
    jrb_insert_int(graph, v1, new_jval_v(tree)); //insert new tree as value of key v1
  }else{
    tree = (JRB)jval_v(g1->val);                 //else, assign new tree as v1 edge tree
  }
  jrb_insert_int(tree, v2, new_jval_i(1));       //insert value for node in newtree

  Graph g2 = jrb_find_int(graph, v2);            //similar as v1
  if(g2==NULL){
    tree = creatGraph();
    jrb_insert_int(graph, v2, new_jval_v(tree));
  }else{
   tree = (JRB)jval_v(g2->val);
  }
  jrb_insert_int(tree, v1, new_jval_i(1));
}

int adjacent(Graph graph, int v1, int v2){
  
}

int getAdjacentVertices (Graph graph, int v, int* output){
  JRB node;
  int total=0;
  node = jrb_find_int(graph, v);
  tree = (JRB)jval_v(node->val);
  jrb_traverse(node, tree){
    output[total++] = jval_i(node->key);
  }
  return total;
}

void printGraph(Graph graph){
  JRB tmp, nodetmp;
  jrb_traverse(tmp, graph){
    printf("%d: ", jval_i(tmp->key));
    jrb_traverse(nodetmp, tmp->val){
      printf("%d ", jval_i(nodetmp->key));
    }
    printf("\n");
  }
}

void dropGraph(Graph graph){
  JRB tmp;
  jrb_traverse(tmp, graph){
    jrb_free_tree(tmp->val);
  }
  jrb_free_tree(graph);
}
