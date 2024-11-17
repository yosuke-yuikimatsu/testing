#include <string>
#include <vector>
#include <iostream>

const int k = 95;

class Trie {
    int terminal_counter = 1;

    struct Vertex {
        Vertex* to[k] = {nullptr}, *go[k] = {nullptr};
        Vertex* link = nullptr, *p, *up = nullptr;
        int pch;
        int is_terminal = 0;
        Vertex(int _pch, Vertex* _p) : pch(_pch), p(_p) {}
    };
    Vertex* root = new Vertex(-1, nullptr);

    Vertex* link(Vertex* v) {
        if (!v->link) {
            if (v == root || v->p == root) {
                v->link = root;
            } else {
                v->link = go(link(v->p), v->pch);
            }
        }
        return v->link;
    }

    Vertex* go(Vertex* v, int c) {
        if (!v->go[c]) {
            if (v->to[c]) {
                v->go[c] = v->to[c];
            } else if (v == root) {
                v->go[c] = root;
            } else {
                v->go[c] = go(link(v), c);
            }
        }
        return v->go[c];
    }

    Vertex* comp(Vertex* v) {
        if (!v->up) {
            if (link(v)->is_terminal != 0) {
                v->up = link(v);
            } else if (link(v) == root) {
                v->up = root;
            } else {
                v->up = comp(link(v));
            }
        }
        return v->up;
    }

public:
    void add_string(const std::string& s) {
        Vertex* v = root;
        for (char _c : s) {
            int c = int(_c - 32);
            if (!v->to[c]) {
                v->to[c] = new Vertex(c, v);
            }
            v = v->to[c];
        }
        v->is_terminal = terminal_counter++;
    }

    void text_processing(const std::string& text) {
        Vertex* cur = root;
        Vertex* tmp;
        for (char c : text) {
            int idx = int(c - 32);
            cur = go(cur, idx);
            tmp = cur;
            while (tmp != root) {
                if (tmp->is_terminal != 0) {
                    std::cout << text << std::endl;
                    return;
                }
                tmp = link(tmp);
            }
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    Trie t;
    for (int i = 0; i < n; ++i) {
        std::string tmp;
        std::getline(std::cin, tmp);
        t.add_string(tmp);
    }

    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            t.text_processing(line);
        }
    }
}
