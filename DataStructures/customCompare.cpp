template<class T>
struct custom_compare {
    bool operator()(const T& a, const T& b) const {
        if (a == b) return true; // Keep duplicates
        return a > b;
    }
};


//REF: GFG
class CustomComparator { 
public: 
    CustomComparator(int baseValue) : baseValue_(baseValue) {} 
  
    bool operator()(int a, int b) const { 
        // Custom comparison logic involving state 
        return (a % baseValue_) < (b % baseValue_); 
    } 
  
private: 
    int baseValue_; 
}; 

// OR through capture by reference (capture clauses)
auto compare = [&](char a, char b) { return localStructure[a] > localStructure[b]; }; 