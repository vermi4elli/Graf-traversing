#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string delim = "\n\n=============================================================\n\n\n";

struct node {
	int vertex;
	int weight;
	int last;
	node(const int& vertex) {
		this->vertex = vertex;
		this->weight = 0;
		this->last = vertex;
	}
	node(const int& vertex, const int& weight, const int& last) {
		this->vertex = vertex;
		this->weight = weight;
		this->last = last;
	}
};

bool operator<(const node& left, const node& right) {
	if (left.weight < right.weight) {
		return true;
	}
	return false;
}

bool operator==(const node& left, const node& right) {
	if (left.vertex == right.vertex) {
		return true;
	}
	return false;
}

class Graf {
private:
	int length;
	int size;
	int** adjMatrix;
public:

	Graf() {
		this->length = 0;
		this->size = 0;
		this->adjMatrix = 0;
	}
	Graf(const int& size) {
		this->length = 0;
		this->size = size;
		this->adjMatrix = new int* [size];
		for (int j = 0; j < size; j++) {
			this->adjMatrix[j] = new int[size];
			for (int i = 0; i < size; i++) {
				this->adjMatrix[j][i] = 0;
			}
		}
	}
	void Fill() {
		string length;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if (i == j) continue;
				if (adjMatrix[i][j] != 0) continue;
				int temp = rand() % 20;
				this->adjMatrix[i][j] = temp;
				this->adjMatrix[j][i] = temp;
				length = to_string(temp);
			}
		}
		this->length = length.length();
		length = to_string(this->size);
		if (length.length() > this->length) this->length = length.length();
	}
	void FillManually() {
		for (int i = 0; i < size; i++) {
			cout << "Enter the " << i+1 << " line of the matrix:" << endl;
			for (int j = 0; j < size; j++) {
				cin >> adjMatrix[i][j];
			}
			cout << endl;
		}
	}
	void Variant() {
		this->size = 17;
		this->length = 2;
		int Matrix[17][17] = {
			//	 0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
				{0, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//0
				{4, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//1
				{7, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},//2
				{3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0},//3
				{0, 2, 2, 0, 0, 0, 4, 0, 0, 0, 7, 0, 0, 8, 0, 8, 0},//4
				{0, 0, 0, 0, 0, 0, 0, 7, 3, 0, 0, 0, 1, 9,11, 0, 0},//5
				{0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 6, 0, 0, 0, 0, 0, 0},//6
				{0, 0, 0, 0, 0, 7, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0},//7
				{0, 0, 0, 0, 0, 3, 4, 0, 0, 3, 0, 0, 9, 0, 0,15, 0},//8
				{0, 0, 0, 0, 0, 0, 0, 5, 3, 0, 0, 0, 2, 0, 3, 0,12},//9
				{0, 0, 2, 7, 7, 0, 6, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},//10
				{0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 0, 0, 0},//11
				{0, 0, 0, 0, 0, 1, 0, 0, 9, 2, 0, 0, 0, 0, 0, 0,11},//12
				{0, 0, 0, 0, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},//13
				{0, 0, 0, 0, 0,11, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 8},//14
				{0, 0, 0, 0, 8, 0, 0, 0,15, 0, 0, 0, 0, 1, 0, 0, 0},//15
				{0, 0, 0, 0, 0, 0, 0, 0, 0,12, 0, 0,11, 0, 8, 0, 0},//16
		};
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				adjMatrix[i][j] = Matrix[i][j];
			}
		}
	}
	void Print() {
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
				cout << setw(space) << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << delim;
	}
	void BFS() {
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
				if (adjMatrix[temp][i] == 0) continue;
				if (used.count(i) != 0) continue;
				Queue.push(i);
				//cout << "(+ " << i << ")";
				used.insert(i);
			};
			Queue.pop();
		} while (!Queue.empty());
		cout << delim;
	}
	void DFS(int& start, set<int>& used, int& temp) {
		if (used.count(start) != 0) return;
		used.insert(start);
		temp++;
		cout << "v" << start;
		if (temp != size) cout << " -> ";
		for (int i = 0; i < size; i++) {
			if (adjMatrix[start][i] == 0) continue;
			if (used.count(i) != 0) continue;
			DFS(i, used, temp);
		};
		//cout << "\nback " << endl;
		return;
	}
	void Dijkstra(int& start) {		
		cout << "Dijkstra's algorithm is running...\n" << endl;

		//vectors for "not visited" and "visited" vertexes 
		vector<node> curr;
		vector<node> used;
		curr.push_back(start);
		
		//visiting every vertex of the graf
		while (!curr.empty()) {
			for (int i = 0; i < size; i++) {
				//check if route exists
				if (adjMatrix[curr[0].vertex][i] == 0) continue;
				
				if (i == 5) {
					int a = 0;
				}
				//check if this node is visited
				if (find(used.begin(), used.end(), (i)) != used.end()) continue;

				//check if the weight to the node is already written
				//if yes, check if it's bigger than the new one and overright, if yes
				vector<node>::iterator it;
				if ((it = find(curr.begin(), curr.end(), (i) )) != curr.end()) {
					if (curr[distance(curr.begin(), it)].weight > curr[0].weight + adjMatrix[curr[0].vertex][i]) {
						if (curr[distance(curr.begin(), it)].vertex == i) continue;
						curr[distance(curr.begin(), it)].weight = curr[0].weight + adjMatrix[curr[0].vertex][i];
						curr[distance(curr.begin(), it)].last = i;
					}
					continue;
				}
				//push the new element to the curr-vector
				node temp(i, (curr[0].weight + adjMatrix[curr[0].vertex][i]), curr[0].vertex);
				curr.push_back(temp);
			}
			used.push_back(curr[0]);
			curr.erase(curr.begin());
			sort(curr.begin(), curr.end());
		}
		sort(used.begin(), used.end(), [](const node & left, const node & right) {
			if (left.vertex < right.vertex) return true;
			return false;
			});
		for (const auto& x : used) {
			cout << "v" << x.vertex << " = " << x.weight << ", with path: " << x.vertex;
			int temp_i = x.last;
			while (temp_i != start) {
				cout << " -> " << temp_i;
				temp_i = used[temp_i].last;
			}
			cout << " -> " << temp_i;
			cout << endl;
		}
	}
	void Floyd_Warshall() {
		cout << delim;
		cout << "Floyd-Warshall's algorithm is running...\n" << endl;
		int** matrix = adjMatrix;
		for (int k = 0; k < size; k++)
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
					if (matrix[i][k] && matrix[k][j] && i != j)
						if (matrix[i][k] + matrix[k][j] < matrix[i][j] || matrix[i][j] == 0)
							matrix[i][j] = matrix[i][k] + matrix[k][j];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cout << i + 1 << " -> " << j + 1 << " = " << matrix[i][j] << endl;
		cout << delim;
	}
	/*void ford()
	{
		int v[10000];
		int u[10000];
		int w[10000];
		int e = 0;
		int start;
		for (int q = 0; q < size; q++)
		{
			start = q;
			for (int i = 0; i < size; i++)
				for (int j = 0; j < size; j++)
				{
					if (adjMatrix[i][j] != 0)
					{
						v[e] = i;
						u[e] = j;
						w[e] = adjMatrix[i][j];

						e++;
					}

				}
			int d[1000];
			for (int i = 0; i < size; i++) d[i] = 1000;
			d[start] = 0;
			for (int i = 0; i < size - 1; i++)
				for (int j = 0; j < e; j++)
					if (d[v[j]] + w[j] < d[u[j]])
						d[u[j]] = d[v[j]] + w[j];
			for (int i = 0; i < size; i++)
				cout << start + 1 << " -> " << i + 1 << " = " << d[i] << endl;

		}
	}*/
};

Graf CreateGraf() {
	Graf result;
	cout << "Enter, what you'd like to do:" << endl;
	cout << "1. Print a task-given graf" << endl;
	cout << "2. Create a random graf and print it" << endl;
	cout << "3. Fill manually" << endl;
	cout << "Your answer: ";
	int variant = 0;
	cin >> variant;
	if (variant == 2) {
		cout << "Enter the amount of nodes: ";
		int amount = 0;
		cin >> amount;
		Graf graf(amount);
		graf.Fill();
		graf.Print();
		result = graf;
	}
	else if(variant == 1){
		Graf graf(17);
		graf.Variant();
		graf.Print();
		result = graf;
	}
	else {
		cout << "Enter the amount of nodes: ";
		int amount = 0;
		cin >> amount;
		Graf graf(amount);
		graf.FillManually();
		graf.Print();
		result = graf;
	}
	return result;
}

int main() {
	srand(time(0));
	Graf graf = CreateGraf();
	
	cout << "Enter what you'd like to do:" << endl;
	cout << "1. BFS" << endl;
	cout << "2. DFS" << endl;
	cout << "3. Dijkstra's algorithm" << endl;
	cout << "4. Floyd-Warshall algorithm" << endl;
	cout << "5. Bellman-Ford algorithm" << endl;
	cout << "Your answer: ";
	int variant = 0;
	cin >> variant;
	if (variant == 1) {
		graf.BFS();
	}
	else if (variant == 2) {
		cout << delim;
		cout << "DFS is running...\n" << endl;
		cout << "Enter the node you'd like to begin with: ";
		int start = 0;
		cin >> start;
		cout << endl;
		set<int> used;
		int temp = 0;
		graf.DFS(start, used, temp);
		cout << delim;
	}
	else if (variant == 3) {
		cout << delim;
		cout << "Enter the node you'd like to begin with: ";
		int start = 0;
		cin >> start;
		cout << endl;
		graf.Dijkstra(start);
		cout << delim;
	}
	else if (variant == 4) {
		graf.Floyd_Warshall();
	}
	/*else if (variant == 5) {
		graf.ford();
	}*/
	return 0;
}
