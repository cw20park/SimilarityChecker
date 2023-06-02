#include <string>

using namespace std;
#define MAX_LENGTH_CHECK_POINT 60

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