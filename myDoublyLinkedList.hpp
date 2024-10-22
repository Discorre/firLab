#ifndef MYDOUBLYLINKEDLIST_HPP
#define MYDOUBLYLINKEDLIST_HPP

template <typename T>
class MyDoublyLinkedList {
private:
    struct Node {
        T data;          // Данные узла
        Node* next;      // Указатель на следующий узел
        Node* prev;      // Указатель на предыдущий узел

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;         // Указатель на голову списка
    Node* tail;         // Указатель на хвост списка
    size_t size;        // Текущий размер списка

public:
    MyDoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~MyDoublyLinkedList() {
        clear();
    }

    // Добавление элемента в голову
    void LPUSHHEAD(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    // Добавление элемента в хвост
    void LPUSHTAIL(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++size;
    }

    // Удаление элемента с головы
    void LDELHEAD() {
        if (!head) {
            throw std::runtime_error("List is empty");
        }
        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr; // Если список стал пустым
        }
        delete temp;
        --size;
    }

    // Удаление элемента с хвоста
    void LDELTAIL() {
        if (!tail) {
            throw std::runtime_error("List is empty");
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr; // Если список стал пустым
        }
        delete temp;
        --size;
    }

    // Удаление элемента по индексу
    void LDEL(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            LDELHEAD();
            return;
        }
        if (index == size - 1) {
            LDELTAIL();
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        --size;
    }

    // Поиск элемента
    bool contains(const T& value) const {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Чтение элемента по индексу
    T LGET(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Печать элементов списка
    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Получение текущего размера списка
    size_t getSize() const {
        return size;
    }

    // Сохранение списка в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for writing");
        }
        Node* current = head;
        while (current) {
            file << current->data << "\n";
            current = current->next;
        }
        file.close();
    }

    // Загрузка списка из файла
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for reading");
        }
        clear(); // Очищаем текущий список перед загрузкой
        T value;
        while (file >> value) {
            LPUSHTAIL(value); // Добавляем элементы в хвост списка
        }
        file.close();
    }

    // Очистка списка
    void clear() {
        while (head) {
            LDELHEAD();
        }
    }
};

#endif