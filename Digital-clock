#include <stdio.h>         // For printf()
#include <time.h>          // For time(), localtime(), struct tm
#include <stdbool.h>       // For bool, true, false
#include <unistd.h>        // For sleep() on Unix/Linux (use windows.h for Sleep(milliseconds) on Windows)

// ----------------------
// DIGITAL CLOCK PROGRAM
// ----------------------

int main()
{
	
    
    time_t rawtime = 0;        // Variable to store the current time in "epoch" format (seconds since Jan 1, 1970)
    struct tm *pTime = NULL;   // Pointer to a structure holding broken-down time (hour, minute, second)
    bool isRunning = true;     // Control variable for keeping the clock running
    
    printf("DIGITAL CLOCK\n");
    
    // Loop runs until isRunning becomes false (in this case, forever)
    while(isRunning){
        
        // Get current time in raw (epoch) format
        time(&rawtime);
        
        // Convert raw time into human-readable components (hour, min, sec)
        pTime = localtime(&rawtime);
        
        // Print time in HH:MM:SS format
        // \r moves the cursor back to the start of the line so the time updates in place
        printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        
        // Force immediate display update (otherwise, printf may wait until newline)
        fflush(stdout);
        
        // Pause for 1 second before showing the next update
        sleep(1);  // On Windows, use Sleep(1000) instead
    }
    
    
	return 0;  // End of program
}
