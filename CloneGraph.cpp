/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode * clone_helper(UndirectedGraphNode *node,map<UndirectedGraphNode *,UndirectedGraphNode *> &lookup){
        if(lookup.find(node)==lookup.end()){
            lookup[node]=new UndirectedGraphNode(node->label);
            for(int i=0;i<(node->neighbors).size();i++){
                lookup[node]->neighbors.push_back(clone_helper(node->neighbors[i],lookup));
            }
        }
        return lookup[node];
              
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!node) return node;
        map<UndirectedGraphNode *,UndirectedGraphNode *> lookup;
        return clone_helper(node,lookup);
        
    }
};
