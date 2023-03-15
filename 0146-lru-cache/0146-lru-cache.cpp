class LRUCache {
  public:
    //DS For DLL, such that it can store key and value both
    class node {
      public:
          int key;
          int val;
          node * next;
          node * prev;
          node(int _key, int _val) {
            key = _key;
            val = _val;
          }
    };
    
    // Maintaing head and tail, so that we don't have to look for NULL everytime we insert or delete  
    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    //for carrying capacity to PUT function
    int cap;  
    
    //for storing the key and their address in DLL
    //used to check  if key already exists, and also if we are overflowing by capacity
    unordered_map < int, node * > m;
    
    //Intially only 2 nodes in DLL, head's next to tail, tail's prev to head
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    //For adding the newNode to the just right of the head
    void addnode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    //For deleting the given node
    void deletenode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key_) {
        //If key is present in map
        if (m.find(key_) != m.end()) {
          //Store the address of key
          node * resnode = m[key_];
            
          //take the value associated to it
          int res = resnode -> val;
            
          //remove that key from map, as we will update the address of it in DLL
          m.erase(key_);
            
          //Since the given key is Most recently used we need to delete it from it's extising positon
          //and place it just right of head
          deletenode(resnode);
          addnode(resnode);
            
          //store the new address(which will head->next, as we are storing the newnode right of head) for the given key in the map
          m[key_] = head -> next;
            
          //return the value associated with it.
          return res;
        }
        
        //if NOT present return -1
        return -1;
    }

  void put(int key_, int value) {
      
      //If found the key in map, we need to update its val to given value
      //so just delete that node, as it will be most recently used
      //and erase the key from the map also, later we are gonna put it back
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
      //If we reached the capacity, we need to erase the LCU node, which will the last node,
      //i.e prev node of Tail
      //erase it from map also.
    if (m.size() == cap) {
      node* lruNode = tail->prev;
      m.erase(lruNode->key);
      deletenode(lruNode);
    }
      
      //Take the given key and value, make new node, add it to the immediate right of the head,
      //also add address for the given key.
    node* newNode = new node(key_,value);
    addnode(newNode);
    m[key_] = head -> next;
  }
};