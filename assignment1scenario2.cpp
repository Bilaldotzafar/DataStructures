#include <iostream>
#include <string>
#include <stack>
using namespace std;

class TextEditor {
private:
    stack<string> undoStack;
    stack<string> redoStack;
    string text;
    
public:
    TextEditor() {
        text = "";
    }
    
    void write(string newText) {
        if (undoStack.size() == 100) {
            stack<string> temp;
            for (int i = 0; i < 99; i++) {
                temp.push(undoStack.top());
                undoStack.pop();
            }
            undoStack.pop();
            while (!temp.empty()) {
                undoStack.push(temp.top());
                temp.pop();
            }
        }
        
        undoStack.push(text);
        text = newText;
        
        while (!redoStack.empty()) {
            redoStack.pop();
        }
        
        cout << "Text: " << text << endl;
    }
    
    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo" << endl;
            return;
        }
        
        redoStack.push(text);
        text = undoStack.top();
        undoStack.pop();
        cout << "Text: " << text << endl;
    }
    
    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo" << endl;
            return;
        }
        
        undoStack.push(text);
        text = redoStack.top();
        redoStack.pop();
        cout << "Text: " << text << endl;
    }
    
    void showText() {
        cout << "Current text: " << text << endl;
    }
};

int main() {
    cout << "SCENARIO 2: Text Editor with Stacks" << endl;
    cout << "====================================" << endl;
    
    TextEditor editor;
    
    cout << "Writing text:" << endl;
    editor.write("Hello");
    editor.write("Hello World");
    editor.write("Hello World!");
    
    cout << "\nUndo operations:" << endl;
    editor.undo();
    editor.undo();
    editor.undo();
    editor.undo();
    
    cout << "\nRedo operations:" << endl;
    editor.redo();
    editor.redo();
    
    cout << "\nWriting new text (clears redo):" << endl;
    editor.write("New text");
    editor.redo();
    
    return 0;
}