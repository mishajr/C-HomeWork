#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size;
    int capacity;
    int grow;

public:
    Array(int initialCapacity = 10, int growBy = 5) : size(0), capacity(initialCapacity), grow(growBy) {
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    int GetSize() const {
        return size;
    }

    void SetSize(int newSize) {
        if (newSize > capacity) {
            int newCapacity = newSize + grow;
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        size = newSize;
    }

    int GetUpperBound() const {
        return size - 1;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void FreeExtra() {
        SetSize(size);
    }

    void RemoveAll() {
        size = 0;
    }

    T& GetAt(int index) {
        if (index < 0 || index >= size) {
            cerr << "Index out of range" << endl;
            exit(1);
        }
        return data[index];
    }

    const T& GetAt(int index) const {
        if (index < 0 || index >= size) {
            cerr << "Index out of range" << endl;
            exit(1);
        }
        return data[index];
    }

    void SetAt(int index, const T& value) {
        if (index < 0 || index >= size) {
            cerr << "Index out of range" << endl;
            exit(1);
        }
        data[index] = value;
    }

    void Add(const T& value) {
        if (size == capacity) {
            SetSize(size + grow);
        }
        data[size++] = value;
    }

    T& operator[](int index) {
        return GetAt(index);
    }

    const T& operator[](int index) const {
        return GetAt(index);
    }

    void Append(const Array<T>& other) {
        int newSize = size + other.GetSize();
        if (newSize > capacity) {
            SetSize(newSize);
        }
        for (int i = 0; i < other.GetSize(); ++i) {
            data[size++] = other[i];
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            grow = other.grow;
            data = new T[capacity];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T* GetData() const {
        return data;
    }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            cerr << "Index out of range" << endl;
            exit(1);
        }
        if (size == capacity) {
            SetSize(size + grow);
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            cerr << "Index out of range" << endl;
            exit(1);
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }
};

template <typename T>
T FindMax(const Array<T>& arr) {
    if (arr.IsEmpty()) {
        cerr << "Array is empty" << endl;
        exit(1);
    }
    T maxVal = arr[0];
    for (int i = 1; i < arr.GetSize(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T>
T FindMin(const Array<T>& arr) {
    if (arr.IsEmpty()) {
        cerr << "Array is empty" << endl;
        exit(1);
    }
    T minVal = arr[0];
    for (int i = 1; i < arr.GetSize(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

template <typename T>
void BubbleSort(Array<T>& arr) {
    int n = arr.GetSize();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
int BinarySearch(const Array<T>& arr, const T& value) {
    int left = 0;
    int right = arr.GetSize() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void ReplaceElement(Array<T>& arr, const T& oldValue, const T& newValue) {
    for (int i = 0; i < arr.GetSize(); ++i) {
        if (arr[i] == oldValue) {
            arr[i] = newValue;
            return;
        }
    }
    cerr << "Element not found" << endl;
}

int main() {
    Array<int> arr;
    arr.Add(5);
    arr.Add(3);
    arr.Add(8);
    arr.Add(1);
    arr.Add(6);

    cout << "Original array:" << endl;
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Max value: " << FindMax(arr) << endl;
    cout << "Min value: " << FindMin(arr) << endl;

    BubbleSort(arr);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int index = BinarySearch(arr, 6);
    if (index != -1) {
        cout << "Element 6 found at index: " << index << endl;
    } else {
        cout << "Element 6 not found" << endl;
    }

    ReplaceElement(arr, 3, 10);
    cout << "Array after replacing element 3 with 10:" << endl;
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


}
