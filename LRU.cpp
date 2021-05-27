#include<bits/stdc++.h>
using namespace std ;

class LRUCache {

    public  :
    int capacity;
    list<int>dq;
    unordered_map< int, pair< int,list<int>::iterator> > cache;

    LRUCache(int _capacity) {
        capacity=_capacity;
    }

    void remove(){
        int leastRecent = dq.back();
        cache.erase(leastRecent);
        dq.pop_back();
    }

    void update(int key , int value){
        if(cache.count(key) > 0){
            dq.erase(cache[key].second);
        }
        dq.push_front(key);
        cache[key].first = value;
        cache[key].second = dq.begin();
    }

    int get(int key){
        if(cache.count(key) > 0){
            update(key,cache[key].first);
            return cache[key].first;
        }
            
        else{
            return -1;
        }
    }

    void put(int key , int value){
        if(cache.size() == capacity  && cache.find[key] == cache.end()){
            remove();
        }

        update(key,value);
    }
};

int main() {
    LRUCache  *c = new LRUCache(2);
    c->put(1,1);
    c->put(2,2);
    cout<<c->get(1)<<endl;
    // cout<<c->get(21)<<endl;
    c->put(3,3);
    cout<<c->get(2)<<endl;
    // c->put(3,3);
    // c->put(3,5);
    // cout<<c->get(3)<<endl;
}
