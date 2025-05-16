#include <iostream>  
#include <vector>    
#include <queue>     


using namespace std;


//bai 1
#ifdef DISABLED
void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
	// Ham dfs (Depth-First Search) duyet theo chieu sau, tim tat ca cac dinh lien thong voi v.
	visited[v] = true;  // Danh dau dinh v la da duyet.

	for (int v_next : adj[v]) {  // Duyet qua cac dinh ke cua dinh v.
		if (!visited[v_next]) {  // Neu dinh v_next chua duoc duyet.
			dfs(v_next, adj, visited);  // Goi de quy dfs de duyet dinh v_next.
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;  // Doc so dinh n va so canh m.

	vector<vector<int>> adj(n + 1);  // Khai bao ma tran ke adj, voi chi so bat dau tu 1 (1-based index).

	for (int i = 0; i < m; i++) {  // Doc danh sach canh.
		int x, y;
		cin >> x >> y;  // Doc 2 dinh x, y cua canh.
		adj[x].push_back(y);  // Them dinh y vao danh sach ke cua dinh x.
		adj[y].push_back(x);  // Them dinh x vao danh sach ke cua dinh y.
	}

	vector<bool> visited(n + 1, false);  // Khai bao vector visited de danh dau cac dinh da duyet.
	int connected_components = 0;  // Bien dem so lien thong.

	for (int i = 1; i <= n; i++) {  // Duyet qua tat ca cac dinh.
		if (!visited[i]) {  // Neu dinh i chua duoc duyet (chua thuoc lien thong).
			dfs(i, adj, visited);  // Goi ham dfs de duyet toa do cac dinh lien thong tu dinh i.
			connected_components++;  // Tang bien so lien thong.
		}
	}

	cout << connected_components;  // In ra so lien thong trong do thi.
	return 0;  // Ket thuc chuong trinh.
}
#endif

//bai2
#ifdef DISBLED

int bfs(int v, int target, const vector<vector<int>>& adj) {
	// Ham bfs (Breadth-First Search) tim duong di ngan nhat tu dinh v den target trong do thi adj.
	queue<int> q;  // Khai bao hang doi de luu cac dinh can duyet.
	q.push(v);  // Bat dau duyet tu dinh v.
	vector<bool> visited(adj.size(), false);  // Khai bao vector visited de danh dau dinh da duyet hay chua.
	vector<int> distance(adj.size(), -1);  // Khai bao vector distance de luu khoang cach tu v den moi dinh, khoang cach khoi tao la -1.
	distance[v] = 0;  // Khoang cach tu v den chinh no la 0.

	while (!q.empty()) {  // Lap cho den khi hang doi rong.
		int current = q.front();  // Lay dinh dau hang doi.
		q.pop();  // Xoa dinh dau hang doi.

		for (int v_next : adj[current]) {  // Duyet qua cac dinh ke cua dinh current.
			if (!visited[v_next]) {  // Neu dinh v_next chua duoc duyet.
				visited[v_next] = true;  // Danh dau dinh v_next da duyet.
				distance[v_next] = distance[current] + 1;  // Cap nhat khoang cach den dinh v_next.
				q.push(v_next);  // Them dinh v_next vao hang doi.

				if (v_next == target) {  // Neu dinh v_next la dinh target, return khoang cach.
					return distance[v_next];
				}
			}
		}
	}
	return -1;  // Neu khong tim thay duong di den target, tra ve -1.
}

int main() {
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;  // Doc so dinh n, so canh m, va hai dinh X, Y.

	vector<vector<int>> adj(n + 1);  // Khai bao vector adj de luu ma tran ke, voi 1 chi so bo sung cho dinh 1-based index.

	for (int i = 0; i < m; i++) {  // Doc danh sach canh.
		int x, y;
		cin >> x >> y;  // Doc 2 dinh x, y cua canh.
		adj[x].push_back(y);  // Them dinh y vao danh sach ke cua dinh x.
		adj[y].push_back(x);  // Them dinh x vao danh sach ke cua dinh y.
	}

	vector<bool> visited(n + 1, false);  // Khai bao vector visited danh dau cac dinh da duyet.
	int shortest_path = bfs(X, Y, adj);  // Goi ham bfs de tim duong di ngan nhat tu X den Y.

	if (shortest_path == -1) {  // Neu khong tim thay duong di.
		cout << "No path exists" << endl;  // In ra thong bao khong co duong di.
	}
	else {  // Neu tim thay duong di.
		cout << shortest_path << endl;  // In ra khoang cach ngan nhat.
	}
	return 0;  // Ket thuc chuong trinh.
}

#endif