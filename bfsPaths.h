/***************************************************************************//**
 * @file bfsPaths.h
 ******************************************************************************/
#ifndef __BFSPATHS_H
#define __BFSPATHS_H
#include <list>
#include <map>
#include <queue>
#include "graph.h"

/***************************************************************************//**
 * @class BFSPaths
 ******************************************************************************/
class BFSPaths
{
   // What data structures do you need to record the necessary information
   // while traversing the graph in a breadth-first manner?
   map<int, bool> isvisited;
   map<int, int> dist;
   map<int, int> prev;
   set<int> vertices;
   int start;
   int numV;

public:
   /// Given a graph and a start node, construct the client object
   BFSPaths(Graph *G, int s);

   /// Answers the question, is there a path from the start to vertex 'v'
   bool hasPath(int v);
   /// Returns the path (from start node to v) of the path if it exists
   std::list<int> pathTo(int v);
   /// Return the distance from the source to vertex 'v'
   int distance(int v);
   map<int, bool> Visited();
private:
   /// Perform a breadth-first-search starting at node s
   void bfs(Graph *G, int s);
};
#endif
