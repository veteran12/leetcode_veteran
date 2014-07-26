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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        
        map<UndirectedGraphNode *, UndirectedGraphNode *> built;
        
        return copy(node, built);
    }
    
    UndirectedGraphNode *copy(UndirectedGraphNode *node, map<UndirectedGraphNode *, UndirectedGraphNode *> &built) {
        if(built.find(node) != built.end())
            return built[node];
        
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        for (int i=0; i<node->neighbors.size(); i++) {
            if(node->neighbors[i] == node)
                newNode->neighbors.push_back(newNode);
            else
                newNode->neighbors.push_back(copy(node->neighbors[i], built));
        }
        built[node] = newNode;
        
        return newNode;
    }
};