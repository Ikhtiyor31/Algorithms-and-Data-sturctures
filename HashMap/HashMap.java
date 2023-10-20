
class ListNode {
    int key;
    int value;
    ListNode next;
    public ListNode(int key, int value, ListNode next) {
        this.key = key;
        this.value = value;
        this.next = next;
    }
}
class MyHashMap {
     ListNode [] listNode;
    public MyHashMap() {
        listNode = new ListNode[10_000_000];
    }
    
    public void put(int key, int value) {
        int index = getIndex(key);
        if (listNode[index] == null) 
            listNode[index] = new ListNode(key, value, listNode[index]);
        ListNode prev = find(index, key);
        if (prev.next != null) 
            prev.next.value = value;
        else 
            prev.next = new ListNode(key, value, null);
    }
    
    public int get(int key) {
        int index = getIndex(key);
        if (listNode[index] == null)
            return -1;
        ListNode node = find(index, key);
        if (node.next != null)
            return node.next.value;
        return -1;
    }
    
    public void remove(int key) {
        int index = getIndex(key);
        if (listNode[index] == null)
            return;
        ListNode prev = find(index, key);
        if (prev.next != null)
            prev.next = prev.next.next;
    }

    public int getIndex(int key) {
        return Integer.hashCode(key)  % listNode.length;
    }

    public ListNode find(int index, int key) {
        ListNode prev = listNode[index];
        while(prev.next != null && prev.next.key != key)
            prev = prev.next;
        return prev;
    }

}

/**
 * MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
