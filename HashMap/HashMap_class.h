#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    string key;
    T value;
    Node<T> *next;
    // next is a pointer to another node

    // constructor
    Node(string k, T val)
    {
        key = k;
        value = val;
        next = NULL;
    }

    // destructor
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

template <typename T>
class HashMap
{
    Node<T> **table;
    int table_size;
    int current_size;

    int hashFn(string key)
    {
        int idx = 0;
        int p = 1;

        for (int j = 0; j < key.length(); j++)
        {
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }

        return idx;
    }

    void rehash()
    {
        Node<T> **oldTable = table;
        // changing the pointer of the existing table

        // assigning the "table" pointer to a newly created
        // table of double size;

        int oldTableSize = table_size;
        table_size = 2 * table_size;
        // Although we are not doing it here, in reality,
        // you set the table size as the next prime number greater than
        // 2*tableSize

        table = new Node<T> *[table_size];
        current_size = 0;
        // since, we are re-inserting all the nodes
        // the current size becomes 0 again and will
        // increase as we insert into the new Table

        // initializing the array with NULL entries
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }

        for (int i = 0; i < oldTableSize; i++)
        {
            Node<T> *temp = oldTable[i];

            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
            // this calls the destructor of the Node class
            // which will actually recursively delete all the nodes of that
            // particular LL
        }

        // After all the LL's are deleted,
        // we also delete the array OldTable

        delete[] oldTable;
    }

public:
    HashMap(int ts = 7)
    {
        table_size = ts;
        current_size = 0;

        table = new Node<T> *[table_size];
        // creating an array table of pointers of size ts

        // initialize the array with NULL pointers
        for (int i = 0; i < table_size; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, T val)
    {
        int idx = hashFn(key);

        // creating a new node
        Node<T> *n = new Node<T>(key, val);

        n->next = table[idx];
        table[idx] = n;

        current_size++;

        //Rehashing
        float load_factor = current_size / (1.0 * table_size);
        if (load_factor > 0.7)
        {
            rehash();
        }
    }

    void print()
    {
        for (int i = 0; i < table_size; i++)
        {
            Node<T> *temp = table[i];
            cout << "Idx " << i << ": ";
            while (temp != NULL)
            {
                cout << temp->key << "->";
                temp = temp->next;
            }

            cout << endl;
        }
    }
    void erase(string key)
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        if (temp->key == key)
        {
            table[idx] = temp->next;
            return;
        }
        while (temp->next != NULL)
        {
            if (temp->next->key == key)
            {
                temp->next = temp->next->next;
                return;
            }

            temp = temp->next;
        }

        cout<<"Said element doesn't exist"<<endl;
    }

    T *search(string key) // Return type is T*
    {
        int idx = hashFn(key);
        Node<T> *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
                // key found
                // return the address of its req value
            }

            temp = temp->next;
        }

        return NULL;
        // not present, return NULL
    }

    //operator overloading for[] to enable easy access to the key value pair
    //the following should work after that

    //menu["Dosa"]=60;
    //menu["Dosa"]+=20;
    //etc...


    //return type is the value of the node returned as reference
    //Bcoz we would want to change the same

    T& operator [] (string key){
        auto it=search(key);

        //if already present in the HashMap
        if(it!=NULL){
            return *it;
            //return the value container
            //since the it is a pointer,...
            //to pass the value, we need to
            // do *it.
        }

        //if key already not present
        else{
            T garbage;
            insert(key,garbage);
            auto it=search(key);
            return *it;
        }
    }


};
