#pragma once

struct SQL_query {
    std::vector<std::string> SELECT;
    std::string FROM;
    std::vector<std::pair<std::string, std::string>> WHERE;
};

class SQL_queryBuilder {
public:
    explicit SQL_queryBuilder();
    std::string BuildQuery() noexcept;
    SQL_queryBuilder& AddColumn(std::string column) noexcept;
    SQL_queryBuilder& AddFrom(std::string from);
    SQL_queryBuilder& AddWhere(std::string lhs, std::string rhs);
    SQL_queryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;
    SQL_queryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
private:
    SQL_query SQL_query;
};