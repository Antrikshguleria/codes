#include <string>
using namespace std;
template <typename V>
class mapnode
{
public:
    string key;
    V value;
    mapnode *next;
    mapnode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapnode()
    {
        delete next;
    }
};
template <typename V>
class ourmap
{
    mapnode<V> **buckets;
    int count;
    int numbuckets;

    int getbucketindex(string key)
    {
        int hashcode = 0;
        int currentcoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currentcoeff;
            hashcode = hashcode % numbuckets;
            currentcoeff *= 37;
            currentcoeff = currentcoeff * numbuckets; //(n1*n2*n3*)%r = ((n1%r)*(n2%r)*(n3*r))%r
        }

        return hashcode % numbuckets;
    }

public:
    ourmap()
    {
        count = 0;
        numbuckets = 5;
        buckets = new mapnode<V> *[numbuckets];
        for (int i = 0; i < numbuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    void rehash()
    {
        mapnode<V> **temp = buckets;
        buckets = new mapnode<V> *[2 * numbuckets];
        for (int i = 0; i < 2 * numbuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldbucketcount = numbuckets;
        numbuckets *= 2;
        count = 0;
        for (int i = 0; i < oldbucketcount; i++)
        {
            mapnode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldbucketcount; i++)
        {
            mapnode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

    void insert(string key, V value)
    {
        int bucketindex = getbucketindex(key);
        mapnode<V> *head = buckets[bucketindex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketindex];
        mapnode<V> *node = new mapnode<V>(key, value);
        node->next = head;
        buckets[bucketindex] = node;
        count++;
        double loadfactor = (1.0 * count) / numbuckets;
        if (loadfactor > 0.7)
        {
            rehash();
        }
    }
    V getvalue(string key)
    {
        int bucketindex = getbucketindex(key);
        mapnode<V> *head = buckets[bucketindex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    V remove(string key)
    {
        int bucketindex = getbucketindex(key);
        mapnode<V> *head = buckets[bucketindex];
        mapnode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketindex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};