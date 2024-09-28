def conditional_program():
    month = input("Enter a month and I shall tell you what season it is!: ")
    month_lower = month.lower()

    if month_lower in {"december", "january", "february"}:
        season = "Winter! So do not forget your coats and stay warm!☃️"
    elif month_lower in {"march", "april", "may"}:
        season = "Spring! Perfect time to go and have a picnic. 💐"
    elif month_lower in {"june", "july", "august"}:
        season = "Summer! So grab your sunscreen and get ready to swim! 🌞"
    elif month_lower in {"september", "october", "november"}:
        season = "Fall! Time to enjoy the beautiful change of the season! 🍂"
    else:
        season = "Invalid month"

    print(f"The season for {month} is {season}.")

def list_program():
    number_list_str = input("Enter a list of numbers separated by spaces: ")
    user_number_list = [int(num) for num in number_list_str.split()]

    print("User-entered list of numbers:", user_number_list)

    number_count = {}
    for number in user_number_list:
        number_count[number] = number_count.get(number, 0) + 1

    print("Number count:", number_count)

    most_common_number = max(number_count, key=number_count.get)

    print("Most common number:", most_common_number)
    print("Count:", number_count[most_common_number])

def dictionary_program():
    shopping_list = []

    print("\tGood day User! I am your Shopping Assistant, I will help you keep a list of your grocery! 📄")

    def add_item(item):
        shopping_list.append(item)
        print(f"{item} added to the shopping list.")

    def remove_item(item):
        if item in shopping_list:
            shopping_list.remove(item)
            print(f"{item} removed from the shopping list.")
        else:
            print(f"{item} not found in the shopping list.")

    def view_list():
        print("\nYour Shopping List 📄:")
        for item in shopping_list:
            print(f"- {item}")

    while True:
        print("\nMenu:")
        print("\t1. Add item to the list")
        print("\t2. Remove item from the list")
        print("\t3. View list")
        print("\t4. Exit")

        choice = input("\tEnter your choice (1-4): ")

        if choice == "1":
            item_to_add = input("\tEnter the item to add: ")
            add_item(item_to_add)
        elif choice == "2":
            item_to_remove = input("\tEnter the item to remove: ")
            remove_item(item_to_remove)
        elif choice == "3":
            view_list()
        elif choice == "4":
            print("\tExiting the program. Thank you!")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 4.")

# Programmer's Profile
def programmers_profile():
    print("\nWelcome to the Programmer's Profile!")
    print("==========================================================")
    print("\nMeet the Programmer!")
    print("\tName: Emm Katrina L. Caayao")
    print("\tCourse and Section: BSIS - 2B // 2nd Year 1st Semester")
    print("\tSubject: Object Oriented Programming")
    print("\tUniversity: Technological University of the Philippines - Manila")
    print("\tAge and Birthday: 19 years old // February 03, 2004")
    print("\tFrom: Imus City, Cavite")
    print("\n==========================================================")
    print("\nMiscellaneous things about Programmer")
    print("\tFavorite color is ✨ R e d ✨")
    print("\tA Digital Artist with big dreams")
    print("\tShy but ambitious and opinionated, rawr")
    print("\tCurrently nasa Fish-Man Island Arc ng One piece")
    print("\tMiddle child ako with an older brother and a younger brother")
    print("\n==========================================================")

# Main Menu
while True:
    print("\nMain Menu:")
    print("\tA. Conditional Program")
    print("\tB. List Program")
    print("\tC. Dictionary Program")
    print("\tD. Programmer's Profile")
    print("\tE. Exit")

    user_choice = input("Enter your choice (A-E): ")

    if user_choice.upper() == "A":
        conditional_program()
    elif user_choice.upper() == "B":
        list_program()
    elif user_choice.upper() == "C":
        dictionary_program()
    elif user_choice.upper() == "D":
        programmers_profile()
    elif user_choice.upper() == "E":
        print("Exiting the program. See you next time!")
        break
    else:
        print("Invalid choice. Please enter a valid option (A-E).")
