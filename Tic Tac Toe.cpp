#include<iostream>
#include<string>

using namespace std;
void interface(string value[3][3]);
int check1(string value[3][3], int counter);
int check2(string value[3][3], int counter);


int check1(string value[3][3], int counter)
{

    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (value[i][0] == value[i][1] && value[i][1] == value[i][2] && value[i][0] != " ") {
            if (counter % 2 == 0) {
                cout << "--------The Player2 won :)--------" << endl;
                return 0;
            }
            else {
                cout << "--------The Player1 Won :)--------" << endl;
                return 0;
            }
        }
    }
    // check columns
    for (int i = 0; i < 3; ++i) {
        if (value[0][i] == value[1][i] && value[1][i] == value[2][i] && value[0][i] != " ") {
            if (counter % 2 == 0) {
                cout << "--------The Player2 won :)--------" << endl;
                return 0;
            }
            else {
                cout << "--------The Player1 Won :)--------" << endl;
                return 0;
            }
        }
    }
    return 0;
}
void interface(string value[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " | " << value[i][j];
        }
        cout << " | " << endl;
    }
}
 int check2(string value[3][3], int counter)
{
    // بتشيك على القطرين
    if ((value[0][0] == value[1][1] && value[1][1] == value[2][2]) || (value[0][2] == value[1][1] && value[1][1] == value[2][0]))
    {
        if (counter % 2 == 0) {
            cout << "--------The Player2 won :)--------" << endl;
            return 0;
        }
        else {
            cout << "--------The Player1 Won :)--------" << endl;
            return 0;
        }
    }
    return 0;

}
int main()
{
    int row = 0, colmun = 0;
    string v = " ";
    string value[3][3];
    int count = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            value[i][j] = " ";
        interface(value);

    while (true) {
        cout << "Enter the Row" << endl;
        cin >> row;
        while (row != 1 && row != 2 && row != 3)
        {
            cout << "----------INVALID INPUT----------" << endl;
            cout << "Enter the Row" << endl;
            cin >> row;
        }

        cout << "Enter the Column" << endl;
        cin >> colmun;
        while (colmun != 1 && colmun != 2 && colmun != 3)
        {
            cout << "----------INVALID INPUT----------" << endl;
            cout << "Enter the Column" << endl;
            cin >> colmun;
        }
        cout << " X OR O " << endl;
        cin >> v;
        while (v != "X" && v != "x" && v != "o" && v != "O")
        {
            cout << "----------INVALID INPUT----------" << endl;
            cout << " X OR O " << endl;
            cin >> v;
        }

        count++;
        value[row - 1][colmun - 1] = v;
        interface(value);
        if (count >= 5)
        {
            check1(value, count);
            check2(value, count);
        }

    }

    return 0;
}


