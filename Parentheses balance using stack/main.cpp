#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

const int MAX_ITEMS = 5;
class FullStack
// Exception class thrown
// by Push when stack is full.
{};
class EmptyStack
// Exception class thrown
// by Pop and Top when stack is emtpy.
{};
template <class ItemType>
class StackType
{
public:
StackType();
bool IsFull();
bool IsEmpty();
void Push(ItemType);
void Pop();
ItemType Top();
private:
int top;
ItemType items[MAX_ITEMS];
};

#endif // STACKTYPE_H_INCLUDED



template <class ItemType>
StackType<ItemType>::StackType()
{
top = -1;
}
template <class ItemType>
bool StackType<ItemType>::IsEmpty()
{
return (top == -1);
}
template <class ItemType>
bool StackType<ItemType>::IsFull()
{
return (top == MAX_ITEMS-1);
}
template <class ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
if( IsFull() ) throw FullStack();
top++;
items[top] = newItem;
}
template <class ItemType>
void StackType<ItemType>::Pop()
{
if( IsEmpty() ) throw EmptyStack();
top--;
}
template <class ItemType>
ItemType StackType<ItemType>::Top()
{
if (IsEmpty()) throw EmptyStack();
return items[top];
}


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
