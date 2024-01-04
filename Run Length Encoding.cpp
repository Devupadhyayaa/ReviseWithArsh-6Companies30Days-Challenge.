string encode(string src)
{     
  //Your code here 
  string ans="";
  for(int i=0;i<src.size();i++){
      char c=src[i];
      ans+=c;
      char cnt='0';
      while(i<src.size()&&c==src[i]){
          cnt++;
          i++;
      }
      ans+=cnt;
      i--;
  }
  return ans;
}     
