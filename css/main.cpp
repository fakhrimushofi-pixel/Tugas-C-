#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;


// ======================================================
// STEP 1: MEMBUAT STRUKTUR DATA MAHASISWA
// ======================================================
// struct digunakan untuk menggabungkan beberapa data
// yang berhubungan dengan seorang mahasiswa.

struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
    float nilai;
};


// ======================================================
// STEP 2: MEMBUAT TEMPAT PENYIMPANAN DATA
// ======================================================

// vector digunakan untuk menyimpan banyak data mahasiswa.
// Bisa dianggap seperti Array yang ukurannya dapat bertambah.
vector<Mahasiswa> dataMahasiswa;


// stack digunakan untuk menyimpan RIWAYAT PERUBAHAN.
// Prinsip Stack: data terakhir masuk akan keluar terlebih dahulu.
stack<string> riwayat;


// queue digunakan untuk membuat ANTREAN pelayanan mahasiswa.
// Prinsip Queue: yang masuk terlebih dahulu akan dilayani terlebih dahulu.
queue<string> antrean;


// ======================================================
// STEP 3: FUNGSI TAMBAH DATA MAHASISWA
// ======================================================

void tambahMahasiswa() {

    Mahasiswa m;

    cout << "\n===== TAMBAH DATA MAHASISWA =====\n";

    cout << "Masukkan NIM      : ";
    cin >> m.nim;

    // Mengecek apakah NIM sudah ada
    for (const auto &data : dataMahasiswa) {
        if (data.nim == m.nim) {
            cout << "NIM sudah terdaftar!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Masukkan Nama     : ";
    getline(cin, m.nama);

    cout << "Masukkan Jurusan  : ";
    getline(cin, m.jurusan);

    cout << "Masukkan Nilai    : ";
    cin >> m.nilai;

    // Memasukkan data mahasiswa ke vector
    dataMahasiswa.push_back(m);

    // Menyimpan aktivitas ke Stack
    riwayat.push("Menambahkan mahasiswa: " + m.nama);

    cout << "\nData mahasiswa berhasil ditambahkan!\n";
}


// ======================================================
// STEP 4: FUNGSI MENAMPILKAN DATA MAHASISWA
// ======================================================

void tampilkanMahasiswa() {

    cout << "\n================ DATA MAHASISWA ================\n";

    // Mengecek apakah data masih kosong
    if (dataMahasiswa.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }

    cout << left
         << setw(12) << "NIM"
         << setw(25) << "Nama"
         << setw(25) << "Jurusan"
         << setw(10) << "Nilai" << endl;

    cout << "--------------------------------------------------------------\n";

    // Menampilkan semua data dalam vector
    for (const auto &m : dataMahasiswa) {

        cout << left
             << setw(12) << m.nim
             << setw(25) << m.nama
             << setw(25) << m.jurusan
             << setw(10) << m.nilai
             << endl;
    }
}


// ======================================================
// STEP 5: FUNGSI MENCARI MAHASISWA
// ======================================================

void cariMahasiswa() {

    string nim;

    cout << "\n===== CARI MAHASISWA =====\n";

    cout << "Masukkan NIM yang dicari: ";
    cin >> nim;

    bool ditemukan = false;

    // Linear Search
    // Program mencari data satu per satu dari awal
    for (const auto &m : dataMahasiswa) {

        if (m.nim == nim) {

            cout << "\nData ditemukan!\n";
            cout << "NIM      : " << m.nim << endl;
            cout << "Nama     : " << m.nama << endl;
            cout << "Jurusan  : " << m.jurusan << endl;
            cout << "Nilai    : " << m.nilai << endl;

            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa tidak ditemukan.\n";
    }
}


// ======================================================
// STEP 6: FUNGSI EDIT DATA MAHASISWA
// ======================================================

void editMahasiswa() {

    string nim;

    cout << "\n===== EDIT DATA MAHASISWA =====\n";

    cout << "Masukkan NIM yang ingin diedit: ";
    cin >> nim;

    for (auto &m : dataMahasiswa) {

        if (m.nim == nim) {

            cin.ignore();

            cout << "Nama baru     : ";
            getline(cin, m.nama);

            cout << "Jurusan baru  : ";
            getline(cin, m.jurusan);

            cout << "Nilai baru    : ";
            cin >> m.nilai;

            // Menyimpan riwayat edit ke Stack
            riwayat.push("Mengedit mahasiswa: " + m.nama);

            cout << "\nData berhasil diperbarui!\n";

            return;
        }
    }

    cout << "Mahasiswa tidak ditemukan.\n";
}


// ======================================================
// STEP 7: FUNGSI HAPUS DATA MAHASISWA
// ======================================================

void hapusMahasiswa() {

    string nim;

    cout << "\n===== HAPUS DATA MAHASISWA =====\n";

    cout << "Masukkan NIM yang ingin dihapus: ";
    cin >> nim;

    // Mencari posisi data
    for (auto it = dataMahasiswa.begin();
         it != dataMahasiswa.end();
         ++it) {

        if (it->nim == nim) {

            string nama = it->nama;

            // Menghapus data dari vector
            dataMahasiswa.erase(it);

            // Menyimpan riwayat penghapusan
            riwayat.push("Menghapus mahasiswa: " + nama);

            cout << "Data berhasil dihapus.\n";

            return;
        }
    }

    cout << "Mahasiswa tidak ditemukan.\n";
}


// ======================================================
// STEP 8: FUNGSI SORTING / PENGURUTAN
// ======================================================

void urutkanMahasiswa() {

    int pilihan;

    cout << "\n===== PENGURUTAN DATA =====\n";

    cout << "1. Berdasarkan NIM\n";
    cout << "2. Berdasarkan Nama\n";
    cout << "3. Berdasarkan Nilai Tertinggi\n";
    cout << "4. Berdasarkan Nilai Terendah\n";

    cout << "Pilih: ";
    cin >> pilihan;


    // Sorting berdasarkan NIM
    if (pilihan == 1) {

        sort(dataMahasiswa.begin(),
             dataMahasiswa.end(),
             [](const Mahasiswa &a, const Mahasiswa &b) {
                 return a.nim < b.nim;
             });

        cout << "Data berhasil diurutkan berdasarkan NIM.\n";
    }


    // Sorting berdasarkan Nama
    else if (pilihan == 2) {

        sort(dataMahasiswa.begin(),
             dataMahasiswa.end(),
             [](const Mahasiswa &a, const Mahasiswa &b) {
                 return a.nama < b.nama;
             });

        cout << "Data berhasil diurutkan berdasarkan nama.\n";
    }


    // Nilai tertinggi ke terendah
    else if (pilihan == 3) {

        sort(dataMahasiswa.begin(),
             dataMahasiswa.end(),
             [](const Mahasiswa &a, const Mahasiswa &b) {
                 return a.nilai > b.nilai;
             });

        cout << "Data berhasil diurutkan dari nilai tertinggi.\n";
    }


    // Nilai terendah ke tertinggi
    else if (pilihan == 4) {

        sort(dataMahasiswa.begin(),
             dataMahasiswa.end(),
             [](const Mahasiswa &a, const Mahasiswa &b) {
                 return a.nilai < b.nilai;
             });

        cout << "Data berhasil diurutkan dari nilai terendah.\n";
    }

    else {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    // Menampilkan hasil sorting
    tampilkanMahasiswa();
}


// ======================================================
// STEP 9: REKAP NILAI MAHASISWA
// ======================================================

void rekapNilai() {

    cout << "\n========== REKAP NILAI MAHASISWA ==========\n";

    if (dataMahasiswa.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }


    float total = 0;
    float tertinggi = dataMahasiswa[0].nilai;
    float terendah = dataMahasiswa[0].nilai;


    int jumlahA = 0;
    int jumlahB = 0;
    int jumlahC = 0;
    int jumlahD = 0;
    int jumlahE = 0;


    // Menghitung total dan mencari nilai tertinggi/terendah
    for (const auto &m : dataMahasiswa) {

        total += m.nilai;

        if (m.nilai > tertinggi) {
            tertinggi = m.nilai;
        }

        if (m.nilai < terendah) {
            terendah = m.nilai;
        }


        // Menentukan grade
        if (m.nilai >= 80) {
            jumlahA++;
        }
        else if (m.nilai >= 70) {
            jumlahB++;
        }
        else if (m.nilai >= 60) {
            jumlahC++;
        }
        else if (m.nilai >= 50) {
            jumlahD++;
        }
        else {
            jumlahE++;
        }
    }


    float rataRata = total / dataMahasiswa.size();


    cout << fixed << setprecision(2);

    cout << "Jumlah mahasiswa : " << dataMahasiswa.size() << endl;
    cout << "Nilai tertinggi  : " << tertinggi << endl;
    cout << "Nilai terendah   : " << terendah << endl;
    cout << "Nilai rata-rata  : " << rataRata << endl;

    cout << "\n===== JUMLAH BERDASARKAN GRADE =====\n";

    cout << "Grade A (80-100) : " << jumlahA << " mahasiswa\n";
    cout << "Grade B (70-79)  : " << jumlahB << " mahasiswa\n";
    cout << "Grade C (60-69)  : " << jumlahC << " mahasiswa\n";
    cout << "Grade D (50-59)  : " << jumlahD << " mahasiswa\n";
    cout << "Grade E (<50)    : " << jumlahE << " mahasiswa\n";
}


// ======================================================
// STEP 10: MENAMPILKAN RIWAYAT STACK
// ======================================================

void tampilkanRiwayat() {

    cout << "\n========== RIWAYAT PERUBAHAN ==========\n";

    if (riwayat.empty()) {
        cout << "Belum ada riwayat perubahan.\n";
        return;
    }


    // Karena Stack tidak boleh langsung dihabiskan,
    // kita menggunakan salinan Stack.
    stack<string> temp = riwayat;

    int nomor = 1;

    while (!temp.empty()) {

        cout << nomor << ". "
             << temp.top() << endl;

        // Mengambil data paling atas
        temp.pop();

        nomor++;
    }
}


// ======================================================
// STEP 11: MENAMBAHKAN MAHASISWA KE ANTREAN
// ======================================================

void tambahAntrean() {

    string nama;

    cout << "\n========== TAMBAH ANTREAN ==========\n";

    cin.ignore();

    cout << "Masukkan nama mahasiswa: ";
    getline(cin, nama);

    // Memasukkan nama ke Queue
    antrean.push(nama);

    cout << nama << " berhasil masuk antrean.\n";
}


// ======================================================
// STEP 12: MELAYANI ANTREAN
// ======================================================

void layaniAntrean() {

    cout << "\n========== PELAYANAN ANTREAN ==========\n";

    if (antrean.empty()) {

        cout << "Tidak ada mahasiswa dalam antrean.\n";

        return;
    }


    // Melihat mahasiswa yang berada paling depan
    string nama = antrean.front();

    cout << "Mahasiswa yang dilayani: "
         << nama << endl;


    // Menghapus mahasiswa dari antrean
    antrean.pop();
}


// ======================================================
// STEP 13: MENAMPILKAN ANTREAN
// ======================================================

void tampilkanAntrean() {

    cout << "\n========== DAFTAR ANTREAN ==========\n";

    if (antrean.empty()) {

        cout << "Antrean kosong.\n";

        return;
    }


    // Membuat salinan queue agar antrean asli tidak hilang
    queue<string> temp = antrean;

    int nomor = 1;

    while (!temp.empty()) {

        cout << nomor << ". "
             << temp.front() << endl;

        temp.pop();

        nomor++;
    }
}


// ======================================================
// STEP 14: MENU ANTREAN
// ======================================================

void menuAntrean() {

    int pilihan;

    do {

        cout << "\n========== MENU ANTREAN ==========\n";

        cout << "1. Tambah Antrean\n";
        cout << "2. Layani Antrean\n";
        cout << "3. Tampilkan Antrean\n";
        cout << "0. Kembali\n";

        cout << "Pilih: ";
        cin >> pilihan;


        switch (pilihan) {

            case 1:
                tambahAntrean();
                break;

            case 2:
                layaniAntrean();
                break;

            case 3:
                tampilkanAntrean();
                break;

            case 0:
                cout << "Kembali ke menu utama.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);
}


// ======================================================
// STEP 15: PROGRAM UTAMA
// ======================================================

int main() {

    int pilihan;


    do {

        cout << "\n\n";
        cout << "=============================================\n";
        cout << "       SISTEM MANAJEMEN DATA MAHASISWA\n";
        cout << "=============================================\n";

        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Edit Data Mahasiswa\n";
        cout << "5. Hapus Data Mahasiswa\n";
        cout << "6. Pengurutan Data\n";
        cout << "7. Rekap Nilai Mahasiswa\n";
        cout << "8. Riwayat Perubahan (Stack)\n";
        cout << "9. Antrean Pelayanan (Queue)\n";
        cout << "0. Keluar\n";

        cout << "=============================================\n";

        cout << "Pilih menu: ";
        cin >> pilihan;


        switch (pilihan) {

            case 1:
                tambahMahasiswa();
                break;

            case 2:
                tampilkanMahasiswa();
                break;

            case 3:
                cariMahasiswa();
                break;

            case 4:
                editMahasiswa();
                break;

            case 5:
                hapusMahasiswa();
                break;

            case 6:
                urutkanMahasiswa();
                break;

            case 7:
                rekapNilai();
                break;

            case 8:
                tampilkanRiwayat();
                break;

            case 9:
                menuAntrean();
                break;

            case 0:
                cout << "\nProgram selesai. Terima kasih!\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia!\n";
        }


    } while (pilihan != 0);


    return 0;
}