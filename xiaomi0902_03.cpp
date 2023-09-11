#include <bits/stdc++.h>
using namespace std;

int main() {
      int final_score = 0;
      int m,n,del_score,del_score_m;
      //评委总数
      cin>>n;
      vector<int> score(n);
      //删除的评委
      cin>>m;
      del_score = score[m-1];
      sort(score.begin(),score.end());
      if (del_score==score[0]){
         for(int i =2;i<n-1;i++){
            final_score+=score[i];
         }
         return final_score/n-3;
      }
      else if (del_score==score[n-1]){
            for(int i =1;i<n-2;i++){
            final_score+=score[i];
         }
         return final_score/n-3;
      }else{
            
            for(int i =1;i<n-1;i++){
                  if(score[i]==del_score) del_score_m = i;
            }
            for (int i =1;i<n-1;i++)
            {
                  if(del_score_m==i) continue;
                  final_score+=score[i];
            }
            
      }
      
      return final_score/n-3;

}