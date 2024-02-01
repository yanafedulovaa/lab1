#ifndef TIME_FUNCTIONS // include guard
#define TIME_FUNCTIONS

long long measure_ins_beg(Node** head, Node* put);
long long measure_ins_end(Node* head, Node* put);

long long measure_del_end(Node** head);
long long measure_del_beg(Node** head);

long long measure_ins_mid(Node** head, Node* put, unsigned int index);
long long measure_get_ind(Node** head, unsigned int index);
long long measure_del_ind(Node** head, unsigned int index);

long long measure_get_len(Node* head);
long long measure_del_list(Node** head);
long long measure_replace(Node** head, Node* put, unsigned int index);
long long measure_empty(Node** head);
long long measure_reverse(Node** head);


long long measure_list_ind(Node** head, Node* head2, unsigned int index);
long long measure_list_end(Node** head, Node* head2);
long long measure_list_beg(Node** head, Node* head2);

long long measure_contains(Node** head, Node* head2, unsigned int len1, unsigned int len2);
long long measure_first_contain(Node** head, Node* head2, unsigned int len1, unsigned int len2);
long long measure_last_contain(Node** head, Node* head2, unsigned int len1, unsigned int len2);

long long measure_swap(Node* head, unsigned int index1, unsigned int index2);

#endif #pragma once
