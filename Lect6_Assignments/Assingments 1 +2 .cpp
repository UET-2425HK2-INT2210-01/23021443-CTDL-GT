#include <iostream>

using namespace std;

///bai1

#ifdef DISABLED
struct node { //tao struct node gom data , con tro left va right
	int data;
	node* left;
	node* right;
	node(int val) { // khi tao node thi gan gia tri node data la val , left va right la nullp[tr
		data = val;
		left = right = nullptr;
	}
};

class binaryTree {
private:
	node* root; // con tro root

	node* insertPrep(node* root, int data) {
		if (!root) return new node(data); // neu root = nullptr tuc la da co cho insert dung nen tao node moi

		if (data < root->data) { // neu data nho hon root thi insert vao left
			root->left = insertPrep(root->left, data);
		}
		else if (data > root->data) { // neu data lon hon root thi insert vao right
			root->right = insertPrep(root->right, data);
		}
		return root;

	}

	node* findMin(node* root) {
		while (root->left) { // trong bst node nho hon o ben trai nen soat het o ben trai
			root = root->left;
		}
		return root;
	}

	node* deletePrep(node* root, int data) {
		if (!root) return nullptr; // neu root = nullptr thi return nullptr

		if (data < root->data) { // neu data nho hon root thi delete o trai
			root->left = deletePrep(root->left, data);
		}
		else if (data > root->data) { // neu data lon hon root thi delete o phai
			root->right = deletePrep(root->right, data);
		}
		else {  // truong hop node dang xet co data can xoa
			if (!root->left && !root->right) { // neu no ko co con thi xoa tra ve nullptr cho parent
				delete root;
				return nullptr;
			}
			else if (!root->left) { // neu no co con phai thi store tam con phai roi xoa node sau do tra ve con phai no voi parent
				node* temp = root->right;
				delete root;
				return temp;
			}
			else if (!root->right) { // tuong tu nhu tren nhung doi voi con trai
				node* temp = root->left;
				delete root;
				return temp;
			}
			node* temp = findMin(root->right); // truong hop node co 2 con thi di tim min ben phai 
			root->data = temp->data;
			root->right = deletePrep(root->right, temp->data); // sau do xoa node min ben phai
		}
		return root; // update root
	}


	void inorderPrep(node* root) { // ham chuan bi inorder
		if (!root) return;
		inorderPrep(root->left);
		cout << root->data << " ";
		inorderPrep(root->right);
	}

public:
	binaryTree() { // init cay voi root = nullptr
		root = nullptr;
	}

	void insert(int data) { // ham insert
		root = insertPrep(root, data);
	}

	void inorder() { // ham inorder
		inorderPrep(root);
		cout << endl;
	}
	~binaryTree() { // ham huy de free bo nho
		destroyTree(root);
	}

	void deleteNode(int data) { // ham delete node
		root = deletePrep(root, data);
	}
	void destroyTree(node* root) { // chay de quy post order de xoa het con truoc 
		if (!root) return;
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}


};

int main() {
	binaryTree bst;
	bst.insert(2);
	bst.insert(1);
	bst.insert(10);
	bst.insert(6);
	bst.insert(3);
	bst.insert(8);
	bst.insert(7);
	bst.insert(13);
	bst.insert(20);
	bst.insert(14);
	bst.insert(0);
	bst.insert(35);
	bst.deleteNode(6);
	bst.deleteNode(13);
	bst.deleteNode(35);
	bst.inorder();

	return 0;
}

///Psuedo code 
#ifdef PSUEDO
STRUCT Node :
data
left
right
CONSTRUCTOR(val) :
	data = val
	left = NULL
	right = NULL

	CLASS BinaryTree :
PRIVATE:
root

FUNCTION insertPrep(currentNode, data) :
	IF currentNode IS NULL THEN
	RETURN new Node(data)
	ENDIF

	IF data < currentNode.data THEN
	currentNode.left = insertPrep(currentNode.left, data)
	ELSE IF data > currentNode.data THEN
	currentNode.right = insertPrep(currentNode.right, data)
	ENDIF

	RETURN currentNode
	END FUNCTION

	FUNCTION findMin(currentNode) :
	WHILE currentNode.left IS NOT NULL DO
	currentNode = currentNode.left
	ENDWHILE
	RETURN currentNode
	END FUNCTION

	FUNCTION deletePrep(currentNode, data) :
	IF currentNode IS NULL THEN
	RETURN NULL
	ENDIF

	IF data < currentNode.data THEN
	currentNode.left = deletePrep(currentNode.left, data)
	ELSE IF data > currentNode.data THEN
	currentNode.right = deletePrep(currentNode.right, data)
	ELSE:

IF currentNode.left IS NULL AND currentNode.right IS NULL THEN
DELETE currentNode
RETURN NULL
ELSE IF currentNode.left IS NULL THEN
temp = currentNode.right
DELETE currentNode
RETURN temp
ELSE IF currentNode.right IS NULL THEN
temp = currentNode.left
DELETE currentNode
RETURN temp
ELSE :

temp = findMin(currentNode.right)
currentNode.data = temp.data
currentNode.right = deletePrep(currentNode.right, temp.data)
ENDIF
ENDIF

RETURN currentNode
END FUNCTION

FUNCTION inorderPrep(currentNode) :
	IF currentNode IS NULL THEN
	RETURN
	ENDIF
	inorderPrep(currentNode.left)
	PRINT currentNode.data
	inorderPrep(currentNode.right)
	END FUNCTION

	FUNCTION destroyTree(currentNode) :
	IF currentNode IS NULL THEN
	RETURN
	ENDIF
	destroyTree(currentNode.left)
	destroyTree(currentNode.right)
	DELETE currentNode
	END FUNCTION

	PUBLIC :
CONSTRUCTOR:
root = NULL
END CONSTRUCTOR

FUNCTION insert(data) :
	root = insertPrep(root, data)
	END FUNCTION

	FUNCTION deleteNode(data) :
	root = deletePrep(root, data)
	END FUNCTION

	FUNCTION inorder() :
	inorderPrep(root)
	PRINT newline
	END FUNCTION

	DESTRUCTOR :
destroyTree(root)
END DESTRUCTOR
END CLASS


BEGIN MAIN :
CREATE new BinaryTree bst


bst.insert(2)
bst.insert(1)
bst.insert(10)
bst.insert(6)
bst.insert(3)
bst.insert(8)
bst.insert(7)
bst.insert(13)
bst.insert(20)
bst.insert(14)
bst.insert(0)
bst.insert(35)

bst.deleteNode(6)
bst.deleteNode(13)
bst.deleteNode(35)

bst.inorder()
END MAIN
#endif

#endif

///bai2

	
#ifdef DISABLED
struct Node { // khoi tao struct node gom data , con tro left, right va parent
	int data;
	Node* left;
	Node* right;
	Node* parent;

	Node(int val) { // khi tao node thi gan gia tri node data la val , left,right va parent  la nullp[tr
		data = val;
		left = right = parent = nullptr;
	}
};

void swap(int& a, int& b) { // ham swap de hoan doi 2 gia tri
	int temp = a;
	a = b;
	b = temp;
}

class MinHeap {
private:
	Node* root; // con tro den root
	int nodeCount; // dung nodeCount de xac dinh cho insert


	int getHighestBit(int x) { // tinh ham 2 mu cao nhat ma be hon hoac bang x
		int bit = 1; // tuc 2 mu 0
		while (bit <= x) {  // loop di bit den khi no lon hon x 
			bit <<= 1;
		}
		return bit >> 1; // tra ve bit bang viec di ve de no be hon hoac bang x
	}

	Node* getLastNode() {
		if (!root) return nullptr; // neu heap chua co	gi thi return nullptr

		int path = nodeCount;// dung path de xac dinh node vua duoc insert  nhu la bitmask  
		Node* temp = root;
		int bit = getHighestBit(nodeCount) >> 1; // di bit sang phai phai de bo qua bit lon nhat tuc la root

		while (bit > 0) { // loop di tu root den node moi duoc insert
			temp = (path & bit) ? temp->right : temp->left; // dung bitmask tim huong  neu bit co trong path thi sang phai , neu khong thi sang trai
			bit >>= 1; // di dang phai de xet tiep bit tiep theo
		}
		return temp; //tra ve node cuoi cung
	}

	void heapifyUp(Node* node) {
		while (node->parent && node->data < node->parent->data) { // loop voi dieu kien node co parent va data cua no nho hon parent 
			swap(node->data, node->parent->data); // swap data giua node va parent 
			node = node->parent; // tiep tuc di len cay
		}
	}

	void heapifyDown(Node* node) {
		while (node) {
			Node* smallest = node; // gan smallest = node de xet node hien tai bang viec coi nhu no la nho nhat 
			if (node->left && node->left->data < smallest->data)  // check neu co ton tai left va data cua no nho hon notde dang xet neu co thi update smallest 
				smallest = node->left;
			if (node->right && node->right->data < smallest->data) // check neu co ton tai right va data cua no nho hon notde dang xet neu co thi update smallest
				smallest = node->right;

			if (smallest != node) { // neu smallest khong bang node thi tuc la node hien tai khong phai la nho nhat thi thuc hien sawp data 
				swap(node->data, smallest->data);
				node = smallest; // di xuong node nho nhat de tiep tuc kiem tra
			}
			else break; // neu smallest bang node thi tuc la no da o vi tri dung roi thi break
		}
	}



	Node* findNode(Node* root, int val) {
		if (!root) return nullptr; // neu root = nullptr thi return nullptr
		if (root->data == val) return root; // neu root->data bang val thi return root

		Node* found = findNode(root->left, val); // tim node ben trai
		if (found) return found; // neu tim thay thi return
		return findNode(root->right, val); // neu khong tim thay ben trai thi tim ben phai
	}

	void inorderPrep(Node* node) {  // ham chuan bi inorder
		if (!node) return;
		inorderPrep(node->left);
		cout << node->data << " ";
		inorderPrep(node->right);
	}

public:
	MinHeap() { // init heap voi root = nullptr va nodeCount = 0
		root = nullptr;
		nodeCount = 0;
	}

	void insert(int val) { // ham insert de them node moi
		Node* newNode = new Node(val); // tao node moi voi data la val
		nodeCount++; // trang nodeCount them 1 cho node moi 

		if (!root) { // neu chua co root thi gan root = newNode
			root = newNode;
			return;
		}

		int path = nodeCount; // dung path de xac dinh node moi se duoc insert o vi tri nao
		Node* temp = root;
		int bit = getHighestBit(nodeCount) >> 1; // skip bit root

		while (bit > 1) { // tuong tu loop xac dinh huong 
			temp = (path & bit) ? temp->right : temp->left;  // bit co trong path thi sang phai khong co thi sang trai 
			bit >>= 1; // di sang bit tiep theo
		}

		newNode->parent = temp; // gan parent cho node moi
		if (path & 1) temp->right = newNode; // phu thuoc vao bit trong path gan node moi nhu la con phai hoac trai
		else temp->left = newNode;

		heapifyUp(newNode); // call de quy de chinh lai heap sau khi insert
	}
	void deleteNode(int val) {
		if (!root) return; // ko co node tuc la ko co gi de delete nen return

		Node* target = findNode(root, val); // tim node can xoa
		if (!target) { // neu khong tim thay node can xoa thi return tuc la node de khong ton tai trong cay
			cout << "Value " << val << " not found.\n";
			return;
		}

		Node* last = getLastNode(); // tim node cuoi cung trong heap
		if (target == last) { // neu node can xoa la node cuoi cung thi xoa no va return
			if (last->parent) { // neu node cuoi cung co parent thi chinh  con tro parent tro toi thanh null roi xoa 
				if (last->parent->left == last)
					last->parent->left = nullptr;
				else
					last->parent->right = nullptr;
			}
			else {
				root = nullptr;
			}
			delete last;
			nodeCount--; // xoa nodeCount di 1
			return;
		}


		target->data = last->data; //neu target khong phai la node cuoi cung thi thay data cua no voi last 
		if (last->parent) { // lam tuong tu nhu tren 
			if (last->parent->left == last)
				last->parent->left = nullptr;
			else
				last->parent->right = nullptr;
		}
		delete last;
		nodeCount--; // xoa nodeCount di 1

		if (target->parent && target->data < target->parent->data) // neu target co parent va data cua no nho hon parent thi call heapifyUp
			heapifyUp(target);
		else // neu khong thi call heapifyDown de chinh lai heap
			heapifyDown(target);
	}

	void inorder() { // ham inorder de in ra cac node trong heap
		inorderPrep(root);
		cout << endl;
	}

	~MinHeap() { // ham huy de free bo nho
		clearTree(root);
	}

	void clearTree(Node* node) { // ham de xoa cac node trong heap
		if (!node) return;
		clearTree(node->left);
		clearTree(node->right);
		delete node;
	}
};

int main() {
	MinHeap heap;

	heap.insert(2);
	heap.insert(1);
	heap.insert(10);
	heap.insert(6);
	heap.insert(3);
	heap.insert(8);
	heap.insert(7);
	heap.insert(13);
	heap.insert(20);
	heap.inorder();
	heap.insert(14);
	heap.inorder();
	heap.insert(0);
	heap.inorder();
	heap.insert(35);
	heap.inorder();


	heap.deleteNode(6);

	heap.inorder();
	heap.deleteNode(13);

	heap.inorder();
	heap.deleteNode(35);

	heap.inorder();

	return 0;
}

//Psuedo code
#ifdef PSUEDO
STRUCT Node :
data
left
right
parent
CONSTRUCTOR(val) :
	data = val
	left = NULL
	right = NULL
	parent = NULL
	END CONSTRUCTOR
	END STRUCT


METHOD swap(a, b) :
	temp = a
	a = b
	b = temp
	END METHOD


CLASS MinHeap :
VARIABLES:
root
nodeCount

CONSTRUCTOR :
root = null
nodeCount = 0

METHOD getHighestBit(x) :
	bit = 1
	WHILE bit <= x :
	bit = bit * 2
	RETURN bit / 2

	METHOD getLastNode() :
	IF root is null :
RETURN null
path = nodeCount
temp = root
bit = getHighestBit(nodeCount) / 2
WHILE bit > 0:
IF(path AND bit) is nonzero :
temp = temp.right
ELSE :
temp = temp.left
bit = bit / 2
RETURN temp

METHOD heapifyUp(node) :
	WHILE node has a parent AND node.data < node.parent.data :
	SWAP node.data with node.parent.data
	node = node.parent

	METHOD heapifyDown(node) :
	WHILE node is not null :
	smallest = node
	IF node.left exists AND node.left.data < smallest.data :
	smallest = node.left
	IF node.right exists AND node.right.data < smallest.data :
	smallest = node.right
	IF smallest is not node :
	SWAP node.data with smallest.data
	node = smallest
	ELSE :
BREAK out of loop

METHOD findNode(currentNode, val) :
	IF currentNode is null :
RETURN null
IF currentNode.data equals val :
RETURN currentNode
found = findNode(currentNode.left, val)
IF found is not null :
	RETURN found
	RETURN findNode(currentNode.right, val)

	METHOD inorderPrep(node) :
	IF node is null :
RETURN
inorderPrep(node.left)
PRINT node.data
inorderPrep(node.right)

METHOD insert(val) :
	newNode = new Node(val)
	nodeCount = nodeCount + 1
	IF root is null :
root = newNode
RETURN

path = nodeCount
temp = root
bit = getHighestBit(nodeCount) / 2

WHILE bit > 1:
IF(path AND bit) is nonzero :
temp = temp.right
ELSE :
temp = temp.left
bit = bit / 2

newNode.parent = temp
IF(path AND 1) is nonzero :
temp.right = newNode
ELSE :
temp.left = newNode

heapifyUp(newNode)

METHOD deleteNode(val) :
	IF root is null :
RETURN

target = findNode(root, val)
IF target is null :
PRINT "Value not found."
RETURN

last = getLastNode()

IF target equals last :
IF last.parent exists :
IF last is left child of its parent :
last.parent.left = null
ELSE :
last.parent.right = null
ELSE :
root = null
DELETE last
nodeCount = nodeCount - 1
RETURN

target.data = last.data
IF last.parent exists :
IF last is left child of its parent :
last.parent.left = null
ELSE :
last.parent.right = null
DELETE last
nodeCount = nodeCount - 1

IF target has a parent AND target.data < target.parent.data :
	heapifyUp(target)
	ELSE :
	heapifyDown(target)

	METHOD inorder() :
	inorderPrep(root)
	PRINT newline

	METHOD clearTree(node) :
	IF node is null :
RETURN
clearTree(node.left)
clearTree(node.right)
DELETE node

DESTRUCTOR :
clearTree(root)
END DESTRUCTOR
END CLASS
BEGIN MAIN :
CREATE new MinHeap heap
heap.insert(2)
heap.insert(1)
heap.insert(10)
heap.insert(6)
heap.insert(3)
heap.insert(8)
heap.insert(7)
heap.insert(13)
heap.insert(20)
heap.insert(14)
heap.insert(0)
heap.insert(35)
heap.inorder()
heap.deleteNode(6)
heap.inorder()
heap.deleteNode(13)
heap.inorder()
heap.deleteNode(35)
heap.inorder()
END MAIN
#endif

#endif
