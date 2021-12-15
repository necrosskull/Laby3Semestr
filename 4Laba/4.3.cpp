#include <iostream>
#include <iomanip>  
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

//����-��������� �������� � ��� �����
//��� ���� ������ � ������� ������ ����� ��������
bool hamilton(vector<vector<int> >& mat, vector <bool>& visited, vector <int>& path, int curr) //���� � ���� ��� ������ ��������� ��� ������� ���� ������. ����� ������� ���� ����� �����
{
	path.push_back(curr);
	//���� �������� ��� �������: ���� ���� ����� ��������� ������� � ��������, ���� ������
	//���� ���, ������������ �� ��� �����
	if (path.size() == mat.size())
	{
		return true;//�-� ���� (�-� �����������)

		//if(mat[curr][path[0]]>0)
		//{
		//   return true;//�-� ���� (�-� �����������)	
		//}
	}

	//������� ������������ � ����
	visited[curr] = true;
	//��������� ���� ������������ ������� ������� curr

	//����� ���� ������� � ��� ������
	for (int i = 0; i < mat.size(); i++)
	{
		if (mat[curr][i] > 0 && !visited[i])
		{
			if (hamilton(mat, visited, path, i)) //rekursivnya visov
			{
				return true;
			}
		}
	}


	//���� ���� �� ��������, ������� ������� � ������������
	visited[curr] = false;
	path.pop_back();
	return false;
}

int main()
{
	//������� 5�� ������� ��� �������� ����, ��� ���
	vector<vector<int> > mat =
	{
	{ 0, 5, 3, 6, 8, 9, 7, 8, 1, 7, 0, 0, 4, 8 },
	{ 5, 0, 0, 3, 6, 9, 6, 5, 0, 8, 0, 0, 5, 6 },
	{ 3, 0, 0, 2, 8, 1, 3, 0, 8, 8, 5, 5, 8, 4 },
	{ 6, 3, 2, 0, 4, 6, 6, 4, 6, 8, 8, 6, 9, 4 },
	{ 8, 6, 8, 4, 0, 2, 8, 0, 9, 0, 8, 2, 0, 5 },
	{ 9, 9, 1, 6, 2, 0, 8, 5, 5, 9, 8, 8, 9, 8 },
	{ 7, 6, 3, 6, 8, 8, 0, 3, 6, 6, 8, 1, 5, 6 },
	{ 8, 5, 0, 4, 0, 5, 3, 0, 7, 1, 4, 7, 8, 5 },
	{ 1, 0, 8, 6, 9, 5, 6, 7, 0, 1, 2, 5, 2, 2 },
	{ 7, 8, 8, 8, 0, 9, 6, 1, 1, 0, 6, 2, 4, 8 },
	{ 0, 0, 5, 8, 8, 8, 8, 4, 2, 6, 0, 8, 4, 3 },
	{ 0, 0, 5, 6, 2, 8, 1, 7, 5, 2, 8, 0, 5, 5 },
	{ 4, 5, 8, 9, 0, 9, 5, 8, 2, 4, 4, 5, 0, 3 },
	{ 8, 6, 4, 4, 5, 8, 6, 5, 2, 8, 3, 5, 3, 0 }
	};

	vector<bool> visited(6, 0);
	vector<int> path;

	cout << "\nHamilton: " << hamilton(mat, visited, path, 0);

	char c1; cin >> c1;

	char c; std::cin >> c;
	return 0;
}