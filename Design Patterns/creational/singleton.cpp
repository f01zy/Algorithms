#include <iostream>

class Singleton final {
public:
  static Singleton &getInstance() {
    static Singleton instance;
    return instance;
  };

  void method() { std::cout << "I'm singleton." << std::endl; };
};

int main() {
  Singleton &singleton = Singleton::getInstance();
  singleton.method();
}
