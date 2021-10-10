//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <chrono>
#include <random>
#include <sstream>
#include "Sequence.hpp"
#include "ListSequence.hpp"
#include "ArraySequence.hpp"
#include "Complex.hpp"
#include <vector>
#include "WebAssembly.hpp"

using namespace std;
using namespace Sorts;
using namespace std::chrono;

const char *MSGS[] = {"0. Quit",
                      "1. Int",
                      "2. Float",
                      "3. String",
                      "4. Complex"};


const char *MSGS1[] = {"0. Quit",
                       "1. Init sequence",
                       "2. Add value to sequence",
                       "3. Remove value from sequence",
                       "4. Print sequence",
                       "5. Fill with random values",
                       "6. Sort"};

const char *MSGS2[] = {"0. Quit",
                       "1. ListSequence",
                       "2. ArraySequence"};

const char *MSGS3[] = {"0. Quit",
                       "1. QuickSort",
                       "2. ShellSort",
                       "3. InsertionSort"};


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

int GenRandom(int minValue, int maxValue, mt19937 &rng) {
    uniform_int_distribution<signed> distribution(minValue, maxValue);
    return (int) distribution(rng);
}

float GenRandom(float minValue, float maxValue, mt19937 &rng) {
    uniform_real_distribution<> distribution(minValue, maxValue);
    return (float) distribution(rng);
}

template<typename T>
T GenRandom(mt19937 &rng) {
    if constexpr(std::is_same<T, string>::value) {
        static string alphanum = "0123456789"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "abcdefghijklmnopqrstuvwxyz";
        uniform_int_distribution<unsigned> distribution(0, alphanum.length() - 1);
        string res;
        for (int i = 0; i < 5; ++i) {
            res += alphanum[distribution(rng)];
        }
        return res;
    } else {
        uniform_real_distribution<> distribution(-1, 1);
        return Complex((float) distribution(rng), (float) distribution(rng));
    }
}

int DialogValue(const string &msg) {
    string error;
    int choice = -1;
    do {
        cout << error;
        error = "You're wrong. Try again!\n";
        cout << msg << endl;
        cout << "Make your choice: " << endl;
        stringstream ss(readline());
        ss >> choice;
    } while (choice < 0);
    return choice;
}

template<typename T>
void StartUI() {
    random_device rd;
    mt19937::result_type seed = rd() ^ (
            (mt19937::result_type)
                    chrono::duration_cast<std::chrono::seconds>(
                            chrono::system_clock::now().time_since_epoch()
                    ).count() +
            (mt19937::result_type)
                    chrono::duration_cast<chrono::microseconds>(
                            chrono::high_resolution_clock::now().time_since_epoch()
                    ).count());
    mt19937 rng(seed);
    int choice = 1;
    string tmp;
    unique_ptr<Enumerable<T>> seq = make_unique<ArraySequence<T>>();
    while (choice) {
        try {
            choice = Dialog(MSGS1);
            T value1, value2;
            int count;
            switch (choice) {
                case 0:
                    break;
                case 1: {
                    choice = Dialog(MSGS2);
                    if (choice == 1)
                        seq = make_unique<ListSequence<T>>();
                    else if (choice == 2)
                        seq = make_unique<ArraySequence<T>>();
                    choice = 1;
                    break;
                }

                case 2: {
                    seq->Add(InputValue<T>());
                    break;
                }

                case 3:
                    seq->Remove(InputValue<T>());
                    break;

                case 4:
                    cout << *seq << endl;
                    break;
                case 5:
                    count = DialogValue("Input items count");
                    if constexpr(std::is_same<T, string>::value || std::is_same<T, Complex>::value) {
                        for (int i = 0; i < count; ++i) {
                            seq->Add(GenRandom<T>(rng));
                        }
                    } else {
                        do {
                            cout << "Input min value" << endl;
                            value1 = InputValue<T>();
                            cout << "Input max value" << endl;
                            value2 = InputValue<T>();
                            if (value1 >= value2) {
                                cout << "Min value is less than max value. Try again." << endl;
                            }
                        } while (value1 >= value2);
                        for (int i = 0; i < count; ++i) {
                            seq->Add(GenRandom(value1, value2, rng));
                        }

                    }
                    break;
                case 6:
                    choice = Dialog(MSGS3);
                    if (choice) {
                        ISort<T> *sort = &QuickSort<T>;
                        if (choice == 2)
                            sort = &ShellSort<T>;
                        else if (choice == 3)
                            sort = &InsertionSort<T>;
                        auto t1 = high_resolution_clock::now();
                        seq->Sort(*sort);
                        auto t2 = high_resolution_clock::now();
                        duration<double, milli> ms_double = t2 - t1;
                        cout << ms_double.count() << "ms" << endl;
                    }
                    choice = 1;
                    break;
                default: {
                    cout << "How did you end up here?" << endl;
                    break;
                }
            }
        }
        catch (exception &e) {
            cout << "An error has occurred: " << e.what() << "\nTry again!\n";
        }
    }
}

void MainStartUI() {
//    int && res1 = move(1);
    int choice = 1;

    while (choice) {
        cout << "Enter data type:" << endl;
        choice = Dialog(MSGS);
        switch (choice) {
            case 0:
                break;
            case 1:
                StartUI<int>();
                break;
            case 2:
                StartUI<float>();
                break;
            case 3:
                StartUI<string>();
                break;
            case 4:
                StartUI<Complex>();
                break;
            default: {
                cout << "How did you end up here?" << endl;
                break;
            }
        }
    }
}


int main() {
//    vector<int> a = {};
//    auto it = a.begin();
//    cout << &(*it) << " " << &(*a.end()) << endl;
//    a.push_back(1);
//    cout << &(*it) << " " << &(*a.end()) << endl;
    MainStartUI();
    return 0;
}


#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(Laba3) {
        emscripten::function("start", &MainStartUI, emscripten::allow_raw_pointers());
}
#endif
//#pragma clang diagnostic pop