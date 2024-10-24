# Имя исполняемого файла(для Windows)
#TARGET = a.exe

# Имя исполняемого файла(для Linux)
TARGET = a.out

# Список исходных файлов .cpp
SRCS = mainMenu.cpp

# Список заголовочных файлов .h и .hpp
#HDRS = myListKV.hpp myVector.hpp mySinglyLinkedList.hpp myArray.hpp myDoublyLinkedList.hpp myQueue.hpp myStack.hpp 

# Список объектных файлов .o, которые будут созданы
OBJS = $(SRCS:.cpp=.o)

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++17

# Компилятор
CXX = g++

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Правило для компиляции каждого .cpp файла в .o файл
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки объектных файлов и исполняемого файла
clean:
	rm -f $(OBJS) $(TARGET)

# Правило для перекомпиляции всего проекта
rebuild: clean $(TARGET)

# Правило по умолчанию
.PHONY: all clean rebuild