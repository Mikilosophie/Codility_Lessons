
struct divisor_set {
  int *divisor_pointer;
  int divisor_position;
};

int solution(int A[], int B[], int Z) {
    // write your code in C99 (gcc 6.2.0)
    int divisor_set_match = 0;
    
    struct divisor_set divisor_set_A;
    struct divisor_set divisor_set_B;
    
    divisor_set_A.divisor_pointer = (int*)malloc( Z / 2 * sizeof(int) );
    divisor_set_A.divisor_position = 0;
    
    divisor_set_B.divisor_pointer = (int*)malloc( Z / 2 * sizeof(int) );
    divisor_set_B.divisor_position = 0;
    
    int prime(int candidate);
    
    for(int i=0; i<Z; i++)
    {
        free(divisor_set_A.divisor_pointer);
        divisor_set_A.divisor_pointer = (int*)malloc( Z / 2 * sizeof(int) );
        divisor_set_A.divisor_position = 0;
        
        for(int candidate = 2; candidate <= A[i]; candidate++ )
        {
            if( ( A[i] % candidate == 0 ) && ( prime(candidate) == 1 ) )
            {
                *(divisor_set_A.divisor_pointer + divisor_set_A.divisor_position) = candidate;
                divisor_set_A.divisor_position++;
            }
            
        } //end of loop candidate in A[i]
        
        
        free(divisor_set_B.divisor_pointer);
        divisor_set_B.divisor_pointer = (int*)malloc( Z / 2 * sizeof(int) );
        divisor_set_B.divisor_position = 0;
        
        for(int candidate = 2; candidate <= B[i]; candidate++ )
        {
            if( ( A[i] % candidate == 0 ) && ( prime(candidate) == 1 ) )
            {
                *(divisor_set_B.divisor_pointer + divisor_set_B.divisor_position) = candidate;
                divisor_set_B.divisor_position++;
            }
            
        } //end of loop candidate in B[i]
        
        //if (divisor_set_A.divisor_pointer == divisor_set_B.divisor_pointer)
        if( ( divisor_set_A.divisor_position != 0 ) && ( divisor_set_A.divisor_position == divisor_set_B.divisor_position ) )
        {
            int match = 1;
            
            printf("divisor_set_A.divisor_position: %d\n", divisor_set_A.divisor_position);
            printf("divisor_set_B.divisor_position: %d\n", divisor_set_A.divisor_position);
            printf("---------\n");
            
            
            for(int p=0; p < divisor_set_B.divisor_position; p++)
            {
                if( *(divisor_set_A.divisor_pointer+p) != *(divisor_set_B.divisor_pointer+p) )   
                    {
                        match = -1;
                        break;
                    }
            }
            
            if( match == 1 )
            {
                divisor_set_match++;
            }
            
        }
        
    } //end of loop i within Z
    
    
    free(divisor_set_A.divisor_pointer);
    free(divisor_set_B.divisor_pointer);
    return divisor_set_match;
}


int prime(int candidate)
{
    for(int i=2; i<candidate; i++)
    {
        if( ( candidate % i != 0))
        {
            return -1;
        }
    }
    
    return 1;
}
