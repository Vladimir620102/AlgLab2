using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_7cs
{
    internal class Program
    {
        static List<int> _source = new List<int>() { 5, 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
        //  static List<int> _source = new List<int>() { 7, 2, 1, 3, 8, 4, 9, 1, 2, 6, 5, 9, 3, 8, 1 };

        static Dictionary<int, int> _counts = new Dictionary<int, int>();
        static Dictionary<int, int> _prevPositions = new Dictionary<int, int>();
        static Stack<int> _path = new Stack<int>();

        static void Main(string[] args)
        {
            PrepareData();
            PrintSource();

            FindLSC();

            Console.Write("Длина наибольшей возрастающей подпоследовательности: ");
            Console.WriteLine($"{_path.Count}");
            Console.WriteLine("Наибольшая возрастающая подпоследовательность (один из вариантов)");
            while (_path.Count > 0)
            {
                Console.Write($"{_path.Pop(),2} ");
            }

            Console.ReadLine();
        }

        private static void FindLSC()
        {
            var maxLen = _counts.Max(t => t.Value);
            var indexmax = _counts.FirstOrDefault(t => t.Value == maxLen).Key;
            SetPath(indexmax, maxLen);
        }

        static void SetPath(int index, int len)
        {
            if (index < 0 || len <= 0) return;
            _path.Push(_source[index]);
            SetPath(_prevPositions[index], len--);
        }

        private static void PrintSource()
        {
            Console.WriteLine("Длина подпоследовательности для каждого элемента");
            foreach (var x in _counts)
            {
                //                Console.Write($"{x.Key}->{x.Value} ");
                Console.Write($"{x.Value,2} ");
                //_indexes.Add(x.Value);
            }
            Console.WriteLine("");
            Console.WriteLine("Индекс предыдущего элемента");
            for (int i = 0; i < _source.Count; i++)
                Console.Write($"{_prevPositions[i],2} ");
            Console.WriteLine("");
        }

        private static void PrepareData()
        {
            InitDataSource();
            GenericData();
        }

        private static void GenericData()
        {
            for (int i = 0; i < _source.Count; i++)
            {
                for (int j = i + 1; j < _source.Count; j++)
                {
                    if (_source[j] > _source[i] && _counts[j] <= _counts[i])
                    {
                        _counts[j] = _counts[i] + 1;
                        _prevPositions[j] = i;
                    }
                }
            }
        }

        static void InitDataSource()
        {
            Console.WriteLine("Исходные данные:");
            for (int i = 0; i < _source.Count; i++)
            {
                Console.Write($"{i, 2} ");
                _counts[i] = 1;
                _prevPositions[i] = -1;
            }
            Console.WriteLine("");
            for (int i = 0; i < _source.Count; i++)
                Console.Write($"{_source[i],2} ");
            Console.WriteLine("");
        }
    }
}
