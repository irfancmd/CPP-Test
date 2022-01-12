#include <bits/stdc++.h>

using namespace std;

int main() {
    /* Unlike Java, C++ int capacity can vary form one
    architecture to another.
    So, It's safe to use long long instead of int. long grantees 64 bits. */
    long long l, c, n;

    cin >> l >> c >> n;

    // Array class adds extra functionality over C-style arrays
    array<long long, 100001> count{};
    count.fill(0);

    set<pair<pair<long long, long long>, long long>> master;

    master.insert(make_pair(make_pair(0, l - 1), 1));
    count[1] = l;

    for (int i = 0; i < n; i++) {
        long long p, x;
        long long a, b;

        cin >> p >> x >> a >> b;

        long long s = count[p];

        long long m1 = (a + s * s) % l;
        long long m2 = (a + (s + b) * (s + b)) % l;

        if (m1 > m2) {
            long long tmp = m1;
            m1 = m2;
            m2 = tmp;
        }

//        cout << "M1 " << m1 << " M2 " << m2 << endl;

        auto it = master.lower_bound(make_pair(make_pair(m1 + 1, 0), 0));
        it--;

        vector<pair<pair<long long, long long>, long long>> insert, remove;

        while (it != master.end()) {
            // check see if we're out of valid range
            if (it->first.first > m2) {
                break;
            }

            // remove the count for current pair since it's being examined.
            count[it->second] -= ((it->first.second - it->first.first) + 1);

            /* check for this type of situation
             * current pair:    ---------
             * requested range:     ---------
             * */

            if (it->first.first < m1) {
                insert.push_back(make_pair(make_pair(it->first.first, m1 - 1), it->second));
                count[it->second] += (((m1 - 1) - it->first.first) + 1);
            }

            /* check for this type of situation
             * current pair:        ---------
             * requested range: ---------
             * */

            if (it->first.second > m2) {
                insert.push_back(make_pair(make_pair(m2 + 1, it->first.second), it->second));
                count[it->second] += ((it->first.second - (m2 + 1)) + 1);
            }

            remove.push_back(*it);

            count[x] += (min(it->first.second, m2) - max(it->first.first, m1) + 1);

            it++;
        }

        for (auto item : remove) {
            master.erase(item);
        }

        for (auto item : insert) {
            master.insert(item);
        }

        master.insert(make_pair(make_pair(m1, m2), x));
    }

    long long *max = max_element(count.begin(), count.end());
    cout << *max << endl;

    return 0;
}


