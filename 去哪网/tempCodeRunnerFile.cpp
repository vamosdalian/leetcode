int result = 1;
    int k = n-m;
    for(int i = n; i > 1; i--){
        result *= i;
    }
    for(int i = k; i >= 1; i--){
        result /= i;
    }
    for(int i = m; i >1; i--){
        result /= i;
    }
    return result;