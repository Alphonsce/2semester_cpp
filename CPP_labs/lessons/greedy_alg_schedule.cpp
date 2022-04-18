#include <iostream>
#include <vector>
#include <algorithm>

// Задача заключается в том, чтобы по расписанию определить какое максимальное количество рейсов можно сделать,

// Один элемент из расаписания - содержит начало и конец
struct job {
    float start;
    float end;
    public:
        void print() {
            std::cout << start << ':' << end << std::endl;
        }

        job(float start, float end) : start(start), end(end) {
            
        }
};

void print_jobs(std::vector<job> jobs) {
    
    for (int i = 0; i < jobs.size(); i ++) {
        jobs[i].print();
    }

}

// Сравнение для объектов job для сортировки по окончанию всего расписания
bool cmp_end_of_jobs(job one, job two) {
    return two.end > one.end;
}

int get_max_jobs(std::vector<job> jobs) {
    int n_jobs = 0;
    int n = jobs.size();

    std::sort(jobs.begin(), jobs.end(), cmp_end_of_jobs);   // после такой сортировки у нас по возрастанию времени окончания все выстроилось
    float current_end = 0.;   

    for (int i = 0; i < n; i ++) {
        if (jobs[i].start > current_end) {
            current_end = jobs[i].end;
            n_jobs += 1;
        }
    }

    return n_jobs;
}

int main() {
    
    std::vector<job> jobs = {
        {2., 3.},
        {7., 16.},
        {4., 7.},
        {1., 5.},
        {1., 8.},
        {5., 9.},
        {8., 10.},
        {9., 11.}
    };

    std::cout << get_max_jobs(jobs) << std::endl;

    return 0;
}