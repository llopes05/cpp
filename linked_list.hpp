#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() { // O(1)
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    ~linked_list() { // O(n)
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() const { // O(1)
        return this->size_;
    }
    unsigned int capacitty() { // O(1)
        return size_; 
    }
    double percent_occupied() { // O(1)
        if (this->size_ == 0)
            return 0.0;
        return (static_cast<double>(this->size_) / this->capacitty()) * 100.0;
    }
    bool insert_at(unsigned int index, int value) { // O(n)
        if (index > this->size_)
            return false; // Índice fora do intervalo

        int_node* new_node = new int_node;
        new_node->value = value;

        if (index == 0) {
            new_node->next = this->head;
            new_node->prev = nullptr;
            if (this->head != nullptr)
                this->head->prev = new_node;
            this->head = new_node;
            if (this->tail == nullptr)
                this->tail = new_node;
        } else if (index == this->size_) {
            new_node->next = nullptr;
            new_node->prev = this->tail;
            if (this->tail != nullptr)
                this->tail->next = new_node;
            this->tail = new_node;
        } else {
            int_node* current = this->head;
            for (unsigned int i = 0; i < index; ++i)
                current = current->next;
            new_node->next = current;
            new_node->prev = current->prev;
            if (current->prev != nullptr)
                current->prev->next = new_node;
            current->prev = new_node;
        }

        this->size_++;
        return true; // Inseriu
    }
    bool remove_at(unsigned int index) { // O(n)
        if (index >= this->size_)
            return false; // Não removeu

        // Encontrar o nó a ser removido
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;

        // Atualizar os ponteiros de anterior e próximo, se existirem
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        else
            this->head = to_remove->next; // Se for o primeiro nó, atualizar o head

        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        else
            this->tail = to_remove->prev; // Se for o último nó, atualizar o tail

        delete to_remove; // Remover o nó
        this->size_--; // Decrementar o tamanho da lista
        return true; // Remoção bem-sucedida
    }
    int get_at(unsigned int index) { // O(n)
        if (index >= this->size_)
            throw std::out_of_range("Índice fora do intervalo");
        int_node* current = this->head;
        for (unsigned int i = 0; i < index; ++i)
            current = current->next;
        return current->value;
    }
    void clear() { // O(n)
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    void push_back(int value) { // O(1)
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;
        if (this->tail != nullptr)
            this->tail->next = new_node;
        this->tail = new_node;
        if (this->head == nullptr)
            this->head = new_node;
        this->size_++;
    }
    void push_front(int value) { // O(1)
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
        this->size_++; // Incrementa o tamanho da lista
    }

    bool pop_back() { // O(1)
        if (this->tail == nullptr)
            return false; // Lista vazia, não removeu
        int_node* to_remove = this->tail;
        this->tail = this->tail->prev;
        if (this->tail != nullptr)
            this->tail->next = nullptr;
        else
            this->head = nullptr; // Lista ficou vazia
        delete to_remove;
        this->size_--;
        return true; // Removeu
    }
    bool pop_front() { // O(1)
        if (this->head == nullptr)
            return false; // Lista vazia, não removeu
        int_node* to_remove = this->head;
        this->head = this->head->next;
        if (this->head != nullptr)
            this->head->prev = nullptr;
        else
            this->tail = nullptr; // Lista ficou vazia
        delete to_remove;
        this->size_--;
        return true; // Removeu
    }
    int front() { // O(1)
        if (this->head == nullptr)
            throw std::out_of_range("Lista vazia");
        return this->head->value;
    }
    int back() { // O(1)
        if (this->tail == nullptr)
            throw std::out_of_range("Lista vazia");
        return this->tail->value;
    }
    bool remove(int value) { // O(n)
        int_node* current = this->head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                if (current->next != nullptr)
                    current->next->prev = current->prev;
                if (current == this->head)
                    this->head = current->next;
                if (current == this->tail)
                    this->tail = current->prev;
                delete current;
                this->size_--;
                return true; // Removeu
            }
            current = current->next;
        }
        return false; // Não encontrou o valor
    }
    int find(int value) { // O(n)
        int_node* current = this->head;
        unsigned int index = 0;
        while (current != nullptr) {
            if (current->value == value)
                return index;
            current = current->next;
            index++;
        }
        return -1; // Não encontrou o valor
    }
    int count(int value) { // O(n)
        int_node* current = this->head;
        int count = 0;
        while (current != nullptr) {
            if (current->value == value)
                count++;
            current = current->next;
        }
        return (count > 0) ? count : -1;
    }
    int sum() { // O(n)
        int_node* current = this->head;
        int sum = 0;
        while (current != nullptr) {
            sum += current->value;
            current = current->next;
        }
        return sum;
    }
};

#endif // __LINKED_LIST_IFRN__