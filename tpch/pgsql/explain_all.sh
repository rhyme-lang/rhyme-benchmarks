#!/bin/bash

OUTPUT="plans.txt"
> "$OUTPUT"

explain_query() {
    local i=$1
    local QUERY_FILE="./queries/${i}.sql"

    echo "========================================" >> "$OUTPUT"
    echo "Query ${i}" >> "$OUTPUT"
    echo "========================================" >> "$OUTPUT"
    echo "" >> "$OUTPUT"
    echo "-- SQL:" >> "$OUTPUT"
    cat "$QUERY_FILE" >> "$OUTPUT"
    echo "" >> "$OUTPUT"
    echo "-- EXPLAIN:" >> "$OUTPUT"

    if [ "$i" -eq 15 ]; then
        # Q15 creates a view, selects from it, then drops it; EXPLAIN only the SELECT
        psql -U postgres -c "create view revenue0 (supplier_no, total_revenue) as
            select l_suppkey, sum(l_extendedprice * (1 - l_discount))
            from lineitem
            where l_shipdate >= date '1996-01-01'
              and l_shipdate < date '1996-01-01' + interval '3' month
            group by l_suppkey;" 2>> "$OUTPUT"

        psql -U postgres -c "EXPLAIN select s_suppkey, s_name, s_address, s_phone, total_revenue
            from supplier, revenue0
            where s_suppkey = supplier_no
              and total_revenue = (select max(total_revenue) from revenue0)
            order by s_suppkey LIMIT 1;" >> "$OUTPUT"

        psql -U postgres -c "drop view revenue0;" 2>> "$OUTPUT"
    else
        psql -U postgres -c "EXPLAIN $(cat "$QUERY_FILE")" >> "$OUTPUT"
    fi

    echo "" >> "$OUTPUT"
}

for i in $(seq 1 22); do
    explain_query "$i"
done
