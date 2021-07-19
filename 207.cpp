class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int inside[numCourses];
        memset(inside, 0, sizeof(inside));
        
        vector<vector<int> > vec;
        for(int i = 0; i< numCourses; i++) vec.push_back(vector<int>{});
        for(int i = 0; i < prerequisites.size(); i++){
            vec[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inside[prerequisites[i][0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
            if(inside[i] == 0) q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto o: vec[u]){
                inside[o]--;
                if(inside[o] == 0) q.push(o);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inside[i]) return false;
        }
        return true;
    }
};
