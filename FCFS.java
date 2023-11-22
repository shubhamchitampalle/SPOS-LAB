// package OOPS_codes.TYSPOS;
import java.util.Scanner;

class Process {
    String name;
    int arrivalTime;
    int burstTime;

    public Process(String name, int arrivalTime, int burstTime) {
        this.name = name;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
    }
}

public class FCFS {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int n = scanner.nextInt();

        Process[] processes = new Process[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter the name of process " + (i + 1) + ": ");
            String name = scanner.next();
            System.out.print("Enter the arrival time of process " + (i + 1) + ": ");
            int arrivalTime = scanner.nextInt();
            System.out.print("Enter the burst time of process " + (i + 1) + ": ");
            int burstTime = scanner.nextInt();
            processes[i] = new Process(name, arrivalTime, burstTime);
        }

        // Sort the processes by arrival time
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                    // Swap the processes
                    Process temp = processes[j];
                    processes[j] = processes[j + 1];
                    processes[j + 1] = temp;
                }
            }
        }

        int currentTime = 0;
        double totalTurnaroundTime = 0;
        double totalWaitingTime = 0;

        System.out.println("\nProcess Execution Order:");
        System.out.println("----------------------------");

        for (int i = 0; i < n; i++) {
            Process currentProcess = processes[i];
            System.out.println("Time " + currentTime + ": Executing " + currentProcess.name);

            // Calculate waiting time for the current process
            int waitingTime = currentTime - currentProcess.arrivalTime;
            if (waitingTime < 0) {
                waitingTime = 0;
            }

            totalWaitingTime += waitingTime;
            currentTime += currentProcess.burstTime;

            // Calculate turnaround time for the current process
            int turnaroundTime = waitingTime + currentProcess.burstTime;
            totalTurnaroundTime += turnaroundTime;
        }

        double averageTurnaroundTime = totalTurnaroundTime / n;
        double averageWaitingTime = totalWaitingTime / n;

        System.out.println("\nAverage Turnaround Time: " + averageTurnaroundTime);
        System.out.println("Average Waiting Time: " + averageWaitingTime);

        scanner.close();
    }
}
