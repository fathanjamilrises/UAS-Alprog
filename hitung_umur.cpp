#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Array jumlah hari untuk setiap bulan (1 = Januari s.d. 12 = Desember)
    // Februari dianggap tetap 28 hari (tanpa perhitungan tahun kabisat)
    int hariPerBulan[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Array nama-nama bulan untuk memformat tampilan tanggal lahir
    string namaBulan[13] = {
        "", "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    };

    // Kapasitas maksimal array untuk menampung data
    const int MAX_ORANG = 100;

    // Array untuk menyimpan data input setiap orang
    string nama[MAX_ORANG];
    int tglLahir[MAX_ORANG];
    int blnLahir[MAX_ORANG];
    int thnLahir[MAX_ORANG];

    // Array untuk menyimpan hasil perhitungan umur
    int umurTahun[MAX_ORANG];
    int umurBulan[MAX_ORANG];
    int umurHari[MAX_ORANG];

    int jumlahOrang;
    int tglSekarang, blnSekarang, thnSekarang;

    cout << "========================================\n";
    cout << "   PROGRAM MENGHITUNG UMUR SESEORANG   \n";
    cout << "========================================\n\n";

    // 1. Input tanggal saat ini
    cout << "--- Input Tanggal Saat Ini ---\n";
    cout << "Masukkan tanggal saat ini (1-31) : ";
    cin >> tglSekarang;
    cout << "Masukkan bulan saat ini (1-12)   : ";
    cin >> blnSekarang;
    cout << "Masukkan tahun saat ini          : ";
    cin >> thnSekarang;

    // 2. Input jumlah orang
    cout << "\nMasukkan jumlah orang yang akan dihitung: ";
    cin >> jumlahOrang;

    // 3. Perulangan untuk input data setiap orang ke dalam array
    cout << "\n--- Input Data Setiap Orang ---\n";
    for (int i = 0; i < jumlahOrang; i++) {
        cout << "\nData Orang ke-" << (i + 1) << ":\n";
        cout << "Nama          : ";
        // getline(cin >> ws, ...) digunakan untuk membaca string nama lengkap termasuk spasi
        getline(cin >> ws, nama[i]);
        cout << "Tanggal Lahir : ";
        cin >> tglLahir[i];
        cout << "Bulan Lahir   : ";
        cin >> blnLahir[i];
        cout << "Tahun Lahir   : ";
        cin >> thnLahir[i];
    }

    // 4. Perulangan untuk menghitung umur setiap orang
    for (int i = 0; i < jumlahOrang; i++) {
        int dNow = tglSekarang;
        int mNow = blnSekarang;
        int yNow = thnSekarang;

        // Langkah A: Menghitung selisih hari
        // Jika tanggal sekarang lebih kecil dari tanggal lahir, pinjam hari dari bulan sebelumnya
        if (dNow < tglLahir[i]) {
            int bulanSebelum = mNow - 1;

            // Jika sekarang bulan 1 (Januari), bulan sebelumnya adalah bulan 12 (Desember)
            if (bulanSebelum == 0) {
                bulanSebelum = 12;
            }

            // Tambahkan jumlah hari dari bulan sebelumnya (tanpa kabisat)
            dNow += hariPerBulan[bulanSebelum];
            mNow -= 1; // Kurangi 1 bulan karena sudah dipinjam
        }
        umurHari[i] = dNow - tglLahir[i];

        // Langkah B: Menghitung selisih bulan
        // Jika bulan sekarang lebih kecil dari bulan lahir, pinjam 12 bulan dari tahun sekarang
        if (mNow < blnLahir[i]) {
            mNow += 12; // Pinjam 1 tahun = 12 bulan
            yNow -= 1;  // Kurangi 1 tahun karena sudah dipinjam
        }
        umurBulan[i] = mNow - blnLahir[i];

        // Langkah C: Menghitung selisih tahun
        umurTahun[i] = yNow - thnLahir[i];
    }

    // 5. Menampilkan hasil dalam bentuk tabel
    cout << "\n\n========================================================================================\n";
    cout << left << setw(12) << "Nama" 
         << setw(22) << "Tanggal Lahir" 
         << "Umur" << endl;
    cout << "========================================================================================\n";

    for (int i = 0; i < jumlahOrang; i++) {
        // Format tanggal lahir, contoh: "10 Mei 2000"
        string formatTglLahir = to_string(tglLahir[i]) + " " + namaBulan[blnLahir[i]] + " " + to_string(thnLahir[i]);
        
        // Format umur, contoh: "26 tahun, 5 bulan, 25 hari"
        string formatUmur = to_string(umurTahun[i]) + " tahun, " + 
                            to_string(umurBulan[i]) + " bulan, " + 
                            to_string(umurHari[i]) + " hari";

        cout << left << setw(12) << nama[i] 
             << setw(22) << formatTglLahir 
             << formatUmur << endl;
    }
    cout << "========================================================================================\n";

    return 0;
}
