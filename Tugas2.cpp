#include <iostream>
using namespace std;
struct Node {
    int nilai;
    Node* next;
};

Node* head = NULL;
void tampilkanList() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "List kosong." << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->nilai;
        if (temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Tambah di depan
void tambahDepan(int nilaiBaru) {
    Node* nodeBaru = new Node();
    nodeBaru->nilai = nilaiBaru;
    nodeBaru->next = head;
    head = nodeBaru;
}

// Tambah di belakang
void tambahBelakang(int nilaiBaru) {
    Node* nodeBaru = new Node();
    nodeBaru->nilai = nilaiBaru;
    nodeBaru->next = NULL;

    if (head == NULL) {
        head = nodeBaru;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
}

// Tambah setelah nilai tertentu
void tambahSetelah(int nilaiBaru, int acuan) {
    Node* temp = head;
    while (temp != NULL && temp->nilai != acuan) {
        temp = temp->next;
    }

    if (temp != NULL) {
        Node* nodeBaru = new Node();
        nodeBaru->nilai = nilaiBaru;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    } else {
        cout << "Nilai acuan " << acuan << " tidak ditemukan!" << endl;
    }
}

// Hapus node berdasarkan nilai
void hapusNode(int nilaiHapus) {
    if (head == NULL) return;

    // Jika node yang dihapus adalah head
    if (head->nilai == nilaiHapus) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->nilai != nilaiHapus) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
    } else {
        cout << "Nilai " << nilaiHapus << " tidak ditemukan!" << endl;
    }
}

int main() {
    // 1. Inisialisasi 10 data awal
    int dataAwal[] = {100, 92, 45, 87, 71, 99, 95, 60, 55, 88};
    for (int i = 0; i < 10; i++) {
        tambahBelakang(dataAwal[i]);
    }
    cout << "DATA AWAL" << endl;
    tampilkanList();

    // 2. Tambahkan 70 didepan
    cout << "\n1. Tambahkan 70 didepan:" << endl;
    tambahDepan(70);
    tampilkanList();

    // 3. Tambahkan 50 dibelakang
    cout << "\n2. Tambahkan 50 dibelakang:" << endl;
    tambahBelakang(50);
    tampilkanList();

    // 4. Tambahkan 0 setelah 45
    cout << "\n3. Tambahkan 0 setelah 45:" << endl;
    tambahSetelah(0, 45);
    tampilkanList();

    // 5. Hapus 99
    cout << "\n4. Hapus 99:" << endl;
    hapusNode(99);
    tampilkanList();

    // 6. Hapus 60
    cout << "\n5. Hapus 60:" << endl;
    hapusNode(60);
    tampilkanList();

    return 0;
}