#include <bits/stdc++.h>
using namespace std;

//Notes: The program was created with version C++17.

class HashTable {
      private:
      struct Node {
        string Data;
        Node *Next;
        Node(string Data): Data(Data), Next(NULL) {}
      };
      Node **Table;
      size_t Size;
      unsigned long Hash(string str) {
        unsigned long hash = 5381;
        for (char c: str) 
          hash = ((hash << 5) + hash) + c;
        return hash%Size;
      }
      public:
      HashTable(size_t Size) {
        this->Size = Size;
        this->Table = new Node*[Size];
        memset(Table, NULL, sizeof(Table));
      }
      void Insert(string New) {
        unsigned long Key = Hash(New);
        Node *NewNode = new Node(New);
        if (this->Table[Key])
          NewNode->Next = this->Table[Key];
        this->Table[Key] = NewNode;
      }
      void Delete(string Target) {
        unsigned long Key = Hash(Target);
        if (!this->Table[Key]) return;
        Node *Prev = NULL;
        Node *Current = this->Table[Key];
        while (Current && Current->Data != Target) Prev = Current,
          Current = Current->Next;
        if (Current) {
          if (Prev) {
            Prev->Next = Current->Next;
          } else {
            this->Table[Key] = Current->Next;
          }
          delete Current;
        }
      }
      void Search(string Target) {
        unsigned long Key = Hash(Target);
        Node *Current = this->Table[Key];
        while (Current && Current->Data != Target) Current = Current->Next;
        if (Current) {
          cout << Target << " exists at index: " << Key << '\n';
        } else {
          cout << Target << " wasn't found!" << '\n';
        }
      }
      void View() {
        for (size_t i = 0;i < this->Size;i++) {
          cout << i << ": ";
          Node *Current = this->Table[i];
          while (Current && Current->Next) {
            cout << Current->Data << " | ";
            Current = Current->Next;
          }
          if (Current) cout << Current->Data;
          cout << '\n';
        }
      }
      ~HashTable() {
        for (size_t i = 0;i < this->Size;i++) {
          Node *Current = this->Table[i];
          while (Current) {
            Node *Temp = Current;
            Current = Current->Next;
            delete Temp;
          }
        }
        delete[] Table;
      }
};
 
int main() {
    // DECLARING HASH TABLE
    HashTable HT(578);
    // INSERT OPERATION
    HT.Insert("Serral");
    HT.Insert("Dark");
    HT.Insert("Rogue");
    HT.Insert("Reynor");
    HT.Insert("soO");
    HT.Insert("Solar");
    HT.Insert("Life");
    HT.Insert("Scarlett");
    HT.Insert("Snute");
    HT.Insert("Nerchio");
    // SEARCH OPERATION
    HT.Search("Solar");
    HT.Search("Serral");
    HT.Search("idrA");
    // VIEW BEFORE DELETE OPERATION
    HT.View();
    // DELETE OPERATION
    HT.Delete("Life");
    HT.Delete("Snute");
    HT.Delete("Rogue");
    // VIEW AFTER DELETE OPERATION
    HT.View();
    return 0;
}

//Notes: The program was created with version C++17.

/* DOCUMENTATION OF "HashTable"
  
  Declared with the syntax "HashTable [Identifier]([Size]);"
  Change [Identifier] to the name you wish the hash table to have.
  Change [Size] to the size you wish the hash table to have.
  
  void Insert(string New): Insert a new string into the hash table.
  void Delete(string Target): Delete one instance of the target from the hash table.
  void Search(string Target): Search for the target value and inform about its existence in the hash table.
  void View(): View every index of the hash table.

*/
