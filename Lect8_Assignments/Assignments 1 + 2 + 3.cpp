#include <iostream>
#include <vector>

using namespace std;

//bai1
#ifdef DISABLED
//quicksort
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    // Chon phan tu cuoi lam pivot
    int pivot = arr[high];

    // Dat chi so cua phan tu nho hon pivot
    int i = low - 1;

    // Duyet tu vi tri low den high - 1
    for (int j = low; j <= high - 1; j++) {
        // Neu phan tu hien tai nho hon pivot
        if (arr[j] < pivot) {
            i++; // Tang chi so cua phan tu nho hon pivot
            swap(arr[i], arr[j]); // Hoan doi phan tu
        }
    }

    // Dua pivot ve vi tri dung trong mang
    swap(arr[i + 1], arr[high]);
    return i + 1; // Tra ve chi so cua pivot sau khi sap xep
}

void quickSort(vector<int>& arr, int low, int high) {
    // Neu chi so con trai nho hon chi so con phai thi tiep tuc de quy
    if (low < high) {
        int pi = partition(arr, low, high); // Chia mang thanh 2 phan
        quickSort(arr, low, pi - 1); // Sap xep mang ben trai
        quickSort(arr, pi + 1, high); // Sap xep mang ben phai
    }
}

int main() {
    int n;
    cin >> n; // Nhap so luong phan tu cua mang

    vector<int> arr(n); // Tao mang co n phan tu

    // Nhap cac phan tu cua mang
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1); // Goi ham quickSort de sap xep mang

    // In ra mang da sap xep
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}



///mergesort
// Ham merge de tron hai mang con da duoc sap xep thanh mot mang da sap xep
void merge(vector<int>& arr, int left, int right, int middle) {
	// Tinh so phan tu cua hai mang con
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// Tao hai vector de luu hai mang con
	vector<int> L(n1), R(n2);

	// Copy du lieu tu mang goc sang mang con L
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}

	// Copy du lieu tu mang goc sang mang con R
	for (int i = 0; i < n2; i++) {
		R[i] = arr[middle + i + 1];
	}

	// i la chi so cua mang L, j la chi so cua mang R, k la chi so cua mang goc arr
	int i = 0, j = 0;
	int k = left;

	// Tron hai mang con vao mang goc theo thu tu tang dan
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy cac phan tu con lai cua mang L neu co
	while (i < n1) {
		arr[k] = L[i];
		k++;
		i++;
	}

	// Copy cac phan tu con lai cua mang R neu co
	while (j < n2) {
		arr[k] = R[j];
		k++;
		j++;
	}
}

// Ham mergeSort dung de sap xep mang theo thuat toan chia de tri
void mergeSort(vector<int>& arr, int left, int right) {
	// Dieu kien dung cua de quy khi chi con mot phan tu
	if (left >= right) {
		return;
	}

	// Tinh chi so giua cua mang
	int middle = left + (right - left) / 2;

	// Goi de quy de sap xep mang con ben trai
	mergeSort(arr, left, middle);

	// Goi de quy de sap xep mang con ben phai
	mergeSort(arr, middle + 1, right);

	// Tron hai mang con da sap xep
	merge(arr, left, right, middle);
}

int main() {
	int n;
	// Nhap so luong phan tu cua mang
	cin >> n;
	vector<int> arr(n);

	// Nhap cac phan tu cua mang
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// Goi ham sap xep mergeSort
	mergeSort(arr, 0, n - 1);

	// In ra mang da sap xep
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}


#endif

//bai2
#ifdef DISABLED
// Ham de quy genSum dung de tao tat ca tong con co the tu mang arr
void genSum(int index, int currentSum, vector<int>& arr, vector<int>& result) {
	// Neu da duyet het mang, them tong hien tai vao result
	if (index == arr.size()) {
		result.push_back(currentSum);
		return;
	}

	// Khong chon phan tu tai index hien tai
	genSum(index + 1, currentSum, arr, result);

	// Chon phan tu tai index hien tai va cong vao tong
	genSum(index + 1, currentSum + arr[index], arr, result);
}

// Ham mergeosrt voi cong dung y het nhu bai 1 o tren
void merge(vector<int>& arr, int left, int right, int middle) {
	int n1 = middle - left + 1;
	int n2 = right - middle;


	vector<int> L(n1), R(n2);


	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}


	for (int i = 0; i < n2; i++) {
		R[i] = arr[middle + i + 1];
	}

	int i = 0, j = 0;
	int k = left;


	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while (i < n1) {
		arr[k] = L[i];
		k++;
		i++;
	}

	while (j < n2) {
		arr[k] = R[j];
		k++;
		j++;
	}
}

// Ham sap xep merge sort
void mergeSort(vector<int>& arr, int left, int right) {
	if (left >= right) {
		return;
	}

	int middle = left + (right - left) / 2;
	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);


	merge(arr, left, right, middle);
}

// Ham kiem tra xem co cap tong hai day bang target hay khong
void checkTargetSum(int target, vector<int>& arr, vector<int>& arr2) {
	int n = 0; // bien nay khong su dung
	int m = arr2.size(); // chi luu kich thuoc arr2 (khong can thiet lam)

	// Sinh cac tong con tu arr va arr2
	vector<int> resultSum;
	vector<int> resultSum2;
	genSum(0, 0, arr, resultSum);
	genSum(0, 0, arr2, resultSum2);

	// Sap xep hai danh sach tong
	if (!resultSum.empty()) {
		mergeSort(resultSum, 0, resultSum.size() - 1);
	}
	if (!resultSum2.empty()) {
		mergeSort(resultSum2, 0, resultSum2.size() - 1);
	}

	// Su dung hai con tro de tim cap tong bang target
	int left = 0;
	int right = resultSum2.size() - 1;

	while (left < resultSum.size() && right >= 0) {
		int currentSum = resultSum[left] + resultSum2[right];
		if (currentSum == target) {
			// Neu tim thay cap tong bang target thi in YES va ket thuc
			cout << "YES" << endl;
			return;
		}
		else if (currentSum < target) {
			// Neu tong nho hon target thi tang con tro ben trai
			left++;
		}
		else {
			// Neu tong lon hon target thi giam con tro ben phai
			right--;
		}
	}

	// Neu khong tim duoc cap nao phu hop thi in NO
	cout << "NO " << endl;
}

int main() {
	int n, targetSum;

	// Nhap so luong phan tu va tong muc tieu
	cin >> n >> targetSum;

	vector<int> arr;
	vector<int> arr2;

	// Tach mang thanh hai phan arr va arr2
	for (int i = 0; i < n / 2; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	for (int i = n / 2; i < n; ++i) {
		int num;
		cin >> num;
		arr2.push_back(num);
	}

	// Goi ham kiem tra tong
	checkTargetSum(targetSum, arr, arr2);
}

#endif


//bai3

#ifdef DISABLED
const int MAX_SIZE = 1000;
// Cau truc Item dai dien cho moi vat voi trong luong va gia tri
struct Item {
	int weight;
	int value;
};

//ham mergesort tuong tu chuc nang y het nhu bai1
void merge(std::vector<Item>& arr, int left, int right, int middle) {
	int n1 = middle - left + 1;
	int n2 = right - middle;
	std::vector<Item> L(n1), R(n2);

	for (int i = 0; i < n1; ++i) {
		L[i] = arr[left + i];
	}
	for (int i = 0; i < n2; ++i) {
		R[i] = arr[middle + i + 1];
	}

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i].weight <= R[j].weight) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		k++;
		i++;
	}

	while (j < n2) {
		arr[k] = R[j];
		k++;
		j++;
	}
}

void mergeSort(std::vector<Item>& arr, int left, int right) {
	if (left >= right) {
		return;
	}
	int middle = left + (right - left) / 2;
	mergeSort(arr, left, middle);
	mergeSort(arr, middle + 1, right);
	merge(arr, left, right, middle);
}

void generateSubsets(int index, int currentWeight, int currentValue, const std::vector<Item>& items, std::vector<Item>& subsets) {
	if (index == items.size()) {
		subsets.push_back({ currentWeight, currentValue });
		return;
	}
	generateSubsets(index + 1, currentWeight, currentValue, items, subsets);
	generateSubsets(index + 1, currentWeight + items[index].weight, currentValue + items[index].value, items, subsets);
}


// Ham loai bo cac tap con khong toi uu (co trong luong lon hon nhung gia tri lai nho hon hoac bang)
// Chi giu lai cac tap con co gia tri lon nhat voi tung trong luong
vector<Item> pruneSubsets(vector<Item>& subsets) {
	if (subsets.empty()) return {};

	// Sap xep cac tap con theo trong luong tang dan
	mergeSort(subsets, 0, subsets.size() - 1);

	vector<Item> pruned_subsets;
	pruned_subsets.push_back(subsets[0]);

	for (size_t i = 1; i < subsets.size(); ++i) {
		// Chi them vao neu gia tri lon hon tap con truoc do (toi uu hon)
		if (subsets[i].value > pruned_subsets.back().value) {
			pruned_subsets.push_back(subsets[i]);
		}
	}

	return pruned_subsets;
}


// Ham tim cap tap con tu hai nua A va B co tong trong luong <= X va tong gia tri lon nhat
int find_best_pair(vector<Item>& L_A, int sizeA, vector<Item>& L_B, int sizeB, int X) {
	int max_total_value = 0;

	// Tinh mang prefix_max_B de luu gia tri lon nhat toi vi tri i trong B
	vector<int> prefix_max_B(sizeB);
	if (sizeB > 0) {
		prefix_max_B[0] = L_B[0].value;
		for (int i = 1; i < sizeB; ++i) {
			prefix_max_B[i] = max(prefix_max_B[i - 1], L_B[i].value);
		}
	}

	// Duyet qua moi tap con trong L_A
	for (int i = 0; i < sizeA; ++i) {
		int wA = L_A[i].weight;
		int vA = L_A[i].value;

		// Trong luong con lai co the su dung tu L_B
		int remaining_weight = X - wA;
		if (remaining_weight < 0) continue;

		// Tim tap con trong L_B co trong luong <= remaining_weight
		int low = 0;
		int high = sizeB - 1;
		int best_index_B = -1;

		while (low <= high) {
			int mid = (low + high) / 2;
			if (L_B[mid].weight <= remaining_weight) {
				best_index_B = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		// Neu tim thay, tinh tong gia tri
		if (best_index_B != -1) {
			int vB = prefix_max_B[best_index_B];
			max_total_value = max(max_total_value, vA + vB);
		}
		// Neu khong ghep duoc voi B thi chi lay A
		else if (wA <= X) {
			max_total_value = max(max_total_value, vA);
		}
	}

	return max_total_value;
}

int main() {
	int n, X;
	cin >> n >> X;

	// Nhap n item gom trong luong va gia tri
	vector<Item> items(n);
	for (int i = 0; i < n; ++i) {
		cin >> items[i].weight >> items[i].value;
	}

	// Tach danh sach item thanh hai nua
	int n1 = n / 2;
	vector<Item> first_half(items.begin(), items.begin() + n1);
	vector<Item> second_half(items.begin() + n1, items.end());

	// Sinh tat ca tap con cua moi nua
	vector<Item> subsets_A;
	generateSubsets(0, 0, 0, first_half, subsets_A);

	vector<Item> subsets_B;
	generateSubsets(0, 0, 0, second_half, subsets_B);

	// Loai bo cac tap con khong toi uu
	vector<Item> pruned_A = pruneSubsets(subsets_A);
	vector<Item> pruned_B = pruneSubsets(subsets_B);

	// Tim tong gia tri lon nhat co the dat duoc voi tong trong luong <= X
	int max_value = find_best_pair(pruned_A, pruned_A.size(), pruned_B, pruned_B.size(), X);

	cout << max_value << endl;

	return 0;
}
#endif 
