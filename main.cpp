#include <iostream>
#include <cassert>
#include <vector>

const int RUNNING = 0;
const int REVERSE = 1;
const int POINTSELF = 2;

struct Node {
    Node *next;
};

Node *get_linked_list(int m, int n) {
    Node *lst = new Node();
    Node *curr = lst;
    Node *cycle = nullptr;
    for (int i = 0; i < m + n; ++i) {
        if (i == m) cycle = curr;
        curr->next = new Node();
        if (i < m + n - 1) curr = curr->next;
    }
    curr->next = cycle;
    return lst;
}

void delete_linked_list(Node *lst, int m, int n) {
    Node *curr = lst;
    for (int i = 0; i < m + n; ++i) {
        Node *prev = curr;
        curr = curr->next;
        delete prev;
    }
}

bool has_cycle_running(Node *lst) {
    Node *fast = lst;
    Node *slow = lst;
    while (true) {
        fast = fast->next;
        if (fast == nullptr) return false;
        if (fast == slow) return true;
        fast = fast->next;
        if (fast == nullptr) return false;
        if (fast == slow) return true;
        slow = slow->next;
        if (fast == slow) return true;
    }
}

bool reverse(Node *lst, Node **tail) {
    Node *prev = nullptr;
    Node *curr = lst;
    while (curr != nullptr) {
        Node *temp = curr->next;
        curr->next = prev;
        *tail = prev = curr;
        curr = temp;
        if (curr == lst) {
            curr->next = prev;
            return true;
        }
    }
    return false;
}

bool has_cycle_reverse(Node *lst) {
    Node *tail = nullptr;
    bool result = reverse(lst, &tail);
    if (result) reverse(lst, &tail);
    else reverse(tail, &tail);
    return result;
}

bool has_cycle_pointself(Node* lst) {
    bool result = false;
    Node *curr = lst;
    std::vector<Node *> visited;
    while (curr != nullptr) {
        if (curr->next == curr) {
            result = true;
            break;
        }
        visited.push_back(curr);
        Node *temp = curr->next;
        curr->next = curr;
        curr = temp;
    }
    for (Node *n : visited) delete n;
    return result;
}

int main(int argc, char **argv) {
    int method = std::stoi(argv[1]);
    int m = std::stoi(argv[2]);
    int n = std::stoi(argv[3]);
    m = m - n;
    Node *lst = get_linked_list(m, n);
    bool r;
    if (method == RUNNING) {
        r = has_cycle_running(lst);
    } else if (method == REVERSE) {
        r = has_cycle_reverse(lst);       
    } else { // POINTSELF
        Node *lst2 = get_linked_list(m, n);
        r = has_cycle_pointself(lst2);
    }
    if (n == 0) assert(r == false);
    else assert(r == true);
    delete_linked_list(lst, m, n);
    return 0;
}
