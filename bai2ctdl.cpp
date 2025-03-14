#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct SinhVien {
    string ten;
    string maSo;
    float diemTrungBinh;
};

// Hàm in danh sách sinh viên
void inDanhSachSinhVien(const vector<SinhVien>& danhSach) {
    cout << "Danh sách sinh viên:\n";
    for (const auto& sv : danhSach) {
        cout << "Tên: " << sv.ten << ", Mã số: " << sv.maSo << ", Điểm trung bình: " << sv.diemTrungBinh << endl;
    }
}

// Hàm liệt kê sinh viên có điểm trung bình cao nhất
void lietKeSinhVienDiemMax(const vector<SinhVien>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sách sinh viên rỗng.\n";
        return;
    }
    
    // Tìm điểm trung bình cao nhất
    float diemMax = -1;
    for (const auto& sv : danhSach) {
        if (sv.diemTrungBinh > diemMax) {
            diemMax = sv.diemTrungBinh;
        }
    }
    
    // Liệt kê các sinh viên có điểm trung bình cao nhất
    cout << "Sinh viên có điểm trung bình cao nhất (" << diemMax << "):\n";
    for (const auto& sv : danhSach) {
        if (sv.diemTrungBinh == diemMax) {
            cout << "Tên: " << sv.ten << ", Mã số: " << sv.maSo << ", Điểm trung bình: " << sv.diemTrungBinh << endl;
        }
    }
}

// Hàm đếm số sinh viên có điểm trung bình >= 5
void demSinhVienDiemLonHon5(const vector<SinhVien>& danhSach) {
    int count = 0;
    for (const auto& sv : danhSach) {
        if (sv.diemTrungBinh >= 5) {
            count++;
        }
    }
    
    if (count == 0) {
        cout << "Không có sinh viên có điểm trung bình >= 5.\n";
    } else {
        cout << "Số sinh viên có điểm trung bình >= 5: " << count << endl;
    }
}

// Hàm tìm sinh viên theo tên
void timSinhVienTheoTen(const vector<SinhVien>& danhSach, const string& ten) {
    bool found = false;
    for (const auto& sv : danhSach) {
        if (sv.ten == ten) {
            cout << "Sinh viên tìm thấy: " << "Tên: " << sv.ten << ", Mã số: " << sv.maSo << ", Điểm trung bình: " << sv.diemTrungBinh << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "Không có sinh viên tên " << ten << " trong lớp học.\n";
    }
}

// Hàm xoá sinh viên theo mã số
void xoaSinhVienTheoMaSo(vector<SinhVien>& danhSach, const string& maSo) {
    auto it = find_if(danhSach.begin(), danhSach.end(), [&maSo](const SinhVien& sv) {
        return sv.maSo == maSo;
    });
    
    if (it != danhSach.end()) {
        danhSach.erase(it);
        cout << "Đã xoá sinh viên có mã số " << maSo << ".\n";
    } else {
        cout << "Không có sinh viên có mã số " << maSo << ".\n";
    }
}

// Hàm chèn sinh viên vào danh sách theo thứ tự điểm trung bình tăng dần
void chenSinhVien(vector<SinhVien>& danhSach, const SinhVien& svMoi) {
    auto it = lower_bound(danhSach.begin(), danhSach.end(), svMoi, [](const SinhVien& sv1, const SinhVien& sv2) {
        return sv1.diemTrungBinh < sv2.diemTrungBinh;
    });
    danhSach.insert(it, svMoi);
    cout << "Đã chèn sinh viên " << svMoi.ten << " vào danh sách.\n";
}

// Menu và xử lý các yêu cầu
int main() {
    vector<SinhVien> danhSach;
    int n;
    
    // Nhập số lượng sinh viên
    cout << "Nhập số lượng sinh viên: ";
    cin >> n;
    cin.ignore(); // Để bỏ qua ký tự newline còn lại sau khi nhập số
    
    // Nhập thông tin sinh viên
    for (int i = 0; i < n; ++i) {
        SinhVien sv;
        cout << "Nhập tên sinh viên " << i + 1 << ": ";
        getline(cin, sv.ten);
        cout << "Nhập mã số sinh viên: ";
        getline(cin, sv.maSo);
        cout << "Nhập điểm trung bình: ";
        cin >> sv.diemTrungBinh;
        cin.ignore();
        danhSach.push_back(sv);
    }
    
    int choice;
    do {
        // In menu cho người dùng chọn
        cout << "\nMenu:\n";
        cout << "1. In danh sách sinh viên\n";
        cout << "2. Liệt kê sinh viên có điểm trung bình cao nhất\n";
        cout << "3. Đếm số sinh viên có điểm trung bình >= 5\n";
        cout << "4. Tìm sinh viên theo tên\n";
        cout << "5. Xoá sinh viên theo mã số\n";
        cout << "6. Chèn một sinh viên vào lớp học\n";
        cout << "0. Thoát\n";
        cout << "Chọn một thao tác (0-6): ";
        cin >> choice;
        cin.ignore(); // Để bỏ qua ký tự newline còn lại sau khi nhập số
        
        switch (choice) {
            case 1:
                inDanhSachSinhVien(danhSach);
                break;
            case 2:
                lietKeSinhVienDiemMax(danhSach);
                break;
            case 3:
                demSinhVienDiemLonHon5(danhSach);
                break;
            case 4: {
                string ten;
                cout << "Nhập tên sinh viên cần tìm: ";
                getline(cin, ten);
                timSinhVienTheoTen(danhSach, ten);
                break;
            }
            case 5: {
                string maSo;
                cout << "Nhập mã số sinh viên cần xoá: ";
                getline(cin, maSo);
                xoaSinhVienTheoMaSo(danhSach, maSo);
                break;
            }
            case 6: {
                SinhVien svMoi;
                cout << "Nhập tên sinh viên: ";
                getline(cin, svMoi.ten);
                cout << "Nhập mã số sinh viên: ";
                getline(cin, svMoi.maSo);
                cout << "Nhập điểm trung bình: ";
                cin >> svMoi.diemTrungBinh;
                cin.ignore();
                chenSinhVien(danhSach, svMoi);
                break;
            }
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại.\n";
                break;
        }
    } while (choice != 0);
    
    return 0;
}
