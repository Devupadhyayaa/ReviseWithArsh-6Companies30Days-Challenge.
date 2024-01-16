class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt=0;
        int n=board.size();
        int m=board[0].size();
        int x=0,y=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    int near=0;
                    for(int d=-1;d<=1;d++){
                        if(i+d<n&&i+d>=0&&d!=0){
                            if(board[i+d][j]=='X')near++;
                        }
                        if(j+d<m&&j+d>=0&&d!=0){
                            if(board[i][j+d]=='X')near++;
                        }
                    }
                    if(near==0)x++;
                    else if(near==1)y++;
                }
            }
        }
        return x+(y/2);
    }
};
