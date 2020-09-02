
#ifndef TASKMANAGER_PROCESS_H
#define TASKMANAGER_PROCESS_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

struct Process {
    char name[30];
    string status;
    int priority;
    int cpu;
    int time_arrived;
    int waiting_time;
    int success_time;
};

struct Node {
    Process data;
    struct Node *next{};
};

void show(Node *);
void push(Node *&,const Process&);
void sort(Node *&);
//void pop(Node *&);
//void popAll(Node *&);
void swapNodes(Node *, Node *);
void simulate(Node *&, int);
void print(Process);
string spaces(const string&);

#endif //TASKMANAGER_PROCESS_H
