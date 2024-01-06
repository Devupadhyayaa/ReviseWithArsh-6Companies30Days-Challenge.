class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans;
        vector<int> v;
        int n = img.size();
        int m = img[0].size();
        int a,b,c;
        int d,e,f;
        int g,h,x;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a=b=c=0;
                d=e=f=0;
                g=h=x=0;
                int count=1;
                if((i-1)>=0 && (j-1)>=0 && (i-1)<n && (j-1)<m){
                    a = img[i-1][j-1];
                    count++;
                }

                if((i-1)>=0 && (j)>=0 && (i-1)<n && (j)<m){
                    b = img[i-1][j];
                    count++;
                }

                if((i-1)>=0 && (j+1)>=0 && (i-1)<n && (j+1)<m){
                    c = img[i-1][j+1];
                    count++;
                }

                if((i)>=0 && (j-1)>=0 && (i)<n && (j-1)<m){
                    d = img[i][j-1];
                    count++;
                }

                e = img[i][j];

                if((i)>=0 && (j+1)>=0 && (i)<n && (j+1)<m){
                    f = img[i][j+1];
                    count++;
                }

                if((i+1)>=0 && (j-1)>=0 && (i+1)<n && (j-1)<m){
                    g = img[i+1][j-1];
                    count++;
                }

                if((i+1)>=0 && (j)>=0 && (i+1)<n && (j)<m){
                    h = img[i+1][j];
                    count++;    
                }

                if((i+1)>=0 && (j+1)>=0 && (i+1)<n && (j+1)<m){
                    x = img[i+1][j+1];
                    count++;
                }
                long long avg = (a+b+c+d+e+f+g+h+x)/count;
                v.push_back(avg);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};
