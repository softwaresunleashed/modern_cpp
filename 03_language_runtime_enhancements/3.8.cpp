// 3.8.cpp

class Foo {
    const char*&& right = "this is a rvalue";
public:
    void bar() {
        right = "still rvalue"; // the string literal is a rvalue 
    }
};

int main() {
    const char* const &left = "this is an lvalue"; // the string literal is an lvalue
}
