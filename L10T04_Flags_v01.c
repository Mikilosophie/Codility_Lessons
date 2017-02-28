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
        }
                
    } //end of choosing peaks
    
    if(peakNumber == 1)
        maximum = 1;
    
    if(peakNumber > 1)
    {
        
        
        for(int flagNumber=1; flagNumber <= peakNumber; flagNumber++)   // flagNumber between [1....peakNumber]
        {
            flagCarry = 0;
            
            for(int peakPosition=0; peakPosition < (flagNumber); peakPosition++)
            {
                if( ( *(peakPointer + peakPosition + 1 - 1) - *(peakPointer + peakPosition - 1) ) >= flagNumber)
                {
                    flagCarry++;
                }
                
            }
            
            if (maximum < flagCarry)
	            maximum = flagCarry;
        
        }
        
    }
    
    
    return maximum;
}
