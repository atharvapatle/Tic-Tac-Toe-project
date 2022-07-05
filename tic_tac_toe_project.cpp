#include <bits/stdc++.h>
using namespace std;


string player1, player2;
char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int rows, columns;
bool draw;
char token='x';
int key;

void func1()
{


    cout << "           |                 |            " << endl;
    cout << "\t" << arr[0][0] << "  |        " << arr[0][1] << "        | \t" << arr[0][2] << endl;
    cout << "           |                 |             " << endl;
    cout << "___________|_________________|_____________" << endl;
    cout << "           |                 |            " << endl;
    cout << "\t" << arr[1][0] << "  |        " << arr[1][1] << "        | \t" << arr[1][2] << endl;
    cout << "           |                 |            " << endl;
    cout << "___________|_________________|_____________" << endl;
    cout << "           |                 |            " << endl;
    cout << "\t" << arr[2][0] << "  |        " << arr[2][1] << "        | \t" << arr[2][2] << endl;
    cout << "           |                 |            " << endl;
    cout << "           |                 |            " << endl;
}

void checkCondition()
{
    if (token == 'x' && arr[rows][columns] != 'x' && arr[rows][columns] != 'o')
    {
        arr[rows][columns] = 'x';
        token = 'o';
    }
    else if (token == 'o' && arr[rows][columns] != 'x' && arr[rows][columns] != 'o')
    {
        arr[rows][columns] = 'o';
        token = 'x';
    }
}

void func2()
{
    // Initially token value will be set to 'x'

    if (token == 'x')
    {
        cout << player1 << " ! Enter key : ";
        cin >> key;
    }
    else if (token == 'o')
    {
        cout << player2 << " ! Enter key : ";
        cin >> key;
    }

    switch (key)
    {
    case 1:
        rows = 0;
        columns = 0;
        checkCondition();
        break;
    case 2:
        rows = 0;
        columns = 1;
        checkCondition();
        break;
    case 3:
        rows = 0;
        columns = 2;
        checkCondition();
        break;
    case 4:
        rows = 1;
        columns = 0;
        checkCondition();
        break;
    case 5:
        rows = 1;
        columns = 1;
        checkCondition();
        break;
    case 6:
        rows = 1;
        columns = 2;
        checkCondition();
        break;
    case 7:
        rows = 2;
        columns = 0;
        checkCondition();
        break;
    case 8:
        rows = 2;
        columns = 1;
        checkCondition();
        break;
    case 9:
        rows = 2;
        columns = 2;
        checkCondition();
        break;

    default:
        cout << " Invalid Input! " << endl;
        func2();
    }
}


// to check who is gonna won this match!
bool func3()
{
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] || arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
        {
            return true;
        }
        else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] || arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2])
        {
            return true;
        }
    }

//to check game is finished or not:
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j]!='x' && arr[i][j]!='o')
            {
                return false;
            }
            
        }
        
    }

draw=true;
return false;
    

}

int main(){
    
    cout << "Enter the name of player 1 : ";
    getline(cin, player1);
    cout << "\n\nEnter the name of player 2 : ";
    getline(cin, player2);
    cout << "\n\t\tPlayer 1 will go first!\t\t";
    while(!func3()){
           func1();
           func2();
           func3();
    }
    if (draw==false && token=='x')
    {
        cout<<player2<<" Wins! "<<endl;
    }
    else if (draw==false && token=='o')
    {
        cout<<player1<<" Wins! "<<endl;
    }
    else
    {
        cout<<" Game is Draw!"<<endl;
    }
    
}