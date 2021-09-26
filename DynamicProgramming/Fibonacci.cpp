int fib(int n) {
        if (n <= 1)
            return n;
        
        vector<int> fibSeries(n+1,0);
        fibSeries[0] = 0;
        fibSeries[1] = 1;
        
        for (int i = 2; i <=n ; i++)
        {
            fibSeries[i] = fibSeries[i-1] + fibSeries[i-2];
        }
        
        return fibSeries[fibSeries.size()-1];
    }
