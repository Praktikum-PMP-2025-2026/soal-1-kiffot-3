#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct pasien {  
    char nama[50];  
    int d;  //d = durasi
    struct pasien* next;
}  pasien;


typedef struct antri {
    int panjang;
    pasien* front;
    pasien* rear;
} antri;

int isEmpty(antri* antrian) {
    return antrian->front == NULL;
}

pasien* newNode(int data, char nama[]) {
    pasien* node = (pasien*)malloc(sizeof(pasien));
    node->d = data;
    strcpy(node->nama, nama);
    node->next = NULL;
    return node;
}

antri* createQueue() {
    antri* antrian = (antri*)malloc(sizeof(antri));
    antrian->front = antrian->rear = NULL;
    antrian->panjang = 0;
    return antrian;
}
void enqueue(antri* antrian, char nama[],int data) {
    pasien* node = newNode(data, nama);
    if (isEmpty(antrian)) {
        antrian->front = antrian->rear = node;
    } else {
        antrian->rear->next = node;
        antrian->rear = node;
    }
}


int main() {
    int n=0;
    scanf("%d", &n);
    char namabaru[50];
    int dbaru;
    int dcumul;
    antri*  antrian = createQueue();
    for(int i = 0; i<n; i++){
        scanf("%s", namabaru);
        scanf("%d", &dbaru);
        dcumul+=dbaru;
        enqueue(antrian, namabaru, dcumul);
    }
    int totalwait;
    printf("ORDER");
    for(int i = 0; i<n; i++){
        printf(" %s", antrian->front->nama);
        totalwait += antrian->front->d;
        if (i!=n-1){
            antrian->front=antrian->front->next;    
        }
     
    }
    totalwait -= antrian->front->d;
    printf ("\nWAIT %d", totalwait);
}
