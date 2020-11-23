class C {
public:
    C() : counter(0) {};
    int ref(void) const {
        return counter++;
    };
private:
    mutable int counter;
};

