using System;

public class Solution {
    public int[] ExclusiveTime(int n, IList<string> logs) {
        // int[] exclusive_time = new int[n];
        // // Use a stack to store the current executing functions
        // Stack<int> functions = new Stack<int>();
        // // Parameters for splitted string
        // string[] current, former;
        // int c0, f0, c2, f2;
        // string c1, f1;

        // for(int i = 0 ; i < logs.Count() ; i++){
        //     // Split the current string
        //     current = logs[i].Split(':');
        //     c0 = Convert.ToInt32(current[0]);
        //     c2 = Convert.ToInt32(current[2]);
        //     c1 = current[1];
        //     // Start of the function
        //     if(c1 == "start"){
        //         if(functions.Count != 0){
        //             // Split the former string
        //             former = logs[i - 1].Split(':');
        //             f0 = Convert.ToInt32(former[0]);
        //             f2 = Convert.ToInt32(former[2]);
        //             f1 = former[1];
        //             // Start -> Start
        //             if(f1 == "start"){
        //                 exclusive_time[functions.Peek()] += c2 - f2;
        //             }
        //             // End -> Start when a function is executing
        //             else if(logs[i - 1].Split(':')[1] == "end"){
        //                 exclusive_time[functions.Peek()] += c2 - f2 - 1;
        //             }
        //         }
        //         functions.Push(c0);
        //     }
        //     // End of the function
        //     else{
        //         // Split the former string
        //             former = logs[i - 1].Split(':');
        //             f0 = Convert.ToInt32(former[0]);
        //             f2 = Convert.ToInt32(former[2]);
        //             f1 = former[1];
        //         // Start -> End
        //         if(f1 == "start"){
        //             exclusive_time[functions.Peek()] += c2 - f2 + 1;
        //         }
        //         // End -> End
        //         else{
        //             exclusive_time[functions.Peek()] += c2 - f2;
        //         }
        //         functions.Pop();
        //     }
        //     // foreach(int num in exclusive_time){
        //     //     Console.Write(num + " ");
        //     // }
        //     // Console.WriteLine();
        // }
        // return exclusive_time;

        int[] exclusive_time = new int[n];
        // Use a stack to store the timestamp of the start of the function and the amount of time which needs to be subtracted from the execution time of the function.
        Stack<(int timestamp, int subtracted_time)> functions = new Stack<(int, int)>();
        // Variables used;
        string[] splitted;
        int ts, st, exe_time;

        for(int i = 0 ; i < logs.Count() ; i++){
            splitted = logs[i].Split(':');
            // Start of the function
            if(splitted[1] == "start"){
                functions.Push((Convert.ToInt32(splitted[2]), 0));
            }
            // End of the function
            else{
                ts = functions.Peek().timestamp;
                st = functions.Peek().subtracted_time;
                // Needs to subtract the period of time where other functions are executing
                exe_time = Convert.ToInt32(splitted[2]) - ts + 1;
                exclusive_time[Convert.ToInt32(splitted[0])] += exe_time - st;
                functions.Pop();
                if(functions.TryPeek(out var element)){
                    ts = element.timestamp;
                    st = element.subtracted_time;
                    // Store the amount of time where other functions are executing for the subtracting later
                    st += exe_time;
                    functions.Pop();
                    functions.Push((ts, st));
                }
            }
        }
        return exclusive_time;
    }
}