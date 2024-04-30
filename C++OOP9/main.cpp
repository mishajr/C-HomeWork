#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
    Node(int value, Node* next, Node* prev) : value(value), next(next), prev(prev) {}
};

class List {
private:
    Node* head;  // Вказівник на початок списку
    Node* tail;  // Вказівник на кінець списку
    size_t size; // Розмір списку

public:
    // Конструктор за замовчуванням
    List() : head(nullptr), tail(nullptr), size(0) {}

    // Конструктор зі списком значень
    List(initializer_list<int> values) : head(nullptr), tail(nullptr), size(0) {
        for (int value : values) {
            AddToTail(value);
        }
    }

    // Додавання елемента на початок списку
    void AddToHead(int value) {
        Node* newNode = new Node(value, head, nullptr);

        if (IsEmpty()) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    // Додавання елемента в кінець списку
    void AddToTail(int value) {
        Node* newNode = new Node(value, nullptr, tail);

        if (IsEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    // Видалення елемента за значенням
    void DeleteByValue(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->value == value) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr) {
                        tail->next = nullptr;
                    }
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }

                delete current;
                size--;
                return;
            }
            current = current->next;
        }
    }

    // Очистак списку
    void Clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    // Перенавантаження оператора []
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Недопустимий індекс");
        }

        Node* current = head;
        int i = 0;
        while (current != nullptr) {
            if (i == index) {
                return current->value;
            }
            current = current->next;
            i++;
        }

        throw out_of_range("Недопустимий індекс");
    }

    // Виведення елементів списку у зворотному порядку
    void PrintReverse() const {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }
    // Виведення всього списку
    void PrintAll() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void RemoveDuplicates() {
        Node* current = head;

        // Перший цикл що перебирає все
        while (current != nullptr) {
            Node* runner = current;

            // Другий цикл що перебирає всі наступні ноди для порівняння з поточним
            while (runner->next != nullptr) {
                if (runner->next->value == current->value) {
                    // Видалення дубліката
                    Node* temp = runner->next;
                    runner->next = runner->next->next;
                    if (runner->next != nullptr) {
                        runner->next->prev = runner;
                    } else {
                        tail = runner; // Оновлення хвоста якщо видаляємо останній елемент
                    }
                    delete temp;
                    size--;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
    // Ці коментарі це просто жах
    //    Не хочу більше так мучитись,дякую♥

    // Пошук мінімального значення у списку
    int FindMin() const {
        if (IsEmpty()) {
            throw logic_error("Список порожній");
        }

        int minValue = head->value;
        Node* current = head->next;

        while (current != nullptr) {
            if (current->value < minValue) {
                minValue = current->value;
            }
            current = current->next;
        }

        return minValue;
    }

    // пошук максимального значення у списку
    int FindMax() const {
        if (IsEmpty()) {
            throw logic_error("Список порожній");
        }

        int maxValue = head->value;
        Node* current = head->next;

        while (current != nullptr) {
            if (current->value > maxValue) {
                maxValue = current->value;
            }
            current = current->next;
        }

        return maxValue;
    }

    // Перевірка, чи список порожній
    bool IsEmpty() const {
        return head == nullptr;
    }

    // Дестуктор, що видаляє всі елементи списку
    ~List() {
        Clear();
    }
};

int main() {
    List myList = {1, 2, 3, 2, 4, 3, 5};

    cout << "Список до видалення дублікатів:" << endl;
    myList.PrintAll();

    myList.RemoveDuplicates();

    cout << "Список після видалення дублікатів:" << endl;
    myList.PrintAll();

    cout << "Список у зворотньому порядку:" << endl;
    myList.PrintReverse();

    cout << "Мінімальне значення у списку: " << myList.FindMin() << endl;
    cout << "Максимальне значення у списку: " << myList.FindMax() << endl;

    // Приклад використання оператора [] з коректним і некоректним індексом
    cout << "Елемент з індексом 2: " << myList[2] << endl;
    // Спроба виклику з індексом 10 (поза межами списку)
    cout << "Елемент з індексом 10: " << myList[10] << endl; // Видасть виключення
}
