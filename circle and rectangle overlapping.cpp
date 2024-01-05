class Solution {
public:
    bool checkOverlap(int r, int h, int k, int x1, int y1, int x2, int y2) {
        for(int x=x1;x<=x2;x++){
            for(int y=y1;y<=y2;y++){
                int val = (x-h)*(x-h) + (y-k)*(y-k);
                if(val<=r*r)return true;
            }
        }
        return false;
    }
};
