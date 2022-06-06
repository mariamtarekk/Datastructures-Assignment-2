#include<iostream>
using namespace std;

class Stack {
    class Node {
    public:
        string data;
        Node *next = nullptr;
    };

    Node *top;
public:
    //Default Constructor
    Stack() {
        top = nullptr;
    }

    //Parameterized Constructor
    Stack(string d) {
        top = new Node ;
        for(int i = 0 ; i < d.length() ; i++)
            Push(d);
    }

    //Push Function for inserting.
    void Push(string str) {
        Node *newnode = new Node;
        newnode->data = str;
        newnode->next = top;
        top = newnode;
    }

    //Pop Function for Deleting
    string Pop() {
        string str;
        //Check if Stack is empty.
        if (top == NULL) {
            cout << "Stack UnderFlow" << endl;
            return NULL;
        }
            //Stack not Empty.
        else {
            Node *firstNode = top;
            top = firstNode->next;
            str = firstNode->data;
            delete (firstNode);
            return str;
        }
    }

    string Peak() {
        //Check if Stack is empty.
        if (top == NULL) {
            cout << "Stack UnderFlow" << endl;
            return NULL;
        } else {
            return top->data;
        }
    }

    void display() {
        Node *current;
        //Check if Stack is empty.
        if (top == NULL) {
            cout << "Stack UnderFlow" << endl;
        } else {
            current = top;
            while (current != NULL) {
                cout << current->data << endl;
                current = current->next;
            }
        }
        cout << endl;
    }

    //bool is emoty function to check if the stack is empty or not
    bool IsEmpty() {
        if (top == NULL)
            return true;
        else
            return false;
    }
    //Destructor
    ~Stack(){
        delete top ;
    }
};

string Simplify(string sr) {
    //contain the result of simplify.
    Stack str;
    string result;
    for (int i = 0; i < sr.length(); i++) {
        string directory = "";
        //skip any multiple '/'
        while (sr[i] == '/')
            i++;
        while (i < sr.length() && sr[i] != '/') {
            directory += sr[i];
            i++;
        }
        if (directory == "..") {
            if (!str.IsEmpty())
                str.Pop();
        } else {
            // push the current directory into the vector.
            str.Push(directory);
        }
    }


    while (!str.IsEmpty()) {
        result += +"/" + str.Pop();
    }
    if (result == "")
        return "/";

    return result;
}

int main() {
    //First Test Case.
    string string1("/home/");
    string res = Simplify(string1);
    cout << "\"" << res << "\"" << endl;

    //Second Test Case.
    string string2("/../");
    string res1 = Simplify(string2);
    cout << "\"" << res1 << "\"" << endl;

    //Third Test Case.
    string string3("/home//foo/");
    string res2 = Simplify(string3);
    cout << "\"" << res2 << "\"" << endl;

    //Fourth Test Case.
    string string4("");
    string res3 = Simplify(string4);
    cout << "\"" << res3 << "\"" << endl;

    return 0;

}