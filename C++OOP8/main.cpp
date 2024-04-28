#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    void push(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    T pop() {
        if (is_empty()) {
            throw runtime_error("Stack is empty");
        }

        Node<T>* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    bool is_empty() const {
        return top == nullptr;
    }

    T peek() const {
        if (is_empty()) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }

    int get_size() const {
        return size;
    }

    Stack<T>* clone() const {
        Stack<T>* clonedStack = new Stack<T>();
        Node<T>* current = top;
        Stack<T>* temp = new Stack<T>();

        while (current != nullptr) {
            temp->push(current->data);
            current = current->next;
        }

        current = temp->top;

        while (current != nullptr) {
            clonedStack->push(current->data);
            current = current->next;
        }

        delete temp;
        return clonedStack;
    }

    Stack<T>* operator+(const Stack<T>& other) const {
        Stack<T>* combinedStack = this->clone();
        Node<T>* current = other.top;

        while (current != nullptr) {
            combinedStack->push(current->data);
            current = current->next;
        }

        return combinedStack;
    }

    Stack<T>* operator*(const Stack<T>& other) const {
        Stack<T>* commonStack = new Stack<T>();
        Node<T>* current = top;

        while (current != nullptr) {
            Node<T>* otherCurrent = other.top;
            while (otherCurrent != nullptr) {
                if (current->data == otherCurrent->data) {
                    commonStack->push(current->data);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }

        return commonStack;
    }

    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }
};

int main() {
    Stack<int> stack1, stack2;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack2.push(2);
    stack2.push(3);
    stack2.push(4);

    cout << "Stack 1 size: " << stack1.get_size() << endl;
    cout << "Stack 2 size: " << stack2.get_size() << endl;

    Stack<int>* clonedStack = stack1.clone();
    cout << "Clone size: " << clonedStack->get_size() << endl;

    Stack<int>* combinedStack = stack1 + stack2;
    cout << "Combined size: " << combinedStack->get_size() << endl;

    Stack<int>* commonStack = stack1 * stack2;
    cout << "Common size: " << commonStack->get_size() << endl;

    delete clonedStack;
    delete combinedStack;
    delete commonStack;

}
