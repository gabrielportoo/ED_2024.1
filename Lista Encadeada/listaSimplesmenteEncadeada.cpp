#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;

// Node: classe utilizada para representar um No
// Nao altere essa classe
struct Node {
    int info; // Informacao salva pelo usuario na lista
    Node *next; // Ponteiro para o proximo elemento da lista

    struct Node(); // Construtor
    Node(int info, Node *next=NULL); // Construtor
    ~Node(); // Destrutor
};

// Singly Linked List ou
// Lista Simplesmente Encadeada
// Altere somente os campos marcados com TODO
struct SLinkedList {
    Node *head;   // Ponteiro para a cabeca da lista (primeiro No)

    SLinkedList(){
        // TODO
        // Atribua NULL no valor do head
        head = NULL;
    }

    ~SLinkedList(){ // Destrutor
        // TODO
        // dica: implemente o metodo clear e apenas o chame
        clear();
    }

    // Retorna true se uma informacao pertence a lista, false caso contrario
    // index: posicao do elemento
    bool hasInfo(int info){
        // TODO: Complexidade O(n)
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
    // L == 10 -> 20 -> 15 -> 50
    // L.hasInfo(20) == true
    // L.hasInfo(100) == false


    // Retorna a informacao dada uma posicao
    // index: posicao do elemento
    int get(int index){
        // TODO: Complexidade O(n)
        Node* temp = head;

        int count = 0;

        while(temp != NULL){
            if(count == index){
                return temp->info;
            }
            count++;
            temp = temp->next;
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.get(0) == 10
    // L.get(1) == 20
    // L.get(2) == 15


    // operador[] sobrecarregado. Retorna a 
    // informacao do elemento na posicao 'index'
    int operator[](int index){
        return get(index);
    }


    // Adiciona um elemento no inicio da lista
    // info: informacao do elemento a ser inserido
    void push_front(int info){
        Node* newNode = new Node(info, NULL);
        newNode->next = head;
        head = newNode;
        // Ou simplesmente
        // head = new Node(info, head);
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 30 -> 10 -> 20 -> 15 -> 50


    // Adiciona um elemento ao final da lista
    // info: informacao do elemento a ser inserido
    void push_back(int info){
        // TODO: Complexidade O(n)
        Node* newNode = new Node(info);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.push_front(30)
    // L == 10 -> 20 -> 15 -> 50 -> 30


    // Remove o primeiro elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_front(){
        // TODO: Complexidade O(1)
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_front()
    // L == 20 -> 15 -> 50


    // Remove o ultimo elemento da lista.
    // Nao faz nada se a lista esta vazia
    void pop_back(){
        // TODO: Complexidade O(n)
        if(empty()){
        } else if(head->next == NULL){
            Node* temp = head;
            head = NULL;
            delete temp;
        } else {
            Node* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.pop_back()
    // L == 10 -> 20 -> 15


    // Deixa a lista vazia, com zero elementos
    void clear(){
        // TODO: Complexidade O(n)
        // dica: voce pode usar os metodos pop_front e empty
        Node* temp = head;
        while(temp != NULL){
            pop_front();
        }
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.clear()
    // L == []


    // Retorna o numero de elementos da lista
    int length(){
        // TODO: Complexidade O(n)

        int n = 0;
        Node* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        return n;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.length() == 4


    // Devolve true se cheia e false caso contrario
    bool empty(){
        // TODO
        return head == NULL;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.empty() == false
    // L == ''
    // L.empty() == true


    // Dado um no, retorna o proximo no da lista
    // Retorna NULL caso nao exista
    Node* successor(Node* node){
        return node->next;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.successor(No 20) == No 15
    // L.successor(No 50) == NULL


    // Dado um No, retorna o anterior No da lista
    // Retorna NULL caso nao exista
    Node* predecessor(Node* node){
        // TODO: complexidade O(n)

        if (node == head) {
            return NULL;
        }

        Node* temp = head;
        while (temp != NULL && temp->next != node) {
            temp = temp->next;
        }

        return temp;
    }
    // Exemplo:
    // L == 10 -> 20 -> 15 -> 50
    // L.predecessor([20]) == [10]
    // L.predecessor([10]) == NULL

    // Printa as informacoes da lista
    void print(){
        std::cout << "[";
        for(Node* node = head; node != NULL; node = node->next){
            std::cout << node->info;
            if(node->next != NULL)
                std::cout << " -> ";
        }
        std::cout << "]" << std::endl;
    }    
};

