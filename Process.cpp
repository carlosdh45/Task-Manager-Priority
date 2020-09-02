

#include "Process.h"

void push(Node *&head, const Process& newProcess) {
    Node* newNode = new Node;
    newNode->data= newProcess;
    Node *aux1 = head;
    Node *aux2;

    while (aux1 != nullptr && aux1->data.priority < newProcess.priority) {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (head == aux1) {
        head = newNode;
    } else {
        aux2->next = newNode;
    }

    newNode->next = aux1;
}

void sort(Node *&head){
    int swapped;
    Node *left;
    Node *right = nullptr;

    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.time_arrived > left->next->data.time_arrived && left->data.priority == left->next->data.priority) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}

void swapNodes(Node *node1, Node *node2) {
    Process temp = node1->data;
    node1->data = node2 -> data;
    node2->data = temp;
}

/*void pop(Node *&head) {
    Node *aux;
    aux = head;
    head = aux->next;
    delete aux;
}
void popAll(Node *&head) {
    Node *aux;
    while (head != nullptr) {
        aux = head;
        head = aux->next;
        delete aux;
    }
}*/

void simulate(Node *&head, int cpu) {
    Node *aux;
    aux =head;
    int execution_time=0;
    cout << "Process     Priority    CPU     Status     Time arrived     Waiting time     Succes time" << endl;
    while(aux != nullptr) {
        if(aux->data.cpu != 0)
            aux->data.status = "execution";
        if (aux->data.cpu <= 4 && aux->data.status != "success") {
            print(aux->data);
            cpu -= aux->data.cpu;
            aux->data.waiting_time += execution_time;
            execution_time += aux->data.cpu;
            aux->data.cpu = 0;
            aux->data.status = "success";
            aux->data.success_time += aux->data.waiting_time;
            print(aux->data);
        } else if (aux->data.cpu > 0) {
            aux->data.waiting_time += execution_time;
            print(aux->data);
            aux->data.status = "blocked";
            aux->data.cpu -= 4;
            aux->data.success_time += 4;
            if(aux->data.cpu == 0)
                aux->data.status = "success";
            cpu -= 4;
            execution_time += 4;
            print(aux->data);
        }
        aux = aux->next;
        if(aux == nullptr){
            aux = head;
            execution_time = 0;
        }
        if(cpu == 0) {
            aux->data.status = "success";
            break;
        }
    }
}

void show(Node *head) {
    Node *current = head;
    cout << "Process     Priority    CPU     Status     Time arrived     WaitingT     SuccesT" << endl;
    while (current != nullptr) {
        print(current->data);
        current = current->next;
    }
}

void print(Process process) {
    cout << process.name << "              " << process.priority << "         " << process.cpu << "      "
         <<  process.status << spaces(process.status) << process.time_arrived  << "               " << process.waiting_time
         << "           " << process.success_time << endl;
}

string spaces(const string& word) {
    if(word == "success" || word == "blocked") {
        return "          ";
    } else if(word == "ready") {
        return "            ";
    }
    return "        ";
}
