#include "std_lib_facilities.h"

void parentheses()
{
    cout << "in parentheses\n";
    
    int sum = 0;
    int numbers = 0;
    char op {};
    string s {};
    
    // read until not a number
    while(cin >> numbers)
    {
        // but catch operator
        cin >> op;
        switch(op)
        {
        case '+':
            sum += numbers;
            s += numbers;
            break;
            
        }
    }
    cout << s << "," << sum;
}

void readSum(int& lval, int& rval)
{
    int count = 0;
    // first input
	cin >> lval;
	if(!cin) error("no first operand");
	
    // grab operator for each new rval
	for(char op; cin >> op;)
	{
	    // now grab rval
	    if(op!='x') cin >> rval;
	    if(!cin) error("no second operand");
	    switch(op)
	    {
	        case '+':
	        {
	            lval += rval;
	            cout << "check" << count << ":";
	            cin.unget();
	            char check {};
	            cin >> check;
	            if(check=='(')
	            {
	                cout << "found";
	                return;
	            }
	            break;
	        }
	        case '-':
	            lval -= rval;
	            break;
	        case '*':
	            lval *= rval;
	            break;
	        case '/':
	            lval /= rval;
	            break;
	        default:
	            cout << ":" << lval << "\n";
	            return;
	            //error("no recognised operator");
	    }
	    ++count;
	}
	error("bad expression");
}

int main(int argc, char *argv[])
{
	int lval = 0;
	int rval = 0;
	
	cout << "Please enter a sum.\n";
	readSum(lval, rval);
}