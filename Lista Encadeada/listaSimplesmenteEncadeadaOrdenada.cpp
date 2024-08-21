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

    Node(); // Construtor
    Node(int info, Node *next=NULL); // Construtor
    ~Node(); // Destrutor
};

// Singly Linked List ou
// Lista Simplesmente Encadeada
// Altere somente os campos marcados com TODO
struct OrderedSLinkedList {
    Node *head; // Ponteiro para a cabeca da lista (primeiro No)

    OrderedSLinkedList(){
        this->head = NULL;
    }

    // Para esse exercicio, nao precisa implementar o destrutor
    // ~OrderedSLinkedList();

    // Adiciona um elemento na lista, mantendo a ordenação das informacoes da lista
    // info: informacao do elemento a ser inserido
    void push(int info){
        // TODO: Complexidade O(n)
        Node* newNode = new Node(info);

        // Se a lista estiver vazia ou o novo nó deve ser o primeiro
        if (head == NULL || head->info >= info) {
            newNode->next = head;
            head = newNode;
        } else {
            // Percorrer a lista para encontrar a posição correta para inserir
            Node* temp = head;
                while (temp->next != NULL && temp->next->info < info) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
        }
    }
    // Exemplo:
    // L == []
    // L.push(4)
    // L == 4
    // L.push(10)
    // L == 4 -> 10
    // L.push(18)
    // L == 4 -> 10 -> 18
    // L.push(1)
    // L == 1 -> 4 -> 10 -> 18
    // L.push(4)
    // L == 1 -> 4 -> 4 -> 10 -> 18

    // Retorna a menor informacao da lista
    // Pode assumir que a lista possui pelo menos 1 elemento
    int min(){
        // TODO
        return head->info;
    }
    // Exemplo:
    // L == 1 -> 4 -> 4 -> 10 -> 18
    // L.min() == 1


    // Retorna a maior informacao da lista
    // Pode assumir que a lista possui pelo menos 1 elemento
    int max(){
        // TODO
        Node* temp = head;
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->info;
    }
    // Exemplo:
    // L == 1 -> 4 -> 4 -> 10 -> 18
    // L.max() == 18

    // Remove todos elementos com informacao duplicada da lista.
    // Sobrando apenas os nos com informacoes únicas.
    void remove_duplicated(){
        // TODO: Complexidade O(n)
        // dica: aproveite que os elementos estao ordenados
        if (head == NULL) return;

        Node* temp = head;

        while (temp->next != NULL) {
            if (temp->info == temp->next->info) {
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
    }
    // Exemplo:
    // L == 1 -> 1 -> 1 -> 1 -> 2 -> 2 -> 2 -> 4 -> 4 -> 8
    // L.remove_duplicated()
    // L == 1 -> 2 -> 4 -> 8
    // L.remove_duplicated()
    // L == 1 -> 2 -> 4 -> 8

    bool empty(){
        return head == NULL;
    }

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

