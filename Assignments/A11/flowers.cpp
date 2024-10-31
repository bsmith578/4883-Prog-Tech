class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //Vectors for adjacency list and final flowers answer
        vector<vector<int>> adj(n + 1);
        vector<int> answer(n, 0);

        //Loop and fill the adjacency list
        for(const auto& v : paths) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        //Check and assign flowers for each node
        for(int i = 0; i < n; i++) {
            //Check if current node does not have a flower
            if(answer[i] == 0) {
                //If no flower, create a set of all neighboring flowers
                set<int> neighbor_colors;

                for(const auto& x : adj[i + 1]) {
                    if(answer[x - 1] != 0)
                        neighbor_colors.insert(answer[x - 1]);
                }

                //Assign the node the lowest available flower
                for(int f = 1; f <= 4; f++) {
                    if(neighbor_colors.find(f) == neighbor_colors.end()) {
                        answer[i] = f;
                        break;
                    }
                }
            }
        }

        return answer;
    }
};