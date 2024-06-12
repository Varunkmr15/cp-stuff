//Factors in O(Sqrt(n))
vector <int> factor(int x) {
    vector <int> result;
    int i = 1;
    while(i*i <= x) {
        if(x % i == 0) {
            result.pb(i);
            if(x/i != i) {
                result.pb(x/i);
            }
        }
        i++;
    }
    return result;
}