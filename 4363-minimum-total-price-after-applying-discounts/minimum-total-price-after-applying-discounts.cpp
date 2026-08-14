class Solution {
public:
    static bool cmp(int a, int b){
        return (a>b);
    }

    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), cmp);
        sort(discounts.begin(), discounts.end(), cmp);

        double ans=0;
        int i=0;
        int ps = prices.size();
        int ds = discounts.size();
        while(i<ps && i<ds){
            double p = prices[i];
            double d = discounts[i];
            ans += 1.0*(p*(100-d))/100;
            i++;
        }
        while(i<ps){
            double p = prices[i];
            double d = 0;
            ans += 1.0*(p*(100-d))/100;
            i++;
        }
        return ans;
    }
};