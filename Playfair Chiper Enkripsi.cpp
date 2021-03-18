#include "iostream"
#include "algorithm"
#include "string"
#include "bits/stdc++.h"
#include "fstream"

using namespace std;

int loop = 0;
char mMatriksBigram[5][5];

void OrderChiper(stack<char> s, char mMatriks[])
{
	if (s.empty())
		return;

	char x = s.top();
	mMatriks[loop] = x;
	loop++;

	s.pop();
	OrderChiper(s, mMatriks);
	s.push(x);
}

int main()
{
	char mAbjad[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char mMatriks[25];
	bool mExists[25] = {false};
	stack<char> s;

	string mKunci;
	cout << "Kunci : ";
	cin >> mKunci;
	// Menentukan array
	for (int i = 0; i < mKunci.length(); i++)
	{
		for (int j = 0; j < sizeof(mAbjad); j++)
		{
			if (mKunci[i] == mAbjad[j] && mExists[j] == false)
			{
				mExists[j] = true;
				s.push(mAbjad[j]);
				break;
			}
		}
	}
	// Memasukkan sisa abjad yang belum dipush kedalam array
	for (int i = 0; i < sizeof(mAbjad); i++)
	{
		if (mExists[i] == false)
		{
			s.push(mAbjad[i]);
		}
	}

	OrderChiper(s, mMatriks);

	// Mengubah array ke Matriks 5 x 5
	int x = 24;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			mMatriksBigram[i][j] = mMatriks[x];
			x--;
		}
	}

	//Output Matriks
	cout << endl
		 << "Matriks :" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << mMatriksBigram[i][j] << " ";
		}
		cout << endl;
	}

	string mPlainteks, line;
	ifstream file("playfair chiper encrypt.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			mPlainteks = line;
		}
		file.close();
	}

	string mFixPlainteks = "";

	// Membuat bigram 2 huruf
	for (int i = 0; i < mPlainteks.length(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (mPlainteks[i] == mMatriksBigram[j][k])
				{
					if (i % 2 == 0)
					{
						if (mPlainteks[i + 1] == mPlainteks[i])
						{
							mFixPlainteks += mPlainteks[i + 1];
							mFixPlainteks += "x";
						}
						else
						{
							mFixPlainteks += mMatriksBigram[j][k];
						}
					}
					else if (i % 2 == 1)
					{
						if (mPlainteks[i + 1] == mPlainteks[i])
						{
							mFixPlainteks += mPlainteks[i + 1];
							mFixPlainteks += "x";
						}
						else
						{
							mFixPlainteks += mMatriksBigram[j][k];
						}
					}
				}
			}
		}
	}

	if (mFixPlainteks.length() % 2 == 1)
	{
		mFixPlainteks += "x";
	}

	// Output Bigram dari proses diatas
	cout << endl
		 << "Bigram \t: ";

	for (int i = 0; i < mFixPlainteks.length(); i += 2)
	{
		cout << mFixPlainteks[i] << mFixPlainteks[i + 1] << " ";
	}

	cout << endl;
	string mChiper = "";

	for (int i = 0; i < mFixPlainteks.length(); i += 2)
	{
		int a, b, c, d;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (mFixPlainteks[i] == mMatriksBigram[j][k])
				{
					a = j;
					b = k;
				}
			}
		}
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (mFixPlainteks[i + 1] == mMatriksBigram[j][k])
				{
					c = j;
					d = k;
				}
			}
		}
		if (a == c)
		{
			if (b == 4 || d == 4)
			{
				if (b == 4)
				{
					mChiper += mMatriksBigram[a][0];
					mChiper += mMatriksBigram[c][d + 1];
				}
				if (d == 4)
				{
					mChiper += mMatriksBigram[a][b + 1];
					mChiper += mMatriksBigram[c][0];
				}
			}
			else
			{
				mChiper += mMatriksBigram[a][b + 1];
				mChiper += mMatriksBigram[c][d + 1];
			}
			continue;
		}
		if (b == d)
		{
			if (a == 4 || c == 4)
			{
				if (a == 4)
				{
					mChiper += mMatriksBigram[0][b];
					mChiper += mMatriksBigram[c + 1][d];
				}
				if (c == 4)
				{
					mChiper += mMatriksBigram[a + 1][b];
					mChiper += mMatriksBigram[0][d];
				}
			}
			else
			{
				mChiper += mMatriksBigram[a + 1][b];
				mChiper += mMatriksBigram[c + 1][d];
			}
			continue;
		}
		mChiper += mMatriksBigram[a][d];
		mChiper += mMatriksBigram[c][b];
	}

	cout << "Chiper : ";
	for (int i = 0; i < mChiper.length(); i += 2)
	{
		cout << mChiper[i] << mChiper[i + 1] << " ";
	}
}
