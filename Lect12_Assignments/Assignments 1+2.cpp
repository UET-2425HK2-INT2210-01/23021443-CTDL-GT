#include <iostream>
#include <vector>
#include <stack>
#include <fstream>



//bai1
#ifdef DISABLED 
using namespace std;

// Ham DFS de duyet do thi theo chieu sau
void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& topoStack) {
	visited[v] = true; // Danh dau dinh v da tham
	for (int v_next : adj[v]) { // Duyet cac dinh ke voi v
		if (!visited[v_next]) { // Neu chua tham
			dfs(v_next, adj, visited, topoStack); // Duyet tiep
		}
	}
	topoStack.push(v); // Sau khi duyet xong tat ca cac dinh ke, day v vao ngan xep
}

int main() {
	int n, m;
	cin >> n >> m; // Doc so dinh n va so canh m
	vector <vector<int>> adj(n + 1); // Tao danh sach ke co n+1 vi tri (vi dinh bat dau tu 1)
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; // Doc canh noi tu u den v
		adj[u].push_back(v); // Them v vao danh sach ke cua u
	}

	vector<bool> visited(n + 1, false); // Tao vector danh dau da tham hay chua
	stack<int> topoStack; // Tao ngan xep de luu thu tu topo
	vector<int> result; // Ket qua cuoi cung

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, adj, visited, topoStack); // Duyet tu cac dinh chua tham
		}
	}

	while (!topoStack.empty()) {
		result.push_back(topoStack.top()); // Lay dinh tu dinh ngan xep
		topoStack.pop(); // Bo dinh vua lay
	}

	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << (i == result.size() - 1 ? "" : " "); // In ket qua ra
	}
}

#endif



//bai 2
#ifdef DISABLED 

std::vector<int> parent; // Luu cha cua moi nut
std::vector<int> ranks; // Luu do cao cua cay (rank)

// Khoi tao cac tap hop rieng biet
void make_sets(int n) {
	parent.resize(n + 1);
	for (int i = 0; i <= n; ++i) {
		parent[i] = i; // Moi dinh la cha cua no
	}
	ranks.assign(n + 1, 0); // Ban dau do cao la 0
}

// Tim tap hop chua dinh i (voi rut gon duong di)
int find_set(int i) {
	if (i == parent[i])
		return i; // Neu chinh no la goc
	return parent[i] = find_set(parent[i]); // Quy hoach duong di
}

// Gop hai tap hop
bool union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) { // Chi gop neu khac tap hop
		if (ranks[a] < ranks[b])
			std::swap(a, b); // Dam bao a co rank cao hon
		parent[b] = a; // Gop tap hop
		if (ranks[a] == ranks[b])
			ranks[a]++; // Tang rank neu bang nhau
		return true;
	}
	return false; // Da cung tap hop, khong gop
}

// Cau truc canh
struct Edge {
	int u, v, d; // u va v la hai dinh, d la trong so
};

// Sap xep canh theo trong so tang dan (bubble sort)
void bubbleSortEdges(std::vector<Edge>& edges) {
	int n = edges.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (edges[j].d > edges[j + 1].d) { // So sanh trong so
				Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
}

// Sap xep canh cua cay khung nho nhat truoc khi xuat
void bubbleSortMstEdgesForOutput(std::vector<Edge>& edges) {
	int n = edges.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			bool shouldSwap = false;
			if (edges[j].d > edges[j + 1].d) {
				shouldSwap = true;
			}
			else if (edges[j].d == edges[j + 1].d) { // Neu trong so bang nhau
				if (edges[j].u > edges[j + 1].u) {
					shouldSwap = true;
				}
				else if (edges[j].u == edges[j + 1].u) {
					if (edges[j].v > edges[j + 1].v) {
						shouldSwap = true;
					}
				}
			}
			if (shouldSwap) {
				Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
	}
}

int main() {
	std::ifstream cin_file("connection.txt"); // Mo file nhap
	if (!cin_file.is_open()) {
		std::cerr << "Error: Could not open connection.txt" << std::endl;
		return 1;
	}
	std::cin.rdbuf(cin_file.rdbuf()); // Gan dau vao tu file

	std::ofstream cout_file("connection.out"); // Mo file xuat
	if (!cout_file.is_open()) {
		std::cerr << "Error: Could not open connection.out" << std::endl;
		return 1;
	}
	std::cout.rdbuf(cout_file.rdbuf()); // Gan dau ra ra file

	int n, m;
	std::cin >> n >> m; // Doc so dinh va so canh

	std::vector<Edge> edges(m); // Luu danh sach canh
	for (int i = 0; i < m; ++i) {
		std::cin >> edges[i].u >> edges[i].v >> edges[i].d; // Doc tung canh
	}

	bubbleSortEdges(edges); // Sap xep cac canh theo trong so tang dan

	make_sets(n); // Khoi tao cac tap hop

	long long totalCost = 0; // Tong chi phi cua MST
	std::vector<Edge> mstEdges; // Luu cac canh cua cay khung nho nhat

	// Duyet cac canh da sap xep
	for (const auto& edge : edges) {
		if (union_sets(edge.u, edge.v)) { // Neu gop duoc tap hop
			totalCost += edge.d; // Cong them trong so
			mstEdges.push_back(edge); // Luu vao ket qua

			if (mstEdges.size() == n - 1) {
				break; // Du n-1 canh thi dung
			}
		}
	}

	std::cout << totalCost << std::endl; // In tong chi phi

	bubbleSortMstEdgesForOutput(mstEdges); // Sap xep cac canh MST de xuat

	for (const auto& edge : mstEdges) {
		std::cout << edge.u << " " << edge.v << " " << edge.d << std::endl; // In ra tung canh
	}

	return 0; 
}
#endif
