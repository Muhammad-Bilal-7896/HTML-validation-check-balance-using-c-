#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

char openingBracket(char closing_bracket)
{
    char opening_bracket;
    if (closing_bracket == '}') 
      return '{' ;
    else if (closing_bracket == ')') 
     return '(' ;
    else if (closing_bracket == ']') 
     return '[' ;
}
void areParenthesisBalanced(string name)
{
    stack<char> S;
    bool isBalanced = true;
    for(int i=0;i<name.length();i++)
    {
        if( name[i] == '(' || name[i] == '{' || name[i] == '[' )
        {
        S.push(name[i]);
        }
        else if(name[i] == '}' || name[i] == ')' || name[i] == ']')
        {
            if( (S.empty() && i!=name.length()) || (S.top()!= openingBracket(name[i]) ))
            {
               isBalanced = false;
               break;
            }
            else
            {
               S.pop();
            }
        }
    }
    if(isBalanced)
    {
        cout<<"\n The expression is balanced!!\n";
    }
    else if(!isBalanced)
    {
       cout << "The expression is not balanced!\n";
    }
    
}
int main()
{
    string name ;
    cout<<"Enter an expression:";
    getline(cin,name);
    areParenthesisBalanced(name);

    return 0;
}
