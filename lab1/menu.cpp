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
        cout << "������� ���������� ��������� ������ �������� ������:\n";
        cin >> quan;
        Node* head = new Node; // ������� ������
        head = NULL; // ������ ������
        input_txt(head, quan);
        cout << "�������� ������:\n";
        outList(head);
        while (1) {
            cout << "______________________________________________________________________________________\n";
            cout << "����:\n\n";
            cout << "0. ����� �� ���������\n";
            cout << "1. �������� ������� � ����� ������\n";
            cout << "2. �������� ������� � ������ ������\n ";
            cout << "3. ������� ��������� ������� ������\n ";
            cout << "4. ������� ������ ������� ������\n";
            cout << "5. �������� ������� �� �������\n ";
            cout << "6. �������� ������� �� �������\n ";
            cout << "7. ������� ������� �� �������\n";
            cout << "8. �������� ������ ������\n ";
            cout << "9. ������� ��� ��������\n ";
            cout << "10. �������� ������� �� ������� �� ������������ �������\n";
            cout << "11. ��������� ���� �� ������\n ";
            cout << "12. �������� ������� ��������� � ������ �� ��������\n ";
            cout << "13. �������� ������ ������ � ������, ������� � �������\n";
            cout << "14. �������� ������ ������ � �����\n ";
            cout << "15. �������� ������ ������ � ������\n ";
            cout << "16. ��������� ���������� �� ������ ������ � ������\n";
            cout << "17. ����� ������ ��������� ������� ������ � ������\n ";
            cout << "18. ����� ��������� ��������� ������ � ������\n ";
            cout << "19. ��������  ��� �������� ������ �� ��������\n";
            cout << "______________________________________________________________________________________\n";
            cin >> cmd;

            switch (cmd) {
            case 0:
                return;

            case 1:
            {
                Node* tmp = new Node;
                cout << "������� �������, ������� �� ������ ��������:";
                cin >> tmp->num;
                insertEnd(head, tmp);
                outList(head);
            }
            break;
            case 2:
            {
                Node* tmp = new Node;
                cout << "������� �������, ������� �� ������ ��������:";
                cin >> tmp->num;
                insertBeg(&head, tmp);
                cout << "���������� ������:";
                outList(head);
            }
            break;
            case 3:
                DeleteEnd(&head);
                cout << "���������� ������:";
                outList(head);
                break;
            case 4:
                DeleteBeg(&head);
                cout << "���������� ������:";
                outList(head);
                break;
            case 5:
            {
                Node* tmp = new Node;
                unsigned int el;
                cout << "������� ������ ��������, ����� ������� ����� �������� ������� ";
                cin >> el;
                cout << "������� �������, ������� �� ������ ��������: ";
                cin >> tmp->num;
                insertMiddle(&head, tmp, el);
                cout << "���������� ������:";
                outList(head);
            }

            break;
            case 6:
            {
                unsigned int el;
                cout << "������� ������ ��������, ������� ������ �������� ";
                cin >> el;
                cout << "������� � �������� " << el << ": " << get_elem(&head, el) << endl;

            }
            break;
            case 7:
            {
                unsigned int el;
                cout << "������� ������ ��������, ������� ������ ������� ";
                cin >> el;
                delete_ind(&head, el);
                cout << "���������� ������:";
                outList(head);
            }
            break;
            case 8:
                cout << "����� ������ ����� " << get_len(head) << endl;

                break;
            case 9:
                DeleteList(&head);
                cout << "��� �������� ������ ���� �������.\n���������� ������:";
                outList(head);
                break;
            case 10:
            {
                Node* tmp = new Node;
                unsigned int el;
                cout << "������� ������ ��������, ������� �� ������ �������� ";
                cin >> el;
                cout << "������� �������, �� ������� ����� �������� ������� � �������� " << el << " :";
                cin >> tmp->num;
                replace_elem(&head, tmp, el);
                cout << "���������� ������:";
                outList(head);
            }
            break;
            case 11:
                if (isEmpty(&head)) {
                    cout << "\n������ ����\n";
                }
                else {
                    cout << "\n������ �� ����\n";
                }
                break;
            case 12:
                reverseOrder(&head);
                cout << "���������� ������:";
                outList(head);
                break;
            case 13:
            {
                Node* head2 = new Node; // ������� ������
                head2 = NULL;
                unsigned int quan, index;
                cout << "������� �������� ������ ��� �������!\n������� ���������� ��������� ������ �������� ������:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "������� ������, � �������� ����� �������� �������\n";
                cin >> index;
                insertListind(&head, head2, index);
                cout << "���������� ������:";
                outList(head);
            }
            break;
            case 14:
            {
                Node* head2 = new Node; // ������� ������
                head2 = NULL;
                unsigned int quan;
                cout << "������� �������� ������ ��� �������!\n������� ���������� ��������� ������ �������� ������:\n";
                cin >> quan;
                input_txt(head2, quan);
                insertListEnd(&head, head2);
                cout << "���������� ������:";
                outList(head);
            }
            break;
            case 15:
            {
                Node* head2 = new Node; // ������� ������
                head2 = NULL;
                unsigned int quan;
                cout << "������� �������� ������ ��� �������!\n������� ���������� ��������� ������ �������� ������:\n";
                cin >> quan;
                input_txt(head2, quan);
                insertListBeg(&head, head2);
                cout << "���������� ������:";
                outList(head);
            }
            break;
            case 16:
            {
                Node* head2 = new Node; // ������� ������
                head2 = NULL;
                unsigned int quan, len1;
                cout << "������� �������� ������, ����� ��������� ������ �� �� � ��������!\n������� ���������� ��������� ������ �������� ������:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "���������� ������:";
                outList(head2);
                len1 = get_len(head);
                if (contains(&head, head2, len1, quan))
                {
                    cout << "������ ���������� � ��������\n";
                }
                else
                {
                    cout << "������ �� ���������� � ��������\n";
                }
                DeleteList(&head2);
            }
            break;
            case 17:
            {
                Node* head2 = new Node; // ������� ������
                head2 = NULL;
                unsigned int quan, len1;
                cout << "������� �������� ������, ����� ����� ������ ��� ������� ��������� � ��������!\n������� ���������� ��������� ������ �������� ������:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "���������� ������:";
                outList(head2);
                len1 = get_len(head);
                if (!contains(&head, head2, len1, quan))
                {
                    cout << "������ �� ���������� � ��������\n";
                }
                else
                {
                    cout << "������ ���������� � ��������\n" << "������ ��������� ���������� � ������� " << firstContain(&head, head2, len1, quan) << endl;
                }
                DeleteList(&head2);
            }
            break;
            case 18:
            {
                Node* head2 = new Node; // ������� ������
                head2 = NULL;
                unsigned int quan, len1;
                cout << "������� �������� ������, ����� ����� ������ ��� ���������� ��������� � ��������!\n������� ���������� ��������� ������ �������� ������:\n";
                cin >> quan;
                input_txt(head2, quan);
                cout << "���������� ������:";
                outList(head2);
                len1 = get_len(head);
                if (!contains(&head, head2, len1, quan))
                {
                    cout << "������ �� ���������� � ��������\n";
                }
                else
                {
                    cout << "������ ���������� � ��������\n" << "��������� ��������� ���������� � ������� " << lastContain(&head, head2, len1, quan) << endl;
                }
                DeleteList(&head2);
            }

            break;
            case 19:
            {
                unsigned int ind1, ind2;
                cout << "������� ������� ��������� ������ ������� �� ������ �������� �������.\n������ ������:";
                cin >> ind1;
                cout << "\n������ ������:";
                cin >> ind2;
                cout << "���������� ������:";
                swap_elems(head, ind1, ind2);
                outList(head);
            }
            break;
            default:
                cout << "������� ������������ �����";
            }
        }
    }
    break;
    case(2):
    {
        unsigned int cmd;

        while (1) {
            cout << "\n______________________________________________________________________________________\n";
            cout << "����:\n\n";
            cout << "0. ����� �� ���������\n";
            cout << "1. �������� ������� � ����� ������\n";
            cout << "2. �������� ������� � ������ ������\n ";
            cout << "3. ������� ��������� ������� ������\n ";
            cout << "4. ������� ������ ������� ������\n";
            cout << "5. �������� ������� �� �������\n ";
            cout << "6. �������� ������� �� �������\n ";
            cout << "7. ������� ������� �� �������\n";
            cout << "8. �������� ������ ������\n ";
            cout << "9. ������� ��� ��������\n ";
            cout << "10. �������� ������� �� ������� �� ������������ �������\n";
            cout << "11. ��������� ���� �� ������\n ";
            cout << "12. �������� ������� ��������� � ������ �� ��������\n ";
            cout << "13. �������� ������ ������ � ������, ������� � �������\n";
            cout << "14. �������� ������ ������ � �����\n ";
            cout << "15. �������� ������ ������ � ������\n ";
            cout << "16. ��������� ���������� �� ������ ������ � ������\n";
            cout << "17. ����� ������ ��������� ������� ������ � ������\n ";
            cout << "18. ����� ��������� ��������� ������ � ������\n ";
            cout << "19. ��������  ��� �������� ������ �� ��������\n";
            cout << "______________________________________________________________________________________\n";
            cin >> cmd;
            switch (cmd) {
            case 0:
                cout << "���� �������";
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

                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_ins_end(head, tmp) << endl;
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_ins_beg(&head, tmp);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_del_end(&head);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_del_beg(&head);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_ins_mid(&head, tmp, i);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_get_ind(&head, i);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_del_ind(&head, i);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_get_len(head);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_del_list(&head);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_replace(&head, tmp, i);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_empty(&head);
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
                    //cout << "\n����� ��� ������ �������� " << i << " :" << measure_reverse(&head);
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
                    //cout << "����� ��� ������ ��������" << i << ":" << measure_list_ind(&head1, head2, i);
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
                    //cout << "����� ��� ������ ��������" << i << ":" << measure_list_end(&head1, head2);
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
                    //cout << "����� ��� ������ ��������" << i << ":" << measure_list_beg(&head1, head2);
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
                    //cout << "����� ��� ������ ��������" << i << ":" << measure_contains(&head1, head2, i, i / 15);
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
                    //cout << "����� ��� ������ ��������" << i << ":" << measure_first_contain(&head1, head2, i, i / 15);
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
                    //cout << "����� ��� ������ ��������" << i << ":" << measure_last_contain(&head1, head2, i, i / 15);
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
                    //cout << "����� ��� ������ ��������" << i << ":" << measure_swap(head, 2, i - 1);
                    cout << measure_swap(head, 2, i - 1) << ", ";
                    DeleteList(&head);
                }
                cout << endl;
            }


            break;
            default:
                cout << "������� ������������ �����";
            }
        }
    }
    break;
    default:
        cout << "������� ������������ �����";

    }
}