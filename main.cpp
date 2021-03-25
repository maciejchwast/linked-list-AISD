/*
 * Maciej Chwast
 * AISD zad1
 * Napisz program który stworzy liste przechowujaca dane typu long oraz wypelni ją pierwszymi N liczbami Fibonacciego
 * zaczynajac od 1, gdzie N przyjmuje wartosci z zakresu [1, 44], po czym usunie wszytskie elementy o nieparzystej
 * wartosci. Jako wynik program zwraca sume nieusunietych elementow. W przypadku pustej listy lub niepoprawnych danych
 * program zwarca -1.
 */

#include <iostream>
using namespace std;

struct node {
    long data;
    node* next;
};

long fib(int n) {
    if (n < 3)
        return 1;

    return fib(n - 2) + fib(n - 1);
}



void add_node(node*& head, long val) {
    node* new_node = new node;
    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void create_fib_list(node*& head, int N) {
    for (int i = 0; i < N-1; i++) {
        add_node(head, fib(i + 2));
    }
}

void remove_first(node*& head)
{
    node* pom = head;
    head = head->next;
    delete pom;
}

void remove_last(node*& head){
    if(!head) return;
    node* pom = head;
    if(!pom->next){
        remove_first(head);
        return;
    }
    while (pom->next->next)
    {
        pom = pom->next;
    }

    delete pom->next;
    pom->next = NULL;
}

void del_odd(node*& head) {
    if(head->data%2 ==1){
        remove_first(head);
    }
    remove_last(head);
    if(!head) return;
    remove_last(head);
    if(!head) return;
    node* pom = head;
    while(pom->next){
        if((pom->next->data %2) ==1){
            node* pom2 = pom->next;
            pom->next=pom2->next;
            delete pom2;
            continue;
        }
        pom = pom->next;
    }
}

int sum(node*& head) {
    if(!head) return -1;
    int sum = 0;
    node* pom = head;
    while(pom){
        sum += pom->data;
        pom = pom->next;
    }
    if(sum==0)return -1;
    else return sum;
}

void print_list(node* head){
    node* pom = head;
    while(pom){
        cout<<pom->data<<"->";
        pom = pom->next;
    }

}


int main()
{
    node* head = new node;
    head->next = nullptr;
    head->data = fib(0);
    int N = 0;
    cin >> N;
    create_fib_list(head, N);
    //print_list(head);
   // cout<<endl<<endl;
    del_odd(head);
    //print_list(head);
    cout << sum(head);
    //system("pause");
}