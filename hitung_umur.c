#include <stdio.h>
#include <string.h>

int main() {
    // Array jumlah hari untuk setiap bulan (1 = Januari s.d. 12 = Desember)
    // Februari dianggap tetap 28 hari (tanpa perhitungan tahun kabisat)
    int hariPerBulan[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Array nama-nama bulan untuk memformat tampilan tanggal lahir
    const char *namaBulan[13] = {
        "", "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    };

    // Kapasitas maksimal array untuk menampung data
    const int MAX_ORANG = 100;

    // Array untuk menyimpan data input setiap orang
    char nama[MAX_ORANG][50];
    int tglLahir[MAX_ORANG];
    int blnLahir[MAX_ORANG];
    int thnLahir[MAX_ORANG];

    // Array untuk menyimpan hasil perhitungan umur
    int umurTahun[MAX_ORANG];
    int umurBulan[MAX_ORANG];
    int umurHari[MAX_ORANG];

    int jumlahOrang;
    int tglSekarang, blnSekarang, thnSekarang;

    printf("========================================\n");
    printf("   PROGRAM MENGHITUNG UMUR SESEORANG   \n");
    printf("========================================\n\n");

    // 1. Input tanggal saat ini
    printf("--- Input Tanggal Saat Ini ---\n");
    printf("Masukkan tanggal saat ini (1-31) : ");
    scanf("%d", &tglSekarang);
    printf("Masukkan bulan saat ini (1-12)   : ");
    scanf("%d", &blnSekarang);
    printf("Masukkan tahun saat ini          : ");
    scanf("%d", &thnSekarang);

    // 2. Input jumlah orang
    printf("\nMasukkan jumlah orang yang akan dihitung: ");
    scanf("%d", &jumlahOrang);

    // 3. Perulangan untuk input data setiap orang ke dalam array
    printf("\n--- Input Data Setiap Orang ---\n");
    for (int i = 0; i < jumlahOrang; i++) {
        printf("\nData Orang ke-%d:\n", i + 1);
        printf("Nama          : ");
        // scanf(" %[^\n]") digunakan untuk membaca string nama lengkap termasuk spasi
        scanf(" %[^\n]", nama[i]);
        printf("Tanggal Lahir : ");
        scanf("%d", &tglLahir[i]);
        printf("Bulan Lahir   : ");
        scanf("%d", &blnLahir[i]);
        printf("Tahun Lahir   : ");
        scanf("%d", &thnLahir[i]);
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
    printf("\n\n========================================================================================\n");
    printf("%-12s %-22s %s\n", "Nama", "Tanggal Lahir", "Umur");
    printf("========================================================================================\n");

    for (int i = 0; i < jumlahOrang; i++) {
        char formatTglLahir[50];
        char formatUmur[50];

        // Format tanggal lahir, contoh: "10 Mei 2000"
        sprintf(formatTglLahir, "%d %s %d", tglLahir[i], namaBulan[blnLahir[i]], thnLahir[i]);

        // Format umur, contoh: "26 tahun, 5 bulan, 25 hari"
        sprintf(formatUmur, "%d tahun, %d bulan, %d hari", umurTahun[i], umurBulan[i], umurHari[i]);

        printf("%-12s %-22s %s\n", nama[i], formatTglLahir, formatUmur);
    }
    printf("========================================================================================\n");

    return 0;
}
