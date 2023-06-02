#include <string>

using namespace std;
#define MAX_LENGTH_CHECK_POINT (60)
#define MAX_ALPHABET (26)

class SimilarityChecker
{
public:
	int checkLength(string A, string B)
	{
		if (isLengthZero(A, B))
			return 0;

		int gap = calculateGap(A, B);
		if (gap == 0)
			return MAX_LENGTH_CHECK_POINT;
		if (gap < 0)
		{
			swap(A, B);
			gap *= -1;
		}

		if (isMoreThanTwice(A.length(), B.length()))
			return 0;

		return 1 * MAX_LENGTH_CHECK_POINT - gap * MAX_LENGTH_CHECK_POINT / B.length();
	}
	int checkSameAlphabetCount(string A, string B)
	{
		int totalCount = 0;
		int sameCount = 0;

		initTotalAlphabetFlag();
		setTotalAlphabetFlag(A);
		setTotalAlphabetFlag(B);
		totalCount = countTotalAlphabetFlag();
		sameCount = calculateSameCount(A, B);

		return sameCount * 40 / totalCount;
	}
private:
	bool isLengthZero(string A, string B)
	{
		if (A.length() == 0 || B.length() == 0)
			return true;
		else
			return false;
	}
	int calculateGap(string A, string B)
	{
		int gap = A.length() - B.length();
		return gap;
	}
	void swap(string& A, string& B)
	{
		string temp = A;
		A = B;
		B = temp;
	}
	bool isMoreThanTwice(int a, int b)
	{
		if (a >= b * 2)
			return true;
		return false;
	}

	void initTotalAlphabetFlag()
	{
		for (int i = 0; i < MAX_ALPHABET; i++)
		{
			totalAlphabetFlag[i] = 0;
		}
	}
	void setTotalAlphabetFlag(string str)
	{
		for (char c = 0; c < str.length(); c++)
		{
			int alphabetNum = alphabetToNum(str[c]);
			if (totalAlphabetFlag[alphabetNum] == 0)
				totalAlphabetFlag[alphabetNum]++;
		}
	}
	int alphabetToNum(char c)
	{
		return c - 'A';
	}
	char numToAlphabet(int num)
	{
		return num + 'A';
	}
	int countTotalAlphabetFlag()
	{
		int totalCount = 0;
		for (int i = 0; i < MAX_ALPHABET; i++)
		{
			if (totalAlphabetFlag[i])
				totalCount++;
		}
		return totalCount;
	}
	int calculateSameCount(string A, string B)
	{
		int sameCount = 0;
		for (int i = 0; i < MAX_ALPHABET; i++)
		{
			if (totalAlphabetFlag[i] == 0)
				continue;

			char alphabet = numToAlphabet(i);
			if (isExist(alphabet, A) && isExist(alphabet, B))
			{
				sameCount++;
				totalAlphabetFlag[i] = 0;
			}
		}
		return sameCount;
	}
	bool isExist(char c, string str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == c)
				return true;
		}
		return false;
	}

	int totalAlphabetFlag[26] = { 0, };
};