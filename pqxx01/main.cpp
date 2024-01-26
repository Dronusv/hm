#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <string	>
class bd {
public:
	void creatbd(pqxx::connection& conn) {
		pqxx::transaction tx{ conn };
		tx.exec("CREATE TABLE public.Person ("
			"id serial PRIMARY KEY,"
			"name text NOT NULL,"
			"last_name text NOT NULL,"
			"email text NOT NULL);");
		tx.exec("CREATE TABLE public.Phone ("
			"id serial PRIMARY KEY,"
			"personId INTEGER  REFERENCES public.Person(id),"
			"number varchar NOT NULL);");
		tx.commit();
	}
	void insert_person(pqxx::connection& conn,std::string name,std::string last_name,std::string email) {
		pqxx::transaction tx{ conn };
		tx.exec("INSERT INTO public.Person(name, last_name, email)"
			"VALUES('" + tx.esc(name) + "','" + tx.esc(last_name) + "','" + tx.esc(email) + "');");
		tx.commit();
	}
	int get_id_person(pqxx::connection& conn, std::string name, std::string last_name, std::string email) {
		pqxx::transaction tx{ conn };
		int id_person = tx.query_value<int>("SELECT id FROM public.Person WHERE name = '" + tx.esc(name) + "' AND last_name = '" + tx.esc(last_name) + "' AND email = '" + tx.esc(email) + "';");
		return id_person;
	}
	void insert_phone(pqxx::connection& conn, int id_person,std::string number) {
		pqxx::transaction tx{ conn };
		tx.exec("INSERT INTO public.Phone(personId,number)"
			"VALUES('" + std::to_string(id_person) + "','" + tx.esc(number) + "');");
		tx.commit();
	}
	void update_person(pqxx::connection& conn, int id_person, std::string newname, std::string newlast_name, std::string newemail) {
		pqxx::transaction tx{ conn };
		tx.exec("UPDATE public.Person SET name='" + tx.esc(newname) + "', last_name= '" + tx.esc(newlast_name) + "', email = '" + tx.esc(newemail) + "' WHERE id = " + std::to_string(id_person) + ";");
		tx.commit();
	}
	void delete_phone(pqxx::connection& conn, std::string number) {
		pqxx::transaction tx{ conn };
		tx.exec("DELETE FROM public.Phone WHERE number = '" + tx.esc(number)+"';");
		tx.commit();
	}
	void delete_person(pqxx::connection& conn, int id_person) {
		pqxx::transaction tx{ conn };
		tx.exec("DELETE FROM public.Phone WHERE personId = '" + std::to_string(id_person) + "';");
		tx.exec("DELETE FROM public.Person WHERE id = '" + std::to_string(id_person) + "';");
		tx.commit();
	}
	auto search_person(pqxx::connection& conn,std::string str){
		pqxx::transaction tx{ conn };
		auto ptr = tx.query<int,std::string, std::string, std::string>("SELECT id, name, last_name, email FROM public.Person WHERE name='" + tx.esc(str) + "' OR last_name= '" + tx.esc(str) + "' OR email = '" + tx.esc(str) + "';");
		return ptr;
	}
	auto search_person_phone(pqxx::connection& conn, std::string number) {
		pqxx::transaction tx{ conn };
		
		int idphone=tx.query_value<int>("SELECT id FROM public.Phone WHERE number = '" + tx.esc(number) + "';");
		int id_person = tx.query_value<int>("SELECT personId FROM public.Phone WHERE id= '" + std::to_string(idphone) + "';");
		auto ptr = tx.query<int, std::string, std::string, std::string>("SELECT id, name, last_name, email FROM public.Person WHERE id = '" + std::to_string(id_person) + "';");
		return ptr;
	}
	
private:
	
};
int main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	try {
		pqxx::connection conn("dbname=postgres "
			"host=localhost "
			"port=5432 "
			"user=postgres "
			"password=Dronusv222");

		 
		bd base;
		base.creatbd(conn);
		base.insert_person(conn, "Роман", "Бакушин", "Dronusv22@mail.ru");
		base.insert_person(conn, "Арина", "Бакушина", "Улолыа@mail.ru");
		int idPersonA = base.get_id_person(conn, "Арина", "Бакушина", "Улолыа@mail.ru");
		int idPersonR=base.get_id_person(conn, "Роман", "Бакушин", "Dronusv22@mail.ru");
		base.insert_phone(conn, idPersonR, "89892093232");
		base.insert_phone(conn, idPersonR, "89505679983");
		base.insert_phone(conn, idPersonA, "89528891683");
		base.update_person(conn, idPersonR, "Лиза", "Бакушина", "YFqc");
		base.delete_phone(conn, "89892093232");
		base.delete_person(conn, idPersonA);
		auto res = base.search_person(conn, "Лиза");
		auto res2 = base.search_person_phone(conn, "89505679983");

		for (auto [id,name,last_name,email] : res) {

			std::cout << id << " " << name << " " << last_name << " " << email << "\n";
		}
		for (auto [id, name, last_name, email] : res2) {

			std::cout << id << " " << name << " " << last_name << " " << email << "\n";
		}
		

	}	
	catch (const std::exception ex) {
		std::cout << ex.what()<<"\n";
	}
}