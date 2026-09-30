#include <bits/stdc++.h>
using namespace std;

class DocumentEditor {
    private:
        vector<string> elements;
        string renderedDocument;

    public:
        // adds text as a plain text
        void addText(string text)
        {
            elements.push_back(text);
        }

        // adds am imgae represented by its file path
        void addImage(string path)
        {
            elements.push_back(path);
        }

        // renders the document by checking the type of each element
        string rendereDocument()
        {
            if(renderedDocument.empty())
            {   
                string result;
                for(auto &it: elements)
                {
                    if(it.size() > 4 && (it.substr(it.size() - 4) == ".jpg" || it.substr(it.size() - 4) == ".png"))
                    {
                        result += "[Image: "+ it + "]" + "\n";
                    }
                    else
                    {
                        result += it + "\n";
                    }
                }
                renderedDocument += result;
            }
            return renderedDocument;
        }

        // saves the content of the doc to the DB or anything
        void saveToFile()
        {
            ofstream file("document.txt");
            if(file.is_open())
            {
                file << rendereDocument();
                file.close();
                cout<<"Document save to document.txt"<<endl;
            }
            else
            {
                cout<<"Unable to open a file"<<endl;
            }
        }

};

int main()
{
    DocumentEditor editor;
    editor.addText("Hello World!");
    editor.addImage("picture.png");
    editor.addText("This is some anothor text");

    cout<< editor.rendereDocument() << endl;

    editor.saveToFile();

    return 0;
}