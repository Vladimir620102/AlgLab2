using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_9cs
{
    internal class Program
    {

        public const int NumCities = 5;

        /// <summary>
        /// Поиск прямым перебором (только для тестирования) 
        /// </summary>
        static void TestSimpleSearch(int[,] data)
        {

            List<Distance> distances = new List<Distance>();
            Cities cities = new Cities(distances, data);
            cities.InitDistances();
            Console.WriteLine("Исходные данные:"); 
            cities.ShowDistances();

            Console.WriteLine("");
            Console.WriteLine("Поиск перебором всех путей");

            string path = string.Empty;
            int minPath = 100000;       // большое число
            for (var i1 = 0; i1 < NumCities; i1++)
            {
                for (var i2 = 0; i2 < NumCities; i2++)
                {
                    for (var i3 = 0; i3 < NumCities; i3++)
                    {
                        for (var i4 = 0; i4 < NumCities; i4++)
                        {
                            for (var i5 = 0; i5 < NumCities; i5++)
                            {

                                // нельзя посещать один и тот же город больше одного раза
                                if (
                                    (i1 != i2) && (i1 != i3) && (i1 != i4) && (i1 != i5) &&
                                    (i2 != i3) && (i2 != i4) && (i2 != i5) &&
                                    (i3 != i4) && (i3 != i5) &&
                                    (i4 != i5)
                                    )
                                {
                                    var c1 = "City" + (i1 + 1).ToString();
                                    var c2 = "City" + (i2 + 1).ToString();
                                    var c3 = "City" + (i3 + 1).ToString();
                                    var c4 = "City" + (i4 + 1).ToString();
                                    var c5 = "City" + (i5 + 1).ToString();
                                    var d1 = distances.FirstOrDefault(p => p.CityFrom.Name == c1 && p.CityTo.Name == c2);
                                    if (d1 == null) continue;
                                    var d2 = distances.FirstOrDefault(p => p.CityFrom.Name == c2 && p.CityTo.Name == c3);
                                    if (d2 == null) continue;
                                    var d3 = distances.FirstOrDefault(p => p.CityFrom.Name == c3 && p.CityTo.Name == c4);
                                    if (d3 == null) continue;
                                    var d4 = distances.FirstOrDefault(p => p.CityFrom.Name == c4 && p.CityTo.Name == c5);
                                    if (d4 == null) continue;
                                    var d5 = distances.FirstOrDefault(p => p.CityFrom.Name == c5 && p.CityTo.Name == c1);
                                    
                                    // запоминаем текущий путь, если он короче 
                                    var tempDistance = d1.Weight + d2.Weight + d3.Weight + d4.Weight + d5.Weight;
                                    if (tempDistance < minPath) 
                                    {
                                        minPath = tempDistance;
                                        path = $"{i1 + 1} -> {i2 + 1} -> {i3 + 1} -> {i4 + 1} -> {i5 + 1} -> {i1 + 1}";
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Console.WriteLine("Лучший путь:");
            Console.WriteLine(path);
            Console.WriteLine(minPath);
        }

        static void Main(string[] args)
        {

  
//          Тестовая матрица
            int[,] data = {
                { 0, 25, 40, 31, 27},
                { 5,  0,  17, 30, 25 },
                {19, 15,  0,  6,  1},
                { 9, 50, 24,  0,  6 },
                {22,  8,  7, 10,  0 }
            };

            TestSimpleSearch(data);
            Console.ReadLine();
        }
    }

    public class Population
    {

    }
}
