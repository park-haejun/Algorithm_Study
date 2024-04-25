using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BOJ14502_연구소_
{
    class BOJ14502_연구소_
    {
        static int N, M;
        static int[,] lab;
        static int[,] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        static int maxSafeArea = 0;

        static void Main(string[] args)
        {
            string input = Console.ReadLine();
            string[] inputs = input.Split(' ');
            N = int.Parse(inputs[0]);
            M = int.Parse(inputs[1]);

            lab = new int[N, M];
  
            for (int i = 0; i < N; i++)
            {
                string row = Console.ReadLine();
                string[] cells = row.Split(' ');
                for (int j = 0; j < M; j++)
                {
                    lab[i, j] = int.Parse(cells[j]);
                }
            }

            BuildWall(0, 0);

            Console.WriteLine(maxSafeArea);
        }

        static void BuildWall(int count, int index)
        {
            if (count == 3)
            {
                SpreadVirus();
                return;
            }

            for (int i = index; i < N * M; i++)
            {
                int x = i / M;
                int y = i % M;
                if (lab[x, y] == 0)
                {
                    lab[x, y] = 1;
                    BuildWall(count + 1, i + 1);
                    lab[x, y] = 0;
                }
            }
        }

        static void SpreadVirus()
        {      
            // 바이러스 퍼지는 거
        }

        static void CountSafeArea()
        {
          // 안전 영역 구하기
        }
    }
}
