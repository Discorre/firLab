#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

template <typename T>
class Queue {
private:
    T* data;        // Указатель на динамический массив
    size_t front;   // Индекс первого элемента
    size_t back;    // Индекс следующего элемента для добавления
    size_t capacity; // Вместимость массива
    size_t size;     // Текущий размер очереди

    // Увеличение размера массива
    void resize() {
        capacity = capacity == 0 ? 1 : capacity * 2; // Увеличиваем вдвое
        T* newData = new T[capacity]; // Новый массив
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[(front + i) % capacity]; // Копируем старые данные
        }
        delete[] data; // Удаляем старый массив
        data = newData; // Указатель на новый массив
        front = 0; // Обнуляем индекс первого элемента
        back = size; // Обновляем индекс добавления
    }

public:
    Queue() : data(nullptr), front(0), back(0), capacity(0), size(0) {}

    ~Queue() {
        delete[] data; // Освобождаем память
    }

    void Q_PUSH(const T& value) {
        if (size == capacity) {
            resize(); // Увеличиваем размер при необходимости
        }
        data[back] = value; // Добавляем новый элемент
        back = (back + 1) % capacity; // Обновляем индекс добавления
        ++size; // Увеличиваем размер очереди
    }

    void Q_DEL() {
        if (size == 0) {
            throw std::out_of_range("Queue is empty");
        }
        front = (front + 1) % capacity; // Обновляем индекс первого элемента
        --size; // Уменьшаем размер очереди
    }

    T Q_POP() {
        if (size == 0) {
            throw std::out_of_range("Queue is empty");
        }
        T value = data[front]; // Считываем значение
        Q_DEL(); // Удаляем элемент
        return value; // Возвращаем значение
    }

    size_t getSize() const {
        return size; // Возвращаем текущий размер очереди
    }

    bool isEmpty() const {
        return size == 0; // Проверка на пустоту
    }

    // Метод для печати элементов очереди
    void print() const {
        if (size == 0) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[(front + i) % capacity] << " "; // Печатаем каждый элемент
        }
        std::cout << std::endl;
    }

    // Сохранение очереди в файл
    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for writing");
        }
        for (size_t i = 0; i < size; ++i) {
            file << data[(front + i) % capacity] << "\n"; // Сохраняем каждый элемент
        }
        file.close();
    }

    // Загрузка очереди из файла
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file for reading");
        }
        clear(); // Очищаем текущую очередь перед загрузкой
        T value;
        while (file >> value) {
            Q_PUSH(value); // Добавляем каждый считанный элемент в очередь
        }
        file.close();
    }

    // Очистка очереди
    void clear() {
        delete[] data; // Освобождаем память
        data = nullptr; // Обнуляем указатель
        front = back = capacity = size = 0; // Сбрасываем все параметры
    }
};

#endif