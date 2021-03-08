#include "iostream"
#include "string"
#include "bits/stdc++.h"
#include "fstream"

using namespace std;

int loop = 0;

void OrderChiper(stack<char> s, char mChiper[])
{
	if (s.empty())
		return;

	char x = s.top();
	mChiper[loop] = x;
	loop++;

	s.pop();
	OrderChiper(s, mChiper);
	s.push(x);
}

int main()
{

	char mAbjad[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char mChiper[26];
	bool mExists[26] = {false};
	stack<char> s;
	string mKunci, line, mPesan;

	ifstream myfile("monoalfabetik enkripsi.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			mPesan = line;
		}
		myfile.close();
	}

	cout << "Masukkan kunci = ";
	cin >> mKunci;

	int mP = mKunci.length();

	cout << endl;

	for (int i = 0; i < mP; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (mKunci[i] == mAbjad[j] && (mExists[j] != true))
			{
				mExists[j] = true;
				s.push(mAbjad[j]);
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (mExists[i] == false)
		{
			s.push(mAbjad[i]);
		}
	}

	cout << "Abjad \t:";
	for (int i = 0; i < 26; i++)
	{
		cout << mAbjad[i];
	}
	cout << endl;

	OrderChiper(s, mChiper);

	cout << "Chiper \t:";
	for (int i = 25; i >= 0; i--)
	{
		cout << mChiper[i];
	}
	
	cout << endl;

	cout << "Pesan \t";

	for (int i = 0; i < mPesan.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (mPesan[i] == mAbjad[j])
			{
				cout << mChiper[25 - j];
			}
		}
	}

	cout << endl;
}

