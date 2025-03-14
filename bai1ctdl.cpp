#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void xuatMang(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void xoaPhanTu(vector<int>& arr, int k) {
    if (k >= 0 && k < arr.size()) {
        arr.erase(arr.begin() + k);
    } else {
        cout << "Vị trí không hợp lệ!" << endl;
    }
}

void lietKeMax(const vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    cout << "Những phần tử có giá trị lớn nhất là: ";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == maxVal) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void lietKeMin(const vector<int>& arr) {
    int minVal = *min_element(arr.begin(), arr.end());
    cout << "Những phần tử có giá trị nhỏ nhất là: ";
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == minVal) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int demPhanTuAm(const vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

int giaTriAmLonNhat(const vector<int>& arr) {
    int maxNegative = INT_MIN;
    bool found = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0 && arr[i] > maxNegative) {
            maxNegative = arr[i];
            found = true;
        }
    }
    return found ? maxNegative : -1; // -1 nếu không có giá trị âm
}

int giaTriDuongNhoNhat(const vector<int>& arr) {
    int minPositive = INT_MAX;
    bool found = false;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0 && arr[i] < minPositive) {
            minPositive = arr[i];
            found = true;
        }
    }
    return found ? minPositive : -1; // -1 nếu không có giá trị dương
}

bool timPhanTuX(const vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            return true;
        }
    }
    return false;
}

int demPhanTuX(const vector<int>& arr, int x) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, k, x;
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Nhập các phần tử của mảng: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // a. Xuất mảng 1 chiều
    cout << "Mảng ban đầu: ";
    xuatMang(arr);

    // b. Xoá 1 phần tử tại vị trí k
    cout << "Nhập vị trí k để xoá: ";
    cin >> k;
    xoaPhanTu(arr, k);
    cout << "Mảng sau khi xoá phần tử tại vị trí k: ";
    xuatMang(arr);
    
    // c. Liệt kê những phần tử có giá trị lớn nhất
    lietKeMax(arr);
    
    // d. Liệt kê những phần tử có giá trị nhỏ nhất
    lietKeMin(arr);
    
    // e. Đếm số phần tử có giá trị âm
    cout << "Số phần tử âm trong mảng: " << demPhanTuAm(arr) << endl;
    
    // f. Cho biết giá trị âm lớn nhất
    int maxNegative = giaTriAmLonNhat(arr);
    if (maxNegative != -1) {
        cout << "Giá trị âm lớn nhất trong mảng: " << maxNegative << endl;
    } else {
        cout << "Không có giá trị âm trong mảng." << endl;
    }

    // g. Cho biết giá trị dương nhỏ nhất
    int minPositive = giaTriDuongNhoNhat(arr);
    if (minPositive != -1) {
        cout << "Giá trị dương nhỏ nhất trong mảng: " << minPositive << endl;
    } else {
        cout << "Không có giá trị dương trong mảng." << endl;
    }

    // h. Tìm phần tử có khóa bằng x có hay không
    cout << "Nhập giá trị x để tìm: ";
    cin >> x;
    if (timPhanTuX(arr, x)) {
        cout << "Có phần tử có giá trị " << x << " trong mảng." << endl;
    } else {
        cout << "Không có phần tử có giá trị " << x << " trong mảng." << endl;
    }

    // i. Đếm số phần tử có giá trị bằng x
    int countX = demPhanTuX(arr, x);
    if (countX > 0) {
        cout << "Số phần tử có giá trị " << x << " trong mảng: " << countX << endl;
    } else {
        cout << "Không có phần tử nào có giá trị " << x << " trong mảng." << endl;
    }

    return 0;
}
