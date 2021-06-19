#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include <cmath>

const int Max_Distance = 1e9+5;

struct HeapNode{
    int element, key;
    HeapNode():element(0),key(0){};
    HeapNode(int node, int key):element(node), key(key){};
};

class BinaryHeap{
private:
    std::vector<HeapNode> heap;
    static void swap(struct HeapNode &n1, struct HeapNode &n2);
    int findPosition(int node);
    static int getParentNode(int node){return std::floor(node / 2);};
public:
    BinaryHeap(){
        heap.resize(1);
    }
    BinaryHeap(int n){
        heap.resize(n + 1);
    }
    bool isHeapEmpty(){return (heap.empty());};
    void minHeapify(int node, int length);
    void buildMinHeap(std::vector<int> array);
    void decreaseKey(int node, int newKey);
    void minHeapInsert(int node, int key);
    int minimum();
    int extractMin();
};

void BinaryHeap::minHeapify(int node, int length){
    int left = 2*node;
    int right = 2*node + 1;
    int smallest;

    if (left <= length && heap[left].key < heap[node].key){
        smallest = left;
    }else{
        smallest = node;
    }
    if (right <= length && heap[right].key < heap[smallest].key)
        smallest = right;

    if (smallest != node) {
        swap(heap[smallest], heap[node]);
        minHeapify(smallest, length);
    }
}
void BinaryHeap::buildMinHeap(std::vector<int> array){
    for (int i = 0; i < array.size(); i++) {
        heap[i + 1].element = i;
        heap[i + 1].key = array[i];
    }
    for (int i = (int)heap.size()/2; i >= 1 ; i--) {
        minHeapify(i, (int) heap.size() - 1);
    }
}
void BinaryHeap::swap(struct HeapNode &n1, struct HeapNode &n2){
    struct HeapNode temp = n1;
    n1 = n2;
    n2 = temp;
}
int BinaryHeap::findPosition(int node){

    int idx = 0;
    for (int i = 1; i < heap.size(); i++) {
        if (heap[i].element == node) {
            idx = i;
        }
    }
    return idx;
}
int BinaryHeap::minimum(){
    return heap[1].element;
}
int BinaryHeap::extractMin(){
    if (isHeapEmpty()) {
        std::cout << "error: heap is empty\n";
        exit(-1);
    }
    int min = heap[1].element;
    heap[1] = heap[heap.size()-1];
    heap.erase(heap.begin() + heap.size()-1);
    minHeapify(1, (int) heap.size());
    return min;
}
void BinaryHeap::decreaseKey(int node, int newKey){
    int index_node = findPosition(node);
    if (newKey > heap[index_node].key){
        return;
    }
    heap[index_node].key = newKey;
    while (index_node > 1 && heap[getParentNode(index_node)].key > heap[index_node].key) {
        swap(heap[index_node], heap[getParentNode(index_node)]);
        index_node = getParentNode(index_node);
    }
}
void BinaryHeap::minHeapInsert(int node, int key){
    heap.emplace_back(node,key);
    decreaseKey(node, key);
}

class Dijkstra {
private:
    int num_vertex;
    std::vector<std::list<std::pair<int,int>>> AdjList;
    std::vector<int> predecessor, distance;
    std::vector<bool> visited;
public:
    Dijkstra(int n):num_vertex(n){
        AdjList.resize(num_vertex);
    }
    void addEdge(int from, int to, int weight);
    void printArray(std::vector<int> array) const;
    void initializeSource(int Start);
    void relax(int X, int Y, int weight);
    int solve(int Start, int target);
};

int Dijkstra::solve(int Start, int target){
    initializeSource(Start);
    BinaryHeap minQueue(num_vertex);
    minQueue.buildMinHeap(distance);
    visited.resize(num_vertex, false);
    while (!minQueue.isHeapEmpty()) {
        int u = minQueue.extractMin();
        for (auto itr = AdjList[u].begin();
             itr != AdjList[u].end(); itr++) {
            relax(u, (*itr).first, (*itr).second);
            minQueue.decreaseKey((*itr).first, distance[(*itr).first]);
        }
    }
//    std::cout << "\nprint predecessor:\n";
//    printArray(predecessor);
//    std::cout << "\nprint distance:\n";
//    printArray(distance);
    return distance[target];
}
void Dijkstra::initializeSource(int Start){
    distance.resize(num_vertex);
    predecessor.resize(num_vertex);
    for (int i = 0; i < num_vertex; i++) {
        distance[i] = Max_Distance;
        predecessor[i] = -1;
    }
    distance[Start] = 0;
}
void Dijkstra::relax(int X, int Y, int weight){

    if (distance[Y] > distance[X] + weight) {
        distance[Y] = distance[X] + weight;
        predecessor[Y] = X;
    }
}
void Dijkstra::addEdge(int from, int to, int weight){
    AdjList[from].push_back(std::make_pair(to,weight));
}
void Dijkstra::printArray(std::vector<int> array) const{
    for (int i = 0; i < num_vertex; i++)
        std::cout << std::setw(4) << i;
    std::cout << std::endl;
    for (int i = 0; i < num_vertex; i++)
        std::cout << std::setw(4) << array[i];
    std::cout << std::endl;
}

int main()
{
    char s, t;
    std::cin >> s >> t;
    int source, target;
    source = s - 'a';
    target = t - 'a';
    auto d = Dijkstra(52);
    int e, weight, a, b;
    std::cin >> e;
    for (int i = 0; i < e; i++){
        std::cin >> s >> t >> weight;
        a = s - 'a';
        b = t - 'a';
        d.addEdge(a, b, weight);
    }
    std::cout << d.solve(source, target) << "\n";
    return 0;
}
