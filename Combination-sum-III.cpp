#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void comb( int k , int idx , int sum , vector<int>& arr , vector<vector<int>> & ans  ){

        if( sum == 0 && k == arr.size() ){
            ans.push_back( arr );
             return ; 
        }

        if( arr.size() > k ) return ;
        if( sum < 0 ) return ;
        if( idx > 9)  return ;
        
        arr.push_back( idx );
        sum = sum - idx;
        comb( k,  idx + 1 , sum , arr , ans );

        
        arr.pop_back();
        sum = sum+idx;
        comb( k , idx+1 , sum , arr , ans);

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        vector<vector<int>> ans ; 

        int idx = 1;
         comb( k , idx , n , arr , ans );
         return ans;
        
    }
};

int main(){

    int k , n;
    cout << "Enter K :";
    cin >> k;

    cout << "Enter N :";
    cin >> n;

    vector<vector<int>>ans ;

    Solution solution;

    ans = solution.combinationSum3( k , n );

    for( int i =0; i< ans.size() ; i++){
        for(int j=0; j < ans[i].size(); j++){
            cout << ans[i][j]<< " ";
        }
        cout << endl;
    }
}

/*

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60

*/