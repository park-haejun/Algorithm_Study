using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ17298_오큰수_
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            string RL = Console.ReadLine();
            int[] A = Array.ConvertAll(RL.Split(), int.Parse);
            int[] NGE = new int[n];
            Stack<int> stack = new Stack<int>();

            for (int i = 0; i < n; i++)
            {
                while (stack.Count > 0 && A[i] > A[stack.Peek()])
                {
                    NGE[stack.Pop()] = A[i];
                }
                stack.Push(i);
            }
            while (stack.Count > 0)
            {
                NGE[stack.Pop()] = -1;
            }
            Console.WriteLine(string.Join(" ", NGE));
        }
    }
}
