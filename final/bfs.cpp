#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

namespace std{
    template<typename T, size_t N>
    struct hash<array<T, N> >
    {
        typedef array<T, N> argument_type;
        typedef size_t result_type;

        result_type operator()(const argument_type& a) const
        {
            hash<T> hasher;
            result_type h = 0;
            for (result_type i = 0; i < N; ++i)
            {
                h = h * 31 + hasher(a[i]);
            }
            return h;
        }
    };
}

class Node{
public:
    Node(std::array<int, 9> status) {
        for (int i = 0; i < 9; ++i) {
            this->status[i] = status[i];
            if(status[i] == 0){
                zero_index = i;
            }
        }
    }
    Node* prev = nullptr;
    std::vector<std::array<int, 9>> history() const;
    std::array<int, 9> status{};

    bool equals(std::array<int, 9> target) const{
        return status == target;
    }

    bool equals(Node node) const{
        return status == node.status;
    }

     static void printStatus(std::array<int, 9> arr){
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i];
            if (i%3 == 2){
                std::cout << "\n";
            }else{
                std::cout << " ";
            }
        }
    }

    void printStatus() const{
        printStatus(status);
    }
    Node* moveLeft(){
        int col = zero_index % 3;
        if (col != 0){
            std::array<int, 9> arr(status);
            std::swap(arr.at(zero_index), arr.at(zero_index-1));
            Node* n = new Node(arr);
            n->prev = this;
            return n;
        }
        return nullptr;
    }
    Node* moveRight(){
        int col = zero_index % 3;
        if (col != 2){
            std::array<int, 9> arr(status);
            std::swap(arr.at(zero_index), arr.at(zero_index+1));
            Node* n = new Node(arr);
            n->prev = this;
            return n;
        }
        return nullptr;
    }
    Node* moveTop(){
        int row = zero_index / 3;
        if (row != 0){
            std::array<int, 9> arr(status);
            std::swap(arr.at(zero_index), arr.at(zero_index-3));
            Node* n = new Node(arr);
            n->prev = this;
            return n;
        }
        return nullptr;
    }

    Node* moveBottom(){
        int row = zero_index / 3;
        if (row != 2){
            std::array<int, 9> arr(status);
            std::swap(arr.at(zero_index), arr.at(zero_index+3));
            Node* n = new Node(arr);
            n->prev = this;
            return n;
        }
        return nullptr;
    }
private:
    int zero_index = -1;
};

std::vector<std::array<int, 9>> Node::history() const {
    std::vector<std::array<int, 9>> h;
    h.push_back(status);
    Node* n = prev;
    while (n != nullptr){
        h.push_back(n->status);
        n = n->prev;
    }
    std::reverse(h.begin(), h.end());
    return h;
}

int main()
{
    std::array<int, 9> init{};
    std::array<int, 9> target{};
    for (int &i : init) {
        std::cin >> i;
    }
    for (int &i : target) {
        std::cin >> i;
    }
    std::queue<Node*> q;
    std::unordered_set<std::array<int, 9>> explored;
    q.emplace(new Node(init));
    explored.emplace(init);
    while (!q.empty()){
        Node* n = q.front();
        q.pop();
        n->printStatus();
        if (n->equals(target)){
//            std::cout << "===========\n";
//            auto history = n->history();
//            std::for_each(history.begin(), history.end(), [](auto item){Node::printStatus(item);});
            break;
        }
        Node* top = n->moveTop();
        Node* right = n->moveRight();
        Node* bottom = n->moveBottom();
        Node* left = n->moveLeft();
        if (top != nullptr && explored.find(top->status) == explored.end()){
            explored.emplace(top->status);
            q.emplace(top);
        }
        if (right != nullptr && explored.find(right->status) == explored.end()){
            explored.emplace(right->status);
            q.emplace(right);
        }
        if (bottom != nullptr && explored.find(bottom->status) == explored.end()){
            explored.emplace(bottom->status);
            q.emplace(bottom);
        }
        if (left != nullptr && explored.find(left->status) == explored.end()){
            explored.emplace(left->status);
            q.emplace(left);
        }
    }
    return 0;
}
