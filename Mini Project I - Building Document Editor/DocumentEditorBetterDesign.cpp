#include <bits/stdc++.h>
using namespace std;

// Abstract Class
class DocumentElement 
{
    public:
        virtual string render() = 0;
};

class TextElement : public DocumentElement 
{
    private:
        string text;
    public:
        TextElement(string text)
        {
            this->text = text;
        }
        string render() override
        {
            return text;
        }    
};

class ImageElement : public DocumentElement 
{
     private:
        string imagePath;
    public:
        ImageElement(string imagePath)
        {
            this->imagePath = imagePath;
        }
        string render() override
        {
            return "[Image:" + imagePath + "]";
        }    
};

// class responsible for holding collection of elements
class Document 
{
    public:
        vector<DocumentElement*> elements;

        void addElements(DocumentElement* ele)
        {
            elements.push_back(ele);
        }

        string render()
        {
            string result;
            for(auto it: elements)
            {
                result += it->render();
            }
            return result;
        }
};

// Persistance Interface 
class Persistance
{
    public:
        virtual void save(string data) = 0;
};

class SaveToFile : public Persistance
{
    public:
        // function to save document to the file
        void save(string data) override
        {
            ofstream outFile("document.txt");
            if(outFile)
            {
                outFile << data;
                outFile.close();
            }
            else
            {
                cout<<"Errorr in opening file" <<endl;
            }
        }
};

class SaveTDB : public Persistance
{
    public:
        // function to save document to the Database
        void save(string data) override
        {
            // save to the database 
        }
};

class DocumentEditor 
{
    private:
        Document* doc;
        Persistance* ps;
        string renderedDocument;

    public:
        DocumentEditor(Document* doc, Persistance* ps)
        {
            this->doc = doc;
            this->ps = ps;
        }

        void addText(string text)
        {
            doc->addElements(new TextElement(text));
        }

        void addImage(string path)
        {
            doc->addElements(new ImageElement(path));
        }

        string renderDocument()
        {
            if(renderedDocument.empty())
            {
                renderedDocument = doc->render();
            }
            return renderedDocument;
        }

        void save()
        {
           ps->save(renderedDocument);
        }

};

// Client usage example
int main()
{
    Document* document = new Document();
    Persistance* persistance = new SaveToFile();

    DocumentEditor* editor = new DocumentEditor(document, persistance);

    editor->addText("Hello World !");
    editor->addImage("image.jpg");
    editor->addText("This is another text");

    // render and display the final document
    cout<< editor->renderDocument() << endl;

    editor->save();
}