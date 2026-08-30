class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int srcSum = source[0] + source[1];
        int tSum = target[0] + target[1];
        if(srcSum % 2 != tSum%2 )return -1;
        int sX = source[0];
        int sY = source[1];
        int tX = target[0];
        int tY = target[1];
        if (abs(sX - tX) == abs(sY - tY)) return 1;
        else return 2;
        
    }
};