#include <iostream>
#include <string>

using namespace std;

struct Transaksi {
    string jenis, tanggal, jumlah;   
};

int main() { system("cls");
    string akses[4][4] = {//array untuk data login
        {"anwar100", "100", "M. Kaspul Anwar", "10000000"},
        {"sofia200", "200", "Sofia Amara Putri Anwar", "400000"},
        {"zahra300", "300", "Zahra Farah Anwar", "200000"},
        {"nabila400", "400", "Nabila Anwar Al-Farisi", "800000"}
    };
    Transaksi mutasi[100]; //aray data mutasi
    int jumlah_transaksi = 0;  

    string nomor_kartu, kode_akses, ulangi_transaksi, ulangi_login;
    bool ditemukan = false;
    int index_ditemukan = -1;
    int menu_utama, login_menu;

    do {
        cout << "========================================" << endl;
        cout << "             MOBILE BANKING" << endl;
        cout << "           App By Anwar Group" << endl;
        cout << "========================================" << endl;

  
        cout << "           1. Mobile Login" << endl;
        cout << "           2. Buka Rekening baru" << endl;
        cout << "           3. Ganti Kode Akses" << endl;
        cout << "           4. Mobile Info" << endl << endl;

        cout << "     Selamat datang di Mobile Banking" << endl;
        cout << "========================================" << endl;
        cout << endl << endl;

        cout << "Masukkan pilihan anda = ";
        cin >> menu_utama;

        switch (menu_utama) {
            case 1:
                system("cls");

                cout << "===============================================================" << endl;
                cout << "              *Jika 3 Salah Memasukkan Kode Akses*" << endl;
                cout << "               *Maka Akun Anda Akan Kami Blokir*" << endl;
                cout << "===============================================================" << endl;

                cout << "Masukkan Nomor Kartu: " << endl;
                cin >> nomor_kartu;
                cout << "Masukkan Kode Akses: " << endl;
                cin >> kode_akses;

                
                for (int i = 0; i < 4; ++i) {//Sequential Search
                    if (akses[i][0] == kode_akses && akses[i][1] == nomor_kartu) {
                        ditemukan = true;
                        index_ditemukan = i; 
                        break;
                    }
                } system("cls");

                for (volatile int i = 0; i < 1000000000; ++i) {}

                if (ditemukan) {
                    string nama_pengguna = akses[index_ditemukan][2];
                    cout << "                   Login Berhasil" << endl << endl;
                    cout << " Tunggu Sebentar..............." << endl;

                    for (volatile int i = 0; i < 1000000000; ++i) {}
                    do {system("cls");

                        cout << "========================================" << endl;
                        cout << "             MOBILE BANKING" << endl;
                        cout << "           App By Anwar Group" << endl;
                        cout << "========================================" << endl << endl;
                        cout << "     Selamat Datang, " << nama_pengguna << endl << endl;
                        cout << "           1. Cek Saldo" << endl;
                        cout << "           2. Setoran" << endl;
                        cout << "           3. Tarik Tunai" << endl;
                        cout << "           4. Mutasi Rekening" << endl;
                        cout << "           5. Mobile Virtual Account" << endl;
                        cout << "           6. Info Rekening" << endl << endl;
                   
                        cout << "Masukkan Pilihan Anda: ";
                        cin >> login_menu;

                        switch (login_menu) {
                            case 1:
                                cout << "Saldo Anda saat ini adalah: Rp " << akses[index_ditemukan][3] << endl;
                                break;
                            case 2:
                            {
                                string jumlah_setoran;
                                cout << "Masukkan jumlah yang akan disetor: ";
                                cin >> jumlah_setoran;

                                int saldo_sekarang = stoi(akses[index_ditemukan][3]); 
                                int setoran = stoi(jumlah_setoran);  
                                saldo_sekarang += setoran;

                                akses[index_ditemukan][3] = to_string(saldo_sekarang);


                                mutasi[jumlah_transaksi].jenis = "Setoran";
                                mutasi[jumlah_transaksi].tanggal = "08-06-2024"; 
                                mutasi[jumlah_transaksi].jumlah = jumlah_setoran;
                                jumlah_transaksi++;

                                cout << "Setoran berhasil." << endl;
                                break;
                            }
                            case 3:
                            {
                                string jumlah_tarikan;
                                cout << "Masukkan jumlah yang akan ditarik: ";
                                cin >> jumlah_tarikan;

                                int saldo_sekarang = stoi(akses[index_ditemukan][3]);  
                                int tarikan = stoi(jumlah_tarikan); 

                                if (tarikan > saldo_sekarang) {
                                    cout << "Saldo tidak mencukupi untuk melakukan penarikan." << endl;
                                } else {
                                    saldo_sekarang -= tarikan;

                                    
                                    akses[index_ditemukan][3] = to_string(saldo_sekarang);
                                 
                                    mutasi[jumlah_transaksi].jenis = "Tarik Tunai";
                                    mutasi[jumlah_transaksi].tanggal = "08-06-2024"; 
                                    mutasi[jumlah_transaksi].jumlah = jumlah_tarikan;
                                    jumlah_transaksi++;

                                    cout << "Tarik Tunai berhasil." << endl;
                                }
                                break;
                            }
                            case 4:  
                            {
                                cout << "Riwayat Mutasi Rekening:" << endl;
                                for (int i = 0; i < jumlah_transaksi; ++i) {
                                    cout << "Tanggal: " << mutasi[i].tanggal << " | Jenis: " << mutasi[i].jenis << " | Jumlah: " << mutasi[i].jumlah << endl;
                                }
                                break;
                            }
                            case 5: system("cls");
                            cout<<"Fitur Ini Masih dalam Tahap Pengembangan"<<endl;
                            break;

                            case 6: system("cls");
                            cout<<"Info Rekening anda:"<<endl<<endl;
                            cout<<"       Nama:           "<<nama_pengguna<<endl;
                            cout<<"       Tanggal Lahir:  Tempat, xx Bulan xxx"<<endl;
                            cout<<"       Jenis Kartu:    Debit Regular"<<endl;
                            cout<<"       Limit:          Penarikan 20 Juta/Bulan"<<endl;

                            break;

                            default: system("cls");
                                cout << "Pilihan tidak valid." << endl;
                                break;
                        }
                    
                        cout << endl << "Apakah Anda ingin melakukan transaksi lagi? (y/n): ";
                        cin >> ulangi_transaksi;
                        

                    } while (ulangi_transaksi == "y");

                } else {
                    cout << "Akses dan Nomer Kartu Salah." << endl;
                    cout << "Silahkan Login Kembali...........";
                }
                break;
        }
        system("cls");
        cout << endl << "Apakah Anda ingin melakukan login lagi? (y/n): ";
        cin >> ulangi_login;

    } while (ulangi_login == "y");
    system("cls");
    cout << "========================================================="<<endl;
    cout << "                     TERIMA KASIH"<< endl;
    cout << "========================================================="<<endl;
    cout << "         Sudah Bertransaksi Dengan Mobile Banking"<<endl;
    cout << "        App made by M. Kaspul Anwar (230104040212)"<<endl<<endl<<endl;
}
