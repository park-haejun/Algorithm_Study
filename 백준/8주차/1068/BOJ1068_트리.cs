using System;
using System.Collections.Generic;

class MainClass
{
    static int n, k, leaf = 0, root;
    static List<int>[] tree;

    public static void Main(string[] args)
    {
        n = int.Parse(Console.ReadLine());
        tree = new List<int>[n];

        for (int i = 0; i < n; i++)
        {
            tree[i] = new List<int>();
        }

        string[] parentInput = Console.ReadLine().Split();
        int[] parent = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = int.Parse(parentInput[i]);
            if (parent[i] == -1)
                root = i;
            else
                tree[parent[i]].Add(i);
        }

        k = int.Parse(Console.ReadLine());

        int result = DFS(root);

        Console.WriteLine(leaf);
    }

    static int DFS(int node)
    {
        if (node == k) return -1;
        if (tree[node].Count == 0)
        {
            leaf++;
            return 0;
        }
        foreach (var child in tree[node])
        {
            int tmp = DFS(child);
            if (tmp == -1 && tree[node].Count == 1)
                leaf++;
        }
        return 0;
    }
}