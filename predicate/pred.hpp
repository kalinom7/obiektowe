class Predicate{
    private:
    public:
    virtual bool operator()(int value) const = 0;
};

class Even : public Predicate{
    private:
    public:
    bool operator()(int value) const;
};

class Negative : public Predicate{
    private:
    public:
    bool operator()(int value) const;
};