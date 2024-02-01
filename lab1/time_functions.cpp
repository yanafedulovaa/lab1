#include <iostream>
#include <chrono>
#include "node.h"
#include "time_functions.h"
#include "functions.h"

using namespace std;

long long measure_ins_beg(Node** head, Node* put)
{
    auto start = chrono::high_resolution_clock::now();

    insertBeg(head, put);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();

}



long long measure_ins_end(Node* head, Node* put)
{
    auto start = chrono::high_resolution_clock::now();

    insertEnd(head, put);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();

}

long long measure_del_end(Node** head)
{
    auto start = chrono::high_resolution_clock::now();

    DeleteEnd(head);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_del_beg(Node** head)
{
    auto start = chrono::high_resolution_clock::now();

    DeleteBeg(head);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_ins_mid(Node** head, Node* put, unsigned int index)
{
    auto start = chrono::high_resolution_clock::now();

    insertMiddle(head, put, index / 2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_get_ind(Node** head, unsigned int index)
{
    auto start = chrono::high_resolution_clock::now();

    get_elem(head, index / 2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_del_ind(Node** head, unsigned int index)
{
    auto start = chrono::high_resolution_clock::now();

    delete_ind(head, index / 2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_get_len(Node* head)
{
    auto start = chrono::high_resolution_clock::now();

    get_len(head);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_del_list(Node** head)
{
    auto start = chrono::high_resolution_clock::now();

    DeleteList(head);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_replace(Node** head, Node* put, unsigned int index)
{
    auto start = chrono::high_resolution_clock::now();

    replace_elem(head, put, index / 2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_empty(Node** head)
{
    auto start = chrono::high_resolution_clock::now();

    isEmpty(head);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_reverse(Node** head)
{
    auto start = chrono::high_resolution_clock::now();

    reverseOrder(head);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}

long long measure_list_ind(Node** head, Node* head2, unsigned int index)
{
    auto start = chrono::high_resolution_clock::now();

    insertListind(head, head2, index / 2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_list_end(Node** head, Node* head2)
{
    auto start = chrono::high_resolution_clock::now();

    insertListEnd(head, head2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_list_beg(Node** head, Node* head2)
{
    auto start = chrono::high_resolution_clock::now();

    insertListBeg(head, head2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_contains(Node** head, Node* head2, unsigned int len1, unsigned int len2)
{
    auto start = chrono::high_resolution_clock::now();

    contains(head, head2, len1, len2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_first_contain(Node** head, Node* head2, unsigned int len1, unsigned int len2)
{
    auto start = chrono::high_resolution_clock::now();

    firstContain(head, head2, len1, len2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_last_contain(Node** head, Node* head2, unsigned int len1, unsigned int len2)
{
    auto start = chrono::high_resolution_clock::now();

    lastContain(head, head2, len1, len2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}


long long measure_swap(Node* head, unsigned int index1, unsigned int index2)
{
    auto start = chrono::high_resolution_clock::now();

    swap_elems(head, index1, index2);

    auto end = chrono::high_resolution_clock::now();

    return  chrono::duration_cast<::chrono::nanoseconds>(end - start).count();
}