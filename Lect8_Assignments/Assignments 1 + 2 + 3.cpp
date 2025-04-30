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
// Ham dynamic programming de tao tat ca tong co the tao tu tap con cua arr
void computeSubsetSumsDP(const vector<int>& arr, int target, vector<bool>& dp) {
	dp[0] = true; // tong 0 luon co the tao duoc

	for (int num : arr) {
		for (int i = target; i >= num; --i) {
			if (dp[i - num]) {
				dp[i] = true;
			}
		}
	}
}

// Ham kiem tra co tong con tu arr + arr2 bang target hay khong
void checkTargetSum(int target, const vector<int>& arr, const vector<int>& arr2) {
	vector<bool> dp1(target + 1, false);
	vector<bool> dp2(target + 1, false);

	computeSubsetSumsDP(arr, target, dp1);
	computeSubsetSumsDP(arr2, target, dp2);

	for (int i = 0; i <= target; ++i) {
		if (dp1[i] && dp2[target - i]) {
			cout << "YES" << endl;
			return;
		}
	}

	cout << "NO" << endl;
}

int main() {
	int n, targetSum;
	cin >> n >> targetSum;

	vector<int> arr;
	vector<int> arr2;

	// Tach mang thanh 2 nua
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
// Cau truc Item luu trong luong va gia tri cua moi vat
struct Item {
	int weight;
	int value;
};

int main() {
	int n, maxWeight;
	cin >> n >> maxWeight;

	// Nhap n vat, moi vat co trong luong va gia tri
	vector<Item> items(n);
	for (int i = 0; i < n; ++i) {
		cin >> items[i].weight >> items[i].value;
	}

	// Khoi tao mang dp voi maxWeight + 1 phan tu, tat ca bang 0
	// dp[w] luu tong gia tri lon nhat co the dat duoc voi trong luong la w
	vector<int> dp(maxWeight + 1, 0);

	// Duyet qua tung vat trong danh sach
	for (int i = 0; i < n; ++i) {
		// Duyet nguoc tu maxWeight ve weight cua vat
		// Dam bao moi vat chi duoc dung 1 lan
		for (int w = maxWeight; w >= items[i].weight; --w) {
			// Cap nhat dp[w] neu chon vat hien tai cho gia tri cao hon
			if (dp[w] < dp[w - items[i].weight] + items[i].value) {
				dp[w] = dp[w - items[i].weight] + items[i].value;
			}
		}
	}

	// Tim gia tri lon nhat trong mang dp
	int maxValue = 0;
	for (int i = 0; i <= maxWeight; ++i) {
		if (dp[i] > maxValue) {
			maxValue = dp[i];
		}
	}

	// In ra ket qua la tong gia tri lon nhat
	cout << maxValue << endl;
	return 0;
}
#endif 
