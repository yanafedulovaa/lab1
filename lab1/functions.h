#ifndef FUNCTIONS // include guard
#define FUNCTIONS

//void inputStr(List_L1*& tmp, ifstream& fin);

void insertEnd(Node* head, Node* put);
void insertBeg(Node** head, Node* put);
void insertMiddle(Node** head, Node* put, unsigned int index);

void input_txt(Node*& head, unsigned int len);
void input_txt2(Node*& head, unsigned int len);
void outList(Node* head);

void menu(unsigned int choice);


void DeleteMiddle(Node* cur);
void DeleteEnd(Node** head);
void DeleteBeg(Node** head);
void DeleteList(Node** head);
void delete_ind(Node** head, unsigned int index);


int get_elem(Node** head, unsigned int index);

unsigned int get_len(Node* head);
void replace_elem(Node** head, Node* put, unsigned int index);
bool isEmpty(Node** head);
void reverseOrder(Node** head);

void insertListind(Node** head, Node* head2, unsigned int index);
void insertListEnd(Node** head, Node* head2);
void insertListBeg(Node** head, Node* head2);


bool contains(Node** head, Node* head2, unsigned int len1, unsigned int len2);
unsigned int firstContain(Node** head, Node* head2, unsigned int len1, unsigned int len2);
unsigned int lastContain(Node** head, Node* head2, unsigned int len1, unsigned int len2);
void swap_elems(Node* head, unsigned int ind1, unsigned int ind2);

#endif 
#pragma once
