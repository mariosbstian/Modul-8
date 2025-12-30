# <h1 align="center">Laporan Praktikum Modul (8)</h1>
<p align="center">Mario Sebastian Barus</p>

## Dasar Teori
Queue adalah struktur data yang bekerja dengan aturan **FIFO**, yaitu data yang masuk lebih dulu akan keluar lebih dulu. Queue memiliki dua penunjuk, **front** di bagian depan dan **rear** di bagian belakang. Operasi utamanya adalah **enqueue** untuk menambah data dan **dequeue** untuk menghapus data. Queue dapat dibuat menggunakan array atau linked list, dan dapat dikembangkan menjadi **circular queue** agar penggunaan memori lebih efisien.
## Guided 

### main.cpp
```C++

#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}

```
### queue.cpp
```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}
```
### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif
```

## Guided 1

### main.cpp
```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}

```
### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void createQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama); 
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```



## Unguided 

### 1. [main1.cpp]

```C++
#include <iostream>
#include "no1.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------------" << endl;
    cout << " H - T \t | Queue Info" << endl;
    cout << "----------------------------" << endl;

    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    return 0;
}

```
Kode ini merupakan program utama yang berfungsi untuk menjalankan dan menampilkan proses operasi queue melalui penambahan dan penghapusan data.
#### Full code Screenshot:
<img width="592" height="619" alt="image" src="https://github.com/user-attachments/assets/31d9ba64-bf25-4ad9-b695-25fa7074dc81" />

### [no1.cpp]

```C++
#include "no1.h"

void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.front == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.rear == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.front = 0;
    }

    Q.rear++;
    Q.data[Q.rear] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype hasil = Q.data[Q.front];

    for (int i = Q.front; i < Q.rear; i++) {
        Q.data[i] = Q.data[i + 1];
    }

    Q.rear--;

    if (Q.rear < Q.front) {
        Q.front = -1;
        Q.rear = -1;
    }

    return hasil;
}

void printInfo(Queue Q) {
    cout << Q.front << " - " << Q.rear << " \t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.front; i <= Q.rear; i++) {
        cout << Q.data[i] << " ";
    }
    cout << endl;
}

```

Kode ini merupakan file implementasi yang menangani seluruh operasi queue, mulai dari inisialisasi, pengecekan kondisi kosong dan penuh, proses penambahan dan penghapusan data, hingga penampilan isi queue beserta informasi posisi elemen.
#### Full code Screenshot:
<img width="337" height="377" alt="image" src="https://github.com/user-attachments/assets/4f480165-f11a-4bf4-afea-2c491786c7f2" />
<img width="337" height="377" alt="image" src="https://github.com/user-attachments/assets/5b554de3-e439-4b31-8f55-de50aa8d0192" />



### [no1.h]

```C++
#ifndef NO1_H
#define NO1_H

#include <iostream>
using namespace std;

#define MAX 10
typedef int infotype;

struct Queue {
    infotype data[MAX];
    int front;
    int rear;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

#### Output:
<img width="405" height="187" alt="image" src="https://github.com/user-attachments/assets/297fc8f0-7daa-4d2e-9075-bb11f7dfaed1" />

Kode ini merupakan file header yang mendefinisikan struktur data queue beserta deklarasi fungsi-fungsi utama untuk pengelolaan data, seperti inisialisasi, pengecekan kondisi, penambahan, penghapusan, dan penampilan isi queue.
#### Full code Screenshot:
<img width="332" height="305" alt="image" src="https://github.com/user-attachments/assets/28f5ac7c-815d-4b1f-b33f-c5b9a79247d6" />

### 2. [main2.cpp]

```C++
#include <iostream>
#include "no2.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Queue Q;
    createQueue(Q);

    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    enqueue(Q, 4);
    printInfo(Q);

    dequeue(Q);
    printInfo(Q);

    return 0;
}

```
Kode ini merupakan program utama yang digunakan untuk menjalankan dan menampilkan operasi queue, mulai dari inisialisasi, penambahan data, penghapusan data, hingga melihat kondisi queue setelah setiap proses.
#### Full code Screenshot:
<img width="453" height="464" alt="image" src="https://github.com/user-attachments/assets/fcad21df-7f32-4f79-b38e-fb6c48dfc044" />

### [no2.cpp]

```C++
#include <iostream>
#include "no2.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear  = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.front == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.rear + 1) % MAX == Q.front);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.front = 0;
        Q.rear  = 0;
    } else {
        Q.rear = (Q.rear + 1) % MAX;
    }

    Q.buffer[Q.rear] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1;
    }

    infotype hasil = Q.buffer[Q.front];

    if (Q.front == Q.rear) {
        Q.front = -1;
        Q.rear  = -1;
    } else {
        Q.front = (Q.front + 1) % MAX;
    }

    return hasil;
}

void printInfo(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << "-1 - -1\t| empty queue" << endl;
        return;
    }

    cout << Q.front << " - " << Q.rear << "\t| ";

    int idx = Q.front;
    while (true) {
        cout << Q.buffer[idx] << " ";
        if (idx == Q.rear) break;
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}

```

Kode ini merupakan file implementasi yang menangani cara kerja queue berbentuk circular, mulai dari membuat queue kosong, menambah dan menghapus data, hingga menampilkan isi queue sesuai urutan penyimpanannya.
#### Full code Screenshot:
<img width="357" height="429" alt="image" src="https://github.com/user-attachments/assets/ccbc96b5-5890-4ac3-b2ec-4df6aad82781" />
<img width="398" height="460" alt="image" src="https://github.com/user-attachments/assets/643ba80b-6ac2-4381-8c56-bf2026aade9d" />


### [no2.h]

```C++
#ifndef NO2_H
#define NO2_H

#define MAX 5
typedef int infotype;

struct Queue {
    infotype buffer[MAX];
    int front;
    int rear;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

```

#### Output:
<img width="354" height="145" alt="image" src="https://github.com/user-attachments/assets/6eff4cac-e2a3-4cdb-b07c-def237c98801" />

Kode ini merupakan file header yang digunakan sebagai dasar pengelolaan queue berbasis circular. Di dalamnya didefinisikan struktur queue, kapasitas penyimpanan, serta deklarasi fungsi-fungsi utama untuk mengatur proses penambahan, penghapusan, dan penampilan data dalam queue.

#### Full code Screenshot:
<img width="297" height="262" alt="image" src="https://github.com/user-attachments/assets/b6a7dbfa-8ce4-494c-a82f-848851626483" />

### 3. [main3.cpp]

```C++
#include <iostream>
#include "no3.h"
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printQueue(Q);
    enqueue(Q, 5); printQueue(Q);
    enqueue(Q, 2); printQueue(Q);
    enqueue(Q, 7); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    dequeue(Q);    printQueue(Q);
    enqueue(Q, 4); printQueue(Q);
    dequeue(Q);    printQueue(Q);
    dequeue(Q);    printQueue(Q);

    return 0;
}

```
Kode ini merupakan program utama yang digunakan untuk menjalankan dan memperlihatkan proses kerja queue secara bertahap, mulai dari kondisi awal, penambahan elemen, hingga penghapusan elemen, dengan menampilkan informasi queue setelah setiap operasi.

#### Full code Screenshot:
<img width="337" height="347" alt="image" src="https://github.com/user-attachments/assets/ae0b4a7a-20f5-42ed-909d-52b279229467" />

### [no3.cpp]

```C++
#include <iostream>
#include "no3.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear  = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.front == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.rear + 1) % MAX == Q.front);
}

void enqueue(Queue &Q, infotype X) {
    if (isFullQueue(Q)) {
        cout << "Queue sudah penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.front = 0;
        Q.rear  = 0;
    } else {
        Q.rear = (Q.rear + 1) % MAX;
    }

    Q.data[Q.rear] = X;
}

void dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }

    if (Q.front == Q.rear) {
        Q.front = -1;
        Q.rear  = -1;
    } else {
        Q.front = (Q.front + 1) % MAX;
    }
}

void printQueue(Queue Q) {
    if (isEmptyQueue(Q)) {
        cout << Q.front << " - " << Q.rear << " | Empty Queue" << endl;
        return;
    }

    cout << Q.front << " - " << Q.rear << " | ";
    int idx = Q.front;
    while (true) {
        cout << Q.data[idx] << " ";
        if (idx == Q.rear) break;
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}

```

Kode ini merupakan program utama yang digunakan untuk menjalankan dan memperlihatkan proses kerja queue secara bertahap, mulai dari kondisi awal, penambahan elemen, hingga penghapusan elemen, dengan menampilkan informasi queue setelah setiap operasi.
#### Full code Screenshot:
<img width="347" height="431" alt="image" src="https://github.com/user-attachments/assets/0d148187-ef77-4608-b18d-baa813d1a0e0" />
<img width="444" height="387" alt="image" src="https://github.com/user-attachments/assets/dc215acd-3e96-45ca-a7e7-379f0298eb27" />


### [no3.h]

```C++
#ifndef NO3_H
#define NO3_H

#define MAX 5
typedef int infotype;

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype X);
void dequeue(Queue &Q);
void printQueue(Queue Q);

#endif

```

#### Output:
<img width="405" height="241" alt="image" src="https://github.com/user-attachments/assets/535332f3-136b-41c6-b6c1-daa6e1aec81d" />

Kode ini merupakan file header yang berisi definisi struktur queue serta daftar fungsi dasar untuk mengelola data queue.

#### Full code Screenshot:
<img width="254" height="267" alt="image" src="https://github.com/user-attachments/assets/95d1d10b-7b64-4155-8aac-136dd3c04901" />


## Kesimpulan
Sebagai kesimpulan, queue adalah struktur data yang menggunakan prinsip FIFO dan mudah dipahami untuk mengelola data secara berurutan. Melalui operasi enqueue dan dequeue dengan bantuan penunjuk front dan rear, queue dapat diterapkan menggunakan array maupun linked list sesuai dengan kebutuhan pemrograman.
## Referensi
[1] Modul Praktikum Struktur Data, Program Studi Informatika.
[2] Goodrich, M. T., Tamassia, R., & Goldwasser, M. H. (2014). Data Structures and Algorithms in C++. Wiley.
[3] GeeksforGeeks. Queue Data Structure.
[4] Kurniawan, A. (2019). Struktur Data dan Algoritma dengan C++. Andi Offset.
