class ProductOfNumbers {
public:
    vector<int>list;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        list.push_back(num);
    }
    
    int getProduct(int k) {
        int n = list.size()-1;
        int result=1;
        while(k--){
            result = result*list[n];
            n--;
        }

        return result;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */