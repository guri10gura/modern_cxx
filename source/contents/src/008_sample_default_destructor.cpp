// Base は、多態な基底クラスを想定
class Base {
    public:
    virtual ~Base() = default;              // 基底クラスなので、デストラクタを仮想化

    Base(Base&&) = default;                 // ムーブ対応
    Base& Operator=(Base&&) = default;      // これを書かないと、自動生成されない

    Base(const Base&) = default;            // コピー対応
    Base& operator=(const Base&) = default; // これを書かないと、自動生成されない
};

