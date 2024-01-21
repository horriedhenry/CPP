#include <iostream>
#include <string>
#include <utility>

void basics() {
    // reference should not be null.
    std::string foo = "Iam foo";
    std::string bar = "Iam bar";
    std::string& fooRef = foo;
    // once fooRef is referring to foo it will always refere to it i.e it always
    // points to foo no matter what 
    // and foo can be modified by using fooRef.
    fooRef += ". Hi";
    std::cout << "fooRef : " << fooRef << std::endl;
    std::cout << "foo    : " << foo << std::endl;
    // as mentioned fooRef always points to address of foo or referes to foo
    fooRef = bar;
    // this does not make fooRef to points to bar or refer to bar
    std::cout << "after fooRef = bar " << std::endl; 
    std::cout << "fooRef : " << fooRef << std::endl; // output = Iam bar
    std::cout << "foo    : " << foo << std::endl; // output = Iam bar
}

void copy_(std::string param) {
    // this copys the string
    // copy is an expensive operation
    std::cout << param << std::endl;
}

void ref_reg(std::string& param) {
    // referes to the string pass to this func(), do not copy for the scope of
    // this function
    param += " hello form param ";
    // this will modify the origirnal string that is passed to this func()
}

std::string temp_obj() {
    // the return string is not defined
    // and when this string is returnd , then it will copy this entire string
    // ex : in main func() we do 
    // string = temp_obj();
    return "temp string from temp_obj()";
}

void r_value_ref(std::string&& param) {
    // r_value_ref(temp_obj())
    std::cout << param << std::endl; // takes ownership of the returned value
    // from temp_obj()
    param += " (modified in r_value_ref)";
}

void r_value_ref_2() {
    std::string str = temp_obj(); // this will copy the return value from temp_obj().
    std::cout << str << std::endl;
    std::string&& strs = temp_obj(); // this will not copy the string , it will
    // refer to the temp_obj returned from temp_obj().
    std::cout << strs << std::endl;
}

void std_move() {
    std::string&& r_ref = "r_reference";
    r_value_ref(std::move(r_ref));
    std::cout << r_ref << std::endl;
}

// reference to reference (Reference Collapsing)
void ref_to_ref() {
    int x = 42;
    int& ref1 = x;
    int&& ref2 = std::move(x);
    int&& ref3 = std::move(ref1); // reference collapsing
}

int main (int argc, char *argv[]) {
    ref_to_ref();
    return 0;
}
