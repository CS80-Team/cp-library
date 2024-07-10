
// return true with number of nodes in the cycle, either odd cycle or even
bool cycle_detection(unordered_map<int, vector<int>> &graph, int source, int par, unordered_map<int,bool> vis, int c){
    if(vis[source]) return true;

   vis[source] = true;

   for(int v: graph[source]){
    if(v != par){
        c++;
        if(dfs(graph,v, source, vis, c)) return true;
    }   
   }
   return false;
}
