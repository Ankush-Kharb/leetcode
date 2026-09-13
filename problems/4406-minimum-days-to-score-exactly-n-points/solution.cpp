class Solution {
public:
    int minDays(int n) {
        queue<pair<int,int>> q;
        q.push({0, 0}); // value , streak , day
        int max_streak= sqrt(2.0*n)+2;
        vector<vector<bool>> visited(n + 1, vector<bool>(max_streak, 0));
        int days = 0;
        visited[0][0]=1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [score, streak] = q.front();
                q.pop();
                if (score == n)
                    return days;
                int ns=score+streak+1;
                int nk=streak+1;
                if(ns<=n && !visited[ns][nk]){
                    visited[ns][nk]=1;
                    q.push({ns,nk});
                }

                if(streak>0 && !visited[score][0])
                {
                    visited[score][0]=1;
                    q.push({score,0});
                }
            }
            days++;
        }
        return -1;
    }
};