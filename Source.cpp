/*
* Team 11
* 
* Assignment  02
 ****   N- queen  ****
 * 
 * 
description:
************** this program will display the 8*8 board of queens by put the queens =>1 else put 0
*/
/*
we include
library iostream , vector and string  and define N with value 8*/
#include <iostream>
#include <vector>
#include<string>
#define N 8
using namespace std;
/*
* struct Node
* with data members :-
* row ,col (with data type int) and pointer next (with data type node)
*/
struct Node {
	int row;
	int col;
	Node* next;
};
/*
* class StackLi with data members:-
* size (data type int) and pointer first(with data type node)
* and member fun:-
* constructor StackLi()
* destructor ~StackLi()
* push()
* pop()
* peak_col()
* peak_row()
* isEmpty()
*/
class StackLi {
private:
	Node* first;
	int  size;
public:
	/*
	* constructor to initial size with 0
	* and pointer first to NULL
	*/
	StackLi() {
		size = 0;
		first = NULL;
	}
	/*
	* destructor to delete Node by:-
	* we define pointer temp and inital it with NULL
	* while loop that do instructions if first not equal NULL(is not empty):-
	* we assign first to temp
	* then first point to next
	* then initialize temp->next to NULL
	* then delete temp and inital it with NULL
	*/
	~StackLi() {
		Node* temp = NULL;
		while (first != NULL) {
			temp = first;
			first = first->next;
			temp->next = NULL;
			delete temp;
			temp = NULL;
		}
	}
	/*
	* push function that take two parameters from data type int (row and column) with return type void that returns nothing
	* first we create new node
	* then check that if new node == NULL
	* if true return nothing
	* else
	* initale newNode->row with the first value in parameter
	* initale newNode->col with the second value in parameter
	* initale newNode->next with first
	* assign newNode to first
	* and finally increament size with 1
	*/
	void push(int row, int col) {
		// step 1
		Node* newNode = new Node();
		// step 2
		if (newNode == NULL)
			return;
		// step 3
		newNode->row = row;
		newNode->col = col;
		newNode->next = first;
		first = newNode;
		size++;
	}
	/*
	* peak_row with return type int and don`t take any parameters
	* inside it check if the stack isEmpty
	* if true print  "stack is under flow\n" and return ' '
	* else return first->row
	*/
	int peak_row() {
		if (isEmpty()) {
			cout << "stack is under flow\n";
			return ' ';
		}
		return first->row;
	}
	/*
	* peak_col with return type int and don`t take any parameters
	* inside it check if the stack isEmpty
	* if true print  "stack is under flow\n" and return ' '
	* else return first->col
	*/
	int peak_col() {
		if (isEmpty()) {
			cout << "stack is under flow\n";
			return ' ';
		}
		return first->col;
	}
	/*
	* pop fun with return type void that delete node
	*  inside it check if the stack isEmpty if true return nothing
	* else
	* decreament size with 1
	* we initialize first to temp
	* then first point to next
	* then initialize temp->next to NULL
	* then delete temp and inital it with NULL
	*/
	void pop() {
		if (isEmpty())
			return;
		size--;
		Node* temp = first;
		first = first->next;
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}
	/*
	* isEmpty fun with return type bool
	* that return true if first==NULL
	*/
	bool isEmpty() {
		return first == NULL;
	}
};
/*
* check the position of the queen is  not in the same row_column_digonal
* noQueenConflicts with return type bool with 3 parametar with data type int (row _ col _ loc(two dymantion array))
*/
bool noQueenConflicts(int Row, int Col, int loc[N][N]) {
	/* nested for with i represent row j represents column*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			/* cheack if there is queen in this location */
			if (loc[i][j] == 1) {
				/* check if current row equal previousrow  and current column  equal previous col , remain in this position*/
				if (Row == i && Col == j) {
				}
				/* check if the another queen(s) in the same column return false*/
				else if (Col == j) {
					return false;
				}
				/*check if the another queen(s) in the diagonal  return false
				*use built in fun abs from library vector
				*/
				else if (abs(Col - j) == abs(Row - i)) {
					return false;
				}
			}
		}
	}
	/* else return true */
	return true;
}
/* fun print board  with return type void and parametar int (two dymantion array) print elements in the stack*/
void printBoard(int loc[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << loc[i][j] << " ";
		}
		cout << endl;
	}
}
/* fun shift queen with retutn type bool and two parametar int (col _ n)
* check if the col in the range of N return true
* else reurn false */
bool ShiftQueen(int Col, int n) {
	if (Col <= n)
		return true;
	return false;
}

int main() {
	/*we define object from the stack called myStack
	3 variables int (Row ,Col, filled<NO of complete Row(queen) >)
	2bool variable (destination , backtrack) and initalize them with true
	two dimention array with dataType int */
	StackLi myStack;
	int Row, Col, filled;
	bool destination = true, backtrack = true;
	int loc[N][N];
	/*
	* Nested for to initialize all positions with 0
	*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			loc[i][j] = 0;
		}
	}
	/*
	*  assign first position [0][0] with 1
	* initalize row=>0
	* initalize col=>0
	* initalize filled=>0
	* the push them in the stack in the first position
	*/
	loc[0][0] = 1;
	Row = 0;
	Col = 0;
	filled = 0;
	myStack.push(Row, Col);
	/*
	* while loop destination is true (inside the range ) do the following instruction
	*/
	while (destination) {
		/* check if  noQueenconflicts with each other and backtrack equal true
		* increament filled with 1
		*/
		if (noQueenConflicts(Row, Col, loc) && backtrack) {
			filled++;
			/*
			check if filled ==N (the board is full and thre is no remaining queen )
			assign destination with false
			else :-
			increament Row with 1
			initaile col with 0
			make location of [current Row][current Col]=1
			then push them in the stack
			*/
			if (filled == N) {
				destination = false;
			}
			else {
				Row++;
				Col = 0;
				loc[Row][Col] = 1;
				myStack.push(Row, Col);

			}
		}
		/*
		* else if check if the col in the range
		* replace  value of current position to 0
		* then pop it from the stack
		* increament col with 1
		* assign  value  of current position with 1
		* then push it to stack
		* finally assign backtrack with true
		*/
		else if (ShiftQueen(Col + 1, N - 1)) {
			loc[Row][Col] = 0;
			myStack.pop();
			Col++;
			loc[Row][Col] = 1;
			myStack.push(Row, Col);
			backtrack = true;
		}
		/*
		* else
		* decreament filled by 1
		* replace value of the current position with 0
		* then pop it from the stack
		*  do myStack.peak_row() and assign it to Row
		*  do myStack.peak_col() and assign it to Col
		* finally assign backtrack with false
		*/
		else {
			filled--;
			loc[Row][Col] = 0;
			myStack.pop();
			Row = myStack.peak_row();
			Col = myStack.peak_col();
			backtrack = false;
		}
	}
	/*print Board*/
	cout << "You program has completed!" << endl;
	printBoard(loc);
	return 0;
}
/************************THANKS******************************/

