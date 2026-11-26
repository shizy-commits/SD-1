#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j) {
        // i dan j dikurang satu supaya sesuai dengan angka di gambar
        i--;
        j--;
        if (i >= 0 && i < numVertices && j >= 0 && j < numVertices) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1; // karena graf tidak berarah
        } else {
            cout << "Indeks simpul tidak valid." << endl;
        }
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // ----- BAGIAN DFS -----
    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "Depth-First Traversal (dari vertex " << startVertex << "):" << endl;

        // TODO: panggil fungsi dfsUtil di sini
        dfsUtil(startVertex, visited);

        cout << endl;
    }

    void dfsUtil(int currentVertex, vector<bool>& visited) {
        // TODO: isi logika DFS di sini
        // 1. Tandai simpul sekarang sudah dikunjungi
        visited[currentVertex] = true;

        // 2. Cetak simpul sekarang
        int currentRealVertex = currentVertex + 1;
        cout << currentRealVertex << " ";

        // 3. Kunjungi semua simpul yang terhubung (rekursif)
        for (int i = 0; i < numVertices; i++){
            if(adjMatrix[currentVertex][i] == 1 && !visited[i]){
                dfsUtil (i, visited);
            }
        }
        
    }
};

int main() {
    Graph g(8);

    // Parameter fungsi addEdge sekarang menerima angka sesuai gambar
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 7);
    g.addEdge(6, 8);

    // Cetak adjacency matrix untuk melihat representasi graf
    g.printAdjMatrix();
    cout << endl;

    // Panggil fungsi DFS mulai dari vertex 0 (yakni simpul 1)
    g.dfs(0);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct node {
    string n_b;
    long harga;
    int jumlah;
    node *next;
};

node *head = NULL;
node *tail = NULL;

// Subprogram untuk menambahkan barang di awal
void insertFirst(string nama_barang, long harga_barang, int jumlah_barang) {
    node *newNode = new node;
    newNode->n_b = nama_barang;
    newNode->harga = harga_barang;
    newNode->jumlah = jumlah_barang;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        newNode->next = head;
        head = newNode;
    }

    cout << "[ " << nama_barang << " | " << harga_barang
         << " | " << jumlah_barang << " ]" << endl;
}

// Subprogram untuk menambahkan barang di akhir
void insertLast(string nama_barang, long harga_barang, int jumlah_barang) {
    node *newNode = new node;
    newNode->n_b = nama_barang;
    newNode->harga = harga_barang;
    newNode->jumlah = jumlah_barang;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }

    cout << "[ " << nama_barang << " | " << harga_barang
         << " | " << jumlah_barang << " ]" << endl;
}

// Subprogram untuk menyisipkan barang setelah barang tertentu
void insertAfter(string target_nama, string nama_barang,
                 long harga_barang, int jumlah_barang) {

    node *p = head;

    while (p != NULL && p->n_b != target_nama) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Barang dengan nama \"" << target_nama
             << "\" tidak ditemukan." << endl;
        return;
    }

    node *newNode = new node;
    newNode->n_b = nama_barang;
    newNode->harga = harga_barang;
    newNode->jumlah = jumlah_barang;
    newNode->next = p->next;

    p->next = newNode;

    if (p == tail) {
        tail = newNode;
    }

    cout << "Barang berhasil disisipkan." << endl;
}

// Subprogram untuk menghapus barang
void hapusBarang(string nama_barang) {
    node *p = head;
    node *prev = NULL;

    while (p != NULL && p->n_b != nama_barang) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        cout << "Barang " << nama_barang
             << " tidak ditemukan." << endl;
        return;
    }

    if (prev == NULL) {
        head = p->next;
    }
    else {
        prev->next = p->next;
    }

    if (p == tail) {
        tail = prev;
    }

    delete p;

    cout << "Barang " << nama_barang
         << " berhasil dihapus." << endl;
    cout << endl;
}

// Subprogram untuk menampilkan isi keranjang
void tampilkanKeranjang() {
    node *p = head;
    int total_barang = 0;
    long total_harga = 0;

    if (head == NULL) {
        cout << "Keranjang masih kosong." << endl;
        cout << endl;
        return;
    }

    while (p != NULL) {
        cout << p->n_b << " - Rp" << p->harga
             << " x" << p->jumlah << endl;

        total_barang += p->jumlah;
        total_harga += p->harga * p->jumlah;

        p = p->next;
    }

    cout << "Total barang: " << total_barang << endl;
    cout << "Total harga: Rp" << total_harga << endl;
    cout << endl;
}

// Program utama
int main() {
    int pilih;
    string nama_hapus;

    while (true) {
        cout << "=== Keranjang Belanja Ajaib ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Sisipkan Barang" << endl;
        cout << "3. Hapus Barang" << endl;
        cout << "4. Tampilkan Barang" << endl;
        cout << "5. Keluar Program" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        cout << endl;

        if (pilih == 1) {
            string nama;
            long harga;
            int jumlah;

            cout << "Nama Barang: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Harga: ";
            cin >> harga;

            cout << "Jumlah: ";
            cin >> jumlah;

            if (head == NULL) {
                insertFirst(nama, harga, jumlah);
            }
            else {
                insertLast(nama, harga, jumlah);
            }

            cout << endl;
        }

        else if (pilih == 2) {
            string target, sisip;
            long harga;
            int jumlah;

            cout << "Target Sisipan: ";
            cin.ignore();
            getline(cin, target);

            cout << "Apa yang mau disisipkan: ";
            getline(cin, sisip);

            cout << "Harga: ";
            cin >> harga;

            cout << "Jumlah: ";
            cin >> jumlah;

            insertAfter(target, sisip, harga, jumlah);
            cout << endl;
        }

        else if (pilih == 3) {
            cout << "Masukkan nama barang yang ingin dihapus: ";
            cin.ignore();
            getline(cin, nama_hapus);

            hapusBarang(nama_hapus);
        }

        else if (pilih == 4) {
            cout << "Isi Keranjang Belanja:" << endl;
            tampilkanKeranjang();
        }

        else if (pilih == 5) {
            cout << "Terima kasih telah menggunakan program!" << endl;
            break;
        }

        else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            cout << endl;
        }
    }

    return 0;
}