#include <iostream>

// Node: classe utilizada para representar um No
// NAO ALTERE ESSA CLASSE
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista
    Node *previous; // Ponteiro para o elemento anterior da lista

    // Construtor
    Node(int info, Node *next=NULL, Node *previous=NULL);
    ~Node(); // Destrutor
};

// Double Linked List ou
// Lista Duplamente Encadeada
// Altere somente os campos marcados com TODO
struct DLinkedList {
    Node *head;   // Ponteiro para o No cabeca da lista (primeiro No)
    Node *tail;  //  Ponteiro para o No cauda da lista (ultimo No)

    DLinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }

    ~DLinkedList(){ // Destrutor
        clear();
    }

    // Retorna true se uma informacao pertence a lista
    // index: posicao do elemento
    bool hasInfo(int info){
        Node* temp = head;

        while(temp != NULL){
            if(temp->info == info){
                return true;
            }
            temp = temp->next;
        }

        return false;
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.hasInfo(20) == true
    // L.hasInfo(100) == false

    // Adiciona um elemento no inicio da lista
    // info: informacao do elemento a ser inserido
    void push_front(int info){
        // Complexidade: O(1)
        if(head == NULL){ // lista vazia
            // havera somente um No, ambos 'head' e 'tail'
            // apontam para o primeiro No
            head = tail = new Node(info);
        }else{ // lista com pelo menos 1 No
            Node* newNode = new Node(info, head, NULL);
            head->previous = newNode;
            head = newNode;
        }
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.push_front(30)
    // L == 30 <-> 10 <-> 20 <-> 15 <-> 50


    // Adiciona um elemento ao final da lista
    // info: informacao do elemento a ser inserido
    void push_back(int info){
        // Complexidade O(1)
        // dica: utilize o 'tail' para realizar
        //       a operacao em O(1)
        if(tail == NULL) { // lista vazia
            head = tail = new Node(info);
        } else {
            Node* newNode = new Node(info, NULL, tail);
            tail->next = newNode;
            tail = newNode;
        }
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.push_back(30)
    // L == 10 <-> 20 <-> 15 <-> 50 <-> 30


    // Remove o primeiro elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_front(){
        // Complexidade O(1)
        // dica: separe em 3 casos: lista vazia, somente 1 No, mais de 1 No
        if(head == NULL){
            return;
        }
        if(head == tail){
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            head->previous = NULL;
            delete temp;
        }
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.pop_front()
    // L == 20 <-> 15 <-> 50


    // Remove o ultimo elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_back(){
        // Complexidade O(1)
        if (tail == NULL) return;

        if (head == tail) { // Apenas um elemento na lista
            delete tail;
            head = tail = NULL;
        } else {
            Node* temp = tail;
            tail = tail->previous;
            tail->next = NULL;
            delete temp;
        }
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.pop_back()
    // L == 10 <-> 20 <-> 15

    // Remove a ocorrencia do primeiro No com
    // uma informacao especifica.
    // Nao faz nada se nao existe No.
    // info: informacao do No a ser removido.
    void remove_one(int info){
        // Complexidade O(n)
        Node* current = head;
        while (current != NULL) {
            if (current->info == info) {
                if (current == head) {
                    pop_front();
                } else if (current == tail) {
                    pop_back();
                } else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    delete current;
                }
                return;
            }
            current = current->next;
        }
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.removeOne(20)
    // L == 10 <-> 15 <-> 50

    // Exemplo 2:
    // L == 2 <-> 10 <-> 4 <-> 6 <-> 4 <-> 4
    // L.removeOne(4)
    // L == 2 <-> 10 <-> 6 <-> 4 <-> 4
    // L.removeOne(4)
    // L == 2 <-> 10 <-> 6 <-> 4
    // L.removeOne(4)
    // L == 2 <-> 10 <-> 6
    // L.removeOne(4)
    // L == 2 <-> 10 <-> 6


    // Deixa a lista vazia, removendo todos os Nos
    void clear(){
        while(!empty()){
            pop_front();
        }
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.clear()
    // L == []


    // Retorna o numero de elementos da lista
    int length(){
        int count = 0;
        for(Node *temp = head; temp != NULL; temp = temp->next)
            count++;

        return count;
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.length() == 4


    // Devolve true se vazia e false caso contrario
    bool empty(){
        return head == NULL;
    }
    // Exemplo:
    // L == 10 <-> 20 <-> 15 <-> 50
    // L.empty() == false
    // L == ''
    // L.empty() == true

    // Printa as informacoes da lista
    void print(){
        std::cout << "Lista: [";
        for(Node* node = head; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << ((node->next->previous == node) ? " <-> " : " -> ");
        }
        std::cout << "]" << std::endl;
    }    
};