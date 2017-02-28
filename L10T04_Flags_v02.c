
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int maximum = 0;
    int *peakPointer;
    peakPointer = (int *)malloc( N/3 * sizeof(int));
    int peakNumber = 0;
    int flagCarry;
    
    for(int p=1; p<N-1; p++)
    {
        if( ( A[p-1] < A[p]) && ( A[p] > A[p+1]) )
        {
            *(peakPointer+peakNumber) = p;
            peakNumber++;   
            //printf("*(peakPointer+peakNumber): %d\n", *(peakPointer+peakNumber-1));
        }
                
    } //end of choosing peaks
    
    if(peakNumber == 1)
        maximum = 1;
    
    if(peakNumber > 1)
    {
        
        
        for(int flagNumber = peakNumber; flagNumber > 0 ; flagNumber--)   // flagNumber between [1....peakNumber]
        {
            flagCarry = 0;
            
            for(int peakPosition=flagNumber-1; peakPosition >=0 ; peakPosition--)
            {
                //printf("right: %d\n", *(peakPointer + flagNumber -1  ));
                //printf("left: %d\n", *(peakPointer +  peakPosition ) );
                //printf("flagNumber: %d\n", flagNumber );
                    
                
                if( ( *(peakPointer + flagNumber -1 ) - *(peakPointer +  peakPosition) ) >= flagNumber)
                {
                    flagCarry++;
                }
                
            }
            
            //printf("flagCarry: %d\n", flagCarry);
            
            if (maximum < flagCarry)
	            maximum = flagCarry;
        
        }
        
    }
    
    free(peakPointer);
    return maximum;
}

