using System.Collections;
using System.Collections.Generic;

namespace Lab2_9cs
{
    public class  City
    {
        public City(string name) { 
            _distances=new Hashtable();
            Name = name; }
        public string Name { get; set; }

        Hashtable _distances;
        public Hashtable Distances
        {
            get => _distances;
            set
            {
                _distances = value;
            }
        }
        public List<City> CloseCities { get;set; }
    }
}
