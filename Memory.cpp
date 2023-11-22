#include<iostream>
#include<iomanip>
#include<string>
#include<numeric>
#include <bits/stdc++.h> 
using namespace std;

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    int totalMemoryUsed = 0;
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1) bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j]) bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
            totalMemoryUsed += processSize[i];
        }
    }
    cout << "\nProcess No.\tSize\tBlock no.\tStatus\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << processSize[i] << "\t";
        if (allocation[i] != -1) {cout << allocation[i] + 1 << "\t Allocated!";}
        else {cout << "Empty \tNot Allocated";}
        cout << endl;
    }
    cout << "Total Memory Used: " << totalMemoryUsed << endl;

}

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    int totalMemoryUsed = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                totalMemoryUsed += processSize[i];
                break;
            }
        }
    }
    cout << "\nProcess No.\tSize\tBlock no.\tStatus\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << processSize[i] << "\t";
        if (allocation[i] != -1) 
        {cout << allocation[i] + 1 << "\t Allocated!";
        }
        else {cout << "Empty \tNot Allocated";}
        cout << endl;
    }
    cout << "Total Memory Used: " << totalMemoryUsed << endl;
}

void NextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], j = 0, t = m - 1;
    memset(allocation, -1, sizeof(allocation));
    int totalMemoryUsed = 0;
    for(int i = 0; i < n; i++){
        while (j < m){
            if(blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                totalMemoryUsed += processSize[i];
                t = (j - 1) % m;
                break;
            } 
            if (t == j){
                t = (j - 1) % m;
                break;
            }
            j = (j + 1) % m;
        }
    cout << "\nProcess No.\tSize\tBlock no.\tStatus\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << processSize[i] << "\t";
        if (allocation[i] != -1) {cout << allocation[i] + 1 << "\t Allocated!";}
        else {cout << "Empty \tNot Allocated";}
        cout << endl;
    }
    cout << "Total Memory Used: " << totalMemoryUsed << endl;
}
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    int totalMemoryUsed = 0;
    for (int i=0; i<n; i++) {
        int wstIdx = -1;
        for (int j=0; j<m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (wstIdx == -1) wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j]) wstIdx = j;
            }
        }
        if (wstIdx != -1) {
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
            totalMemoryUsed += processSize[i];
        }
    }
    cout << "\nProcess No.\tSize\tBlock no.\tStatus\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << processSize[i] << "\t";
        if (allocation[i] != -1) {cout << allocation[i] + 1 << "\t Allocated!";}
        else {cout << "Empty \tNot Allocated";}
        cout << endl;
    }
    cout << "Total Memory Used: " << totalMemoryUsed << endl;
}

int main() {
    int n, m, processSize[20], blockSize[20], choice;
    while (1) {
        cout << "\nMENU\n\n";
        cout << "1. Best Fit\n2. First Fit\n3. Next Fit\n4. Worst Fit\n5. Exit\n\n";
        cout << "Enter your choice : ";
        cin >> choice;
        if(choice == 5){
            exit(0);
        }
        cout << "\nEnter number of processes : ";
        cin >> n;
        cout << "\nEnter the size of the processes \n";
        for (int i = 0; i < n; i++) {
            cout << "Process no. " << i+1 << " : ";
            cin >> processSize[i];
        }
        cout << "\nEnter number of blocks : ";
        cin >> m;
        cout << "\nEnter the size of the blocks\n"<<endl;
        for (int i = 0; i < m; i++) {
            cout << "Block no. " << i+1 << " : ";
            cin >> blockSize[i];
        }
        switch (choice) {
            case 1: {
                bestFit(blockSize, m, processSize, n);
                break;
            }
            case 2: {
                firstFit(blockSize, m, processSize, n);
                break;
            }
            case 3: {
                NextFit(blockSize, m, processSize, n);
                break;
            }
            case 4: {
                worstFit(blockSize, m, processSize, n);
                break;
            }
            default: break;
        }
    }
    return 0;
}

