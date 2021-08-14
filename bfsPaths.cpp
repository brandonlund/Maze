/***************************************************************************//**
 * @file bfsPaths.cpp
 ******************************************************************************/
#include "bfsPaths.h"

// It's your job to implement the BFSPaths functionality

/// Given a graph and a start node, construct the client object
BFSPaths::BFSPaths(Graph *G, int s)
{
    int i;
    
    vertices = G->Vertices();
    numV = G->V();
    
    for ( i = 0; i < numV; i++ )
        isvisited[i] = false;
    
    bfs( G, s );
    start = s;
}


/// Answers the question, is there a path from the start to vertex 'v'
bool BFSPaths::hasPath(int v)
{
    return isvisited[v];
}


/// Returns the path (from start node to v) of the path if it exists
std::list<int> BFSPaths::pathTo(int v)
{
    std::list<int> path;
    
    while ( v != start )
    {
        path.push_front( prev[v] );
        v = prev[v];
    }
    return path;
}


/// Return the distance from the source to vertex 'v'
int BFSPaths::distance(int v)
{
    return dist[v];
}


map<int, bool> BFSPaths::Visited()
{
    return isvisited;
}


/// Perform a breadth-first-search starting at node s
void BFSPaths::bfs(Graph *G, int s)
{
    list<int> queue;
    set<int>::iterator it;
    set<int> adj = G->adj( s );
    int distance = 0;
    
    isvisited[s] = true;
    
    queue.push_back( s );
    dist[s] = distance;
    
    distance++;
    
    while ( !queue.empty() )
    {
        s = queue.front();
        queue.pop_front();
        adj = G->adj( s );
        
        for ( it = adj.begin(); it != adj.end(); it++ )
        {
            if ( !isvisited[*it] )
            {
                prev[*it] = s;
                isvisited[*it] = true;
                queue.push_back( *it );
                dist[*it] = distance;
            }
        }
        
        distance++;
    }
}
