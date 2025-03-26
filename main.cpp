#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>

// Member class to represent gym members
class Member {
private:
    // Private attributes to store member details
    int memberId;
    std::string name;
    int age;
    std::string phoneNumber;
    std::string membershipType;
    std::string registrationDate;

public:
    // Constructor to initialize member details
    Member(int id, const std::string& memberName, int memberAge,
           const std::string& phone, const std::string& memType,
           const std::string& regDate) {
        memberId = id;
        name = memberName;
        age = memberAge;
        phoneNumber = phone;
        membershipType = memType;
        registrationDate = regDate;
    }

    // Getter methods to access private attributes
    int getMemberId() const { return memberId; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getMembershipType() const { return membershipType; }
    std::string getRegistrationDate() const { return registrationDate; }

    // Method to update member details
    void updateDetails(const std::string& newName, int newAge,
                       const std::string& newPhone,
                       const std::string& newMemType) {
        name = newName;
        age = newAge;
        phoneNumber = newPhone;
        membershipType = newMemType;
    }
};

// GymMembershipSystem class to manage members
class GymMembershipSystem {
private:
    std::vector<Member> members;
    int nextMemberId;

    // Input validation methods
    bool isValidName(const std::string& name) {
        return std::all_of(name.begin(), name.end(), [](char c) {
            return std::isalpha(c) || std::isspace(c);
        });
    }

    bool isValidAge(int age) {
        return age > 0 && age < 120;
    }

    bool isValidPhoneNumber(const std::string& phone) {
        return phone.length() == 10 &&
               std::all_of(phone.begin(), phone.end(), ::isdigit);
    }

public:
    // Constructor
    GymMembershipSystem() : nextMemberId(1) {}

    // Method to add a new member
    void addMember() {
        std::string name, phone, memType, regDate;
        int age;

        // Input validation
        while (true) {
            std::cout << "Enter Member Name: ";
            std::getline(std::cin, name);
            if (isValidName(name)) break;
            std::cout << "Invalid name. Use only letters.\n";
        }

        while (true) {
            std::cout << "Enter Age: ";
            std::cin >> age;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (isValidAge(age)) break;
            std::cout << "Invalid age. Must be between 1 and 120.\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (true) {
            std::cout << "Enter Phone Number (10 digits): ";
            std::getline(std::cin, phone);
            if (isValidPhoneNumber(phone)) break;
            std::cout << "Invalid phone number. Must be 10 digits.\n";
        }

        std::cout << "Enter Membership Type: ";
        std::getline(std::cin, memType);

        // Get current date (simplified)
        regDate = "2024-03-26"; // You can replace with actual date retrieval

        // Create and add member
        members.emplace_back(nextMemberId++, name, age, phone, memType, regDate);
        std::cout << "Member added successfully with ID: " << nextMemberId - 1 << std::endl;
    }

    // Method to view all members
    void viewMembers() {
        if (members.empty()) {
            std::cout << "No members registered.\n";
            return;
        }

        std::cout << std::left
                  << std::setw(10) << "Member ID"
                  << std::setw(20) << "Name"
                  << std::setw(10) << "Age"
                  << std::setw(15) << "Phone"
                  << std::setw(15) << "Membership"
                  << std::setw(15) << "Reg. Date" << std::endl;
        std::cout << std::string(85, '-') << std::endl;

        for (const auto& member : members) {
            std::cout << std::left
                      << std::setw(10) << member.getMemberId()
                      << std::setw(20) << member.getName()
                      << std::setw(10) << member.getAge()
                      << std::setw(15) << member.getPhoneNumber()
                      << std::setw(15) << member.getMembershipType()
                      << std::setw(15) << member.getRegistrationDate() << std::endl;
        }
    }

    // Method to update a member's details
    void updateMember() {
        int id;
        std::cout << "Enter Member ID to update: ";
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        auto it = std::find_if(members.begin(), members.end(),
            [id](const Member& m) { return m.getMemberId() == id; });

        if (it != members.end()) {
            std::string newName, newPhone, newMemType;
            int newAge;

            // Reuse validation logic from addMember
            while (true) {
                std::cout << "Enter New Name: ";
                std::getline(std::cin, newName);
                if (isValidName(newName)) break;
                std::cout << "Invalid name. Use only letters.\n";
            }

            while (true) {
                std::cout << "Enter New Age: ";
                std::cin >> newAge;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a number.\n";
                    continue;
                }
                if (isValidAge(newAge)) break;
                std::cout << "Invalid age. Must be between 1 and 120.\n";
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            while (true) {
                std::cout << "Enter New Phone Number (10 digits): ";
                std::getline(std::cin, newPhone);
                if (isValidPhoneNumber(newPhone)) break;
                std::cout << "Invalid phone number. Must be 10 digits.\n";
            }

            std::cout << "Enter New Membership Type: ";
            std::getline(std::cin, newMemType);

            it->updateDetails(newName, newAge, newPhone, newMemType);
            std::cout << "Member details updated successfully.\n";
        } else {
            std::cout << "Member not found.\n";
        }
    }

    // Method to delete a member
    void deleteMember() {
        int id;
        std::cout << "Enter Member ID to delete: ";
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        auto it = std::find_if(members.begin(), members.end(),
            [id](const Member& m) { return m.getMemberId() == id; });

        if (it != members.end()) {
            members.erase(it);
            std::cout << "Member deleted successfully.\n";
        } else {
            std::cout << "Member not found.\n";
        }
    }

    // Main menu method
    void runSystem() {
        int choice;
        do {
            std::cout << "\n--- Gym Membership Management System ---\n";
            std::cout << "1. Add New Member\n";
            std::cout << "2. View All Members\n";
            std::cout << "3. Update Member Details\n";
            std::cout << "4. Delete Member\n";
            std::cout << "5. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
                case 1: addMember(); break;
                case 2: viewMembers(); break;
                case 3: updateMember(); break;
                case 4: deleteMember(); break;
                case 5: std::cout << "Exiting system...\n"; break;
                default: std::cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 5);
    }
};

// Main function to start the system
int main() {
    GymMembershipSystem gymSystem;
    gymSystem.runSystem();
    return 0;
}
