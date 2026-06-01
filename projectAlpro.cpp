#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// ================= STRUCT =================
struct Buku {
    string kode;
    string judul;
    string penulis;
    int tahun;
    bool tersedia;
};

// ================= ARRAY =================
const int MAX_BUKU = 100;

Buku daftarBuku[MAX_BUKU];
int jumlahBuku = 0;

// ================= VALIDASI INPUT ANGKA =================
int inputAngka() {

    int angka;

    while (!(cin >> angka)) {

        cout << "Input harus berupa angka!\n";

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Masukkan lagi: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return angka;
}

// ================= VALIDASI INPUT STRING =================
string inputString(string pesan) {

    string data;

    do {

        cout << pesan;
        getline(cin, data);

        if (data.empty()) {
            cout << "Input tidak boleh kosong!\n";
        }

    } while (data.empty());

    return data;
}

// ================= POINTER =================
void tambahBuku(Buku *b) {

    if (jumlahBuku >= MAX_BUKU) {

        cout << "Database penuh!\n";
        return;
    }

    cout << "\n===== TAMBAH BUKU =====\n";

    b->kode = inputString("Kode Buku   : ");
    b->judul = inputString("Judul Buku  : ");
    b->penulis = inputString("Penulis     : ");

    cout << "Tahun Terbit: ";
    b->tahun = inputAngka();

    // VALIDASI TAHUN
    while (b->tahun < 1000 || b->tahun > 2100) {

        cout << "Tahun tidak valid!\n";
        cout << "Masukkan tahun antara 1000 - 2100: ";

        b->tahun = inputAngka();
    }

    b->tersedia = true;

    daftarBuku[jumlahBuku] = *b;

    jumlahBuku++;

    cout << "Buku berhasil ditambahkan!\n";
}

// ================= TAMPILKAN BUKU =================
void tampilkanBuku() {

    if (jumlahBuku == 0) {

        cout << "\nBelum ada buku.\n";
        return;
    }

    cout << "\n===== DAFTAR BUKU =====\n";

    for (int i = 0; i < jumlahBuku; i++) {

        cout << "\nBuku ke-" << i + 1 << endl;

        cout << "Kode      : "
             << daftarBuku[i].kode << endl;

        cout << "Judul     : "
             << daftarBuku[i].judul << endl;

        cout << "Penulis   : "
             << daftarBuku[i].penulis << endl;

        cout << "Tahun     : "
             << daftarBuku[i].tahun << endl;

        cout << "Status    : "
             << (daftarBuku[i].tersedia ? "Tersedia" : "Dipinjam")
             << endl;
    }
    system("pause");
    system("cls");
}

// ================= SEARCHING =================
void cariBuku() {

    if (jumlahBuku == 0) {

        cout << "\nBelum ada buku.\n";
        return;
    }

    string keyword;

    cout << "\nMasukkan Judul / Kode Buku: ";
    getline(cin, keyword);

    if (keyword.empty()) {

        cout << "Input tidak boleh kosong!\n";
        return;
    }

    bool ditemukan = false;

    for (int i = 0; i < jumlahBuku; i++) {

        if (daftarBuku[i].judul == keyword ||
            daftarBuku[i].kode == keyword) {

            cout << "\n===== BUKU DITEMUKAN =====\n";

            cout << "Kode    : "
                 << daftarBuku[i].kode << endl;

            cout << "Judul   : "
                 << daftarBuku[i].judul << endl;

            cout << "Penulis : "
                 << daftarBuku[i].penulis << endl;

            cout << "Tahun   : "
                 << daftarBuku[i].tahun << endl;

            cout << "Status  : "
                 << (daftarBuku[i].tersedia ? "Tersedia" : "Dipinjam")
                 << endl;

            ditemukan = true;
        }
    }

    if (!ditemukan) {

        cout << "Buku tidak ditemukan.\n";
    }
    system("pause");
    system("cls");
}

// ================= PINJAM BUKU =================
void pinjamBuku() {

    if (jumlahBuku == 0) {

        cout << "\nBelum ada buku.\n";
        return;
    }

    string kode;

    cout << "\nMasukkan kode buku: ";
    getline(cin, kode);

    if (kode.empty()) {

        cout << "Kode tidak boleh kosong!\n";
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {

        if (daftarBuku[i].kode == kode) {

            if (daftarBuku[i].tersedia) {

                daftarBuku[i].tersedia = false;

                cout << "Buku berhasil dipinjam.\n";

            } else {

                cout << "Buku sedang dipinjam.\n";
            }

            return;
        }
    }

    cout << "Kode buku tidak ditemukan.\n";
    system("pause");
    system("cls");
}

// ================= SORTING JUDUL =================
void sortJudul() {

    if (jumlahBuku == 0) {

        cout << "\nBelum ada buku.\n";
        return;
    }

    for (int i = 0; i < jumlahBuku - 1; i++) {

        for (int j = 0; j < jumlahBuku - i - 1; j++) {

            if (daftarBuku[j].judul >
                daftarBuku[j + 1].judul) {

                swap(daftarBuku[j],
                     daftarBuku[j + 1]);
            }
        }
    }

    cout << "Data berhasil diurutkan berdasarkan judul.\n";
    system("pause");
    system("cls");
}

// ================= SORTING TAHUN =================
void sortTahun() {

    if (jumlahBuku == 0) {

        cout << "\nBelum ada buku.\n";
        return;
    }

    for (int i = 0; i < jumlahBuku - 1; i++) {

        for (int j = 0; j < jumlahBuku - i - 1; j++) {

            if (daftarBuku[j].tahun >
                daftarBuku[j + 1].tahun) {

                swap(daftarBuku[j],
                     daftarBuku[j + 1]);
            }
        }
    }

    cout << "Data berhasil diurutkan berdasarkan tahun.\n";
    system("pause");
    system("cls");
}

// ================= HAPUS BUKU =================
void hapusBuku() {

    if (jumlahBuku == 0) {

        cout << "\nBelum ada buku.\n";
        return;
    }

    string kode;

    cout << "\nMasukkan kode buku yang ingin dihapus: ";
    getline(cin, kode);

    if (kode.empty()) {

        cout << "Kode tidak boleh kosong!\n";
        return;
    }

    bool ditemukan = false;

    for (int i = 0; i < jumlahBuku; i++) {

        if (daftarBuku[i].kode == kode) {

            ditemukan = true;

            // GESER ARRAY
            for (int j = i; j < jumlahBuku - 1; j++) {

                daftarBuku[j] = daftarBuku[j + 1];
            }

            jumlahBuku--;

            cout << "Buku berhasil dihapus.\n";

            break;
        }
    }

    if (!ditemukan) {

        cout << "Buku tidak ditemukan.\n";
    }
    system("pause");
    system("cls");
}

// ================= FILE =================
void simpanFile() {

    ofstream file("database_buku.txt");

    if (!file) {

        cout << "File gagal dibuat.\n";
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {

        file << daftarBuku[i].kode << "|";
        file << daftarBuku[i].judul << "|";
        file << daftarBuku[i].penulis << "|";
        file << daftarBuku[i].tahun << "|";
        file << daftarBuku[i].tersedia << endl;
    }

    file.close();

    cout << "Data berhasil disimpan ke file.\n";
    system("pause");
    system("cls");
}

// ================= LOAD FILE =================
void loadFile() {

    ifstream file("database_buku.txt");

    if (!file) {
        return;
    }

    while (
        jumlahBuku < MAX_BUKU &&
        getline(file, daftarBuku[jumlahBuku].kode, '|')
    ) {

        getline(file,
                daftarBuku[jumlahBuku].judul,
                '|');

        getline(file,
                daftarBuku[jumlahBuku].penulis,
                '|');

        string tahunStr;
        string tersediaStr;

        getline(file, tahunStr, '|');
        getline(file, tersediaStr);

        try {

            daftarBuku[jumlahBuku].tahun =
                stoi(tahunStr);

            daftarBuku[jumlahBuku].tersedia =
                stoi(tersediaStr);

            jumlahBuku++;

        } catch (...) {

            cout << "Ada data rusak pada file.\n";
        }
    }

    file.close();
}

// ================= KEMBALIKAN BUKU =================
void kembalikanBuku() {

    if (jumlahBuku == 0) {

        cout << "\nBelum ada buku.\n";
        return;
    }

    string kode;

    cout << "\nMasukkan kode buku yang ingin dikembalikan: ";
    getline(cin, kode);

    if (kode.empty()) {

        cout << "Kode tidak boleh kosong!\n";
        return;
    }

    for (int i = 0; i < jumlahBuku; i++) {

        if (daftarBuku[i].kode == kode) {

            if (!daftarBuku[i].tersedia) {

                daftarBuku[i].tersedia = true;

                cout << "Buku berhasil dikembalikan.\n";

            } else {

                cout << "Buku sudah berstatus tersedia.\n";
            }

            system("pause");
            system("cls");
            return;
        }
    }

    cout << "Kode buku tidak ditemukan.\n";

    system("pause");
    system("cls");
}

// ================= RECURSION =================
void menuRecursive() {

    int pilihan;

    cout << "\n===== SISTEM MANAJEMEN PERPUSTAKAAN =====\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Tampilkan Buku\n";
    cout << "3. Cari Buku\n";
    cout << "4. Pinjam Buku\n";
    cout << "5. Kembalikan Buku\n";
    cout << "6. Sorting Judul\n";
    cout << "7. Sorting Tahun\n";
    cout << "8. Hapus Buku\n";
    cout << "9. Keluar Dan Simpan\n";
    cout << "Pilih menu: ";

    pilihan = inputAngka();

    // VALIDASI MENU
    if (pilihan < 1 || pilihan > 9) {

        cout << "Menu hanya tersedia dari 1 - 9!\n";
        system("pause");
        system("cls");

        menuRecursive();
        return;
    }

    Buku b;

    switch (pilihan) {

        case 1:
            tambahBuku(&b);
            break;

        case 2:
            tampilkanBuku();
            break;

        case 3:
            cariBuku();
            break;

        case 4:
            pinjamBuku();
            break;

        case 5:
            kembalikanBuku();
            break;

        case 6:
            sortJudul();
            break;

        case 7:
            sortTahun();
            break;

        case 8:
            hapusBuku();
            break;

        case 9:
            simpanFile();
            cout << "Program selesai.\n";
            cout << " :)\n ";
            cout << "\t\n";
            return;
    }

    // ================= RECURSION =================
    menuRecursive();
}

// ================= MAIN =================
int main() {

    loadFile();

    menuRecursive();

    return 0;
}