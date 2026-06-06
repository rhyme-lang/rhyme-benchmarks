#include "rhyme-c.h"
typedef int (*__compar_fn_t)(const void *, const void *);
struct tmp3__DEFAULT__arr {
    int count$;
    int32_t *l_suppkey$;
    double *l_extendedprice$;
    double *l_discount$;
};
struct tmp5__DEFAULT__arr {
    int count$;
    int32_t *l_suppkey$;
    double *l_extendedprice$;
    double *l_discount$;
    int32_t *o_orderdate$;
};
struct tmp11__DEFAULT__arr {
    int count$;
    double *l_extendedprice$;
    double *l_discount$;
    int32_t *o_orderdate$;
};
int32_t *tmp18_year;
int compare_func0(int *i, int *j) {
    int tmp_cmp0 = ((tmp18_year[*i] < tmp18_year[*j]) ? -1 : ((tmp18_year[*i] > tmp18_year[*j]) ? 1 : 0));
    return tmp_cmp0;
}
int main() {
    struct timeval timeval0;
    gettimeofday(&timeval0, NULL);
    long t0 = ((timeval0.tv_sec * 1000000L) + timeval0.tv_usec);
    // init hashmap for tmp2
    // keys of tmp2
    int32_t *tmp2_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp2
    int tmp2_key_count = 0;
    // hash table for tmp2
    int *tmp2_htable = (int *)calloc(16777216, sizeof(int));
    // value of tmp2: _DEFAULT_
    int32_t *tmp2__DEFAULT_ = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    uint8_t *tmp2__DEFAULT__defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // init hashmap for tmp3
    // keys of tmp3
    int32_t *tmp3_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp3
    int tmp3_key_count = 0;
    // hash table for tmp3
    int *tmp3_htable = (int *)calloc(16777216, sizeof(int));
    struct tmp3__DEFAULT__arr **tmp3__DEFAULT_ = (struct tmp3__DEFAULT__arr **)malloc(sizeof(struct tmp3__DEFAULT__arr *) * 16777216);
    // init hashmap for tmp5
    // keys of tmp5
    int32_t *tmp5_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp5
    int tmp5_key_count = 0;
    // hash table for tmp5
    int *tmp5_htable = (int *)calloc(16777216, sizeof(int));
    struct tmp5__DEFAULT__arr **tmp5__DEFAULT_ = (struct tmp5__DEFAULT__arr **)malloc(sizeof(struct tmp5__DEFAULT__arr *) * 16777216);
    // init hashmap for tmp9
    // keys of tmp9
    int32_t *tmp9_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp9
    int tmp9_key_count = 0;
    // hash table for tmp9
    int *tmp9_htable = (int *)calloc(16777216, sizeof(int));
    // value of tmp9: _DEFAULT_
    int32_t *tmp9__DEFAULT_ = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    uint8_t *tmp9__DEFAULT__defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // init hashmap for tmp10
    // keys of tmp10
    int32_t *tmp10_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp10
    int tmp10_key_count = 0;
    // hash table for tmp10
    int *tmp10_htable = (int *)calloc(16777216, sizeof(int));
    // value of tmp10: _DEFAULT_
    int32_t *tmp10__DEFAULT_ = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    uint8_t *tmp10__DEFAULT__defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // init hashmap for tmp11
    // keys of tmp11
    int32_t *tmp11_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp11
    int tmp11_key_count = 0;
    // hash table for tmp11
    int *tmp11_htable = (int *)calloc(16777216, sizeof(int));
    struct tmp11__DEFAULT__arr **tmp11__DEFAULT_ = (struct tmp11__DEFAULT__arr **)malloc(sizeof(struct tmp11__DEFAULT__arr *) * 16777216);
    // init hashmap for tmp18
    // keys of tmp18
    int32_t *tmp18_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp18
    int tmp18_key_count = 0;
    // hash table for tmp18
    int *tmp18_htable = (int *)calloc(16777216, sizeof(int));
    // value of tmp18: year
    (tmp18_year = (int32_t *)malloc(sizeof(int32_t) * 16777216));
    uint8_t *tmp18_year_defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // value of tmp18: mkt_share
    double *tmp18_mkt_share = (double *)malloc(sizeof(double) * 16777216);
    uint8_t *tmp18_mkt_share_defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // value of tmp15: _DEFAULT_
    double *tmp15__DEFAULT_ = (double *)malloc(sizeof(double) * 16777216);
    uint8_t *tmp15__DEFAULT__defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // init hashmap for tmp14
    // keys of tmp14
    int32_t *tmp14_keys0 = (int32_t *)malloc(sizeof(int32_t) * 16777216);
    // key count for tmp14
    int tmp14_key_count = 0;
    // hash table for tmp14
    int *tmp14_htable = (int *)calloc(16777216, sizeof(int));
    // value of tmp14: _DEFAULT_
    const char **tmp14__DEFAULT__str = (const char **)malloc(sizeof(const char *) * 16777216);
    int *tmp14__DEFAULT__len = (int *)malloc(sizeof(int) * 16777216);
    uint8_t *tmp14__DEFAULT__defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    // value of tmp16: _DEFAULT_
    double *tmp16__DEFAULT_ = (double *)malloc(sizeof(double) * 16777216);
    uint8_t *tmp16__DEFAULT__defined = (uint8_t *)calloc(16777216, sizeof(uint8_t));
    int fd0 = open("../data//lineitem.tbl", 0);
    if ((fd0 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//lineitem.tbl");
        return 1;
    }
    size_t n0 = fsize(fd0);
    char *file_tbl0 = mmap(0, n0, PROT_READ, MAP_FILE | MAP_SHARED, fd0, 0);
    close(fd0);
    // init array for preloaded0
    int preloaded0_data_count;
    (preloaded0_data_count = 0);
    // value of preloaded0: l_orderkey
    int32_t *preloaded0_l_orderkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded0: l_partkey
    int32_t *preloaded0_l_partkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded0: l_suppkey
    int32_t *preloaded0_l_suppkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded0: l_extendedprice
    double *preloaded0_l_extendedprice = (double *)malloc(sizeof(double) * 60000000);
    // value of preloaded0: l_discount
    double *preloaded0_l_discount = (double *)malloc(sizeof(double) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//lineitem.tbl)
    size_t i0 = 0;
    for (size_t preload_iter = 0; i0 < n0; preload_iter++) {
        // reading column l_orderkey
        int32_t file_tbl0_preload_iter_l_orderkey = 0;
        int32_t tmp_negative4 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative4 = 1);
            i0++;
        }
        while ((file_tbl0[i0] != '|')) {
            // extract integer
            (file_tbl0_preload_iter_l_orderkey = ((file_tbl0_preload_iter_l_orderkey * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        i0++;
        if (tmp_negative4) {
            (file_tbl0_preload_iter_l_orderkey = -file_tbl0_preload_iter_l_orderkey);
        }
        // reading column l_partkey
        int32_t file_tbl0_preload_iter_l_partkey = 0;
        int32_t tmp_negative3 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative3 = 1);
            i0++;
        }
        while ((file_tbl0[i0] != '|')) {
            // extract integer
            (file_tbl0_preload_iter_l_partkey = ((file_tbl0_preload_iter_l_partkey * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        i0++;
        if (tmp_negative3) {
            (file_tbl0_preload_iter_l_partkey = -file_tbl0_preload_iter_l_partkey);
        }
        // reading column l_suppkey
        int32_t file_tbl0_preload_iter_l_suppkey = 0;
        int32_t tmp_negative2 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative2 = 1);
            i0++;
        }
        while ((file_tbl0[i0] != '|')) {
            // extract integer
            (file_tbl0_preload_iter_l_suppkey = ((file_tbl0_preload_iter_l_suppkey * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        i0++;
        if (tmp_negative2) {
            (file_tbl0_preload_iter_l_suppkey = -file_tbl0_preload_iter_l_suppkey);
        }
        // reading column l_linenumber
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_quantity
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_extendedprice
        long number1 = 0;
        long scale1 = 1;
        int tmp_negative1 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative1 = 1);
            i0++;
        }
        while (((file_tbl0[i0] != '.') && (file_tbl0[i0] != '|'))) {
            // extract integer part
            (number1 = ((number1 * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        if ((file_tbl0[i0] == '.')) {
            i0++;
            while ((file_tbl0[i0] != '|')) {
                // extract fractional part
                (number1 = ((number1 * 10) + (file_tbl0[i0] - '0')));
                (scale1 = (scale1 * 10));
                i0++;
            }
        }
        double file_tbl0_preload_iter_l_extendedprice = ((double)number1 / scale1);
        i0++;
        if (tmp_negative1) {
            (file_tbl0_preload_iter_l_extendedprice = -file_tbl0_preload_iter_l_extendedprice);
        }
        // reading column l_discount
        long number0 = 0;
        long scale0 = 1;
        int tmp_negative0 = 0;
        if ((file_tbl0[i0] == '-')) {
            (tmp_negative0 = 1);
            i0++;
        }
        while (((file_tbl0[i0] != '.') && (file_tbl0[i0] != '|'))) {
            // extract integer part
            (number0 = ((number0 * 10) + (file_tbl0[i0] - '0')));
            i0++;
        }
        if ((file_tbl0[i0] == '.')) {
            i0++;
            while ((file_tbl0[i0] != '|')) {
                // extract fractional part
                (number0 = ((number0 * 10) + (file_tbl0[i0] - '0')));
                (scale0 = (scale0 * 10));
                i0++;
            }
        }
        double file_tbl0_preload_iter_l_discount = ((double)number0 / scale0);
        i0++;
        if (tmp_negative0) {
            (file_tbl0_preload_iter_l_discount = -file_tbl0_preload_iter_l_discount);
        }
        // reading column l_tax
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_returnflag
        (i0 = (i0 + 2));
        // reading column l_linestatus
        (i0 = (i0 + 2));
        // reading column l_shipdate
        (i0 = (i0 + 11));
        // reading column l_commitdate
        (i0 = (i0 + 11));
        // reading column l_receiptdate
        (i0 = (i0 + 11));
        // reading column l_shipinstruct
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_shipmode
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        // reading column l_comment
        while ((file_tbl0[i0] != '|')) i0++;
        i0++;
        i0++;
        (preloaded0_l_orderkey[preloaded0_data_count] = file_tbl0_preload_iter_l_orderkey);
        (preloaded0_l_partkey[preloaded0_data_count] = file_tbl0_preload_iter_l_partkey);
        (preloaded0_l_suppkey[preloaded0_data_count] = file_tbl0_preload_iter_l_suppkey);
        (preloaded0_l_extendedprice[preloaded0_data_count] = file_tbl0_preload_iter_l_extendedprice);
        (preloaded0_l_discount[preloaded0_data_count] = file_tbl0_preload_iter_l_discount);
        (preloaded0_data_count = (preloaded0_data_count + 1));
    }
    int fd1 = open("../data//part.tbl", 0);
    if ((fd1 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//part.tbl");
        return 1;
    }
    size_t n1 = fsize(fd1);
    char *file_tbl1 = mmap(0, n1, PROT_READ, MAP_FILE | MAP_SHARED, fd1, 0);
    close(fd1);
    // init array for preloaded1
    int preloaded1_data_count;
    (preloaded1_data_count = 0);
    // value of preloaded1: p_partkey
    int32_t *preloaded1_p_partkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded1: p_type
    const char **preloaded1_p_type_str = (const char **)malloc(sizeof(const char *) * 60000000);
    int *preloaded1_p_type_len = (int *)malloc(sizeof(int) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//part.tbl)
    size_t i1 = 0;
    for (size_t preload_iter = 0; i1 < n1; preload_iter++) {
        // reading column p_partkey
        int32_t file_tbl1_preload_iter_p_partkey = 0;
        int32_t tmp_negative5 = 0;
        if ((file_tbl1[i1] == '-')) {
            (tmp_negative5 = 1);
            i1++;
        }
        while ((file_tbl1[i1] != '|')) {
            // extract integer
            (file_tbl1_preload_iter_p_partkey = ((file_tbl1_preload_iter_p_partkey * 10) + (file_tbl1[i1] - '0')));
            i1++;
        }
        i1++;
        if (tmp_negative5) {
            (file_tbl1_preload_iter_p_partkey = -file_tbl1_preload_iter_p_partkey);
        }
        // reading column p_name
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        // reading column p_mfgr
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        // reading column p_brand
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        // reading column p_type
        size_t file_tbl1_preload_iter_p_type_start = i1;
        while ((file_tbl1[i1] != '|')) i1++;
        size_t file_tbl1_preload_iter_p_type_end = i1;
        i1++;
        // reading column p_size
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        // reading column p_container
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        // reading column p_retailprice
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        // reading column p_comment
        while ((file_tbl1[i1] != '|')) i1++;
        i1++;
        i1++;
        (preloaded1_p_partkey[preloaded1_data_count] = file_tbl1_preload_iter_p_partkey);
        (preloaded1_p_type_str[preloaded1_data_count] = (file_tbl1 + file_tbl1_preload_iter_p_type_start));
        (preloaded1_p_type_len[preloaded1_data_count] = (file_tbl1_preload_iter_p_type_end - file_tbl1_preload_iter_p_type_start));
        (preloaded1_data_count = (preloaded1_data_count + 1));
    }
    int fd2 = open("../data//orders.tbl", 0);
    if ((fd2 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//orders.tbl");
        return 1;
    }
    size_t n2 = fsize(fd2);
    char *file_tbl2 = mmap(0, n2, PROT_READ, MAP_FILE | MAP_SHARED, fd2, 0);
    close(fd2);
    // init array for preloaded2
    int preloaded2_data_count;
    (preloaded2_data_count = 0);
    // value of preloaded2: o_orderkey
    int32_t *preloaded2_o_orderkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded2: o_custkey
    int32_t *preloaded2_o_custkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded2: o_orderdate
    int32_t *preloaded2_o_orderdate = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//orders.tbl)
    size_t i2 = 0;
    for (size_t preload_iter = 0; i2 < n2; preload_iter++) {
        // reading column o_orderkey
        int32_t file_tbl2_preload_iter_o_orderkey = 0;
        int32_t tmp_negative7 = 0;
        if ((file_tbl2[i2] == '-')) {
            (tmp_negative7 = 1);
            i2++;
        }
        while ((file_tbl2[i2] != '|')) {
            // extract integer
            (file_tbl2_preload_iter_o_orderkey = ((file_tbl2_preload_iter_o_orderkey * 10) + (file_tbl2[i2] - '0')));
            i2++;
        }
        i2++;
        if (tmp_negative7) {
            (file_tbl2_preload_iter_o_orderkey = -file_tbl2_preload_iter_o_orderkey);
        }
        // reading column o_custkey
        int32_t file_tbl2_preload_iter_o_custkey = 0;
        int32_t tmp_negative6 = 0;
        if ((file_tbl2[i2] == '-')) {
            (tmp_negative6 = 1);
            i2++;
        }
        while ((file_tbl2[i2] != '|')) {
            // extract integer
            (file_tbl2_preload_iter_o_custkey = ((file_tbl2_preload_iter_o_custkey * 10) + (file_tbl2[i2] - '0')));
            i2++;
        }
        i2++;
        if (tmp_negative6) {
            (file_tbl2_preload_iter_o_custkey = -file_tbl2_preload_iter_o_custkey);
        }
        // reading column o_orderstatus
        (i2 = (i2 + 2));
        // reading column o_totalprice
        while ((file_tbl2[i2] != '|')) i2++;
        i2++;
        // reading column o_orderdate
        int32_t file_tbl2_preload_iter_o_orderdate = (((((((file_tbl2[i2] * 10 + file_tbl2[i2 + 1]) * 10 + file_tbl2[i2 + 2]) * 10 + file_tbl2[i2 + 3]) * 10 + file_tbl2[i2 + 5]) * 10 + file_tbl2[i2 + 6]) * 10 + file_tbl2[i2 + 8]) * 10 + file_tbl2[i2 + 9]) - 533333328;
        (i2 = (i2 + 11));
        // reading column o_orderpriority
        while ((file_tbl2[i2] != '|')) i2++;
        i2++;
        // reading column o_clerk
        while ((file_tbl2[i2] != '|')) i2++;
        i2++;
        // reading column o_shippriority
        while ((file_tbl2[i2] != '|')) i2++;
        i2++;
        // reading column o_comment
        while ((file_tbl2[i2] != '|')) i2++;
        i2++;
        i2++;
        (preloaded2_o_orderkey[preloaded2_data_count] = file_tbl2_preload_iter_o_orderkey);
        (preloaded2_o_custkey[preloaded2_data_count] = file_tbl2_preload_iter_o_custkey);
        (preloaded2_o_orderdate[preloaded2_data_count] = file_tbl2_preload_iter_o_orderdate);
        (preloaded2_data_count = (preloaded2_data_count + 1));
    }
    int fd3 = open("../data//customer.tbl", 0);
    if ((fd3 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//customer.tbl");
        return 1;
    }
    size_t n3 = fsize(fd3);
    char *file_tbl3 = mmap(0, n3, PROT_READ, MAP_FILE | MAP_SHARED, fd3, 0);
    close(fd3);
    // init array for preloaded3
    int preloaded3_data_count;
    (preloaded3_data_count = 0);
    // value of preloaded3: c_custkey
    int32_t *preloaded3_c_custkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded3: c_nationkey
    int32_t *preloaded3_c_nationkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//customer.tbl)
    size_t i3 = 0;
    for (size_t preload_iter = 0; i3 < n3; preload_iter++) {
        // reading column c_custkey
        int32_t file_tbl3_preload_iter_c_custkey = 0;
        int32_t tmp_negative9 = 0;
        if ((file_tbl3[i3] == '-')) {
            (tmp_negative9 = 1);
            i3++;
        }
        while ((file_tbl3[i3] != '|')) {
            // extract integer
            (file_tbl3_preload_iter_c_custkey = ((file_tbl3_preload_iter_c_custkey * 10) + (file_tbl3[i3] - '0')));
            i3++;
        }
        i3++;
        if (tmp_negative9) {
            (file_tbl3_preload_iter_c_custkey = -file_tbl3_preload_iter_c_custkey);
        }
        // reading column c_name
        while ((file_tbl3[i3] != '|')) i3++;
        i3++;
        // reading column c_address
        while ((file_tbl3[i3] != '|')) i3++;
        i3++;
        // reading column c_nationkey
        int32_t file_tbl3_preload_iter_c_nationkey = 0;
        int32_t tmp_negative8 = 0;
        if ((file_tbl3[i3] == '-')) {
            (tmp_negative8 = 1);
            i3++;
        }
        while ((file_tbl3[i3] != '|')) {
            // extract integer
            (file_tbl3_preload_iter_c_nationkey = ((file_tbl3_preload_iter_c_nationkey * 10) + (file_tbl3[i3] - '0')));
            i3++;
        }
        i3++;
        if (tmp_negative8) {
            (file_tbl3_preload_iter_c_nationkey = -file_tbl3_preload_iter_c_nationkey);
        }
        // reading column c_phone
        while ((file_tbl3[i3] != '|')) i3++;
        i3++;
        // reading column c_acctbal
        while ((file_tbl3[i3] != '|')) i3++;
        i3++;
        // reading column c_mktsegment
        while ((file_tbl3[i3] != '|')) i3++;
        i3++;
        // reading column c_comment
        while ((file_tbl3[i3] != '|')) i3++;
        i3++;
        i3++;
        (preloaded3_c_custkey[preloaded3_data_count] = file_tbl3_preload_iter_c_custkey);
        (preloaded3_c_nationkey[preloaded3_data_count] = file_tbl3_preload_iter_c_nationkey);
        (preloaded3_data_count = (preloaded3_data_count + 1));
    }
    int fd4 = open("../data//nation.tbl", 0);
    if ((fd4 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//nation.tbl");
        return 1;
    }
    size_t n4 = fsize(fd4);
    char *file_tbl4 = mmap(0, n4, PROT_READ, MAP_FILE | MAP_SHARED, fd4, 0);
    close(fd4);
    // init array for preloaded4
    int preloaded4_data_count;
    (preloaded4_data_count = 0);
    // value of preloaded4: n_nationkey
    int32_t *preloaded4_n_nationkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded4: n_name
    const char **preloaded4_n_name_str = (const char **)malloc(sizeof(const char *) * 60000000);
    int *preloaded4_n_name_len = (int *)malloc(sizeof(int) * 60000000);
    // value of preloaded4: n_regionkey
    int32_t *preloaded4_n_regionkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//nation.tbl)
    size_t i4 = 0;
    for (size_t preload_iter = 0; i4 < n4; preload_iter++) {
        // reading column n_nationkey
        int32_t file_tbl4_preload_iter_n_nationkey = 0;
        int32_t tmp_negative11 = 0;
        if ((file_tbl4[i4] == '-')) {
            (tmp_negative11 = 1);
            i4++;
        }
        while ((file_tbl4[i4] != '|')) {
            // extract integer
            (file_tbl4_preload_iter_n_nationkey = ((file_tbl4_preload_iter_n_nationkey * 10) + (file_tbl4[i4] - '0')));
            i4++;
        }
        i4++;
        if (tmp_negative11) {
            (file_tbl4_preload_iter_n_nationkey = -file_tbl4_preload_iter_n_nationkey);
        }
        // reading column n_name
        size_t file_tbl4_preload_iter_n_name_start = i4;
        while ((file_tbl4[i4] != '|')) i4++;
        size_t file_tbl4_preload_iter_n_name_end = i4;
        i4++;
        // reading column n_regionkey
        int32_t file_tbl4_preload_iter_n_regionkey = 0;
        int32_t tmp_negative10 = 0;
        if ((file_tbl4[i4] == '-')) {
            (tmp_negative10 = 1);
            i4++;
        }
        while ((file_tbl4[i4] != '|')) {
            // extract integer
            (file_tbl4_preload_iter_n_regionkey = ((file_tbl4_preload_iter_n_regionkey * 10) + (file_tbl4[i4] - '0')));
            i4++;
        }
        i4++;
        if (tmp_negative10) {
            (file_tbl4_preload_iter_n_regionkey = -file_tbl4_preload_iter_n_regionkey);
        }
        // reading column n_comment
        while ((file_tbl4[i4] != '|')) i4++;
        i4++;
        i4++;
        (preloaded4_n_nationkey[preloaded4_data_count] = file_tbl4_preload_iter_n_nationkey);
        (preloaded4_n_name_str[preloaded4_data_count] = (file_tbl4 + file_tbl4_preload_iter_n_name_start));
        (preloaded4_n_name_len[preloaded4_data_count] = (file_tbl4_preload_iter_n_name_end - file_tbl4_preload_iter_n_name_start));
        (preloaded4_n_regionkey[preloaded4_data_count] = file_tbl4_preload_iter_n_regionkey);
        (preloaded4_data_count = (preloaded4_data_count + 1));
    }
    int fd5 = open("../data//region.tbl", 0);
    if ((fd5 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//region.tbl");
        return 1;
    }
    size_t n5 = fsize(fd5);
    char *file_tbl5 = mmap(0, n5, PROT_READ, MAP_FILE | MAP_SHARED, fd5, 0);
    close(fd5);
    // init array for preloaded5
    int preloaded5_data_count;
    (preloaded5_data_count = 0);
    // value of preloaded5: r_regionkey
    int32_t *preloaded5_r_regionkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded5: r_name
    const char **preloaded5_r_name_str = (const char **)malloc(sizeof(const char *) * 60000000);
    int *preloaded5_r_name_len = (int *)malloc(sizeof(int) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//region.tbl)
    size_t i5 = 0;
    for (size_t preload_iter = 0; i5 < n5; preload_iter++) {
        // reading column r_regionkey
        int32_t file_tbl5_preload_iter_r_regionkey = 0;
        int32_t tmp_negative12 = 0;
        if ((file_tbl5[i5] == '-')) {
            (tmp_negative12 = 1);
            i5++;
        }
        while ((file_tbl5[i5] != '|')) {
            // extract integer
            (file_tbl5_preload_iter_r_regionkey = ((file_tbl5_preload_iter_r_regionkey * 10) + (file_tbl5[i5] - '0')));
            i5++;
        }
        i5++;
        if (tmp_negative12) {
            (file_tbl5_preload_iter_r_regionkey = -file_tbl5_preload_iter_r_regionkey);
        }
        // reading column r_name
        size_t file_tbl5_preload_iter_r_name_start = i5;
        while ((file_tbl5[i5] != '|')) i5++;
        size_t file_tbl5_preload_iter_r_name_end = i5;
        i5++;
        // reading column r_comment
        while ((file_tbl5[i5] != '|')) i5++;
        i5++;
        i5++;
        (preloaded5_r_regionkey[preloaded5_data_count] = file_tbl5_preload_iter_r_regionkey);
        (preloaded5_r_name_str[preloaded5_data_count] = (file_tbl5 + file_tbl5_preload_iter_r_name_start));
        (preloaded5_r_name_len[preloaded5_data_count] = (file_tbl5_preload_iter_r_name_end - file_tbl5_preload_iter_r_name_start));
        (preloaded5_data_count = (preloaded5_data_count + 1));
    }
    int fd6 = open("../data//supplier.tbl", 0);
    if ((fd6 == -1)) {
        fprintf(stderr, "Unable to open file %s\n", "../data//supplier.tbl");
        return 1;
    }
    size_t n6 = fsize(fd6);
    char *file_tbl6 = mmap(0, n6, PROT_READ, MAP_FILE | MAP_SHARED, fd6, 0);
    close(fd6);
    // init array for preloaded6
    int preloaded6_data_count;
    (preloaded6_data_count = 0);
    // value of preloaded6: s_suppkey
    int32_t *preloaded6_s_suppkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // value of preloaded6: s_nationkey
    int32_t *preloaded6_s_nationkey = (int32_t *)malloc(sizeof(int32_t) * 60000000);
    // generator: preload_iter <- loadInput('tbl', ../data//supplier.tbl)
    size_t i6 = 0;
    for (size_t preload_iter = 0; i6 < n6; preload_iter++) {
        // reading column s_suppkey
        int32_t file_tbl6_preload_iter_s_suppkey = 0;
        int32_t tmp_negative14 = 0;
        if ((file_tbl6[i6] == '-')) {
            (tmp_negative14 = 1);
            i6++;
        }
        while ((file_tbl6[i6] != '|')) {
            // extract integer
            (file_tbl6_preload_iter_s_suppkey = ((file_tbl6_preload_iter_s_suppkey * 10) + (file_tbl6[i6] - '0')));
            i6++;
        }
        i6++;
        if (tmp_negative14) {
            (file_tbl6_preload_iter_s_suppkey = -file_tbl6_preload_iter_s_suppkey);
        }
        // reading column s_name
        while ((file_tbl6[i6] != '|')) i6++;
        i6++;
        // reading column s_address
        while ((file_tbl6[i6] != '|')) i6++;
        i6++;
        // reading column s_nationkey
        int32_t file_tbl6_preload_iter_s_nationkey = 0;
        int32_t tmp_negative13 = 0;
        if ((file_tbl6[i6] == '-')) {
            (tmp_negative13 = 1);
            i6++;
        }
        while ((file_tbl6[i6] != '|')) {
            // extract integer
            (file_tbl6_preload_iter_s_nationkey = ((file_tbl6_preload_iter_s_nationkey * 10) + (file_tbl6[i6] - '0')));
            i6++;
        }
        i6++;
        if (tmp_negative13) {
            (file_tbl6_preload_iter_s_nationkey = -file_tbl6_preload_iter_s_nationkey);
        }
        // reading column s_phone
        while ((file_tbl6[i6] != '|')) i6++;
        i6++;
        // reading column s_acctbal
        while ((file_tbl6[i6] != '|')) i6++;
        i6++;
        // reading column s_comment
        while ((file_tbl6[i6] != '|')) i6++;
        i6++;
        i6++;
        (preloaded6_s_suppkey[preloaded6_data_count] = file_tbl6_preload_iter_s_suppkey);
        (preloaded6_s_nationkey[preloaded6_data_count] = file_tbl6_preload_iter_s_nationkey);
        (preloaded6_data_count = (preloaded6_data_count + 1));
    }
    struct timeval timeval1;
    gettimeofday(&timeval1, NULL);
    long t1 = ((timeval1.tv_sec * 1000000L) + timeval1.tv_usec);
    // generator: *p1 <- loadInput('tbl', ../data//part.tbl)
    for (size_t xp1 = 0; xp1 < preloaded1_data_count; xp1++) {
        int tmp_cmpstr0 = strncmp(preloaded1_p_type_str[xp1], "ECONOMY ANODIZED STEEL", ((preloaded1_p_type_len[xp1] < 22) ? preloaded1_p_type_len[xp1] : 22));
        (tmp_cmpstr0 = ((tmp_cmpstr0 == 0) ? (preloaded1_p_type_len[xp1] - 22) : tmp_cmpstr0));
        // generator: K0 <- mkset(and(equal(loadInput('tbl', ../data//part.tbl)[*p1][p_type], ECONOMY ANODIZED STEEL), loadInput('tbl', ../data//part.tbl)[*p1][p_partkey]))
        if (!!(tmp_cmpstr0 == 0)) {
            // singleton value here
            unsigned long hash0 = 0;
            unsigned long tmp_hash0 = (unsigned long)preloaded1_p_partkey[xp1];
            (hash0 = (hash0 + tmp_hash0));
            unsigned long tmp_pos0$ = (hash0 & 16777215);
            while (((tmp2_htable[tmp_pos0$] != 0) && (tmp2_keys0[tmp2_htable[tmp_pos0$]] != preloaded1_p_partkey[xp1]))) {
                (tmp_pos0$ = ((tmp_pos0$ + 1) & 16777215));
            }
            int key_pos0$ = tmp2_htable[tmp_pos0$];
            if ((key_pos0$ == 0)) {
                tmp2_key_count++;
                (key_pos0$ = tmp2_key_count);
                (tmp2_htable[tmp_pos0$] = key_pos0$);
                (tmp2_keys0[key_pos0$] = preloaded1_p_partkey[xp1]);
            }
            if (!tmp2__DEFAULT__defined[key_pos0$]) {
                (tmp2__DEFAULT__defined[key_pos0$] = 1);
            }
            (tmp2__DEFAULT_[key_pos0$] = preloaded1_p_partkey[xp1]);
        }
    }
    // generator: *l1 <- loadInput('tbl', ../data//lineitem.tbl)
    for (size_t xl1 = 0; xl1 < preloaded0_data_count; xl1++) {
        unsigned long hash1 = 0;
        unsigned long tmp_hash1 = (unsigned long)preloaded0_l_partkey[xl1];
        (hash1 = (hash1 + tmp_hash1));
        unsigned long tmp_pos1$ = (hash1 & 16777215);
        while (((tmp2_htable[tmp_pos1$] != 0) && (tmp2_keys0[tmp2_htable[tmp_pos1$]] != preloaded0_l_partkey[xl1]))) {
            (tmp_pos1$ = ((tmp_pos1$ + 1) & 16777215));
        }
        int key_pos1$ = tmp2_htable[tmp_pos1$];
        // generator: K1 <- mkset(and(tmp2[][loadInput('tbl', ../data//lineitem.tbl)[*l1][l_partkey]], loadInput('tbl', ../data//lineitem.tbl)[*l1][l_orderkey]))
        if (!(key_pos1$ == 0)) {
            // singleton value here
            unsigned long hash2 = 0;
            unsigned long tmp_hash2 = (unsigned long)preloaded0_l_orderkey[xl1];
            (hash2 = (hash2 + tmp_hash2));
            unsigned long tmp_pos2$ = (hash2 & 16777215);
            while (((tmp3_htable[tmp_pos2$] != 0) && (tmp3_keys0[tmp3_htable[tmp_pos2$]] != preloaded0_l_orderkey[xl1]))) {
                (tmp_pos2$ = ((tmp_pos2$ + 1) & 16777215));
            }
            int key_pos2$ = tmp3_htable[tmp_pos2$];
            if ((key_pos2$ == 0)) {
                tmp3_key_count++;
                (key_pos2$ = tmp3_key_count);
                (tmp3_htable[tmp_pos2$] = key_pos2$);
                (tmp3_keys0[key_pos2$] = preloaded0_l_orderkey[xl1]);
                (tmp3__DEFAULT_[key_pos2$] = (struct tmp3__DEFAULT__arr *)malloc(sizeof(struct tmp3__DEFAULT__arr) * 1));
                (tmp3__DEFAULT_[key_pos2$]->l_suppkey$ = (int32_t *)malloc(sizeof(int32_t) * 64));
                (tmp3__DEFAULT_[key_pos2$]->l_extendedprice$ = (double *)malloc(sizeof(double) * 64));
                (tmp3__DEFAULT_[key_pos2$]->l_discount$ = (double *)malloc(sizeof(double) * 64));
                (tmp3__DEFAULT_[key_pos2$]->count$ = 0);
            }
            (tmp3__DEFAULT_[key_pos2$]->l_suppkey$[tmp3__DEFAULT_[key_pos2$]->count$] = preloaded0_l_suppkey[xl1]);
            (tmp3__DEFAULT_[key_pos2$]->l_extendedprice$[tmp3__DEFAULT_[key_pos2$]->count$] = preloaded0_l_extendedprice[xl1]);
            (tmp3__DEFAULT_[key_pos2$]->l_discount$[tmp3__DEFAULT_[key_pos2$]->count$] = preloaded0_l_discount[xl1]);
            (tmp3__DEFAULT_[key_pos2$]->count$ = (tmp3__DEFAULT_[key_pos2$]->count$ + 1));
        }
    }
    // generator: *o1 <- loadInput('tbl', ../data//orders.tbl)
    for (size_t xo1 = 0; xo1 < preloaded2_data_count; xo1++) {
        unsigned long hash3 = 0;
        unsigned long tmp_hash3 = (unsigned long)preloaded2_o_orderkey[xo1];
        (hash3 = (hash3 + tmp_hash3));
        unsigned long tmp_pos5$ = (hash3 & 16777215);
        while (((tmp3_htable[tmp_pos5$] != 0) && (tmp3_keys0[tmp3_htable[tmp_pos5$]] != preloaded2_o_orderkey[xo1]))) {
            (tmp_pos5$ = ((tmp_pos5$ + 1) & 16777215));
        }
        int key_pos5$ = tmp3_htable[tmp_pos5$];
        // generator: K2 <- mkset(and(andAlso(andAlso(tmp3[][loadInput('tbl', ../data//orders.tbl)[*o1][o_orderkey]], greaterThanOrEqual(loadInput('tbl', ../data//orders.tbl)[*o1][o_orderdate], 19950101)), lessThanOrEqual(loadInput('tbl', ../data//orders.tbl)[*o1][o_orderdate], 19961231)), loadInput('tbl', ../data//orders.tbl)[*o1][o_custkey]))
        if (!(((key_pos5$ == 0) || !(preloaded2_o_orderdate[xo1] >= 19950101)) || !(preloaded2_o_orderdate[xo1] <= 19961231))) {
            // singleton value here
            unsigned long hash4 = 0;
            unsigned long tmp_hash4 = (unsigned long)preloaded2_o_custkey[xo1];
            (hash4 = (hash4 + tmp_hash4));
            unsigned long tmp_pos6$ = (hash4 & 16777215);
            while (((tmp5_htable[tmp_pos6$] != 0) && (tmp5_keys0[tmp5_htable[tmp_pos6$]] != preloaded2_o_custkey[xo1]))) {
                (tmp_pos6$ = ((tmp_pos6$ + 1) & 16777215));
            }
            int key_pos6$ = tmp5_htable[tmp_pos6$];
            if ((key_pos6$ == 0)) {
                tmp5_key_count++;
                (key_pos6$ = tmp5_key_count);
                (tmp5_htable[tmp_pos6$] = key_pos6$);
                (tmp5_keys0[key_pos6$] = preloaded2_o_custkey[xo1]);
                (tmp5__DEFAULT_[key_pos6$] = (struct tmp5__DEFAULT__arr *)malloc(sizeof(struct tmp5__DEFAULT__arr) * 1));
                (tmp5__DEFAULT_[key_pos6$]->l_suppkey$ = (int32_t *)malloc(sizeof(int32_t) * 64));
                (tmp5__DEFAULT_[key_pos6$]->l_extendedprice$ = (double *)malloc(sizeof(double) * 64));
                (tmp5__DEFAULT_[key_pos6$]->l_discount$ = (double *)malloc(sizeof(double) * 64));
                (tmp5__DEFAULT_[key_pos6$]->o_orderdate$ = (int32_t *)malloc(sizeof(int32_t) * 64));
                (tmp5__DEFAULT_[key_pos6$]->count$ = 0);
            }
            // generator: *l2 <- tmp3[][loadInput('tbl', ../data//orders.tbl)[*o1][o_orderkey]]
            if (!(key_pos5$ == 0)) for (size_t xl2 = 0; xl2 < tmp3__DEFAULT_[key_pos5$]->count$; xl2++) {
                (tmp5__DEFAULT_[key_pos6$]->l_suppkey$[tmp5__DEFAULT_[key_pos6$]->count$] = tmp3__DEFAULT_[key_pos5$]->l_suppkey$[xl2]);
                (tmp5__DEFAULT_[key_pos6$]->l_extendedprice$[tmp5__DEFAULT_[key_pos6$]->count$] = tmp3__DEFAULT_[key_pos5$]->l_extendedprice$[xl2]);
                (tmp5__DEFAULT_[key_pos6$]->l_discount$[tmp5__DEFAULT_[key_pos6$]->count$] = tmp3__DEFAULT_[key_pos5$]->l_discount$[xl2]);
                (tmp5__DEFAULT_[key_pos6$]->o_orderdate$[tmp5__DEFAULT_[key_pos6$]->count$] = preloaded2_o_orderdate[xo1]);
                (tmp5__DEFAULT_[key_pos6$]->count$ = (tmp5__DEFAULT_[key_pos6$]->count$ + 1));
            }
        }
    }
    // generator: *r1 <- loadInput('tbl', ../data//region.tbl)
    for (size_t xr1 = 0; xr1 < preloaded5_data_count; xr1++) {
        // generator: K3 <- mkset(and(equal(loadInput('tbl', ../data//region.tbl)[*r1][r_name], AMERICA), loadInput('tbl', ../data//region.tbl)[*r1][r_regionkey]))
        if (!!((preloaded5_r_name_len[xr1] == 7) ? ((*((uint64_t *)preloaded5_r_name_str[xr1]) & 0x00FFFFFFFFFFFFFF) == 0x41434952454D41) : 0)) {
            // singleton value here
            unsigned long hash5 = 0;
            unsigned long tmp_hash5 = (unsigned long)preloaded5_r_regionkey[xr1];
            (hash5 = (hash5 + tmp_hash5));
            unsigned long tmp_pos9$ = (hash5 & 16777215);
            while (((tmp9_htable[tmp_pos9$] != 0) && (tmp9_keys0[tmp9_htable[tmp_pos9$]] != preloaded5_r_regionkey[xr1]))) {
                (tmp_pos9$ = ((tmp_pos9$ + 1) & 16777215));
            }
            int key_pos9$ = tmp9_htable[tmp_pos9$];
            if ((key_pos9$ == 0)) {
                tmp9_key_count++;
                (key_pos9$ = tmp9_key_count);
                (tmp9_htable[tmp_pos9$] = key_pos9$);
                (tmp9_keys0[key_pos9$] = preloaded5_r_regionkey[xr1]);
            }
            if (!tmp9__DEFAULT__defined[key_pos9$]) {
                (tmp9__DEFAULT__defined[key_pos9$] = 1);
            }
            (tmp9__DEFAULT_[key_pos9$] = preloaded5_r_regionkey[xr1]);
        }
    }
    // generator: *n1 <- loadInput('tbl', ../data//nation.tbl)
    for (size_t xn1 = 0; xn1 < preloaded4_data_count; xn1++) {
        unsigned long hash6 = 0;
        unsigned long tmp_hash6 = (unsigned long)preloaded4_n_regionkey[xn1];
        (hash6 = (hash6 + tmp_hash6));
        unsigned long tmp_pos10$ = (hash6 & 16777215);
        while (((tmp9_htable[tmp_pos10$] != 0) && (tmp9_keys0[tmp9_htable[tmp_pos10$]] != preloaded4_n_regionkey[xn1]))) {
            (tmp_pos10$ = ((tmp_pos10$ + 1) & 16777215));
        }
        int key_pos10$ = tmp9_htable[tmp_pos10$];
        // generator: K4 <- mkset(and(tmp9[][loadInput('tbl', ../data//nation.tbl)[*n1][n_regionkey]], loadInput('tbl', ../data//nation.tbl)[*n1][n_nationkey]))
        if (!(key_pos10$ == 0)) {
            // singleton value here
            unsigned long hash7 = 0;
            unsigned long tmp_hash7 = (unsigned long)preloaded4_n_nationkey[xn1];
            (hash7 = (hash7 + tmp_hash7));
            unsigned long tmp_pos12$ = (hash7 & 16777215);
            while (((tmp10_htable[tmp_pos12$] != 0) && (tmp10_keys0[tmp10_htable[tmp_pos12$]] != preloaded4_n_nationkey[xn1]))) {
                (tmp_pos12$ = ((tmp_pos12$ + 1) & 16777215));
            }
            int key_pos12$ = tmp10_htable[tmp_pos12$];
            if ((key_pos12$ == 0)) {
                tmp10_key_count++;
                (key_pos12$ = tmp10_key_count);
                (tmp10_htable[tmp_pos12$] = key_pos12$);
                (tmp10_keys0[key_pos12$] = preloaded4_n_nationkey[xn1]);
            }
            if (!tmp10__DEFAULT__defined[key_pos12$]) {
                (tmp10__DEFAULT__defined[key_pos12$] = 1);
            }
            (tmp10__DEFAULT_[key_pos12$] = preloaded4_n_nationkey[xn1]);
        }
    }
    // generator: *c1 <- loadInput('tbl', ../data//customer.tbl)
    for (size_t xc1 = 0; xc1 < preloaded3_data_count; xc1++) {
        unsigned long hash8 = 0;
        unsigned long tmp_hash8 = (unsigned long)preloaded3_c_custkey[xc1];
        (hash8 = (hash8 + tmp_hash8));
        unsigned long tmp_pos8$ = (hash8 & 16777215);
        while (((tmp5_htable[tmp_pos8$] != 0) && (tmp5_keys0[tmp5_htable[tmp_pos8$]] != preloaded3_c_custkey[xc1]))) {
            (tmp_pos8$ = ((tmp_pos8$ + 1) & 16777215));
        }
        int key_pos8$ = tmp5_htable[tmp_pos8$];
        // generator: *o2 <- tmp5[][loadInput('tbl', ../data//customer.tbl)[*c1][c_custkey]]
        if (!(key_pos8$ == 0)) for (size_t xo2 = 0; xo2 < tmp5__DEFAULT_[key_pos8$]->count$; xo2++) {
            unsigned long hash9 = 0;
            unsigned long tmp_hash9 = (unsigned long)preloaded3_c_nationkey[xc1];
            (hash9 = (hash9 + tmp_hash9));
            unsigned long tmp_pos13$ = (hash9 & 16777215);
            while (((tmp10_htable[tmp_pos13$] != 0) && (tmp10_keys0[tmp10_htable[tmp_pos13$]] != preloaded3_c_nationkey[xc1]))) {
                (tmp_pos13$ = ((tmp_pos13$ + 1) & 16777215));
            }
            int key_pos13$ = tmp10_htable[tmp_pos13$];
            // generator: K5 <- mkset(and(andAlso(tmp5[][loadInput('tbl', ../data//customer.tbl)[*c1][c_custkey]], tmp10[][loadInput('tbl', ../data//customer.tbl)[*c1][c_nationkey]]), tmp5[][loadInput('tbl', ../data//customer.tbl)[*c1][c_custkey]][*o2][l_suppkey]))
            if (!((key_pos8$ == 0) || (key_pos13$ == 0))) {
                // singleton value here
                unsigned long hash10 = 0;
                unsigned long tmp_hash10 = (unsigned long)tmp5__DEFAULT_[key_pos8$]->l_suppkey$[xo2];
                (hash10 = (hash10 + tmp_hash10));
                unsigned long tmp_pos14$ = (hash10 & 16777215);
                while (((tmp11_htable[tmp_pos14$] != 0) && (tmp11_keys0[tmp11_htable[tmp_pos14$]] != tmp5__DEFAULT_[key_pos8$]->l_suppkey$[xo2]))) {
                    (tmp_pos14$ = ((tmp_pos14$ + 1) & 16777215));
                }
                int key_pos14$ = tmp11_htable[tmp_pos14$];
                if ((key_pos14$ == 0)) {
                    tmp11_key_count++;
                    (key_pos14$ = tmp11_key_count);
                    (tmp11_htable[tmp_pos14$] = key_pos14$);
                    (tmp11_keys0[key_pos14$] = tmp5__DEFAULT_[key_pos8$]->l_suppkey$[xo2]);
                    (tmp11__DEFAULT_[key_pos14$] = (struct tmp11__DEFAULT__arr *)malloc(sizeof(struct tmp11__DEFAULT__arr) * 1));
                    (tmp11__DEFAULT_[key_pos14$]->l_extendedprice$ = (double *)malloc(sizeof(double) * 64));
                    (tmp11__DEFAULT_[key_pos14$]->l_discount$ = (double *)malloc(sizeof(double) * 64));
                    (tmp11__DEFAULT_[key_pos14$]->o_orderdate$ = (int32_t *)malloc(sizeof(int32_t) * 64));
                    (tmp11__DEFAULT_[key_pos14$]->count$ = 0);
                }
                (tmp11__DEFAULT_[key_pos14$]->l_extendedprice$[tmp11__DEFAULT_[key_pos14$]->count$] = tmp5__DEFAULT_[key_pos8$]->l_extendedprice$[xo2]);
                (tmp11__DEFAULT_[key_pos14$]->l_discount$[tmp11__DEFAULT_[key_pos14$]->count$] = tmp5__DEFAULT_[key_pos8$]->l_discount$[xo2]);
                (tmp11__DEFAULT_[key_pos14$]->o_orderdate$[tmp11__DEFAULT_[key_pos14$]->count$] = tmp5__DEFAULT_[key_pos8$]->o_orderdate$[xo2]);
                (tmp11__DEFAULT_[key_pos14$]->count$ = (tmp11__DEFAULT_[key_pos14$]->count$ + 1));
            }
        }
    }
    // generator: *n2 <- loadInput('tbl', ../data//nation.tbl)
    for (size_t xn2 = 0; xn2 < preloaded4_data_count; xn2++) {
        // generator: K6 <- mkset(loadInput('tbl', ../data//nation.tbl)[*n2][n_nationkey])
        if (1) {
            // singleton value here
            unsigned long hash11 = 0;
            unsigned long tmp_hash11 = (unsigned long)preloaded4_n_nationkey[xn2];
            (hash11 = (hash11 + tmp_hash11));
            unsigned long tmp_pos23$ = (hash11 & 16777215);
            while (((tmp14_htable[tmp_pos23$] != 0) && (tmp14_keys0[tmp14_htable[tmp_pos23$]] != preloaded4_n_nationkey[xn2]))) {
                (tmp_pos23$ = ((tmp_pos23$ + 1) & 16777215));
            }
            int key_pos23$ = tmp14_htable[tmp_pos23$];
            if ((key_pos23$ == 0)) {
                tmp14_key_count++;
                (key_pos23$ = tmp14_key_count);
                (tmp14_htable[tmp_pos23$] = key_pos23$);
                (tmp14_keys0[key_pos23$] = preloaded4_n_nationkey[xn2]);
            }
            if (!tmp14__DEFAULT__defined[key_pos23$]) {
                (tmp14__DEFAULT__defined[key_pos23$] = 1);
            }
            (tmp14__DEFAULT__str[key_pos23$] = preloaded4_n_name_str[xn2]);
            (tmp14__DEFAULT__len[key_pos23$] = preloaded4_n_name_len[xn2]);
        }
    }
    // generator: *s1 <- loadInput('tbl', ../data//supplier.tbl)
    for (size_t xs1 = 0; xs1 < preloaded6_data_count; xs1++) {
        unsigned long hash12 = 0;
        unsigned long tmp_hash12 = (unsigned long)preloaded6_s_suppkey[xs1];
        (hash12 = (hash12 + tmp_hash12));
        unsigned long tmp_pos16$ = (hash12 & 16777215);
        while (((tmp11_htable[tmp_pos16$] != 0) && (tmp11_keys0[tmp11_htable[tmp_pos16$]] != preloaded6_s_suppkey[xs1]))) {
            (tmp_pos16$ = ((tmp_pos16$ + 1) & 16777215));
        }
        int key_pos16$ = tmp11_htable[tmp_pos16$];
        // generator: *c2 <- tmp11[][loadInput('tbl', ../data//supplier.tbl)[*s1][s_suppkey]]
        if (!(key_pos16$ == 0)) for (size_t xc2 = 0; xc2 < tmp11__DEFAULT_[key_pos16$]->count$; xc2++) {
            // generator: K7 <- mkset(and(tmp11[][loadInput('tbl', ../data//supplier.tbl)[*s1][s_suppkey]], year(tmp11[][loadInput('tbl', ../data//supplier.tbl)[*s1][s_suppkey]][*c2][o_orderdate])))
            if (!(key_pos16$ == 0)) {
                // singleton value here
                unsigned long hash13 = 0;
                unsigned long tmp_hash13 = (unsigned long)(tmp11__DEFAULT_[key_pos16$]->o_orderdate$[xc2] / 10000);
                (hash13 = (hash13 + tmp_hash13));
                unsigned long tmp_pos18$ = (hash13 & 16777215);
                while (((tmp18_htable[tmp_pos18$] != 0) && (tmp18_keys0[tmp18_htable[tmp_pos18$]] != (tmp11__DEFAULT_[key_pos16$]->o_orderdate$[xc2] / 10000)))) {
                    (tmp_pos18$ = ((tmp_pos18$ + 1) & 16777215));
                }
                int key_pos18$ = tmp18_htable[tmp_pos18$];
                if ((key_pos18$ == 0)) {
                    tmp18_key_count++;
                    (key_pos18$ = tmp18_key_count);
                    (tmp18_htable[tmp_pos18$] = key_pos18$);
                    (tmp18_keys0[key_pos18$] = (tmp11__DEFAULT_[key_pos16$]->o_orderdate$[xc2] / 10000));
                }
                if (!tmp18_year_defined[key_pos18$]) {
                    (tmp18_year_defined[key_pos18$] = 1);
                }
                (tmp18_year[key_pos18$] = (tmp11__DEFAULT_[key_pos16$]->o_orderdate$[xc2] / 10000));
                if (!tmp15__DEFAULT__defined[key_pos18$]) {
                    (tmp15__DEFAULT__defined[key_pos18$] = 1);
                    (tmp15__DEFAULT_[key_pos18$] = 0);
                }
                unsigned long hash14 = 0;
                unsigned long tmp_hash14 = (unsigned long)preloaded6_s_nationkey[xs1];
                (hash14 = (hash14 + tmp_hash14));
                unsigned long tmp_pos24$ = (hash14 & 16777215);
                while (((tmp14_htable[tmp_pos24$] != 0) && (tmp14_keys0[tmp14_htable[tmp_pos24$]] != preloaded6_s_nationkey[xs1]))) {
                    (tmp_pos24$ = ((tmp_pos24$ + 1) & 16777215));
                }
                int key_pos24$ = tmp14_htable[tmp_pos24$];
                if (!((key_pos24$ == 0) || !((tmp14__DEFAULT__len[key_pos24$] == 6) ? ((*((uint64_t *)tmp14__DEFAULT__str[key_pos24$]) & 0x0000FFFFFFFFFFFF) == 0x4C495A415242) : 0))) {
                    (tmp15__DEFAULT_[key_pos18$] = (tmp15__DEFAULT_[key_pos18$] + (double)(tmp11__DEFAULT_[key_pos16$]->l_extendedprice$[xc2] * (double)(1 - tmp11__DEFAULT_[key_pos16$]->l_discount$[xc2]))));
                }
                if (!tmp16__DEFAULT__defined[key_pos18$]) {
                    (tmp16__DEFAULT__defined[key_pos18$] = 1);
                    (tmp16__DEFAULT_[key_pos18$] = 0);
                }
                (tmp16__DEFAULT_[key_pos18$] = (tmp16__DEFAULT_[key_pos18$] + (double)(tmp11__DEFAULT_[key_pos16$]->l_extendedprice$[xc2] * (double)(1 - tmp11__DEFAULT_[key_pos16$]->l_discount$[xc2]))));
                if (!((key_pos18$ == 0) || (key_pos18$ == 0))) {
                    if (!tmp18_mkt_share_defined[key_pos18$]) {
                        (tmp18_mkt_share_defined[key_pos18$] = 1);
                    }
                    (tmp18_mkt_share[key_pos18$] = ((double)(double)tmp15__DEFAULT_[key_pos18$] / (double)(double)tmp16__DEFAULT_[key_pos18$]));
                }
            }
        }
    }
    int *tmp18 = (int *)malloc(sizeof(int) * tmp18_key_count);
    for (int i = 0; i < tmp18_key_count; i++) tmp18[i] = i + 1;
    qsort(tmp18, tmp18_key_count, sizeof(int), (__compar_fn_t)compare_func0);
    // print hashmap
    for (int i = 0; i < tmp18_key_count; i++) {
        int key_pos = tmp18[i];
        // print value
        if ((key_pos == 0)) {
            printf("null");
        } else {
            // print object
            if (((key_pos == 0) || !tmp18_year_defined[key_pos])) {
                printf("null");
            } else {
                print_date(tmp18_year[key_pos]);
            }
            printf("|");
            if (((key_pos == 0) || !tmp18_mkt_share_defined[key_pos])) {
                printf("null");
            } else {
                printf("%.4lf", tmp18_mkt_share[key_pos]);
            }
            printf("|");
        }
        if (i != tmp18_key_count - 1) {
            printf("\n");
        }
    }
    fflush(stdout);
    struct timeval timeval2;
    gettimeofday(&timeval2, NULL);
    long t2 = ((timeval2.tv_sec * 1000000L) + timeval2.tv_usec);
    fprintf(stderr, "\n\nTiming:\n\tInitializaton:\t%ld μs\n\tRuntime:\t%ld μs\n\tTotal:\t\t%ld μs\n", (t1 - t0), (t2 - t1), (t2 - t0));
    return 0;
}
