#include <iostream>
#include <vector>

using namespace std;


struct node {  //tao struct node
	int data; //bien data kieu int
	struct node* firstChild; // con tro firstChild
	struct node* nextSibling; // con tro nextSibling

	node(int val) { //ham khoi tao node
		data = val; //gan data = val de tranh bi dinh garbage
		nextSibling = firstChild = nullptr; //gan nextSibling va firstChild = nullptr de cho chung ban dau ko tro toi cai gi (tranh bi dinh garbage)
	}
};

class tree { //tao class tree

private:
	node* root; // con tro den root node
	node** nodes; // mang con tro den cac node
	bool* isChild; // mang bool kiem tra xem node co phai la child hay ko
	int numNodes; // so luong node
public:
	tree(int n) { // n la so luong node
		numNodes = n;
		nodes = new node * [numNodes + 1] {nullptr}; //khoi tao mang con tro nodes voi so luong numNode+1 va gan cac con tro thanh nullptr
		isChild = new bool[numNodes + 1] {false}; //khoi tao mang bool isChild voi so luong numNode+1 va gan cac gia tri thanh false

	}

	~tree() { // de tren tao ham cay thi day la ham huy de free bo nho
		for (int i = 0; i <= numNodes; i++) {
			if (nodes[i]) { // neu nodes[i] != nullptr thi xoa
				delete nodes[i];
			}
		}
		delete[] nodes; // xoa mang nodes
		delete[] isChild; // xoa mang isChild
	}

	void add(int parentData, int childData) { // ham them child cho parent
		if (!nodes[parentData]) { // neu parentData chua co node thi tao node moi
			nodes[parentData] = new node(parentData);
			if (!root) { //neu la node dau tien thi gan  no la root
				root = nodes[parentData];
			}
		}

		if (!nodes[childData]) { // neu chua co childData thi tao moi
			nodes[childData] = new node(childData);
		}

		isChild[childData] = true; // gan isChild[childData] = true de biet no la child

		node* parent = nodes[parentData];
		node* child = nodes[childData];

		if (!parent->firstChild) { // neu parent chua co child thi gan child la firstChild
			parent->firstChild = child;
		}
		else { // neu parent da co child thi tim den cuoi va gan child la nextSibling
			node* temp = parent->firstChild;
			while (temp->nextSibling) {
				temp = temp->nextSibling;
			}
			temp->nextSibling = child;
		}
	}

	int findRoot() { // ham tim root
		for (int i = 1; i <= numNodes; i++) {
			if (nodes[i] != nullptr && !isChild[i]) { // neu node dang xet khac nullptr va ko phai la child (ischild set la false) thi day la root
				return i;
			}
		}
		return -1;
	}


	void build(int edge, vector<pair<int, int>>& edges) { //ham dung cay init voi so canh , mang vecor voi pair de bieu dien parent-child
		for (int i = 1; i <= numNodes; i++) {
			nodes[i] = new node(i); // tao nodes
		}
		for (int i = 0; i < edge; i++) { // vong lap adds canh(edges) 
			int parent = edges[i].first;
			int child = edges[i].second;
			isChild[child] = true;// set ve true de biet no khong phai la root vi child da co parent

			if (nodes[parent]->firstChild == nullptr) { //check neu parent ko co child(NULL) thu gan firstchild
				nodes[parent]->firstChild = nodes[child];
			}
			else { // neu parent da co child thi kiem tra het cac siblings roi gan child o cuoi cung
				node* temp = nodes[parent]->firstChild;
				while (temp->nextSibling) {
					temp = temp->nextSibling;
				}
				temp->nextSibling = nodes[child];
			}
		}

		int rootValue = findRoot(); // chay ham findRoot xem co node nao chua duoc gan child 
		if (rootValue == -1) { // neu ko co root thi in loi
			cout << "Invalid tree structure" << endl;
			return;
		}
		root = nodes[rootValue];
	}

	void preorder() {
		prepPreorder(root); //chay ham chuan bi
		cout << endl;
	}

	void postorder() {
		prepPostorder(root); // chay ham chuan bi
		cout << endl;
	}

	void inorder() {
		if (isBinaryTree(root)) { //kiem tra neu co phai la cay binary ko neu co thi chay ham kiem tra con khong bi bao loi
			prepInorder(root);
			cout << endl;
		}
		else {
			cout << "NOT BINARY TREE" << endl;
		}
	}

	int getHeight() { // chay ham getHigh de tra ve chieu cao
		return getHigh(root);
	}
private:

	void prepPreorder(node* current) {
		if (!current) return; // kiem neu node hien tai dang xem la nullptr thi return
		cout << current->data << " "; // in data
		prepPreorder(current->firstChild); // call lai prep de check toan bo subtree root o firstchild
		prepPreorder(current->nextSibling); // call tuong tu nh tren nhung ma cua nextSibling
	}

	void prepPostorder(node* current) { // kiem tra dieu kien tuong tu nhu o tren
		if (!current) return;


		prepPostorder(current->firstChild); // call lai prep cho firsthild 

		node* temp = current->firstChild; // su dung temp chay qua tu firstChild den het siblings 
		while (temp) {
			prepPostorder(temp->nextSibling); // cu den moi sibling call lai prep
			temp = temp->nextSibling;
		}


		cout << current->data << " "; // in data
	}

	void prepInorder(node* current) {
		if (!current) return;// kiem tra dieu kien tuong tu nhu tren


		node* child = current->firstChild;


		if (child) { // xet ben trai neu node co child thi call prep cho child(firstchild)
			prepInorder(child);
		}


		cout << current->data << " "; //in data	

		if (child) {// xet ben phai neu co firstchild  thi chay lap tat ca cac sibling roi call prep
			node* sibling = child->nextSibling;
			while (sibling) {
				prepInorder(sibling);
				sibling = sibling->nextSibling;
			}
		}
	}



	int getHigh(node* current) {// ham lay chieu cao 
		if (!current) {//kiem tra dieu kien nhu tren
			return -1;
		}
		int max1 = -1;
		node* temp = current->firstChild;
		while (temp) {//chay lap cho firstchild va siblings cua no  moi child call gethigh check chieu cao cua child dong thoi dung max de tim so lon nhat giua cac child
			int childHeight = getHigh(temp);
			if (childHeight > max1) {
				max1 = childHeight;
			}
			temp = temp->nextSibling;
		}
		return max1 + 1;
	}

	bool isBinaryTree(node* current) {
		if (!current) { // kiem tra dieu kien nhu tren
			return true;
		}
		int count = 0;
		node* temp = current->firstChild;
		while (temp) { //chay lap cu den mot child bien count tang 1 neu vuot qua 2 thi tuc la co nhieu hon2 child thi return false (tuc la ko phai cay binary)
			count++;
			if (count > 2) {
				return false;
			}
			temp = temp->nextSibling;
		}
		return isBinaryTree(current->firstChild) && isBinaryTree(current->nextSibling);  // sau khi check xong mot node call lai func check nextsiblings va retrun true neu thoa man ca hai
	}
};

int main() {
	int numNodes, numEdges; //khoi tao so node va so canh
	cin >> numNodes >> numEdges; //input
	vector<pair<int, int>> edges(numEdges); // tao mang chua
	for (int i = 0; i < numEdges; i++) { // vong lap add 
		int parent, child;
		cin >> parent >> child;
		edges[i] = { parent, child };
	}
	tree myTree(numNodes); //  call tree
	myTree.build(numEdges, edges); // build func

	cout << myTree.getHeight() << endl; // output chieu cao
	myTree.preorder(); // preoder func
	myTree.postorder();// postorder func
	myTree.inorder(); // inorder func
	return 0;
}