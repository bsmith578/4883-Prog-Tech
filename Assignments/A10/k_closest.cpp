class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //Max heap to hold each distance and set of points
        priority_queue<pair<int, vector<int>>> mxh;
        vector<vector<int>> closest;

        //Loop through points vector
        for(int i = 0; i < points.size(); i++) {
            //Calculate current point's distance, push distance and point into max heap
            int distance = pow(points[i][0], 2) + pow(points[i][1], 2);
            mxh.push({distance, points[i]});

            //Only keep K Closest points(smallest distance),
            //popping the top will remove the largest points
            if(mxh.size() > k)
                mxh.pop();
        }
        
        //Place only the points that are left in the max heap
        //into closest vector then remove from the max heap
        while(!mxh.empty()) {
            closest.push_back(mxh.top().second);
            mxh.pop();
        }

        return closest;
    }
};