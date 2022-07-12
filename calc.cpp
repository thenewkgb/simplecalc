#include "std_lib_facilities.h"

// you can find "std_lib_facilities.h" at Bjarne Stroustrups website

// does cin try to read the right type but fails after two attemps?

// todo
// right parentheses special case does not
// calculate lval

void readSum(int& lval, int& rval)
{
    char symbol {};
    int count = 0;
    int countop = 0;
    int foundnotcin = 0;
    
    // first input
	cin >> lval;
	if(!cin) error("no first operand");
	
    // grab operator
	for(char op; cin >> op;)
	{
	    cout << "op " << op;
	    // now grab rval
	    if(op!='x')
	    {
	         cin >> rval;
	    }
	    // if rval is a parentheses
	    if(!cin)
	    {
	        cin.clear();
	        cin >> symbol;
	        cout << foundnotcin++ << "cin failed with " << symbol << "\n";
	        if(symbol!='(')
	            error("no second operand");
	    }
	    
	    switch(op)
	    {
	        case '+':
	        {
	            lval += rval;
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
	        // special case for last parentheses
	        case ')':
	            cout << "rval" << rval;
	            break;
	        default:
	            cout << ":" << lval << "\n";
	            return;
	    }
	}
	// handle worst case scenario
	error("bad expression");
}

int main(int argc, char *argv[])
{
	int lval = 0;
	int rval = 0;
	
	cout << "Please enter a sum.\n";
	readSum(lval, rval);
}
