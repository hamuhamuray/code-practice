// ChatGPT版 O(N + Q)
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <cmath>

// using namespace std;

// int main() {
//     long long N, Q;
//     cin >> N;

//     vector<long long> numbers(N);
//     unordered_map<long long, long long> freq;

//     for (long long i = 0; i < N; i++) {
//         cin >> numbers[i];
//         freq[numbers[i]]++;
//     }

//     cin >> Q;

//     while (Q--) {
//         long long a, b;
//         cin >> a >> b;

//         long long ans = 0;

//         long long D = a * a - 4 * b;

//         if (D >= 0) {
//             long long sqrtD = sqrt(D);

//             if (sqrtD * sqrtD == D) {
//                 long long x_num = a + sqrtD;
//                 long long y_num = a - sqrtD;

//                 if (x_num % 2 == 0 && y_num % 2 == 0) {
//                     long long x = x_num / 2;
//                     long long y = y_num / 2;

//                     if (x == y) {
//                         ans = freq[x] * (freq[x] - 1) / 2;
//                     } else {
//                         ans = freq[x] * freq[y];
//                     }
//                 }
//             }
//         }

//         cout << ans << " ";
//     }

//     return 0;
// }

//我的版本 O(NQ)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main(){
    //Input
    long N, Q;
    cin >> N;
    vector<double> numbers(N);
    unordered_map<double, double> map;
    for(long i = 0 ; i < N ; i++)cin >> numbers[i];
    cin >> Q;
    vector<vector<double>> questions(Q, vector<double> (2));
    for(long i = 0 ; i < Q ; i++)cin >> questions[i][0] >> questions[i][1];
    
    for(long i = 0 ; i < Q ; i++){
        long ans = 0;
        //If the pair exists, calculate the pair of each question
        if(pow(questions[i][0], 2) - 4 * questions[i][1] >= 0){
            double x = (questions[i][0] + sqrt(pow(questions[i][0], 2) - 4 * questions[i][1])) / 2;
            double y = (questions[i][0] - sqrt(pow(questions[i][0], 2) - 4 * questions[i][1])) / 2;
            unordered_map<double, double> map;
            for(long j = 0 ; j < N ; j++){
                //If the number equals to one number of the pair, check if the other number of the pair exists in the map
                if(numbers[j] == x && map.count(y)){
                    //Add up the frequency of that number
                    ans += map[y];
                }
                else if(numbers[j] == y && map.count(x)){
                    //Add up the frequency of that number
                    ans += map[x];
                }
                //Add the frequency of the number
                map[numbers[j]]++;
            }
        }
        cout << ans << " ";
    }
    return 0;
}