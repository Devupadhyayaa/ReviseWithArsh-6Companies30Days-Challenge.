#define mod 1000000007
namespace std {
    // Custom hash function for std::pair
    template <typename T1, typename T2>
    struct hash<std::pair<T1, T2>> {
        size_t operator()(const std::pair<T1, T2>& p) const {
            size_t hashValue = 0;

            // Combine hash of the first element in the pair
            hash_combine(hashValue, p.first);

            // Combine hash of the second element in the pair
            hash_combine(hashValue, p.second);

            return hashValue;
        }
        // Helper function to combine hash values
        template <typename T>
        void hash_combine(size_t& seed, const T& value) const {
            seed ^= std::hash<T>{}(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
    };
}
// namespace std {
//     template <>
//     struct hash<std::pair<int, std::vector<int>>> {
//         size_t operator()(const std::pair<int, std::vector<int>>& p) const {
//             size_t hashValue = 0;
//             hash_combine(hashValue, p.first);
//             for (const auto& element : p.second) {
//                 hash_combine(hashValue, element);
//             }

//             return hashValue;
//         }
//         template <typename T>
//         void hash_combine(size_t& seed, const T& value) const {
//             seed ^= std::hash<T>{}(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//         }
//     };
// }
class Solution {
// int solve(vector<int>&nums,vector<int>&ds,int idx){
//     if(idx==nums.size()){
//         int n=nums.size();
//         int cnt=0;
//         for(int i=0;i<n-1;i++){
//             if(ds[i]%ds[i+1]!=0&&ds[i+1]%ds[i]!=0)return 0;
//         }
//         return 1;
//     }
//     int ans=0;
//     for(int i=0;i<nums.size();i++){
//         if(nums[i]==-1)continue;
//         int temp=nums[i];
//         nums[i]=-1;
//         ds.push_back(temp);
//         ans = ans%mod + (solve(nums,ds,idx+1)%mod);
//         ds.pop_back();
//         nums[i]=temp;
//     }
//     return ans;
// }
int solve(int temp,int pre, vector<int>&nums,int idx,unordered_map<pair<int,int>,int>& dp){
    if(idx==nums.size()){
        return 1;
    }
    if(dp.count({pre,temp}))return dp[{pre,temp}];
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if((temp&(1<<i))!=0)continue;
        if(pre==-1||nums[i]%nums[pre]==0||nums[pre]%nums[i]==0){
            ans = (ans%mod + solve(temp|(1<<i),i,nums,idx+1,dp)%mod)%mod;
        }
    }
    return dp[{pre,temp}]=ans;
}
public:
    int specialPerm(vector<int>& nums) {
        unordered_map<pair<int,int>,int>dp;
        return solve(0,-1,nums,0,dp);
    }
};
