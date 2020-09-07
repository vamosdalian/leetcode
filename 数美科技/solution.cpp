#include "include.h"

using namespace std;

Node* nixu(Node* head){
    Node* p = head;
    Node* q = head;
    Node* result;
    while(p){
        q = p->next;
        p->next = result;
        result = p;
        p = q;
    }
    return result;
}