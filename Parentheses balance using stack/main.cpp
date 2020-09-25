#include <iostream>

#include "stacktype.cpp"
using namespace std;

int sum(string eq)
{

    if(eq[0] == '\0')
        return -1;
    int result = 1, i=0;

    while(i<eq.length())
    {
        if(eq[i] == '(' || eq[i] == ')' || eq[i] == '{' || eq[i] == '}' || eq[i] == '[' || eq[i] == ']')
            {
                i++;
                continue;
            }

        int num;
        char opr;
        if(eq[i] >= '0' && eq[i] <= '9')
        {
            num = (int)eq[i];
            opr = eq[i+1];
        }
        else
        {
            i++;
            continue;
        }

        switch(opr)
        {
        case '+':
            result += num;
            break;
        case '-':
            result -= num;
            break;
        case '*':
            result *= num;
            break;
        case '/':
            result /= num;
            break;
        default:
            break;
        }
        i+=2;
    }



    return result;
}

int main()
{
    cout << "Hello world!" << endl;

    string paren;
    cout << "Enter equation: " << endl;
    getline(cin, paren);
    cout << paren << endl ;
    StackType<char> balance;
    char top;

    for( int i=0; i<paren.length(); i++)
    {
        if(paren[i] =='(' || paren[i] == '{' || paren[i] == '[' )
        {
            balance.Push(paren[i]);
            continue;
        }

         switch(paren[i])
            {
            case ')':

                if(balance.Top() == '(')
                    balance.Pop();
                else
                    balance.Push(paren[i]);

                break;

            case '}':

                if(balance.Top() == '{')
                    balance.Pop();
                else
                    balance.Push(paren[i]);

                break;

            case ']':

                if(balance.Top() == '[')
                    balance.Pop();
                else
                    balance.Push(paren[i]);

                break;

            default:
                break;
            }

    }

    if(balance.IsEmpty())
    {
        cout << "balanced." << endl;
        int result = sum(paren); //doesn't work properly
        cout << result;
    }
    else
        cout << "not balanced. " << endl;


    return 0;
}
