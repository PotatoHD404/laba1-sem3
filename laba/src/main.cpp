//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <chrono>
#include <random>


//#ifdef __EMSCRIPTEN__
//#else
//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "EndlessLoop"
//#endif
//
using namespace std;
using namespace std::chrono;


#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
string str;
EM_JS(const char *, do_fetch, (), {
return Asyncify.handleAsync(async () => {
        let promise = new Promise(function(resolve, reject){
        Module.addEventListener("message", text => {

            resolve(text);

        }, {once : true});
        });
        let promise = Module.cpp_promise;
        let res = await promise;
        let lengthBytes = lengthBytesUTF8(res)+1;
        let stringOnWasmHeap = _malloc(lengthBytes);
        stringToUTF8(res, stringOnWasmHeap, lengthBytes);
        return stringOnWasmHeap;
});
str = "";
});


string readline(){
    string res;
    if(str == ""){
        const char * input = do_fetch();
        str = input;
        delete[] input;
    }
                    string delimiter = "\n";
        if((str.find(delimiter)) != std::string::npos && str.find(delimiter) != 0){


        res = str.substr(0, str.find(delimiter));
            str = str.substr(str.find(delimiter) + 1,str.length()-1);
        }
        else if(str.find(delimiter) == 0)
            {
            str = str.substr(str.find(delimiter) + 3,str.length()-1);
            return readline();
            }
        else {res = str;
            str = "";}

    return res;
}
#else

string readline() {
    string res;
    getline(cin, res);
    return res;
}

#endif


//int start() {
////    for (int i = 0; i < 10; ++i) {
////        string c = readline();
////        cout << "Hello from your wasm module " << i << " " << c << endl;
////    }
//    BTree<int> bTree(3);
//    for (int i = 0; i < 1500000; ++i) {
//        bTree.Insert(i);
////        cout << bTree.Order(R"({K}(1)[2]<3>d4b/5\"6')") << endl;
//    }
//    cout << bTree.Order(R"({K}(1)[2]<3>d4b/5\"6')") << endl;
////    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC * 1000 << " milisecs" << endl;
//    return 0;
//}

//template<typename T>
//class HasMore {
//private:
//    typedef int YesType;
//    typedef long NoType;
//
//    template<typename T1>
//    static YesType test(decltype(T1::operator>)) { return 0; }
//
//    template<typename T1>
//    static NoType test(...) { return 0; }
//
//public:
//    enum {
//        value = sizeof(test<T>(0)) == sizeof(YesType)
//    };
//};





#include <iostream>
#include "NAryTree.hpp"
#include "Functions.hpp"
#include "Complex.hpp"
#include "Person.hpp"
#include "BTree.hpp"
#include "Set.hpp"

using namespace std;


const char *MSGS[] = {"0. Quit",
                      "1. Add value to set",
                      "2. Remove value from set",
                      "3. Print set",
                      "4. Convert set to ArraySequence and print",
                      "5. Print set as tree",
                      "6. Check if set contains value",
                      "7. Calculate union of sets",
                      "8. Calculate intersection of sets",
                      "9. Calculate difference of sets"};

const char *MSGS1[] = {"0. Quit",
                       "1. Int",
                       "2. Double",
                       "3. Float",
                       "4. Complex",
                       "5. Functions",
                       "6. People",
                       "7. String"};

const char *MSGS2[] = {"0. Quit",
                       "1. Square",
                       "2. x2",
                       "3. subtract2"};

const char *MSGS3[] = {"0. Quit",
                       "1. Add value",
                       "2. Remove value",
                       "3. Print",
                       "4. Convert to ArraySequence and print",
                       "5. Contains element in set",
                       "6. Apply func"};

const char *MSGS4[] = {"0. Quit",
                       "1. Set A",
                       "2. Set B"};

template<int N>
int Dialog(const char *(&msgs)[N]) {
    string error;
    int choice = -1;
    do {
        cout << error;
        error = "You're wrong. Try again!\n";
        for (int i = 0; i < N; ++i) {
            cout << msgs[i] << endl;
        }
        cout << "Make your choice: \n";
        stringstream ss(readline());
        ss >> choice;
    } while (choice < 0 || choice >= N);
    return choice;
}

template<typename T>
T InputValue() {

    bool success = false;
    T value;
    while (!success) {
        cout << "Input value:\n";
        stringstream ss(readline());
        try {
            ss >> value;
            success = true;
        }
        catch (exception &e) {
            cout << "An error has occurred: " << e.what() << "\nTry again!\n";
        }
    }
    return value;
}

template<typename T>
void StartUI() {
    int res = 1;
    string tmp;
    Set<T> set1, set2;
    Set<T> *set;
    while (res != 0) {
        try {
            res = Dialog(MSGS);
            T value;
            switch (res) {
                case 0:
                    break;
                case 1: {
                    res = Dialog(MSGS4);
                    if (res == 1)
                        set = &set1;
                    else if (res == 2)
                        set = &set2;
                    else
                        break;
                    value = InputValue<T>();
                    set->Add(value);
                    break;
                }

                case 2: {
                    res = Dialog(MSGS4);
                    value = InputValue<T>();
                    if (res == 1)
                        set = &set1;
                    else if (res == 2)
                        set = &set2;
                    else
                        break;
                    set->Remove(value);
                    break;
                }

                case 3:
                    res = Dialog(MSGS4);
                    if (res == 1)
                        set = &set1;
                    else if (res == 2)
                        set = &set2;
                    else
                        break;

                    cout << "Result Set " << ((res == 1) ? "A" : "B") << ": " << *set << endl;
                    break;
                case 4:
                    res = Dialog(MSGS4);
                    if (res == 1)
                        set = &set1;
                    else if (res == 2)
                        set = &set2;
                    else
                        break;
                    cout << "Result: " << set->ToArraySequence() << endl;
                    break;
                case 5:
                    res = Dialog(MSGS4);
                    if (res == 1)
                        set = &set1;
                    else if (res == 2)
                        set = &set2;
                    else
                        break;
                    cout << "Result: " << set->AsTree() << endl;
                    break;
                case 6:
                    res = Dialog(MSGS4);
                    value = InputValue<T>();
                    if (res == 1)
                        set = &set1;
                    else if (res == 2)
                        set = &set2;
                    else
                        break;
                    if (set->Contains(value))
                        cout << "Set contains the value\n";
                    else
                        cout << "Set does not contain the value\n";
                    break;
                case 7:
                    cout << "Result: " << set1 + set2 << endl;
                    break;
                case 8:
                    cout << "Result: " << set1 * set2 << endl;
                    break;
                case 9:
                    cout << "Result: " << set1 - set2 << endl;
                    break;
                default: {
                    cout << "How did you end up here?\n";
                    break;
                }
            }
        }
        catch (exception &e) {
            cout << "An error has occurred: " << e.what() << "\nTry again!\n";
        }
    }
}

void StartUI_func() {
    int res = 1;
    string tmp;
    Set<int (*)(int)> set;
    while (res != 0) {
        res = Dialog(MSGS3);
        int (*func)(int) = nullptr;
        switch (res) {
            case 0:
                break;
            case 1: {
                res = Dialog(MSGS2);
                switch (res) {
                    case 0:
                        break;
                    case 1:
                        func = Square;
                        break;
                    case 2:
                        func = x2;
                        break;
                    case 3:
                        func = subtract2;
                        break;
                    default: {
                        cout << "How did you end up here?\n";
                        break;
                    }
                }
                set.Add(func);
                break;
            }

            case 2: {
                res = Dialog(MSGS2);
                switch (res) {
                    case 0:
                        break;
                    case 1:
                        func = Square;
                        break;
                    case 2:
                        func = x2;
                        break;
                    case 3:
                        func = subtract2;
                        break;
                    default: {
                        cout << "How did you end up here?\n";
                        break;
                    }
                }
                set.Remove(func);
                break;
            }

            case 3:
                cout << set << endl;
                break;
            case 4: {
                cout << set.ToArraySequence() << endl;
                break;
            }
            case 5: {
                res = Dialog(MSGS2);

                switch (res) {
                    case 0:
                        break;
                    case 1:
                        func = Square;
                        break;
                    case 2:
                        func = x2;
                        break;
                    case 3:
                        func = subtract2;
                        break;
                    default: {
                        cout << "How did you end up here?\n";
                        break;
                    }
                }
                if (set.Contains(func))
                    cout << "Set contains the value\n";
                else
                    cout << "Set does not contain the value\n";
                break;
            }
            case 6: {
                ArraySequence<int (*)(int)> seq = set.ToArraySequence();
                cout << "Applying all functions to number 5\n";
                for (size_t i = 0; i < seq.Count(); ++i) {
                    cout << seq[i](5) << endl;
                }
                break;
            }

            default: {
                cout << "How did you end up here?\n";
                break;
            }
        }
    }
}

[[noreturn]] void MainStartUI() {
    while (true) {
        int res = 1;
        cout << "Enter data type:" << endl;
        res = Dialog(MSGS1);
        switch (res) {
            case 0:
                break;
            case 1:
                StartUI<int>();
                break;
            case 2:
                StartUI<double>();
                break;
            case 3:
                StartUI<float>();
                break;
            case 4:
                StartUI<Complex>();
                break;
            case 5:
                StartUI_func();
                break;
            case 6:
                StartUI<Person>();
                break;
            case 7:
                StartUI<std::string>();
                break;
            default: {
                cout << "How did you end up here?\n";
                break;
            }
        }
    }
}

//int main() {
////    while (true)
//    MainStartUI();
////    Set<int> a;
////    a.Add(1);
////    a.Remove(1);
////    a.Add(2);
////    a.Remove(2);
//////    a.Add(2);
//////    a.Add(5);
////    cout << a << endl;
//    return 0;
//}



int main() {
    cout << "All working" << endl;
    return 0;
}

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(Laba3) {
        emscripten::function("start", &MainStartUI, emscripten::allow_raw_pointers());
}
#endif
//#pragma clang diagnostic pop