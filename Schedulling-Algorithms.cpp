#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void printProcessTimeline(int processID, float startTime, float endTime) 
{
    cout << "P" << processID << ": " << startTime << "-" << endTime << "\n";
}

void displayTimeline(int startTime, int endTime, int processId) 
{
    cout << "P" << processId << ": " << startTime << "-" << endTime << endl;
}
// FCFS Scheduling Algorithm Using Arrival Time
void fcfsScheduling() 
{
    int n, i;
    // abt time -----> finish time
    float process[500], aTime[500], bTime[500], abTime[500], wTime[500], tat_time[500];
    float aw_time = 0, atat_time = 0;

    cout << "* FCFS Scheduling Algorithm Using Arrival Time *\n";
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the Arrival time and Burst time.\n\n";
    cout << "\tA_Time B_Time\n";
    for (i = 0; i < n; i++) 
    {
         process[i] = i + 1;
        cout << "P" << i + 1 << ":\t";
        cin >> aTime[i] >> bTime[i];
    }

    cout << "\n\nProcess\tA_Time\tB_Time\n";
    for (i = 0; i < n; i++) 
    {
        cout << "P[" << i+1 << "]\t" << aTime[i] << "\t" << bTime[i] << "\n";
    }

    wTime[0] = 0;
    tat_time[0] = bTime[0];
    abTime[0] = bTime[0] + aTime[0];

    for (i = 0; i < n; i++)
     {
        abTime[i] = abTime[i - 1] + bTime[i];
        tat_time[i] = abTime[i] - aTime[i];
        wTime[i] = tat_time[i] - bTime[i];
    }

    for (i = 0; i < n; i++) 
    {
        aw_time = aw_time + wTime[i];
        atat_time = atat_time + tat_time[i];
    }
     // Call the function to print the process timeline
     cout << "Process Time line :\n";
    for (i = 0; i < n; i++) 
    {
        printProcessTimeline(i+1, abTime[i] - bTime[i], abTime[i]);
    }
    cout << "\tA_time\tB_time\tC_time\tTat_time  W_time\n";
    
    
       for (i = 0; i < n; i++)
          {
             cout << "P[" << i+1 << "]\t" << aTime[i] << "\t" << bTime[i] << "\t" << abTime[i] << "\t" << tat_time[i] << "\t" << wTime[i] << "\n";
      
         }
    cout << fixed << setprecision(2);
    cout << "\nAverage waiting time : " << aw_time / n;
    cout << "\nAverage turn around time : " << atat_time / n;
}
// Round Robin Scheduling Algorithm
// Round Robin Scheduling Algorithm
// Round Robin Scheduling Algorithm
void roundRobinScheduling() 
{
    int limit, end = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    vector<int> arrival_time_rr(10), burst_time_rr(10), temp_rr(10);
    float average_wait_time_rr, average_turnaround_time_rr;

    cout << "\nEnter Total Number of Processes for Round Robin: ";
    cin >> limit;
    x = limit;

    for (int i = 0; i < limit; i++) 
    {
        cout << "\nEnter Details of Process[" << i + 1 << "]\n";

        cout << "Arrival Time: ";
        cin >> arrival_time_rr[i];

        cout << "Burst Time: ";
        cin >> burst_time_rr[i];

        temp_rr[i] = burst_time_rr[i];
    }
//     if quantum=3
//        burst 
//     p1= 2
//     p2=5
//     p3=6
//     time line :
//       p1     p2     p3   p2     p3
//    0------2-------5----8-----10-----13
// **********
// if burst time smaller than or equal quantum busrt time still as it (dont decompose)
// **********
    cout << "\nEnter Time Quantum: ";
    cin >> time_quantum;
    cout << "\nProcess ID\t\tBurst Time\t\t\t\tTurnaround Time\t\t\t\tWaiting Time\t\n";
    int i = 0;
    for (end = 0; x != 0;) 
    {
        if (temp_rr[i] <= time_quantum && temp_rr[i] > 0) 
        {
            end += temp_rr[i];
            temp_rr[i] = 0;
            counter = 1;
            // Update the call to printProcessTimeline
            cout << "\t\t\t\t" << burst_time_rr[i] << "\t\t\t\t\t" << end - arrival_time_rr[i] << "\t\t\t\t\t" << end - arrival_time_rr[i] - burst_time_rr[i] << "\n";
            printProcessTimeline(i + 1, end - time_quantum, end);
        }
        else if (temp_rr[i] > 0) 
        {
            temp_rr[i] -= time_quantum;
            end += time_quantum;
            // Update the call to printProcessTimeline
            cout << "\t\t\t\t" << burst_time_rr[i] << "\t\t\t\t\t" << end - arrival_time_rr[i] << "\t\t\t\t\t" << end - arrival_time_rr[i] - burst_time_rr[i] << "\n";

            printProcessTimeline(i + 1, end - time_quantum, end);
        }
        if (temp_rr[i] == 0 && counter == 1) 
        {
            x--;
            cout << "\t\t\t\t" << burst_time_rr[i] << "\t\t\t\t\t" << end - arrival_time_rr[i] << "\t\t\t\t\t" << end - arrival_time_rr[i] - burst_time_rr[i] << "\n";
            wait_time += end - arrival_time_rr[i] - burst_time_rr[i];
            turnaround_time += end - arrival_time_rr[i];
            counter = 0;
        }
        if (i == limit - 1) 
        {
            i = 0;
        }
        else if (arrival_time_rr[i + 1] <= end) 
        {
            i++;
        }
        else 
        {
            i = 0;
        }
    }
    average_wait_time_rr = wait_time * 1.0 / limit;
    average_turnaround_time_rr = turnaround_time * 1.0 / limit;

    cout << "\nAverage Waiting Time for Round Robin: " << average_wait_time_rr << "\n";
    cout << "Average Turnaround Time for Round Robin: " << average_turnaround_time_rr << "\n";
}
// SJF (Non-preemptive) Scheduling Algorithm
void sjfNonPreemptiveScheduling() {
    int arrival_time_sjf[10], burst_time_sjf[10], temp_sjf[10];
    int smallest, count_sjf = 0, time_sjf, limit_sjf;
    double wait_time_sjf = 0, turnaround_time_sjf = 0, end_sjf;
    float average_waiting_time_sjf, average_turnaround_time_sjf;

    cout << "\nEnter the Total Number of Processes for SJF (Non-preemptive): ";
    cin >> limit_sjf;

    cout << "Enter Details of " << limit_sjf << " Processes\n";

    for (int i = 0; i < limit_sjf; i++) {
        cout << "Enter Arrival Time: ";
        cin >> arrival_time_sjf[i];

        cout << "Enter Burst Time: ";
        cin >> burst_time_sjf[i];

        temp_sjf[i] = burst_time_sjf[i];
    }

    burst_time_sjf[9] = 9999;

    for (time_sjf = 0; count_sjf != limit_sjf; time_sjf++) {
        smallest = 9;

        for (int i = 0; i < limit_sjf; i++) {
            if (arrival_time_sjf[i] <= time_sjf && burst_time_sjf[i] < burst_time_sjf[smallest] && burst_time_sjf[i] > 0) {
                smallest = i;
            }
        }

        burst_time_sjf[smallest]--;

        if (burst_time_sjf[smallest] == 0) {
            count_sjf++;
            end_sjf = time_sjf + 1;
            wait_time_sjf = wait_time_sjf + end_sjf - arrival_time_sjf[smallest] - temp_sjf[smallest];
            turnaround_time_sjf = turnaround_time_sjf + end_sjf - arrival_time_sjf[smallest];

            // Display the timeline for the process
            displayTimeline(time_sjf - temp_sjf[smallest] + 1, end_sjf, smallest + 1);
        }
    }

    average_waiting_time_sjf = wait_time_sjf / limit_sjf;
    average_turnaround_time_sjf = turnaround_time_sjf / limit_sjf;

    cout << "\nAverage Waiting Time for SJF (Non-preemptive): " << average_waiting_time_sjf << "\n";
    cout << "Average Turnaround Time for SJF (Non-preemptive): " << average_turnaround_time_sjf << "\n";

}


// SJF (Preemptive) Scheduling Algorithm
void sjfPreemptiveScheduling()
 {
    int arrival_time_sjf_pre[10], burst_time_sjf_pre[10], temp_sjf_pre[10];
    int smallest_pre, count_sjf_pre = 0, time_sjf_pre, limit_sjf_pre;
    double wait_time_sjf_pre = 0, turnaround_time_sjf_pre = 0, end_sjf_pre;
    float average_waiting_time_sjf_pre, average_turnaround_time_sjf_pre;
    cout << "\nEnter the Total Number of Processes for SJF (Preemptive): ";
    cin >> limit_sjf_pre;
    cout << "Enter Details of " << limit_sjf_pre << " Processes\n";
    for (int i = 0; i < limit_sjf_pre; i++) 
    {
        cout << "Enter Arrival Time: ";
        cin >> arrival_time_sjf_pre[i];

        cout << "Enter Burst Time: ";
        cin >> burst_time_sjf_pre[i];

        temp_sjf_pre[i] = burst_time_sjf_pre[i];
    }
    burst_time_sjf_pre[9] = 9999;

    for (time_sjf_pre = 0; count_sjf_pre != limit_sjf_pre; time_sjf_pre++)
     {
        smallest_pre = 9;

        for (int i = 0; i < limit_sjf_pre; i++) 
        {
            if (arrival_time_sjf_pre[i] <= time_sjf_pre && burst_time_sjf_pre[i] < burst_time_sjf_pre[smallest_pre] && burst_time_sjf_pre[i] > 0)
             {
                smallest_pre = i;
            }
        }
        burst_time_sjf_pre[smallest_pre]--;
        if (burst_time_sjf_pre[smallest_pre] == 0) 
        {
            count_sjf_pre++;
            end_sjf_pre = time_sjf_pre + 1;
            wait_time_sjf_pre = wait_time_sjf_pre + end_sjf_pre - arrival_time_sjf_pre[smallest_pre] - temp_sjf_pre[smallest_pre];
            turnaround_time_sjf_pre = turnaround_time_sjf_pre + end_sjf_pre - arrival_time_sjf_pre[smallest_pre];
        }
    }
    average_waiting_time_sjf_pre = wait_time_sjf_pre / limit_sjf_pre;
    average_turnaround_time_sjf_pre = turnaround_time_sjf_pre / limit_sjf_pre;
    cout << "\nAverage Waiting Time for SJF (Preemptive): " << average_waiting_time_sjf_pre << "\n";
    cout << "Average Turnaround Time for SJF (Preemptive): " << average_turnaround_time_sjf_pre << "\n";
}
// Priority (Non-preemptive) Scheduling Algorithm
void priorityNonPreemptiveScheduling()
 {
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10], p[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;
    cout << "\nEnter the number of Processes: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "\nEnter arrival time of process: ";
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        cout << "\nEnter burst time of process: ";
        cin >> b[i];
    }
    for (i = 0; i < n; i++) {
        cout << "\nEnter priority of process: ";
        cin >> p[i];
    }
    for (i = 0; i < n; i++)
        x[i] = b[i];

    p[9] = -1;
    for (time = 0; count != n; time++) 
    {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (a[i] <= time && p[i] > p[smallest] && b[i] > 0)
                smallest = i;
        }
        time += b[smallest] - 1;
        b[smallest] = -1;
        count++;
        end = time + 1;
        completion[smallest] = end;
        waiting[smallest] = end - a[smallest] - x[smallest];
        turnaround[smallest] = end - a[smallest];
        // Display the timeline for the process
        displayTimeline(time - x[smallest] + 1, end, smallest + 1);
    }
    cout << "Process" << "\t" << "burst-time" << "\t" << "arrival-time" << "\t" << "waiting-time" << "\t" << "turnaround-time" << "\t" << "completion-time" << "\t" << "Priority" << endl;
    for (i = 0; i < n; i++) 
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << "\t\t" << p[i] << endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout << "\n\nAverage waiting time =" << avg / n;
    cout << "  Average Turnaround time =" << tt / n << endl;
}
void priorityPreemptiveScheduling() 
{
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10], p[10];
    int i, j, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;

    cout << "\nEnter the number of Processes: ";
    cin >> n;
    for (i = 0; i < n; i++) 
    {
        cout << "\nEnter arrival time of process: ";
        cin >> a[i];
    }
    for (i = 0; i < n; i++) 
    {
        cout << "\nEnter burst time of process: ";
        cin >> b[i];
    }
    for (i = 0; i < n; i++) 
    {
        cout << "\nEnter priority of process: ";
        cin >> p[i];
    }
    for (i = 0; i < n; i++)
        x[i] = b[i];
    p[9] = -1;
    for (time = 0; count != n; time++) 
    {
        smallest = 9;
        for (i = 0; i < n; i++)
         {
            if (a[i] <= time && p[i] > p[smallest] && b[i] > 0)
                smallest = i;
        }
        b[smallest]--;

        if (b[smallest] == 0) 
        {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout << "Process" << "\t" << "burst-time" << "\t" << "arrival-time" << "\t" << "waiting-time" << "\t" << "turnaround-time" << "\t" << "completion-time" << "\t" << "Priority" << endl;
    for (i = 0; i < n; i++) 
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << waiting[i] << "\t\t" << turnaround[i] << "\t\t" << completion[i] << "\t\t" << p[i] << endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout << "\n\nAverage waiting time =" << avg / n;
    cout << "  Average Turnaround time =" << tt / n << endl;
}
int main() 
{
    int choice;
    cout << "Choose scheduling algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. Round Robin\n";
    cout << "3. SJF (Non-preemptive)\n";
    cout << "4. SJF (Preemptive)\n";
    cout << "5. Priority (Non-preemptive)\n";
    cout << "6. Priority (preemptive)\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) 
    {
    case 1:
        fcfsScheduling();
        break;
    case 2:
        roundRobinScheduling();
        break;
    case 3:
        sjfNonPreemptiveScheduling();
        break;
    case 4:
        sjfPreemptiveScheduling();
        break;
    case 5:
        priorityNonPreemptiveScheduling();
        break;
    case 6:
        priorityPreemptiveScheduling();
        break;
    default:
        cout << "Invalid choice. Exiting.\n";
        return 1;
    }
    return 0;
}