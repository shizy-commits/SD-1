#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices; //nyimpan jumlah simpul (vertex)
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) { //belum ada graf jadi adjMartix masih 0
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
    
    // ----- BAGIAN BFS -----
    void bfs(int startVertex) {
        vector<bool> visited(numVertices, false); //false untuk nandain simpul yang blm dikunjungi
        queue<int> q;

        // Tandai simpul awal sudah dikunjungi dan masukkan ke antrian
        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth-First Traversal (dari vertex " << startVertex << "):" << endl;

        // TODO: isi logika BFS di bawah ini bersama-sama!
        // 1. Tandai simpul awal sudah dikunjungi dan masukkan ke antrian
        // 2. Selama antrian belum kosong:
        //    - Ambil simpul terdepan (front)
        //    - Cetak simpulnya
        //    - Kunjungi semua tetangga yang belum dikunjungi
        //      dan masukkan ke antrian

        while(!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            cout << currentVertex + 1 << " ";

            for (int i = 0; i  < numVertices; i++){
                if (adjMatrix[currentVertex][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        cout << endl;
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

    // Panggil fungsi BFS mulai dari vertex 0 (yakni simpul 1)
    g.bfs(0);

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    system("CLS");
    int n;
    
    // Validasi: Pastikan n lebih besar dari 0
    do {
        cout << "Masukkan jumlah pesanan: "; 
        cin >> n;
        if (n <= 0) {
            cout << "Jumlah pesanan harus lebih dari 0!\n";
        }
    } while (n <= 0);
    
    cin.ignore(); // Membersihkan sisa newline di buffer setelah input n
    cout << endl;

    string* nama_hewan = new string[n];
    string* menu = new string[n];
    int* status = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Pesanan " << i + 1 << endl;
        
        // Menggunakan getline agar bisa membaca nama hewan lebih dari satu kata (misal: Golden Retriever)
        cout << "Nama hewan: "; 
        getline(cin, nama_hewan[i]);
        
        cout << "Menu pesanan: "; 
        getline(cin, menu[i]);
        
        // Validasi: Input status hanya boleh 1 atau 2
        do {
            cout << "Status VIP (1=biasa, 2=VIP): "; 
            cin >> status[i];
            if (status[i] != 1 && status[i] != 2) {
                cout << "Pilihan tidak valid! Masukkan 1 atau 2.\n";
            }
        } while (status[i] != 1 && status[i] != 2);
        
        cin.ignore(); // Membersihkan sisa newline setelah cin >> status[i]
        cout << endl;
    }

    cout << "\n--- Daftar Pesanan (Prioritas VIP) ---\n";
    int nomor = 1;
    for (int i = 0; i < n; i++) {
        if (status[i] == 2) {
            for (int j = 0; j < nama_hewan[i].length(); j++) {
                nama_hewan[i][j] = toupper(nama_hewan[i][j]);
            }
            cout << nomor++ << ". " << nama_hewan[i] << " - " << menu[i] << " [VIP]" << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            for (int j = 0; j < nama_hewan[i].length(); j++) {
                nama_hewan[i][j] = toupper(nama_hewan[i][j]);
            }
            cout << nomor++ << ". " << nama_hewan[i] << " - " << menu[i] << endl;
        }
    }

    delete[] nama_hewan;
    delete[] menu;
    delete[] status;

    return 0;
}