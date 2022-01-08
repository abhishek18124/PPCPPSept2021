/*

	Implementation of HashTable

*/

#include<iostream>

using namespace std;

template <typename T1, typename T2>
class node {

public:
	T1 key;
	T2 value;
	node<T1, T2>* next;

	node(T1 key, T2 value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T1, typename T2>
class HashTable {
	int M; // to store the capacity of the hash table
	int N; // to store the size of the hash table i.e. no. of (key, value) pairs inside the HT
	double LFT; // to store load factor threshold
	node<T1, T2>** table; // to store reference of dynamically created internal array

	int hash_fn(T1 key) {
		return key%M;
	}

	void transfer(node<T1, T2>* head) {
		node<T1, T2>* temp = head;
		while(temp) {
			insert(temp->key, temp->value);
			temp = temp->next;
		}

		while(head) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void rehash() {
		int oldM = M;
		node<T1, T2>** oldTable = table;

		// 1. create a new array of double capacity

		M = 2*M;
		table = new node<T1, T2>*[M];
		for(int i=0; i<M; i++) {
			table[i] = NULL;
		}
		N = 0;

		// 2. transfer the content of old array into new array
		for(int i=0; i<oldM; i++) {
			transfer(oldTable[i]);
		}

		// 3. delete the old array
		delete [] oldTable;
	}

	public :

		HashTable(int M=5, double LFT=0.7) {
			this->M = M;
			this->LFT = LFT;
			this->N = 0;
			table = new node<T1, T2>*[M];
			for(int i=0; i<M; i++) {
				table[i] = NULL;
			}
		}

		void insert(T1 key, T2 value) {
			// 1. compute the hash index
			int hash_idx = hash_fn(key);

			// 2. insert the (key, value) at the head of the LL at the hash index
			node<T1, T2>* n = new node<T1, T2>(key, value);
			n->next = table[hash_idx];
			table[hash_idx] = n;

			N++;

			// 3. rehash, if load factor exceeds the load factor threshold
			double LF = (N*1.0)/M;
			if(LF > LFT) {
				cout << "LF : " << LF << " rehasing..." << endl;
				rehash();
			}

		}

		node<T1, T2>* find(T1 key) {
			// 1. compute the hash index
			int hash_idx = hash_fn(key);

			// 2. traverse the linked list at hash_idx and check if there exists
			// a node whose key matches the key given here
			node<T1, T2>* temp = table[hash_idx];
			while(temp && temp->key != key) {
				temp = temp->next;
			}
			return temp;
		}

		void erase(T1 key) {
			// 1. compute the hash index
			int hash_idx = hash_fn(key);

			// 2. delete the node with the given key, if present, from the linked 
			// list present at the hash index
			node<T1, T2>* temp = table[hash_idx];
			if(temp && temp->key == key) {
				// delete the head node of the linked list at the hash index
				table[hash_idx] = temp->next;
				delete temp;
				N--;
			} else {
				node<T1, T2>* prev = NULL;
				while(temp) {
					if(temp->key == key) {
						prev->next = temp->next;
						delete temp;
						N--;
						break;
					}
					prev = temp;
					temp = temp->next;
				}
			}
		}

		void printLinkedList(node<T1, T2>* head) {
			while(head) {
				cout << "(" << head->key << ", " << head->value << ")";
				head = head->next;
				if(head) cout << "->";
			}
			cout << endl;
		}

		void print() {
			for(int i=0; i<M; i++) {
				cout << i << " : ";
				printLinkedList(table[i]);
			}
			cout << endl;
		}

		T2& operator[](T1 key) {
			node<T1, T2>* n = find(key);
			if(!n) {
				T2 garbage;
				insert(key, garbage);
				n = find(key);
			}
			return n->value;
		}
};


int main() {

	HashTable<int, int> hashTable;

	hashTable.insert(0, 0);
	hashTable.insert(1, 1);
	hashTable.insert(10, 100);
	hashTable.print();

	hashTable.insert(11, 121);
	hashTable.print();

	// hashTable.insert(2, 4);
	// hashTable.insert(3, 9);
	// hashTable.insert(13, 169);
	// hashTable.insert(4, 16);

	// hashTable.print();

	// node<int, int>* node = hashTable.find(13);
	// node ? cout << "(" << node->key << ", " << node->value << ")" << endl :
	// 	   cout << "not found!" << endl;

 //    hashTable.erase(13);

 //    hashTable.print();
	
	// node = hashTable.find(13);
	// node ? cout << "(" << node->key << ", " << node->value << ")" << endl :
	// 	   cout << "not found!" << endl;

	hashTable[12] = 0;
	hashTable.print();

	hashTable[12] = 144;
	hashTable.print();

	return 0;
	
}







