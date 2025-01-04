#include <stdio.h>
#include <string.h>

// Definisi struct untuk data pegawai
struct Pegawai
{
    char nip[20];
    char nama[50];
    char alamat[100];
    char no_hp[15];
    char jabatan[30];
    char golongan[3];
    float gaji_pokok;
    float lembur_per_jam;
};

void inputDataPegawai(struct Pegawai *dataPegawai)
{
    printf("Masukkan Nomor Induk Pegawai: ");
    scanf("%s", dataPegawai->nip);
    getchar(); // Membersihkan buffer input

    printf("Masukkan Nama: ");
    fgets(dataPegawai->nama, sizeof(dataPegawai->nama), stdin);
    dataPegawai->nama[strcspn(dataPegawai->nama, "\n")] = '\0'; // menghapus newline

    printf("Masukkan Alamat: ");
    fgets(dataPegawai->alamat, sizeof(dataPegawai->alamat), stdin);
    dataPegawai->alamat[strcspn(dataPegawai->alamat, "\n")] = '\0';

    printf("Masukkan No.HP: ");
    scanf("%s", dataPegawai->no_hp);

    printf("Masukkan Jabatan: ");
    getchar();
    fgets(dataPegawai->jabatan, sizeof(dataPegawai->jabatan), stdin);
    dataPegawai->jabatan[strcspn(dataPegawai->jabatan, "\n")] = '\0';

    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf("%s", dataPegawai->golongan);

    if (strcmp(dataPegawai->golongan, "D1") == 0)
    {
        dataPegawai->gaji_pokok = 2500000;
        dataPegawai->lembur_per_jam = 10000;
    }
    else if (strcmp(dataPegawai->golongan, "D2") == 0)
    {
        dataPegawai->gaji_pokok = 2000000;
        dataPegawai->lembur_per_jam = 5000;
    }
    else if (strcmp(dataPegawai->golongan, "D3") == 0)
    {
        dataPegawai->gaji_pokok = 1500000;
        dataPegawai->lembur_per_jam = 2500;
    }
    else
    {
        printf("Golongan tidak valid!\n");
        dataPegawai->gaji_pokok = 0;
        dataPegawai->lembur_per_jam = 0;
    }
}

void displayDataPegawai(struct Pegawai dataPegawai)
{
    printf("\n--- Informasi Data Pegawai ---\n");
    printf("NIP: %s\n", dataPegawai.nip);
    printf("Nama: %s\n", dataPegawai.nama);
    printf("Alamat: %s\n", dataPegawai.alamat);
    printf("No HP: %s\n", dataPegawai.no_hp);
    printf("Jabatan: %s\n", dataPegawai.jabatan);
    printf("Golongan: %s\n", dataPegawai.golongan);
    printf("Gaji Pokok: Rp %.2f \n", dataPegawai.gaji_pokok);
}

void totalGaji(struct Pegawai dataPegawai)
{
    int jam_lembur;
    printf("\nMasukkan Jumlah Jam Lembur: ");
    scanf("%d", &jam_lembur);

    float total_gaji = dataPegawai.gaji_pokok + (jam_lembur * dataPegawai.lembur_per_jam);

    printf("\n--- Total Gaji Bulan Ini ---\n");
    printf("NIP: %s\n", dataPegawai.nip);
    printf("Golongan: %s\n", dataPegawai.golongan);
    printf("Lemburan: %d jam\n", jam_lembur);
    printf("Total Gaji Bulan ini: Rp %.2f\n", total_gaji);
}

int main()
{

    struct Pegawai dataPegawai;
    inputDataPegawai(&dataPegawai);
    displayDataPegawai(dataPegawai);
    totalGaji(dataPegawai);

    return 0;
}