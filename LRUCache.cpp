struct Node{
    int val;
    int key;
    Node *next;
    Node *prev;
    Node(int _key,int _val):key(_key),val(_val),next(NULL),prev(NULL){}
};
class LRUCache{
public:
    map<int,Node*> dict;
    int cap;
    int size;
    Node *head,*tail;
    LRUCache(int capacity) {
        dict.clear();
        cap=capacity;
        size=0;
        head=NULL,tail=NULL;
    }
    
    int get(int key) {
        if(dict.find(key)==dict.end()) return -1;
        Node *p=dict[key];
        if(p==head) return p->val;
        if(p==tail) tail=p->prev,head=p;
        else{
            p->prev->next=p->next;
            p->next->prev=p->prev;
            p->next=head;
            p->prev=tail;
            tail->next=p;
            head->prev=p;
            head=p;
        }
        return p->val;
    }
    
    void set(int key, int value) {
        if(dict.find(key)==dict.end()){
            //insert
            Node *p=new Node(key,value);
            if(head==NULL && tail==NULL){
                head=tail=p;
                
            }
            p->next=head;
            p->prev=tail;
            
            
            tail->next=p;
            head->prev=p;
            head=p;
            size++;
            dict[key]=p;
            if(size>cap){
                tail->prev->next=head;
                tail->next->prev=tail->prev;
                Node *t=tail;
                tail=tail->prev;
                dict.erase(t->key);
                delete t;
                size--;
            }
            
        }else
        {
            //move to head
            Node *p=dict[key];
            p->val=value;
            if(p==head) return;
            if(p==tail) tail=p->prev,head=p;
            else{
                p->prev->next=p->next;
                p->next->prev=p->prev;
                p->next=head;
                p->prev=tail;
                tail->next=p;
                head->prev=p;
                head=p;
            }
        }
    }
};
