/*
What will this code print out?

```
def make_functions():
    flist = []

    for i in [1, 2, 3]:
        def print_i():
            print(i)
        flist.append(print_i)

    return flist

functions = make_functions()
for f in functions:
    f()
```

How can we make it print out what we apparently want?
*/

#include <bits/stdc++.h>
using namespace std;

vector<function<void()>> make_functions() {
    vector<function<void()>> flist;

    for (int i : {1, 2, 3}) {
        flist.push_back([&]() { cout << i << endl; });  // Output: 3 3 3
        // flist.push_back([i]() { cout << i << endl; });   // Output: 1 2 3
    }

    return flist;
}

int main() {
    auto functions = make_functions();
    for (auto& f : functions) {
        f();
    }
    return 0;
}
