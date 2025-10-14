#include<iostream>
using namespace std;

class TrieNode
{
    public:
      char data;
      TrieNode *children[26];
      bool isterminal;

      //constructor
      TrieNode(char d)
      {
          data= d;
          for(int i=0;i<26;i++)
          {
            children[i]=NULL;
          }
          isterminal=false;
      }
};

class Trie
{
    public:
    TrieNode* root;

    //constructor
    Trie()
    { 
        root= new TrieNode('\0');    //creates a root node whose data is the null character; root isn't a real letter but a starting point
    }



    void insertUtil(TrieNode* root,string word)
    {
        //base case
        if(word.length()==0)
        {
           root->isterminal=true;
           return;
        }

        //assumption,word is in caps
        int index= word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL)
        {
            child= root->children[index];
        }
        else
        {
            child= new TrieNode(word[0]);
            root->children[index]= child ;
        }

        //recursion
        insertUtil(child,word.substr(1));

        // When inserting "CAT":
        // First call handles 'C'
        // Then recursively insert "AT" (remaining part)
        // Then recursively insert "T"
        // Then finally base case with empty string ""

    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    }




    bool searchUtil(TrieNode* root, string word)
    {
        //base case
        if(word.length()==0)
        {
            return root->isterminal;  //if isterminal is true then word is found
        }

        int index= word[0]-'A';
        TrieNode* child;

        if(root->children[index]!=NULL)   //present
        {
            child = root->children[index];
        }
        else   //not present
        {
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    bool search(string word)
    {
       return searchUtil(root,word);
    }




    bool removeword(TrieNode* root, string word)
    {
        //base case
        if(word.length()==0)
        {
            root->isterminal=false;  //if isterminal is true then word is found
            return true;    // successfully unmarked
        }

        int index= word[0]-'A';
        TrieNode* child =root->children[index];

        if (child == NULL)
            return false; // word not found

        bool deleted = removeword(child, word.substr(1));    

        // if child node became useless (no children + not terminal)
        bool hasChild = false;
        for (int i = 0; i < 26; i++) {
            if (child->children[i] != NULL) {
                hasChild = true;
                break;
            }
        }

        if (!hasChild && child->isterminal == false) {
            delete child;
            root->children[index] = NULL;
        }

        

        return deleted;
    }

    bool remove(string word)
    {
      return removeword(root,word);
    }

};



int main()
{
    Trie *t = new Trie();

    t->insertWord("CAT");
    t->insertWord("CAR");
    t->insertWord("COW");

    cout << "Before deletion:\n";
    cout << "CAT: " << t->search("CAT") << endl;
    cout << "CAR: " << t->search("CAR") << endl;
    cout << "COW: " << t->search("COW") << endl;

    t->remove("CAR");

    cout << "\nAfter deleting CAR:\n";
    cout << "CAT: " << t->search("CAT") << endl;
    cout << "CAR: " << t->search("CAR") << endl;
    cout << "COW: " << t->search("COW") << endl;

}