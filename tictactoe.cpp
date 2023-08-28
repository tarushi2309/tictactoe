#include<iostream>
using namespace std;
char game[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
string n1,n2;
bool tie=false;
char token='x';
void entry()
{
    int digit;
    if(token=='x')
    {
        cout<<n1<<" please enter block: \n";
        cin>>digit;
    }
    else
    {
        cout<<n2<<" please enter block: \n";
        cin>>digit;
    }
    if(digit==1)
    {
        row=0;
        column=0;
    }
    else if(digit==2)
    {
        row=0;
        column=1;
    }
    else if(digit==3)
    {
        row=0;
        column=2;
    }
    else if(digit==4)
    {
        row=1;
        column=0;
    }
    else if(digit==5)
    {
        row=1;
        column=1;
    }
    else if(digit==6)
    {
        row=1;
        column=2;
    }
    else if(digit==7)
    {
        row=2;
        column=0;
    }
    else if(digit==8)
    {
        row=2;
        column=1;
    }
    else if(digit==9)
    {
        row=2;
        column=2;
    }
    else
    {
        cout<<"invalid input\n";
        entry();
    }
    if(token=='x'&&game[row][column]!='x'&&game[row][column]!='0')
    {
        game[row][column]='x';
        token='0';
    }
    else
    {
        if(token=='0'&&game[row][column]!='x'&&game[row][column]!='0')
        {
        game[row][column]='0';
        token='x';
        }
        else
        {
            cout<<"no empty space\n";
            entry();
        }
    }
}
bool winner()
{
    for(int i=0;i<3;i++)
    {
        if((game[i][0]==game[i][1]&&game[i][2]==game[i][0])||(game[0][i]==game[1][i]&&game[2][i]==game[0][i]))
        return true;
        else if((game[1][1]==game[2][2]&&game[1][1]==game[0][0])||(game[1][1]==game[2][0]&&game[1][1]==game[0][2]))
        return true;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(game[i][j]!='x'&&game[i][j]!='0')
                return false;
            }
        }
        tie=true;
        return true;
    }
}
void display()
{
     cout<<"     |     |     "<<endl;
    cout<<" "<<game[0][0]<<"   |  "<<game[0][1]<<"  |  "<<game[0][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<" "<<game[1][0]<<"   |  "<<game[1][1]<<"  |  "<<game[1][2]<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<" "<<game[2][0]<<"   |  "<<game[2][1]<<"  |  "<<game[2][2]<<endl;
}
int main()
{
    
    cout<<"enter name of player1"<<endl;
    cin>>n1;
    cout<<"enter name of player2"<<endl;
    cin>>n2;
    cout<<n1<<" is player 1 and "<<n2<<" is player 2"<<endl;
    display();
    while(!winner())
    {
        entry();
        display();
        winner();
    }
    if(token=='0'&&tie==false)
    cout<<n1<<" wins\n";
    else if(token=='x'&&tie==false)
    cout<<n2<<" wins\n";
    else
    cout<<"it is a draw\n";
}