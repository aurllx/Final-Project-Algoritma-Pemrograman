#include <iostream>
#include <string>
// library buat fungsi random
#include <cstdlib> // random/bilangan acak
#include <ctime> //manipulasi waktu
// Library untuk fungsi sort, search, memanipulasi, menghitung
#include <algorithm>
#include <vector> // buat menyimpan variabel sort (array)

using namespace std;

// Fungsi untuk menampilkan pilihan
void kategori(int pilihan)
{
    switch (pilihan)
    {
    case 1:
        cout << "Batu";
        break;
    case 2:
        cout << "Kertas";
        break;
    case 3:
        cout << "Gunting";
        break;
    default:
        cout << "Pilihan tidak valid";
    }
}

// menampilkan pilihan player, komputer dan hasilnya
void displayResult(string uname, int player, int Comp)
{
    cout << "+------------------------------------+\n";
    cout << "| Computer: ";
    kategori(Comp);
    cout << endl;

    cout << "| " << uname << "    : ";
    kategori(player);
    cout << endl;
    cout << "+------------------------------------+\n";
    cout << "| Hasil " << uname << ": ";
}

// Fungsi untuk menampilkan Score
void Score(int scorePlayer, int scoreComp, string uname)
{
    cout << "+-----------Score Sementara----------+\n";
    cout << "| Score " << uname << ": " << scorePlayer << endl;
    cout << "| Score Computer: " << scoreComp << endl;
    cout << "+------------------------------------+\n";
}

// array and sort
void SortWinner(int scorePlayer, int scoreComp, string uname)
{
    int ScoreAkhir[] = {scorePlayer, scoreComp};
    sort(ScoreAkhir, ScoreAkhir + 2, greater<int>());

    cout << endl;

    if (scorePlayer == ScoreAkhir[0])
    {
        cout << "+----------------Win!----------------+\n";
        cout << "| " << uname << ": Juara I \n";
        cout << "| Computer: Juara II \n";
    }
    else if (scoreComp == ScoreAkhir[0])
    {
        cout << "+----------------Lose!---------------+\n";
        cout << "| Computer: Juara I \n";
        cout << "| " << uname << ": Juara II \n";
    }

    cout << "+------------------------------------+\n"
         << endl;
}

// Fungsi untuk menampilkan Score per Round
void displayRound(const int maxRounds, const int scoreRound[][2], string uname)
{
    cout << "+----------Data Array Score----------+\n";
    cout << "|                                    |\n";
    for (int round = 0; round < maxRounds; ++round)
    {
        // cout << "| Round ke-" << round + 1 << ": \n";
        cout << "+-------------Round Ke-" << round + 1 << "-------------+\n";
        cout << "| Score " << uname << ": " << scoreRound[round][0] << endl;
        cout << "| Score Computer: " << scoreRound[round][1] << endl
             << endl;
    }
    cout << "+------------------------------------+\n";
}

// Fungsi untuk mencari Score tertinggi pada suatu Round / sort
void searchRound(const int maxRounds, const int scoreRound[][2], string uname)
{
    int cari, ditemukan = 0;
    cout << "| Cari Round: ";
    cin >> cari;
    for (int round = 0; round < maxRounds; ++round)
    {
        if (round + 1 == cari) // Sesuaikan dengan nomor Round yang dimasukkan pengguna
        {
            ditemukan++;
            // cout << "| Round ke-" << round + 1 << ": \n";
            cout << "+-------------Round Ke-" << round + 1 << "-------------+\n";
            cout << "| Score " << uname << ": " << scoreRound[round][0] << endl;
            cout << "| Score Computer: " << scoreRound[round][1] << endl;
        }
    }

    if (ditemukan == 0)
    {
        cout << "+------------------------------------+\n";
        cout << "| Round Not Found!" << endl;
    }
    cout << "+------------------------------------+\n";
}

int main()
{
    string uname;
    int maxRounds, scorePlayer = 0, scoreComp = 0, rounds = 1;

    cout << endl
         << "+-------------Let's Play-------------+\n";
    cout << "| Username: ";
    getline(cin, uname);
    cout << "| max. Round: ";
    cin >> maxRounds;

    // Batasan jumlah Round, sesuaikan sesuai kebutuhan
    const int MAX_ROUNDS = 100;

    // Matriks untuk menyimpan Score, Kolom 0: Score Anda, Kolom 1: Score Comp
    int scoreRound[MAX_ROUNDS][2] = {0};

    while (rounds <= maxRounds)
    {
        int player, Comp;

        srand(time(0)); // Inisialisasi generator angka acak

        cout << "\n+-------------Round Ke-" << rounds << "-------------+\n";
        cout << "| 1. Batu\n";
        cout << "| 2. Kertas\n";
        cout << "| 3. Gunting\n";
        cout << "| 0. Game Over!\n";
        cout << "+------------------------------------+\n";
        cout << "| Masukkan pilihan (1/2/3/0): ";
        cin >> player;

        if (player == 0)
        {
            break; // Keluar dari permainan
        }

        if (player < 1 || player > 3)
        {
            cout << "+------------------------------------+\n";
            cout << "| Pilihan tidak valid.\n";
            continue; // Mengulang loop
        }

        Comp = rand() % 3 + 1;

        // fungsi winner
        displayResult(uname, player, Comp);
        if (player == Comp)
        {
            cout << "Seri!\n";
        }
        else if ((player == 1 && Comp == 3) ||
                 (player == 2 && Comp == 1) ||
                 (player == 3 && Comp == 2))
        {
            cout << "menang!\n";
            scorePlayer++;
        }
        else
        {
            cout << "Kalah!\n";
            scoreComp++;
        }

        // Menyimpan Score per Round ke dalam matriks
        scoreRound[rounds - 1][0] = scorePlayer;
        scoreRound[rounds - 1][1] = scoreComp;

        rounds++;
        Score(scorePlayer, scoreComp, uname);
    }

    // fungsi sort
    SortWinner(scorePlayer, scoreComp, uname);
    // fungsi array round dan score
    displayRound(maxRounds, scoreRound, uname);
    // fungsi search
    searchRound(maxRounds, scoreRound, uname);

    return 0;
}