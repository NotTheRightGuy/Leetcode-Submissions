class LRUCache
{
    int capacity;
    list<pair<int, int>> cache;                           // Stores key-value pairs
    unordered_map<int, list<pair<int, int>>::iterator> m; // Maps keys to iterators of list entries

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        auto it = m.find(key);
        if (it == m.end())
            return -1;

        // Move the accessed item to the end (signifying recent use)
        cache.splice(cache.end(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = m.find(key);
        if (it != m.end())
        {
            // If the key exists, remove the old value from the list
            cache.erase(it->second);
        }
        else if (cache.size() == capacity)
        {
            // If the cache is at capacity, remove the least recently used item
            int key_to_remove = cache.front().first;
            cache.pop_front();
            m.erase(key_to_remove);
        }

        // Insert the new key-value pair to the end of the cache and update the map
        cache.push_back({key, value});
        m[key] = --cache.end(); // .end() gives iterator past the end, so decrement to get the actual last element
    }
};