#include <bits/stdc++.h>

using namespace std;
#define ll long long 
void setIO(string name=""){
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()!=0){
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
} 
const int max_int = 1e5 +5 ;
vector<int> st(max_int) ;
int merge(int l , int r){
    return l+r ;
}
void build(int idx , int l , int r , vector<int> &arr){
    if (l==r){
        st[idx] = arr[l] ;
        return ;
    }
    int mid = (l+r) / 2 ; 
    build(idx*2 , l , mid  , arr) ;
    build(idx*2+1 , mid + 1 , r , arr) ;
    st[idx] = merge(st[idx*2] , st[idx*2 +1]) ;
}

int query(int idx , int l , int r , int i , int j){
    if (r < i || j < l) return 0 ; 
    if (i <= l && r<=j) return st[idx] ; 
    int  mid = (l+r) / 2 ; 
    int left = query(idx*2,l,mid,i,j) ; 
    int right = query(idx*2+1,mid+1,r,i,j) ;
    return merge(left,right) ;
}
void pointUpdate(int idx , int l , int r , int i , int v){
    if (i < l ||r < i) return ; 
    if (l==r){
        st[idx] = v ; 
        return ;
    }
    int mid = (l+r) / 2 ;
    pointUpdate(idx*2 , l , mid , i , v) ; 
    pointUpdate(idx*2+1 , mid+1 , r , i , v) ; 
    st[idx] = merge(st[idx*2] , st[idx*2+1]) ;
}

int main(){
    setIO();
    int a ;
    cin >> a ; 
    vector<int> X(a+1)  ; 
    for (int i = 1 ; i <= a; i++){
        cin >> X[i] ;
    }
    st.resize(4*a) ; 
    build(1,1,a,X) ; 
    cout << query(1,1,a,1,4) << endl ;
    pointUpdate(1,1,a,2,10) ;
    cout << query(1,1,a,1,4) << endl ;
}
