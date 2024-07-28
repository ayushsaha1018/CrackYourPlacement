// TC : O(n+m), SC : O(1)

class solution {
  public:
    const long long mod = 1e9 + 7;
    int countDigit(long long n) { return floor(log10(n) + 1); }
    long long multiplyTwoLists(Node *first, Node *second) {
        long long num1 = 0, num2 = 0;
        while(first != NULL){
            num1 = ((num1 * 10) % mod + (first->data) % mod) % mod;
            first = first -> next;
        }
        while(second != NULL){
             num2 = ((num2 * 10) % mod + second->data % mod) % mod;
            second = second -> next;
        }
        
        return (num1 % mod * num2 % mod) % mod;
    }
};