//generating subsets ; 
void search(int k){
    if (k==n){

        //process subset
    }
    else{
        search(k+1) ; 
        subset.push_back(k) ; 
        search(k+1) ; 
        subset.pop_back() ; 
    }
}

vector<int> generate_subset(int n){
    //generating subsets methode 2 
    for (int b = 0 ; b < (1<<n) ; b++){ 
        vector<int> subset; 
        for (int i = 0 ; i< n ; i++){
            if (b&(1<<i)){
                subset.push_back(i) ;
            }
        }
    }
}
