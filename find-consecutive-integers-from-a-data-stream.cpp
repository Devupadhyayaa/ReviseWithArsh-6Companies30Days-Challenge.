class DataStream {
public:
    int val=0;int ans=0,count=0;
    DataStream(int value, int k) {
        val=value;
        ans=k;
    }
    
    bool consec(int num) {
        if(num!=val){
            count=0;
        }
        if(num==val)count++;
        return count>=ans;
    }
};
