class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto pre : prerequisites){
            int course=pre[0];
            int prereq=pre[1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int>q;
        int completed=0;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            completed++;

            for(auto it : graph[cur]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return completed==numCourses;
    }
};