
#include "../common.h"

// https://leetcode-cn.com/problems/valid-sudoku/
// AC

class Solution 
{
	// Place constraint
	vector<set<int>> m_RowCst;
	vector<set<int>> m_ColCst;
	vector<set<int>> m_BlkCst;
	vector<vector<int>> m_Arrs;

public:

	int coordinateToCellPoint(int row, int col)
	{
		int ret = 0;

		ret = row / 3;
		ret *= 3;  // Must be divide 3 then multiply 3
		ret += col / 3;

		return ret;
	}

	void initConstraint(vector<vector<char>>& board)
	{
		int ret = 0;
		int i = 0, j = 0;
		int a = 0, b = 0;
		set<int> s_row;
		set<int> s_col;
		set<int> s_blk;
		int size = 0;
		int t = 0;
		char c_null = '.';

		
		for (i = 0; i < 9; i++)
		{
			vector<int> vt(9, 0);
			m_Arrs.push_back(vt);
		}

		for (i = 0; i < 9; i++)
		{
			s_row.clear();
			s_col.clear();
			for (j = 0; j < 9; j++)
			{
				t = board[i][j];

				// Init to array
				if (t != c_null) m_Arrs[i][j] = t - '0';
				else m_Arrs[i][j] = 0;

				if (t != c_null) s_row.insert(t);
				t = board[j][i];
				if (t != c_null) s_col.insert(t);
			}
			m_RowCst.push_back(s_row);
			m_ColCst.push_back(s_col);
		}

		for (i = 0; i < 9; i += 3)
		{
			for (j = 0; j < 9; j += 3)
			{
				s_blk.clear();
				for (a = 0; a < 3; a++)
				{
					for (b = 0; b < 3; b++)
					{
						t = board[i + a][j + b];
						if (t != c_null) s_blk.insert(t);
					}
				}
				m_BlkCst.push_back(s_blk);
			}
		}
	}

	set<int> getRemaindElementFromSet(set<int> &cst)
	{
		int i = 0;
		int e = 0;
		set<int> ret;

		for (i = 0; i <= 9; i++)
		{
			if (cst.count(e) == 0) ret.insert(e);
		}
		return ret;
	}

	vector<int> getCommonRemaindElementForOnePoint(int row, int col)
	{
		int i = 0;
		int e = 0;

		vector<int> ret;
		set<int> remRow;
		set<int> remCol;
		set<int> remBlk;
		
		remRow = getRemaindElementFromSet(m_RowCst[row]);
		remCol = getRemaindElementFromSet(m_ColCst[col]);

		i = coordinateToCellPoint(row, col);
		remBlk = getRemaindElementFromSet(m_BlkCst[i]);

		for (i = 1; i <= 9; i++)
		{
			if (remRow.count(i) == 1 &&
				remCol.count(i) == 1 &&
				remBlk.count(i) == 1 )
			{
				ret.push_back(i);
			}
		}
		return ret;
	}

	bool getNextValidPoint(int &nrow, int &ncol)
	{
		int i = 0, j = 0;
		bool ret = true;

		for (i = nrow; i < 9; i++)
		{
			for (j = ncol; j < 9; j++)
			{
				if (m_Arrs[i][j] == 0)
				{
					nrow = i;
					ncol = j;
					return true;
				}
			}
		}

		return false;
	}

	bool placeNextElement(int row, int col)
	{
		int i = 0, j = 0;
		vector<int> rem;
		int blk = 0;
		bool ret = false;
		int nrow = 0, ncol = 0;
		int elem = 0;

		// Find a space location
		nrow = row;
		ncol = col;
		ret = getNextValidPoint(nrow, ncol);
		if (ret == false) return true;   // Finish

		rem = getCommonRemaindElementForOnePoint(nrow, ncol);
		for (i = 0; i < rem.size(); i++)
		{
			elem = rem[i];
			m_Arrs[nrow][ncol] = elem;

			// Add constraints
			blk = coordinateToCellPoint(nrow, ncol);
			m_RowCst[nrow].insert(elem);
			m_ColCst[ncol].insert(elem);
			m_BlkCst[blk].insert(elem);

			ret = placeNextElement(nrow, ncol);
			if (ret == true) return true;

			// Rollback: remove pre constraints
			m_RowCst[nrow].erase(elem);
			m_ColCst[ncol].erase(elem);
			m_BlkCst[blk].erase(elem);
			m_Arrs[nrow][ncol] = 0;
		}

		return false;
	}

	void solveSudoku(vector<vector<char>>& board)
	{
		int ret = 0;
		int i = 0, j = 0;

		initConstraint(board);
		ret = placeNextElement(0, 0);

		// Fill in the board
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') board[i][j] = m_Arrs[i][j] + '0';
			}
		}
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

	sln.solveSudoku(board);
	cout << ret << endl;


	return 0;
}





