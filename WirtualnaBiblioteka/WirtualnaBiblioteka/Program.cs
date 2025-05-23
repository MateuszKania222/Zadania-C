using System;
using System.Collections.Generic;
using System.Linq;

class Book
{
    public string Title;
    public string Author;
    public bool IsLoaned;

    public Book(string title, string author)
    {
        Title = title;
        Author = author;
        IsLoaned = false;
    }
}

class Member
{
    public string Name;
    public List<Book> BorrowedBooks = new List<Book>();

    public Member(string name)
    {
        Name = name;
    }

    public void Borrow(Book book)
    {
        if (!book.IsLoaned)
        {
            BorrowedBooks.Add(book);
            book.IsLoaned = true;
            Console.WriteLine("Wypożyczono książkę.");
        }
        else
        {
            Console.WriteLine("Ta książka jest już wypożyczona.");
        }
    }

    public void Return(Book book)
    {
        if (BorrowedBooks.Contains(book))
        {
            BorrowedBooks.Remove(book);
            book.IsLoaned = false;
            Console.WriteLine("Zwrócono książkę.");
        }
        else
        {
            Console.WriteLine("Nie masz tej książki.");
        }
    }
}

class Program
{
    static List<Book> books = new List<Book>();
    static List<Member> members = new List<Member>();

    static void Main()
    {
        books.Add(new Book("Dziady", "Adam Mickiewicz"));      // 1
        books.Add(new Book("Lalka", "Bolesław Prus"));         // 2
        books.Add(new Book("Quo Vadis", "Henryk Sienkiewicz"));// 3

        while (true)
        {
            Console.WriteLine("\n--- Menu ---");
            Console.WriteLine("1. Dodaj użytkownika");
            Console.WriteLine("2. Wypożycz książkę");
            Console.WriteLine("3. Zwróć książkę");
            Console.WriteLine("4. Pokaż książki");
            Console.WriteLine("5. Wyjście");
            Console.WriteLine("6. Pokaż moje książki");
            Console.Write("Wybierz: ");
            string option = Console.ReadLine();

            switch (option)
            {
                case "1":
                    AddMember();
                    break;
                case "2":
                    BorrowBook();
                    break;
                case "3":
                    ReturnBook();
                    break;
                case "4":
                    ShowBooks();
                    break;
                case "5":
                    return;
                case "6":
                    ShowMyBooks();
                    break;
                default:
                    Console.WriteLine("Nieprawidłowa opcja.");
                    break;
            }
        }
    }

    static void AddMember()
    {
        Console.Write("Podaj imię i nazwisko: ");
        string name = Console.ReadLine();

        if (!IsValidName(name))
        {
            Console.WriteLine("Nieprawidłowe dane.Wprowadź prawidłowe imię i nazwisko.");
            return;
        }

        members.Add(new Member(name));
        Console.WriteLine("Dodano użytkownika.");
    }

    static bool IsValidName(string name)
    {
        if (string.IsNullOrWhiteSpace(name)) return false;
        if (name.Any(char.IsDigit)) return false;
        if (name.Length < 3) return false;
        if (!name.Any(char.IsUpper)) return false;
        if (!name.Any(char.IsLower)) return false;
        return true;
    }

    static Member SelectMember()
    {
        if (members.Count == 0)
        {
            Console.WriteLine("Brak użytkowników.");
            return null;
        }

        Console.WriteLine("Użytkownicy:");
        for (int i = 0; i < members.Count; i++)
        {
            Console.WriteLine($"{i + 1}. {members[i].Name}");
        }

        Console.Write("Wybierz numer: ");
        if (int.TryParse(Console.ReadLine(), out int index) && index >= 1 && index <= members.Count)
        {
            return members[index - 1];
        }

        Console.WriteLine("Nieprawidłowy numer.");
        return null;
    }

    static Book GetBookByFixedNumber()
    {
        Console.WriteLine("Książki:");
        Console.WriteLine("1. Dziady - Adam Mickiewicz");
        Console.WriteLine("2. Lalka - Bolesław Prus");
        Console.WriteLine("3. Quo Vadis - Henryk Sienkiewicz");
        Console.Write("Wybierz numer książki: ");

        if (int.TryParse(Console.ReadLine(), out int choice) && choice >= 1 && choice <= 3)
        {
            return books[choice - 1];
        }

        Console.WriteLine("Nieprawidłowy numer.");
        return null;
    }

    static void BorrowBook()
    {
        var member = SelectMember();
        if (member == null) return;

        var book = GetBookByFixedNumber();
        if (book == null) return;

        member.Borrow(book);
    }

    static void ReturnBook()
    {
        var member = SelectMember();
        if (member == null) return;

        var book = GetBookByFixedNumber();
        if (book == null) return;

        member.Return(book);
    }

    static void ShowBooks()
    {
        Console.WriteLine("Lista książek:");
        for (int i = 0; i < books.Count; i++)
        {
            var b = books[i];
            Console.WriteLine($"{i + 1}. {b.Title} - {b.Author} ({(b.IsLoaned ? "wypożyczona" : "dostępna")})");
        }
    }

    static void ShowMyBooks()
    {
        var member = SelectMember();
        if (member == null) return;

        if (member.BorrowedBooks.Count == 0)
        {
            Console.WriteLine("Nie masz żadnych wypożyczonych książek.");
        }
        else
        {
            Console.WriteLine("Twoje książki:");
            foreach (var book in member.BorrowedBooks)
            {
                Console.WriteLine($"- {book.Title} - {book.Author}");
            }
        }
    }
}
