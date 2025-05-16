#include <iostream> 
#include <vector>    
#include <limits>    
#include <fstream>  

using namespace std;

#ifdef DISABLED
const long long INF = numeric_limits<long long>::max();  // Khai bao gia tri lon nhat cho long long, dung lam gia tri "vo cung" trong thuat toan.

struct Edge {  // Cau truc Edge dung de bieu dien mot canh trong do thi.
    int u, v, d;  // u: dinh dau, v: dinh cuoi, d: trong so cua canh.
};

void printPath(int start_node, int end_node, const vector<int>& predecessors, ofstream& outfile) {
    // Ham in duong di tu start_node den end_node theo day predecessors.
    if (predecessors[end_node] == -1 && end_node != start_node) {  // Neu khong co duong di tu start_node den end_node.
        return;
    }

    vector<int> path;  // Khai bao vector de luu duong di.
    int current = end_node;  // Bat dau tu dinh cuoi.
    while (current != -1) {  // Lap cho den khi tim duoc dinh khoi dau.
        path.push_back(current);  // Them dinh vao duong di.
        if (current == start_node) break;  // Neu da den dinh bat dau, dung lai.
        current = predecessors[current];  // Di chuyen ve dinh tien nhiem.
    }

    // In ra duong di theo thu tu tu start_node den end_node.
    for (size_t i = path.size(); i > 0; --i) {
        outfile << path[i - 1] << (i == 1 ? "" : " ");  // In dinh, them khoang trang giua cac dinh.
    }
    outfile << endl;  // Xuat dong moi.
}

int main() {
    ifstream infile("dirty.txt");  // Mo file dau vao.
    ofstream outfile("dirty.out");  // Mo file dau ra.

    if (!infile.is_open()) {  // Neu khong mo duoc file dau vao.
        cerr << "Could not open dirty.txt" << endl;
        return 1;
    }
    if (!outfile.is_open()) {  // Neu khong mo duoc file dau ra.
        cerr << "Could not open dirty.out" << endl;
        return 1;
    }

    int n, m, s_bellman, e_bellman;
    infile >> n >> m >> s_bellman >> e_bellman;  // Doc so dinh, so canh, va hai dinh start va end.

    s_bellman--;  // Chuyen tu chi so 1 sang chi so 0.
    e_bellman--;  // Chuyen tu chi so 1 sang chi so 0.

    vector<Edge> edges(m);  // Khai bao vector luu danh sach cac canh.
    for (int i = 0; i < m; ++i) {  // Doc thong tin cac canh.
        infile >> edges[i].u >> edges[i].v >> edges[i].d;
        edges[i].u--;  // Chuyen chi so dinh u sang chi so 0.
        edges[i].v--;  // Chuyen chi so dinh v sang chi so 0.
    }

    infile.close();  // Dong file dau vao.

    vector<long long> dist(n, INF);  // Khai bao vector luu khoang cach tu start_node den cac dinh.
    vector<int> predecessors(n, -1);  // Khai bao vector luu dinh tien nhiem cua moi dinh.
    dist[s_bellman] = 0;  // Khoang cach tu start_node den chinh no la 0.

    // Thuat toan Bellman-Ford lap n-1 lan.
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].d < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].d;  // Cap nhat khoang cach moi.
                predecessors[edges[j].v] = edges[j].u;  // Cap nhat dinh tien nhiem cua v.
            }
        }
    }

    // Kiem tra co chu trinh am khong.
    bool has_negative_cycle = false;
    for (int j = 0; j < m; ++j) {
        if (dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].d < dist[edges[j].v]) {
            has_negative_cycle = true;  // Neu co chu trinh am, dat co flag has_negative_cycle = true.
            break;
        }
    }

    if (dist[e_bellman] == INF) {  // Neu khong the den duoc dinh end_node.
        outfile << "INF" << endl;  // In ra "INF" duong di khong ton tai.
        outfile << "No path" << endl;  // In ra "No path".
    }
    else {  // Neu co duong di den end_node.
        outfile << dist[e_bellman] << endl;  // In ra khoang cach ngan nhat.
        printPath(s_bellman, e_bellman, predecessors, outfile);  // In ra duong di ngan nhat.
    }

    // Thuat toan Floyd-Warshall cho All-Pairs Shortest Paths
    vector<vector<long long>> adj_matrix(n, vector<long long>(n, INF));  // Khoi tao ma tran ke.

    for (int i = 0; i < n; ++i) {
        adj_matrix[i][i] = 0;  // Khoang cach tu mot dinh den chinh no la 0.
    }

    for (int k = 0; k < m; ++k) {  // Cap nhat ma tran ke tu cac canh.
        // Thay the `std::min` de tranh su dung <algorithm>
        if (adj_matrix[edges[k].u][edges[k].v] > edges[k].d) {
            adj_matrix[edges[k].u][edges[k].v] = edges[k].d;  // Cap nhat ma tran khoang cach.
        }
    }

    // Thuat toan Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adj_matrix[i][k] != INF && adj_matrix[k][j] != INF) {
                    if (adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j]) {
                        adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];  // Cap nhat khoang cach ngan nhat.
                    }
                }
            }
        }
    }

    // In ma tran khoang cach giua cac dinh (All-Pairs Shortest Paths)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj_matrix[i][j] == INF) {
                outfile << "INF" << (j == n - 1 ? "" : " ");  // In "INF" neu khong co duong di.
            }
            else {
                outfile << adj_matrix[i][j] << (j == n - 1 ? "" : " ");  // In khoang cach ngan nhat.
            }
        }
        outfile << endl;  // Xuat dong moi.
    }

    outfile.close();  // Dong file dau ra.

    return 0;  // Ket thuc chuong trinh.
}
#endif