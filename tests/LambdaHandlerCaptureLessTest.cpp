// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3559.pdf

int main() {
    int (*fp)(int, char) = [](auto a, auto b){ return a + b; };

#if 0
struct /* anonymous */
       {
template<class A, class B>
auto operator()(A a, B b) const // N3386 Return Type Deduction
           { return a + b; }
         private:
           // Note: We don't want to simply forward the call to operator()
           //       since forwarding is not entirely transparent, and could
           //       introduce visible side-effects. To produce the
           //       desired semantics we copy the parameter-clause
           //       and body exactly
           template<class A, class B>
static auto __invoke(A a, B b) { // N3386 Return Type Deduction return a + b;
}
           template<class A, class B, class R>
              using fptr_t = R (*) (A, B);
         public:
           template<class A, class B, class R>
             operator fptr_t<R, A, B>() const {
                return &__invoke;
} } L;

int (*fp)(int, char) = L;




int main() {
    class __lambda_4
    {
    public:
    using x = int ;
   using ptr_t = int (*)(int,char);    
    typedef int (*ptr_t)(int,char);
//    public: inline constexpr  operator x(*)(int, char)() const
    public: inline constexpr  operator ptr_t () const
    {
      return __invoke;
    }
    
    public: inline constexpr int operator()(int, char) const
    {
      return a + b;
    }
    
    private: inline static int __invoke(int, char)
    {
      return a + b;
    }
    
    };
    
    int (*fp)(int, char) = __lambda_4{};

}
#endif
}

