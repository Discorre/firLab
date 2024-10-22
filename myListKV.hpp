#ifndef MYLISTKV_HPP
#define MYLISTKV_HPP

template <typename K, typename V>
class MyList {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(K key, V value) : key(key), value(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    // Конструктор
    MyList() : head(nullptr), tail(nullptr), length(0) {}

    // Деструктор
    ~MyList() {
        clear();
    }

    // Добавление пары ключ-значение в конец списка
    void push_back(const K& key, const V& value) {
        Node* newNode = new Node(key, value);
        if (tail == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // Поиск элемента по ключу
    bool find(const K& key, V& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Получение элемента по индексу
    bool findAt(int index, K& key, V& value) const {
        if (index < 0 || index >= length) {
            return false; // Индекс вне диапазона
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        key = current->key;
        value = current->value;
        return true;
    }

    // Удаление элемента по ключу
    bool remove(const K& key) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev != nullptr) {
                    prev->next = current->next;
                }
                else {
                    head = current->next;
                }
                if (current == tail) {
                    tail = prev;
                }
                delete current;
                length--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }

    // Метод для печати элементов списка
    void print() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "{" << current->key << ": " << current->value << "} ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Получение длины списка
    int size() const {
        return length;
    }

    // Очистка списка
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        length = 0;
    }
};

#endif