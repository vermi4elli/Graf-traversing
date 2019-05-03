#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <set>
#include <queue>
using namespace std;

string delim = "\n\n=============================================================\n\n\n";
const int I = 10000;

class Graf {
private:
	vector<vector<int>> adjMatrix;
	int size;
	int length;
public:
	Graf() {
		size = 0;
		length = 0;
	}
	int GetSize();
	void FillRandomly();
	void FillManually();
	void FillVariant();
	void Print();
	void BFS();
	void DFSInitialization();
	void DFS(int& start, set<int>& used, int& temp);
	void Dijkstra(const int& start, const bool& check);
	void DijkstraForAll();
	void Bellman(const int& start);
	void Floyd();
};
int Graf::GetSize() {
	return size;
}
void Graf::FillRandomly() {
	srand(time(0));
	cout << delim;
	cout << "Enter the amount of vertexes you want: ";
	int size = 0;
	cin >> size;
	this->size = size;
	string length;
	vector<vector<int>> Matrix(size, vector<int>(size, I));
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			if (i == j) {
				Matrix[i][j] = 0;
				continue;
			}
			if (Matrix[i][j] != 0 && Matrix[i][j] != I) continue;
			if (rand() % 2) continue;
			int temp = rand() % 20 + 1;
			Matrix[i][j] = temp;
			Matrix[j][i] = temp;
			if (length.length() < to_string(temp).length()) length = to_string(temp);
		}
	}
	this->adjMatrix = Matrix;
	this->length = length.length();
	length = to_string(this->size);
	if (length.length() > this->length) this->length = length.length();
	cout << delim;
}
void Graf::FillManually() {
	cout << delim;
	cout << "Enter the amount of vertexes you want: ";
	int size = 0, temp = 0;
	cin >> size;
	cout << endl;
	this->size = size;
	string length;
	vector<vector<int>> Matrix(size, vector<int>(size, I));
	for (int i = 0; i < this->size; i++) {
		cout << "Enter the " << i << " line of adjacency Matrix:" << endl;
		for (int j = 0; j < this->size; j++) {
			cin >> temp;
			Matrix[i][j] = temp;
			if (temp == 0 && i != j) Matrix[i][j] = I;
		}
	}
	this->adjMatrix = Matrix;
	this->length = length.length();
	length = to_string(this->size);
	if (length.length() > this->length) this->length = length.length();
	cout << delim;
}
void Graf::FillVariant() {
	size = 17;
	length = 2;
	adjMatrix = {
		//	 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
			{0, 7, 3, 7, I, I, I, I, I, I, I, I, I, I, I, I, I},//0
			{7, 0, I, I, 5, I, I, I, I, I, I, I, I, I, I,11, I},//1
			{3, I, 0, I, 8, I, I, I, I, I, I, I, I, I, I, 7, I},//2
			{7, I, I, 0, 2, I, I, I, I, I, 5, I, I, I, I, I, I},//3
			{I, 5, 8, 2, 0, I,10, I, I, I, 9, I, I, I, I, 8, I},//4
			{I, I, I, I, I, 0, I, 7, 3, I, I, I, 3, 8, I, I, 7},//5
			{I, I, I, I,10, I, 0, I, 4, I, 1, I, I, I, I, I, I},//6
			{I, I, I, I, I, 7, I, 0, I, 2, I, 1, I, I, I, I, I},//7
			{I, I, I, I, I, 3, 4, I, 0, 9, I, I, 4, I, I, 5, I},//8
			{I, I, I, I, I, I, I, 2, 9, 0, I, I, 7, I, 2, I, I},//9
			{I, I, I, 5, 9, I, 1, I, I, I, 0, 4, I, I, I, I, I},//10
			{I, I, I, I, I, I, I, 1, I, I, 4, 0, I, I, I, I, I},//11
			{I, I, I, I, I, 3, I, I, 4, 7, I, I, 0, I, I, I, 9},//12
			{I, I, I, I, I, 8, I, I, I, I, I, I, I, 0, I,11, I},//13
			{I, I, I, I, I, I, I, I, I, 2, I, I, I, I, 0, I, 3},//14
			{I,11, 7, I, 8, I, I, I, 5, I, I, I, I,11, I, 0, I},//15
			{I, I, I, I, I, 7, I, I, I, I, I, I, 9, I, 3, I, 0},//16
	};
}
void Graf::Print() {
	cout << delim << "Matrix of adjacency:\n\n\n";
	int space = this->length;
	space++;
	cout << setw(space) << " " << setw(3) << " " << " ";
	for (rsize_t i = 0; i < this->size; i++) {
		cout << setw(space) << ("v" + to_string(i)) << " ";
	}
	cout << endl;
	cout << setfill('_');
	cout << setw(space) << "_" << setw(3) << "_";
	for (rsize_t i = 0; i < this->size; i++) {
		cout << setw(space) << "_" << "_";
	}
	cout << setfill(' ');
	cout << endl;
	for (rsize_t i = 0; i < this->size; i++) {
		cout << setw(space) << ("v" + to_string(i)) << setw(3) << "|" << " ";
		for (rsize_t j = 0; j < this->size; j++) {
			if (adjMatrix[i][j] != I) {
				cout << setw(space) << adjMatrix[i][j] << " ";
				continue;
			}
			cout << setw(space) << 0 << " ";
		}
		cout << endl;
	}
	cout << delim;
}
void Graf::BFS() {
	cout << delim;
	cout << "BFS is running...\n" << endl;
	cout << "Enter the node you'd like to begin with: ";
	int start = 0;
	cin >> start;
	cout << endl;
	queue<int> Queue;
	set<int> used;
	Queue.push(start);
	used.insert(start);
	do {
		int temp = Queue.front();
		if (temp != start) cout << " -> ";
		cout << "v" << temp;
		for (int i = 0; i < size; i++) {
			if (adjMatrix[temp][i] == 0 || adjMatrix[temp][i] == I) continue;
			if (used.count(i) != 0) continue;
			Queue.push(i);
			//cout << "(+ " << i << ")";
			used.insert(i);
		};
		Queue.pop();
	} while (!Queue.empty());
	cout << delim;
}
void Graf::DFSInitialization() {
	cout << delim;
	cout << "DFS is running...\n" << endl;
	cout << "Enter the node you'd like to begin with: ";
	int start = 0;
	cin >> start;
	cout << endl;
	set<int> used;
	int temp = 0;
	DFS(start, used, temp);
	cout << delim;
}
void Graf::DFS(int& start, set<int>& used, int& temp) {
	if (used.count(start) != 0) return;
	used.insert(start);
	temp++;
	cout << "v" << start;
	if (temp != size) cout << " -> ";
	for (int i = 0; i < size; i++) {
		if (adjMatrix[start][i] == 0) continue;
		if (used.count(i) != 0) continue;
		Graf::DFS(i, used, temp);
	};
	//cout << "\nback " << endl;
	return;
}
void Graf::Dijkstra(const int& start, const bool& check) {
	if (check == 1) {
		cout << delim;
		cout << "Dijkstra's algorithm is running for v" << start << " ...\n";
	}
	cout << endl;

	//the vector of marks
	vector<bool> used(this->size);

	//the vector of distances
	//dist[v] = min_distance(start, v)
	vector<int> dist(this->size, I);;

	//setting 0 for the starting vertex
	dist[start] = 0;

	while(1) {
		int v = -1;
		for (int nv = 0; nv < size; nv++) {//looping throuh the vertexes
			if (!used[nv] && dist[nv] < I && (v == -1 || dist[v] > dist[nv])) {//choosing the closest unmarked vertex
				v = nv;
			}
		}
		if (v == -1) break; {//closest vertex is not found
			used[v] = true; //marking
		}
		for (int nv = 0; nv < size; nv++) {
			if (!used[nv] && adjMatrix[v][nv] < I) {//for all unmarked closest vertexes
				dist[nv] = min(dist[nv], dist[v] + adjMatrix[v][nv]);//making the distance shorter(called relaxation)
			}
		}
	}
	
	for (rsize_t i = 0; i < dist.size(); i++) {
		cout << "v" << start << " -> v" << i << ": " << dist[i] << endl;
	}
	if(check == 1)	cout << delim;
}
void Graf::DijkstraForAll() {
	cout << delim;
	cout << "Dijkstra's algorithm is running for all vertexes...\n" << endl;
	for (int i = 0; i < size; i++) {
		Dijkstra(i, 0);
		cout << endl;
	}
	cout << delim;
}
void Graf::Floyd() {
	cout << delim;
	cout << "Floyd-Warshall's algorithm is running...\n" << endl;
	vector<vector<int>> matrix = adjMatrix;
	vector<vector<vector<int>>> matrixes;
	matrixes.push_back(matrix);
	for (int k = 0; k < size; k++) {
		matrix = adjMatrix;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = min(matrixes[matrixes.size() - 1][i][j], matrixes[matrixes.size() - 1][i][k] + matrixes[matrixes.size() - 1][k][j]);
		matrixes.push_back(matrix);
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << "v" << i << " -> v" << j << ": " << matrix[i][j] << endl;
		cout << endl;
	}
	cout << delim;
}

int main() {
	Graf graf;
	graf.FillVariant();
	graf.Print();
	graf.BFS();
}
