// DIJKSTRA ALGORITHM FOR SHORTEST PATH
// SINGLE-SOURCE SHORTEST PATH ALGORITHM(SSSP)
// FOR NON-NEGATIVE WEIGHTED GRAPHS (DIRECTED AND NON-DIRECTED)
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std ;

template<typename T>
class Graph{
	unordered_map<T, list<pair<T, int>>> umap; 

public:
	void addEdge(T a, T b, int dist, bool dir=true){
		umap[a].push_back({b, dist}) ;
		if(dir)
			umap[b].push_back({a, dist}) ;
	}

	void print_adj(){
		for(auto it:umap){
			cout << it.first << "->"  ;
			for(auto itr:it.second)
				cout << "(" << itr.first << " " << itr.second << ")" ;
			cout << endl ;
		}
	}

	void dijkstra(T src){
	    unordered_map<T, int> dist ;
    	for(auto it:umap)
    		dist[it.first]=INT_MAX ;
    
    	set<pair<int, T>> s ;
    	dist[src]=0 ;
    	s.insert({0, src}) ;
    
    	while(!s.empty()){
    		auto itr = *(s.begin()) ;
    		s.erase(s.begin()) ;
    		T node = itr.second ;
    		int node_dist = itr.first ;
    		for(auto nbr:umap[node]){
    		    T v = nbr.first ;
    		    int weight = nbr.second ;
    			if(node_dist + weight < dist[v]){
    				// In set updation is not possible
    				// we have to remove the old pair and 
    				// insert a new pair instead
    				if(s.find({dist[v], v})!=s.end())
    					s.erase({dist[v], v}) ;
    				dist[v] = node_dist + weight ;
    				s.insert({dist[v], v}) ;
    			}
    		}
    	}
    
    	for(auto i : dist)
    		cout << i.first << " " << i.second << endl ;
    }	
};

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;

	Graph<int> g;
	g.addEdge(1, 2, 1) ;
	g.addEdge(1, 3, 4) ;
	g.addEdge(2, 3, 1) ;
	g.addEdge(3, 4, 2) ;
	g.addEdge(1, 4, 7) ;

	g.print_adj() ;
	g.dijkstra(1) ;

	return 0 ;
}