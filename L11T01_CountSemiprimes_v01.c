#include <math.h>

int Total;

struct Results solution(int N, int P[], int Q[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.A = (int *)malloc( 2 * N * sizeof(int) );
    result.M = 0;
    
    Total = N;
    
    int primeCounter;
    
    int semiprime(int candidate);
    
    for(int K=0; K<M; K++)
    {
        primeCounter=0;
            
        for(int PK = P[K]; PK <= Q[K]; PK++)
        {
            //printf("(PK): %d\n", PK);
            //printf("semiprime(PK): %d\n", semiprime(PK));
            
            if( semiprime(PK) == 1)
            {
                primeCounter++;
                //printf("primeCounter: %d\n", primeCounter);
            }           
            
        }
        
        *(result.A+result.M) = primeCounter;
        
        result.M++;    
    
    }
    
    //free(result.A);  // result should be initialted in other function, so result.A can be freed out there.   
    return result;
}

int semiprime(int candidate)
{	
	int prime(int n);
	
	for(int a=2; a<=Total; a++)
	{
		
		if( ( prime(a)==1 ) && ( ( candidate % a ) == 0 ) )
		{
		
    		for(int b=2; b<=Total; b++)
    		{
    		    if( ( prime(b)==1 ) && (a * b == candidate) )    		    
    		        return 1;
    		    
    		}
		
		}
		
		
	} //end of a loop
	return -1;
}

int prime(int n)
{
	for(int divisor=2; divisor<n; divisor++)
	{
		//printf("n: %d\n", n);
		//printf("divisor: %d\n", divisor);
		//printf("n/divisor: %d\n", n%divisor);
		
			
		if(n % divisor == 0)
			return -1;
	}
	
	return 1;
}
