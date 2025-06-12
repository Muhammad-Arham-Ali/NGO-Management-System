Alif Insaan NGO Management System
A complete C++ console-based application to manage the operations of an NGO. The system includes role-based access (Admin and Agent), and provides features to add, edit, delete, view, search, and sort data related to projects, donations, volunteers, beneficiaries, and suggestions. All data is saved using text file I/O, and stored in memory using arrays.
________________________________________

🚀 Features
•	🔐 Admin and Agent login/signup system
•	📁 Persistent file storage using ifstream and ofstream
•	📋 Add / View / Edit / Delete:
o	Projects (name + description)
o	Volunteers
o	Beneficiaries
o	Donors and Donations
o	Suggestions
•	🔍 Search data by name
•	🔠 Sort data alphabetically
•	🧠 Uses:
o	1D and 2D arrays
o	Modular C++ functions
o	Menu-based console UI
o	Pass-by-reference for real-time data updates
________________________________________

🧑‍💻 Technologies Used
•	Language: C++
•	Compiler: g++ (GCC / MinGW)
•	Platform: Windows/Linux console
________________________________________

📂 File Structure
📦 AlifInsaanNGO
 ┣ 📄 main.cpp
 ┣ 📄 projects.txt
 ┣ 📄 projectdescription.txt
 ┣ 📄 volunteers.txt
 ┣ 📄 donations.txt
 ┣ 📄 donor.txt
 ┣ 📄 beneficiaries.txt
 ┣ 📄 suggestions.txt
 ┣ 📄 admin.txt / adminPassword.txt
 ┣ 📄 agent.txt / agentPassword.txt
________________________________________

🔧 How to Run
g++ main.cpp -o NGOApp
./NGOApp
Or use a C++ IDE like Code::Blocks, Dev-C++, or Visual Studio with console support.
Ensure all .txt data files are in the same folder as your compiled .exe, or the program will create them on first run.
________________________________________

📚 What You’ll Learn
•	How to implement login/signup functionality with file-backed storage
•	How to manage data using arrays
•	File I/O in C++
•	Menu-driven programming
•	String manipulation and array sorting/searching
________________________________________

🌱 Future Improvements
•	Use vector or classes instead of static arrays
•	Convert to object-oriented design (OOP)
•	Add password encryption
•	Export/import using .csv or .json
•	Build GUI using Qt or web frontend
________________________________________

🙌 Contributing
This project was created for educational purposes. Contributions to make it more modular or OOP-based are welcome!
________________________________________

“Making a difference through organized code.”
