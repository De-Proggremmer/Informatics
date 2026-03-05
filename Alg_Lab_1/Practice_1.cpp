

#include <iostream>
#include <map>
#include <chrono>

using namespace std;

int add_to_dict(map<int, int> dict, int N)
{
    for (int i = 0; i < N; i++)
    {
        dict.insert({ i, 0 });
    }
    return N;
}

template <typename Func, typename... Args>
auto measure_execution_time(Func&& func, Args&&... args) {
    auto start_time = chrono::high_resolution_clock::now();  // Начинаем отсчет времени
    auto result = func(forward<Args>(args)...);  // Выполняем переданную функцию с аргументами
    auto end_time = chrono::high_resolution_clock::now();  // Останавливаем отсчет времени

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);  // Вычисляем продолжительность в миллисекундах
    return make_pair(result, duration.count());  // Возвращаем результат и время выполнения
}


int main()
{
    map<int, int> dict;

    cout << measure_execution_time(add_to_dict, dict, 1000000).second << endl;
    cout << measure_execution_time(add_to_dict, dict, 10000000).second << endl;
    //cout << measure_execution_time(add_to_dict, dict, 4000000).second << endl;
    //cout << measure_execution_time(add_to_dict, dict, 5000000).second << endl;
    //cout << measure_execution_time(add_to_dict, dict, 6000000).second << endl;
    //cout << measure_execution_time(add_to_dict, dict, 7000000).second << endl;
    //cout << measure_execution_time(add_to_dict, dict, 8000000).second << endl;
    //cout << measure_execution_time(add_to_dict, dict, 9000000).second << endl;

    return 0;
}
