#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int empty() {
    return front == -1;
}

int size() {
    if(front == -1) return 0;
    return rear - front + 1;
}

void push_front(int val) {
    if(front == -1) {
        front = rear = 0;
        dq[front] = val;
    }
    else if(front > 0) {
        dq[--front] = val;
    }
    else {
        printf("Overflow\n");
    }
}

void push_back(int val) {
    if(front == -1) {
        front = rear = 0;
        dq[rear] = val;
    }
    else if(rear < MAX-1) {
        dq[++rear] = val;
    }
    else {
        printf("Overflow\n");
    }
}

void pop_front() {
    if(empty()) {
        printf("-1\n");
        return;
    }
    front++;
    if(front > rear)
        front = rear = -1;
}

void pop_back() {
    if(empty()) {
        printf("-1\n");
        return;
    }
    rear--;
    if(rear < front)
        front = rear = -1;
}

int get_front() {
    if(empty()) return -1;
    return dq[front];
}

int get_back() {
    if(empty()) return -1;
    return dq[rear];
}

void display() {
    if(empty()) {
        printf("Deque Empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    display();

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    return 0;
}