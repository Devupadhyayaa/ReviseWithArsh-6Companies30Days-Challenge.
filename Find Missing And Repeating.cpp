class Solution{
    #define ll long long
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repeat;
        int miss;
        ll sum=0;
        ll rs=((1ll*n)*(n+1))/2;
        for(auto it:arr)sum+=it;
        for(int i=0;i<n;i++){
            int idx=arr[i]%(n+1) - 1;
            arr[idx]+=(n+1);
        }
        for(int i=0;i<n;i++){
            if(arr[i]/(n+1)>=2){
                repeat=i+1;
            }
        }
        sum-=repeat;
        miss=rs-sum;
        return {repeat,miss};
    }
};
