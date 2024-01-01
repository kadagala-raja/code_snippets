#include <bits/stdc++.h>
using namespace std;

class SEGTree{
  public:
   vector<int>seg;
   SEGTree(vector<int>&arr){
       int n = arr.size();
       for(int i=0;i<4*n;++i){
           seg.push_back(-1);
       }
       build(0,0,n-1,arr);
   }
   void build(int ind,int l,int r,vector<int>&arr){
       if(l == r){
           seg[ind] = arr[l];
           return;
       }
       int m = (l+r)/2;
       build(2*ind + 1,l,m,arr);
       build(2*ind + 2,m+1,r,arr);
       seg[ind] = seg[2*ind + 1]|seg[2*ind + 2];  
       
   }  
   void update(int ind,int l,int r,int i,int val,vector<int>&arr){
       if(l==r){
           seg[ind] = val;
           arr[i] = val;
           return;
       }
       int m = (l+r)/2;
       if(i>m){
           update(2*ind+2,m+1,r,i,val,arr);
       }
       else{
           update(2*ind+1,l,m,i,val,arr);
       }
        seg[ind] = seg[2*ind + 1]|seg[2*ind + 2];  
   }
   int query(int ind,int l,int r,int req_l,int req_r){
       //no overlap
       if(req_l>r || req_r<l)return 0;
       //complete overlap
       else if(l>=req_l && r<=req_r)return seg[ind];
       //partial overlap
       else{
           int m = (l+r)/2;
           int lef = query(2*ind + 1,l,m,req_l,req_r);
           int rig = query(2*ind + 2,m+1,r,req_l,req_r);
              return lef|rig;
       }
   }
    
};

