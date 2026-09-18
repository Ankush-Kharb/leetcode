class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>> graph,
                         vector<int> inD) {
        queue<int> q;
        for (int i = 0; i < inD.size(); i++) {
            if (inD[i] == 0) {
                q.push(i);
            }
        }
        vector<int> order;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            order.push_back(top);
            for (auto it : graph[top]) {
                inD[it]--;
                if (inD[it] == 0) {
                    q.push(it);
                }
            }
        }
        return order;
    }
    vector<int> sortItems(int n, int m, vector<int>& group,
                          vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        unordered_map<int, vector<int>> itemG;
        vector<int> itemInd(n, 0);
        for (int i = 0; i < n; i++) {
            itemG[i] = vector<int>();
        }

        unordered_map<int, vector<int>> groupG;
        vector<int> groupInd(m, 0);
        for (int i = 0; i < m; i++) {
            groupG[i] = vector<int>();
        }

        for (int i = 0; i < n; i++) {
            for (int item : beforeItems[i]) {
                itemG[item].push_back(i);
                itemInd[i]++;

                if(group[i] != group[item]){
                    int prevItemG = group[item];
                    int currItemG = group[i];

                    groupG[prevItemG].push_back(currItemG);
                    groupInd[currItemG]++;
                }
            }
        }

        vector<int> itemOrder = topoSort(itemG , itemInd);
        vector<int> groupOrder = topoSort(groupG, groupInd);

        unordered_map<int , vector<int>> groupToItem;

        for(int &item : itemOrder){
            int itemGroup = group[item];

            groupToItem[itemGroup].push_back(item);
        }

        vector<int> ans;
        for(auto it : groupOrder){
            for(auto items : groupToItem[it]){
                ans.push_back(items);
            }
        }
        if(ans.size() != n)return {};
        return ans;


    }
};