#include <windows.h>    // sleep
#include <iostream>
#include <stdlib.h>     // ���
#include <time.h>       // �����
using namespace std;

/* ������� ���� ��������� �����. ����� ������ �� ������� ������ ���������� (������). ����� ������� ������, ������ ������, ������� �� ��� �������. � ���� ������ �������,
�������� � ������� ���� ������, ������� �� � ������������.

� ���������� ����� ������ ������������. ������ ����� �� ��� ��� ���� �� �������� ������ � ������ (�������) ��� �� �� �� ��������� �� ����. ������������ ����� ������-
������ �� ���� ������ 0. ��� ���������� ������� ����� ������������.
���� ������� ���� ����� ���������: �� ������ �������� ������� ����� ������ � ������� � ����� ������ �� ��� ��� ���� �� ��� �� ��������� ���� �� ��������� �� ����. ����
����� ������ 0, �� ������ ��������� �� ����. ����� �� ���� ����� ��������� ��� ���������� ����.

���: ���� �� ������� %6, �� � ����� ������ � ��� ������� ����� �� 0 �� 6 (0-5), � 0 ��� �� �����, ����, �� �������� 1 � ���������� ����� ���� ������������������ �� 1
(�� 1 �� 7). ���������� ��� ���������: ����� �� ������� %7, ��� ������ � �����, ������� ��� ����������� rand(), �� ����� ������� �� ������� �� 7. � ������� �� �������
�� 7 ������ ����� ��� ����� ���� 0 (����� ������� �� 7 ��� �������), ���� ����� �� ��������� �� 1 �� 7 (������ �������� 0-6).
������ ������ ���? �.�. ��� ���������� ����� 6 � �������, ������ ���� 7-�� ����� ������� � ����� ������� ��� ����� ����� ��� ������� � ��� ����� � ����� �� 0 �� 7. ��-
��� �������� ����� ��������� ���� ������. ����, %6 ������������ �������� �� 6, � +1 �������� ���. ����, ����� � ��� ��������, ����� ����� ������� ������ ������ �� 4 ��
6 ��� ������� ������ ���������, ���� ��� �������� � �.�.

�������� �������� ��������� ��� ������. ������������� ���� � �����, �.�. ����� ����� ���� ��������� ��� ������. ��� �������� ���� while, �.�. �� � ���� ������ ����� ��-
��� ��� ��������, � ��������� ������ ������� ���� �����. */

int main()
{
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    cout << "----------------------------------------------------------�������! ���� � �����!-----------------------------------------------------------------" << endl;
    int cash = 0, bet = 0, strike_pc = 0, strike_player = 0;

    do
    {
        cout << "����� ������ �� �����! "; cin >> cash;
        if (cash < 0)cout << "��p! ������� �������, ����� �������!" << endl;

    } while (cash < 0);

    if (cash == 0)
        cout << "��p! ������� ����������! �����-�� ����������!" << endl;
    else
    {
        do
        {
            system("cls");                                                                          // ������� ������ ����� ������ �����
            cout << "------������ �� �����!------" << endl;
            cout << "� ������� ��������: " << cash << " ��������!" << endl;                         // ������� � ��� ����� �� ����
            do                                                                                      // ����� ������
            {
                cout << "������� ������� ��������? "; cin >> bet;
                if (bet < 0)
                {
                    cout << "����! � ������ ��� ����..? ������� �������?" << endl;
                    Sleep(3000);
                    cout << "�������..? ������ �������� ���� � �������� �������!" << endl;
                    Sleep(3000);
                }
                if (bet > cash)cout << "����, ������� ���� ����! ������ �����/� ������������?" << endl;
            } while (bet<0 || bet>cash);

            if (bet == 0)                                                                            // ����� �� ����!
            {
                cout << "����! ����� ��������! �������� ����� ������!" << endl;
                break;
            }
            else                                                                                     // ������ ������
            {
                strike_pc = rand() % 6 + 1;
                strike_player = rand() % 6 + 1;
                cout << "� ������ ������: ";
                Sleep(3000);
                switch (strike_pc)
                {
                case 1:
                    cout << R"(
 _ _ _
|     |
|  *  |
|_ _ _|
)";
                    break;
                case 2:
                    cout << R"(
 _ _ _
|   * |
|     |
|_*_ _|
)";
                    break;
                case 3:
                    cout << R"(
 _ _ _
|   * |
|  *  |
|_*_ _|
)";
                    break;
                case 4:
                    cout << R"(
 _ _ _
| * * |
|     |
|_*_*_|
)";
                    break;
                case 5:
                    cout << R"(
 _ _ _
| * * |
|  *  |
|_*_*_|
)";
                    break;
                case 6:
                    cout << R"(
 _ _ _
| * * |
| * * |
|_*_*_|
)";
                    break;

                }
                Sleep(3000);
                cout << "\n� ������� ������: ";
                Sleep(3000);
                switch (strike_player)
                {
                case 1:
                    cout << R"(
 _ _ _
|     |
|  *  |
|_ _ _|

)";
                    break;
                case 2:
                    cout << R"(
 _ _ _
|   * |
|     |
|_*_ _|

)";
                    break;
                case 3:
                    cout << R"(
 _ _ _
|   * |
|  *  |
|_*_ _|

)";
                    break;
                case 4:
                    cout << R"(
 _ _ _
| * * |
|     |
|_*_*_|

)";
                    break;
                case 5:
                    cout << R"(
 _ _ _
| * * |
|  *  |
|_*_*_|

)";
                    break;
                case 6:
                    cout << R"(
 _ _ _
| * * |
| * * |
|_*_*_|

)";
                    break;

                }
                Sleep(3000);

                while (strike_pc == strike_player)
                {
                    cout << "\n����! ���������!\n" << endl;
                    strike_pc = rand() % 6 + 1;
                    strike_player = rand() % 6 + 1;
                    cout << "� ������ ������: ";
                    Sleep(3000);
                    switch (strike_pc)
                    {
                    case 1:
                        cout << R"(
 _ _ _
|     |
|  *  |
|_ _ _|
)";
                        break;
                    case 2:
                        cout << R"(
 _ _ _
|   * |
|     |
|_*_ _|
)";
                        break;
                    case 3:
                        cout << R"(
 _ _ _
|   * |
|  *  |
|_*_ _|
)";
                        break;
                    case 4:
                        cout << R"(
 _ _ _
| * * |
|     |
|_*_*_|
)";
                        break;
                    case 5:
                        cout << R"(
 _ _ _
| * * |
|  *  |
|_*_*_|
)";
                        break;
                    case 6:
                        cout << R"(
 _ _ _
| * * |
| * * |
|_*_*_|
)";
                        break;

                    }
                    Sleep(3000);
                    cout << "\n� ������� ������: ";
                    Sleep(3000);
                    switch (strike_player)
                    {
                    case 1:
                        cout << R"(
 _ _ _
|     |
|  *  |
|_ _ _|
)";
                        break;
                    case 2:
                        cout << R"(
 _ _ _
|   * |
|     |
|_*_ _|
)";
                        break;
                    case 3:
                        cout << R"(
 _ _ _
|   * |
|  *  |
|_*_ _|
)";
                        break;
                    case 4:
                        cout << R"(
 _ _ _
| * * |
|     |
|_*_*_|
)";
                        break;
                    case 5:
                        cout << R"(
 _ _ _
| * * |
|  *  |
|_*_*_|
)";
                        break;
                    case 6:
                        cout << R"(
 _ _ _
| * * |
| * * |
|_*_*_|
)";
                        break;

                    }
                    Sleep(3000);
                }

                // ����������� ����������
                if (strike_pc > strike_player)
                {
                    cout << "�����, ���, �� � ���� ������ ����!" << endl;
                    cash -= bet;
                    cout << "� ������� ��������: " << cash << " ��������!" << endl;
                }
                else
                {
                    cout << "����� ���� ���������/��!" << endl;
                    cash += bet;
                    cout << "� ������� ���������: " << cash << " ��������!" << endl;
                }
                if (cash == 0)
                {
                    cout << "�����, �����, �� �� ����� ������� �����������/��! ������!" << endl;
                    break;
                }
                system("pause");
            }
        } while (cash > 0);   // ������ �� ��� ���, ���� ���� ������
    }
    Sleep(3000);
}

/* ���������:
1.  ��������� ������������ (����� �� ������)
2.  �������� ������ (���� ������, �������� �����, ��������, ����������� ��� ������, ��������� ��� ���������)
3.  ����� ������� (���������)
4.  ����������� ��������� ���� (���������������)
5.  �������� ����������� ���������� (�������� ��� ������ � ������, � �������, ������� ��� � ���� ������ ��� �������...)
6.  �������� ��������� ��� ������ (�������� ��� ������)

�����������:
(!) ������ ������ ���������� ������� ����, �� ����� ��������������! ��� � ��� ��� ����������:
� ��� ���� ������� ������, �� ��� ������� �� �����, � ����� ���� �����, �� ��� ��� ������������� �� ��� ���, ���� �����. �� �����, �������, � ����� ��������� ����� ��
��� ��� �������. �� ������� ������ �����-�� ��������, ����� ��������, � ����� ��������� ����� �� ��������� ���� ����� ����� ��������. � ������ ��� �/� ���������, ��
�������, � ���� �����, ����� �������! � ����� �� �� ����� ������ ������ � ����� do_while. ���������� ��������� ���� ������ � ���� �������, �.�. �� ������������� ��� ��-
����. ����������� ����� ��������� � ����.�������. */