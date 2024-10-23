#ifndef MYFULLBINARYTREE_HPP
#define MYFULLBINARYTREE_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

template <typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class FullBinaryTree {
private:
    Node<T>* root;  // Корень дерева

    // Вспомогательная функция для вставки элемента
    Node<T>* insert(Node<T>* node, T value) {
        if (node == nullptr) {
            return new Node<T>(value);
        }

        // Вставляем элемент в соответствии с порядком
        if (node->left == nullptr) {
            node->left = new Node<T>(value);
        } else if (node->right == nullptr) {
            node->right = new Node<T>(value);
        } else {
            // Если оба потомка заняты, вставляем в левое поддерево
            insert(node->left, value);
        }

        return node;
    }

    // Вспомогательная функция для поиска элемента
    bool search(Node<T>* node, T value) const {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        }

        // Поиск в левом и правом поддереве
        return search(node->left, value) || search(node->right, value);
    }

    // Вспомогательная функция для удаления элемента
    Node<T>* deleteNode(Node<T>* node, T value) {
        if (node == nullptr) {
            return nullptr;
        }

        // Поиск удаляемого узла
        if (node->data == value) {
            // Если у узла нет потомков
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }

            // Если только один потомок
            if (node->left == nullptr) {
                Node<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node<T>* temp = node->left;
                delete node;
                return temp;
            }

            // Если 2 потомка, находим максимальное значение в левом поддереве
            Node<T>* maxNode = findMax(node->left);
            node->data = maxNode->data;
            node->left = deleteNode(node->left, maxNode->data);
        }
        else {
            node->left = deleteNode(node->left, value);
            node->right = deleteNode(node->right, value);
        }

        return node;
    }

    // Вспомогательная функция для поиска максимального значения
    Node<T>* findMax(Node<T>* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // In-order обход для чтения
    void inOrder(Node<T>* node) const {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Pre-order обход для сохранения в файл
    void savePreOrder(Node<T>* node, std::ofstream& file) const {
        if (node == nullptr) {
            file << "# ";  // Специальный символ для обозначения null
            return;
        }
        file << node->data << " ";  // Сохраняем данные узла
        savePreOrder(node->left, file);   // Сохраняем левое поддерево
        savePreOrder(node->right, file);  // Сохраняем правое поддерево
    }

    // Pre-order обход для загрузки из файла
    Node<T>* loadPreOrder(std::ifstream& file) {
        std::string val;
        if (!(file >> val) || val == "#") {
            return nullptr;  // Если считали '#', возвращаем null
        }
        Node<T>* node = new Node<T>(std::stoi(val));  // Преобразуем строку в число
        node->left = loadPreOrder(file);   // Загружаем левое поддерево
        node->right = loadPreOrder(file);  // Загружаем правое поддерево
        return node;
    }

public:
    // Конструктор
    FullBinaryTree() : root(nullptr) {}

    // Деструктор (рекурсивное удаление всех узлов)
    ~FullBinaryTree() {
        clear(root);
    }

    // Очистка дерева
    void clear(Node<T>* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    // Операция TINSERT — добавление элемента
    void TINSERT(T value) {
        root = insert(root, value);
    }

    // Операция TDEL — удаление элемента
    void TDEL(T value) {
        root = deleteNode(root, value);
    }

    // Операция TGET — поиск элемента
    bool TGET(T value) const {
        return search(root, value);
    }

    // Чтение дерева (in-order traversal)
    void print() const {
        inOrder(root);
        std::cout << std::endl;
    }

    // Сохранение дерева в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for writing");
        }
        savePreOrder(root, file);  // Сохраняем дерево в pre-order обходе
        file.close();
    }

    // Загрузка дерева из файла
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for reading");
        }
        clear(root);  // Очищаем текущее дерево перед загрузкой
        root = loadPreOrder(file);  // Загружаем дерево из файла
        file.close();
    }
};

#endif