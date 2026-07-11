class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> V(n);
        for(auto i : edges) {
            V[i[0]].push_back(i[1]);
            V[i[1]].push_back(i[0]);
        }
        vector<bool> visit(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(visit[i]) continue;
            queue<int> q;
            visit[i] = true;
            q.push(i);
            int n = 0, eC = 0;
            while(!q.empty()) {
                int k = q.front(); q.pop();
                n++;
                eC += V[k].size();
                for(auto v: V[k]) {
                    if(!visit[v]) {
                        visit[v] = true;
                        q.push(v);
                    }
                }
            }
            eC /= 2;
            if((n * (n - 1) / 2) == eC) ans++;
        }
        return ans;
    }
};