using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Need to do this fol all the types defined
using IEC_BOOL = System.Byte;
using IEC_DINT = System.Int32;

namespace ClassInterface
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Here!");
            Wrapper wrapper = new Wrapper();
            wrapper.print_hello();

            float f = 1.7f;
            IEC_DINT i = 5;

            wrapper.print_variable<float>(f, 0);
            wrapper.print_variable<IEC_DINT>(i, 0);

            Console.WriteLine("Break");
        }
    }
}
