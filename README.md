# S4-OS-KTU-Lab
# CPU Scheduling Algorithms
This repository contains implementations of various CPU scheduling algorithms in C. These algorithms simulate how an operating system allocates CPU time to processes.

## Algorithms Implemented
1. **First-Come, First-Served (FCFS)** - A non-preemptive algorithm where processes are executed in the order they arrive in the ready queue.
2. **Shortest Job First (SJF)** - A non-preemptive algorithm that selects the process with the shortest burst time among all available processes.
3. **Additional Scheduling Algorithms** - More algorithms to be added soon.

## Features
- Process simulation with arrival time and burst time
- Calculation of important metrics:
  - Waiting time
  - Turnaround time
  - Completion time
- Visual Gantt chart representation of the scheduling
- Average waiting time and turnaround time calculations

## How to Run
### Prerequisites
- GCC compiler or any C compiler

### Compilation and Execution
```bash
# Compile the FCFS program
gcc fcfs.c -o fcfs
# Run the FCFS program
./fcfs

# Compile the SJF program
gcc sjf.c -o sjf
# Run the SJF program
./sjf
```

## Input Format
For each process, you'll need to enter:
1. Process name (e.g., P1, P2, etc.)
2. Arrival time (when the process arrives in the ready queue)
3. Burst time (execution time required by the process)

## Output
1. Gantt Chart visualization showing the execution sequence
2. Average Waiting Time
3. Average Turnaround Time

## Example
```
Enter the number of processes: 3
Enter the process name: P1
Enter the arrival time: 0
Enter the burst time: 5
Enter the process name: P2
Enter the arrival time: 1
Enter the burst time: 3
Enter the process name: P3
Enter the arrival time: 2
Enter the burst time: 8

**Gant Chart**
-----------------
|P1    |P2  |P3       |
-----------------
0     5    8         16

Average Waiting time: 4.333333
Average Turnaround time: 9.666667
```

## SJF Implementation
The Shortest Job First implementation includes:
- Non-preemptive scheduling
- Selection of processes based on shortest burst time
- Tie-breaking based on arrival time when burst times are equal
- Proper handling of idle CPU time when no process is available
- Detailed Gantt chart visualization

## Terminology
- **Arrival Time (AT)**: Time at which the process arrives in the ready queue
- **Burst Time (BT)**: Time required by a process for CPU execution
- **Completion Time (CT)**: Time at which process completes its execution
- **Turnaround Time (TT)**: Time difference between completion time and arrival time (TT = CT - AT)
- **Waiting Time (WT)**: Time difference between turnaround time and burst time (WT = TT - BT)

## Contributing
Feel free to contribute by:
- Adding new scheduling algorithms
- Fixing bugs or improving the code
- Enhancing the visualization
- Improving documentation

## License
This project is open source and available under the MIT License.

## Contact
If you have any questions or suggestions, feel free to open an issue or submit a pull request.
