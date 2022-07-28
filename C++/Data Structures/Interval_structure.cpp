
struct range_maintainance {

    set<pair<int, int>>s;
    void fill_range(int x, int y) {
        auto it = s.upper_bound({x, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= x) {
                // merge with [x,y]
                x = it->ff;
                y = max(y, it->ss);
                s.erase(it);

            }
        }
        it = s.upper_bound({y, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= y) {
                // merge with [x,y]
                y = it->ss;
                x = min(x, it->ff);
                s.erase(it);

            }
        }
        while (1) {
            it = s.lower_bound({x, -1e9});
            if (it == s.end() || (it->ff >= y))
                break;
            s.erase(it);
        }
        s.insert(x,y);

    }
    void clear_range(int x, int y)
    {
        auto it = s.upper_bound({x, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= y) {
                ll lo1 = it->ff;
                ll hi1 = x;


                ll lo2 = y;
                ll hi2 = it->ss;

                s.erase(it);
                s.insert({lo1, hi1});
                s.insert({lo2, hi2});
                return;
            }
            if (it->ss >= x) {

                ll lo = it->ff;
                ll hi = x;
                s.erase(it);
                s.insert({lo, hi});

            }
        }
        it = s.upper_bound({y, 1e9});
        if (it != s.begin()) {
            it--;
            if (it->ss >= y) {
                // merge with [x,y]

                ll lo = y;
                ll hi = it->ss;
                s.erase(it);
                s.insert({lo, hi});
            }
        }
        while (1) {
            it = s.lower_bound({x, -1e9});
            if (it == s.end() || (it->ff >= y))
                break;
            s.erase(it);
        }
    }
    bool check_point(int x) {
        auto it = s.upper_bound({x, 1e9});
        if (it == s.begin()) {
            return 0;
        }
        it--;
        return it->ss >= x;
    }
    bool check_range_any(int x, int y) {
        auto it = s.upper_bound({x, 1e9});
        if (it != s.end()) {
            if (it->first <= y) {
                return 1;
            }
        }
        return check_point(x);

    }
    bool check_range_all(int x, int y) {
        auto it = s.upper_bound({x, 1e9});
        if (it == s.begin()) {
            return 0;
        }
        it--;
        return it->ss >= y;
    }
    void print_status()
    {
        for (auto i : s) {
            cout << i.ff << " " << i.ss << ',';
        }
        cout<<'\n';

    }
};
