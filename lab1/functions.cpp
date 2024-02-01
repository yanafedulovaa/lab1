#include <fstream>
#include <iostream>
#include "node.h"
#include "functions.h"

using namespace std;

bool contains(Node** head, Node* head2, unsigned int len1, unsigned int len2)
{
    Node* cur1 = new Node;
    cur1 = *head;
    Node* cur2 = new Node;
    cur2 = head2;

    if (cur1 == NULL && cur2 == NULL)
        return true;

    if (len1 < len2)
        return false;

    while (cur1 != NULL)
    {

        while (cur1->num == cur2->num)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
            if (cur2 == NULL)
                return true;
        }
        if (cur2 == NULL)
        {
            return true;
        }
        else
        {
            cur2 = head2;
        }
        cur1 = cur1->next;
    }
    return false;

}

unsigned int firstContain(Node** head, Node* head2, unsigned int len1, unsigned int len2)
{
    Node* cur1 = new Node;
    cur1 = *head;
    Node* cur2 = new Node;
    cur2 = head2;
    unsigned int i = 0;

    while (cur1 != NULL)
    {
        while (cur1->num == cur2->num)
        {
            cur1 = cur1->next;
            i++;
            cur2 = cur2->next;
            if (cur2 == NULL)
                return i - len2 + 1;
        }
        if (cur2 == NULL)
        {
            return i - len2 + 1;
        }
        else
        {
            cur2 = head2;
        }
        cur1 = cur1->next;
        i++;
    }
    return i;
}

unsigned int lastContain(Node** head, Node* head2, unsigned int len1, unsigned int len2)
{
    Node* cur1 = *head;
    Node* cur2 = head2;
    unsigned int i = 1, counter = 0;

    while (cur1 != NULL)
    {
        if (cur1->num == cur2->num)
        {


            cur2 = cur2->next;
            if (cur2 == NULL)
            {
                cur2 = head2;
                counter = i - len2 + 1;
            }
            cur1 = cur1->next;
            i++;
        }
        else
        {
            if (cur2 == head2)
            {
                cur1 = cur1->next;
                i++;
            }
            else
            {
                cur2 = head2;
            }
        }

    }
    return counter;
}

void DeleteMiddle(Node* cur) // Удаление элемента после cur
{
    Node* tmp = cur->next;
    if (tmp != NULL)
    {
        cur->next = tmp->next;
        if (tmp->next != NULL) {
            tmp->next->prev = cur;
        }
        delete tmp;
    }
}

void delete_ind(Node** head, unsigned int index)
{
    if (index == 1)
    {
        DeleteBeg(head);
    }
    else
    {
        Node* cur = *head;
        unsigned int i = 1;
        while (i < index - 1 && cur != NULL)
        {
            cur = cur->next;
            i++;
        }
        if (cur != NULL && cur->next != NULL)
        {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            if (tmp->next != NULL) {
                tmp->next->prev = cur;
            }
            delete tmp;
        }
    }
}


void DeleteEnd(Node** head)
{
    if (*head == NULL) return;

    Node* tmp = *head;
    if (tmp->next == NULL) // Если в списке только один элемент
    {
        delete tmp;
        *head = NULL;
    }
    else
    {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->prev->next = NULL;
        delete tmp;
    }
}

/////////
void DeleteBeg(Node** head) {
    if (*head == NULL) return;

    Node* tmp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    delete tmp;
}

void DeleteList(Node** head) //удаление всего списка
{
    Node* cur;
    while (*head != NULL)
    {
        cur = (*head)->next;
        delete* head;
        *head = cur;
    }
}

bool isEmpty(Node** head)
{
    if (*head == NULL) return true;
    else return false;
}

int get_elem(Node** head, unsigned int index)
{
    Node* cur = *head;
    unsigned int i = 0;
    while (i < index - 1 && cur != NULL)
    {
        i++;
        cur = cur->next; // переход на нужный элемент
    }
    if (cur != NULL) {
        return cur->num;
    }
    else {
        // Обработка ситуации, когда индекс выходит за пределы списка
        return -1; // Или другое значение, сигнализирующее об ошибке
    }
}


unsigned int get_len(Node* head)
{

    Node* cur;
    cur = head;
    unsigned int i = 0;
    while (cur != NULL)
    {
        i++;
        cur = cur->next;
    }
    //cFinish = clock();
    //cout << "\nВремя выполнения метода: " << cFinish - cStart << endl;
    return i;
}



void input_txt(Node*& head, unsigned int len)
{


    unsigned short num_of_list = 0;

    while (num_of_list < len) {
        Node* tmp = new Node;
        cout << "Введите элемент списка номер " << num_of_list + 1 << ": ";
        cin >> tmp->num;
        num_of_list++;
        if (num_of_list != 1)
        {
            insertEnd(head, tmp);
        }
        else
        {
            insertBeg(&head, tmp);
        }
    }
    if (num_of_list == 1)
    {
        head->next = NULL;
    }
}

void input_txt2(Node*& head, unsigned int len)
{


    unsigned int num_of_list = 0;

    while (num_of_list < len) {
        Node* tmp = new Node;
        tmp->num = rand() % 100;
        num_of_list++;


        if (num_of_list != 1)
        {
            insertEnd(head, tmp);
        }
        else
        {
            insertBeg(&head, tmp);
        }

    }
    if (num_of_list == 1)
    {
        head->next = NULL;
    }
}



void insertEnd(Node* head, Node* put) {
    Node* tmp = new Node;
    if (tmp != NULL) {
        tmp->num = put->num;
        tmp->next = NULL;
        // Проверяем, является ли список пустым
        if (head == NULL) {
            head = tmp;
            tmp->prev = NULL;
        }
        else {
            Node* cur = head;
            // Переходим к последнему элементу
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = tmp;
            tmp->prev = cur; // Устанавливаем указатель на предыдущий элемент
        }
    }
}


//////
void insertBeg(Node** head, Node* put) {
    Node* tmp = new Node;
    if (tmp != NULL) {
        tmp->num = put->num;
        tmp->next = *head;
        tmp->prev = NULL;

        if (*head != NULL) {
            (*head)->prev = tmp;
        }

        *head = tmp;
    }
}

void insertMiddle(Node** head, Node* put, unsigned int index) {
    if (*head == NULL || index == 1) {
        insertBeg(head, put);
        return;
    }

    Node* cur = *head;
    for (unsigned int i = 1; i < index - 1 && cur->next != NULL; i++) {
        cur = cur->next;
    }

    Node* tmp = new Node;
    tmp->num = put->num;
    tmp->next = cur->next;
    tmp->prev = cur;
    if (cur->next != NULL) {
        cur->next->prev = tmp;
    }
    cur->next = tmp;
}


void outList(Node* head)
{
    Node* cur;
    cur = head;
    while (cur != NULL)
    {
        cout << cur->num;
        cout << " -> ";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}

void replace_elem(Node** head, Node* put, unsigned int index) {
    if (*head == NULL) return;

    Node* cur = *head;
    for (unsigned int i = 1; i < index && cur != NULL; i++) {
        cur = cur->next;
    }

    if (cur != NULL) {
        cur->num = put->num;
    }
}



void reverseOrder(Node** head) {
    Node* cur = *head, * tmp = NULL;
    while (cur != NULL) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }

    if (tmp != NULL) {
        *head = tmp->prev;
    }
}


void insertListind(Node** head, Node* head2, unsigned int index) {
    if (head2 == NULL) return;

    if (*head == NULL || index == 1) {
        insertListBeg(head, head2);
        return;
    }

    Node* cur = *head;
    for (unsigned int i = 1; i < index - 1 && cur->next != NULL; i++) {
        cur = cur->next;
    }

    Node* tmp = cur->next;
    cur->next = head2;
    head2->prev = cur;

    if (tmp != NULL) {
        tmp->prev = head2;
        while (head2->next != NULL) {
            head2 = head2->next;
        }
        head2->next = tmp;
    }
}


void insertListEnd(Node** head, Node* head2) {
    if (*head == NULL) {
        *head = head2;
        return;
    }

    Node* cur = *head;
    // Находим последний узел первого списка
    while (cur->next != NULL) {
        cur = cur->next;
    }

    // Прикрепляем второй список к концу первого
    cur->next = head2;

    // Обновляем указатели prev для всех узлов второго списка
    if (head2 != NULL) {
        head2->prev = cur;
        while (head2->next != NULL) {
            head2 = head2->next;
            head2->prev = cur;
            cur = head2;
        }
    }
}


void insertListBeg(Node** head, Node* head2) {
    if (head2 == NULL) return;

    Node* cur = head2;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = *head;
    if (*head != NULL) {
        (*head)->prev = cur;
    }
    *head = head2;
}


void swap_elems(Node* head, unsigned int ind1, unsigned int ind2) {
    if (head == NULL || ind1 == ind2) return;

    Node* node1 = NULL, * node2 = NULL;
    unsigned int current_index = 1;

    // Проходим по списку один раз, находим оба узла
    for (Node* cur = head; cur != NULL; cur = cur->next) {
        if (current_index == ind1) {
            node1 = cur;
        }
        if (current_index == ind2) {
            node2 = cur;
        }
        current_index++;
    }

    // Если оба узла найдены, меняем их значения
    if (node1 != NULL && node2 != NULL) {
        int temp = node1->num;
        node1->num = node2->num;
        node2->num = temp;
    }
}


