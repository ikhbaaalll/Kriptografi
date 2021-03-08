#include "iostream"
#include "cmath"
#include "fstream"

using namespace std;

int main()
{
	char mAbjad[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	string mPesan, mKunci, mHasil = "";

	ofstream myfile;
	myfile.open("vinegere chiper.txt");

	cout << "Masukkan chiperteks = ";
	cin >> mPesan;

	cout << "Masukkan kunci = ";
	cin >> mKunci;

	int mPanjangPesan = mPesan.length();
	int mPanjangKunci = mKunci.length();
	int x = 0, i = 0;
	int arrayPesan[mPanjangPesan], arrayKunci[mPanjangPesan];
	for (int j = 0; j < mPanjangPesan; j++)
	{
		if (x == mPanjangKunci)
			x = 0;
		for (int k = 0; k < 26; k++)
		{
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
			if (mPesan[j] == mAbjad[k])
			{
				arrayKunci[j] = k;
				break;
			}
		}
	}

	int arrayP[mPanjangPesan];

	for (int j = 0; j < mPanjangPesan; j++)
	{
		if (arrayKunci[j] - arrayPesan[j] < 0)
		{
			arrayP[j] = 26 - abs(arrayKunci[j] - arrayPesan[j]);
		}
		else
		{
			arrayP[j] = arrayKunci[j] - arrayPesan[j];
		}
		cout << mAbjad[arrayP[j] % 26];
		mHasil += mAbjad[arrayP[j] % 26];
	}
	myfile << mHasil;
	myfile.close();
}

