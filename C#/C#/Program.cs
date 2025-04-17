using System;

class Program
{
    static void Main()
    {
        bool running = true;
        while (running)
        {
            Console.WriteLine("\nWybierz zadanie:");
            Console.WriteLine("1. Kalkulator");
            Console.WriteLine("2. Konwerter temperatur");
            Console.WriteLine("3. Średnia ocen");
            Console.WriteLine("4. Zakończ");

            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    Kalkulator();
                    break;
                case "2":
                    KonwerterTemperatur();
                    break;
                case "3":
                    SredniaOcen();
                    break;
                case "4":
                    Console.WriteLine("Koniec");
                    running = false;
                    break;
                default:
                    Console.WriteLine("Nieprawidłowy wybór.");
                    break;
            }
        }
    }

    static void Kalkulator()
    {
        Console.WriteLine("\n--- Kalkulator ---");
        Console.Write("Podaj pierwszą liczbę:");
        double a = Convert.ToDouble(Console.ReadLine());

        Console.Write("Podaj drugą liczbę:");
        double b = Convert.ToDouble(Console.ReadLine());

        Console.Write("Wybierz operację (+, -, *, /): ");
        string operacja = Console.ReadLine();

        double wynik;
        switch (operacja)
        {
            case "+":
                wynik = a + b;
                break;
            case "-":
                wynik = a - b;
                break;
            case "*":
                wynik = a * b;
                break;
            case "/":
                if (b != 0)
                    wynik = a / b;
                else
                {
                    Console.WriteLine("Błąd: dzielenie przez zero!");
                    return;
                }
                break;
            default:
                Console.WriteLine("Nieznana operacja.");
                return;
        }
        Console.WriteLine("Wynik: " + wynik);
    }

    static void KonwerterTemperatur()
    {
        Console.WriteLine("\n--- Konwerter temperatur ---");
        Console.Write("Wybierz kierunek konwersji (C na °F lub F na °C): ");
        string kierunek = Console.ReadLine().ToUpper();

        Console.Write("Podaj temperaturę: ");
        double temp = Convert.ToDouble(Console.ReadLine());

        if (kierunek == "C")
        {
            double wynik = temp * 1.8 + 32;
            Console.WriteLine($"{temp}°C = {wynik:F2}°F");
        }
        else if (kierunek == "F")
        {
            double wynik = (temp - 32) / 1.8;
            Console.WriteLine($"{temp}°F = {wynik:F2}°C");
        }
        else
        {
            Console.WriteLine("Nieprawidłowy wybór.");
        }
    }

    static void SredniaOcen()
    {
        Console.WriteLine("\n--- Średnia ocen ---");
        Console.Write("Podaj liczbę ocen: ");
        int n = Convert.ToInt32(Console.ReadLine());

        double suma = 0;

        for (int i = 1; i <= n; i++)
        {
            double ocena;

            while (true)
            {
                Console.Write($"Ocena {i}: ");
                ocena = Convert.ToDouble(Console.ReadLine());

                if (ocena >= 1.0 && ocena <= 6.0)
                    break;
                else
                    Console.WriteLine("Nieprawidłowa ocena. Wprowadź ocenę od 1 do 6.");
            }

            suma += ocena;
        }

        double srednia = suma / n;
        Console.WriteLine($"Średnia: {srednia:F2}");

        if (srednia >= 3.0)
            Console.WriteLine("Uczeń zdał.");
        else
            Console.WriteLine("Uczeń nie zdał.");
    }
}
