#include "iostream"
#include "fstream"
#include "string"

using namespace std;

int main()
{
	// Inisialisasi abjad
	char mAbjad[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	string mPesan, mKunci, line;

	ifstream myfile("vinegere plaintext.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			mPesan = line;
		}
		myfile.close();
	}

	// Input kunci
	cout << "Masukkan kunci = ";
	cin >> mKunci;

	int mPanjangPesan = mPesan.length();
	int mPanjangKunci = mKunci.length();
	int x = 0;

	// Inisialisasi array pesan dan kunci sebanyak panjang pesan
	int arrayPesan[mPanjangPesan], arrayKunci[mPanjangPesan];

	for (int j = 0; j < mPanjangPesan; j++)
	{
		// Jika x sama dengan index panjang kunci maka set var x = 0
		if (x == mPanjangKunci)
			x = 0;
		for (int k = 0; k < 26; k++)
		{
			// Jika mKunci dengan index x sama dengan mAbjad dengan index k
			// Maka set arrayPesan index j di isi dengan k
			if (mKunci[x] == mAbjad[k])
			{
				arrayPesan[j] = k;
				break;
			}
		}
		x++;
	}

	for (int j = 0; j < mPanjangPesan; j++)
	{
		for (int k = 0; k < 26; k++)
		{
			// Jika mPesan dengan index j sama dengan mAbjd dengan index k
			// Maka set arrayKunci index j di isi dengan k
			if (mPesan[j] == mAbjad[k])
			{
				arrayKunci[j] = k;
				break;
			}
		}
	}

	cout << "Pesan \t:" << mPesan << endl;
	cout << "Kunci \t:" << mKunci << endl;
	cout << "Chiper \t:";

	// Output hasil enkripsi dengan arrayKunci index j ditambah arrayPesan index j dan dimodulus 26
	for (int j = 0; j < mPanjangPesan; j++)
	{
		cout << mAbjad[(arrayKunci[j] + arrayPesan[j]) % 26];
	}
}


