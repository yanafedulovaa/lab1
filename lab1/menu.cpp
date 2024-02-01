#include <iostream>
#include <chrono>
#include "node.h"
#include "functions.h"
#include "time_functions.h"

using namespace std;

void menu(unsigned int choice) {
    switch (choice) {
    case(1):
    {
        unsigned int cmd;
        unsigned short quan;
        cout << "Введите количество элементов вашего будущего списка:\n";
        cin >> quan;
        Node* head = new Node; // создаем список
        head = NULL; // список пустой
        input_txt(head, quan);
        cout << "Исходный список:\n";
        outList(head);
        while (1) {
            cout << "______________________________________________________________________________________\n";
            cout << "Меню:\n\n";
            cout << "0. Выйти из программы\n";
            cout << "1. Добавить элемент в конец списка\n";
            cout << "2. Добавить элемент в начало списка\n ";
            cout << "3. Удалить последний элемент списка\n ";
            cout << "4. Удалить первый элемент списка\n";
            cout << "5. Добавить элемент по индексу\n ";
            cout << "6. Получить элемент по индексу\n ";
            cout << "7. Удалить элемент по индексу\n";
            cout << "8. Получить размер списка\n ";
            cout << "9. Удалить все элементы\n ";
            cout << "10. Заменить элемент по индексу на передаваемый элемент\n";
            cout << "11. Проверить пуст ли список\n ";
            cout << "12. Изменить порядок элементов в списке на обратный\n ";
            cout << "13. Вставить другой список в список, начиная с индекса\n";
            cout << "14. Вставить другой список в конец\n ";
            cout << "15. Вставить другой список в начало\n ";
            cout << "16. Проверить содержится ли другой список в списке\n";
            cout << "17. Найти первое вхождение другого списка в список\n ";
            cout << "18. Найти последнее вхождение списка в список\n ";
            cout << "19. Поменять  два элемента списка по индексам\n";
            cout << "______________________________________________________________________________________\n";
            cin >> cmd;

            switch (cmd) {
            case 0:
                return;

            case 1:
            {
                Node* tmp = new Node;
                cout << "Введите элемент, который вы хотите добавить:";
                cin >> tmp->num;
                insertEnd(head, tmp);
                outList(head);
            }
            break;
            case 2:
            {
                Node* tmp = new Node;
                cout << "Введите элемент, который вы хотите добавить:";
                cin >> tmp->num;
                insertBeg(&head, tmp);
                cout << "Полученный список:";
                outList(head);
            }
            break;
            case 3:
                DeleteEnd(&head);
                cout << "Полученный список:";
                outList(head);
                break;
            case 4:
                DeleteBeg(&head);
                cout << "Полученный список:";
                outList(head);
                break;
            case 5:
            {
                Node* tmp = new Node;
                unsigned int el;
                cout << "Введите индекс элемента, перед котором нужно добавить элемент ";
                cin >> el;
                cout << "Введите элемент, который вы хотите добавить: ";
                cin >> tmp->num;
                insertMiddle(&head, tmp, el);
                cout << "Полученный список:";
                outList(head);
            }

            break;
            case 6:
            {
                unsigned int el;
                cout << "Введите индекс элемента, который хотите получить ";
                cin >> el;
                cout << "Элемент с индексом " << el << ": " << get_elem(&head, el) << endl;

            }
            break;
            case 7:
            {
                unsigned int el;
                cout << "Введите индекс элемента, который хотите удалить ";
                cin >> el;
                delete_ind(&head, el);
                cout << "Полученный список:";
                outList(head);
            }
            break;
            case 8:
                cout << "Длина списка равна " << get_len(head) << endl;

                break;
            case 9:
                DeleteList(&head);
                cout << "Все элементы списка были удалены.\nПолученный список:";
                outList(head);
                break;
            case 10:
            {
                Node* tmp = new Node;
                unsigned int el;
                cout << "Введите индекс элемента, который вы хотите заменить ";
                cin >> el;
                cout << "Введите элемент, на который нужно заменить элемент с индексом " << el << " :";
                cin >> tmp->num;
                replace_elem(&head, tmp, el);
                cout << "Полученный список:";
                outList(head);
            }
            break;
            case 11:
                if (isEmpty(&head)) {
                    cout << "\nСписок пуст\n";
                }
                else {
                    cout << "\nСписок не пуст\n";
                }
                break;
            case 12:
                reverseOrder(&head);
                cout << "Полученный список:";
                outList(head);
                break;
            case 13:
            {
                Node* head2 = new Node; // создаем список
                head2 = NULL;
                unsigned int quan, index;
                cout << "Давайте создадим список для вставки!\nВведите количество элементов вашего будущего списка:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "Введите индекс, с которого нужно начинать вставку\n";
                cin >> index;
                insertListind(&head, head2, index);
                cout << "Полученный список:";
                outList(head);
            }
            break;
            case 14:
            {
                Node* head2 = new Node; // создаем список
                head2 = NULL;
                unsigned int quan;
                cout << "Давайте создадим список для вставки!\nВведите количество элементов вашего будущего списка:\n";
                cin >> quan;
                input_txt(head2, quan);
                insertListEnd(&head, head2);
                cout << "Полученный список:";
                outList(head);
            }
            break;
            case 15:
            {
                Node* head2 = new Node; // создаем список
                head2 = NULL;
                unsigned int quan;
                cout << "Давайте создадим список для вставки!\nВведите количество элементов вашего будущего списка:\n";
                cin >> quan;
                input_txt(head2, quan);
                insertListBeg(&head, head2);
                cout << "Полученный список:";
                outList(head);
            }
            break;
            case 16:
            {
                Node* head2 = new Node; // создаем список
                head2 = NULL;
                unsigned int quan, len1;
                cout << "Давайте создадим список, чтобы проверить входит ли он в исходный!\nВведите количество элементов вашего будущего списка:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "Полученный список:";
                outList(head2);
                len1 = get_len(head);
                if (contains(&head, head2, len1, quan))
                {
                    cout << "Список содержится в исходном\n";
                }
                else
                {
                    cout << "Список не содержится в исходном\n";
                }
                DeleteList(&head2);
            }
            break;
            case 17:
            {
                Node* head2 = new Node; // создаем список
                head2 = NULL;
                unsigned int quan, len1;
                cout << "Давайте создадим список, чтобы найти индекс его первого вхождения в исходный!\nВведите количество элементов вашего будущего списка:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "Полученный список:";
                outList(head2);
                len1 = get_len(head);
                if (!contains(&head, head2, len1, quan))
                {
                    cout << "Список не содержится в исходном\n";
                }
                else
                {
                    cout << "Список содержится в исходном\n" << "Первое вхождение начинается с индекса " << firstContain(&head, head2, len1, quan) << endl;
                }
                DeleteList(&head2);
            }
            break;
            case 18:
            {
                Node* head2 = new Node; // создаем список
                head2 = NULL;
                unsigned int quan, len1;
                cout << "Давайте создадим список, чтобы найти индекс его последнего вхождения в исходный!\nВведите количество элементов вашего будущего списка:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "Полученный список:";
                outList(head2);
                len1 = get_len(head);
                if (!contains(&head, head2, len1, quan))
                {
                    cout << "Список не содержится в исходном\n";
                }
                else
                {
                    cout << "Список содержится в исходном\n" << "Последнее вхождение начинается с индекса " << lastContain(&head, head2, len1, quan) << endl;
                }
                DeleteList(&head2);
            }

            break;
            case 19:
            {
                unsigned int ind1, ind2;
                cout << "Введите индексы элементов списка которые вы хотите поменять местами.\nПервый индекс:";
                cin >> ind1;
                cout << "\nВторой индекс:";
                cin >> ind2;
                cout << "Полученный список:";
                swap_elems(head, ind1, ind2);
                outList(head);
            }
            break;
            default:
                cout << "Введено некорректное число";
            }
        }
    }
    break;
    case(2):
    {
        unsigned int cmd;

        while (1) {
            cout << "\n______________________________________________________________________________________\n";
            cout << "Меню:\n\n";
            cout << "0. Выйти из программы\n";
            cout << "1. Добавить элемент в конец списка\n";
            cout << "2. Добавить элемент в начало списка\n ";
            cout << "3. Удалить последний элемент списка\n ";
            cout << "4. Удалить первый элемент списка\n";
            cout << "5. Добавить элемент по индексу\n ";
            cout << "6. Получить элемент по индексу\n ";
            cout << "7. Удалить элемент по индексу\n";
            cout << "8. Получить размер списка\n ";
            cout << "9. Удалить все элементы\n ";
            cout << "10. Заменить элемент по индексу на передаваемый элемент\n";
            cout << "11. Проверить пуст ли список\n ";
            cout << "12. Изменить порядок элементов в списке на обратный\n ";
            cout << "13. Вставить другой список в список, начиная с индекса\n";
            cout << "14. Вставить другой список в конец\n ";
            cout << "15. Вставить другой список в начало\n ";
            cout << "16. Проверить содержится ли другой список в списке\n";
            cout << "17. Найти первое вхождение другого списка в список\n ";
            cout << "18. Найти последнее вхождение списка в список\n ";
            cout << "19. Поменять  два элемента списка по индексам\n";
            cout << "______________________________________________________________________________________\n";
            cin >> cmd;
            switch (cmd) {
            case 0:
                cout << "Меню закрыто";
                return;

            case 1:
            {
                Node* tmp = new Node;
                tmp->num = 80;
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;

                    input_txt2(head, i);

                    //cout << "\nВремя для списка размером " << i << " :" << measure_ins_end(head, tmp) << endl;
                    cout << measure_ins_end(head, tmp) << ", ";
                    DeleteList(&head);
                }

                cout << endl;
            }
            break;
            case 2:
            {
                Node* tmp = new Node;
                tmp->num = 80;
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_ins_beg(&head, tmp);
                    cout << measure_ins_beg(&head, tmp) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 3:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_del_end(&head);
                    cout << measure_del_end(&head) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 4:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_del_beg(&head);
                    cout << measure_del_beg(&head) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 5:
            {
                Node* tmp = new Node;
                tmp->num = 80;
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_ins_mid(&head, tmp, i);
                    cout << measure_ins_mid(&head, tmp, i) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }

            break;
            case 6:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_get_ind(&head, i);
                    cout << measure_get_ind(&head, i) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 7:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_del_ind(&head, i);
                    cout << measure_del_ind(&head, i) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 8:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_get_len(head);
                    cout << measure_get_len(head) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 9:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_del_list(&head);
                    cout << measure_del_list(&head) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 10:
            {
                Node* tmp = new Node;
                tmp->num = 80;
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_replace(&head, tmp, i);
                    cout << measure_replace(&head, tmp, i) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 11:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_empty(&head);
                    cout << measure_empty(&head) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 12:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "\nВремя для списка размером " << i << " :" << measure_reverse(&head);
                    cout << measure_reverse(&head) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }
            break;
            case 13:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head1 = new Node;
                    head1 = NULL;
                    input_txt2(head1, i);
                    Node* head2 = new Node;
                    head2 = NULL;
                    input_txt2(head2, i / 2);
                    //cout << "Время для списка размером" << i << ":" << measure_list_ind(&head1, head2, i);
                    cout << measure_list_ind(&head1, head2, i) << ", ";
                    DeleteList(&head1);
                }
                cout << endl;
            }
            break;
            case 14:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head1 = new Node;
                    head1 = NULL;
                    input_txt2(head1, i);
                    Node* head2 = new Node;
                    head2 = NULL;
                    input_txt2(head2, i / 2);
                    //cout << "Время для списка размером" << i << ":" << measure_list_end(&head1, head2);
                    cout << measure_list_end(&head1, head2) << ", ";
                    DeleteList(&head1);
                }
                cout << endl;
            }
            break;
            case 15:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head1 = new Node;
                    head1 = NULL;
                    input_txt2(head1, i);
                    Node* head2 = new Node;
                    head2 = NULL;
                    input_txt2(head2, i / 2);
                    //cout << "Время для списка размером" << i << ":" << measure_list_beg(&head1, head2);
                    cout << measure_list_beg(&head1, head2) << ", ";
                    DeleteList(&head1);
                }
                cout << endl;
            }
            break;
            case 16:
            {
                for (unsigned int i = 200; i <= 4000; i += 200)
                {
                    Node* head1 = new Node;
                    head1 = NULL;
                    input_txt2(head1, i);
                    Node* head2 = new Node;
                    head2 = NULL;
                    input_txt2(head2, i / 15);
                    //cout << "Время для списка размером" << i << ":" << measure_contains(&head1, head2, i, i / 15);
                    cout << measure_contains(&head1, head2, i, i / 15) << ", ";
                    DeleteList(&head1);
                    DeleteList(&head2);
                }
                cout << endl;
            }
            break;
            case 17:
            {
                for (unsigned int i = 200; i <= 4000; i += 200)
                {
                    Node* head1 = new Node;
                    head1 = NULL;
                    input_txt2(head1, i);
                    Node* head2 = new Node;
                    head2 = NULL;
                    input_txt2(head2, i / 15);
                    if (!contains(&head1, head2, i, i / 15))
                    {
                        cout << measure_contains(&head1, head2, i, i / 15) << ", ";
                    }
                    else
                    {
                        cout << measure_first_contain(&head1, head2, i, i / 15) << ", ";
                    }
                    //cout << "Время для списка размером" << i << ":" << measure_first_contain(&head1, head2, i, i / 15);
                    DeleteList(&head1);
                    DeleteList(&head2);
                }
                cout << endl;
            }
            break;
            case 18:
            {
                for (unsigned int i = 200; i <= 4000; i += 200)
                {
                    Node* head1 = new Node;
                    head1 = NULL;
                    input_txt2(head1, i);
                    Node* head2 = new Node;
                    head2 = NULL;
                    input_txt2(head2, i / 15);
                    //cout << "Время для списка размером" << i << ":" << measure_last_contain(&head1, head2, i, i / 15);
                    if (!contains(&head1, head2, i, i / 15))
                    {
                        cout << measure_contains(&head1, head2, i, i / 15) << ", ";
                    }
                    else
                    {
                        cout << measure_last_contain(&head1, head2, i, i / 15) << ", ";
                    }
                    DeleteList(&head1);
                    DeleteList(&head2);
                }
                cout << endl;
            }

            break;
            case 19:
            {
                for (unsigned int i = 500; i <= 10000; i += 500)
                {
                    Node* head = new Node;
                    head = NULL;
                    input_txt2(head, i);
                    //cout << "Время для списка размером" << i << ":" << measure_swap(head, 2, i - 1);
                    cout << measure_swap(head, 2, i - 1) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }


            break;
            default:
                cout << "Введено некорректное число";
            }
        }
    }
    break;
    default:
        cout << "Введено некорректное число";

    }
}