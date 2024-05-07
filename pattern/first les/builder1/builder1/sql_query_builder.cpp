#include <iostream>
#include <vector>
#include <map>
#include <chrono> 
#include "sql_query_builder.h"




 SQL_queryBuilder::SQL_queryBuilder() {

}
std::string SQL_queryBuilder::BuildQuery() noexcept {
        std::string str;
        std::string select = "SELECT ";
        if (SQL_query.SELECT.size() > 0) {
            for (int i = 0; i < SQL_query.SELECT.size(); ++i) {
                select += SQL_query.SELECT[i];
                if (i < SQL_query.SELECT.size() - 1) {
                    select += ", ";
                }
                else {
                    select += " ";
                }
            }
        }
        else {
            select += "* ";
        }
        std::string from = "FROM " + SQL_query.FROM + " ";

        std::string where = "WHERE ";
        for (int i = 0; i < SQL_query.WHERE.size(); ++i) {
            where += SQL_query.WHERE[i].first + "=" + SQL_query.WHERE[i].second;
            if (i < SQL_query.WHERE.size() - 1) {
                where += " AND ";
            }
        }
        str = select + from + where + ";";
        return str;
    }

SQL_queryBuilder& SQL_queryBuilder::AddColumn(std::string column) noexcept {
    SQL_query.SELECT.push_back(column);
    return *this;
}

SQL_queryBuilder& SQL_queryBuilder::AddFrom(std::string from) {
    SQL_query.FROM = from;
    return *this;
}
SQL_queryBuilder& SQL_queryBuilder::AddWhere(std::string lhs, std::string rhs) {
    std::pair <std::string, std::string> wh(lhs, rhs);
    SQL_query.WHERE.push_back(wh);
    return *this;
}
SQL_queryBuilder& SQL_queryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept {
    for (auto c : kv) {
        SQL_query.WHERE.push_back(c);
    }
    return *this;
}
SQL_queryBuilder& SQL_queryBuilder::AddColumns(const std::vector<std::string>& columns) noexcept {
    for (int i = 0; i < columns.size(); ++i) {
        SQL_query.SELECT.push_back(columns[i]);
    }
    return *this;
}
