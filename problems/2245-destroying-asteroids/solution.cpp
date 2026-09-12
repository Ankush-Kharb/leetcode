class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long massP = mass;
        for(int i = 0; i<asteroids.size();i++){
            if(massP>= asteroids[i]){
                massP+= asteroids[i];
            }
            else if(massP< asteroids[i]){
                return false;
            }
        }
        return true;
        
    }
};