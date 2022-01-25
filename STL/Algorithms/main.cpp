#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

class Person{
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        :name{name}, age{age} {}
    bool operator < (const Person &rhs) const{
        return this->age < rhs.age;
    }
    bool operator == (const Person &rhs) const{
        return(this->name == rhs.name && this->age == rhs.age);
    }
};

// Find an element in a container
void find_test(){
    std::cout << "\n============================" << std::endl;

    std::vector<int> vec{1,2,3,4,5};

    auto loc = std::find(vec.begin(), vec.end(), 2);

    if (loc != vec.end())
        std::cout << "Found the number : " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number " << std::endl;
    
    std::list <Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 22}
    };

    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20});
    if(loc1 != players.end())
        std::cout << "Found Moe" << std::endl;
    else 
        std::cout << "Moe not found" << std::endl;
}

// count the number of eelemnt in a container
void count_test(){
    std::cout << "\n=============================" << std::endl;
    
    std::vector <int> vec {1,2,3,4,5,1,2,10};

    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurence found" << std::endl;
}

//  Count the number of occurences of an ellement in a container 
// based on a predicate using a lambda expression

void count_if_test(){
    std::cout << "\n=========================" << std::endl;

    // Count only if element is even
    std::vector <int> vec {1,2,3,4,5,6,7,8,9,10,12,3,5,};
    int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x%2 == 0; });
    std::cout << num << " even numbers found" << std::endl;

    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x%2 != 0; });
    std::cout << num << " odd numbers found" << std::endl;
    
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x >= 5; });
    std::cout << num << " numbers > 5" << std::endl;
}

// replace occurences of elementsa in a container
void replace_test(){
    std::cout << "\n===============================" << std::endl;

    std::vector <int> vec {1,2,3,4,5,1,2,1};
    for(auto i:vec){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 100);
    for(auto i:vec){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test(){
    std::vector <int> vec {1,3,5,7,9,1,3,13,19,5};    
    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x > 10; }))
        std::cout << "All elements are > 10" << std::endl;
    else
        std::cout << "Not all elements are > 10" << std::endl;   
    
    if (std::all_of(vec.begin(), vec.end(), [] (int x) { return x < 20; }))
        std::cout << "All elements are < 20" << std::endl;
    else
        std::cout << "Not all elements are < 10" << std::endl;  
}

// Transform elements in container - string in this code 
void string_transform_test (){
    std::cout << "\n=========================" << std::endl;

    std::string str1 {"This is a test"}; 
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "After transform: "  << str1  << std::endl;
}

int main()
{
    // find_test();
    // count_test();
    // count_if_test();
    // replace_test();
    // all_of_test();
    string_transform_test();
    return 0;
}