class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int i = 0;
        int count5 = 0;
        int count10 = 0;
        while (i < n) {
            if (bills[i] == 5) {
                count5++;
                i++;
            }
            else if (bills[i] == 10) {
                if (count5 > 0) {
                    count10++;
                    count5--;
                    i++;
                }
                else {
                    return false;
                }
            }
            else {
                if( count5 > 0 && count10 >0){
                    count5 --; 
                    count10--;
                    i++;
                }
                else if(count5 > 2 ){
                    count5 -=3;
                    i++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};