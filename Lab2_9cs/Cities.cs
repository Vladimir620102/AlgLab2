using System;
using System.Collections.Generic;
using System.Linq;

namespace Lab2_9cs
{
    public class Cities : List<City>
    {
        public Cities(List<Distance> distances, int[,] data)
        {
            Distances = distances;
            Data = data;
        }
        List<Distance> _distances;
        public List<Distance> Distances
        {
            get => _distances;
            set => _distances = value;
        }

        int[,] _data;
        public int[,] Data
        {
            get => _data;
            set => _data = value;
        }

        public void InitDistances()
        {

            for(int i = 0; i < Program.NumCities; i++)
            {
                var name = $"City{i+1}";
                City city = new City(name);
                this.Add(city);
            }

            for(int i = 0;i < Program.NumCities; i++)
            {
                var currentCity = this[i];
                for(int j=0;j < Program.NumCities;j++)
                {
                    currentCity.Distances[this[j].Name] = Data[i, j];
                }
            }
        }

        public void ShowDistances()
        {
            for (int i = 0; i < Program.NumCities; i++)
            {
                for (int j = 0; j < Program.NumCities; j++)
                {
                    if (i == j) continue;
                    var c1 = "City" + (i + 1).ToString();
                    var c2 = "City" + (j + 1).ToString();
                    City city1 = this.FirstOrDefault(c => c.Name == c1);
                    City city2 = this.FirstOrDefault(c => c.Name == c2);
                    Distance d = new Distance();
                    d.CityFrom = city1;
                    d.CityTo = city2;
                    d.Weight = (int)city1.Distances[city2.Name];
                    Distances.Add(d);
                    Console.WriteLine($"{d.CityFrom.Name} -> {d.CityTo.Name} {d.Weight}");
                }
            }
        }
    }
}
