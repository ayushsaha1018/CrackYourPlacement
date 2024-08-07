class twoStacks {
  public:
    vector<int> s1;
    vector<int> s2;
    twoStacks() {}

    // Function to push an integer into the stack1.
    void push1(int x) {
        s1.push_back(x);
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        s2.push_back(x);
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(s1.empty())
            return -1;
        int x = s1.back();
        s1.pop_back();
        return x;
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(s2.empty())
            return -1;
        int x = s2.back();
        s2.pop_back();
        return x;
    }
};