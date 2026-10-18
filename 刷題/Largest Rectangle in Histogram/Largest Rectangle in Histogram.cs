// using System;
// using System.Collections.Generic;

// public class Solution {
    
//     // Define a class for storing the height and the maximum width
//     public class SizeInfo{
//         public int Height { get; set; }
//         public int MaxWidth { get; set; }

//         public SizeInfo(int height, int max_width){
//             Height = height;
//             MaxWidth = max_width;
//         }
//     }
    
//     public int LargestRectangleArea(int[] heights) {
//         // Use a monotonic stack to store the heights in ascending order, and their corresponding maximum width
//         List<SizeInfo> monotonic_stack = new List<SizeInfo>();
//         int rect;
//         int largest_rect = 0;
//         int curr_width;
//         for(int i = 0 ; i < heights.Length ; i++){
//             SizeInfo curr = new SizeInfo(heights[i], 1);
//             // If the last height in the stack is larger than the current height
//             curr_width = 0;
//             while(monotonic_stack.Count > 0 && monotonic_stack[monotonic_stack.Count - 1].Height > heights[i]){
//                 // monotonic_stack[monotonic_stack.Count - 1] can not be wider, therefore calculate its rectangle to check if it's larger than largest_rect. Also, Update curr_width for the next area calculation of the last element in monotonic_stack
//                 curr_width += monotonic_stack[monotonic_stack.Count - 1].MaxWidth;
//                 // Console.WriteLine($"curr width: {curr_width}");
//                 rect = monotonic_stack[monotonic_stack.Count - 1].Height * curr_width;
//                 largest_rect = rect > largest_rect ? rect : largest_rect;
//                 // Pop the stack, then update the max_width of curr.Maxwidth
//                 curr.MaxWidth += monotonic_stack[monotonic_stack.Count - 1].MaxWidth;
//                 monotonic_stack.RemoveAt(monotonic_stack.Count - 1);
//                 // Console.WriteLine($"largest rect: {largest_rect}");
//             }
//             //Add the current element into monotonic_stack
//             if(curr.Height != 0) monotonic_stack.Add(curr);
//             // foreach (SizeInfo si in monotonic_stack) {
//                 // Console.Write($"{si.Height} ");
//             // }
//             // Console.WriteLine();
//         }
//         // Calculate the rest of the rectangles in the monotonic stack, and find largest_rect
//         curr_width = 0;
//         while(monotonic_stack.Count > 0){
//             curr_width += monotonic_stack[monotonic_stack.Count - 1].MaxWidth;
//             // Console.WriteLine($"curr width: {curr_width}");
//             rect = monotonic_stack[monotonic_stack.Count - 1].Height * curr_width;
//             largest_rect = rect > largest_rect ? rect : largest_rect;
//             monotonic_stack.RemoveAt(monotonic_stack.Count - 1);
//             // Console.WriteLine($"largest rect: {largest_rect}");
//             // foreach (SizeInfo si in monotonic_stack) {
//             //     Console.Write($"{si.Height} ");
//             // }
//             // Console.WriteLine();
//         }
//         return largest_rect;
//     }
// }

public class Solution {

    
    public int LargestRectangleArea(int[] heights) {
        // Use a monotonic stack to store the indices, where their heights are in ascending order
        List<int> monotonic_stack = new List<int>();
        int stack_count = 0;
        int rect;
        int largest_rect = 0;
        for(int i = 0 ; i < heights.Length ; i++){
            // If the last height in the stack is larger than the current height
            while(stack_count > 0 && heights[monotonic_stack[stack_count - 1]] > heights[i]){
                // monotonic_stack[stack_count - 1] can not be wider, therefore calculate its rectangle to check if it's larger than largest_rect
                // Consider the left and the right boundary of the height. If there is only one element in the stack, the largest width should be i
                if(stack_count > 1) rect = heights[monotonic_stack[stack_count - 1]] * (i - monotonic_stack[stack_count - 2] - 1);
                else rect = heights[monotonic_stack[stack_count - 1]] * i;
                largest_rect = rect > largest_rect ? rect : largest_rect;
                monotonic_stack.RemoveAt(stack_count-- - 1);
                // Console.WriteLine($"largest rect: {largest_rect}");
            }
            //Add the current index into monotonic_stack
            monotonic_stack.Add(i);
            stack_count++;
        }
        // Calculate the rest of the rectangles in the monotonic stack, and find largest_rect
        while(stack_count > 1){
            rect = heights[monotonic_stack[stack_count - 1]] * (heights.Length - monotonic_stack[stack_count - 2] - 1);
            largest_rect = rect > largest_rect ? rect : largest_rect;
            monotonic_stack.RemoveAt(stack_count-- - 1);
        }
        rect = heights[monotonic_stack[stack_count - 1]] * heights.Length;
        largest_rect = rect > largest_rect ? rect : largest_rect;
        return largest_rect;
    }
}