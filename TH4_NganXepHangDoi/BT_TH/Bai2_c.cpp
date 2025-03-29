#include <iostream>
#include <cmath>
#include <algorithm>

struct Node {
    int data; // Dữ liệu của nút
    Node* next; // Con trỏ đến nút tiếp theo
};

struct LinkedQueueInt {
    Node* front; // Con trỏ đầu của hàng đợi
    Node* rear; // Con trỏ cuối của hàng đợi
};

void InitQueue(LinkedQueueInt& queue) {
    queue.front = queue.rear = nullptr; // Khởi tạo hàng đợi rỗng
}

bool IsEmpty(LinkedQueueInt& queue) {
    return (queue.front == nullptr); // Kiểm tra hàng đợi có rỗng không
}

void Enqueue(LinkedQueueInt& queue, int x) {
    Node* temp = new Node(); // Tạo nút mới
    temp->data = x; // Gán dữ liệu cho nút
    temp->next = nullptr; // Nút mới không trỏ đến nút nào
    if (IsEmpty(queue)) {
        queue.front = queue.rear = temp; // Nếu hàng đợi rỗng, đặt cả front và rear về nút mới
    } else {
        queue.rear->next = temp; // Nút cuối trỏ đến nút mới
        queue.rear = temp; // Đặt rear về nút mới
    }
}

int Dequeue(LinkedQueueInt& queue) {
    if (IsEmpty(queue)) {
        std::cout << "Queue is empty\n";
        return -1;
    }
    Node* temp = queue.front; // Lưu trữ nút đầu để xóa
    int data = temp->data; // Lấy dữ liệu của nút đầu
    queue.front = queue.front->next; // Đặt front về nút tiếp theo
    delete temp; // Xóa nút đầu
    if (queue.front == nullptr) {
        queue.rear = nullptr; // Nếu hàng đợi rỗng, đặt rear về nullptr
    }
    return data;
}

// Hàm tìm giá trị lớn nhất trong mảng
int getMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Hàm RadixSort sử dụng LinkedQueueInt
void RadixSort(int arr[], int n) {
    LinkedQueueInt buckets[10]; // Mảng các hàng đợi cho các chữ số từ 0 đến 9
    for (int i = 0; i < 10; i++) {
        InitQueue(buckets[i]); // Khởi tạo các hàng đợi
    }

    int maxVal = getMax(arr, n); // Tìm giá trị lớn nhất trong mảng
    int maxDigits = log10(maxVal) + 1; // Tính số chữ số của giá trị lớn nhất

    for (int digit = 0; digit < maxDigits; digit++) {
        for (int i = 0; i < n; i++) {
            int bucketIndex = (arr[i] / static_cast<int>(pow(10, digit))) % 10; // Tính chỉ số hàng đợi
            Enqueue(buckets[bucketIndex], arr[i]); // Thêm phần tử vào hàng đợi tương ứng
        }

        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!IsEmpty(buckets[i])) {
                arr[index++] = Dequeue(buckets[i]); // Lấy phần tử từ hàng đợi và đặt lại vào mảng
            }
        }
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    RadixSort(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " "; // In ra mảng đã được sắp xếp
    }

    return 0;
}