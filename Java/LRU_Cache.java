import java.util.LinkedHashMap;
import java.util.Map;

public class LRUCache {
    int cacheSize;
    LinkedHashMap<Integer, Integer> table;
    
    public LRUCache(int capacity) {
        cacheSize = capacity;
        table = new LinkedHashMap<Integer, Integer>(2 * capacity, .75f, true) {
            protected boolean removeEldestEntry(Map.Entry  eldest) {
                return size() >  cacheSize;
            };
        };
    }
    
    public int get(int key) {
        Integer val = table.get(key);
        
        if(val == null)
            val = -1;
        
        return val;
    }
    
    public void set(int key, int value) {
        table.put(key, value);
    }
}
