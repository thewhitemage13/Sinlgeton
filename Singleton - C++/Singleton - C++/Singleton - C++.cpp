#include <iostream>
#include <string>
using namespace std;

class DatabaseHelper {
	DatabaseHelper() {
		cout << "Database Connection...\n";
	};

	static DatabaseHelper* DataBaseConnection;

	string data;
public:
	DatabaseHelper(const DatabaseHelper&) = delete;
	void operator = (const DatabaseHelper&) = delete;

	static DatabaseHelper* GetConnection() {
		if (DataBaseConnection == nullptr)
			DataBaseConnection = new DatabaseHelper();
		return DataBaseConnection;
	}

	string SelectData() const {
		return data;
	}

	void InsertData(string data) {
		this->data = data;
		cout << "new data: " << data << " entered into the database\n";
	}
};

DatabaseHelper* DatabaseHelper::DataBaseConnection = nullptr;

int main() {
	DatabaseHelper::GetConnection()->InsertData("123");
	cout << "Data from DB: " << DatabaseHelper::GetConnection()->SelectData() << "\n";
}