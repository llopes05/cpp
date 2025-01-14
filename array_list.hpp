#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
private:
    int* data;
    unsigned int size_, capacity_;
    void increase_capacity() {
    this->capacity_ *= 2;
    int* new_data = new int[this->capacity_];
    for (unsigned int i = 0; i < this->size_; ++i) {
        new_data[i] = this->data[i];
    }
    delete[] this->data;
    this->data = new_data;
}

public:
    array_list() {
        data = new int[8];
        this->size_ = 0;
        this->capacity_ = 8;
    }
    ~array_list() {
        delete[] data;
    }
    unsigned int size() { // Retorna o tamanho da lista
        return this->size_;
    }
    unsigned int capacity() { // Retorna a capacidade da lista
        return this->capacity_;
    }
    double percent_occupied() { // Retorna a porcentagem de ocupação da lista
        return (static_cast<double>(this->size_) / this->capacity_) * 100;
    }
    bool insert_at(unsigned int index, int value) { // Insere o elemento no índice
    if (index > this->size_)
        return false; // Índice inválido
    if (this->size_ == this->capacity_)
        increase_capacity();
    for (unsigned int i = this->size_; i > index; --i) {
        this->data[i] = this->data[i - 1];
    }
    this->data[index] = value;
    this->size_++;
    return true; // Inseriu com sucesso
    }
    bool remove_at(unsigned int index) { // Remove o elemento no índice
        if (index >= this->size_)
            return false; // Não removeu
        for (int i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { // Retorna o valor no índice
        // TODO: Check if index is valid
        return this->data[index];
    }
    void clear() { // Limpa a lista
        this->size_ = 0;
    }
    void push_back(int value) { // Insere um elemento no final da lista
        if (this->size_ == this->capacity_)
            increase_capacity();
        this->data[size_++] = value;
    }
    void push_front(int value) { // Insere um elemento no início da lista
        if (this->size_ == this->capacity_)
            increase_capacity();
        for (int i = this->size_; i > 0; --i) {
            this->data[i] = this->data[i - 1];
        }
        this->data[0] = value;
        this->size_++;
    }
    bool pop_back() { // Remove o último elemento da lista
        if (this->size_ == 0)
            return false;
        this->size_--;
        return true;
    }
    bool pop_front() { // Remove o primeiro elemento da lista
        if (this->size_ == 0)
            return false;
        for (int i = 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true;
    }
    int front() { // Retorna o primeiro elemento da lista
        if (this->size_ == 0)
            throw std::out_of_range("Lista vazia");
        return this->data[0];
    }
    int back() { // Retorna o último elemento da lista
        if (this->size_ == 0)
            throw std::out_of_range("Lista vazia");
        return this->data[this->size_ - 1];
    }
    bool remove(int value) { // Remove a primeira ocorrência do valor na lista
        for (unsigned int i = 0; i < this->size_; ++i) {
            if (this->data[i] == value) {
                return remove_at(i);
            }
        }
        return false;
    }

    int find(int value) {   // Retorna o índice do valor na lista
        for (unsigned int i = 0; i < this->size_; ++i) {
            if (this->data[i] == value) {
                return i;
            }
        }
        return -1; // Not found
    }

    int count(int value) { // Retorna a quantidade de ocorrências do valor na lista
        int count = 0;
        for (unsigned int i = 0; i < this->size_; ++i) {
            if (this->data[i] == value) {
                count++;
            }
        }
        return count;
    }

    int sum() { // Retorna a soma de todos os elementos da lista
        int total = 0;
        for (unsigned int i = 0; i < this->size_; ++i) {
            total += this->data[i];
        }
        return total;
    }
};


#endif // __ARRAY_LIST_IFRN__