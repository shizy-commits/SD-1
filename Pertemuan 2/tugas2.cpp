#include <iostream>
using namespace std;

// Struktur Node untuk Linked List
struct Node {
    int nilai;
    Node* next;
};

// Deklarasi pointer head
Node* head = NULL;

// Fungsi untuk menampilkan isi Linked List
void tampilkanList() {
    cout << "Isi Linked List: ";
    if (head == NULL) {
        cout << "NULL" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->nilai << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 1. Tambah Node di Awal
void tambahAwal(int nilai) {
    Node* newNode = new Node();
    newNode->nilai = nilai;
    newNode->next = head;
    head = newNode;
}

// 2. Tambah Node di Akhir
void tambahAkhir(int nilai) {
    Node* newNode = new Node();
    newNode->nilai = nilai;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. Tambah Node Setelah Nilai Tertentu
void tambahSetelah(int nilaiBaru, int nilaiCari) {
    Node* temp = head;
    while (temp != NULL && temp->nilai != nilaiCari) {
        temp = temp->next;
    }

    if (temp != NULL) {
        Node* newNode = new Node();
        newNode->nilai = nilaiBaru;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Nilai " << nilaiCari << " tidak ditemukan!" << endl;
    }
}

// 4. Hapus Node Berdasarkan Nilai
void hapusNilai(int nilai) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    // Jika node yang akan dihapus adalah head
    if (head->nilai == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Mencari node yang akan dihapus
    Node* temp = head;
    while (temp->next != NULL && temp->next->nilai != nilai) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* nodeDihapus = temp->next;
        temp->next = temp->next->next;
        delete nodeDihapus;
    } else {
        cout << "Nilai " << nilai << " tidak ditemukan!" << endl;
    }
}

int main() {
    int pilihan, nilai, nilaiCari;

    do {
        cout << "\n===== MENU SINGLE LINKED LIST =====" << endl;
        cout << "1. Tambah di awal" << endl;
        cout << "2. Tambah di akhir" << endl;
        cout << "3. Tambah setelah nilai tertentu" << endl;
        cout << "4. Hapus berdasarkan nilai" << endl;
        cout << "5. Tampilkan Linked List" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAwal(nilai);
                tampilkanList();
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAkhir(nilai);
                tampilkanList();
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                tambahSetelah(nilai, nilaiCari);
                tampilkanList();
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusNilai(nilai);
                tampilkanList();
                break;
            case 5:
                tampilkanList();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}