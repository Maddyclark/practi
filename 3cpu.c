#include <stdio.h> 
int arrival_t[100], burst_t[100], ct[100], temp[100]; 

int main()  
{ 
    int i, smallest, count = 0, j, n; 
    double avg_wt = 0, avg_tat = 0, end; 

    printf("\nEnter the Total Number of Processes: "); 
    scanf("%d", &n);  

    printf("\nEnter Details of %d Processes", n); 
    for(i = 0; i < n; i++) 
    { 
        printf("\nEnter Arrival Time for P%d: ", i+1); 
        scanf("%d", &arrival_t[i]); 
        printf("Enter Burst Time for P%d: ", i+1); 
        scanf("%d", &burst_t[i]);  
        temp[i] = burst_t[i]; 
    } 
    
    burst_t[99] = 1000;  

    for(i = 0; count != n; i++) 
    { 
        smallest = 99; 
        for(j = 0; j < n; j++) 
        { 
            if(arrival_t[j] <= i && burst_t[j] < burst_t[smallest] && burst_t[j] > 0) 
            { 
                smallest = j; 
            } 
        } 
        
        burst_t[smallest]--; 
        if(burst_t[smallest] == 0) 
        { 
            count++; 
            ct[smallest] = i + 1; 
        } 
    } 

    for(i = 0; i < n; i++) 
    { 
        int TAT = ct[i] - arrival_t[i]; 
        avg_tat += TAT; 
        avg_wt += TAT - temp[i]; 
    }       

    printf("Average Turnaround Time: %lf\n", avg_tat / n); 
    printf("Average Waiting Time: %lf\n", avg_wt / n); 
    
    return 0; 
} 


--------------------------------------------------------------------------------------------------------------------------------------------------------



#include <stdio.h>  

int main()  
{  
    int i, limit, total = 0, x, counter = 0, time_quantum;  
    int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];  
    float average_wait_time, average_turnaround_time;  

    printf("\nEnter Total Number of Processes:\t");  
    scanf("%d", &limit);  
    x = limit;  
    
    for (i = 0; i < limit; i++)  
    {  
        printf("\nEnter Details of Process[%d]\n", i + 1);  
        printf("Arrival Time:\t");  
        scanf("%d", &arrival_time[i]);  
        printf("Burst Time:\t");  
        scanf("%d", &burst_time[i]);  
        temp[i] = burst_time[i];  
    }  
    
    printf("\nEnter Time Quantum:\t");  
    scanf("%d", &time_quantum);  
    
    printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");  
    
    for (total = 0, i = 0; x != 0;)  
    {  
        if (temp[i] <= time_quantum && temp[i] > 0)  
        {  
            total = total + temp[i];  
            temp[i] = 0;  
            counter = 1;  
        }  
        else if (temp[i] > 0)  
        {  
            temp[i] = temp[i] - time_quantum;  
            total = total + time_quantum;  
        }  
        
        if (temp[i] == 0 && counter == 1)  
        {  
            x--;  
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);  
            
            wait_time = wait_time + total - arrival_time[i] - burst_time[i];  
            turnaround_time = turnaround_time + total - arrival_time[i];  
            counter = 0;  
        }  
        
        if (i == limit - 1)  
        {  
            i = 0;  
        }  
        else if (arrival_time[i + 1] <= total)  
        {  
            i++;  
        }  
        else  
        {  
            i = 0;  
        }  
    }  
    
    average_wait_time = wait_time * 1.0 / limit;  
    average_turnaround_time = turnaround_time * 1.0 / limit;  
    printf("\n\nAverage Waiting Time:\t%f", average_wait_time);  
    printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);  
    
    return 0;  
}
