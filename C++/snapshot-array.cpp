class SnapshotArray {
int m_snap;
    unordered_map<int, map<int,int>> m_vector;
public:
    SnapshotArray(int length) : m_snap(0) {
        m_vector = unordered_map<int, map<int,int>>(length);
    }
    
    void set(int index, int val) {
        m_vector[index][-m_snap] = val;
    }
    
    int snap() {
        return m_snap++;
    }
    
    int get(int index, int snap_id) {
        return m_vector.count(index) ? m_vector[index].lower_bound(-snap_id)->second : 0;
    }
};
