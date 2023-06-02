#include <string>

using namespace std;

class SimilarityChecker
{
public:
	int checkLength(string A, string B)
	{
		if (isLengthZero(A, B))
			return 0;

		int gap = calculateGap(A, B);
		if (gap == 0)
			return 60;
		if (gap < 0)
		{
			swap(A, B);
			gap *= -1;
		}

		if (isMoreThanTwice(A.length(), B.length()))
			return 0;

		return 1 * 60 - gap * 60 / B.length();
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

	void swap(string &A, string &B)
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
};