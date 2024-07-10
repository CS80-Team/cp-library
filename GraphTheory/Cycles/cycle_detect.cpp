
// return true with number of nodes in the cycle, either odd cycle or even
bool cycle_detection(unordered_map<int, vector<int>> &graph, int source, unordered_map<int,bool> vis, int c){
    if(vis[source]){
        return true;
    }
    vis[source] = true;
    for(int v: graph[source]){
        if(v != source){
            c++;
            if(cycle_detection(graph, source, vis,c)){
                return true; 
            }
        }
    }
    return false;
}
