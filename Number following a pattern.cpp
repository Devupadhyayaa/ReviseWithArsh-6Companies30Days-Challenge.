class Solution{   
public:
    string printMinNumberForPattern(string str){
        // code here 
        string ans=""; char c='1';
        for(int i=0;i<=str.size();i++){
            ans+=c;
            c++;
        }
        while(true){
            int f=1;
            for(int i=1;i<ans.size();i++){
                if((str[i-1]=='D'&&ans[i]>ans[i-1])||(str[i-1]=='I'&&ans[i]<ans[i-1])){
                    swap(ans[i],ans[i-1]);
                    f=0;
                }
            }
            if(f==1)break;
        }
        return ans;
    }
};
