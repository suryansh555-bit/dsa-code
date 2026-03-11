#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    if(size == MAX)
        return;

    int i = size - 1;

    while(i >= 0 && pq[i] > x) {
        pq[i+1] = pq[i];
        i--;
    }

    pq[i+1] = x;
    size++;
}

void delete() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i = 1; i < size; i++)
        pq[i-1] = pq[i];

    size--;
}

void peek() {
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main() {

    int N;
    char op[10];
    int x;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {

        scanf("%s", op);

        if(op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        }
        else if(op[0] == 'd') {
            delete();
        }
        else if(op[0] == 'p') {
            peek();
        }
    }

    return 0;
}