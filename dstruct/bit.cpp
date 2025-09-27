

// point update, sum in range query
template <class T>
class FenwickTree{
private:
    int n;
    vector<T> bit;
public:
    FenwickTree(const vector<T> &s){
        this->n = (long long) s.size();
        bit.resize(n + 1);
        for (int i = 1; i <= n; i++){
            bit[i] += s[i - 1];
            int prop = i + (i & -i);
            if (prop <= n) bit[prop] += bit[i];
        }
    }

    // be careful if needs to update not sum
    T sum(int x){
        T ans = 0;
        for (; x > 0; x -= x & -x){
            ans += bit[x];
        }
        return ans;
    }


    T query(int l,int r){
        return sum(r) - sum(l - 1);   
    }

    void update(int x, T val){
            while(x <= n){
                bit[x] += val;
                x += x & -x;
            }
    }
};
