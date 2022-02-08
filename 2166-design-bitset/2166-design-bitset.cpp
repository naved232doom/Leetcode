class Bitset {
public:
    vector<int> B;
    int set_bit_counts, total_bits, unset_bit_counts;
    int parity = 0;
    Bitset(int size) {
        B.assign(size, 0);
        set_bit_counts = 0;
        unset_bit_counts = size;
        total_bits = size;
    }

    void fix(int idx) {
        if (parity) {
            if (B[idx] != 0) {
                set_bit_counts++;
                unset_bit_counts--;
            }
            B[idx] = 0;
        }
        else {
            if (B[idx] != 1) {
                set_bit_counts++;
                unset_bit_counts--;
            }
            B[idx] = 1;
        }
    }

    void unfix(int idx) {
        if (parity) {

            if (B[idx] != 1) {
                set_bit_counts--;
                unset_bit_counts++;
            }
            B[idx] = 1;
        }
        else {
            if (B[idx] != 0) {
                unset_bit_counts++;
                set_bit_counts--;

            }
            B[idx] = 0;
        }
    }

    void flip() {
        parity ^= 1;
        swap(set_bit_counts, unset_bit_counts);
    }

    bool all() {
        return set_bit_counts == total_bits;
    }

    bool one() {
        return set_bit_counts > 0 ;
    }

    int count() {
        return set_bit_counts;
    }

    string toString() {
        string ans = "";
        for (int i = 0; i < total_bits; ++i) ans += (to_string((B[i])^parity));
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */