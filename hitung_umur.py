# ==============================================================================
# PROGRAM MENGHITUNG UMUR SESEORANG (SOAL TIPE 2)
# Bahasa Pemrograman: Python (Tanpa Perhitungan Tahun Kabisat)
# Ditujukan untuk: Mahasiswa Informatika Semester 1 (Dasar Pemrograman)
# ==============================================================================

def main():
    # Array jumlah hari untuk setiap bulan (index 0 dikosongkan agar index 1 = Januari)
    # Februari dianggap tetap 28 hari (tanpa perhitungan tahun kabisat)
    hari_per_bulan = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    # Array daftar nama bulan untuk keperluan menampilkan tanggal lahir dalam format teks
    nama_bulan = [
        "", "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    ]

    print("========================================")
    print("   PROGRAM MENGHITUNG UMUR SESEORANG   ")
    print("========================================\n")

    # 1. Program meminta input tanggal, bulan, dan tahun saat ini
    print("--- Input Tanggal Saat Ini ---")
    tgl_sekarang = int(input("Masukkan tanggal saat ini (1-31) : "))
    bln_sekarang = int(input("Masukkan bulan saat ini (1-12)   : "))
    thn_sekarang = int(input("Masukkan tahun saat ini          : "))

    # 2. Program meminta pengguna memasukkan jumlah orang yang akan dihitung umurnya
    jumlah_orang = int(input("\nMasukkan jumlah orang yang akan dihitung: "))

    # Array (list) untuk menyimpan data input setiap orang
    nama = []
    tgl_lahir = []
    bln_lahir = []
    thn_lahir = []

    # Array (list) untuk menyimpan hasil perhitungan umur
    umur_tahun = []
    umur_bulan = []
    umur_hari = []

    # 3. Gunakan perulangan untuk melakukan proses input data ke dalam array
    print("\n--- Input Data Setiap Orang ---")
    for i in range(jumlah_orang):
        print(f"\nData Orang ke-{i + 1}:")
        input_nama = input("Nama          : ")
        input_tgl = int(input("Tanggal Lahir : "))
        input_bln = int(input("Bulan Lahir   : "))
        input_thn = int(input("Tahun Lahir   : "))

        # Menyimpan ke dalam array (list)
        nama.append(input_nama)
        tgl_lahir.append(input_tgl)
        bln_lahir.append(input_bln)
        thn_lahir.append(input_thn)

    # 4. Gunakan perulangan untuk melakukan perhitungan umur setiap orang
    for i in range(jumlah_orang):
        d_now = tgl_sekarang
        m_now = bln_sekarang
        y_now = thn_sekarang

        # --- Langkah A: Menghitung selisih hari ---
        # Jika tanggal sekarang lebih kecil dari tanggal lahir, pinjam hari dari bulan sebelumnya
        if d_now < tgl_lahir[i]:
            bln_sebelum = m_now - 1

            # Jika sekarang Januari (bulan 1), bulan sebelumnya adalah Desember (bulan 12)
            if bln_sebelum == 0:
                bln_sebelum = 12

            # Pinjam jumlah hari dari bulan sebelumnya (tanpa kabisat)
            d_now += hari_per_bulan[bln_sebelum]
            m_now -= 1  # Bulan sekarang berkurang 1 karena sudah dipinjam

        hasil_hari = d_now - tgl_lahir[i]

        # --- Langkah B: Menghitung selisih bulan ---
        # Jika bulan sekarang lebih kecil dari bulan lahir, pinjam 12 bulan dari tahun sekarang
        if m_now < bln_lahir[i]:
            m_now += 12
            y_now -= 1  # Tahun sekarang berkurang 1 karena sudah dipinjam

        hasil_bulan = m_now - bln_lahir[i]

        # --- Langkah C: Menghitung selisih tahun ---
        hasil_tahun = y_now - thn_lahir[i]

        # Simpan hasil perhitungan ke dalam array
        umur_tahun.append(hasil_tahun)
        umur_bulan.append(hasil_bulan)
        umur_hari.append(hasil_hari)

    # 5. Tampilkan umur setiap orang dalam bentuk tabel (tahun, bulan, dan hari)
    print("\n\n" + "=" * 80)
    print(f"{'Nama':<12} {'Tanggal Lahir':<22} {'Umur'}")
    print("=" * 80)

    for i in range(jumlah_orang):
        format_tgl_lahir = f"{tgl_lahir[i]} {nama_bulan[bln_lahir[i]]} {thn_lahir[i]}"
        format_umur = f"{umur_tahun[i]} tahun, {umur_bulan[i]} bulan, {umur_hari[i]} hari"
        print(f"{nama[i]:<12} {format_tgl_lahir:<22} {format_umur}")

    print("=" * 80)

if __name__ == "__main__":
    main()
