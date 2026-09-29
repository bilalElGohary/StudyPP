class Todo{
private:
    int id;
    string desc;
    bool iscomplete;
    
public:
    Todo(){
        id = 0;
        desc = " ";
        iscomplete = false;
    }
    
    

    ~Todo() = default;
};