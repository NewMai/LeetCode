
#include "../common.h"

// https://leetcode-cn.com/problems/valid-sudoku/
// AC

class Solution 
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		int ret = 0;
		int i = 0, j = 0;
		int a = 0, b = 0;
		set<char> s;
		int size = 0;
		int t = 0;

		for (i = 0; i < 9; i++)
		{
			s.clear();
			for (j = 0; j < 9; j++)
			{
				t = board[i][j];
				if( t != '.')
				{
					size = s.size();
					s.insert(t);
					if (s.size() == size) return false;
				}
			}
			s.clear();
			for (j = 0; j < 9; j++)
			{
				if (board[j][i] != '.')
				{
					size = s.size();
					s.insert(board[j][i]);
					if (s.size() == size) return false;
				}
			}
		}

		for (i = 0; i < 9; i += 3)
		{
			for (j = 0; j < 9; j += 3)
			{
				s.clear();
				for (a = 0; a < 3; a++)
				{
					for (b = 0; b < 3; b++)
					{
						t = board[i + a][j + b];
						if (t != '.')
						{
							size = s.size();
							s.insert(t);
							if (s.size() == size) return false;
						}
					}
				}
			}
		}

		return true;
	}

};


int main()
{
	Solution sln;
	int ret = 0;
	string str = "test";
	vector<vector<char>> board;

	// Todo: Init board
	// 

	ret = sln.isValidSudoku(board);
	cout << ret << endl;


	return 0;
}





