/*program that reads the equations.txt and uses Stack to calculate the result of equations in the postfix form
Each "consecutive" number is separated with the ";" symbol.
"^" is used to represent power operation. (2^3 = 8)
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
using namespace std;
#include <iomanip>
#define default_size 200
#include <cmath> //for power operation

class Stack {
private :
    int top;
    int elements[default_size];
public:
    Stack() {
        top = -1;
        for (int i = 0; i < default_size; i++) {
            elements[i] = NULL; //create empty stack
        }
    }

    bool isFull() {
        return top == default_size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int element) {
        if (!isFull()) {
            top++;
            elements[top] = element;
        } else {
            cout << "Stack is full !" << endl;          
        }
    }

    
    int topElement() {
        return (!isEmpty()) ? elements[top] : NULL;
    };

   
    int pop() {
        if (!isEmpty()) {
            int top_element = elements[top];
            elements[top] = NULL;
            top--;
            return top_element;
        } else {
            cout << "Stack is empty !" << endl;
            return NULL;
        }
    }

    void printStack() {
        cout << "Stack" << endl;
        for (int i = 0; i < default_size; i++) {
            if (elements[i] != NULL) {
                cout << "[" << setprecision(11) << elements[i] << "]";
            } else {
                cout << "[" << "]";
            }
        }
        cout << endl;
    };
};
 
    int main() {
    	
    Stack equations;
    //equations.printStack();
    
    ifstream read_file;
    read_file.open(".../equations.txt");
    
    if (!read_file.is_open()) {
        cerr << "File  could not be opened" << endl;
        exit(1);
    }
    
    string line;
    string element;
    string element2;
    double num1;
    double num2;
	string array[500];
	string s = ";";
	string sum = "+";
	string fark = "-";
	string product = "*";
	string div = "/";
	string ust = "^";
	double result;
	int equationNum = 0;
	
	while (getline(read_file, line)) { //we get each line 
        
		for (int i = 0; i < line.size(); i++){
			element = line[i];			
			
			if(isdigit(line[i])){ //seperates two digit and one digit numbers
				if(isdigit(line[i+1])){
					//cout <<"double";
					element2 = line[i+1];
					string elements = element + element2;
					int int_element2 = stoi(elements);
				    equations.push(int_element2);
				    //cout << int_element2<< endl;
				}else if(!isdigit(line[i-1])){
					//cout << "number";
					int int_element = stoi(element);
					equations.push(int_element);
					//cout << int_element<< endl;
				}
							
			}else if(element == s){ // do nothing when ; 
				//cout << ";";
			}else if(element == sum){ // addition for last two elements of stack when + 
				//cout << "sum";
				
				num1 = equations.pop();
		        num2 = equations.pop();
			      
			    result = num2+num1;
			    equations.push(result);	
				//cout << result << endl;
			}else if(element == fark){ // subtraction when -
				//cout << "fark";
				
				num1 = equations.pop();
		        num2 = equations.pop();
			      
			    result = num1-num2;
			    equations.push(result); 
				//cout << result << endl;
			}else if(element == product){ // multiply when * 
				//cout << "product";
				
			    num1 = equations.pop();
		        num2 = equations.pop();
			    
			    result = num1*num2;
			    equations.push(result);	      		
			    //cout << result << endl;
			}else if(element == div){ // division when /
				//cout << "div";
				
				num1 = equations.pop();
		        num2 = equations.pop();
			      
			    result = num1/num2;
			    equations.push(result);
			    //cout << result << endl;
			}else if(element == ust){ 
				//cout << "ust";
				
				num1 = equations.pop();
		        num2 = equations.pop();
			      
			    result = pow(num1, num2);
			    equations.push(result);	
				//cout << result << endl;
			}	
		}
	equationNum++;	// increment equations numbers when displayed result
	//equations.printStack();  
	cout << "Answer of equation " << equationNum << " is " << equations.topElement() << endl;
	equations.pop(); //for new line or equation, to create empty stack
	
	}
	read_file.close();

}    
	


