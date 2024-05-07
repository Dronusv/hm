
#include <iostream>
#include <vector>
#include <map>
#include <chrono> 
#include "sql_query_builder.h"



int main()
{
    SQL_queryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");
    std::map<std::string, std::string> m{ {"soname","bak"},{"wife","Liza"} };
    std::vector<std::string> v{"soname","wife"};
    query_builder.AddWhere(m);
    query_builder.AddColumns(v);
    std::cout << query_builder.BuildQuery();
        
}

