
struct Results solution(int A[], int N) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.C = (int*)malloc(N*sizeof(int));
    result.L = 0;
    
    int non_divisor;
    
    for(int i=0; i<N; i++)
    {
        non_divisor = 0;
        
        for(int j=0; j<N; j++)
        {
        
            if( A[i] % A[j] != 0 )
            {
                non_divisor++;                    
            }
            
        }
        
        *(result.C+result.L) = non_divisor;
        result.L++;
        
    }
    
    return result;
}
