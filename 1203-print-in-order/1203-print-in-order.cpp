class Foo {
public:
    promise<void> p1, p2;

    void first(function<void()> printFirst) {
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond) {
        p1.get_future().wait();
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird) {
        p2.get_future().wait();
        printThird();
    }
};